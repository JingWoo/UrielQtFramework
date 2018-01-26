#include "PatentInfo.h"
#include <QFileDialog>
#include <QFile>
#include "UrielDatabase\UrielDatabase.h"
#include "UrielQtFrameworkOptions\UrielQtFrameworkOptions.h"
#include "UrielFileTransfer\FTP\UrielFTP.h"
#include "UrielGui\CommonDialog\ProgressDialog\ProgressDialog.h"
#include "UrielGui\CommonDialog\InformationDialog\InformationDialog.h"
PatentInfo::PatentInfo(UrielDatabase * database, UrielQtFrameworkOptions *option, QWidget *parent)
	: QDialog(parent), m_database(database), m_options(option)
{
	ui.setupUi(this);
	initializeUI(parent);
	setSignalsAndSlots();
}

PatentInfo::~PatentInfo()
{
}


void PatentInfo::openWithEditMode(const sUrielPatentItem & item)
{
	m_bIsEditMode = true;
	ui.ConfirmBtn->setText(QStringLiteral("确认更新"));
	m_stPatentInfo = item;
	ui.Type->setCurrentText(m_stPatentInfo.Type);
	ui.Number->setText(m_stPatentInfo.Number);
	ui.Name->setText(m_stPatentInfo.Name);
	ui.ApplyTime->setDateTime(m_stPatentInfo.ApplyTime);
	ui.ReleaseTime->setDateTime(m_stPatentInfo.ReleaseTime);
	ui.AuthorizationTime->setDateTime(m_stPatentInfo.AuthorizationTime);
	ui.CopyRightUnit->setText(m_stPatentInfo.CopyRightUnit);
	ui.Author->setText(m_stPatentInfo.Author);
	ui.IndexedAddress->setText(m_stPatentInfo.IndexedAddress);
	QString dispalyString = "";
	QStringList remoteFileNameList = m_stPatentInfo.ServerFileAddress.split(";");
	for each (QString var in remoteFileNameList)
	{
		if (!var.isEmpty())
			dispalyString += QFileInfo(var).fileName() + ";";
	}
	if (!dispalyString.isEmpty())
		dispalyString.resize(dispalyString.size() - 1);
	ui.ServerFileAddress->setText(dispalyString);
	ui.Abstract->setPlainText(m_stPatentInfo.Abstract);
}
void PatentInfo::initializeUI(QWidget *parent)
{
	this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());
	//this->setAttribute(Qt::WA_TranslucentBackground, true);

	this->resize(parent->geometry().width(), parent->geometry().height() - 45);
	this->move(parent->x(), parent->y() + 45);
	//set as Transparent degree
	//setWindowOpacity(0.7);
	QStringList list;
	list << QStringLiteral("发明专利") << QStringLiteral("实用新型与外观设计专利") << QStringLiteral("计算机软件著作权");
	ui.Type->addItems(list);
	ui.Type->setCurrentIndex(0);

	ui.ApplyTime->setDateTime(QDateTime::currentDateTime());
	ui.ReleaseTime->setDateTime(QDateTime::currentDateTime());
	ui.AuthorizationTime->setDateTime(QDateTime::currentDateTime());
}

void PatentInfo::setSignalsAndSlots()
{
	QObject::connect(ui.AppClose, &QToolButton::clicked, this, &PatentInfo::reject);
	QObject::connect(ui.FileBrower, &QToolButton::clicked, this, &PatentInfo::onFileBrowerClicked);
	QObject::connect(ui.ConfirmBtn, &QToolButton::clicked, this, &PatentInfo::onConfirmClicked);
}

void PatentInfo::onFileBrowerClicked() {
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
		m_bPatentChange = true;
}

void PatentInfo::onConfirmClicked() {
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
			urielFtp->uploadFile(var, urielFtp->getRootPath() + "/Patent");
			progressDialog->exec();
			QEventLoop eventloop;
			QTimer::singleShot(100, &eventloop, SLOT(quit()));
			eventloop.exec();
		}

		m_stPatentInfo.Type = ui.Type->currentText();
		m_stPatentInfo.Number = ui.Number->text();
		m_stPatentInfo.Name = ui.Name->text();
		m_stPatentInfo.ApplyTime = ui.ApplyTime->dateTime();
		m_stPatentInfo.ReleaseTime = ui.ReleaseTime->dateTime();
		m_stPatentInfo.AuthorizationTime = ui.AuthorizationTime->dateTime();
		m_stPatentInfo.CopyRightUnit = ui.CopyRightUnit->text();
		m_stPatentInfo.Author = ui.Author->text();
		m_stPatentInfo.IndexedAddress = ui.IndexedAddress->text();

		QString RemoteNoticesFilePath = urielFtp->getRootPath() + "/Patent";
		QStringList remoteFileNameList = m_sRemoteFilePaths.split(";");
		m_sRemoteFilePaths = "";
		for each (QString var in remoteFileNameList)
		{
			if (!var.isEmpty())
				m_sRemoteFilePaths += (RemoteNoticesFilePath + "/" + var + ";");
		}
		if (!m_sRemoteFilePaths.isEmpty())
			m_sRemoteFilePaths.resize(m_sRemoteFilePaths.size() - 1);

		m_stPatentInfo.ServerFileAddress = m_sRemoteFilePaths;

		m_stPatentInfo.Abstract = ui.Abstract->toPlainText();
		m_stPatentInfo.Uploader = m_options->getAccount();
		m_stPatentInfo.UploadTime = QDateTime::currentDateTime();
		m_stPatentInfo.DownloadCount = 0;
		m_database->insertPatent(m_stPatentInfo);

		InformationDialog infodlg(QStringLiteral("信息"), QStringLiteral("专利信息已添加至数据库！"), this);
		infodlg.exec();

		this->accept();
	}
	else {//编辑模式
		if (m_bPatentChange) {
			//删除原来的论文
			QStringList fileList = m_stPatentInfo.ServerFileAddress.split(";");
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
				urielFtp->uploadFile(var, urielFtp->getRootPath() + "/Patent");
				progressDialog->exec();
				QEventLoop eventloop;
				QTimer::singleShot(100, &eventloop, SLOT(quit()));
				eventloop.exec();
			}
		}
		m_stPatentInfo.Type = ui.Type->currentText();
		m_stPatentInfo.Number = ui.Number->text();
		m_stPatentInfo.Name = ui.Name->text();
		m_stPatentInfo.ApplyTime = ui.ApplyTime->dateTime();
		m_stPatentInfo.ReleaseTime = ui.ReleaseTime->dateTime();
		m_stPatentInfo.AuthorizationTime = ui.AuthorizationTime->dateTime();
		m_stPatentInfo.CopyRightUnit = ui.CopyRightUnit->text();
		m_stPatentInfo.Author = ui.Author->text();
		m_stPatentInfo.IndexedAddress = ui.IndexedAddress->text();

		if (m_bPatentChange) {
			QString RemoteNoticesFilePath = urielFtp->getRootPath() + "/Patent";
			QStringList remoteFileNameList = m_sRemoteFilePaths.split(";");
			m_sRemoteFilePaths = "";
			for each (QString var in remoteFileNameList)
			{
				if (!var.isEmpty())
					m_sRemoteFilePaths += (RemoteNoticesFilePath + "/" + var + ";");
			}
			if (!m_sRemoteFilePaths.isEmpty())
				m_sRemoteFilePaths.resize(m_sRemoteFilePaths.size() - 1);

			m_stPatentInfo.ServerFileAddress = m_sRemoteFilePaths;
		}
		m_stPatentInfo.Abstract = ui.Abstract->toPlainText();
		m_stPatentInfo.Uploader = m_options->getAccount();
		m_stPatentInfo.UploadTime = QDateTime::currentDateTime();
		//m_stPatentInfo.DownloadCount = 0;
		m_database->updatePatent(m_stPatentInfo);
		InformationDialog infodlg(QStringLiteral("信息"), QStringLiteral("专利信息已更新至数据库！"), this);
		infodlg.exec();
		this->accept();
	}
}
