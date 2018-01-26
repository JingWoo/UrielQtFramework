#include "WorksInfo.h"
#include <QFileDialog>
#include <QFile>
#include "UrielDatabase\UrielDatabase.h"
#include "UrielQtFrameworkOptions\UrielQtFrameworkOptions.h"
#include "UrielFileTransfer\FTP\UrielFTP.h"
#include "UrielGui\CommonDialog\ProgressDialog\ProgressDialog.h"
#include "UrielGui\CommonDialog\InformationDialog\InformationDialog.h"
WorksInfo::WorksInfo(UrielDatabase * database, UrielQtFrameworkOptions *option, QWidget *parent)
	: QDialog(parent), m_database(database), m_options(option)
{
	ui.setupUi(this);
	initializeUI(parent);
	setSignalsAndSlots();
}

WorksInfo::~WorksInfo()
{

}

void WorksInfo::openWithEditMode(const sUrielWorksItem & item)
{
	m_bIsEditMode = true;
	ui.ConfirmBtn->setText(QStringLiteral("确认更新"));
	m_stWorksInfo = item;
	ui.Type->setCurrentText(m_stWorksInfo.Type);
	ui.Name->setText(m_stWorksInfo.Name);
	ui.PublishingHouse->setText(m_stWorksInfo.PublishingHouse);
	ui.EmploymentTime->setDateTime(m_stWorksInfo.EmploymentTime);
	ui.PublishingTime->setDateTime(m_stWorksInfo.PublishingTime);
	ui.ISBN->setText(m_stWorksInfo.ISBN);
	ui.Author->setText(m_stWorksInfo.Author);
	QString dispalyString = "";
	QStringList remoteFileNameList = m_stWorksInfo.ServerFileAddress.split(";");
	for each (QString var in remoteFileNameList)
	{
		if (!var.isEmpty())
			dispalyString += QFileInfo(var).fileName() + ";";
	}
	if (!dispalyString.isEmpty())
		dispalyString.resize(dispalyString.size() - 1);
	ui.ServerFileAddress->setText(dispalyString);
	ui.Abstract->setPlainText(m_stWorksInfo.Abstract);
}
void WorksInfo::initializeUI(QWidget *parent)
{
	this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());
	//this->setAttribute(Qt::WA_TranslucentBackground, true);

	this->resize(parent->geometry().width(), parent->geometry().height() - 45);
	this->move(parent->x(), parent->y() + 45);
	//set as Transparent degree
	//setWindowOpacity(0.7);
	QStringList list;
	list << QStringLiteral("专著") << QStringLiteral("编著") << QStringLiteral("编译") << QStringLiteral("校注");
	ui.Type->addItems(list);
	ui.Type->setCurrentIndex(0);
	ui.EmploymentTime->setDateTime(QDateTime::currentDateTime());
	ui.PublishingTime->setDateTime(QDateTime::currentDateTime());
}

void WorksInfo::setSignalsAndSlots()
{
	QObject::connect(ui.AppClose, &QToolButton::clicked, this, &WorksInfo::reject);
	QObject::connect(ui.FileBrower, &QToolButton::clicked, this, &WorksInfo::onFileBrowerClicked);
	QObject::connect(ui.ConfirmBtn, &QToolButton::clicked, this, &WorksInfo::onConfirmClicked);
}

void WorksInfo::onFileBrowerClicked() {
	QStringList files = QFileDialog::getOpenFileNames(
		this, tr("QFileDialog::getOpenFileNames()"),
		QCoreApplication::applicationDirPath(),
		tr("All Files (*);;Word Files (*.doc);;PPT Files (*.ppt);;PDF Files (*.pdf);;Text Files (*.txt)"));
	if (files.count()) {
		for each (auto file in files)
		{

			m_sLoaclFilePaths += file + ";";
			QFileInfo fileInfo(file);
			m_sRemoteFilePaths += fileInfo.fileName() + ";";
		}
	}
	m_sRemoteFilePaths.resize(m_sRemoteFilePaths.length() - 1);
	m_sLoaclFilePaths.resize(m_sLoaclFilePaths.length() - 1);
	ui.ServerFileAddress->setText(m_sRemoteFilePaths);
	if (m_sLoaclFilePaths.split(";").count())
		m_bWorksChange = true;
}

void WorksInfo::onConfirmClicked() {
	UrielFtp *urielFtp = UrielFtp::getInstance();
	if (!m_bIsEditMode)//新增模式
	{
		QStringList fileNameList = m_sLoaclFilePaths.split(";");
		for each (QString var in fileNameList) {

			ProgressDialog *progressDialog = new ProgressDialog(this);
			progressDialog->setTotalProgressBarMax(1);
			QObject::connect(urielFtp, static_cast<void (UrielFtp::*)(qint64 readBytes, qint64 totalBytes)>(&UrielFtp::updateDataTransferProgressSignal), \
				progressDialog, &ProgressDialog::updateProgressBarValue);
			progressDialog->setTotalProgressBarMax(1);
			urielFtp->uploadFile(var, urielFtp->getRootPath() + "/Works");
			progressDialog->exec();
			QEventLoop eventloop;
			QTimer::singleShot(100, &eventloop, SLOT(quit()));
			eventloop.exec();
		}

		m_stWorksInfo.Type = ui.Type->currentText();
		m_stWorksInfo.Name = ui.Name->text();
		m_stWorksInfo.PublishingHouse = ui.PublishingHouse->text();
		m_stWorksInfo.EmploymentTime = ui.EmploymentTime->dateTime();
		m_stWorksInfo.PublishingTime = ui.PublishingTime->dateTime();
		m_stWorksInfo.ISBN = ui.ISBN->text();
		m_stWorksInfo.PrintingTimes = ui.PrintingTimes->text();
		m_stWorksInfo.Author = ui.Author->text();

		QString RemoteNoticesFilePath = urielFtp->getRootPath() + "/Works";
		QStringList remoteFileNameList = m_sRemoteFilePaths.split(";");
		m_sRemoteFilePaths = "";
		for each (QString var in remoteFileNameList)
		{
			if (!var.isEmpty())
				m_sRemoteFilePaths += (RemoteNoticesFilePath + "/" + var + ";");
		}
		if (!m_sRemoteFilePaths.isEmpty())
			m_sRemoteFilePaths.resize(m_sRemoteFilePaths.size() - 1);

		m_stWorksInfo.ServerFileAddress = m_sRemoteFilePaths;

		m_stWorksInfo.Abstract = ui.Abstract->toPlainText();
		m_stWorksInfo.Uploader = m_options->getAccount();
		m_stWorksInfo.UploadTime = QDateTime::currentDateTime();
		m_stWorksInfo.DownloadCount = 0;
		m_database->insertWorks(m_stWorksInfo);

		InformationDialog infodlg(QStringLiteral("信息"), QStringLiteral("著作信息已添加至数据库！"), this);
		infodlg.exec();

		this->accept();
	}
	else {//编辑模式
		if (m_bWorksChange) {
			//删除原来的论文
			QStringList fileList = m_stWorksInfo.ServerFileAddress.split(";");
			for each (QString var in fileList)
				urielFtp->Remove(var);
			//上传新的论文
			QStringList fileNameList = m_sLoaclFilePaths.split(";");
			for each (QString var in fileNameList) {

				ProgressDialog *progressDialog = new ProgressDialog(this);
				progressDialog->setTotalProgressBarMax(1);
				QObject::connect(urielFtp, static_cast<void (UrielFtp::*)(qint64 readBytes, qint64 totalBytes)>(&UrielFtp::updateDataTransferProgressSignal), \
					progressDialog, &ProgressDialog::updateProgressBarValue);
				progressDialog->setTotalProgressBarMax(1);
				urielFtp->uploadFile(var, urielFtp->getRootPath() + "/Works");
				progressDialog->exec();
				QEventLoop eventloop;
				QTimer::singleShot(100, &eventloop, SLOT(quit()));
				eventloop.exec();
			}
		}

		m_stWorksInfo.Type = ui.Type->currentText();
		m_stWorksInfo.Name = ui.Name->text();
		m_stWorksInfo.PublishingHouse = ui.PublishingHouse->text();
		m_stWorksInfo.EmploymentTime = ui.EmploymentTime->dateTime();
		m_stWorksInfo.PublishingTime = ui.PublishingTime->dateTime();
		m_stWorksInfo.ISBN = ui.ISBN->text();
		m_stWorksInfo.PrintingTimes = ui.PrintingTimes->text();
		m_stWorksInfo.Author = ui.Author->text();

		if (m_bWorksChange) {
			QString RemoteNoticesFilePath = urielFtp->getRootPath() + "/Works";
			QStringList remoteFileNameList = m_sRemoteFilePaths.split(";");
			m_sRemoteFilePaths = "";
			for each (QString var in remoteFileNameList)
			{
				if (!var.isEmpty())
					m_sRemoteFilePaths += (RemoteNoticesFilePath + "/" + var + ";");
			}
			if (!m_sRemoteFilePaths.isEmpty())
				m_sRemoteFilePaths.resize(m_sRemoteFilePaths.size() - 1);

			m_stWorksInfo.ServerFileAddress = m_sRemoteFilePaths;
		}
		m_stWorksInfo.Abstract = ui.Abstract->toPlainText();
		m_stWorksInfo.Uploader = m_options->getAccount();
		m_stWorksInfo.UploadTime = QDateTime::currentDateTime();
		//m_stWorksInfo.DownloadCount = 0;
		m_database->updateWorks(m_stWorksInfo);
		InformationDialog infodlg(QStringLiteral("信息"), QStringLiteral("著作信息已更新至数据库！"), this);
		infodlg.exec();
		this->accept();
	}
}
