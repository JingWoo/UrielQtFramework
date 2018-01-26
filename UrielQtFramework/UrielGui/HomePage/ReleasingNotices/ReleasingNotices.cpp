#include "ReleasingNotices.h"
#include <QPainter>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include "UrielDatabase\UrielDatabase.h"
#include "UrielQtFrameworkOptions\UrielQtFrameworkOptions.h"
#include "UrielFileTransfer\FTP\UrielFTP.h"
#include "UrielGui\CommonDialog\ProgressDialog\ProgressDialog.h"
#include "UrielGui\CommonDialog\InformationDialog\InformationDialog.h"
#include "UrielSMTPEmail\UrielSMTPEmail.h"
ReleasingNotices::ReleasingNotices(UrielDatabase * database, UrielQtFrameworkOptions *option, QWidget *parent)
	: QDialog(parent), m_database(database),m_options(option)
{
	ui.setupUi(this);
	initializeUI(parent);
	setSignalsAndSlots();
}

ReleasingNotices::~ReleasingNotices()
{

}

void ReleasingNotices::initializeUI(QWidget *parent)
{
	this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());
	//this->setAttribute(Qt::WA_TranslucentBackground, true);

	this->resize(parent->geometry().width(), parent->geometry().height() - 45);
	this->move(parent->x(), parent->y() + 45);
	//set as Transparent degree
	//setWindowOpacity(0.7);

	//ui.ImportanceDegree->setStyleSheet("QComboBox{border:1px solid gray;}"
	//	"QComboBox QAbstractItemView::item{height:20px;}" //下拉选项高度
	//	"QComboBox::drop-down{border:0px;}"); //下拉按钮
	ui.ImportanceDegree->addItem(QIcon(":/Mainwindow/Resources/UrielQtFramework/generalNotices.png"), QStringLiteral("一般通知"));
	ui.ImportanceDegree->addItem(QIcon(":/Mainwindow/Resources/UrielQtFramework/importantNotices.png"), QStringLiteral("重要通知"));
	ui.ImportanceDegree->addItem(QIcon(":/Mainwindow/Resources/UrielQtFramework/emergencyNotice.png"), QStringLiteral("紧急通知"));
	ui.ImportanceDegree->setCurrentIndex(0);

	//int todayAlreadyReleaseNum;
	//m_database->getCurrentDataNotificationCount(todayAlreadyReleaseNum);
	if (!m_bIsEditMode)
	{
		int lastCodeId;
		m_database->getLastNoticesCodeID(lastCodeId);
		ui.NoticeCode->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd") + "_" + QString("%1").arg(lastCodeId + 1, 3, 10, QLatin1Char('0')));
	}
}

void ReleasingNotices::setSignalsAndSlots()
{
	QObject::connect(ui.AppClose,&QToolButton::clicked,this,&ReleasingNotices::reject);
	QObject::connect(ui.NoticeFileBrower, &QToolButton::clicked, this, &ReleasingNotices::onNoticeFileBrowerClicked);
	QObject::connect(ui.ConfirmReleaseNotice, &QToolButton::clicked, this, &ReleasingNotices::onConfirmReleaseNoticeClicked);

}

void ReleasingNotices::openWithEditMode(const sUrielNotificationsItem & item)
{
	m_bIsEditMode = true;
	ui.ConfirmReleaseNotice->setText(QStringLiteral("修改通知"));
	ui.NoticeCode->setText(item.m_sCode);
	ui.NoticeTitle->setText(item.m_sTitle);
	ui.NoticeFile->setText(item.m_sFilePaths);
	if(item.m_sImportantDegree== QStringLiteral("一般通知"))
		ui.ImportanceDegree->setCurrentIndex(0);
	else if (item.m_sImportantDegree == QStringLiteral("重要通知"))
			ui.ImportanceDegree->setCurrentIndex(1);
	else
		ui.ImportanceDegree->setCurrentIndex(2);
	ui.NoticeContent->setPlainText(item.m_sContent);
	
}

void ReleasingNotices::onNoticeFileBrowerClicked()
{
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
	m_sRemoteFilePaths.resize(m_sRemoteFilePaths.length()-1);
	m_sLoaclFilePaths.resize(m_sLoaclFilePaths.length() - 1);
	ui.NoticeFile->setText(m_sRemoteFilePaths);
}

void ReleasingNotices::onConfirmReleaseNoticeClicked()
{
	sUrielNotificationsItem notifications_item;
	notifications_item.m_sCode = ui.NoticeCode->text();
	notifications_item.m_sTitle = ui.NoticeTitle->text();
	notifications_item.m_sImportantDegree = ui.ImportanceDegree->currentText();
	notifications_item.m_sContent = ui.NoticeContent->toPlainText();
	notifications_item.m_tReleaseTime = QDateTime::currentDateTime();
	notifications_item.m_sNotifingPublisher = m_options->getAccount();

	UrielFtp *urielFtp = UrielFtp::getInstance();
	QString RemoteNoticesFilePath= urielFtp->getRootPath() + "/Notices/" + m_options->getAccount();
	QStringList remoteFileNameList = m_sRemoteFilePaths.split(";");
	m_sRemoteFilePaths = "";
	for each (QString var in remoteFileNameList)
	{
		if(!var.isEmpty())
		     m_sRemoteFilePaths += (RemoteNoticesFilePath + "/" + var + ";");
	}
	if(!m_sRemoteFilePaths.isEmpty())
		m_sRemoteFilePaths.resize(m_sRemoteFilePaths.size()-1);
	notifications_item.m_sFilePaths = m_sRemoteFilePaths;
	//urielFtp->cdToSpecifiedPath(urielFtp->getRootPath() + "/Notices/");
	//QHash<QString, bool> dirInfo = urielFtp->getDirInfo();
	//if (!dirInfo.value(m_options->getAccount()))
	//	urielFtp->mkdir(m_options->getAccount());
	//urielFtp->cdToNextPath(m_options->getAccount());
	if (!m_bIsEditMode)
	{
		QString errorInfo;
		m_database->insertNotification(notifications_item, errorInfo);
		if (!errorInfo.isEmpty())
		{
			QMessageBox::critical(nullptr, QStringLiteral("错误"), QStringLiteral("数据库插入通知信息失败，请联系管理员修复数据库！"));
		}
		else
		{
			QStringList fileNameList = m_sLoaclFilePaths.split(";");
			for each (QString var in fileNameList)
				urielFtp->uploadFile(var, urielFtp->getRootPath() + "/Notices/" + m_options->getAccount());
			QMessageBox::information(nullptr, QStringLiteral("信息"), QStringLiteral("通知发布成功！"));
			this->accept();
		}
	}
	else //Edit Mode
	{
		m_database->updateNotification(notifications_item);
		
		QStringList fileNameList = m_sLoaclFilePaths.split(";");
		for each (QString var in fileNameList) {
			UrielFtp *urielFtp = UrielFtp::getInstance();
			ProgressDialog *progressDialog = new ProgressDialog(this);
			progressDialog->setTotalProgressBarMax(1/*(ui.RP_FileListTreeWidget->currentItem()->text(3).split("K")[0].toInt() * 1024)*/);
			QObject::connect(urielFtp, static_cast<void (UrielFtp::*)(qint64 readBytes, qint64 totalBytes)>(&UrielFtp::updateDataTransferProgressSignal), \
				progressDialog, &ProgressDialog::updateProgressBarValue);
			progressDialog->setTotalProgressBarMax(1);
			urielFtp->uploadFile(var, urielFtp->getRootPath() + "/Notices/" + m_options->getAccount());
			progressDialog->exec();
			QEventLoop eventloop;
			QTimer::singleShot(30, &eventloop, SLOT(quit()));
			eventloop.exec();
			
		}
		InformationDialog infodlg(QStringLiteral("信息"), QStringLiteral("通知修改成功！"), this);
		infodlg.exec();

		this->accept();
	}
	QStringList EmailList, NameList;
	m_database->getAllAccountEmail(EmailList, NameList);

	sSMTPEmailItem EmailItem;
	for(int i=0;i<EmailList.size();++i)
	{
		EmailItem.recipient.insert(EmailList[i], NameList[i]);
	}
	EmailItem.subjectName = QStringLiteral("From:浙江大学精密微纳测量实验室管理系统-%0").arg(notifications_item.m_sTitle);
	EmailItem.text = notifications_item.m_sContent;
	QStringList fileNameList = m_sLoaclFilePaths.split(";");
	for each (QString var in fileNameList) {
		EmailItem.attachment.insert(var, "");
	}
	UrielSMTPEmail * EMail = UrielSMTPEmail::getInstance();
	int code = EMail->sendEmail(m_database,EmailItem);
	/*if (code == 0) {
		InformationDialog dlg(QStringLiteral("信息"), QStringLiteral("已发送邮件告知审核"), this);
		dlg.exec();
	}
	else*/ if (code == -1) {
		InformationDialog dlg(QStringLiteral("信息"), QStringLiteral("连接主机失败"), this);
		dlg.exec();
	}
	else if (code == -2) {
		InformationDialog dlg(QStringLiteral("信息"), QStringLiteral("账号登录失败或者已过期失效，请重新设置系统邮件账号"), this);
		dlg.exec();
	}
	else if (code == -3) {
		InformationDialog dlg(QStringLiteral("信息"), QStringLiteral("信息发送失败"), this);
		dlg.exec();
	}

		
}

void ReleasingNotices::paintEvent(QPaintEvent* event)
{
	Q_UNUSED(event);

	QPainter p(this);
	//p.setCompositionMode(QPainter::CompositionMode_Clear);
	//p.fillRect(10, 10, 300, 300, Qt::SolidPattern);

}
