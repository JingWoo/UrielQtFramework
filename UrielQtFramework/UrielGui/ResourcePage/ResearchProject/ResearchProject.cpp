#include "ResearchProject.h"
#include <QFileDialog>
#include <QFile>
#include "UrielDatabase\UrielDatabase.h"
#include "UrielQtFrameworkOptions\UrielQtFrameworkOptions.h"
#include "UrielFileTransfer\FTP\UrielFTP.h"
#include "UrielGui\CommonDialog\ProgressDialog\ProgressDialog.h"
#include "UrielGui\CommonDialog\InformationDialog\InformationDialog.h"
ResearchProject::ResearchProject(UrielDatabase * database, UrielQtFrameworkOptions *option, QWidget *parent)
	: QDialog(parent), m_database(database), m_options(option)
{
	ui.setupUi(this);
	initializeUI(parent);
	setSignalsAndSlots();
}

ResearchProject::~ResearchProject()
{
}


void ResearchProject::openWithEditMode(const sUrielResearchProjectItem & item)
{
	m_bIsEditMode = true;
	ui.ConfirmBtn->setText(QStringLiteral("确认更新"));
	m_stResearchProject = item;
	ui.Name->setText(m_stResearchProject.Name);
	ui.StartTime->setDateTime(m_stResearchProject.StartTime);
	ui.EndTime->setDateTime(m_stResearchProject.EndTime);
	ui.Type->setCurrentText(m_stResearchProject.Type);
	ui.Number->setText(m_stResearchProject.Number);
	ui.Funds->setText(m_stResearchProject.Funds);
	ui.Participants->setText(m_stResearchProject.Participants);

	QString dispalyString = "";
	QStringList remoteFileNameList = m_stResearchProject.ServerDataAddress.split(";");
	for each (QString var in remoteFileNameList)
	{
		if (!var.isEmpty())
			dispalyString += QFileInfo(var).fileName() + ";";
	}
	if (!dispalyString.isEmpty())
		dispalyString.resize(dispalyString.size() - 1);
	ui.ServerDataAddress->setText(dispalyString);

	ui.IndexedAddress->setText(m_stResearchProject.IndexedAddress);

	dispalyString = "";
	remoteFileNameList = m_stResearchProject.ServerPaperAddress.split(";");
	for each (QString var in remoteFileNameList)
	{
		if (!var.isEmpty())
			dispalyString += QFileInfo(var).fileName() + ";";
	}
	if (!dispalyString.isEmpty())
		dispalyString.resize(dispalyString.size() - 1);
	ui.ServerPaperAddress->setText(dispalyString);

	ui.Abstract->setPlainText(m_stResearchProject.Abstract);
}
void ResearchProject::initializeUI(QWidget *parent)
{
	this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());
	//this->setAttribute(Qt::WA_TranslucentBackground, true);

	this->resize(parent->geometry().width(), parent->geometry().height() - 45);
	this->move(parent->x(), parent->y() + 45);
	//set as Transparent degree
	//setWindowOpacity(0.7);
	//'国家级','省部级','国际科技合作项目','横向科研项目'
	QStringList list;
	list << QStringLiteral("国家级") << QStringLiteral("省部级") << QStringLiteral("国际科技合作项目") << QStringLiteral("横向科研项目");
	ui.Type->addItems(list);
	ui.Type->setCurrentIndex(0);
	ui.StartTime->setDateTime(QDateTime::currentDateTime());
	ui.EndTime->setDateTime(QDateTime::currentDateTime());
}

void ResearchProject::setSignalsAndSlots()
{
	QObject::connect(ui.AppClose, &QToolButton::clicked, this, &ResearchProject::reject);
	QObject::connect(ui.DataFileBrower, &QToolButton::clicked, this, &ResearchProject::onDataFileBrowerClicked);
	QObject::connect(ui.PaperFileBrower, &QToolButton::clicked, this, &ResearchProject::onPaperFileBrowerClicked);
	QObject::connect(ui.ConfirmBtn, &QToolButton::clicked, this, &ResearchProject::onConfirmClicked);
}

void ResearchProject::onDataFileBrowerClicked() {
	QStringList files = QFileDialog::getOpenFileNames(
		this, tr("QFileDialog::getOpenFileNames()"),
		QCoreApplication::applicationDirPath(),
		tr("All Files (*);;Word Files (*.doc);;PPT Files (*.ppt);;PDF Files (*.pdf);;Text Files (*.txt)"));
	if (files.count()) {
		for each (auto file in files)
		{

			m_sLoaclDataFilePaths += file + ";";
			QFileInfo fileInfo(file);
			m_sRemoteDataFilePaths += fileInfo.fileName() + ";";
		}
	}
	m_sRemoteDataFilePaths.resize(m_sRemoteDataFilePaths.length() - 1);
	m_sLoaclDataFilePaths.resize(m_sLoaclDataFilePaths.length() - 1);
	ui.ServerDataAddress->setText(m_sRemoteDataFilePaths);
	if (m_sLoaclDataFilePaths.split(";").count())
		m_bResearchProjectDataChange = true;
}

void ResearchProject::onPaperFileBrowerClicked() {
	QStringList files = QFileDialog::getOpenFileNames(
		this, tr("QFileDialog::getOpenFileNames()"),
		QCoreApplication::applicationDirPath(),
		tr("All Files (*);;Word Files (*.doc);;PPT Files (*.ppt);;PDF Files (*.pdf);;Text Files (*.txt)"));
	if (files.count()) {
		for each (auto file in files)
		{

			m_sLoaclPaperFilePaths += file + ";";
			QFileInfo fileInfo(file);
			m_sRemotePaperFilePaths += fileInfo.fileName() + ";";
		}
	}
	m_sRemotePaperFilePaths.resize(m_sRemotePaperFilePaths.length() - 1);
	m_sLoaclPaperFilePaths.resize(m_sLoaclPaperFilePaths.length() - 1);
	ui.ServerPaperAddress->setText(m_sRemotePaperFilePaths);
	if (m_sLoaclPaperFilePaths.split(";").count())
		m_bResearchProjectPaperChange = true;
}
void ResearchProject::onConfirmClicked() {
	UrielFtp *urielFtp = UrielFtp::getInstance();
	if (!m_bIsEditMode)//新增模式
	{
		QStringList fileNameList = m_sLoaclDataFilePaths.split(";");
		for each (QString var in fileNameList) {
			ProgressDialog *progressDialog = new ProgressDialog(this);
			progressDialog->setTotalProgressBarMax(1);
			QObject::connect(urielFtp, static_cast<void (UrielFtp::*)(qint64 readBytes, qint64 totalBytes)>(&UrielFtp::updateDataTransferProgressSignal), \
				progressDialog, &ProgressDialog::updateProgressBarValue);
			progressDialog->setTotalProgressBarMax(1);
			urielFtp->uploadFile(var, urielFtp->getRootPath() + "/ResearchProject");
			progressDialog->exec();
			QEventLoop eventloop;
			QTimer::singleShot(100, &eventloop, SLOT(quit()));
			eventloop.exec();
		}

		fileNameList = m_sLoaclPaperFilePaths.split(";");
		for each (QString var in fileNameList) {
			ProgressDialog *progressDialog = new ProgressDialog(this);
			progressDialog->setTotalProgressBarMax(1);
			QObject::connect(urielFtp, static_cast<void (UrielFtp::*)(qint64 readBytes, qint64 totalBytes)>(&UrielFtp::updateDataTransferProgressSignal), \
				progressDialog, &ProgressDialog::updateProgressBarValue);
			progressDialog->setTotalProgressBarMax(1);
			urielFtp->uploadFile(var, urielFtp->getRootPath() + "/ResearchProject");
			progressDialog->exec();
			QEventLoop eventloop;
			QTimer::singleShot(100, &eventloop, SLOT(quit()));
			eventloop.exec();
		}

		m_stResearchProject.Name = ui.Name->text();
		m_stResearchProject.StartTime = ui.StartTime->dateTime();
		m_stResearchProject.EndTime = ui.EndTime->dateTime();
		m_stResearchProject.Type = ui.Type->currentText();
		m_stResearchProject.Number = ui.Number->text();
		m_stResearchProject.Funds = ui.Funds->text();
		m_stResearchProject.Participants = ui.Participants->text();

		QString RemoteNoticesFilePath = urielFtp->getRootPath() + "/ResearchProject";
		QStringList remoteFileNameList = m_sRemoteDataFilePaths.split(";");
		m_sRemoteDataFilePaths = "";
		for each (QString var in remoteFileNameList)
		{
			if (!var.isEmpty())
				m_sRemoteDataFilePaths += (RemoteNoticesFilePath + "/" + var + ";");
		}
		if (!m_sRemoteDataFilePaths.isEmpty())
			m_sRemoteDataFilePaths.resize(m_sRemoteDataFilePaths.size() - 1);

		m_stResearchProject.ServerDataAddress = m_sRemoteDataFilePaths;

		m_stResearchProject.IndexedAddress = ui.IndexedAddress->text();

		remoteFileNameList = m_sRemotePaperFilePaths.split(";");
		m_sRemotePaperFilePaths = "";
		for each (QString var in remoteFileNameList)
		{
			if (!var.isEmpty())
				m_sRemotePaperFilePaths += (RemoteNoticesFilePath + "/" + var + ";");
		}
		if (!m_sRemotePaperFilePaths.isEmpty())
			m_sRemotePaperFilePaths.resize(m_sRemotePaperFilePaths.size() - 1);

		m_stResearchProject.ServerPaperAddress = m_sRemotePaperFilePaths;

		m_stResearchProject.Abstract = ui.Abstract->toPlainText();
		m_stResearchProject.Graduates = m_options->getAccount();
		m_stResearchProject.UploadTime = QDateTime::currentDateTime();
		m_stResearchProject.AuditStatus = QStringLiteral("未审核");
		m_stResearchProject.Auditor = QStringLiteral("");
		m_stResearchProject.AuditTime = QDateTime::currentDateTime();
		m_stResearchProject.DownloadCount = 0;
		m_database->insertResearchProject(m_stResearchProject);

		InformationDialog infodlg(QStringLiteral("信息"), QStringLiteral("科研项目-毕业生资料信息已添加至数据库！"), this);
		infodlg.exec();

		this->accept();
	}
	else {//编辑模式
		if (m_bResearchProjectDataChange) {
			//删除原来的论文
			QStringList fileList = m_stResearchProject.ServerDataAddress.split(";");
			for each (QString var in fileList)
				urielFtp->Remove(var);
			//上传新的论文
			QStringList fileNameList = m_sLoaclDataFilePaths.split(";");
			for each (QString var in fileNameList) {

				ProgressDialog *progressDialog = new ProgressDialog(this);
				progressDialog->setTotalProgressBarMax(1);
				QObject::connect(urielFtp, static_cast<void (UrielFtp::*)(qint64 readBytes, qint64 totalBytes)>(&UrielFtp::updateDataTransferProgressSignal), \
					progressDialog, &ProgressDialog::updateProgressBarValue);
				progressDialog->setTotalProgressBarMax(1);
				urielFtp->uploadFile(var, urielFtp->getRootPath() + "/ResearchProject");
				progressDialog->exec();
				QEventLoop eventloop;
				QTimer::singleShot(100, &eventloop, SLOT(quit()));
				eventloop.exec();
			}
		}

		if (m_bResearchProjectPaperChange) {
			//删除原来的论文
			QStringList fileList = m_stResearchProject.ServerPaperAddress.split(";");
			for each (QString var in fileList)
				urielFtp->Remove(var);
			//上传新的论文
			QStringList fileNameList = m_sLoaclPaperFilePaths.split(";");
			for each (QString var in fileNameList) {

				ProgressDialog *progressDialog = new ProgressDialog(this);
				progressDialog->setTotalProgressBarMax(1);
				QObject::connect(urielFtp, static_cast<void (UrielFtp::*)(qint64 readBytes, qint64 totalBytes)>(&UrielFtp::updateDataTransferProgressSignal), \
					progressDialog, &ProgressDialog::updateProgressBarValue);
				progressDialog->setTotalProgressBarMax(1);
				urielFtp->uploadFile(var, urielFtp->getRootPath() + "/ResearchProject");
				progressDialog->exec();
				QEventLoop eventloop;
				QTimer::singleShot(100, &eventloop, SLOT(quit()));
				eventloop.exec();
			}
		}


		m_stResearchProject.Name = ui.Name->text();
		m_stResearchProject.StartTime = ui.StartTime->dateTime();
		m_stResearchProject.EndTime = ui.EndTime->dateTime();
		m_stResearchProject.Type = ui.Type->currentText();
		m_stResearchProject.Number = ui.Number->text();
		m_stResearchProject.Funds = ui.Funds->text();
		m_stResearchProject.Participants = ui.Participants->text();

		QString RemoteNoticesFilePath = urielFtp->getRootPath() + "/ResearchProject";
		if (m_bResearchProjectDataChange) {
			
			QStringList remoteFileNameList = m_sRemoteDataFilePaths.split(";");
			m_sRemoteDataFilePaths = "";
			for each (QString var in remoteFileNameList)
			{
				if (!var.isEmpty())
					m_sRemoteDataFilePaths += (RemoteNoticesFilePath + "/" + var + ";");
			}
			if (!m_sRemoteDataFilePaths.isEmpty())
				m_sRemoteDataFilePaths.resize(m_sRemoteDataFilePaths.size() - 1);

			m_stResearchProject.ServerDataAddress = m_sRemoteDataFilePaths;
		}
		m_stResearchProject.IndexedAddress = ui.IndexedAddress->text();
		if (m_bResearchProjectPaperChange) {
			QStringList remoteFileNameList = m_sRemotePaperFilePaths.split(";");
			m_sRemotePaperFilePaths = "";
			for each (QString var in remoteFileNameList)
			{
				if (!var.isEmpty())
					m_sRemotePaperFilePaths += (RemoteNoticesFilePath + "/" + var + ";");
			}
			if (!m_sRemotePaperFilePaths.isEmpty())
				m_sRemotePaperFilePaths.resize(m_sRemotePaperFilePaths.size() - 1);

			m_stResearchProject.ServerPaperAddress = m_sRemotePaperFilePaths;
		}
		m_stResearchProject.Abstract = ui.Abstract->toPlainText();
		m_stResearchProject.Graduates = m_options->getAccount();
		m_stResearchProject.UploadTime = QDateTime::currentDateTime();
		m_stResearchProject.AuditStatus = QStringLiteral("未审核");
		m_stResearchProject.Auditor = QStringLiteral("");
		m_stResearchProject.AuditTime = QDateTime::currentDateTime();

		m_database->updateResearchProject(m_stResearchProject);
		InformationDialog infodlg(QStringLiteral("信息"), QStringLiteral("科研项目-毕业生资料信息已更新至数据库！"), this);
		infodlg.exec();
		this->accept();
	}
}

