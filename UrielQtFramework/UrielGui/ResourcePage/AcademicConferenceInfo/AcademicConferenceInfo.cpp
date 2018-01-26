#include "AcademicConferenceInfo.h"
#include <QFileDialog>
#include <QFile>
#include "UrielDatabase\UrielDatabase.h"
#include "UrielQtFrameworkOptions\UrielQtFrameworkOptions.h"
#include "UrielFileTransfer\FTP\UrielFTP.h"
#include "UrielGui\CommonDialog\ProgressDialog\ProgressDialog.h"
#include "UrielGui\CommonDialog\InformationDialog\InformationDialog.h"
AcademicConferenceInfo::AcademicConferenceInfo(UrielDatabase * database, UrielQtFrameworkOptions *option, QWidget *parent)
	: QDialog(parent), m_database(database), m_options(option)
{
	ui.setupUi(this);
	initializeUI(parent);
	setSignalsAndSlots();
}

AcademicConferenceInfo::~AcademicConferenceInfo()
{
}

void AcademicConferenceInfo::openWithEditMode(const sUrielAcademicConferenceItem & item)
{
	m_bIsEditMode = true;
	ui.ConfirmBtn->setText(QStringLiteral("确认更新"));
	m_stAcademicConferenceInfo = item;
	ui.OriginalTitle->setText(m_stAcademicConferenceInfo.OriginalTitle);
	ui.TranslationTitle->setText(m_stAcademicConferenceInfo.TranslationTitle);
	ui.ReleaseTime->setDateTime(m_stAcademicConferenceInfo.ReleaseTime);
	m_stAcademicConferenceInfo.ConferenceLanguage == QStringLiteral("英文") ? \
		ui.ConferenceLanguage_English->setChecked(true) : ui.ConferenceLanguage_Chinese->setChecked(true);
	ui.PublicationForm->setCurrentText(m_stAcademicConferenceInfo.PublicationForm);
	ui.Author->setText(m_stAcademicConferenceInfo.Author);
	ui.ConferenceName->setText(m_stAcademicConferenceInfo.ConferenceName);
	ui.ConferenceSessionsNumber->setText(m_stAcademicConferenceInfo.ConferenceSessionsNumber);
	ui.IndexedAddress->setText(m_stAcademicConferenceInfo.IndexedAddress);
	QString dispalyString = "";
	QStringList remoteFileNameList = m_stAcademicConferenceInfo.ServerFileAddress.split(";");
	for each (QString var in remoteFileNameList)
	{
		if (!var.isEmpty())
			dispalyString += QFileInfo(var).fileName() + ";";
	}
	if (!dispalyString.isEmpty())
		dispalyString.resize(dispalyString.size() - 1);
	ui.ServerFileAddress->setText(dispalyString);
	ui.Abstract->setPlainText(m_stAcademicConferenceInfo.Abstract);

}
void AcademicConferenceInfo::initializeUI(QWidget *parent)
{
	this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());
	//this->setAttribute(Qt::WA_TranslucentBackground, true);

	this->resize(parent->geometry().width(), parent->geometry().height() - 45);
	this->move(parent->x(), parent->y() + 45);
	//set as Transparent degree
	//setWindowOpacity(0.7);
	//'主报告', '宣读论文', '墙报论文'
	QStringList list;
	list << QStringLiteral("主报告") << QStringLiteral("宣读论文") << QStringLiteral("墙报论文") ;
	ui.PublicationForm->addItems(list);
	ui.PublicationForm->setCurrentIndex(0);
}

void AcademicConferenceInfo::setSignalsAndSlots()
{
	QObject::connect(ui.AppClose, &QToolButton::clicked, this, &AcademicConferenceInfo::reject);
	QObject::connect(ui.FileBrower, &QToolButton::clicked, this, &AcademicConferenceInfo::onFileBrowerClicked);
	QObject::connect(ui.ConfirmBtn, &QToolButton::clicked, this, &AcademicConferenceInfo::onConfirmClicked);
}

void AcademicConferenceInfo::onFileBrowerClicked() {
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
		m_bAcademicConferenceChange = true;
}

void AcademicConferenceInfo::onConfirmClicked() {
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
			urielFtp->uploadFile(var, urielFtp->getRootPath() + "/AcademicConference");
			progressDialog->exec();
			QEventLoop eventloop;
			QTimer::singleShot(100, &eventloop, SLOT(quit()));
			eventloop.exec();
		}

		m_stAcademicConferenceInfo.OriginalTitle = ui.OriginalTitle->text();
		m_stAcademicConferenceInfo.TranslationTitle = ui.TranslationTitle->text();
		m_stAcademicConferenceInfo.ReleaseTime = ui.ReleaseTime->dateTime();
		m_stAcademicConferenceInfo.ConferenceLanguage = ui.ConferenceLanguage_English->isChecked() ? QStringLiteral("英文") : QStringLiteral("中文");
		m_stAcademicConferenceInfo.PublicationForm = ui.PublicationForm->currentText();
		m_stAcademicConferenceInfo.Author = ui.Author->text();
		m_stAcademicConferenceInfo.ConferenceName = ui.ConferenceName->text();
		m_stAcademicConferenceInfo.ConferenceSessionsNumber = ui.ConferenceSessionsNumber->text();
		m_stAcademicConferenceInfo.IndexedAddress = ui.IndexedAddress->text();

		QString RemoteNoticesFilePath = urielFtp->getRootPath() + "/AcademicConference";
		QStringList remoteFileNameList = m_sRemoteFilePaths.split(";");
		m_sRemoteFilePaths = "";
		for each (QString var in remoteFileNameList)
		{
			if (!var.isEmpty())
				m_sRemoteFilePaths += (RemoteNoticesFilePath + "/" + var + ";");
		}
		if (!m_sRemoteFilePaths.isEmpty())
			m_sRemoteFilePaths.resize(m_sRemoteFilePaths.size() - 1);

		m_stAcademicConferenceInfo.ServerFileAddress = m_sRemoteFilePaths;

		m_stAcademicConferenceInfo.Abstract = ui.Abstract->toPlainText();
		m_stAcademicConferenceInfo.Uploader = m_options->getAccount();
		m_stAcademicConferenceInfo.UploadTime = QDateTime::currentDateTime();
		m_stAcademicConferenceInfo.DownloadCount = 0;
		m_database->insertAcademicConference(m_stAcademicConferenceInfo);

		InformationDialog infodlg(QStringLiteral("信息"), QStringLiteral("会议信息已添加至数据库！"), this);
		infodlg.exec();

		this->accept();
	}
	else {//编辑模式
		if (m_bAcademicConferenceChange) {
			//删除原来的论文
			QStringList fileList = m_stAcademicConferenceInfo.ServerFileAddress.split(";");
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
				urielFtp->uploadFile(var, urielFtp->getRootPath() + "/AcademicConference");
				progressDialog->exec();
				QEventLoop eventloop;
				QTimer::singleShot(100, &eventloop, SLOT(quit()));
				eventloop.exec();
			}
		}
		m_stAcademicConferenceInfo.OriginalTitle = ui.OriginalTitle->text();
		m_stAcademicConferenceInfo.TranslationTitle = ui.TranslationTitle->text();
		m_stAcademicConferenceInfo.ReleaseTime = ui.ReleaseTime->dateTime();
		m_stAcademicConferenceInfo.ConferenceLanguage = ui.ConferenceLanguage_English->isChecked() ? QStringLiteral("英文") : QStringLiteral("中文");
		m_stAcademicConferenceInfo.PublicationForm = ui.PublicationForm->currentText();
		m_stAcademicConferenceInfo.Author = ui.Author->text();
		m_stAcademicConferenceInfo.ConferenceName = ui.ConferenceName->text();
		m_stAcademicConferenceInfo.ConferenceSessionsNumber = ui.ConferenceSessionsNumber->text();
		m_stAcademicConferenceInfo.IndexedAddress = ui.IndexedAddress->text();


		if (m_bAcademicConferenceChange) {
			QString RemoteNoticesFilePath = urielFtp->getRootPath() + "/AcademicConference";
			QStringList remoteFileNameList = m_sRemoteFilePaths.split(";");
			m_sRemoteFilePaths = "";
			for each (QString var in remoteFileNameList)
			{
				if (!var.isEmpty())
					m_sRemoteFilePaths += (RemoteNoticesFilePath + "/" + var + ";");
			}
			if (!m_sRemoteFilePaths.isEmpty())
				m_sRemoteFilePaths.resize(m_sRemoteFilePaths.size() - 1);

			m_stAcademicConferenceInfo.ServerFileAddress = m_sRemoteFilePaths;
		}
		m_stAcademicConferenceInfo.Abstract = ui.Abstract->toPlainText();
		m_stAcademicConferenceInfo.Uploader = m_options->getAccount();
		m_stAcademicConferenceInfo.UploadTime = QDateTime::currentDateTime();
		//m_stAcademicConferenceInfo.DownloadCount = 0;
		m_database->updateAcademicConference(m_stAcademicConferenceInfo);
		InformationDialog infodlg(QStringLiteral("信息"), QStringLiteral("会议信息已更新至数据库！"), this);
		infodlg.exec();
		this->accept();
	}
}