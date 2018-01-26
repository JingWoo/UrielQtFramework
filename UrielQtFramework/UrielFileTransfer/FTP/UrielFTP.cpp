#include "UrielFileTransfer\FTP\UrielFTP.h"
#include <QNetworkSession>
#include <QFile>
//#include <QUrl>
#include <QtNetwork>
#include "ThirdPartyLibraries\QFTP\include\qftp.h"
#include <QMessageBox>
#include <QProgressDialog>
#include <QFileDialog>
#include "UrielQtFrameworkOptions/UrielQtFrameworkOptions.h"
#include "UrielGui\CommonDialog\ProgressDialog\ProgressDialog.h"
//C++ 11 (volatile)

std::atomic<UrielFtp*> UrielFtp::m_instance;
std::mutex UrielFtp::m_mutex;

UrielFtp::UrielFtp()
{
	/*m_pProgressDialog= new ProgressDialog;
	m_pProgressDialog->hide();*/
	//connect(m_pProgressDialog, &QProgressDialog::canceled, this, &UrielFtp::cancelDownload);
	g_pOptions= UrielQtFrameworkOptions::getInstance();
	//m_sCurrentPath = g_pOptions->getDefalutFilesDownloadPath();
	connectOrDisconnect();
}

UrielFtp* UrielFtp::getInstance() {
	UrielFtp* tmp = m_instance.load(std::memory_order_relaxed);
	std::atomic_thread_fence(std::memory_order_acquire);
	if (tmp == nullptr) {
		std::lock_guard<std::mutex> lock(m_mutex);
		tmp = m_instance.load(std::memory_order_relaxed);
		if (tmp == nullptr) {
			tmp = new UrielFtp;
			std::atomic_thread_fence(std::memory_order_release);
			m_instance.store(tmp, std::memory_order_relaxed);
		}
	}
	return tmp;
}



void UrielFtp::connectOrDisconnect()
{
	if (m_pFtp) {
		m_pFtp->abort();
		m_pFtp->deleteLater();
		m_pFtp = 0;
		return;
	}

	if (!m_pNetworkSession || !m_pNetworkSession->isOpen()) {
		if (m_netManager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired) {
			if (!m_pNetworkSession) {
				// Get saved network configuration
				const QString id = g_pOptions->getDefaultNetworkConfiguration();
				/*QSettings settings(QSettings::UserScope, QLatin1String("Trolltech"));
				settings.beginGroup(QLatin1String("QtNetwork"));
				const QString id = settings.value(QLatin1String("DefaultNetworkConfiguration")).toString();
				settings.endGroup();*/

				// If the saved network configuration is not currently discovered use the system default
				QNetworkConfiguration config = m_netManager.configurationFromIdentifier(id);
				if ((config.state() & QNetworkConfiguration::Discovered) !=
					QNetworkConfiguration::Discovered) {
					config = m_netManager.defaultConfiguration();
				}

				m_pNetworkSession = new QNetworkSession(config, this);
				connect(m_pNetworkSession, SIGNAL(opened()), this, SLOT(connectToFtp()));
				connect(m_pNetworkSession, SIGNAL(error(QNetworkSession::SessionError)), this, SLOT(enableConnectServer()));
			}
			//statusLabel->setText(tr("Opening network session."));
			m_pNetworkSession->open();
			return;
		}
	}
	connectToFtpServer();
}

void UrielFtp::connectToFtpServer()
{
	m_pFtp = new QFtp(this);
	connect(m_pFtp, SIGNAL(commandFinished(int, bool)),
		this, SLOT(ftpCommandFinished(int, bool)));
	connect(m_pFtp, SIGNAL(listInfo(const QUrielUrlInfo&)),
		this, SLOT(addToList(const QUrielUrlInfo &)));
	connect(m_pFtp, SIGNAL(dataTransferProgress(qint64, qint64)),
		this, SLOT(updateDataTransferProgress(qint64, qint64)));

	emit GUIClear();
	m_sCurrentPath.clear();
	isDirectory.clear();

	sUrielFTPItem stUrielFTPItem=g_pOptions->getFTPConfigParameter();
	m_strUrl = "ftp://" + stUrielFTPItem.m_sUserName + ":" + stUrielFTPItem.m_sPassword + "@" + stUrielFTPItem.m_sHostIp + "/" + stUrielFTPItem.m_sProfile;
	m_sCurrentPath = "/"+stUrielFTPItem.m_sProfile;
	m_sRootPath = m_sCurrentPath;
	//QUrl url("ftp://ZJG508:ZJG508@10.78.59.4:21/LaboratoryResource");
	QUrl url(m_strUrl);
	if (!url.isValid() || url.scheme().toLower() != QLatin1String("ftp")) {
		m_pFtp->connectToHost(url.host(), 21);
		m_pFtp->login();
	}
	else {
		m_pFtp->connectToHost(url.host(), url.port(21));

		if (!url.userName().isEmpty())
			m_pFtp->login(QUrl::fromPercentEncoding(url.userName().toLatin1()), url.password());
		else
			m_pFtp->login();
		if (!url.path().isEmpty())
			m_pFtp->cd(url.path());
	}
	m_pFtp->list();
}

void UrielFtp::downloadFile(const QString &fileName)
{
	QString file_path = QFileDialog::getExistingDirectory(nullptr, QString::fromLocal8Bit("请选择文件保存路径..."), "./");
	if (file_path.isEmpty()) return;
	QFileInfo fileInfo(fileName);
	QString sfileName;
	if(file_path.at(file_path.size()-1)=='/')
		sfileName = file_path + fileInfo.fileName();
	else
		sfileName=file_path + "/"+ fileInfo.fileName();

	if (QFile::exists(sfileName)) {
		QMessageBox::information(nullptr,tr("FTP"),
			tr("There already exists a file called %1 in "
				"the current directory.")
			.arg(sfileName));
		return;
	}

	m_pFile = new QFile(sfileName);
	if (!m_pFile->open(QIODevice::WriteOnly)) {
		QMessageBox::information(nullptr, tr("FTP"),
			tr("Unable to save the file %1: %2.")
			.arg(sfileName).arg(m_pFile->errorString()));
		delete m_pFile;
		return;
	}

	m_pFtp->get(_ToSpecialEncoding(fileName), m_pFile);
	//m_pProgressDialog->setLabelText(tr("Downloading %1...").arg(filename));
	//m_pProgressDialog->exec();
}

bool UrielFtp::downloadFiles(const QString &file_path, const QString &fileName) {
	if (file_path.isEmpty()) return false;
	QFileInfo fileInfo(fileName);
	QString sfileName;
	if (file_path.at(file_path.size() - 1) == '/')
		sfileName = file_path + fileInfo.fileName();
	else
		sfileName = file_path + "/" + fileInfo.fileName();

	if (QFile::exists(sfileName)) {
		QMessageBox::information(nullptr, tr("FTP"),
			tr("There already exists a file called %1 in "
				"the current directory.")
			.arg(sfileName));
		return false;
	}

	m_pFile = new QFile(sfileName);
	if (!m_pFile->open(QIODevice::WriteOnly)) {
		QMessageBox::information(nullptr, tr("FTP"),
			tr("Unable to save the file %1: %2.")
			.arg(sfileName).arg(m_pFile->errorString()));
		delete m_pFile;
		return false;
	}

	m_pFtp->get(_ToSpecialEncoding(fileName), m_pFile);
	//m_pProgressDialog->setLabelText(tr("Downloading %1...").arg(filename));
	//m_pProgressDialog->exec();
	return true;
}

QImage UrielFtp::downloadImageFile(const QString &fileName)
{
	
	QString file_path = QCoreApplication::applicationDirPath() + "/TempFiles";
	QFileInfo fileInfo(fileName);
	QString sfileName;
	if (file_path.at(file_path.size() - 1) == '/')
		sfileName = file_path + fileInfo.fileName();
	else
		sfileName = file_path + "/" + fileInfo.fileName();

	if (QFile::exists(sfileName)) {
		return QImage(sfileName);
	}

	m_pFile = new QFile(sfileName);
	if (!m_pFile->open(QIODevice::WriteOnly)) {
		QMessageBox::information(nullptr, tr("FTP"),
			tr("Unable to save the file %1: %2.")
			.arg(sfileName).arg(m_pFile->errorString()));
		delete m_pFile;
		return QImage();
	}

	m_pFtp->get(_ToSpecialEncoding(fileName), m_pFile);
	//QEventLoop loop;
	//connect(this, &UrielFtp::updateDataTransferFinishSignal, &loop, &QEventLoop::quit);
	//loop.exec(/*QEventLoop::ExcludeUserInputEvents*/);

	//m_pProgressDialog->setLabelText(tr("Downloading %1...").arg(filename));
	//m_pProgressDialog->exec();
	return QImage(sfileName);
}

void UrielFtp::uploadFiles()
{
	QFileDialog::Options options;
	QString selectedFilter;
	QDir dir;
	QStringList fileNames = QFileDialog::getOpenFileNames(nullptr,
		QStringLiteral("选择文件"),
		dir.absolutePath(),
		tr("All Files (*.*);;zip Files (*.zip);;ISO Files (*.iso)"),
		&selectedFilter,
		options);
	if (fileNames.size()) {
		for each (QString var in fileNames)
		{
			m_pFile = new QFile(var);
			if (m_pFile->open(QIODevice::ReadOnly)) {
				QFileInfo fi(m_pFile->fileName());
				m_pFtp->put(m_pFile, _ToSpecialEncoding(m_sCurrentPath + '/' + fi.fileName()));
				emit GUIClear();
				isDirectory.clear();
				m_pFtp->list();
				return;
			}
			QMessageBox::information(nullptr, QStringLiteral("FTP"),
				QStringLiteral("无法上传该文件 %1: %2.")
				.arg(var).arg(m_pFile->errorString()));

			delete m_pFile;
			return;
		}
	}
}


void UrielFtp::uploadFile()
{
	QFileDialog::Options options;
	QString selectedFilter;
	QDir dir;
	QString fileName = QFileDialog::getOpenFileName(nullptr,
		QStringLiteral("打开文件"),
		dir.absolutePath(),
		tr("All Files (*.*);;zip Files (*.zip);;ISO Files (*.iso)"),
		&selectedFilter,
		options);
	if (!fileName.isEmpty())
	{
#ifdef _DEBUG
		qDebug() << fileName.toLocal8Bit();
#endif
		m_pFile = new QFile(fileName);
		if (m_pFile->open(QIODevice::ReadOnly)) {
			QFileInfo fi(m_pFile->fileName());
			m_pFtp->put(m_pFile, _ToSpecialEncoding(m_sCurrentPath + '/' + fi.fileName()));
			emit GUIClear();
			isDirectory.clear();
			m_pFtp->list();
			return;
		}
		QMessageBox::information(nullptr, QStringLiteral("FTP"),
			QStringLiteral("无法上传该文件 %1: %2.")
			.arg(fileName).arg(m_pFile->errorString()));

		delete m_pFile;
		return;
	}
}

void UrielFtp::uploadFile(const QString &fileName)
{
	if (!fileName.isEmpty())
	{
#ifdef _DEBUG
		qDebug() << fileName.toLocal8Bit();
#endif
		m_pFile = new QFile(fileName);
		if (m_pFile->open(QIODevice::ReadOnly)) {
			QFileInfo fi(m_pFile->fileName());
			m_pFtp->put(m_pFile, _ToSpecialEncoding(m_sCurrentPath + '/' + fi.fileName()));
			return;
		}
		QMessageBox::information(nullptr, QStringLiteral("FTP"),
			QStringLiteral("无法上传该文件 %1: %2.")
			.arg(fileName).arg(m_pFile->errorString()));

		delete m_pFile;
		return;
	}
}

void UrielFtp::uploadFileWithRemoteName(const QString &fileName,const  QString & remoteName)
{
	if (!fileName.isEmpty())
	{
#ifdef _DEBUG
		qDebug() << fileName.toLocal8Bit();
#endif
		m_pFile = new QFile(fileName);
		if (m_pFile->open(QIODevice::ReadOnly)) {
			m_pFtp->put(m_pFile, _ToSpecialEncoding(m_sCurrentPath + '/' + remoteName));
			return;
		}
		QMessageBox::information(nullptr, QStringLiteral("FTP"),
			QStringLiteral("无法上传该文件 %1: %2.")
			.arg(fileName).arg(m_pFile->errorString()));

		delete m_pFile;
		return;
	}
}

void UrielFtp::uploadFile(const QString &fileName, const QString &Path)
{
	if (!fileName.isEmpty())
	{
#ifdef _DEBUG
		qDebug() << fileName.toLocal8Bit();
#endif
		m_pFile = new QFile(fileName);
		if (m_pFile->open(QIODevice::ReadOnly)) {
			QFileInfo fi(m_pFile->fileName());
			m_pFtp->put(m_pFile, _ToSpecialEncoding(Path + '/' + fi.fileName()));
			//cdToParent();
			return;
		}
		QMessageBox::information(nullptr, QStringLiteral("FTP"),
			QStringLiteral("无法上传该文件 %1: %2.")
			.arg(fileName).arg(m_pFile->errorString()));

		delete m_pFile;
		return;
	}
}



void UrielFtp::uploadFileWithRemoteName(const QString &fileName, const  QString & remoteName, const QString &Path)
{
	if (!fileName.isEmpty())
	{
#ifdef _DEBUG
		qDebug() << fileName.toLocal8Bit();
#endif
		m_pFile = new QFile(fileName);
		if (m_pFile->open(QIODevice::ReadOnly)) {
			m_pFtp->put(m_pFile, _ToSpecialEncoding(Path + '/' + remoteName));
			//cdToParent();
			return;
		}
		QMessageBox::information(nullptr, QStringLiteral("FTP"),
			QStringLiteral("无法上传该文件 %1: %2.")
			.arg(fileName).arg(m_pFile->errorString()));

		delete m_pFile;
		return;
	}
}

void UrielFtp::deleteFile(const QString &fileName)
{
	int ret = QMessageBox::question(nullptr, QString::fromLocal8Bit(""),
		QString::fromLocal8Bit("确定删除该文件?").arg(fileName),
		QMessageBox::Ok, QMessageBox::No);

	switch (ret) {
	case QMessageBox::No:
		break;
	case QMessageBox::Ok:
		m_pFtp->remove(_ToSpecialEncoding(fileName));
		/*progressDialog->setLabelText(QString::fromLocal8Bit("正在删除 %1...").arg(fileName));
		progressDialog->exec();*/
		//cdToParent();
		break;
	}
}

void UrielFtp::cancelDownload()
{
	m_pFtp->abort();

	if (m_pFile->exists()) {
		m_pFile->close();
		m_pFile->remove();
	}
	delete m_pFile;
}

void UrielFtp::ftpCommandFinished(int, bool error)
{
	emit GUISetCursor();
	if (m_pFtp->currentCommand() == QFtp::ConnectToHost) {
		if (error) {
			QMessageBox::information(nullptr, tr("FTP"),
				tr("Unable to connect to the FTP server "
					"at %1. Please check that the host "
					"name is correct.")
				.arg(m_strUrl));
			connectOrDisconnect();
			return;
		}
		//statusLabel->setText(tr("Logged onto %1.").arg(ftpServerLineEdit->text()));
		return;
	}
	if (m_pFtp->currentCommand() == QFtp::Login)
		if (error) 
			QMessageBox::information(nullptr, "FTP",tr("登录出现错误：%1").arg(m_pFtp->errorString()));
		else
			m_pFtp->list();

	if (m_pFtp->currentCommand() == QFtp::Get) {
		if (error) {
			QMessageBox::information(nullptr, "FTP", QString::fromLocal8Bit("%1").arg(m_pFtp->errorString()));
				m_pFile->close();
				m_pFile->remove();
		}
		else {
			//statusLabel->setText(tr("Downloaded %1 to current directory.").arg(file->fileName()));
			m_pFile->close();
		}
		delete m_pFile;
		//m_pProgressDialog->hide();

	}
	else if (m_pFtp->currentCommand() == QFtp::List) {
		if (isDirectory.isEmpty()) {
			emit clearGUIList();
			/*fileList->addTopLevelItem(new QTreeWidgetItem(QStringList() << tr("<empty>")));
			fileList->setEnabled(false);*/
		}
	}
	else if (m_pFtp->currentCommand() == QFtp::Put) {
		if (error) QMessageBox::information(nullptr, "FTP", tr("上传出现错误：检查文件是否重名！").arg(m_pFtp->errorString())); 
		//else {
		//	ui->label->setText(tr("上传完成"));
		//	file->close();
		//	currentIndex++;
		//	if (currentIndex < indexCount) {
		//		this->uploadLocalFile(currentIndex);
		//	}
		//	else {
		//		currentIndex = 0;
		//		//刷新显示列表
		//		isDirectory.clear();
		//		ui->fileList->clear();
		//		ftp->list();
		//	}
		//}
	}
	else if (m_pFtp->currentCommand() == QFtp::Mkdir) {
		/*ui->label->setText(tr("新建文件夹完成"));*/
	//	//刷新显示列表
	//	isDirectory.clear();
	//	ui->fileList->clear();
	//	m_pFtp->list();
	//}
	//else if (m_pFtp->currentCommand() == QFtp::Remove) {
	//	currentIndex++;
	//	if (currentIndex >= indexCount) {
	//		ui->label->setText(tr("删除完成！"));
	//		isDirectory.clear(); 
	//		ui->fileList->clear();
	//		m_pFtp->list();
	//	}
	}
	else if (m_pFtp->currentCommand() == QFtp::Rmdir) {
		/*currentIndex++;
		if (currentIndex >= indexCount) {
			ui->label->setText(tr("删除完成！"));
			isDirectory.clear();
			ui->fileList->clear();
			m_pFtp->list();
		}*/
	}
	else if (m_pFtp->currentCommand() == QFtp::Close) {
		//ui->label->setText(tr("已经关闭连接"));
	}
}

void UrielFtp::addToList(const QUrielUrlInfo &urlInfo)
{

	QString xxx=urlInfo.name();
	//QPixmap pixmap(urlInfo.isDir() ? ":/images/dir.png" : ":/images/file.png");
	isDirectory[_FromSpecialEncoding(urlInfo.name())] = urlInfo.isDir();
	emit addToGuiList(urlInfo);
}

void UrielFtp::cdToNextPath(const QString &pathName)
{
	emit GUIClear();
	isDirectory.clear();
	m_sCurrentPath += '/';
	m_sCurrentPath += pathName;
	m_pFtp->cd(_ToSpecialEncoding(pathName));
	m_pFtp->list();
}

void UrielFtp::cd(const QString &name) {
	m_pFtp->cd(name);
}
void UrielFtp::list() {
	m_pFtp->list();
}
void UrielFtp::cdToSpecifiedPath(const QString &pathName)
{
	emit GUIClear();
	isDirectory.clear();
	m_sCurrentPath = pathName;
	m_pFtp->cd(_ToSpecialEncoding(pathName));
	m_pFtp->list();
}

void UrielFtp::cdToParent()
{
	emit GUIClear();
	isDirectory.clear();
	m_sCurrentPath = m_sCurrentPath.left(m_sCurrentPath.lastIndexOf('/'));
	if (m_sCurrentPath.isEmpty()) {
		m_pFtp->cd("/");
	}
	else {
		m_pFtp->cd(_ToSpecialEncoding(m_sCurrentPath));
	}
	m_pFtp->list();
}

void UrielFtp::cdToRootPath()
{
	cdToSpecifiedPath(m_sRootPath);
}

void UrielFtp::updateDataTransferProgress(qint64 readBytes,qint64 totalBytes)
{
	emit updateDataTransferProgressSignal(readBytes, totalBytes);
	//if (readBytes>= totalBytes)
	//	emit updateDataTransferFinishSignal();
	//m_pProgressDialog->setMaximum(totalBytes);
	//m_pProgressDialog->setValue(readBytes);
}

void UrielFtp::saveUsedConfiguration()
{
	// Save the used configuration
	QNetworkConfiguration config = m_pNetworkSession->configuration();
	QString id;
	if (config.type() == QNetworkConfiguration::UserChoice)
		id = m_pNetworkSession->sessionProperty(QLatin1String("UserChoiceConfiguration")).toString();
	else
		id = config.identifier();
	g_pOptions->setDefaultNetworkConfiguration(id);
}

void UrielFtp::enableConnectServer()
{
	//TODO:Set status (can connect to ftp server...)
	 saveUsedConfiguration();
}

void UrielFtp::mkdir(const QString DirName)
{
	if (!isDirectory.value(DirName))
	{
		emit GUIClear();
		isDirectory.clear();
		m_pFtp->mkdir(_ToSpecialEncoding(DirName));
		m_pFtp->list();
	}
	else
		QMessageBox::warning(nullptr,QStringLiteral("错误"), QStringLiteral("当前目录已存在该文件夹，不可创建同名文件夹！"));
}

void UrielFtp::removeAllFile(const QString & DirName) {
	if (DirName == ""|| DirName == "." || DirName == "..")
	{
		return;
	}
	QString name = DirName.split("/")[DirName.split("/").size() - 1];
	if (isDirectory.contains(name))
	{
		if (!isDirectory[name])
		{
			m_pFtp->remove(_ToSpecialEncoding(DirName));
		}
		else if (isDirectory[name])
		{
			//接收文件夹目录下所有的文件实例
			cdToNextPath(name);
			//文件夹为空 递归出口
			if (isDirectory.size())
			{
				return;
			}
			QHash<QString, bool>::const_iterator i;
			for (i = isDirectory.constBegin(); i != isDirectory.constEnd(); ++i) {
				removeAllFile(i.key());
			}
			cdToParent();
			m_pFtp->rmdir(_ToSpecialEncoding(DirName));
		}
	}
}

void UrielFtp::rmdir(const QString DirName)
{
	emit GUIClear();
	//removeAllFile(DirName);
	/*if(!isDirectory[DirName.split("/")[DirName.split("/").size()-1]])
		m_pFtp->remove(_ToSpecialEncoding(DirName));
	else {
		removeAllFile(DirName);
	}*/
	
	m_pFtp->rmdir(_ToSpecialEncoding(DirName));
	isDirectory.clear();
	m_pFtp->list();
}

void UrielFtp::rename(const QString &oldname, const QString &newname) {
	emit GUIClear();
	m_pFtp->rename(_ToSpecialEncoding(oldname), _ToSpecialEncoding(newname));
	isDirectory.clear();
	m_pFtp->list();
}
void UrielFtp::Remove(const QString& fileName) {
	emit GUIClear();
	isDirectory.clear();
	m_pFtp->remove(_ToSpecialEncoding(fileName));
	m_pFtp->list();
}

//有FTP端编码转本地编码
QString UrielFtp::_FromSpecialEncoding(const QString &InputStr)
{
	QTextCodec *codec = QTextCodec::codecForName("UTF-8");
	if (codec)
	{
		return codec->toUnicode(InputStr.toLatin1());
	}
	else
	{
		return QString("");
	}
//#ifdef Q_OS_WIN
//	return  QString::fromLocal8Bit(InputStr.toLatin1());
//#else
//	QTextCodec *codec = QTextCodec::codecForName("gbk");
//	if (codec)
//	{
//		return codec->toUnicode(InputStr.toLatin1());
//	}
//	else
//	{
//		return QString("");
//	}
//#endif
}
//put get等上传文件时，转换为FTP端编码
QString UrielFtp::_ToSpecialEncoding(const QString &InputStr)
{
	
		QTextCodec *codec = QTextCodec::codecForName("UTF-8");
		if (codec)
		{
			return QString::fromLatin1(codec->fromUnicode(InputStr));
		}
		else
		{
			return QString("");
		}
//#ifdef Q_OS_WIN
//	return QString::fromLatin1(InputStr.toLocal8Bit());
//#else
//	QTextCodec *codec = QTextCodec::codecForName("gbk");
//	if (codec)
//	{
//		return QString::fromLatin1(codec->fromUnicode(InputStr));
//	}
//	else
//	{
//		return QString("");
//	}
//#endif
}