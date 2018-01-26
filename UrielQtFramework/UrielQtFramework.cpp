#include "UrielQtFramework.h"
#include "UrielQtFrameworkOptions.h"
#include "glog\logging.h"
#ifdef Q_OS_WIN
#include <qt_windows.h>
#include <Windowsx.h>
#endif

#include <QAction>
#include <QSystemTrayIcon>
#include <QTableWidget>
#include <QFileDialog>
#include <QDesktopServices>
#include <QMessageBox>
#include <QAxObject> 
#include "UrielDatabase\UrielDatabase.h"
#include "ReleasingNotices.h"
#include "TimeFilter.h"
#include "NoticesListMenuItem.h"
#include "UrielModel\NoticesMenuTableModel\NoticesMenuTableModel.h"
#include "UrielModel\NoticesMenuTableModel\NoticesMenuTableItemDelegate.h"
#include "UrielGui\HomePage\NoticesCommentItem\NoticesCommentItem.h"
#include "UrielFileTransfer\FTP\UrielFTP.h"
#include "UrielGui\UserInfo\UserInfo.h"
#include "UrielModel\InstrumentTableModel\InstrumentTableModel.h"
#include "UrielGui\DevicePage\InstrumentInfo\InstrumentInfo.h"
#include "UrielGui\DevicePage\InstrumentBorrowReturn\InstrumentBorrowReturn.h"
#include "UrielGui\DevicePage\InstrumentBorrowReturnHistory\InstrumentBorrowReturnHistory.h"
#include "UrielModel\CheckInTableModel\CheckInTableModel.h"
#include "UrielGui\CommonDialog\InformationDialog\InformationDialog.h"
#include "UrielGui\CommonDialog\CriticalDialog\CriticalDialog.h"
#include "UrielGui\Expense\ExpenseItem\ExpenseItem.h"
#include "UrielGui\Expense\InvoiceInfo\InvoiceInfo.h"
#include "UrielGui\CommonDialog\InputDialog\InputDialog.h"
#include "UrielModel\InvoiceTableModel\InvoiceTableModel.h"
#include "UrielModel\UserCountTableModel\UserCountTableModel.h"
#include "UrielModel\LeaveInfoTableModel\LeaveInfoTableModel.h"
#include "UrielModel\LoginTableModel\LoginTableModel.h"
#include "UrielModel\MaterialPurchaseApplyTableModel\MaterialPurchaseApplyTableModel.h"
#include "UrielGui\Expense\ReimbursementStatistics\ReimbursementStatistics.h"
#include "UrielGui\CommonDialog\UrielImageViewer\UrielImageViewer.h"
#include "UrielGui\TodoPage\MaterialPurchaseApplyTable\MaterialPurchaseApplyTable.h"
#include "UrielGui\CommonDialog\LiftingProhibitionDialog\LiftingProhibitionDialog.h"
#include "ThirdPartyLibraries\QFTP\include\qftp.h"
#include "UrielModel\MeetingReportTableModel\MeetingReportTableModel.h"
#include "UrielGui\CommonDialog\ProgressDialog\ProgressDialog.h"
#include "UrielModel\PaperTableModel\PaperTableModel.h"
#include "UrielGui\ResourcePage\PaperInfo\PaperInfo.h"
#include "UrielModel\AcademicConferenceTableModel\AcademicConferenceTableModel.h"
#include "UrielGui\ResourcePage\AcademicConferenceInfo\AcademicConferenceInfo.h"
#include "UrielModel\PatentTableModel\PatentTableModel.h"
#include "UrielGui\ResourcePage\PatentInfo\PatentInfo.h"
#include "UrielModel\WorksTableModel\WorksTableModel.h"
#include "UrielGui\ResourcePage\WorksInfo\WorksInfo.h"
#include "UrielModel\ResearchProjectTableModel\ResearchProjectTableModel.h"
#include "UrielGui\ResourcePage\ResearchProject\ResearchProject.h"
#include "UrielSMTPEmail\UrielSMTPEmail.h"
UrielQtFramework* UrielQtFramework::mw;

UrielQtFramework::UrielQtFramework(UrielDatabase *database, UrielQtFrameworkOptions *option, QWidget *parent)
	: QMainWindow(parent), m_pDatabase(database), m_pOptions(option),
	m_pCommentSpacerItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding)), m_pUrielFtp(UrielFtp::getInstance())
{
	ui.setupUi(this);
	initializeUi();
	setSignalsAndSlots();

	//sSMTPEmailItem EmailItem;
	//EmailItem.recipient.insert("21525201@zju.edu.cn","WuJing");
	//EmailItem.recipient.insert("wangcy91@zju.edu.cn", "WangChuanYong");
	//EmailItem.subjectName = QStringLiteral("邮件测试，不用管-标题");
	//EmailItem.text = QStringLiteral("邮件测试，不用管-内容");
	//EmailItem.attachment.insert(":/Mainwindow/Resources/UrielQtFramework/applogo.png","image/png");
	//EmailItem.attachment.insert(":/Mainwindow/Resources/UrielQtFramework/applogo.png", "");
	//UrielSMTPEmail * EMail = UrielSMTPEmail::getInstance();
	//int code = EMail->sendEmail(EmailItem);
	//if (code == 0) {
	//	InformationDialog dlg(QStringLiteral("信息"), QStringLiteral("已发送邮件告知审核"), this);
	//	dlg.exec();
	//}
	//else if (code == -1) {
	//	InformationDialog dlg(QStringLiteral("信息"), QStringLiteral("连接主机失败"), this);
	//	dlg.exec();
	//}
	//else if (code == -2) {
	//	InformationDialog dlg(QStringLiteral("信息"), QStringLiteral("账号登录失败或者已过期失效，请重新设置系统邮件账号"), this);
	//	dlg.exec();
	//}
	//else {
	//	InformationDialog dlg(QStringLiteral("信息"), QStringLiteral("信息发送失败"), this);
	//	dlg.exec();
	//}

	//jwsmtp::mailer mail(EmailItem.recipientEmail.toStdString().c_str(), QString("21525201@zju.edu.cn").toStdString().c_str(),
	//	EmailItem.subjectName.toStdString().c_str(), EmailItem.text.toStdString().c_str(),
	//	QString("smtp.zju.edu.cn").toStdString().c_str(), jwsmtp::mailer::SMTP_PORT, false);

	//mail.authtype(jwsmtp::mailer::PLAIN);
	//// using a local file as opposed to a full path.
	////mail.attach("attach.png");

	//mail.username("21525201@zju.edu.cn");
	////这里输入密码
	//mail.password("WuJing3.1415926");
	//mail.send(); // 这里发送邮件，需要注意的是，这里是同步模式哦！
	//std::string xxx=mail.response();
}

UrielQtFramework::~UrielQtFramework()
{
	google::ShutdownGoogleLogging();
	m_pSystemTrayIcon->hide();
	if (m_pSystemTrayIcon) {
		delete m_pSystemTrayIcon;
		m_pSystemTrayIcon = nullptr;
	}
		
}

void UrielQtFramework::setUpOptions(UrielQtFrameworkOptions *option)
{
	this->m_pOptions = option;
}


void UrielQtFramework::setDatabase(UrielDatabase *database)
{
	this->m_pDatabase = database;
}

void UrielQtFramework::initializeUi()
{
	setWindowLogAndTitle();
	//setupMenuBar();
	//setupToolBar();
	this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());
	//set as Transparent background
	//this->setAttribute(Qt::WA_TranslucentBackground, true); 
	//set as Transparent degree
	//setWindowOpacity(0.5);

	this->m_pSystemTrayIcon = new QSystemTrayIcon(this);
	this->m_pSystemTrayIcon->setIcon(QIcon(":/Mainwindow/Resources/UrielQtFramework/applogo.png"));
	this->m_pSystemTrayIcon->setToolTip(QObject::tr("UrielQtFramework"));
	//QObject::connect(m_pSystemTrayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(onSystemTrayIconClicked(QSystemTrayIcon::ActivationReason)));
	QObject::connect(m_pSystemTrayIcon, static_cast<void (QSystemTrayIcon::*) (QSystemTrayIcon::ActivationReason)>(&QSystemTrayIcon::activated), this, &UrielQtFramework::onSystemTrayIconClicked);
	this->m_pSystemTrayIcon->show();

	ui.groupBox_2->setVisible(false);
	ui.AccountInfoTBtn->setIcon(QIcon(m_pOptions->getHeadIcoPath()));
	ui.AccountInfoLabel->setIcon(QIcon(m_pOptions->getHeadIcoPath())); 
	initializeHomePageUi();
	initializeDevicesUi();
	initializeExpenseUi();
	initializeApplyUi();
	initializeCheckInUi();
	initializeResourcesUi();
	initializeStatisticsUi();
	
	initializeSettingsUi();
	onHomePageTBClicked();

	sUrielAccountInfo account;
	m_pDatabase->getUserAccount(account, m_pOptions->getAccount());
	//'super administrator','administrator','regular user'
	if (account.m_sPermision == "regular user") {
		ui.TodoTB->setVisible(false);
	}
	else 
	{
		initializeTodoUi();
	}

}

void UrielQtFramework::setSignalsAndSlots()
{
	QObject::connect(ui.AppClose, &QPushButton::clicked, this, &UrielQtFramework::close);
	QObject::connect(ui.AppMaximize, &QPushButton::clicked, this, &UrielQtFramework::onAppMaximizeClicked);
	QObject::connect(ui.AppMinimize, &QPushButton::clicked, this, &UrielQtFramework::onAppMinimizeClicked);

	//
	QObject::connect(ui.GlobelSearchBtn, &QToolButton::clicked, this, &UrielQtFramework::onGlobelSearchBtnClicked);
	QObject::connect(ui.AccountInfoTBtn, &QToolButton::clicked, this, &UrielQtFramework::onAccountInfoTBtnClicked);
	//ui.HomePageTB->installEventFilter(this);
	QObject::connect(ui.HomePageTB, &QToolButton::clicked, this, &UrielQtFramework::onHomePageTBClicked);
	QObject::connect(ui.DevicesTB, &QToolButton::clicked, this, &UrielQtFramework::onDevicesTBClicked);
	QObject::connect(ui.ExpenseTB, &QToolButton::clicked, this, &UrielQtFramework::onExpenseTBClicked);
	QObject::connect(ui.ApplyTB, &QToolButton::clicked, this, &UrielQtFramework::onApplyTBClicked);
	QObject::connect(ui.CheckInTB, &QToolButton::clicked, this, &UrielQtFramework::onCheckInTBClicked); 
	QObject::connect(ui.ResourcesTB, &QToolButton::clicked, this, &UrielQtFramework::onResourcesTBClicked);
	QObject::connect(ui.StatisticsTB, &QToolButton::clicked, this, &UrielQtFramework::onStatisticsTBClicked);
	QObject::connect(ui.TodoTB, &QToolButton::clicked, this, &UrielQtFramework::onTodoTBClicked);
	QObject::connect(ui.SettingsTB, &QToolButton::clicked, this, &UrielQtFramework::onSettingsTBClicked);

	setHomePageSignalsAndSlots();
	setDevicesSignalsAndSlots();
	setExpenseSignalsAndSlots();
	setApplySignalsAndSlots();
	setCheckInSignalsAndSlots();
	setResourcesSignalsAndSlots();
	setStatisticsSignalsAndSlots();
	setTodoSignalsAndSlots();
	setSettingsSignalsAndSlots();
}


void UrielQtFramework::onGlobelSearchBtnClicked() {
	//QStringList 
}
void UrielQtFramework::onAccountInfoTBtnClicked()
{
	UserInfo UserInfo_Dlg(cursor().pos());
	sUrielAccountInfo accountInfo;
	m_pDatabase->getUserAccount(accountInfo, m_pOptions->getAccount());
	UserInfo_Dlg.setvalue(accountInfo);
	//QObject::connect(&TimeFilter_Dlg, static_cast<void (TimeFilter::*)(const TimeFilterEnum &)>(&TimeFilter::timeFilterSignal), this, &UrielQtFramework::onTimeFilterSlot);
	UserInfo_Dlg.exec();
}

#pragma region HomePage
void UrielQtFramework::initializeHomePageUi()
{
	//hide NotifySearchFrame
	ui.NotifySearchFrame->hide();
	ui.HP_NoticesListMenuItem->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.HP_NoticesListMenuItem->setSortingEnabled(true);
	ui.HP_NoticesListMenuItem->setSelectionBehavior(QAbstractItemView::SelectRows);
	//ui.HP_NoticesListMenuItem->setSelectionMode(QAbstractItemView::ExtendedSelection);
	ui.HP_NoticesListMenuItem->setShowGrid(false);
	ui.HP_NoticesListMenuItem->horizontalHeader()->setVisible(false);
	ui.HP_NoticesListMenuItem->verticalHeader()->setVisible(false);
	ui.HP_NoticesListMenuItem->setAlternatingRowColors(true);
	ui.HP_NoticesListMenuItem->setMouseTracking(true);
	ui.HP_NoticesListMenuItem->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.HP_NoticesListMenuItem->setContextMenuPolicy(Qt::ActionsContextMenu);
	ui.HP_NoticesListMenuItem->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
	ui.HP_NoticesListMenuItem->verticalHeader()->setDefaultSectionSize(50);
	QAction *NoticesEditAction = new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/edits.png"), QStringLiteral("编辑"), this);
	QAction *NoticesDeleteAction = new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/delete.png"), QStringLiteral("删除"), this);
	QAction *NoticesFlagAction = new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/label.png"), QStringLiteral("标记"), this);
	QObject::connect(NoticesEditAction, &QAction::triggered, this, &UrielQtFramework::onNoticesEditActionTriggered);
	QObject::connect(NoticesDeleteAction, &QAction::triggered, this, &UrielQtFramework::onNoticesDeleteActionTriggered);
	QObject::connect(NoticesFlagAction, &QAction::triggered, this, &UrielQtFramework::onNoticesFlagActionTriggered);
	ui.HP_NoticesListMenuItem->addAction(NoticesEditAction);
	ui.HP_NoticesListMenuItem->addAction(NoticesDeleteAction);
	ui.HP_NoticesListMenuItem->addAction(NoticesFlagAction);
	m_pUrielNoticesMenuTableModel = m_pDatabase->creatNoticesMenuTableModel();
	m_pUrielNoticesMenuTableSortFilterModel = new QSortFilterProxyModel;
	m_pUrielNoticesMenuTableSortFilterModel->setDynamicSortFilter(true);
	m_pUrielNoticesMenuTableSortFilterModel->setSourceModel(m_pUrielNoticesMenuTableModel);
	ui.HP_NoticesListMenuItem->setModel(m_pUrielNoticesMenuTableSortFilterModel);
	ui.HP_NoticesListMenuItem->setColumnHidden(0, true);
	ui.HP_NoticesListMenuItem->setColumnHidden(3, true);
	ui.HP_NoticesListMenuItem->setColumnHidden(4, true);
	ui.HP_NoticesListMenuItem->setColumnHidden(6, true);
	//ui.HP_NoticesListMenuItem->setColumnHidden(3, true);
	QObject::connect(ui.HP_NoticesListMenuItem, static_cast<void (QTableView::*)(const QModelIndex &)>(&QTableView::pressed), this, &UrielQtFramework::onNoticesMenuItemPressed);
	//Item Delegate 
	/*NoticesMenuTableItemDelegate *NoticesItemDelegate =new NoticesMenuTableItemDelegate();
	ui.HP_NoticesListMenuItem->setItemDelegateForColumn(1,NoticesItemDelegate);*/  
	QList<int> wdls;
	wdls << 0<< 25 <<140 << 0 <<0<< 68<<0;
	for (int i = 0; i < wdls.size(); i++)
	{
		ui.HP_NoticesListMenuItem->setColumnWidth(i , wdls[i]);
	}

	onTimeFilterSlot(TimeFilterEnum::ALL);

	onNoticesMenuItemPressed(m_pUrielNoticesMenuTableModel->index(0,0));
}

void UrielQtFramework::setHomePageSignalsAndSlots()
{
	QObject::connect(ui.HP_SearchTB, &QToolButton::clicked, this, &UrielQtFramework::onHP_SearchTBClicked);
	QObject::connect(ui.HP_ReturnTB, &QToolButton::clicked, this, &UrielQtFramework::onHP_ReturnTBClicked);
	QObject::connect(ui.HP_FiltrateTB, &QToolButton::clicked, this, &UrielQtFramework::onHP_FiltrateTBClicked);
	QObject::connect(ui.HP_ReleasingNoticesTB, &QToolButton::clicked, this, &UrielQtFramework::onHP_ReleasingNoticesTBClicked); 
	QObject::connect(ui.NoticesReleaseCommentTBtn, &QToolButton::clicked, this, &UrielQtFramework::onHP_ReleasingNoticesCommentTBClicked);
	QObject::connect(ui.NoticesFilePreViewTBtn, &QToolButton::clicked, this, &UrielQtFramework::onHP_NoticesFilePreViewTBtnClicked);
	QObject::connect(ui.HP_Search_CTB, &QToolButton::clicked, this, &UrielQtFramework::onHP_Search_CTBClicked);
	QObject::connect(ui.HP_SearchLE, &QLineEdit::returnPressed, this, &UrielQtFramework::onHP_Search_CTBClicked);
}

void UrielQtFramework::onHP_SearchTBClicked()
{
	ui.NotifyMenuframe->hide();
	ui.NotifySearchFrame->show();
}

void UrielQtFramework::onHP_ReturnTBClicked()
{
	ui.NotifyMenuframe->show();
	ui.NotifySearchFrame->hide();
}

void UrielQtFramework::onHP_ReleasingNoticesTBClicked()
{
	ReleasingNotices ReleasingNotices_dlg(m_pDatabase,m_pOptions,this);
	ReleasingNotices_dlg.exec();
	m_pDatabase->updateNoticesMenuTableModel();
}

void UrielQtFramework::onHP_FiltrateTBClicked()
{
	TimeFilter TimeFilter_Dlg(cursor().pos());
	QObject::connect(&TimeFilter_Dlg, static_cast<void (TimeFilter::*)(const TimeFilterEnum &)>(&TimeFilter::timeFilterSignal),this,&UrielQtFramework::onTimeFilterSlot);
	TimeFilter_Dlg.exec();
}

void UrielQtFramework::onTimeFilterSlot(const TimeFilterEnum & v)
{
	QString strSQL = "";


	QList<sUrielNotificationsMenuItem> NotificationsMenuItemList;
	switch (v)
	{
	case TimeFilterEnum::NEARLY_A_DAT:
	{
		strSQL = " WHERE  DATE_SUB(CURDATE(), INTERVAL " + QString::number(1) + " DAY) <= RELEASE_TIME";
		break;
	}
	case TimeFilterEnum::NEARLY_A_WEEK:
	{
		strSQL = " WHERE  DATE_SUB(CURDATE(), INTERVAL " + QString::number(7) + " DAY) <= RELEASE_TIME";
		break;
	}
	case TimeFilterEnum::NEARLY_A_MONTH:
	{
		strSQL = " WHERE  DATE_SUB(CURDATE(), INTERVAL " + QString::number(30) + " DAY) <= RELEASE_TIME";
		break;
	}
	case TimeFilterEnum::NEARLY_A_YEAR:
	{
		strSQL = " WHERE  DATE_SUB(CURDATE(), INTERVAL " + QString::number(365) + " DAY) <= RELEASE_TIME";
		break;
	}
	case TimeFilterEnum::ALL:
	{
		strSQL = "";
		break;
	}
	default:
		break;
	}
	m_pDatabase->updateNoticesMenuTableModel(strSQL);
}

void UrielQtFramework::onHP_Search_CTBClicked()
{
	QString strSQL = " WHERE TITLE like '%" + ui.HP_SearchLE->text() + "%'"; 
	m_pDatabase->updateNoticesMenuTableModel(strSQL);
}

void UrielQtFramework::setNoticesMenuList(const QList<sUrielNotificationsMenuItem> & notices_list)
{
	
	//for each (auto var in NoticesListMenuItemListWidget)
	//{
	//	QObject::disconnect(var, static_cast<void (NoticesListMenuItem::*)(const QString &)>(&NoticesListMenuItem::NoticeCodeSignal), this, &UrielQtFramework::onNoticesListMenuItemCodeSignal);
	//	ui.HP_NoticeListVerticalLayout->removeWidget(var);
	//	delete var;
	//}
	//ui.HP_NoticeListVerticalLayout->removeItem(NoticeListVerticalLayoutSpacerItem);
	//NoticesListMenuItemListWidget.clear();
	//for each (auto notice in notices_list)
	//{
	//	NoticesListMenuItem *widget = new NoticesListMenuItem();
	//	widget->setNoticesListMenuItemContent(notice);
	//	NoticesListMenuItemListWidget.append(widget);
	//	QObject::connect(widget, static_cast<void (NoticesListMenuItem::*)(const QString &)>(&NoticesListMenuItem::NoticeCodeSignal), this, &UrielQtFramework::onNoticesListMenuItemCodeSignal);
	//	ui.HP_NoticeListVerticalLayout->addWidget(widget);
	//}
	//ui.HP_NoticeListVerticalLayout->addSpacerItem(NoticeListVerticalLayoutSpacerItem);
}


void UrielQtFramework::onNoticesDeleteActionTriggered()
{
	
	QModelIndex index = ui.HP_NoticesListMenuItem->currentIndex();
	if (index.isValid())
	{
		int mIndex = index.row();
		QModelIndex idx = index.sibling(mIndex, 0);
		if (idx.isValid())
			m_pDatabase->deleteNotification(idx.data().toString());
	}
	m_pDatabase->updateNoticesMenuTableModel();
}

void UrielQtFramework::onNoticesFlagActionTriggered()
{

}

void UrielQtFramework::onNoticesEditActionTriggered()
{
	sUrielNotificationsItem item;
	QModelIndex index = ui.HP_NoticesListMenuItem->currentIndex();
	if (index.isValid())
	{
		int mIndex = index.row();
		QModelIndex idx = index.sibling(mIndex, 0);
		if (idx.isValid())
			m_pDatabase->getNotification(item,idx.data().toString());
	}

	ReleasingNotices ReleasingNotices_dlg(m_pDatabase, m_pOptions, this);
	ReleasingNotices_dlg.openWithEditMode(item);
	ReleasingNotices_dlg.exec();
	m_pDatabase->updateNoticesMenuTableModel();
	
}

void UrielQtFramework::onNoticesMenuItemPressed(const QModelIndex & index)
{
	//<< "CODE" << "IMPORTANT_DEGREE" << "TITLE"  << "FILES_PATH" << "CONTENT" << "RELEASE_TIME" << "NOTIFYING_PUBLISHER";
	if (index.isValid())
	{
		int mIndex = index.row();
		QModelIndex idx = index.sibling(mIndex, 1);
		if (idx.isValid())
		{
			QString var = idx.data().toString();
			
			if (var == QStringLiteral("一般通知"))
				ui.NoticesFilesIcoTBtn->setIcon(QPixmap(":/Mainwindow/Resources/UrielQtFramework/generalNotices.png"));
			else if (var == QStringLiteral("重要通知"))
				ui.NoticesFilesIcoTBtn->setIcon(QPixmap(":/Mainwindow/Resources/UrielQtFramework/importantNotices.png"));
			else
				ui.NoticesFilesIcoTBtn->setIcon(QPixmap(":/Mainwindow/Resources/UrielQtFramework/emergencyNotice.png"));
		}

		idx = index.sibling(mIndex, 2);
		if (idx.isValid())
			ui.NoticesTitle->setText(idx.data().toString());
		idx = index.sibling(mIndex, 3);
		if (idx.isValid())
		{
			QString content = idx.data().toString();
			if (!content.isEmpty())
			{
				QStringList FileNames = content.split(";");
				content = "";
				for each (QString var in FileNames)
				{
					QFileInfo fileInfo(var);
					content += fileInfo.fileName() + ";";
				}
			}
			content.resize(content.size()-1);
			if (content.isEmpty())
			{
				ui.NoticesContent->setText(QStringLiteral("无附件"));
				ui.NoticesFilePreViewTBtn->setEnabled(false);
			}	
			else
			{
				ui.NoticesContent->setText(content);
				ui.NoticesFilePreViewTBtn->setEnabled(true);
			}
				
		}
		QString sPublisher;
		idx = index.sibling(mIndex, 6);
		if (idx.isValid())
			sPublisher = idx.data().toString();

		QString sContent;
		idx = index.sibling(mIndex, 4);
		if (idx.isValid())
			sContent = idx.data().toString();

		QString sTime;
		idx = index.sibling(mIndex, 5);
		if (idx.isValid())
			sTime = idx.data().toString();
		
		for each (NoticesCommentItem * var in m_pNoticesCommentItemList)
		{
			QObject::disconnect(var, static_cast<void (NoticesCommentItem::*)(const QString &)>(&NoticesCommentItem::CommentSiganl), this, &UrielQtFramework::onNoticesCommentReply);
			ui.CommentVerticalLayout->removeWidget(var);
			delete var;
		}
			
		ui.CommentVerticalLayout->removeItem(m_pCommentSpacerItem);

		m_pNoticesCommentItemList.clear();
		ui.CommentVerticalLayout->update();

		sUrielAccountInfo accountInfo;
		m_pDatabase->getUserAccount(accountInfo, sPublisher);
		sUrielCommentData stMainComment;
		if (accountInfo.m_imgHeadIco.isNull())
			stMainComment.m_imgHeadIco = QImage(":/Mainwindow/Resources/UrielQtFramework/head.png");
		else
			stMainComment.m_imgHeadIco = accountInfo.m_imgHeadIco;
		stMainComment.m_sName = sPublisher;
		stMainComment.m_sContent = sContent;
		stMainComment.m_sTime = sTime;
		NoticesCommentItem *mainWidget = new NoticesCommentItem();
		mainWidget->setValue(stMainComment);
		m_pNoticesCommentItemList.push_back(mainWidget);
		QString sCodeID;
		idx = index.sibling(mIndex, 0);
		if (idx.isValid())
			sCodeID = idx.data().toString();
		QList<sUrielCommentItem> ChildCommentDataList;
		m_pDatabase->getNoticesCommentList(ChildCommentDataList, sCodeID);
		for each (sUrielCommentItem var in ChildCommentDataList)
		{
			sUrielCommentData stChildComment;
			sUrielAccountInfo childAccountInfo;
			m_pDatabase->getUserAccount(childAccountInfo, var.m_sStaff);
			if (accountInfo.m_imgHeadIco.isNull())
				stChildComment.m_imgHeadIco = QImage(":/Mainwindow/Resources/UrielQtFramework/head.png");
			else
				stChildComment.m_imgHeadIco = childAccountInfo.m_imgHeadIco;
			stChildComment.m_sName = var.m_sStaff;
			stChildComment.m_sContent = var.m_sComment;
			stChildComment.m_sTime = var.m_sTime.toString("yyyy-MM-dd");

			NoticesCommentItem *childWidget = new NoticesCommentItem();
			childWidget->setValue(stChildComment);
			m_pNoticesCommentItemList.push_back(childWidget);
		}


		for each (NoticesCommentItem* var in m_pNoticesCommentItemList)
		{
			ui.CommentVerticalLayout->addWidget(var);
			QObject::connect(var, static_cast<void (NoticesCommentItem::*)(const QString &)>(&NoticesCommentItem::CommentSiganl), this, &UrielQtFramework::onNoticesCommentReply);
		}
			
		if (m_pCommentSpacerItem == nullptr)
			m_pCommentSpacerItem = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
		ui.CommentVerticalLayout->addSpacerItem(m_pCommentSpacerItem);
		ui.CommentVerticalLayout->update();
		
	}
}

void UrielQtFramework::onNoticesListMenuItemCodeSignal(const QString &)
{

}

void UrielQtFramework::onNoticesCommentReply(const QString &name)
{
	m_sCurrentAtStaff = name;
	ui.NoticeCommentComment->setText("@"+name+" ");
	ui.NoticeCommentComment->setFocus();
}

void UrielQtFramework::onHP_ReleasingNoticesCommentTBClicked()
{
	
	sUrielCommentItem commentItem;
	QModelIndex index=ui.HP_NoticesListMenuItem->currentIndex();
	if (index.isValid())
	{
		int mIndex = index.row();
		QModelIndex idx = index.sibling(mIndex, 0);
		if (idx.isValid())
			commentItem.m_sCodeId = idx.data().toString();
	}
	else
	{
		QMessageBox::warning(this, QStringLiteral("错误"), QStringLiteral("未选中通知！"));
		return;
	}
	commentItem.m_sComment = ui.NoticeCommentComment->text();
	commentItem.m_sStaff = m_pOptions->getAccount();
	commentItem.m_sTime = QDateTime::currentDateTime();
	commentItem.m_sAtStaff = m_sCurrentAtStaff;
	QString sError;
	m_pDatabase->insertNoticesComment(commentItem, sError);
	if (!sError.isEmpty())
		QMessageBox::critical(this, QStringLiteral("错误"), QStringLiteral("未能评论成功！"));
	sUrielCommentData stComment;
	stComment.m_imgHeadIco = QImage(m_pOptions->getHeadIcoPath());
	stComment.m_sName = m_pOptions ->getAccount();
	stComment.m_sContent = ui.NoticeCommentComment ->text();
	stComment.m_sTime = commentItem.m_sTime.toString("yyyy-MM-dd");

	NoticesCommentItem *commentWidget = new NoticesCommentItem();
	commentWidget->setValue(stComment);
	ui.CommentVerticalLayout->removeItem(m_pCommentSpacerItem);
	m_pNoticesCommentItemList.push_back(commentWidget);
	ui.CommentVerticalLayout->addWidget(m_pNoticesCommentItemList.back());
	QObject::connect(commentWidget, static_cast<void (NoticesCommentItem::*)(const QString &)>(&NoticesCommentItem::CommentSiganl), this, &UrielQtFramework::onNoticesCommentReply);
	if (m_pCommentSpacerItem == nullptr)
		m_pCommentSpacerItem = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
	ui.CommentVerticalLayout->addSpacerItem(m_pCommentSpacerItem);
	ui.NoticeCommentComment->setText("");
}

void UrielQtFramework::onHP_NoticesFilePreViewTBtnClicked()
{
	QStringList fileList;
	QModelIndex index = ui.HP_NoticesListMenuItem->currentIndex();
	if (index.isValid())
	{
		int mIndex = index.row();
		QModelIndex idx = index.sibling(mIndex, 3);
		if (idx.isValid())
			fileList = idx.data().toString().split(";");
	}
	QString file_path = QFileDialog::getExistingDirectory(nullptr, QStringLiteral("请选择文件保存路径..."), "./");
	//m_pUrielFtp->cdToSpecifiedPath(m_pUrielFtp->getRootPath() + "/Notices/" + m_pOptions->getAccount());
	for each (QString var in fileList)
	{
		ProgressDialog *progressDialog = new ProgressDialog(this);
		progressDialog->setTotalProgressBarMax(1/*(ui.RP_FileListTreeWidget->currentItem()->text(3).split("K")[0].toInt() * 1024)*/);
		QObject::connect(m_pUrielFtp, static_cast<void (UrielFtp::*)(qint64 readBytes, qint64 totalBytes)>(&UrielFtp::updateDataTransferProgressSignal), \
			progressDialog, &ProgressDialog::updateProgressBarValue);
		progressDialog->setTotalProgressBarMax(1);
		if (m_pUrielFtp->downloadFiles(file_path, var)) {
			progressDialog->exec();
			QEventLoop eventloop;
			QTimer::singleShot(100, &eventloop, SLOT(quit()));
			eventloop.exec();
		}
		else {
			QObject::disconnect(m_pUrielFtp, static_cast<void (UrielFtp::*)(qint64 readBytes, qint64 totalBytes)>(&UrielFtp::updateDataTransferProgressSignal), \
				progressDialog, &ProgressDialog::updateProgressBarValue);
			delete progressDialog;
		}
	}

	
}
#pragma endregion

#pragma region Devices
void UrielQtFramework::initializeDevicesUi()
{
	ui.DP_SearchFrame->hide();
	ui.DP_InstrumentTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.DP_InstrumentTableView->setSortingEnabled(true);
	ui.DP_InstrumentTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.DP_InstrumentTableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
	ui.DP_InstrumentTableView->setShowGrid(true);
	ui.DP_InstrumentTableView->verticalHeader()->setVisible(false);
	ui.DP_InstrumentTableView->setAlternatingRowColors(true);
	ui.DP_InstrumentTableView->setMouseTracking(true);
	ui.DP_InstrumentTableView->setSelectionMode(QAbstractItemView::ContiguousSelection);//设置为连续选择模式
	ui.DP_InstrumentTableView->setContextMenuPolicy(Qt::ActionsContextMenu);//设置为action菜单模式
	

	QAction * InstrumentAddAction = new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/add.png"), QStringLiteral("添加"), this);
	QAction * InstrumentEditAction = new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/edit.png"), QStringLiteral("编辑"), this);
	QAction * InstrumentDeleteAction = new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/delete.png"), QStringLiteral("删除"), this);
	m_pactInstrumentUseManageBorrowAction = new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/Lend.png"), QStringLiteral("借出"), this);
	m_pactInstrumentUseManageReturnAction = new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/return.png"), QStringLiteral("归还"), this);
	QAction * InstrumentHistoryBorrowReturnAction = new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/LendReturnManage.png"), QStringLiteral("历史记录"), this);
	
	ui.DP_InstrumentTableView->addAction(InstrumentAddAction);
	ui.DP_InstrumentTableView->addAction(InstrumentEditAction);
	ui.DP_InstrumentTableView->addAction(InstrumentDeleteAction);
	ui.DP_InstrumentTableView->addAction(m_pactInstrumentUseManageBorrowAction);
	ui.DP_InstrumentTableView->addAction(m_pactInstrumentUseManageReturnAction);
	ui.DP_InstrumentTableView->addAction(InstrumentHistoryBorrowReturnAction);

	connect(InstrumentAddAction, &QAction::triggered, this, &UrielQtFramework::onInstrumentAddActionTriggered);
	connect(InstrumentEditAction, &QAction::triggered, this, &UrielQtFramework::onInstrumentEditActionTriggered);
	connect(InstrumentDeleteAction, &QAction::triggered, this, &UrielQtFramework::onInstrumentDeleteActionTriggered);
	connect(m_pactInstrumentUseManageBorrowAction, &QAction::triggered, this, &UrielQtFramework::onInstrumentUseManageBorrowActionTriggered);
	connect(m_pactInstrumentUseManageReturnAction, &QAction::triggered, this, &UrielQtFramework::onInstrumentUseManageReturnActionTriggered);
	connect(InstrumentHistoryBorrowReturnAction, &QAction::triggered, this, &UrielQtFramework::onInstrumentHistoryBorrowReturnActionTriggered);

	connect(ui.DP_InstrumentTableView, static_cast<void (QTableView::*)(const QModelIndex &)>(&QTableView::doubleClicked),this, &UrielQtFramework::onDP_InstrumentTableViewDoubleClicked);
	
	m_pUrielInstrumentTableModel = m_pDatabase->creatInstrumentTableModel();
	m_pUrielInstrumentTableSortFilterModel = new QSortFilterProxyModel;
	m_pUrielInstrumentTableSortFilterModel->setDynamicSortFilter(true);
	m_pUrielInstrumentTableSortFilterModel->setSourceModel(m_pUrielInstrumentTableModel);
	ui.DP_InstrumentTableView->setModel(m_pUrielInstrumentTableSortFilterModel);
	//ui.HP_NoticesListMenuItem->setColumnHidden(0, true);
	QObject::connect(ui.DP_InstrumentTableView, static_cast<void (QTableView::*)(const QModelIndex &)>(&QTableView::pressed), this, &UrielQtFramework::onInstrumentTableViewItemPressed);
	QList<int> wdls;
	wdls << 60 << 250<< 150 << 150 << 100 << 100 << 80 << 200 <<60<<200<<60<<200;
	for (int i = 0; i < wdls.size(); i++)
	{
		ui.DP_InstrumentTableView->setColumnWidth(i, wdls[i]);
	}

	ui.DP_TreeWidget->setHeaderHidden(true);
	connect(ui.DP_TreeWidget, static_cast<void (QTreeWidget::*)(QTreeWidgetItem*, int)>(&QTreeWidget::itemDoubleClicked), this, &UrielQtFramework::onDP_TreeWidgetItemDoubleClicked);
	
	onDP_ProjectTBtnClicked();
	QStringList ChargerList;
	ChargerList << "";
	m_pDatabase->getDistinctChargerFromInstrument(ChargerList);
	ui.DP_ProjectManagerCombox->addItems(ChargerList);
	ui.DP_ProjectManagerCombox->setCurrentIndex(0);

}
void UrielQtFramework::setDevicesSignalsAndSlots()
{
	QObject::connect(ui.DP_SearchTBtn, &QToolButton::clicked, this, &UrielQtFramework::onDP_SearchTBtnClicked);
	QObject::connect(ui.DP_ReturnTBtn, &QToolButton::clicked, this, &UrielQtFramework::onDP_ReturnTBtnClicked);
	QObject::connect(ui.DP_ProjectTBtn, &QToolButton::clicked, this, &UrielQtFramework::onDP_ProjectTBtnClicked);
	QObject::connect(ui.DP_ClassTBtn, &QToolButton::clicked, this, &UrielQtFramework::onDP_ClassTBtnClicked);//DP_ExportInstrumentBRTBtn
	QObject::connect(ui.DP_SearchConfirmTBtn, &QToolButton::clicked, this, &UrielQtFramework::onDP_SearchConfirmTBtnClicked);
	QObject::connect(ui.DP_SerachLineEdit, &QLineEdit::returnPressed, this, &UrielQtFramework::onDP_SerachLineEditClicked);
	QObject::connect(ui.DP_AddInstrumentTBtn, &QToolButton::clicked, this, &UrielQtFramework::onDP_AddInstrumentTBtnClicked);
	QObject::connect(ui.DP_EditInstrumentTBtn, &QToolButton::clicked, this, &UrielQtFramework::onDP_EditInstrumentTBtnClicked);
	QObject::connect(ui.DP_DeleteInstrumentTBtn, &QToolButton::clicked, this, &UrielQtFramework::onDP_DeleteInstrumentTBtnClicked);
	QObject::connect(ui.DP_BorrowInstrumentTBtn, &QToolButton::clicked, this, &UrielQtFramework::onDP_BorrowInstrumentTBtnClicked);
	QObject::connect(ui.DP_ReturnInstrumentTBtn, &QToolButton::clicked, this, &UrielQtFramework::onDP_ReturnInstrumentTBtnClicked);
	QObject::connect(ui.DP_ExportInstrumentTBtn, &QToolButton::clicked, this, &UrielQtFramework::onDP_ExportInstrumentTBtnClicked);
	QObject::connect(ui.DP_BRInstrumentHistroyTBtn, &QToolButton::clicked, this, &UrielQtFramework::onDP_BRInstrumentHistroyTBtnClicked);
	QObject::connect(ui.DP_StatisticsInstrumentTBtn, &QToolButton::clicked, this, &UrielQtFramework::onDP_StatisticsInstrumentTBtnClicked);
	QObject::connect(ui.DP_FilterSearchPBtn, &QToolButton::clicked, this, &UrielQtFramework::onDP_FilterSearchPBtnClicked);//
	QObject::connect(ui.DP_InstrumentNameLineEdit, &QLineEdit::returnPressed, this, &UrielQtFramework::onDP_FilterSearchPBtnClicked);
	QObject::connect(ui.DP_InstrumentModelLineEdit, &QLineEdit::returnPressed, this, &UrielQtFramework::onDP_FilterSearchPBtnClicked);
	QObject::connect(ui.DP_ProjectManagerCombox, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &UrielQtFramework::onDP_ProjectManagerComboxCurrentIndexChanged);
	QObject::connect(ui.DP_InStoreCheckBox, static_cast<void (QCheckBox::*)(bool)>(&QCheckBox::clicked), this, &UrielQtFramework::onDP_InStoreCheckBoxClicked);
}

void UrielQtFramework::onDP_SearchTBtnClicked()
{
	ui.DP_FunctionFrame->hide();
	ui.DP_SearchFrame->show();
}
void UrielQtFramework::onDP_ReturnTBtnClicked()
{
	ui.DP_SearchFrame->hide();
	ui.DP_FunctionFrame->show();
	onDP_ProjectTBtnClicked();
}

void UrielQtFramework::onInstrumentAddActionTriggered()
{
	InstrumentInfo widget(m_pDatabase, this);
	widget.exec();
	m_pDatabase->updateInstrumentTableModel();
}

void UrielQtFramework::onInstrumentEditActionTriggered()
{
	sUrielInstrumentItem instrumentItem;
	QModelIndex index = ui.DP_InstrumentTableView->currentIndex();
	if (index.isValid())
	{
		int mIndex = index.row();
		QModelIndex idx = index.sibling(mIndex, 0);
		if (idx.isValid())
			m_pDatabase->getInstrumentByID(instrumentItem,idx.data().toString());
	}
	InstrumentInfo widget(m_pDatabase,this);
	widget.setValue(instrumentItem);
	widget.exec();
	m_pDatabase->updateInstrumentTableModel();
}

void UrielQtFramework::onInstrumentDeleteActionTriggered()
{
	QModelIndex index = ui.DP_InstrumentTableView->currentIndex();
	if (index.isValid())
	{
		int mIndex = index.row();
		QModelIndex idx = index.sibling(mIndex, 0);
		if (idx.isValid())
			m_pDatabase->deleteInstrumentByID(idx.data().toString());
	}
	m_pDatabase->updateInstrumentTableModel();
}

void UrielQtFramework::onInstrumentUseManageBorrowActionTriggered()
{
	ReturnOrBorrowInstrument();
}

void UrielQtFramework::onInstrumentUseManageReturnActionTriggered()
{
	ReturnOrBorrowInstrument();
}

void UrielQtFramework::onInstrumentHistoryBorrowReturnActionTriggered()
{
	onDP_BRInstrumentHistroyTBtnClicked();
}

void UrielQtFramework::onDP_InstrumentTableViewDoubleClicked()
{
	onInstrumentEditActionTriggered();
}

void UrielQtFramework::onDP_ProjectTBtnClicked()
{
	m_bIsInstrumentSearchMode = false;
	ui.DP_TreeWidget->clear();
	ui.DP_TreeWidget->setColumnCount(1);
	ui.DP_TreeWidget->setHeaderHidden(true);
	QStringList ProjectList;
	m_pDatabase->getDistinctProjectFromInstrument(ProjectList);
	for each (QString var in ProjectList)
	{
		QTreeWidgetItem *root = new QTreeWidgetItem(ui.DP_TreeWidget,QStringList(var));
		QStringList InstrumentList;
		m_pDatabase->getInstrumentByProjectTeam(InstrumentList, var);
		for (int i = 0; i < InstrumentList.size(); i++)
		{
			QTreeWidgetItem *item = new QTreeWidgetItem(root, QStringList(InstrumentList[i]));
			item->setIcon(0, QIcon(":/Mainwindow/Resources/UrielQtFramework/device.png"));
			root->addChild(item);
		}
		ui.DP_TreeWidget->addTopLevelItem(root);
		ui.DP_TreeWidget->expandAll();
	}
}

void UrielQtFramework::onDP_ClassTBtnClicked()
{
	m_bIsInstrumentSearchMode = false;
	ui.DP_TreeWidget->clear();
	ui.DP_TreeWidget->setColumnCount(1);
	ui.DP_TreeWidget->setHeaderHidden(true);
	QStringList ChargerList;
	m_pDatabase->getDistinctChargerFromInstrument(ChargerList);
	for each (QString var in ChargerList)
	{
		QTreeWidgetItem *root = new QTreeWidgetItem(ui.DP_TreeWidget, QStringList(var));
		QStringList InstrumentList;
		m_pDatabase->getInstrumentByCharger(InstrumentList, var);
		for (int i = 0; i < InstrumentList.size(); i++)
		{
			QTreeWidgetItem *item = new QTreeWidgetItem(root, QStringList(InstrumentList[i]));
			item->setIcon(0, QIcon(":/Mainwindow/Resources/UrielQtFramework/device.png"));
		}
		ui.DP_TreeWidget->addTopLevelItem(root);
		ui.DP_TreeWidget->expandAll();
	}
}

void UrielQtFramework::onDP_SerachLineEditClicked()
{
	onDP_SearchConfirmTBtnClicked();
}

void UrielQtFramework::onDP_SearchConfirmTBtnClicked()
{
	m_bIsInstrumentSearchMode = true;
	ui.DP_TreeWidget->clear();
	ui.DP_TreeWidget->setColumnCount(1);
	ui.DP_TreeWidget->setHeaderHidden(true);
	QString searchName = ui.DP_SerachLineEdit->text();
	QStringList InstrumentList;
	m_pDatabase->getInstrumentBySearch(InstrumentList, searchName);

	for each (QString var in InstrumentList)
	{
		QTreeWidgetItem *root = new QTreeWidgetItem(ui.DP_TreeWidget, QStringList(var));
		root->setIcon(0, QIcon(":/Mainwindow/Resources/UrielQtFramework/device.png"));
		ui.DP_TreeWidget->addTopLevelItem(root);
		ui.DP_TreeWidget->expandAll();
	}
}

void UrielQtFramework::onInstrumentTableViewItemPressed(const QModelIndex & index)
{
	if (index.isValid())
	{
		int mIndex = index.row();
		QModelIndex idx = index.sibling(mIndex, 0);
		if (idx.isValid())
		{
			QString status;
			m_pDatabase->getInstrumentStatusByID(status, idx.data().toString());
			if (status == QStringLiteral("借出"))
			{
				ui.DP_BorrowInstrumentTBtn->setEnabled(false);
				ui.DP_ReturnInstrumentTBtn->setEnabled(true);
				this->m_pactInstrumentUseManageBorrowAction->setEnabled(false);
				this->m_pactInstrumentUseManageReturnAction->setEnabled(true);
			}
			else
			{
				ui.DP_BorrowInstrumentTBtn->setEnabled(true);
				ui.DP_ReturnInstrumentTBtn->setEnabled(false);
				this->m_pactInstrumentUseManageBorrowAction->setEnabled(true);
				this->m_pactInstrumentUseManageReturnAction->setEnabled(false);
			}
		}
	}
}

void UrielQtFramework::onDP_TreeWidgetItemDoubleClicked(QTreeWidgetItem* item_, int col)
{
	QString InstrumentName = item_->text(col);
	sUrielInstrumentItem instrumentItem;
	if (!m_bIsInstrumentSearchMode)
	{
		if (ui.DP_ProjectTBtn->isChecked())
		{
			QString ProjectTeam = item_->parent()->text(0);
			m_pDatabase->getInstrumentByInstrumentNameAndProjectTeam(instrumentItem, ProjectTeam, InstrumentName);
		}
		else
		{
			QString Charger = item_->parent()->text(0);
			m_pDatabase->getInstrumentByInstrumentNameAndCharger(instrumentItem, Charger, InstrumentName);
		}
	}
	else
	{
		m_pDatabase->getInstrumentByName(instrumentItem,InstrumentName);
	}
	
	InstrumentInfo widget(m_pDatabase, this);
	widget.setValue(instrumentItem);
	widget.exec();
	m_pDatabase->updateInstrumentTableModel();
}

void UrielQtFramework::onDP_AddInstrumentTBtnClicked()
{
	onInstrumentAddActionTriggered();
}
void UrielQtFramework::onDP_EditInstrumentTBtnClicked()
{
	onInstrumentEditActionTriggered();
}
void UrielQtFramework::onDP_DeleteInstrumentTBtnClicked()
{
	onInstrumentDeleteActionTriggered();
}

void UrielQtFramework::ReturnOrBorrowInstrument()
{
	sUrielInstrumentItem item;
	QModelIndex index = ui.DP_InstrumentTableView->currentIndex();
	if (index.isValid())
	{
		int mIndex = index.row();
		QModelIndex idx = index.sibling(mIndex, 0);
		if (idx.isValid())
			m_pDatabase->getInstrumentByID(item, idx.data().toString());
	}
	else
	{
		QMessageBox::warning(this, QStringLiteral("信息"), QStringLiteral("没有选择任何项！"));
		return;
	}


	InstrumentBorrowReturn Widget(m_pDatabase, this);
	Widget.setSomeInfo(item);
	Widget.exec();
	m_pDatabase->updateInstrumentTableModel();
}

void UrielQtFramework::onDP_BorrowInstrumentTBtnClicked()
{
	ReturnOrBorrowInstrument();
}

void UrielQtFramework::onDP_ReturnInstrumentTBtnClicked()
{
	ReturnOrBorrowInstrument();
}

//第一个参数是页面上的表格，第二个是导出文件的表头数据
void UrielQtFramework::Table2ExcelByHtml(QTableWidget *table, QString title)
{
	QString fileName = QFileDialog::getSaveFileName(table, "保存", QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation), "Excel 文件(*.xls *.xlsx)");
	if (fileName != "")
	{
		QAxObject *excel = new QAxObject;
		if (excel->setControl("Excel.Application")) //连接Excel控件
		{
			excel->dynamicCall("SetVisible (bool Visible)", "false");//不显示窗体
			excel->setProperty("DisplayAlerts", false);//不显示任何警告信息。如果为true那么在关闭是会出现类似“文件已修改，是否保存”的提示
			QAxObject *workbooks = excel->querySubObject("WorkBooks");//获取工作簿集合
			workbooks->dynamicCall("Add");//新建一个工作簿
			QAxObject *workbook = excel->querySubObject("ActiveWorkBook");//获取当前工作簿
			QAxObject *worksheet = workbook->querySubObject("Worksheets(int)", 1);

			int i, j;
			//QTablewidget 获取数据的列数
			int colcount = table->columnCount();
			//QTablewidget 获取数据的行数
			int rowscount = table->rowCount();

			//QTableView 获取列数
			//int colount=ui->tableview->model->columnCount();
			//QTableView 获取行数
			//int rowcount=ui->tableview->model->rowCount();
			QAxObject *cell, *col;
			//标题行
			cell = worksheet->querySubObject("Cells(int,int)", 1, 1);
			cell->dynamicCall("SetValue(const QString&)", title);
			cell->querySubObject("Font")->setProperty("Size", 18);
			//调整行高
			worksheet->querySubObject("Range(const QString&)", "1:1")->setProperty("RowHeight", 30);
			//合并标题行
			QString cellTitle;
			cellTitle.append("A1:");
			cellTitle.append(QChar(colcount - 1 + 'A'));
			cellTitle.append(QString::number(1));
			QAxObject *range = worksheet->querySubObject("Range(const QString&)", cellTitle);
			range->setProperty("WrapText", true);
			range->setProperty("MergeCells", true);
			range->setProperty("HorizontalAlignment", -4108);//xlCenter
			range->setProperty("VerticalAlignment", -4108);//xlCenter
														   //列标题
			for (i = 0; i<colcount; i++)
			{
				QString columnName;
				columnName.append(QChar(i + 'A'));
				columnName.append(":");
				columnName.append(QChar(i + 'A'));
				col = worksheet->querySubObject("Columns(const QString&)", columnName);
				col->setProperty("ColumnWidth", table->columnWidth(i) / 6);
				cell = worksheet->querySubObject("Cells(int,int)", 2, i + 1);
				//QTableWidget 获取表格头部文字信息
				columnName = table->horizontalHeaderItem(i)->text();
				//QTableView 获取表格头部文字信息
				// columnName=ui->tableView_right->model()->headerData(i,Qt::Horizontal,Qt::DisplayRole).toString();
				cell->dynamicCall("SetValue(const QString&)", columnName);
				cell->querySubObject("Font")->setProperty("Bold", true);
				cell->querySubObject("Interior")->setProperty("Color", QColor(191, 191, 191));
				cell->setProperty("HorizontalAlignment", -4108);//xlCenter
				cell->setProperty("VerticalAlignment", -4108);//xlCenter
			}

			//数据区

			//QTableWidget 获取表格数据部分
			for (i = 0; i<rowscount; i++) {
				for (j = 0; j<colcount; j++)
				{
					worksheet->querySubObject("Cells(int,int)", i + 3, j + 1)->dynamicCall("SetValue(const QString&)", table->item(i, j) ? table->item(i, j)->text() : "");
				}
			}


			//QTableView 获取表格数据部分
			//  for(i=0;i<rowcount;i++) //行数
			//     {
			//         for (j=0;j<colcount;j++)   //列数
			//         {
			//             QModelIndex index = ui->tableView_right->model()->index(i, j);
			//             QString strdata=ui->tableView_right->model()->data(index).toString();
			//             worksheet->querySubObject("Cells(int,int)", i+3, j+1)->dynamicCall("SetValue(const QString&)", strdata);
			//         }
			//     }


			//画框线
			QString lrange;
			lrange.append("A2:");
			lrange.append(colcount - 1 + 'A');
			lrange.append(QString::number(table->rowCount() + 2));
			range = worksheet->querySubObject("Range(const QString&)", lrange);
			range->querySubObject("Borders")->setProperty("LineStyle", QString::number(1));
			range->querySubObject("Borders")->setProperty("Color", QColor(0, 0, 0));
			//调整数据区行高
			QString rowsName;
			rowsName.append("2:");
			rowsName.append(QString::number(table->rowCount() + 2));
			range = worksheet->querySubObject("Range(const QString&)", rowsName);
			range->setProperty("RowHeight", 20);
			workbook->dynamicCall("SaveAs(const QString&)", QDir::toNativeSeparators(fileName));//保存至fileName
			workbook->dynamicCall("Close()");//关闭工作簿
			excel->dynamicCall("Quit()");//关闭excel
			delete excel;
			excel = NULL;
			if (QMessageBox::question(NULL, "完成", "文件已经导出，是否现在打开？", QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
			{
				QDesktopServices::openUrl(QUrl("file:///" + QDir::toNativeSeparators(fileName)));
			}
		}
		else
		{
			QMessageBox::warning(NULL, "错误", "未能创建 Excel 对象，请安装 Microsoft Excel。", QMessageBox::Apply);
		}
	}
}

void UrielQtFramework::onDP_BRInstrumentHistroyTBtnClicked()
{
	QString instrumentKey;
	QModelIndex index = ui.DP_InstrumentTableView->currentIndex();
	if (index.isValid())
	{
		int mIndex = index.row();
		QModelIndex idx = index.sibling(mIndex, 0);
		if (idx.isValid())
			instrumentKey=idx.data().toString();
	}
	else
	{
		QMessageBox::warning(this, QStringLiteral("信息"), QStringLiteral("没有选择任何项！"));
		return;
	}

	InstrumentBorrowReturnHistory histroyWidget(m_pDatabase, instrumentKey, this);
	histroyWidget.exec();

}

void UrielQtFramework::onDP_ExportInstrumentTBtnClicked()
{
//	QDir dir(qApp->applicationDirPath());
//#if defined(Q_OS_MAC)
//	dir.cd(QFile::decodeName("../Resources"));
//#endif
//
//	QString fileName = QCoreApplication::applicationDirPath() + QStringLiteral("/UrielFiles/浙江大学实验仪器表单.xml");
//	auto report = QtRPT::createSPtr(this);
//	report->recordCount << ui.DP_InstrumentTableView->rootIndex().data().cou;
//	if (report->loadReport(fileName) == false)
//		qDebug() << "Report file not found";
//	QObject::connect(report.data(), SIGNAL(setValue(const int, const QString, QVariant&, const int)),
//		this, SLOT(setInstrumentReportValue(const int, const QString, QVariant&, const int)));
//	//QObject::connect(report.data(), SIGNAL(setValueDiagram(Chart&)), this, SLOT(setInstrumentReportValueDiagram(Chart&)));
//	report->printExec();
}
void UrielQtFramework::setInstrumentReportValue(const int recNo, const QString paramName, QVariant &paramValue, const int reportPage) {
	/*Q_UNUSED(reportPage);
	if (paramName == "month") {
		if (ui.DP_InstrumentTableView->indexAt()(recNo, 0) == 0) return;
		paramValue = ui.DP_InstrumentTableView->item(recNo, 0)->text();
	}
	if (paramName == "eur") {
		if (ui.DP_InstrumentTableView->item(recNo, 1) == 0) return;
		paramValue = ui.DP_InstrumentTableView->item(recNo, 1)->text();
	}
	if (paramName == "us") {
		if (ui.DP_InstrumentTableView->item(recNo, 2) == 0) return;
		paramValue = ui.DP_InstrumentTableView->item(recNo, 2)->text();
	}
	if (paramName == "ukraine") {
		if (ui.DP_InstrumentTableView->item(recNo, 3) == 0) return;
		paramValue = ui.DP_InstrumentTableView->item(recNo, 3)->text();
	}
	if (paramName == "georgia") {
		if (ui.DP_InstrumentTableView->item(recNo, 4) == 0) return;
		paramValue = ui.DP_InstrumentTableView->item(recNo, 4)->text();
	}
	if (paramName == "other") {
		if (ui.DP_InstrumentTableView->item(recNo, 5) == 0) return;
		paramValue = ui.DP_InstrumentTableView->item(recNo, 5)->text();
	}*/
}

void UrielQtFramework::onDP_StatisticsInstrumentTBtnClicked()
{

}

QString UrielQtFramework::getDPFilters()
{
	QString str, strSQL = "";

	str = ui.DP_InstrumentNameLineEdit->text();

	if (!str.isEmpty())
	{
		strSQL += " WHERE INSTRUMENT_NAME like '%" + str + "%'";
	}
	str = ui.DP_InstrumentModelLineEdit->text();
	if (!str.isEmpty() && !strSQL.isEmpty())
	{
		strSQL += " AND INSTRUMENT_MODEL like '%" + str + "%'";
	}
	else if (!str.isEmpty() && strSQL.isEmpty())
	{
		strSQL += " WHERE INSTRUMENT_MODEL like '%" + str + "%'";
	}
	str = ui.DP_ProjectManagerCombox->currentText();
	if (!str.isEmpty() && !strSQL.isEmpty())
	{
		strSQL += " AND INSTRUMENT_PRESENT_PERSON_IN_CHARGE = '" + str + "'";
	}
	else if (!str.isEmpty() && strSQL.isEmpty())
	{
		strSQL += " WHERE INSTRUMENT_PRESENT_PERSON_IN_CHARGE = '" + str + "'";
	}
	if (ui.DP_InStoreCheckBox->isChecked())
		str = QStringLiteral("借出");
	else 
		str = "";
	if (!str.isEmpty() && !strSQL.isEmpty())
	{
		strSQL += " AND INSTRUMENT_STATUS != '" + str + "'";
	}
	else if (!str.isEmpty() && strSQL.isEmpty())
	{
		strSQL += " WHERE INSTRUMENT_STATUS != '" + str + "'";
	}
	return strSQL;
}

void UrielQtFramework::onDP_ProjectManagerComboxCurrentIndexChanged(int index)
{
	onDP_FilterSearchPBtnClicked();
}

void UrielQtFramework::onDP_InStoreCheckBoxClicked(bool value)
{
	onDP_FilterSearchPBtnClicked();
}

void UrielQtFramework::onDP_FilterSearchPBtnClicked()
{
	if (m_pDatabase)
	{
		m_pDatabase->updateInstrumentTableModel(getDPFilters());
	}
}
#pragma endregion

#pragma region Expense
void UrielQtFramework::initializeExpenseUi()
{
	initializePersonalModelUi();
	initializeCollectModelUi();
	ui.EP_CodeComboBox->setStyleSheet("QComboBox {  background: white; border: 1px solid gray;   border-radius: 3px;   padding: 1px 18px 1px 3px;   min-width: 6em;   }  ");
	updateReimburseCode();
	//onEP_PersonalModelSelectCodeTBtnClicked();
	ui.frame_50->setVisible(false);
	ui.frame_51->setVisible(false);
	onEP_PersonalModelTBtnClicked();
}

void UrielQtFramework::setExpenseSignalsAndSlots()
{
	setPersonalModelSignalsAndSlots();
	setCollectModelSignalsAndSlots(); 
	QObject::connect(ui.EP_HistoryModelTBtn, &QToolButton::clicked, this, &UrielQtFramework::onEP_HistoryModelTBtnClicked);
	QObject::connect(ui.EP_PersonalModelTBtn,&QToolButton::clicked,this,&UrielQtFramework::onEP_PersonalModelTBtnClicked);
	QObject::connect(ui.EP_CollectModelTBtn, &QToolButton::clicked, this, &UrielQtFramework::onEP_CollectModelTBtnClicked);
	QObject::connect(ui.EP_PersonalModelSelectProjectTBtn, &QToolButton::clicked, this, &UrielQtFramework::onEP_PersonalModelSelectProjectTBtnClicked);
	connect(ui.EP_TreeWidget, static_cast<void (QTreeWidget::*)(QTreeWidgetItem*, int)>(&QTreeWidget::itemDoubleClicked), this, &UrielQtFramework::onEP_TreeWidgetItemDoubleClicked);
	connect(ui.EP_StaffTreeWidget, static_cast<void (QTreeWidget::*)(QTreeWidgetItem*, int)>(&QTreeWidget::itemDoubleClicked), this, &UrielQtFramework::onEP_StaffTreeWidgetItemDoubleClicked);
	
}

void UrielQtFramework::initializePersonalModelUi()
{
	ui.EP_PersonalModelStartTime->setDateTime(QDateTime::currentDateTime());
	ui.EP_PersonalModelEndTime->setDateTime(QDateTime::currentDateTime());
	ui.EP_PersonalModelTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.EP_PersonalModelTableView->setSortingEnabled(true);
	ui.EP_PersonalModelTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.EP_PersonalModelTableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
	ui.EP_PersonalModelTableView->setShowGrid(true);
	ui.EP_PersonalModelTableView->verticalHeader()->setVisible(false);
	ui.EP_PersonalModelTableView->setAlternatingRowColors(true);
	ui.EP_PersonalModelTableView->setMouseTracking(true);
	ui.EP_PersonalModelTableView->setSelectionMode(QAbstractItemView::ContiguousSelection);//设置为连续选择模式
	ui.EP_PersonalModelTableView->setContextMenuPolicy(Qt::ActionsContextMenu);//设置为action菜单模式

	QAction * PersonalModelInvoiceAddAction = new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/add.png"), QStringLiteral("添加"), this);
	QAction * PersonalModelInvoiceEditAction = new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/edit.png"), QStringLiteral("编辑"), this);
	QAction * PersonalModelInvoiceDeleteAction = new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/delete.png"), QStringLiteral("删除"), this);
	QAction * PersonalModelCollectSheerPreviewAction = new QAction(QIcon(":/Expense/Resources/Expense/summarizing.png"), QStringLiteral("汇总单"), this);
	QAction * PersonalModelGodownEntryPreviewAction = new QAction(QIcon(":/Expense/Resources/Expense/godownentry.png"), QStringLiteral("入库单"), this);
	QAction * PersonalModelStatisticsPreviewAction = new QAction(QIcon(":/Expense/Resources/Expense/analyze.png"), QStringLiteral("统计"), this);
	QAction * PersonalModelHistoryAction = new QAction(QIcon(":/Expense/Resources/Expense/history.png"), QStringLiteral("历史记录"), this);
	
	ui.EP_PersonalModelTableView->addAction(PersonalModelInvoiceAddAction);
	ui.EP_PersonalModelTableView->addAction(PersonalModelInvoiceEditAction);
	ui.EP_PersonalModelTableView->addAction(PersonalModelInvoiceDeleteAction);
	ui.EP_PersonalModelTableView->addAction(PersonalModelCollectSheerPreviewAction);
	ui.EP_PersonalModelTableView->addAction(PersonalModelGodownEntryPreviewAction);
	ui.EP_PersonalModelTableView->addAction(PersonalModelStatisticsPreviewAction);
	ui.EP_PersonalModelTableView->addAction(PersonalModelHistoryAction);

	connect(PersonalModelInvoiceAddAction, &QAction::triggered, this, &UrielQtFramework::onEP_PersonalModelAddTBtnClicked);
	connect(PersonalModelInvoiceEditAction, &QAction::triggered, this, &UrielQtFramework::onEP_PersonalModelEditTBtnClicked);
	connect(PersonalModelInvoiceDeleteAction, &QAction::triggered, this, &UrielQtFramework::onEP_PersonalModelDeleteTBtnClicked);
	connect(PersonalModelCollectSheerPreviewAction, &QAction::triggered, this, &UrielQtFramework::onEP_PersonalModelCollectSheerPreviewTBtnClicked);
	connect(PersonalModelGodownEntryPreviewAction, &QAction::triggered, this, &UrielQtFramework::onEP_PersonalModelGodownEntryPreviewTBtnClicked);
	connect(PersonalModelStatisticsPreviewAction, &QAction::triggered, this, &UrielQtFramework::onEP_PersonalModelStatisticsPreviewTBtnClicked);
	connect(PersonalModelHistoryAction, &QAction::triggered, this, &UrielQtFramework::onEP_PersonalModelHistoryTBtnClicked);

	connect(ui.EP_PersonalModelTableView, static_cast<void (QTableView::*)(const QModelIndex &)>(&QTableView::doubleClicked), this, &UrielQtFramework::onEP_PersonalModelTableViewDoubleClicked);

	m_pUrielInvoiceTableModel = m_pDatabase->creatInvoiceTableModel();
	m_pUrielInvoiceTableSortFilterModel = new QSortFilterProxyModel;
	m_pUrielInvoiceTableSortFilterModel->setDynamicSortFilter(true);
	m_pUrielInvoiceTableSortFilterModel->setSourceModel(m_pUrielInvoiceTableModel);
	ui.EP_PersonalModelTableView->setModel(m_pUrielInvoiceTableSortFilterModel);
	ui.EP_PersonalModelTableView->setColumnHidden(0,true);
	//ID,ReimburseCode,Type,Name,Model,Quantity,Unit,Univalent,AggregateAmount,Description,InvoiceImagePath,BuyScreenshotPath,VerificationImagePath,ReimbursePerson,ReimburseTime,FilingState,Remark
	QObject::connect(ui.EP_PersonalModelTableView, static_cast<void (QTableView::*)(const QModelIndex &)>(&QTableView::pressed), this, &UrielQtFramework::onPersonalModelTableViewItemPressed);
	QList<int> wdls;
	wdls << 0 << 120 << 120 << 200 << 130 << 60 << 40 << 100 << 100 << 80 << 80 << 80 <<100<< 100;
	for (int i = 0; i < wdls.size(); i++)
	{
		ui.EP_PersonalModelTableView->setColumnWidth(i, wdls[i]);
	}
	//m_pDatabase->updateInvoiceTableModel(" WHERE ReimbursePerson = '" + m_pOptions->getAccount() + "'");
	
}//EP_CodeComboBox

void UrielQtFramework::setPersonalModelSignalsAndSlots()
{
	
	QObject::connect(ui.EP_PersonalModelSelectCodeTBtn, &QToolButton::clicked, this, &UrielQtFramework::onEP_PersonalModelSelectCodeTBtnClicked);
	QObject::connect(ui.EP_PersonalModelCreateCodeTBtn, &QToolButton::clicked, this, &UrielQtFramework::onEP_PersonalModelCreateCodeTBtnClicked);
	QObject::connect(ui.EP_PersonalModelAddTBtn, &QToolButton::clicked, this, &UrielQtFramework::onEP_PersonalModelAddTBtnClicked);
	QObject::connect(ui.EP_PersonalModelEditTBtn, &QToolButton::clicked, this, &UrielQtFramework::onEP_PersonalModelEditTBtnClicked);
	QObject::connect(ui.EP_PersonalModelDeleteTBtn, &QToolButton::clicked, this, &UrielQtFramework::onEP_PersonalModelDeleteTBtnClicked);
	QObject::connect(ui.EP_PersonalModelCollectSheerPreviewTBtn, &QToolButton::clicked, this, &UrielQtFramework::onEP_PersonalModelCollectSheerPreviewTBtnClicked);
	QObject::connect(ui.EP_PersonalModelGodownEntryPreviewTBtn, &QToolButton::clicked, this, &UrielQtFramework::onEP_PersonalModelGodownEntryPreviewTBtnClicked);
	QObject::connect(ui.EP_PersonalModelExportPreviewTBtn, &QToolButton::clicked, this, &UrielQtFramework::onEP_PersonalModelExportPreviewTBtnClicked);
	QObject::connect(ui.EP_PersonalModelStatisticsPreviewTBtn, &QToolButton::clicked, this, &UrielQtFramework::onEP_PersonalModelStatisticsPreviewTBtnClicked);
	QObject::connect(ui.EP_PersonalModelHistoryTBtn, &QToolButton::clicked, this, &UrielQtFramework::onEP_PersonalModelHistoryTBtnClicked);
	QObject::connect(ui.EP_CodeComboBox, static_cast<void (QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged), this, &UrielQtFramework::onEP_CodeComboBoxCurrentIndexChanged);
}

void UrielQtFramework::onEP_PersonalModelTableViewDoubleClicked(const QModelIndex &index)
{
	onEP_PersonalModelEditTBtnClicked();
}

void UrielQtFramework::setEP_TreeWidgetContent(const QString & content)
{
	if (this->m_pEP_TreeWidgetRootItem)
	{
		for (int i = 0; i < this->m_pEP_TreeWidgetRootItem->childCount(); ++i)
		{
			QTreeWidgetItem *item = this->m_pEP_TreeWidgetRootItem->child(i);
			delete item;
			item = nullptr;
		}
		delete this->m_pEP_TreeWidgetRootItem;
		this->m_pEP_TreeWidgetRootItem = nullptr;
	}
	ui.EP_TreeWidget->clear();
	ui.EP_TreeWidget->setColumnCount(1);
	ui.EP_TreeWidget->setHeaderHidden(true);
	QStringList childItemList;
	m_pDatabase->getInvoiceListbyReimburseCodeAndType(childItemList, ui.EP_CodeComboBox->currentText(), ui.EP_PersonalModelSelectedProjectLabel->text(), m_pOptions->getAccount());
	this->m_pEP_TreeWidgetRootItem = new QTreeWidgetItem(ui.EP_TreeWidget, QStringList(content + QStringLiteral("(共%0张)").arg(childItemList.count())));
	this->m_pEP_TreeWidgetRootItem->setIcon(0, QIcon(":/Mainwindow/Resources/UrielQtFramework/class.png"));
	for each (QString var in childItemList)
	{
		QTreeWidgetItem *item = new QTreeWidgetItem(this->m_pEP_TreeWidgetRootItem, QStringList(var));
		item->setToolTip(0, var);
		item->setIcon(0, QIcon(":/Mainwindow/Resources/UrielQtFramework/invoice.png"));
		this->m_pEP_TreeWidgetRootItem->addChild(item);
	}
	ui.DP_TreeWidget->addTopLevelItem(this->m_pEP_TreeWidgetRootItem);
	//ui.DP_TreeWidget->expandItem(this->m_pEP_TreeWidgetRootItem);
	ui.DP_TreeWidget->expandAll();
}//EP_CollectModelSheerPreviewTBtn

void UrielQtFramework::setEP_HistoryModelTreeWidgetContent() {
	if (this->m_pEP_TreeWidgetRootItem)
	{
		for (int i = 0; i < this->m_pEP_TreeWidgetRootItem->childCount(); ++i)
		{
			QTreeWidgetItem *item = this->m_pEP_TreeWidgetRootItem->child(i);
			delete item;
			item = nullptr;
		}
		delete this->m_pEP_TreeWidgetRootItem;
		this->m_pEP_TreeWidgetRootItem = nullptr;
	}
	QStringList ProjectList;
	m_pDatabase->getAllProjectByReimburseCode(ProjectList, ui.EP_CodeComboBox->currentText());

	ui.EP_TreeWidget->clear();
	ui.EP_TreeWidget->setColumnCount(1);
	ui.EP_TreeWidget->setHeaderHidden(true);
	for each (QString var in ProjectList)
	{
		QStringList childItemList;
		m_pDatabase->getInvoiceListbyReimburseCodeAndType(childItemList, ui.EP_CodeComboBox->currentText(), var, m_pOptions->getAccount());
		this->m_pEP_TreeWidgetRootItem = new QTreeWidgetItem(ui.EP_TreeWidget, QStringList(var+QStringLiteral("(共%0张)").arg(childItemList.count())));
		this->m_pEP_TreeWidgetRootItem->setIcon(0, QIcon(":/Mainwindow/Resources/UrielQtFramework/class.png"));
		
		
		for each (QString var_ in childItemList)
		{
			QTreeWidgetItem *item = new QTreeWidgetItem(this->m_pEP_TreeWidgetRootItem, QStringList(var_));
			item->setToolTip(0, var_);
			item->setIcon(0, QIcon(":/Mainwindow/Resources/UrielQtFramework/invoice.png"));
		}
		ui.DP_TreeWidget->addTopLevelItem(this->m_pEP_TreeWidgetRootItem);
		//ui.DP_TreeWidget->expandItem(this->m_pEP_TreeWidgetRootItem);
		ui.DP_TreeWidget->expandAll();
	}

	
}

void UrielQtFramework::onEP_TreeWidgetItemDoubleClicked(QTreeWidgetItem* item_ , int col) {
	if (m_eExpenseOperationModel == ExpenseOperationModel::HistoryModel || m_eExpenseOperationModel == ExpenseOperationModel::PersonalModel) {
		sUrielInvoiceInfoItem item;
		QString szInvoiceProject;
		QString szInvoiceName;
		if (item_->parent()) {
			szInvoiceProject = item_->parent()->text(0).split("(")[0];
			szInvoiceName = item_->text(0).split("(")[0];
		}

		int id = m_pDatabase->getInvoiceIDByReimburseCode_Project_Name(ui.EP_CodeComboBox->currentText(), szInvoiceProject, szInvoiceName);

		m_pDatabase->getInvoiceInfoByID(item, QString::number(id));
		InvoiceInfo InvoiceDlg(m_pDatabase, m_pOptions, this);
		InvoiceDlg.setInvoiceInfoItem(item);
		InvoiceDlg.exec();

		setEP_TreeWidgetContent(ui.EP_PersonalModelSelectedProjectLabel->text());
		m_pDatabase->updateInvoiceTableModel(" WHERE ReimbursePerson = '" + m_pOptions->getAccount() +"' AND ReimburseCode = '" + ui.EP_CodeComboBox->currentText() + "'");
	}
	else {
		if (!item_->parent()) {
			ui.EP_CollectModelCollectSheerLabel_4->setText(item_->text(0).split("(")[0]);
		}
		else if (item_->parent() && item_->childCount()) {
			ui.EP_CollectModelSelectedProjectLabel->setText(item_->text(0).split("(")[0]);
		}

	}
	//EP_CollectModelSelectedProjectLabel
	//EP_CollectModelSelectedStaffLabel
}
void UrielQtFramework::onEP_CodeComboBoxCurrentIndexChanged(const QString & text) {
	switch (m_eExpenseOperationModel)
	{
	case ExpenseOperationModel::HistoryModel: {
		setEP_HistoryModelTreeWidgetContent();
		m_pDatabase->updateInvoiceTableModel(" where ReimburseCode = '" + text + "' and ReimbursePerson='" + m_pOptions->getAccount() + "'");
	}
		break;
	case ExpenseOperationModel::PersonalModel: {
		ui.EP_PersonalModelSelectedProjectLabel->setText(QStringLiteral("实验材料购置费"));
		onExpenseItemSlot(ExpenseItemEnum::PurchaseOfExperimentalMaterials);
		m_pDatabase->updateInvoiceTableModel(" where ReimburseCode = '" + text + "' and ReimbursePerson='" + m_pOptions->getAccount() + "'");
	}
		
		break;
	case ExpenseOperationModel::CollectModel:
	{
		//m_pDatabase->updateInvoiceArchiveTableModel();
		setEP_CollectModelTreeWidgetContent();
		updateEP_StaffTreeWidget();
		m_pDatabase->updateInvoiceArchiveTableModel(" where  ReimburseCode='" + ui.EP_CodeComboBox->currentText() + "'");
		sUrielReimburseStatusItem item;
		m_pDatabase->getReimburseStatusByReimburseCode(item, ui.EP_CodeComboBox->currentText());
		ui.EP_CollectModelAddLockTBtn->setEnabled(item.m_sStatus == QStringLiteral("进行中") ? true : false);
		ui.EP_CollectModelCollectSheerLabel_4->setText(QStringLiteral("尚未选择"));
	}
		break;
	default:
		break;
	}
}

void UrielQtFramework::onEP_HistoryModelTBtnClicked() {
	m_eExpenseOperationModel = ExpenseOperationModel::HistoryModel;
	QStringList ReimburseCodesList;
	m_pDatabase->getAllReimburseCodes(ReimburseCodesList);
	ui.EP_CodeComboBox->clear();
	ui.EP_CodeComboBox->addItems(ReimburseCodesList);
	ui.EP_PersonalModelFrame->hide();
	ui.EP_CollectModelFrame->hide();
	setEP_HistoryModelTreeWidgetContent();
	m_pEP_TreeWidgetDeleteAction->setVisible(false);
	m_pEP_TreeWidgetRenameAction->setVisible(false);
}

void UrielQtFramework::onEP_PersonalModelTBtnClicked()
{
	updateReimburseCode();
	m_eExpenseOperationModel = ExpenseOperationModel::PersonalModel;
	ui.EP_StackedWidget->setCurrentIndex(0);
	ui.EP_PersonalModelFrame->show();
	ui.EP_CollectModelFrame->hide();
	ui.EP_PersonalModelSelectedProjectLabel->setText(QStringLiteral("实验材料购置费"));
	onExpenseItemSlot( ExpenseItemEnum::PurchaseOfExperimentalMaterials);
	ui.EP_CodeComboBox;
	m_pDatabase->updateInvoiceTableModel(" WHERE ReimbursePerson = '" + m_pOptions->getAccount() +"' AND ReimburseCode = '"+ ui.EP_CodeComboBox->currentText()+ "' AND Type = '" + ui.EP_PersonalModelSelectedProjectLabel->text() + "'");
	m_pEP_TreeWidgetDeleteAction->setVisible(false);
	m_pEP_TreeWidgetRenameAction->setVisible(false);
}


void UrielQtFramework::onEP_PersonalModelSelectCodeTBtnClicked()
{
	//ui.EP_CodeComboBox->clear();
	//QStringList ReimburseCodesList;
	//m_pDatabase->getAllReimburseCodes(ReimburseCodesList);
	//ui.EP_CodeComboBox->clear();
	//ui.EP_CodeComboBox->addItems(ReimburseCodesList);

	//updateReimburseCode();
	updateReimburseCode();
	
}

void UrielQtFramework::onEP_PersonalModelCreateCodeTBtnClicked()
{
	if (ui.EP_CodeComboBox->count() != 0)
	{
		InformationDialog dlg(QStringLiteral("信息"), QStringLiteral("已有报销代号，是否继续新建？"), this);
		if (dlg.exec() == QDialog::Rejected) return;
	}
	InputDialog dlg(QStringLiteral("请输入要创建的代号名称"),this);
	QObject::connect(&dlg, static_cast<void (InputDialog::*)(const QString & value)>(&InputDialog::contentSignal), [&](const QString & value)
	{
		
		this->m_sCurrentReimburseCode = value;
		this->m_pDatabase->insertReimburseCode(this->m_sCurrentReimburseCode);
		ui.EP_CodeComboBox->addItem(this->m_sCurrentReimburseCode);
	});
	dlg.exec();
}

#include "UrielGui\Expense\SmallInvoice\SmallInvoice.h"

void UrielQtFramework::onEP_PersonalModelAddTBtnClicked()
{
	
	if (ui.EP_PersonalModelSelectedProjectLabel->text() == QStringLiteral("尚未选择"))
	{
		InformationDialog infor(QStringLiteral("信息"), QStringLiteral("尚未选择项目..."),this);
		infor.exec();
		return;
	}
	if (ui.EP_PersonalModelSelectedProjectLabel->text() == QStringLiteral("市内交通费") ||
		ui.EP_PersonalModelSelectedProjectLabel->text() == QStringLiteral("邮寄费")) {
		SmallInvoice dlg(m_pDatabase, m_pOptions, this);
		dlg.setReimburseCodeAndInvoiceType(ui.EP_CodeComboBox->currentText(), ui.EP_PersonalModelSelectedProjectLabel->text());
		dlg.exec();
	}
	else {
		InvoiceInfo InvoiceDlg(m_pDatabase, m_pOptions, this);
		InvoiceDlg.setReimburseCodeAndInvoiceType(ui.EP_CodeComboBox->currentText(), ui.EP_PersonalModelSelectedProjectLabel->text());
		InvoiceDlg.exec();
	}
	setEP_TreeWidgetContent(ui.EP_PersonalModelSelectedProjectLabel->text());
	m_pDatabase->updateInvoiceTableModel(" WHERE ReimbursePerson = '" + m_pOptions->getAccount() + "' AND ReimburseCode = '" + ui.EP_CodeComboBox->currentText() + "' AND Type = '" + ui.EP_PersonalModelSelectedProjectLabel->text() + "'");

}

void UrielQtFramework::onEP_PersonalModelEditTBtnClicked()
{
	sUrielInvoiceInfoItem item;
	////ID,ReimburseCode,Type,Name,Model,Quantity,Unit,Univalent,AggregateAmount,Description,InvoiceImagePath,BuyScreenshotPath,VerificationImagePath,ReimbursePerson,ReimburseTime,FilingState,Remark
	QModelIndex index = ui.EP_PersonalModelTableView->currentIndex();
	if (index.isValid())
	{
		int mIndex = index.row();
		QModelIndex idx = index.sibling(mIndex, 0);
		if (idx.isValid())
			m_pDatabase->getInvoiceInfoByID(item, idx.data().toString());
	}
	else
	{
		InformationDialog infor(QStringLiteral("信息"), QStringLiteral("尚未选择项目..."), this);
		infor.exec();
		return;
	}
	InvoiceInfo InvoiceDlg(m_pDatabase, m_pOptions, this);
	InvoiceDlg.setInvoiceInfoItem(item);
	InvoiceDlg.exec();
	
	setEP_TreeWidgetContent(ui.EP_PersonalModelSelectedProjectLabel->text());
	m_pDatabase->updateInvoiceTableModel(" WHERE ReimbursePerson = '" + m_pOptions->getAccount() + "' AND ReimburseCode = '" + ui.EP_CodeComboBox->currentText() + "' AND Type = '" + ui.EP_PersonalModelSelectedProjectLabel->text() + "'");
	//m_pDatabase->updateInvoiceTableModel(" WHERE ReimbursePerson = '" + m_pOptions->getAccount() + "'");
}

void UrielQtFramework::onEP_PersonalModelDeleteTBtnClicked()
{
	QModelIndex index = ui.EP_PersonalModelTableView->currentIndex();
	if (index.isValid())
	{
		int mIndex = index.row();
		QModelIndex idx = index.sibling(mIndex, 0);
		if (idx.isValid())
			m_pDatabase->deleteInvoiceInfoByID(idx.data().toString());
	}
	else
	{
		InformationDialog infor(QStringLiteral("信息"), QStringLiteral("尚未选择项目..."), this);
		infor.exec();
		return;
	}
	setEP_TreeWidgetContent(ui.EP_PersonalModelSelectedProjectLabel->text());
	m_pDatabase->updateInvoiceTableModel(" WHERE ReimbursePerson = '" + m_pOptions->getAccount() + "' AND ReimburseCode = '" + ui.EP_CodeComboBox->currentText() + "' AND Type = '" + ui.EP_PersonalModelSelectedProjectLabel->text() + "'");
}

void UrielQtFramework::onEP_PersonalModelCollectSheerPreviewTBtnClicked()
{
	QDir dir(qApp->applicationDirPath());
#if defined(Q_OS_MAC)
	dir.cd(QFile::decodeName("../Resources"));
#endif

	QString fileName = QCoreApplication::applicationDirPath() + QStringLiteral("/UrielFiles/浙江大学报销汇总单.xml");
	auto report = new QtRPT(this);
	//report->setBackgroundImage(QPixmap(dir.absolutePath() + "/examples_report/qt_background_portrait.png"));
	//report->recordCount << ui->tableWidget->rowCount();
	report->loadReport(fileName);

	QObject::connect(report, SIGNAL(setValue(const int, const QString, QVariant&, const int)),
		this, SLOT(setSummarySheetValue(const int, const QString, QVariant&, const int)));
	QObject::connect(report, SIGNAL(setValueImage(const int, const QString, QImage&, const int)),
		this, SLOT(setSummarySheetValueImage(const int, const QString, QImage&, const int)));
	//report->setCallbackFunc(getReportValue);
	report->printExec(true);
}

//enum class ExpenseItemEnum
//{
//	LocalTransportation,//市内交通费
//	OfficeSupplies,//办公用品
//	PurchaseOfProfessionalMaterials, //专业材料购置费
//	PurchaseOfExperimentalMaterials,//实验材料购置费
//	SportingGoodsPurchaseFee,//体育用品购置费
//	XeroxFee,//资料复印费
//	Typography,//版面印刷费
//	MaterialTestingAndProcessingFee,//材料测试加工费
//	LodgingExpenses,//实习费
//	StudentActivityFee,//学生活动费
//	Correspondence,//通讯费
//	PostFee,//邮寄费
//	SelfServiceCost,//自备车费用
//	MotorVehicleMaintenance,//机动车维修费
//	OfficeEquipmentMaintenance,//办公设备维修费
//	EquipmentMaintenanceFee,//仪器设备维修费
//	TrainingFees,//培训费
//	EntertainmentExpense,//招待费
//	ConstructionOfFixedAssets,//固定资产构建费
//	Streamer,//横幅
//	Other//其他
//};

void UrielQtFramework::setSummarySheetValue(const int recNo, const QString paramName, QVariant &paramValue, const int reportPage)
{
	Q_UNUSED(reportPage);
	if (paramName == QStringLiteral("20    年    月    日")) {
		paramValue = "  " + QString::number(QDateTime::currentDateTime().date().year()) + QStringLiteral(" 年 ") +
			QString::number(QDateTime::currentDateTime().date().month()) + QStringLiteral(" 月 ") +
			QString::number(QDateTime::currentDateTime().date().day()) + QStringLiteral(" 日 ");
	}
	if (paramName == "LocalTransportation") {
		double dvalue = m_pDatabase->getSumOfClaimSummaryProject(ExpenseItemEnum::LocalTransportation, ui.EP_CodeComboBox->currentText());
		if (dvalue)
			paramValue = QString::number(dvalue);
	}
	if (paramName == "OfficeSupplies") {
		double dvalue = m_pDatabase->getSumOfClaimSummaryProject(ExpenseItemEnum::OfficeSupplies, ui.EP_CodeComboBox->currentText());
		if (dvalue)
			paramValue = QString::number(dvalue);
	}
	if (paramName == "PurchaseOfProfessionalMaterials") {
		double dvalue = m_pDatabase->getSumOfClaimSummaryProject(ExpenseItemEnum::PurchaseOfProfessionalMaterials, ui.EP_CodeComboBox->currentText());
		if (dvalue)
			paramValue = QString::number(dvalue);
	}
	if (paramName == "PurchaseOfExperimentalMaterials") {
		double dvalue = m_pDatabase->getSumOfClaimSummaryProject(ExpenseItemEnum::PurchaseOfExperimentalMaterials, ui.EP_CodeComboBox->currentText());
		if (dvalue)
			paramValue = QString::number(dvalue);
	}
	if (paramName == "SportingGoodsPurchaseFee") {
		double dvalue = m_pDatabase->getSumOfClaimSummaryProject(ExpenseItemEnum::SportingGoodsPurchaseFee, ui.EP_CodeComboBox->currentText());
		if (dvalue)
			paramValue = QString::number(dvalue);
	}
	if (paramName == "XeroxFee") {
		double dvalue = m_pDatabase->getSumOfClaimSummaryProject(ExpenseItemEnum::XeroxFee, ui.EP_CodeComboBox->currentText());
		if (dvalue)
			paramValue = QString::number(dvalue);
	}
	if (paramName == "Typography") {
		double dvalue = m_pDatabase->getSumOfClaimSummaryProject(ExpenseItemEnum::Typography, ui.EP_CodeComboBox->currentText());
		if (dvalue)
			paramValue = QString::number(dvalue);
	}
	if (paramName == "MaterialTestingAndProcessingFee") {
		double dvalue = m_pDatabase->getSumOfClaimSummaryProject(ExpenseItemEnum::MaterialTestingAndProcessingFee, ui.EP_CodeComboBox->currentText());
		if (dvalue)
			paramValue = QString::number(dvalue);
	}
	if (paramName == "LodgingExpenses") {
		double dvalue = m_pDatabase->getSumOfClaimSummaryProject(ExpenseItemEnum::LodgingExpenses, ui.EP_CodeComboBox->currentText());
		if (dvalue)
			paramValue = QString::number(dvalue);
	}
	if (paramName == "StudentActivityFee") {
		double dvalue = m_pDatabase->getSumOfClaimSummaryProject(ExpenseItemEnum::StudentActivityFee, ui.EP_CodeComboBox->currentText());
		if (dvalue)
			paramValue = QString::number(dvalue);
	}
	if (paramName == "Correspondence") {
		double dvalue = m_pDatabase->getSumOfClaimSummaryProject(ExpenseItemEnum::Correspondence, ui.EP_CodeComboBox->currentText());
		if (dvalue)
			paramValue = QString::number(dvalue);
	}
	if (paramName == "PostFee") {
		double dvalue = m_pDatabase->getSumOfClaimSummaryProject(ExpenseItemEnum::PostFee, ui.EP_CodeComboBox->currentText());
		if (dvalue)
			paramValue = QString::number(dvalue);
	}
	if (paramName == "SelfServiceCost") {
		double dvalue = m_pDatabase->getSumOfClaimSummaryProject(ExpenseItemEnum::SelfServiceCost, ui.EP_CodeComboBox->currentText());
		if (dvalue)
			paramValue = QString::number(dvalue);
	}
	if (paramName == "MotorVehicleMaintenance") {
		double dvalue = m_pDatabase->getSumOfClaimSummaryProject(ExpenseItemEnum::MotorVehicleMaintenance, ui.EP_CodeComboBox->currentText());
		if (dvalue)
			paramValue = QString::number(dvalue);
	}
	if (paramName == "OfficeEquipmentMaintenance") {
		double dvalue = m_pDatabase->getSumOfClaimSummaryProject(ExpenseItemEnum::OfficeEquipmentMaintenance, ui.EP_CodeComboBox->currentText());
		if (dvalue)
			paramValue = QString::number(dvalue);
	}
	if (paramName == "EquipmentMaintenanceFee") {
		double dvalue = m_pDatabase->getSumOfClaimSummaryProject(ExpenseItemEnum::EquipmentMaintenanceFee, ui.EP_CodeComboBox->currentText());
		if (dvalue)
			paramValue = QString::number(dvalue);
	}
	if (paramName == "TrainingFees") {
		double dvalue = m_pDatabase->getSumOfClaimSummaryProject(ExpenseItemEnum::TrainingFees, ui.EP_CodeComboBox->currentText());
		if (dvalue)
			paramValue = QString::number(dvalue);
	}
	if (paramName == "EntertainmentExpense") {
		double dvalue = m_pDatabase->getSumOfClaimSummaryProject(ExpenseItemEnum::EntertainmentExpense, ui.EP_CodeComboBox->currentText());
		if (dvalue)
			paramValue = QString::number(dvalue);
	}
	if (paramName == "ConstructionOfFixedAssets") {
		double dvalue = m_pDatabase->getSumOfClaimSummaryProject(ExpenseItemEnum::ConstructionOfFixedAssets, ui.EP_CodeComboBox->currentText());
		if (dvalue)
			paramValue = QString::number(dvalue);
	}
	if (paramName == "Streamer") {
		double dvalue = m_pDatabase->getSumOfClaimSummaryProject(ExpenseItemEnum::Streamer, ui.EP_CodeComboBox->currentText());
		if (dvalue)
			paramValue = QString::number(dvalue);
	}
	if (paramName == "Other") {
		double dvalue = m_pDatabase->getSumOfClaimSummaryProject(ExpenseItemEnum::Other, ui.EP_CodeComboBox->currentText());
		if (dvalue)
			paramValue = QString::number(dvalue);
	}
	if (paramName == "CapitalRMB") {
		double dvalue = m_pDatabase->getTotalSumOfClaimSummary(ui.EP_CodeComboBox->currentText());
		if (dvalue)
			paramValue = m_pOptions->DigitalChineseUppercase(dvalue)/*+QStringLiteral("        ￥:")+QString::number(dvalue)*/;
	}
	if (paramName == "RMB"|| paramName == "Money_1") {
		double dvalue = m_pDatabase->getTotalSumOfClaimSummary(ui.EP_CodeComboBox->currentText());
		if (dvalue)
			paramValue = QString::number(dvalue);
	}
	if (paramName == "BillCount") {
		paramValue = QString::number(m_pDatabase->getTotalBillCount(ui.EP_CodeComboBox->currentText()));
	}
	if (paramName == "SchoolWorkNumber_1") {
		sUrielAccountInfo account;
		m_pDatabase->getUserAccount(account, m_pOptions->getAccount());
		paramValue = account.m_sSchoolWorkNumber;
	}
	if (paramName == "Name_1") {
		paramValue = m_pOptions->getAccount();
	}
	if (paramName == "Bank_1") {
		sUrielAccountInfo account;
		m_pDatabase->getUserAccount(account, m_pOptions->getAccount());
		paramValue = account.m_sBankCardNumber;
	}
	if (paramName == "BankType") {
		sUrielAccountInfo account;
		m_pDatabase->getUserAccount(account, m_pOptions->getAccount());
		if(account.m_sBankType== QStringLiteral("中国建设银行"))
			paramValue = QStringLiteral("银行（建行●农行□中信□工行□中行□）");
		else if (account.m_sBankType == QStringLiteral("中国农业银行"))
			paramValue = QStringLiteral("银行（建行□农行●中信□工行□中行□）");
		else if (account.m_sBankType == QStringLiteral("中信银行"))
			paramValue = QStringLiteral("银行（建行□农行□中信●工行□中行□）");
		else if (account.m_sBankType == QStringLiteral("中国工商银行"))
			paramValue = QStringLiteral("银行（建行□农行□中信□工行●中行□）");
		else if (account.m_sBankType == QStringLiteral("中国银行"))
			paramValue = QStringLiteral("银行（建行□农行□中信□工行□中行●）"); 
	}

}

void UrielQtFramework::setSummarySheetValueImage(const int recNo, const QString paramName, QImage &paramValue, const int reportPage)
{
	Q_UNUSED(recNo);
	Q_UNUSED(reportPage);

	if (paramName == "image") {
		auto image = new QImage(QCoreApplication::applicationDirPath() + "/pdf.png");
		paramValue = *image;
	}
}


void UrielQtFramework::onEP_PersonalModelGodownEntryPreviewTBtnClicked()
{
	QDir dir(qApp->applicationDirPath());
#if defined(Q_OS_MAC)
	dir.cd(QFile::decodeName("../Resources"));
#endif
	m_sMaterialList.clear();
	m_pDatabase->getMaterialCostInvoiceListByReimburseCode(m_sMaterialList, ui.EP_CodeComboBox->currentText());
	QString fileName = dir.absolutePath() + QStringLiteral("/UrielFiles/浙江大学科研材料入库单%0页.xml")
		.arg(m_sMaterialList.size() >= 25 ? 2 : 1);
	auto report = new QtRPT(this);
	report->loadReport(fileName);

	QObject::connect(report, SIGNAL(setValue(const int, const QString, QVariant&, const int)),
		this, SLOT(setStorageSheetValue(const int, const QString, QVariant&, const int)));
	QObject::connect(report, SIGNAL(setValueImage(const int, const QString, QImage&, const int)),
		this, SLOT(setStorageSheetValueImage(const int, const QString, QImage&, const int)));
	//report->setCallbackFunc(getReportValue);
	
	report->printExec(true);
	m_sMaterialList.clear();
}

void UrielQtFramework::setStorageSheetValue(const int recNo, const QString paramName, QVariant &paramValue, const int reportPage) {
	Q_UNUSED(reportPage);
	
	//number_1;Name_1;Model_1;Unit_1;Quantity_1;UnitPrice_1;Total_1;Remarks_1
	QString szNumber = "number_";
	QString szName = "Name_";
	QString szModel = "Model_";
	QString szUnit = "Unit_";
	QString szQuantity = "Quantity_";
	QString szUnitPrice = "UnitPrice_";
	QString szTotal = "Total_";
	QString szRemarks = "Remarks_"; 
	if (paramName == "Date") {
		paramValue = QDateTime::currentDateTime().toString(QStringLiteral("yyyy年MM月dd日"));
		return;
	}

	for (int i = 1; i <= m_sMaterialList.size(); ++i)
	{
		if (paramName == szNumber+QString::number(i)) {
				paramValue = QString::number(i);
				return;
		}
		if (paramName == szName + QString::number(i)) {
			paramValue = m_sMaterialList[i-1].m_sName;
			return;
		}
		if (paramName == szModel + QString::number(i)) {
			paramValue = m_sMaterialList[i - 1].m_sModel;
			return;
		}
		if (paramName == szUnit + QString::number(i)) {
			paramValue = m_sMaterialList[i - 1].m_sUnit;
			return;
		}
		if (paramName == szQuantity + QString::number(i)) {
			paramValue = m_sMaterialList[i - 1].m_iQuantity;
			return;
		}
		if (paramName == szUnitPrice + QString::number(i)) {
			paramValue = m_sMaterialList[i - 1].m_dUnivalent;
			return;
		}
		if (paramName == szTotal + QString::number(i)) {
			paramValue = m_sMaterialList[i - 1].m_dAggregateAmount;
			return;
		}
		if (paramName == szRemarks + QString::number(i)) {
			paramValue = m_sMaterialList[i - 1].m_sRemark;
			return;
		}
	}

	if (m_sMaterialList.size() < 25) {
		if (paramName == "LTotal_1") {
			double dvalue = 0.0;
			for (int i = 0; i < m_sMaterialList.size(); ++i)
				dvalue += m_sMaterialList[i].m_dAggregateAmount;
			paramValue = QString::number(dvalue);
			return;
		}

		if (paramName == "BTotal_1") {
			double dvalue = 0.0;
			for (int i = 0; i < m_sMaterialList.size(); ++i)
				dvalue += m_sMaterialList[i].m_dAggregateAmount;
			paramValue = m_pOptions->DigitalChineseUppercase(dvalue);
			return;
		}
	}
	else {
		if (paramName == "LTotal_2") {
			double dvalue = 0.0;
			for (int i = 0; i < m_sMaterialList.size(); ++i)
				dvalue += m_sMaterialList[i].m_dAggregateAmount;
			paramValue = QString::number(dvalue);
			return;
		}

		if (paramName == "BTotal_2") {
			double dvalue = 0.0;
			for (int i = 0; i < m_sMaterialList.size(); ++i)
				dvalue += m_sMaterialList[i].m_dAggregateAmount;
			paramValue = m_pOptions->DigitalChineseUppercase(dvalue);
			return;
		}
	}
}
void UrielQtFramework::setStorageSheetValueImage(const int recNo, const QString paramName, QImage &paramValue, const int reportPage) {

}
 
void UrielQtFramework::onEP_PersonalModelExportPreviewTBtnClicked()
{

}

void UrielQtFramework::onEP_PersonalModelStatisticsPreviewTBtnClicked()
{
	QList<sUrielInvoiceInfoItem> InvoiceList;
	m_pDatabase->getAllInvoiceListByReimburseCode(InvoiceList, ui.EP_CodeComboBox->currentText());
	ReimbursementStatistics dlg(this);
	dlg.setExpenseOperationModel(ExpenseOperationModel::PersonalModel);
	dlg.setPMInvoiceList(InvoiceList);
	dlg.showReport();
	dlg.exec();
	//InvoiceList.clear();
}

void UrielQtFramework::onEP_PersonalModelHistoryTBtnClicked()
{
}

void UrielQtFramework::onEP_PersonalModelSelectProjectTBtnClicked()
{
	ExpenseItem expenseItem(cursor().pos(),this); 
	QObject::connect(&expenseItem, static_cast<void (ExpenseItem::*)(const ExpenseItemEnum & v)>(&ExpenseItem::expenseItemSignal), this,&UrielQtFramework::onExpenseItemSlot);
	expenseItem.exec();
	m_pDatabase->updateInvoiceTableModel(" WHERE ReimbursePerson = '" + m_pOptions->getAccount() + "' AND ReimburseCode = '" + ui.EP_CodeComboBox->currentText() + "' AND Type = '" + ui.EP_PersonalModelSelectedProjectLabel->text() + "'");
}
//EP_PersonalModelStatisticsPreviewTBtn
void UrielQtFramework::onExpenseItemSlot(const ExpenseItemEnum & v)
{
	switch (v)
	{
	case ExpenseItemEnum::LocalTransportation:
	{
		ui.EP_PersonalModelSelectedProjectLabel->setText(QStringLiteral("市内交通费"));
		setEP_TreeWidgetContent(ui.EP_PersonalModelSelectedProjectLabel->text());
		break;
	}
	case ExpenseItemEnum::OfficeSupplies:
	{
		ui.EP_PersonalModelSelectedProjectLabel->setText(QStringLiteral("办公用品"));
		setEP_TreeWidgetContent(ui.EP_PersonalModelSelectedProjectLabel->text());
		break;
	}
	case ExpenseItemEnum::PurchaseOfProfessionalMaterials:
	{
		ui.EP_PersonalModelSelectedProjectLabel->setText(QStringLiteral("专业材料购置费"));
		setEP_TreeWidgetContent(ui.EP_PersonalModelSelectedProjectLabel->text());
		break;
	}
	case ExpenseItemEnum::PurchaseOfExperimentalMaterials:
	{
		ui.EP_PersonalModelSelectedProjectLabel->setText(QStringLiteral("实验材料购置费"));
		setEP_TreeWidgetContent(ui.EP_PersonalModelSelectedProjectLabel->text());
		break;
	}
	case ExpenseItemEnum::SportingGoodsPurchaseFee:
	{
		ui.EP_PersonalModelSelectedProjectLabel->setText(QStringLiteral("体育用品购置费"));
		setEP_TreeWidgetContent(ui.EP_PersonalModelSelectedProjectLabel->text());
		break;
	}
	case ExpenseItemEnum::XeroxFee:
	{
		ui.EP_PersonalModelSelectedProjectLabel->setText(QStringLiteral("资料复印费"));
		setEP_TreeWidgetContent(ui.EP_PersonalModelSelectedProjectLabel->text());
		break;
	}
	case ExpenseItemEnum::Typography:
	{
		ui.EP_PersonalModelSelectedProjectLabel->setText(QStringLiteral("版面印刷费"));
		setEP_TreeWidgetContent(ui.EP_PersonalModelSelectedProjectLabel->text());
		break;
	}
	case ExpenseItemEnum::MaterialTestingAndProcessingFee:
	{
		ui.EP_PersonalModelSelectedProjectLabel->setText(QStringLiteral("材料测试加工费"));
		setEP_TreeWidgetContent(ui.EP_PersonalModelSelectedProjectLabel->text());
		break;
	}
	case ExpenseItemEnum::LodgingExpenses:
	{
		ui.EP_PersonalModelSelectedProjectLabel->setText(QStringLiteral("实习费"));
		setEP_TreeWidgetContent(ui.EP_PersonalModelSelectedProjectLabel->text());
		break;
	}
	case ExpenseItemEnum::StudentActivityFee:
	{
		ui.EP_PersonalModelSelectedProjectLabel->setText(QStringLiteral("学生活动费"));
		setEP_TreeWidgetContent(ui.EP_PersonalModelSelectedProjectLabel->text());
		break;
	}
	case ExpenseItemEnum::Correspondence:
	{
		ui.EP_PersonalModelSelectedProjectLabel->setText(QStringLiteral("通讯费"));
		setEP_TreeWidgetContent(ui.EP_PersonalModelSelectedProjectLabel->text());
		break;
	}
	case ExpenseItemEnum::PostFee:
	{
		ui.EP_PersonalModelSelectedProjectLabel->setText(QStringLiteral("邮寄费"));
		setEP_TreeWidgetContent(ui.EP_PersonalModelSelectedProjectLabel->text());
		break;
	}
	case ExpenseItemEnum::SelfServiceCost:
	{
		ui.EP_PersonalModelSelectedProjectLabel->setText(QStringLiteral("自备车费用"));
		setEP_TreeWidgetContent(ui.EP_PersonalModelSelectedProjectLabel->text());
		break;
	}
	case ExpenseItemEnum::MotorVehicleMaintenance:
	{
		ui.EP_PersonalModelSelectedProjectLabel->setText(QStringLiteral("机动车维修费"));
		setEP_TreeWidgetContent(ui.EP_PersonalModelSelectedProjectLabel->text());
		break;
	}
	case ExpenseItemEnum::OfficeEquipmentMaintenance:
	{
		ui.EP_PersonalModelSelectedProjectLabel->setText(QStringLiteral("办公设备维修费"));
		setEP_TreeWidgetContent(ui.EP_PersonalModelSelectedProjectLabel->text());
		break;
	}
	case ExpenseItemEnum::EquipmentMaintenanceFee:
	{
		ui.EP_PersonalModelSelectedProjectLabel->setText(QStringLiteral("仪器设备维修费"));
		setEP_TreeWidgetContent(ui.EP_PersonalModelSelectedProjectLabel->text());
		break;
	}
	case ExpenseItemEnum::TrainingFees:
	{
		ui.EP_PersonalModelSelectedProjectLabel->setText(QStringLiteral("培训费"));
		setEP_TreeWidgetContent(ui.EP_PersonalModelSelectedProjectLabel->text());
		break;
	}
	case ExpenseItemEnum::EntertainmentExpense:
	{
		ui.EP_PersonalModelSelectedProjectLabel->setText(QStringLiteral("招待费"));
		setEP_TreeWidgetContent(ui.EP_PersonalModelSelectedProjectLabel->text());
		break;
	}
	case ExpenseItemEnum::ConstructionOfFixedAssets:
	{
		ui.EP_PersonalModelSelectedProjectLabel->setText(QStringLiteral("固定资产构建费"));
		setEP_TreeWidgetContent(ui.EP_PersonalModelSelectedProjectLabel->text());
		break;
	}
	case ExpenseItemEnum::Streamer:
	{
		ui.EP_PersonalModelSelectedProjectLabel->setText(QStringLiteral("横幅"));
		setEP_TreeWidgetContent(ui.EP_PersonalModelSelectedProjectLabel->text());
		break;
	}
	case ExpenseItemEnum::Other:
	{
		ui.EP_PersonalModelSelectedProjectLabel->setText(QStringLiteral("其他"));
		setEP_TreeWidgetContent(ui.EP_PersonalModelSelectedProjectLabel->text());
		break;
	}
	default:
		break;
	}
}

void UrielQtFramework::onEP_CollectModelTBtnClicked()
{
	m_eExpenseOperationModel = ExpenseOperationModel::CollectModel;
	ui.EP_StackedWidget->setCurrentIndex(1);
	ui.EP_PersonalModelFrame->hide();
	ui.EP_CollectModelFrame->show();
	updateEP_StaffTreeWidget();
	setEP_CollectModelTreeWidgetContent();
	QStringList ReimburseCodesList;
	m_pDatabase->getAllReimburseCodes(ReimburseCodesList);
	ui.EP_CodeComboBox->clear();
	ui.EP_CodeComboBox->addItems(ReimburseCodesList);

	//updateReimburseCode();
	m_pDatabase->updateInvoiceArchiveTableModel(" where  ReimburseCode='" + ui.EP_CodeComboBox->currentText() + "'");
	m_CollectModeCurrentStaff="";
	m_CollectModeCurrentProject="";

	sUrielReimburseStatusItem item;
	m_pDatabase->getReimburseStatusByReimburseCode(item, ui.EP_CodeComboBox->currentText());
	ui.EP_CollectModelAddLockTBtn->setEnabled(item.m_sStatus == QStringLiteral("进行中") ? true : false);
	m_pEP_TreeWidgetDeleteAction->setVisible(true);
	m_pEP_TreeWidgetRenameAction->setVisible(true);
}


void UrielQtFramework::initializeCollectModelUi(){
	

	ui.EP_CollectModelTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.EP_CollectModelTableView->setSortingEnabled(true);
	ui.EP_CollectModelTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.EP_CollectModelTableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
	ui.EP_CollectModelTableView->setShowGrid(true);
	ui.EP_CollectModelTableView->verticalHeader()->setVisible(false);
	ui.EP_CollectModelTableView->setAlternatingRowColors(true);
	ui.EP_CollectModelTableView->setMouseTracking(true);
	ui.EP_CollectModelTableView->setSelectionMode(QAbstractItemView::ContiguousSelection);//设置为连续选择模式
	ui.EP_CollectModelTableView->setContextMenuPolicy(Qt::ActionsContextMenu);//设置为action菜单模式

	QAction * CollectModelArchivedAction = new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/Archived.png"), QStringLiteral("归档"), this);
	QAction * CollectModelUnArchivedAction = new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/release.png"), QStringLiteral("解除"), this);
	QAction * CollectModelRefreshAction = new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/refresh.png"), QStringLiteral("更新"), this);

	ui.EP_CollectModelTableView->addAction(CollectModelArchivedAction);
	ui.EP_CollectModelTableView->addAction(CollectModelUnArchivedAction);
	ui.EP_CollectModelTableView->addAction(CollectModelRefreshAction);

	connect(CollectModelArchivedAction, &QAction::triggered, this, &UrielQtFramework::onEP_CollectModelArchiveTBtnClicked);
	connect(CollectModelUnArchivedAction, &QAction::triggered, this, &UrielQtFramework::onEP_CollectModelUnArchiveTBtnClicked);
	connect(CollectModelRefreshAction, &QAction::triggered, this, &UrielQtFramework::onEP_CollectModelRefreshTBtnClicked);
	
	connect(ui.EP_CollectModelTableView, static_cast<void (QTableView::*)(const QModelIndex &)>(&QTableView::doubleClicked), this, &UrielQtFramework::onEP_CollectModelTableViewDoubleClicked);

	m_pUrielInvoiceArchiveTableModel = m_pDatabase->creatInvoiceArchiveTableModel();
	m_pUrielInvoiceArchiveTableSortFilterModel = new QSortFilterProxyModel;
	m_pUrielInvoiceArchiveTableSortFilterModel->setDynamicSortFilter(true);
	m_pUrielInvoiceArchiveTableSortFilterModel->setSourceModel(m_pUrielInvoiceArchiveTableModel);
	ui.EP_CollectModelTableView->setModel(m_pUrielInvoiceArchiveTableSortFilterModel);
	
	QObject::connect(ui.EP_CollectModelTableView, static_cast<void (QTableView::*)(const QModelIndex &)>(&QTableView::pressed), this, &UrielQtFramework::onCollectModelTableViewItemPressed);
	QList<int> wdls;
	//ID, Type, Name, Model, Quantity, Unit, Univalent, AggregateAmount, ReimbursePerson, ReimburseTime, FilingState,ArchivesName,Remark 
	wdls << 0 <<  120 << 200 << 130 << 60 << 40 << 100 << 100 << 80 << 80 << 80 << 100 << 100;
	for (int i = 0; i < wdls.size(); i++)
	{
		ui.EP_CollectModelTableView->setColumnWidth(i, wdls[i]);
	}
	ui.EP_CollectModelTableView->setColumnHidden(0, true);
	
	ui.EP_TreeWidget->setContextMenuPolicy(Qt::ActionsContextMenu);

	m_pEP_TreeWidgetDeleteAction = new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/delete.png"), QStringLiteral("删除"), this);
	m_pEP_TreeWidgetRenameAction = new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/rename.png"), QStringLiteral("重命名"), this);
	ui.EP_TreeWidget->addAction(m_pEP_TreeWidgetDeleteAction);
	ui.EP_TreeWidget->addAction(m_pEP_TreeWidgetRenameAction);

	connect(m_pEP_TreeWidgetDeleteAction, &QAction::triggered, this, &UrielQtFramework::onEP_TreeWidgetDeleteActionTriggered);
	connect(m_pEP_TreeWidgetRenameAction, &QAction::triggered, this, &UrielQtFramework::onEP_TreeWidgetRenameActionTriggered);
}

void UrielQtFramework::onEP_TreeWidgetDeleteActionTriggered() {
	QModelIndex index=ui.EP_TreeWidget->currentIndex();
	if (index.isValid())
	{
		int mIndex = index.row();
		QModelIndex idx = index.sibling(mIndex, 0);
		if (idx.isValid()) {
			m_pDatabase->unArchiveAllInvoiceFromSpecifiedSummarySheet(ui.EP_CodeComboBox->currentText(), idx.data().toString().split("(")[0]);
			sUrielReimburseArchivesItem item;
			item.m_sReimburseCode = ui.EP_CodeComboBox->currentText();
			item.m_sArchivesName = idx.data().toString().split("(")[0];
			m_pDatabase->deleteReimburseArchives(item);
		}
	}
	setEP_CollectModelTreeWidgetContent();
	updateEP_StaffTreeWidget();

	if (!m_CollectModeCurrentStaff.split(";")[0].isEmpty() && m_CollectModeCurrentProject.isEmpty()) {
		ui.EP_CollectModelSelectedStaffLabel->setText(m_CollectModeCurrentStaff);
		QStringList currentStaffList = m_CollectModeCurrentStaff.split(";");
		QString strSQL = "";
		for (int i = 0; i<currentStaffList.size(); ++i)
			strSQL += "ReimbursePerson ='" + currentStaffList[i] + "' " + ((i == currentStaffList.size() - 1) ? "" : "or ");
		m_pDatabase->updateInvoiceArchiveTableModel(" where  ReimburseCode='" + ui.EP_CodeComboBox->currentText() + "'"\
			+ (strSQL.isEmpty() ? "" : (" and ( " + strSQL + " )")));
	}
	else if (!m_CollectModeCurrentProject.isEmpty()) {
		m_pDatabase->updateInvoiceArchiveTableModel(" where  ReimburseCode='" + ui.EP_CodeComboBox->currentText() + \
			"' and ReimbursePerson ='" + m_CollectModeCurrentStaff.split("(")[0] + "' and Type= '" + m_CollectModeCurrentProject.split("(")[0] + "'");
	}
	else {
		m_pDatabase->updateInvoiceArchiveTableModel(" where  ReimburseCode='" + ui.EP_CodeComboBox->currentText() + "'");
	}
	ui.EP_CollectModelCollectSheerLabel_4->setText(QStringLiteral("尚未选择"));
}

void UrielQtFramework::onEP_TreeWidgetRenameActionTriggered() {
	InputDialog dlg(QStringLiteral("请输入的汇总单名称"), this);
	QObject::connect(&dlg, static_cast<void (InputDialog::*)(const QString & value)>(&InputDialog::contentSignal), [&](const QString & value)
	{
		if (value.isEmpty()) return;
		QModelIndex index = ui.EP_TreeWidget->currentIndex();
		if (index.isValid())
		{
			int mIndex = index.row();
			QModelIndex idx = index.sibling(mIndex, 0);
			if (idx.isValid()) {
				m_pDatabase->renameAllInvoiceArchiveFromSpecifiedSummarySheet(ui.EP_CodeComboBox->currentText(), idx.data().toString().split("(")[0], value);
				sUrielReimburseArchivesItem item;
				item.m_sReimburseCode = ui.EP_CodeComboBox->currentText();
				item.m_sArchivesName = idx.data().toString().split("(")[0];
				m_pDatabase->renameReimburseArchives(item, value);
			}
		}
		setEP_CollectModelTreeWidgetContent();
		updateEP_StaffTreeWidget();

		if (!m_CollectModeCurrentStaff.split(";")[0].isEmpty() && m_CollectModeCurrentProject.isEmpty()) {
			ui.EP_CollectModelSelectedStaffLabel->setText(m_CollectModeCurrentStaff);
			QStringList currentStaffList = m_CollectModeCurrentStaff.split(";");
			QString strSQL = "";
			for (int i = 0; i<currentStaffList.size(); ++i)
				strSQL += "ReimbursePerson ='" + currentStaffList[i] + "' " + ((i == currentStaffList.size() - 1) ? "" : "or ");
			m_pDatabase->updateInvoiceArchiveTableModel(" where  ReimburseCode='" + ui.EP_CodeComboBox->currentText() + "'"\
				+ (strSQL.isEmpty() ? "" : (" and ( " + strSQL + " )")));
		}
		else if (!m_CollectModeCurrentProject.isEmpty()) {
			m_pDatabase->updateInvoiceArchiveTableModel(" where  ReimburseCode='" + ui.EP_CodeComboBox->currentText() + \
				"' and ReimbursePerson ='" + m_CollectModeCurrentStaff.split("(")[0] + "' and Type= '" + m_CollectModeCurrentProject.split("(")[0] + "'");
		}
		else {
			m_pDatabase->updateInvoiceArchiveTableModel(" where  ReimburseCode='" + ui.EP_CodeComboBox->currentText() + "'");
		}
		ui.EP_CollectModelCollectSheerLabel_4->setText(QStringLiteral("尚未选择"));
	});
	dlg.exec();

}
void UrielQtFramework::updateEP_StaffTreeWidget() {

	if (this->m_pEP_StaffTreeWidgetRootItem)
	{
		for (int i = 0; i < this->m_pEP_StaffTreeWidgetRootItem->childCount(); ++i)
		{
			QTreeWidgetItem *item = this->m_pEP_StaffTreeWidgetRootItem->child(i);
			if (item) {
				for (int j = 0; j < item->childCount(); ++j)
				{
					QTreeWidgetItem *childitem = item->child(i);
					delete childitem;
					childitem = nullptr;
				}
			}
			delete item;
			item = nullptr;
		}
		delete this->m_pEP_StaffTreeWidgetRootItem;
		this->m_pEP_StaffTreeWidgetRootItem = nullptr;
	}
	QStringList classList;
	classList << QStringLiteral("待归档人员") << QStringLiteral("已全部归档人员") << QStringLiteral("无报销人员");

	ui.EP_StaffTreeWidget->clear();
	ui.EP_StaffTreeWidget->setColumnCount(1);
	ui.EP_StaffTreeWidget->setHeaderHidden(true);
	QStringList unArchivedStaffList;
	m_pDatabase->getunArchivedStaffByReimburseCode(unArchivedStaffList, ui.EP_CodeComboBox->currentText());
	this->m_pEP_StaffTreeWidgetRootItem = new QTreeWidgetItem(ui.EP_StaffTreeWidget, QStringList(classList[0] + QStringLiteral("(共%0人)").arg(unArchivedStaffList.size())));
	this->m_pEP_StaffTreeWidgetRootItem->setIcon(0, QIcon(":/Mainwindow/Resources/UrielQtFramework/unArchived.png"));

	for each (QString var in unArchivedStaffList)
	{
		int count=m_pDatabase->getunArchivedCountByReimburseCodeAndStaff(ui.EP_CodeComboBox->currentText(), var);
		int Total = m_pDatabase->getInvoiceCountByReimburseCodeAndStaff(ui.EP_CodeComboBox->currentText(), var);
		QTreeWidgetItem *item = new QTreeWidgetItem(this->m_pEP_StaffTreeWidgetRootItem, QStringList(var+QStringLiteral("(待归档%0/%1张)").arg(count).arg(Total)));
		item->setToolTip(0, var);
		item->setIcon(0, QIcon(":/Mainwindow/Resources/UrielQtFramework/unArchivedStaff.png"));
		//QList<sUrielInvoiceInfoItem> InvoicetList;
		//m_pDatabase->getInvoicetListByReimburseCodeAndStaff(InvoicetList,ui.EP_CodeComboBox->currentText(), var);
		QStringList ProjectList;
		m_pDatabase->getProjectListByReimburseCodeAndStaff(ProjectList, ui.EP_CodeComboBox->currentText(), var);
		for each (QString Project in ProjectList)
		{
			int count = m_pDatabase->getunArchivedCountByReimburseCodeAndProjectAndStaff(ui.EP_CodeComboBox->currentText(), var.split("(")[0], Project);
			int Total = m_pDatabase->getInvoiceCountByReimburseCodeAndProjectAndStaff(ui.EP_CodeComboBox->currentText(), var.split("(")[0], Project);
			QTreeWidgetItem *childitem = new QTreeWidgetItem(item, QStringList(Project + QStringLiteral("(%0/%1)").arg(count).arg(Total)));
			childitem->setToolTip(0, Project + QStringLiteral("(%0/%1)").arg(count).arg(Total));
			childitem->setIcon(0, QIcon(":/Mainwindow/Resources/UrielQtFramework/project01.png"));
		}
		this->m_pEP_StaffTreeWidgetRootItem->addChild(item);
	}
	ui.EP_StaffTreeWidget->addTopLevelItem(this->m_pEP_StaffTreeWidgetRootItem);
	ui.EP_StaffTreeWidget->expandAll();
	QStringList ArchivedStaffList;
	m_pDatabase->getArchivedStaffByReimburseCode(ArchivedStaffList, ui.EP_CodeComboBox->currentText());
	
	for each (QString var in ArchivedStaffList) 
		for each (QString var_ in unArchivedStaffList)
			if (ArchivedStaffList.indexOf(var_)!=-1)
				ArchivedStaffList.removeAt(ArchivedStaffList.indexOf(var));
		
	this->m_pEP_StaffTreeWidgetRootItem = new QTreeWidgetItem(ui.EP_StaffTreeWidget, QStringList(classList[1] + QStringLiteral("(共%0人)").arg(ArchivedStaffList.size())));
	this->m_pEP_StaffTreeWidgetRootItem->setIcon(0, QIcon(":/Mainwindow/Resources/UrielQtFramework/Archived.png"));
	for each (QString var in ArchivedStaffList)
	{
		int count = m_pDatabase->getArchivedCountByReimburseCodeAndStaff(ui.EP_CodeComboBox->currentText(), var);
		QTreeWidgetItem *item = new QTreeWidgetItem(this->m_pEP_StaffTreeWidgetRootItem, QStringList(var + QStringLiteral("(已归档%0张)").arg(count)));
		item->setToolTip(0, var);
		item->setIcon(0, QIcon(":/Mainwindow/Resources/UrielQtFramework/ArchivedStaff.png"));
		QStringList ProjectList;
		m_pDatabase->getProjectListByReimburseCodeAndStaff(ProjectList, ui.EP_CodeComboBox->currentText(), var);
		for each (QString Project in ProjectList)
		{
			int Total = m_pDatabase->getInvoiceCountByReimburseCodeAndProjectAndStaff(ui.EP_CodeComboBox->currentText(), var.split("(")[0], Project);
			QTreeWidgetItem *childitem = new QTreeWidgetItem(item, QStringList(Project + QStringLiteral("(%0)").arg(Total)));
			childitem->setToolTip(0, Project + QStringLiteral("(%0)").arg(Total));
			childitem->setIcon(0, QIcon(":/Mainwindow/Resources/UrielQtFramework/project01.png"));
		}
		this->m_pEP_StaffTreeWidgetRootItem->addChild(item);
	}
	ui.EP_StaffTreeWidget->addTopLevelItem(this->m_pEP_StaffTreeWidgetRootItem);
	ui.EP_StaffTreeWidget->expandAll();

	QStringList OtherUserList;
	m_pDatabase->getAllUserName(OtherUserList);
	for each (QString var in unArchivedStaffList)
	{
		if (OtherUserList.indexOf(var) != -1)
			OtherUserList.removeAt(OtherUserList.indexOf(var));
	}
	for each (QString var in ArchivedStaffList)
	{
		if (OtherUserList.indexOf(var) != -1)
			OtherUserList.removeAt(OtherUserList.indexOf(var));
	}
	this->m_pEP_StaffTreeWidgetRootItem = new QTreeWidgetItem(ui.EP_StaffTreeWidget, QStringList(classList[2] + QStringLiteral("(共%0人)").arg(OtherUserList.size())));
	this->m_pEP_StaffTreeWidgetRootItem->setIcon(0, QIcon(":/Mainwindow/Resources/UrielQtFramework/other01.png"));

	for each (QString var in OtherUserList)
	{
		QTreeWidgetItem *item = new QTreeWidgetItem(this->m_pEP_StaffTreeWidgetRootItem, QStringList(var));
		item->setToolTip(0, var);
		item->setIcon(0, QIcon(":/Mainwindow/Resources/UrielQtFramework/NoReimbursement.png"));
	}
	ui.EP_StaffTreeWidget->addTopLevelItem(this->m_pEP_StaffTreeWidgetRootItem);

	ui.EP_StaffTreeWidget->expandAll();
}
void UrielQtFramework::setCollectModelSignalsAndSlots()
{
	QObject::connect(ui.EP_CollectModelNewCollectTBtn, &QToolButton::clicked, this, &UrielQtFramework::onEP_CollectModelNewCollectTBtnClicked);
	QObject::connect(ui.EP_CollectModelArchiveTBtn, &QToolButton::clicked, this, &UrielQtFramework::onEP_CollectModelArchiveTBtnClicked);
	QObject::connect(ui.EP_CollectModelSheerPreviewTBtn, &QToolButton::clicked, this, &UrielQtFramework::onEP_CollectModelSheerPreviewTBtnClicked);
	QObject::connect(ui.EP_CollectModelGodownEntryPreviewTBtn, &QToolButton::clicked, this, &UrielQtFramework::onEP_CollectModelGodownEntryPreviewTBtnClicked);
	QObject::connect(ui.EP_CollectModelScreenshotPreviewTBtn, &QToolButton::clicked, this, &UrielQtFramework::onEP_CollectModelScreenshotPreviewTBtnClicked);
	QObject::connect(ui.EP_CollectModelInvoiceVerificationTBtn, &QToolButton::clicked, this, &UrielQtFramework::onEP_CollectModelInvoiceVerificationTBtnClicked);
	QObject::connect(ui.EP_CollectModelBusinessApprovalTBtn, &QToolButton::clicked, this, &UrielQtFramework::onEP_CollectModelBusinessApprovalTBtnClicked);
	QObject::connect(ui.EP_CollectModelPayWarrantTBtn, &QToolButton::clicked, this, &UrielQtFramework::onEP_CollectModelPayWarrantTBtnClicked);
	QObject::connect(ui.EP_CollectModelExportTBtn, &QToolButton::clicked, this, &UrielQtFramework::onEP_CollectModelExportTBtnClicked);
	QObject::connect(ui.EP_CollectModelStatisticsTBtn, &QToolButton::clicked, this, &UrielQtFramework::onEP_CollectModelStatisticsTBtnClicked);
	QObject::connect(ui.EP_CollectModelHistoryTBtn, &QToolButton::clicked, this, &UrielQtFramework::onEP_CollectModelHistoryTBtnClicked);
	QObject::connect(ui.EP_CollectModelUnArchiveTBtn, &QToolButton::clicked, this, &UrielQtFramework::onEP_CollectModelUnArchiveTBtnClicked);
	QObject::connect(ui.EP_CollectModelRefreshTBtn, &QToolButton::clicked, this, &UrielQtFramework::onEP_CollectModelRefreshTBtnClicked);
	QObject::connect(ui.EP_CollectModelLiftingProhibitionTBtn, &QToolButton::clicked, this, &UrielQtFramework::onEP_CollectModelLiftingProhibitionTBtnClicked);
	QObject::connect(ui.EP_CollectModelAddLockTBtn, &QToolButton::clicked, this, &UrielQtFramework::onEP_CollectModelAddLockTBtnTBtnClicked);
}

void UrielQtFramework::setEP_CollectModelTreeWidgetContent() {
	if (this->m_pEP_TreeWidgetRootItem)
	{
		for (int i = 0; i < this->m_pEP_TreeWidgetRootItem->childCount(); ++i)
		{
			QTreeWidgetItem *item = this->m_pEP_TreeWidgetRootItem->child(i);
			if (item) {
				for (int j = 0; j < item->childCount(); ++j)
				{
					QTreeWidgetItem *childitem = item->child(i);
					delete childitem;
					childitem = nullptr;
				}
			}
			delete item;
			item = nullptr;
		}
		delete this->m_pEP_TreeWidgetRootItem;
		this->m_pEP_TreeWidgetRootItem = nullptr;
	}
	QList<sUrielReimburseArchivesItem> ArchivesList;
	
	m_pDatabase->getArchivesByReimburseCode(ArchivesList, ui.EP_CodeComboBox->currentText());

	ui.EP_TreeWidget->clear();
	ui.EP_TreeWidget->setColumnCount(1);
	ui.EP_TreeWidget->setHeaderHidden(true);
	for each (sUrielReimburseArchivesItem var in ArchivesList)
	{
		QStringList ProjectItemList;
		m_pDatabase->getProjectListbyReimburseCodeAndArchives(ProjectItemList, ui.EP_CodeComboBox->currentText(), var.m_sArchivesName);

		this->m_pEP_TreeWidgetRootItem = new QTreeWidgetItem(ui.EP_TreeWidget, QStringList(var.m_sArchivesName + QStringLiteral("(共%0个)").arg(ProjectItemList.size())));
		this->m_pEP_TreeWidgetRootItem->setIcon(0, QIcon(":/Mainwindow/Resources/UrielQtFramework/Archives.png"));


		for each (QString var_ in ProjectItemList)
		{
			QList<sUrielInvoiceInfoItem> InvoiceList;
			m_pDatabase->getInvoiceListbyReimburseCodeAndArchivesAndProject(InvoiceList, ui.EP_CodeComboBox->currentText(), var.m_sArchivesName, var_);
			QTreeWidgetItem *m_pEP_TreeWidgetChildRootItem = new QTreeWidgetItem(this->m_pEP_TreeWidgetRootItem, QStringList(var_ + QStringLiteral("(共%0张)").arg(InvoiceList.size())));
			m_pEP_TreeWidgetChildRootItem->setToolTip(0, var_);
			m_pEP_TreeWidgetChildRootItem->setIcon(0, QIcon(":/Mainwindow/Resources/UrielQtFramework/project.png"));
			for each (sUrielInvoiceInfoItem InvoiceVar in InvoiceList)
			{
				QTreeWidgetItem *item = new QTreeWidgetItem(m_pEP_TreeWidgetChildRootItem, QStringList(InvoiceVar.m_sName + QStringLiteral("(%0)").arg(InvoiceVar.m_sReimbursePerson)));
				item->setToolTip(0, var_);
				item->setIcon(0, QIcon(":/Mainwindow/Resources/UrielQtFramework/invoice.png"));
			}
			m_pEP_TreeWidgetRootItem->addChild(m_pEP_TreeWidgetChildRootItem);
			//m_pEP_TreeWidgetRootItem->exp();
		}
		ui.DP_TreeWidget->addTopLevelItem(this->m_pEP_TreeWidgetRootItem);
		ui.DP_TreeWidget->expandAll();
		//ui.DP_TreeWidget->expandItem(this->m_pEP_TreeWidgetRootItem);
	}

	
}

void UrielQtFramework::onEP_StaffTreeWidgetItemDoubleClicked(QTreeWidgetItem* item_, int col) {

	if (!item_->parent()) {
		for (int i = 0; i < item_->childCount(); ++i) 
			m_CollectModeCurrentStaff += item_->child(i)->text(0).split("(")[0] + ((i != item_->childCount() - 1)?";":"");
		m_CollectModeCurrentProject = "";
	}
	else if (item_->parent() && item_->childCount()) {
		m_CollectModeCurrentStaff = item_->text(0).split("(")[0];
		m_CollectModeCurrentProject = "";
	}
	else {
		m_CollectModeCurrentStaff = item_->parent()->text(0).split("(")[0];
		m_CollectModeCurrentProject = item_->text(0).split("(")[0];
	}
	if (!item_->parent() || (item_->parent() && !item_->parent()->parent())) {
		ui.EP_CollectModelSelectedStaffLabel->setText(m_CollectModeCurrentStaff);
		QStringList currentStaffList = m_CollectModeCurrentStaff.split(";");
		QString strSQL = "";
		for (int i = 0; i<currentStaffList.size(); ++i)
			strSQL += "ReimbursePerson ='" + currentStaffList[i] + "' " + ((i == currentStaffList.size() - 1) ? "" : "or ");
		m_pDatabase->updateInvoiceArchiveTableModel(" where  ReimburseCode='" + ui.EP_CodeComboBox->currentText() + "'"\
			+ (strSQL.isEmpty() ? "" : (" and ( " + strSQL + " )")));
	}
	else {
		m_pDatabase->updateInvoiceArchiveTableModel(" where  ReimburseCode='" + ui.EP_CodeComboBox->currentText() + \
			"' and ReimbursePerson ='" + item_->parent()->text(0).split("(")[0] + "' and Type= '" + item_->text(0).split("(")[0] + "'");
	}
	
	
}

void UrielQtFramework::onEP_CollectModelNewCollectTBtnClicked() {
	InputDialog dlg(QStringLiteral("请输入要创建的档案名称"), this);
	QObject::connect(&dlg, static_cast<void (InputDialog::*)(const QString & value)>(&InputDialog::contentSignal), [&](const QString & value)
	{
		sUrielReimburseArchivesItem item;
		item.m_sReimburseCode = ui.EP_CodeComboBox->currentText();
		item.m_sArchivesName = value;
		this->m_pDatabase->insertReimburseArchives(item);
		setEP_CollectModelTreeWidgetContent();
	});
	dlg.exec();
}

void UrielQtFramework::onEP_CollectModelArchiveTBtnClicked() {
	if (ui.EP_CollectModelCollectSheerLabel_4->text()==QStringLiteral("尚未选择")) {
		InformationDialog information(QStringLiteral("信息"), QStringLiteral("尚未创建或选择汇总单"), this);
		information.exec();
		return;
	}
	QItemSelectionModel *selections = ui.EP_CollectModelTableView->selectionModel();
	QModelIndexList selectedIndexs = selections->selectedIndexes();
	QMap <int, int> rowMap;
	double daddValue = 0.0;
	foreach(QModelIndex index, selectedIndexs)
	{
		if (index.isValid())
		{
			QModelIndex idx = index.sibling(index.row(), 0);//id
			if (idx.isValid()) {
				m_pDatabase->archiveInvoiceIntoSummarySheet(index.sibling(index.row(), 0).data().toString(), \
					ui.EP_CollectModelCollectSheerLabel_4->text());
				daddValue += index.sibling(index.row(), 7).data().toDouble();//TotalValue
			}
		}
	}
	sUrielReimburseStatusItem item;
	m_pDatabase->getReimburseStatusByReimburseCode(item,ui.EP_CodeComboBox->currentText());
	if (item.m_sAggregator.indexOf(m_pOptions->getAccount()) == -1)
		item.m_sAggregator+=m_pOptions->getAccount();
	item.m_iReimbursedInvoicesNumber += selectedIndexs.size();
	item.m_dTotalReimbursement += daddValue;
	item.m_tFilingEndTime = QDateTime::currentDateTime();
	


	if (m_pDatabase->isAllInvoiceArchived(ui.EP_CodeComboBox->currentText()) == 0) {
		InformationDialog information(QStringLiteral("信息"), QStringLiteral("发票已全部完成归档，是否禁用该代号？"), this);
		if (information.exec() == QDialog::Accepted) 
			item.m_sStatus = QStringLiteral("已完成");
	}
	m_pDatabase->updateReimburseStatusByReimburseCode(item, ui.EP_CodeComboBox->currentText());
	setEP_CollectModelTreeWidgetContent();
	updateEP_StaffTreeWidget();
	//updateReimburseCode();

	if (!m_CollectModeCurrentStaff.split(";")[0].isEmpty() && m_CollectModeCurrentProject.isEmpty()) {
		ui.EP_CollectModelSelectedStaffLabel->setText(m_CollectModeCurrentStaff);
		QStringList currentStaffList = m_CollectModeCurrentStaff.split(";");
		QString strSQL = "";
		for (int i = 0; i<currentStaffList.size(); ++i)
			strSQL += "ReimbursePerson ='" + currentStaffList[i] + "' " + ((i == currentStaffList.size() - 1) ? "" : "or ");
		m_pDatabase->updateInvoiceArchiveTableModel(" where  ReimburseCode='" + ui.EP_CodeComboBox->currentText() + "'"\
			+ (strSQL.isEmpty() ? "" : (" and ( " + strSQL + " )")));
	}
	else if (!m_CollectModeCurrentProject.isEmpty()) {
		m_pDatabase->updateInvoiceArchiveTableModel(" where  ReimburseCode='" + ui.EP_CodeComboBox->currentText() + \
			"' and ReimbursePerson ='" + m_CollectModeCurrentStaff.split("(")[0] + "' and Type= '" + m_CollectModeCurrentProject.split("(")[0] + "'");
	}
	else {
		m_pDatabase->updateInvoiceArchiveTableModel(" where  ReimburseCode='" + ui.EP_CodeComboBox->currentText() + "'");
	}

}

void UrielQtFramework::onEP_CollectModelUnArchiveTBtnClicked() {
	QItemSelectionModel *selections = ui.EP_CollectModelTableView->selectionModel();
	QModelIndexList selectedIndexs = selections->selectedIndexes();
	double daddValue = 0.0;
	foreach(QModelIndex index, selectedIndexs)
	{
		if (index.isValid())
		{
			QModelIndex idx = index.sibling(index.row(), 0);//id
			if (idx.isValid()) {
				m_pDatabase->unArchiveInvoiceFromSummarySheet(index.sibling(index.row(), 0).data().toString(), \
					ui.EP_CollectModelCollectSheerLabel_4->text());
				daddValue += index.sibling(index.row(), 7).data().toDouble();//TotalValue
			}
		}
	}
	sUrielReimburseStatusItem item;
	m_pDatabase->getReimburseStatusByReimburseCode(item, ui.EP_CodeComboBox->currentText());
	if (item.m_sAggregator.indexOf(m_pOptions->getAccount()) == -1)
		item.m_sAggregator += m_pOptions->getAccount();
	item.m_iReimbursedInvoicesNumber -= selectedIndexs.size();
	item.m_dTotalReimbursement -= daddValue;
	item.m_tFilingEndTime = QDateTime::currentDateTime();
	m_pDatabase->updateReimburseStatusByReimburseCode(item, ui.EP_CodeComboBox->currentText());
	setEP_CollectModelTreeWidgetContent();
	updateEP_StaffTreeWidget();
	//m_pDatabase->updateInvoiceArchiveTableModel();
	if (!m_CollectModeCurrentStaff.split(";")[0].isEmpty() && m_CollectModeCurrentProject.isEmpty()) {
		ui.EP_CollectModelSelectedStaffLabel->setText(m_CollectModeCurrentStaff);
		QStringList currentStaffList = m_CollectModeCurrentStaff.split(";");
		QString strSQL = "";
		for (int i = 0; i<currentStaffList.size(); ++i)
			strSQL += "ReimbursePerson ='" + currentStaffList[i] + "' " + ((i == currentStaffList.size() - 1) ? "" : "or ");
		m_pDatabase->updateInvoiceArchiveTableModel(" where  ReimburseCode='" + ui.EP_CodeComboBox->currentText() + "'"\
			+ (strSQL.isEmpty() ? "" : (" and ( " + strSQL + " )")));
	}
	else if (!m_CollectModeCurrentProject.isEmpty()) {
		m_pDatabase->updateInvoiceArchiveTableModel(" where  ReimburseCode='" + ui.EP_CodeComboBox->currentText() + \
			"' and ReimbursePerson ='" + m_CollectModeCurrentStaff.split("(")[0] + "' and Type= '" + m_CollectModeCurrentProject.split("(")[0] + "'");
	}
	else {
		m_pDatabase->updateInvoiceArchiveTableModel(" where  ReimburseCode='" + ui.EP_CodeComboBox->currentText() + "'");
	}

}

void UrielQtFramework::onEP_CollectModelSheerPreviewTBtnClicked() {
	if (ui.EP_CollectModelCollectSheerLabel_4->text() == QStringLiteral("尚未选择")) {
		InformationDialog information(QStringLiteral("信息"), QStringLiteral("尚未创建或选择汇总单"), this);
		information.exec();
		return;
	}
	QDir dir(qApp->applicationDirPath());
#if defined(Q_OS_MAC)
	dir.cd(QFile::decodeName("../Resources"));
#endif
	m_sCollectModelStaffList.clear();
	m_pDatabase->getStaffListByReimburseCodeAndArchivesName(m_sCollectModelStaffList,ui.EP_CodeComboBox->currentText()\
		, ui.EP_CollectModelCollectSheerLabel_4->text());
	m_listCollectModelStaff.clear();
	for each (QString var in m_sCollectModelStaffList)
	{
		sUrielAccountInfo account;
		m_pDatabase->getUserAccount(account, var);
		m_listCollectModelStaff << account;
	}
	QString fileName = QCoreApplication::applicationDirPath() + QStringLiteral("/UrielFiles/浙江大学报销汇总单%0人.xml")
		.arg(m_sCollectModelStaffList.size());
	auto report = new QtRPT(this);
	//report->setBackgroundImage(QPixmap(dir.absolutePath() + "/examples_report/qt_background_portrait.png"));
	//report->recordCount << ui->tableWidget->rowCount();
	report->loadReport(fileName);

	QObject::connect(report, SIGNAL(setValue(const int, const QString, QVariant&, const int)),
		this, SLOT(setCollectModelSummarySheetValue(const int, const QString, QVariant&, const int)));
	QObject::connect(report, SIGNAL(setValueImage(const int, const QString, QImage&, const int)),
		this, SLOT(setCollectModelSummarySheetValueImage(const int, const QString, QImage&, const int)));
	//report->setCallbackFunc(getReportValue);
	report->printExec(true);
}

void UrielQtFramework::setCollectModelSummarySheetValue(const int recNo, const QString paramName, QVariant &paramValue, const int reportPage) {
	Q_UNUSED(reportPage);
	if (paramName == QStringLiteral("20    年    月    日")) {
			paramValue ="  "+ QString::number(QDateTime::currentDateTime().date().year())+ QStringLiteral(" 年 ")+ 
				QString::number(QDateTime::currentDateTime().date().month()) + QStringLiteral(" 月 ") +
					QString::number(QDateTime::currentDateTime().date().day()) + QStringLiteral(" 日 ");
	}
	if (paramName == "LocalTransportation") {
		double dvalue = m_pDatabase->getSumOfClaimSummaryProject(ExpenseItemEnum::LocalTransportation, ui.EP_CodeComboBox->currentText(),ui.EP_CollectModelCollectSheerLabel_4->text());
		if (dvalue) 
			paramValue = QString::number(dvalue);
	}
	if (paramName == "OfficeSupplies") {
		double dvalue = m_pDatabase->getSumOfClaimSummaryProject(ExpenseItemEnum::OfficeSupplies, ui.EP_CodeComboBox->currentText(), ui.EP_CollectModelCollectSheerLabel_4->text());
		if (dvalue)
			paramValue = QString::number(dvalue);
	}
	if (paramName == "PurchaseOfProfessionalMaterials") {
		double dvalue = m_pDatabase->getSumOfClaimSummaryProject(ExpenseItemEnum::PurchaseOfProfessionalMaterials, ui.EP_CodeComboBox->currentText(), ui.EP_CollectModelCollectSheerLabel_4->text());
		if (dvalue)
			paramValue = QString::number(dvalue);
	}
	if (paramName == "PurchaseOfExperimentalMaterials") {
		double dvalue = m_pDatabase->getSumOfClaimSummaryProject(ExpenseItemEnum::PurchaseOfExperimentalMaterials, ui.EP_CodeComboBox->currentText(), ui.EP_CollectModelCollectSheerLabel_4->text());
		if (dvalue)
			paramValue = QString::number(dvalue);
	}
	if (paramName == "SportingGoodsPurchaseFee") {
		double dvalue = m_pDatabase->getSumOfClaimSummaryProject(ExpenseItemEnum::SportingGoodsPurchaseFee, ui.EP_CodeComboBox->currentText(), ui.EP_CollectModelCollectSheerLabel_4->text());
		if (dvalue)
			paramValue = QString::number(dvalue);
	}
	if (paramName == "XeroxFee") {
		double dvalue = m_pDatabase->getSumOfClaimSummaryProject(ExpenseItemEnum::XeroxFee, ui.EP_CodeComboBox->currentText(), ui.EP_CollectModelCollectSheerLabel_4->text());
		if (dvalue)
			paramValue = QString::number(dvalue);
	}
	if (paramName == "Typography") {
		double dvalue = m_pDatabase->getSumOfClaimSummaryProject(ExpenseItemEnum::Typography, ui.EP_CodeComboBox->currentText(), ui.EP_CollectModelCollectSheerLabel_4->text());
		if (dvalue)
			paramValue = QString::number(dvalue);
	}
	if (paramName == "MaterialTestingAndProcessingFee") {
		double dvalue = m_pDatabase->getSumOfClaimSummaryProject(ExpenseItemEnum::MaterialTestingAndProcessingFee, ui.EP_CodeComboBox->currentText(), ui.EP_CollectModelCollectSheerLabel_4->text());
		if (dvalue)
			paramValue = QString::number(dvalue);
	}
	if (paramName == "LodgingExpenses") {
		double dvalue = m_pDatabase->getSumOfClaimSummaryProject(ExpenseItemEnum::LodgingExpenses, ui.EP_CodeComboBox->currentText(), ui.EP_CollectModelCollectSheerLabel_4->text());
		if (dvalue)
			paramValue = QString::number(dvalue);
	}
	if (paramName == "StudentActivityFee") {
		double dvalue = m_pDatabase->getSumOfClaimSummaryProject(ExpenseItemEnum::StudentActivityFee, ui.EP_CodeComboBox->currentText(), ui.EP_CollectModelCollectSheerLabel_4->text());
		if (dvalue)
			paramValue = QString::number(dvalue);
	}
	if (paramName == "Correspondence") {
		double dvalue = m_pDatabase->getSumOfClaimSummaryProject(ExpenseItemEnum::Correspondence, ui.EP_CodeComboBox->currentText(), ui.EP_CollectModelCollectSheerLabel_4->text());
		if (dvalue)
			paramValue = QString::number(dvalue);
	}
	if (paramName == "PostFee") {
		double dvalue = m_pDatabase->getSumOfClaimSummaryProject(ExpenseItemEnum::PostFee, ui.EP_CodeComboBox->currentText(), ui.EP_CollectModelCollectSheerLabel_4->text());
		if (dvalue)
			paramValue = QString::number(dvalue);
	}
	if (paramName == "SelfServiceCost") {
		double dvalue = m_pDatabase->getSumOfClaimSummaryProject(ExpenseItemEnum::SelfServiceCost, ui.EP_CodeComboBox->currentText(), ui.EP_CollectModelCollectSheerLabel_4->text());
		if (dvalue)
			paramValue = QString::number(dvalue);
	}
	if (paramName == "MotorVehicleMaintenance") {
		double dvalue = m_pDatabase->getSumOfClaimSummaryProject(ExpenseItemEnum::MotorVehicleMaintenance, ui.EP_CodeComboBox->currentText(), ui.EP_CollectModelCollectSheerLabel_4->text());
		if (dvalue)
			paramValue = QString::number(dvalue);
	}
	if (paramName == "OfficeEquipmentMaintenance") {
		double dvalue = m_pDatabase->getSumOfClaimSummaryProject(ExpenseItemEnum::OfficeEquipmentMaintenance, ui.EP_CodeComboBox->currentText(), ui.EP_CollectModelCollectSheerLabel_4->text());
		if (dvalue)
			paramValue = QString::number(dvalue);
	}
	if (paramName == "EquipmentMaintenanceFee") {
		double dvalue = m_pDatabase->getSumOfClaimSummaryProject(ExpenseItemEnum::EquipmentMaintenanceFee, ui.EP_CodeComboBox->currentText(), ui.EP_CollectModelCollectSheerLabel_4->text());
		if (dvalue)
			paramValue = QString::number(dvalue);
	}
	if (paramName == "TrainingFees") {
		double dvalue = m_pDatabase->getSumOfClaimSummaryProject(ExpenseItemEnum::TrainingFees, ui.EP_CodeComboBox->currentText(), ui.EP_CollectModelCollectSheerLabel_4->text());
		if (dvalue)
			paramValue = QString::number(dvalue);
	}
	if (paramName == "EntertainmentExpense") {
		double dvalue = m_pDatabase->getSumOfClaimSummaryProject(ExpenseItemEnum::EntertainmentExpense, ui.EP_CodeComboBox->currentText(), ui.EP_CollectModelCollectSheerLabel_4->text());
		if (dvalue)
			paramValue = QString::number(dvalue);
	}
	if (paramName == "ConstructionOfFixedAssets") {
		double dvalue = m_pDatabase->getSumOfClaimSummaryProject(ExpenseItemEnum::ConstructionOfFixedAssets, ui.EP_CodeComboBox->currentText(), ui.EP_CollectModelCollectSheerLabel_4->text());
		if (dvalue)
			paramValue = QString::number(dvalue);
	}
	if (paramName == "Streamer") {
		double dvalue = m_pDatabase->getSumOfClaimSummaryProject(ExpenseItemEnum::Streamer, ui.EP_CodeComboBox->currentText(), ui.EP_CollectModelCollectSheerLabel_4->text());
		if (dvalue)
			paramValue = QString::number(dvalue);
	}
	if (paramName == "Other") {
		double dvalue = m_pDatabase->getSumOfClaimSummaryProject(ExpenseItemEnum::Other, ui.EP_CodeComboBox->currentText(), ui.EP_CollectModelCollectSheerLabel_4->text());
		if (dvalue)
			paramValue = QString::number(dvalue);
	}
	if (paramName == "CapitalRMB") {
		   double  dvalue = m_pDatabase->getTotalSumOfClaimSummary(ui.EP_CodeComboBox->currentText(), ui.EP_CollectModelCollectSheerLabel_4->text());
		   paramValue = m_pOptions->DigitalChineseUppercase(m_pDatabase->getTotalSumOfClaimSummary(ui.EP_CodeComboBox->currentText(), ui.EP_CollectModelCollectSheerLabel_4->text()))/*+QStringLiteral("        ￥:")+QString::number(dvalue)*/;
	}
	if (paramName == "RMB" ) {
		paramValue = QString::number(m_pDatabase->getTotalSumOfClaimSummary(ui.EP_CodeComboBox->currentText(), ui.EP_CollectModelCollectSheerLabel_4->text()));
	}
	if (paramName == "BillCount") {
		paramValue = QString::number(m_pDatabase->getTotalBillCount(ui.EP_CodeComboBox->currentText(), ui.EP_CollectModelCollectSheerLabel_4->text()));
	}

	for (int i = 1; i < 6; ++i) {
		if (paramName == "SchoolWorkNumber_" + QString::number(i)) {
			if (m_listCollectModelStaff.size()>i-1)
				paramValue = m_listCollectModelStaff[i - 1].m_sSchoolWorkNumber;
			return;
		}
		if (paramName == "Name_" + QString::number(i)) {
			if (m_listCollectModelStaff.size()>i - 1)
				paramValue = m_listCollectModelStaff[i - 1].m_sName;
			return;
		}
		if (paramName == "Bank_" + QString::number(i)) {
			if (m_listCollectModelStaff.size() > i - 1) {
				QString sbank = getBankType(m_listCollectModelStaff[i - 1].m_sBankType);
				paramValue = m_listCollectModelStaff[i - 1].m_sBankCardNumber + sbank;
			}
			return;
		}
		if (paramName == "Money_" + QString::number(i)) {
			if (m_listCollectModelStaff.size() > i - 1) {
				double dvalue = m_pDatabase->getTotalSumOfClaimSummaryOfStaff(ui.EP_CodeComboBox->currentText(), \
					ui.EP_CollectModelCollectSheerLabel_4->text(), m_listCollectModelStaff[i - 1].m_sName);
				paramValue = QString::number(dvalue);
			}
			return;
		}
	}
	
}

QString UrielQtFramework::getBankType(const QString &sbankType) {
	QString sbank;
	if (sbankType == QStringLiteral("中国建设银行"))
		sbank = QStringLiteral("（建行）");
	else if (sbankType == QStringLiteral("中国农业银行"))
		sbank = QStringLiteral("（农行）");
	else if (sbankType == QStringLiteral("中信银行"))
		sbank = QStringLiteral("（中信）");
	else if (sbankType == QStringLiteral("中国工商银行"))
		sbank = QStringLiteral("（工行）");
	else if (sbankType == QStringLiteral("中国银行"))
		sbank = QStringLiteral("（中行）");
	else
		sbank = "";
	return sbank;
}
void UrielQtFramework::setCollectModelSummarySheetValueImage(const int recNo, const QString paramName, QImage &paramValue, const int reportPage) {

}

void UrielQtFramework::onEP_CollectModelGodownEntryPreviewTBtnClicked() {
	if (ui.EP_CollectModelCollectSheerLabel_4->text() == QStringLiteral("尚未选择")) {
		InformationDialog information(QStringLiteral("信息"), QStringLiteral("尚未创建或选择汇总单"), this);
		information.exec();
		return;
	}
	QDir dir(qApp->applicationDirPath());
#if defined(Q_OS_MAC)
	dir.cd(QFile::decodeName("../Resources"));
#endif
	m_sMaterialList.clear();
	m_pDatabase->getMaterialCostInvoiceListByReimburseCode(m_sMaterialList, ui.EP_CodeComboBox->currentText(),
		ui.EP_CollectModelCollectSheerLabel_4->text());
	QString fileName = dir.absolutePath() + QStringLiteral("/UrielFiles/浙江大学科研材料入库单%0页.xml")
		.arg(m_sMaterialList.size() >= 25?2:1);
	auto report = new QtRPT(this);
	report->loadReport(fileName);

	QObject::connect(report, SIGNAL(setValue(const int, const QString, QVariant&, const int)),
		this, SLOT(setStorageSheetValue(const int, const QString, QVariant&, const int)));
	QObject::connect(report, SIGNAL(setValueImage(const int, const QString, QImage&, const int)),
		this, SLOT(setStorageSheetValueImage(const int, const QString, QImage&, const int)));
	//report->setCallbackFunc(getReportValue);
	
	report->printExec(true);
	m_sMaterialList.clear();
	
}
#pragma comment (lib, "ThirdPartyLibraries\\QtRPT\\lib\\QtRPT.lib")
void UrielQtFramework::onEP_CollectModelScreenshotPreviewTBtnClicked() {
	QStringList imageList;
	m_pDatabase->getImageListByReimburseCodeAndArchives(imageList, ui.EP_CodeComboBox->currentText(), ui.EP_CollectModelCollectSheerLabel_4->text());
	QList<QImage> imgList;
	for each (QString var in imageList)
	{
		QString file_path = QCoreApplication::applicationDirPath() + "/TempFiles";
		QFileInfo fileInfo(var);
		QString sfileName;
		if (file_path.at(file_path.size() - 1) == '/')
			sfileName = file_path + fileInfo.fileName();
		else
			sfileName = file_path + "/" + fileInfo.fileName();

		if (!QFile::exists(sfileName)) {
			ProgressDialog *progressDialog = new ProgressDialog(this);
			progressDialog->setTotalProgressBarMax(1/*(ui.RP_FileListTreeWidget->currentItem()->text(3).split("K")[0].toInt() * 1024)*/);
			QObject::connect(m_pUrielFtp, static_cast<void (UrielFtp::*)(qint64 readBytes, qint64 totalBytes)>(&UrielFtp::updateDataTransferProgressSignal), \
				progressDialog, &ProgressDialog::updateProgressBarValue);
			progressDialog->setTotalProgressBarMax(1);
			m_pUrielFtp->downloadImageFile(var);
			progressDialog->exec();
			QEventLoop eventloop;
			QTimer::singleShot(100, &eventloop, SLOT(quit()));
			eventloop.exec();
		}
		if(!fileInfo.fileName().isEmpty())
		    imgList.append(QImage(sfileName).scaled(1000,1000/ QImage(sfileName).width()*QImage(sfileName).height()));
	}
	if (imageList.size()) {
		QString pdfDirPath = QFileDialog::getExistingDirectory(this,QStringLiteral("请选择保存路径"));
		QPrinter printerPixmap(QPrinter::HighResolution);
		printerPixmap.setPageSize(QPrinter::A4);  //设置纸张大小为A4
		printerPixmap.setOutputFormat(QPrinter::PdfFormat);  //设置输出格式为pdf
		QString currentDateTime = QStringLiteral("购买截图")+QDateTime::currentDateTime().toString("_yyyyMMddhhmm");
		QString pdfPath = /*QDir::currentPath()*/ pdfDirPath + "/" + currentDateTime + ".pdf";
		printerPixmap.setOutputFileName(pdfPath);

		QPainter painterPixmap;
		painterPixmap.begin(&printerPixmap);
		QRect rect = painterPixmap.viewport();//9583 13699
		int height = 0;
	
		int multiple = rect.width() / imgList[0].width();
		painterPixmap.scale(multiple, multiple);
		for each (QImage var in imgList)
		{

			if (var.width()) {
				if (height + var.height()>rect.height() / multiple) {
					printerPixmap.newPage();
					height = 0;
				}
				//int multiple = rect.width() / var.width();
				////将图像(所有要画的东西)在pdf上放大multiple-1倍
				painterPixmap.drawImage(0, height, var);
				height += var.height();
			}

		}
		painterPixmap.end();

		QDesktopServices::openUrl(QUrl::fromLocalFile(pdfPath));
	}
}

void UrielQtFramework::setField(RptFieldObject &) {
}
void UrielQtFramework::onEP_CollectModelInvoiceVerificationTBtnClicked() {
	QStringList imageList;
	m_pDatabase->getVerifyImageListByReimburseCodeAndArchives(imageList, ui.EP_CodeComboBox->currentText(), ui.EP_CollectModelCollectSheerLabel_4->text());
	QList<QImage> imgList;
	for each (QString var in imageList)
	{
		QString file_path = QCoreApplication::applicationDirPath() + "/TempFiles";
		QFileInfo fileInfo(var);
		QString sfileName;
		if (file_path.at(file_path.size() - 1) == '/')
			sfileName = file_path + fileInfo.fileName();
		else
			sfileName = file_path + "/" + fileInfo.fileName();

		if (!QFile::exists(sfileName)) {
			ProgressDialog *progressDialog = new ProgressDialog(this);
			progressDialog->setTotalProgressBarMax(1/*(ui.RP_FileListTreeWidget->currentItem()->text(3).split("K")[0].toInt() * 1024)*/);
			QObject::connect(m_pUrielFtp, static_cast<void (UrielFtp::*)(qint64 readBytes, qint64 totalBytes)>(&UrielFtp::updateDataTransferProgressSignal), \
				progressDialog, &ProgressDialog::updateProgressBarValue);
			progressDialog->setTotalProgressBarMax(1);
			m_pUrielFtp->downloadImageFile(var);
			progressDialog->exec();
			QEventLoop eventloop;
			QTimer::singleShot(100, &eventloop, SLOT(quit()));
			eventloop.exec();
		}
		if (!fileInfo.fileName().isEmpty())
			imgList.append(QImage(sfileName).scaled(1000, 1000 / QImage(sfileName).width()*QImage(sfileName).height()));
	}
	if (imageList.size()) {
		QString pdfDirPath = QFileDialog::getExistingDirectory(this, QStringLiteral("请选择保存路径"));
		QPrinter printerPixmap(QPrinter::HighResolution);
		printerPixmap.setPageSize(QPrinter::A4);  //设置纸张大小为A4
		printerPixmap.setOutputFormat(QPrinter::PdfFormat);  //设置输出格式为pdf
		QString currentDateTime = QStringLiteral("发票查验") + QDateTime::currentDateTime().toString("_yyyyMMddhhmm");
		QString pdfPath = /*QDir::currentPath()*/ pdfDirPath + "/" + currentDateTime + ".pdf";
		printerPixmap.setOutputFileName(pdfPath);

		QPainter painterPixmap;
		painterPixmap.begin(&printerPixmap);
		QRect rect = painterPixmap.viewport();//9583 13699
		int height = 0;

		int multiple = rect.width() / imgList[0].width();
		painterPixmap.scale(multiple, multiple);
		for each (QImage var in imgList)
		{

			if (var.width()) {
				if (height + var.height()>rect.height() / multiple) {
					printerPixmap.newPage();
					height = 0;
				}
				//int multiple = rect.width() / var.width();
				////将图像(所有要画的东西)在pdf上放大multiple-1倍
				painterPixmap.drawImage(0, height, var);
				height += var.height();
			}

		}
		painterPixmap.end();
		QDesktopServices::openUrl(QUrl::fromLocalFile(pdfPath));
	}
}
void UrielQtFramework::onEP_CollectModelBusinessApprovalTBtnClicked() {
	//if (ui.EP_CollectModelCollectSheerLabel_4->text() == QStringLiteral("尚未选择")) {
	//	InformationDialog information(QStringLiteral("信息"), QStringLiteral("尚未创建或选择汇总单"), this);
	//	information.exec();
	//	return;
	//}
	QDir dir(qApp->applicationDirPath());
#if defined(Q_OS_MAC)
	dir.cd(QFile::decodeName("../Resources"));
#endif
	m_sMaterialList.clear();
	m_pDatabase->getMaterialCostInvoiceListByReimburseCode(m_sMaterialList, ui.EP_CodeComboBox->currentText(),
		ui.EP_CollectModelCollectSheerLabel_4->text());
	QString fileName = dir.absolutePath() + QStringLiteral("/UrielFiles/浙江大学出差审批单.xml")
		.arg(m_sMaterialList.size() >= 25 ? 2 : 1);
	auto report = new QtRPT(this);
	report->loadReport(fileName);

	QObject::connect(report, SIGNAL(setValue(const int, const QString, QVariant&, const int)),
		this, SLOT(setStorageSheetValue(const int, const QString, QVariant&, const int)));
	QObject::connect(report, SIGNAL(setValueImage(const int, const QString, QImage&, const int)),
		this, SLOT(setStorageSheetValueImage(const int, const QString, QImage&, const int)));
	//report->setCallbackFunc(getReportValue);

	report->printExec(true);
	m_sMaterialList.clear();
}
void UrielQtFramework::onEP_CollectModelPayWarrantTBtnClicked() {
	QDir dir(qApp->applicationDirPath());
#if defined(Q_OS_MAC)
	dir.cd(QFile::decodeName("../Resources"));
#endif
	m_sMaterialList.clear();
	m_pDatabase->getMaterialCostInvoiceListByReimburseCode(m_sMaterialList, ui.EP_CodeComboBox->currentText(),
		ui.EP_CollectModelCollectSheerLabel_4->text());
	QString fileName = dir.absolutePath() + QStringLiteral("/UrielFiles/浙江大学支付情况说明书.xml")
		.arg(m_sMaterialList.size() >= 25 ? 2 : 1);
	auto report = new QtRPT(this);
	report->loadReport(fileName);

	QObject::connect(report, SIGNAL(setValue(const int, const QString, QVariant&, const int)),
		this, SLOT(setStorageSheetValue(const int, const QString, QVariant&, const int)));
	QObject::connect(report, SIGNAL(setValueImage(const int, const QString, QImage&, const int)),
		this, SLOT(setStorageSheetValueImage(const int, const QString, QImage&, const int)));
	//report->setCallbackFunc(getReportValue);

	report->printExec(true);
	m_sMaterialList.clear();
}
void UrielQtFramework::onEP_CollectModelExportTBtnClicked() {

}
#include <QHash>
void UrielQtFramework::onEP_CollectModelStatisticsTBtnClicked() {
	
	QStringList ReimbursePersonList;
	m_pDatabase->getReimbursePersonListByReimburseCodeAndArchives(ReimbursePersonList,ui.EP_CodeComboBox->currentText(),\
		ui.EP_CollectModelCollectSheerLabel_4->text());
	QHash<QString, QList<sUrielInvoiceInfoItem>> InvoiceList;
	for each (QString var in ReimbursePersonList)
	{
		QList<sUrielInvoiceInfoItem> InvoiceListofStaff;
		m_pDatabase->getAllInvoiceListByReimburseCodeAndPersonAndArchives(InvoiceListofStaff, 
			ui.EP_CodeComboBox->currentText(),var, ui.EP_CollectModelCollectSheerLabel_4->text());
		InvoiceList[var] = InvoiceListofStaff;
	}
	ReimbursementStatistics dlg(this);
	dlg.setExpenseOperationModel(ExpenseOperationModel::CollectModel);
	dlg.setCMInvoiceList(InvoiceList);
	dlg.showReport();
	dlg.exec();
}

void UrielQtFramework::onEP_CollectModelHistoryTBtnClicked() {

}

void UrielQtFramework::updateReimburseCode() {
	QStringList AvailableReimburseCodeList;
	m_pDatabase->getAvailableReimburseCodeList(AvailableReimburseCodeList);
	ui.EP_CodeComboBox->clear();
	ui.EP_CodeComboBox->addItems(AvailableReimburseCodeList);
}
void UrielQtFramework::onEP_CollectModelLiftingProhibitionTBtnClicked() {
	LiftingProhibitionDialog dlg(m_pDatabase, this);
	QObject::connect(&dlg, static_cast<void (LiftingProhibitionDialog::*)(const QString & value)>(&LiftingProhibitionDialog::contentSignal), [&](const QString & value)
	{
		m_pDatabase->liftingProhibitReimburseCode(value);
	});
	dlg.exec();
	//updateReimburseCode();
}

void UrielQtFramework::onEP_CollectModelAddLockTBtnTBtnClicked() {
	InformationDialog information(QStringLiteral("信息"), QStringLiteral("加锁后，在个人模式下将无法通过本代号录入发票信息？"), this);
	if(information.exec()==QDialog::Accepted)
		m_pDatabase->ReimburseCodeAddLock(ui.EP_CodeComboBox->currentText());
}

void UrielQtFramework::onEP_CollectModelRefreshTBtnClicked() {

}

void UrielQtFramework::onPersonalModelTableViewItemPressed(const QModelIndex &index) {

}
void UrielQtFramework::onEP_CollectModelTableViewDoubleClicked(const QModelIndex &index) {

}
void UrielQtFramework::onCollectModelTableViewItemPressed(const QModelIndex &index) {

}

#pragma endregion

#pragma region Apply
void UrielQtFramework::initializeApplyUi() {
	ui.AP_SearchFrame->hide();

	ui.AP_TreeWidget->clear();
	ui.AP_TreeWidget->setColumnCount(1);
	ui.AP_TreeWidget->setHeaderHidden(true);
	QStringList ProjectList;
	m_pDatabase->getDistinctApplicationNumberFromMaterialPurchaseApply(ProjectList,m_pOptions->getAccount());
	for each (QString var in ProjectList)
	{
		QStringList MaterialList;
		m_pDatabase->getMaterialNameByApplicationNumber(MaterialList, var);
		QTreeWidgetItem *root = new QTreeWidgetItem(ui.AP_TreeWidget, QStringList(var + QStringLiteral("(共%0张)").arg(MaterialList.count())));
		root->setIcon(0,QIcon(":/Mainwindow/Resources/UrielQtFramework/class01.png"));
		for (int i = 0; i < MaterialList.size(); i++)
		{
			QTreeWidgetItem *item = new QTreeWidgetItem(root, QStringList(MaterialList[i]));
			item->setIcon(0, QIcon(":/Mainwindow/Resources/UrielQtFramework/Material01.png"));
		}
		ui.AP_TreeWidget->addTopLevelItem(root);
		ui.AP_TreeWidget->expandAll();
	}

}

void UrielQtFramework::setApplySignalsAndSlots() {
	QObject::connect(ui.AP_PreviewTBtn, &QToolButton::clicked, this, &UrielQtFramework::onAP_PreviewTBtnClicked);
	QObject::connect(ui.AP_ApplyTBtn, &QToolButton::clicked, this, &UrielQtFramework::onAP_ApplyTBtnClicked);
	QObject::connect(ui.AP_SearchTBtn, &QToolButton::clicked, this, &UrielQtFramework::onAP_SearchTBtnClicked);
	QObject::connect(ui.AP_ReturnTBtn, &QToolButton::clicked, this, &UrielQtFramework::onAP_ReturnTBtnClicked);
	QObject::connect(ui.AP_SearchConfirmTBtn, &QToolButton::clicked, this, &UrielQtFramework::onAP_SearchConfirmTBtnClicked);
	QObject::connect(ui.AP_ApplyConfirmBtn, &QToolButton::clicked, this, &UrielQtFramework::onAP_ApplyConfirmBtnClicked);

	QObject::connect(ui.AP_SerachLineEdit, &QLineEdit::returnPressed, this, &UrielQtFramework::onAP_SerachLineEditClicked);
	QObject::connect(ui.AP_SearchConfirmTBtn, &QToolButton::clicked, this, &UrielQtFramework::onAP_SearchConfirmTBtnClicked);

	QObject::connect(ui.AP_PreviewAddImageBtn, &QToolButton::clicked, this, &UrielQtFramework::onAP_PreviewAddImageBtnClicked);
	QObject::connect(ui.AP_PreviewLookImageBtn, &QToolButton::clicked, this, &UrielQtFramework::onAP_PreviewLookImageBtnClicked);
	QObject::connect(ui.AP_PreviewDeleteImageBtn, &QToolButton::clicked, this, &UrielQtFramework::onAP_PreviewDeleteImageBtnClicked);

	QObject::connect(ui.AP_ApplyAddImageBtn, &QToolButton::clicked, this, &UrielQtFramework::onAP_ApplyAddImageBtnClicked);
	QObject::connect(ui.AP_ApplyLookImageBtn, &QToolButton::clicked, this, &UrielQtFramework::onAP_ApplyLookImageBtnClicked);
	QObject::connect(ui.AP_ApplyDeleteImageBtn, &QToolButton::clicked, this, &UrielQtFramework::onAP_ApplyDeleteImageBtnClicked);
	connect(ui.AP_TreeWidget, static_cast<void (QTreeWidget::*)(QTreeWidgetItem*, int)>(&QTreeWidget::itemClicked), this, &UrielQtFramework::onAP_TreeWidgetItemDoubleClicked);
	
	QObject::connect(ui.AP_ApplyUnitPriceLineEdit_1, &QLineEdit::editingFinished, this, &UrielQtFramework::onAP_ApplyUnitPriceLineEdit_1EditingFinished);
	QObject::connect(ui.AP_ApplyUnitPriceLineEdit_2, &QLineEdit::editingFinished, this, &UrielQtFramework::onAP_ApplyUnitPriceLineEdit_2EditingFinished);
	QObject::connect(ui.AP_ApplyUnitPriceLineEdit_3, &QLineEdit::editingFinished, this, &UrielQtFramework::onAP_ApplyUnitPriceLineEdit_3EditingFinished);
	QObject::connect(ui.AP_ApplyUnitPriceLineEdit_4, &QLineEdit::editingFinished, this, &UrielQtFramework::onAP_ApplyUnitPriceLineEdit_4EditingFinished);
	QObject::connect(ui.AP_ApplyUnitPriceLineEdit_5, &QLineEdit::editingFinished, this, &UrielQtFramework::onAP_ApplyUnitPriceLineEdit_5EditingFinished);
	QObject::connect(ui.AP_ApplyUnitPriceLineEdit_6, &QLineEdit::editingFinished, this, &UrielQtFramework::onAP_ApplyUnitPriceLineEdit_6EditingFinished);
	QObject::connect(ui.AP_ApplyTotalAmountLineEdit, &QLineEdit::returnPressed, this, &UrielQtFramework::onAP_ApplyTotalAmountLineEditReturnPressed);

}

void UrielQtFramework::onAP_ApplyTotalAmountLineEditReturnPressed() {
	double t1 = ui.AP_ApplyTotalLineEdit_1->text().isEmpty() ? 0.0 : ui.AP_ApplyTotalLineEdit_1->text().toDouble();
	double t2 = ui.AP_ApplyTotalLineEdit_2->text().isEmpty() ? 0.0 : ui.AP_ApplyTotalLineEdit_2->text().toDouble();
	double t3 = ui.AP_ApplyTotalLineEdit_3->text().isEmpty() ? 0.0 : ui.AP_ApplyTotalLineEdit_3->text().toDouble();
	double t4 = ui.AP_ApplyTotalLineEdit_4->text().isEmpty() ? 0.0 : ui.AP_ApplyTotalLineEdit_4->text().toDouble();
	double t5 = ui.AP_ApplyTotalLineEdit_5->text().isEmpty() ? 0.0 : ui.AP_ApplyTotalLineEdit_5->text().toDouble();
	double t6 = ui.AP_ApplyTotalLineEdit_6->text().isEmpty() ? 0.0 : ui.AP_ApplyTotalLineEdit_6->text().toDouble();
	ui.AP_ApplyTotalAmountLineEdit->setText(m_pOptions->DigitalChineseUppercase(t1+t2+t3+t4+t5+t6));
}

void UrielQtFramework::onAP_ApplyUnitPriceLineEdit_1EditingFinished() {
	if(!ui.AP_ApplyNumberLineEdit_1->text().isEmpty()&&!ui.AP_ApplyUnitPriceLineEdit_1->text().isEmpty())
		ui.AP_ApplyTotalLineEdit_1->setText(QString::number(ui.AP_ApplyNumberLineEdit_1->text().toDouble()*ui.AP_ApplyUnitPriceLineEdit_1->text().toDouble()));
}
void UrielQtFramework::onAP_ApplyUnitPriceLineEdit_2EditingFinished() {
	if (!ui.AP_ApplyNumberLineEdit_2->text().isEmpty() && !ui.AP_ApplyUnitPriceLineEdit_3->text().isEmpty())
		 ui.AP_ApplyTotalLineEdit_2->setText(QString::number(ui.AP_ApplyNumberLineEdit_2->text().toDouble()*ui.AP_ApplyUnitPriceLineEdit_2->text().toDouble()));
}
void UrielQtFramework::onAP_ApplyUnitPriceLineEdit_3EditingFinished() {
	if (!ui.AP_ApplyNumberLineEdit_3->text().isEmpty() && !ui.AP_ApplyUnitPriceLineEdit_3->text().isEmpty())
		 ui.AP_ApplyTotalLineEdit_3->setText(QString::number(ui.AP_ApplyNumberLineEdit_3->text().toDouble()*ui.AP_ApplyUnitPriceLineEdit_3->text().toDouble()));
}
void UrielQtFramework::onAP_ApplyUnitPriceLineEdit_4EditingFinished() {
	if (!ui.AP_ApplyNumberLineEdit_4->text().isEmpty() && !ui.AP_ApplyUnitPriceLineEdit_4->text().isEmpty())
		ui.AP_ApplyTotalLineEdit_4->setText(QString::number(ui.AP_ApplyNumberLineEdit_4->text().toDouble()*ui.AP_ApplyUnitPriceLineEdit_4->text().toDouble()));
}
void UrielQtFramework::onAP_ApplyUnitPriceLineEdit_5EditingFinished() {
	if (!ui.AP_ApplyNumberLineEdit_5->text().isEmpty() && !ui.AP_ApplyUnitPriceLineEdit_5->text().isEmpty())
		ui.AP_ApplyTotalLineEdit_5->setText(QString::number(ui.AP_ApplyNumberLineEdit_5->text().toDouble()*ui.AP_ApplyUnitPriceLineEdit_5->text().toDouble()));
}
void UrielQtFramework::onAP_ApplyUnitPriceLineEdit_6EditingFinished() {
	if (!ui.AP_ApplyNumberLineEdit_6->text().isEmpty() && !ui.AP_ApplyUnitPriceLineEdit_6->text().isEmpty())
		ui.AP_ApplyTotalLineEdit_6->setText(QString::number(ui.AP_ApplyNumberLineEdit_6->text().toDouble()*ui.AP_ApplyUnitPriceLineEdit_6->text().toDouble()));
}
void UrielQtFramework::setAP_PreviewTable(const sUrielMaterialDeviceItem & item,QLineEdit * SerialNumber, QLineEdit * DeviceName, QLineEdit * ModelSpecification,
	QLineEdit * Unit, QLineEdit * Number, QLineEdit * UnitPrice, QLineEdit * Total) {
	SerialNumber->setText(item.m_sSerialNumber);
	DeviceName->setText(item.m_sMaterialName);
	ModelSpecification->setText(item.m_sModelSpecification);
	Unit->setText(item.m_sUnit);
	Number->setText(item.m_sQuantity);
	UnitPrice->setText(item.m_sUnitPrice);
	Total->setText(item.m_sTotal);
}

void UrielQtFramework::onAP_SerachLineEditClicked() {
	onAP_SearchConfirmTBtnClicked();
}

void UrielQtFramework::onAP_SearchConfirmTBtnClicked() {
	ui.AP_TreeWidget->clear();
	ui.AP_TreeWidget->setColumnCount(1);
	ui.AP_TreeWidget->setHeaderHidden(true);
	QString searchName = ui.AP_SerachLineEdit->text();
	QStringList MaterialList;
	m_pDatabase->getMaterialBySearch(MaterialList, searchName);

	for each (QString var in MaterialList)
	{
		QTreeWidgetItem *root = new QTreeWidgetItem(ui.AP_TreeWidget, QStringList(var));
		root->setIcon(0, QIcon(":/Mainwindow/Resources/UrielQtFramework/Material01.png"));
		ui.AP_TreeWidget->addTopLevelItem(root);
		ui.AP_TreeWidget->expandAll();
	}
}

void UrielQtFramework::onAP_TreeWidgetItemDoubleClicked(QTreeWidgetItem*item_, int col) {
	QString ApplicationNumber;
	if (!m_bIsMaterialSearchMode) {
		if (!item_->parent())
			ApplicationNumber = item_->text(0).split("(")[0];
		else
			ApplicationNumber = item_->parent()->text(0).split("(")[0];
	}
	else {
		ApplicationNumber = m_pDatabase->getApplicationNumberByMaterialName(item_->text(0));
	}
	sUrielMaterialPurchaseApplyItem MaterialPurchaseApplyItem;
	m_pDatabase->getMaterialPurchaseApplyByApplicationNumber(MaterialPurchaseApplyItem,ApplicationNumber);
	ui.AP_PreviewApplicantLineEdit->setText(MaterialPurchaseApplyItem.m_sApplicant);
	ui.AP_PreviewDeclarationDateDateEdit->setDateTime(MaterialPurchaseApplyItem.m_tDeclarationDate);
	ui.AP_PreviewTotalAmountLineEdit->setText(MaterialPurchaseApplyItem.m_sTotalAmount);
	ui.AP_PreviewRequisitionReasonsPlainTextEdit->setPlainText(MaterialPurchaseApplyItem.m_sRequisitionReasons);
	if (MaterialPurchaseApplyItem.m_sAuditStatus == "UnAudited") 
		ui.AP_PreviewAuditOpinionPlainTextEdit->setPlainText( QStringLiteral("尚未审核"));
	else if (MaterialPurchaseApplyItem.m_sAuditStatus == "Audited")
		ui.AP_PreviewAuditOpinionPlainTextEdit->setPlainText(QStringLiteral("审核通过 ")+ MaterialPurchaseApplyItem.m_sAuditOpinion);
	else
		ui.AP_PreviewAuditOpinionPlainTextEdit->setPlainText(QStringLiteral("审核未通过 ") + MaterialPurchaseApplyItem.m_sAuditOpinion);
	ui.AP_PreviewReviewerLabel->setText(MaterialPurchaseApplyItem.m_sReviewer);
	ui.AP_PreviewReviewTimeDateEdit->setDateTime(MaterialPurchaseApplyItem.m_tReviewTime);
	ui.AP_PreviewLinkAddressLineEdit->setText(MaterialPurchaseApplyItem.m_sLinkAddress);

	QString file_path = QCoreApplication::applicationDirPath() + "/TempFiles";
	QFileInfo fileInfo(MaterialPurchaseApplyItem.m_sImagePath);
	QString sfileName;
	if (file_path.at(file_path.size() - 1) == '/')
		sfileName = file_path + fileInfo.fileName();
	else
		sfileName = file_path + "/" + fileInfo.fileName();

	if (!QFile::exists(sfileName)) {
		UrielFtp *urielFtp = UrielFtp::getInstance();
		ProgressDialog *progressDialog = new ProgressDialog(this);
		progressDialog->setTotalProgressBarMax(1/*(ui.RP_FileListTreeWidget->currentItem()->text(3).split("K")[0].toInt() * 1024)*/);
		QObject::connect(urielFtp, static_cast<void (UrielFtp::*)(qint64 readBytes, qint64 totalBytes)>(&UrielFtp::updateDataTransferProgressSignal), \
			progressDialog, &ProgressDialog::updateProgressBarValue);
		progressDialog->setTotalProgressBarMax(1);
		urielFtp->downloadImageFile(MaterialPurchaseApplyItem.m_sImagePath);
		progressDialog->exec();
		QEventLoop eventloop;
		QTimer::singleShot(50, &eventloop, SLOT(quit()));
		eventloop.exec();
	}
	setPreviewImage(QImage(sfileName));
	m_imgPreviewMaterialImage = QImage(sfileName);

	QList<sUrielMaterialDeviceItem> MaterialDeviceList;
	m_pDatabase->getAllMaterialDeviceListByApplicationNumber(MaterialDeviceList, ApplicationNumber);
	if (MaterialDeviceList.size() > 0)
		setAP_PreviewTable(MaterialDeviceList[0],ui.AP_PreviewSerialNumberLineEdit_1,ui.AP_PreviewDeviceNameLineEdit_1,
			ui.AP_PreviewModelSpecificationLineEdit_1,ui.AP_PreviewUnitLineEdit_1,ui.AP_PreviewNumberLineEdit_1,
			ui.AP_PreviewUnitPriceLineEdit_1,ui.AP_PreviewTotalLineEdit_1);
	if (MaterialDeviceList.size() > 1)
		setAP_PreviewTable(MaterialDeviceList[1], ui.AP_PreviewSerialNumberLineEdit_2, ui.AP_PreviewDeviceNameLineEdit_2,
			ui.AP_PreviewModelSpecificationLineEdit_2, ui.AP_PreviewUnitLineEdit_2, ui.AP_PreviewNumberLineEdit_2,
			ui.AP_PreviewUnitPriceLineEdit_2, ui.AP_PreviewTotalLineEdit_2);
	if (MaterialDeviceList.size() > 2)
		setAP_PreviewTable(MaterialDeviceList[2], ui.AP_PreviewSerialNumberLineEdit_3, ui.AP_PreviewDeviceNameLineEdit_3,
			ui.AP_PreviewModelSpecificationLineEdit_3, ui.AP_PreviewUnitLineEdit_3, ui.AP_PreviewNumberLineEdit_3,
			ui.AP_PreviewUnitPriceLineEdit_3, ui.AP_PreviewTotalLineEdit_3);
	if (MaterialDeviceList.size() > 3)
		setAP_PreviewTable(MaterialDeviceList[3], ui.AP_PreviewSerialNumberLineEdit_4, ui.AP_PreviewDeviceNameLineEdit_4,
			ui.AP_PreviewModelSpecificationLineEdit_4, ui.AP_PreviewUnitLineEdit_4, ui.AP_PreviewNumberLineEdit_4,
			ui.AP_PreviewUnitPriceLineEdit_4, ui.AP_PreviewTotalLineEdit_4);
	if (MaterialDeviceList.size() > 4)
		setAP_PreviewTable(MaterialDeviceList[4], ui.AP_PreviewSerialNumberLineEdit_5, ui.AP_PreviewDeviceNameLineEdit_5,
			ui.AP_PreviewModelSpecificationLineEdit_5, ui.AP_PreviewUnitLineEdit_5, ui.AP_PreviewNumberLineEdit_5,
			ui.AP_PreviewUnitPriceLineEdit_5, ui.AP_PreviewTotalLineEdit_5);
	if (MaterialDeviceList.size() > 5)
		setAP_PreviewTable(MaterialDeviceList[5], ui.AP_PreviewSerialNumberLineEdit_6, ui.AP_PreviewDeviceNameLineEdit_6,
			ui.AP_PreviewModelSpecificationLineEdit_6, ui.AP_PreviewUnitLineEdit_6, ui.AP_PreviewNumberLineEdit_6,
			ui.AP_PreviewUnitPriceLineEdit_6, ui.AP_PreviewTotalLineEdit_6);
}

void UrielQtFramework::setPreviewImage(const QImage & image)
{
	ui.AP_PreviewImageLabel->setScaledContents(false);
	int height, width;

	width = ui.AP_PreviewImageLabel->geometry().width();
	if ((image.width() / (double)image.height() * ui.AP_PreviewImageLabel->geometry().height()) > ui.AP_PreviewImageLabel->geometry().width())
	{
		width = ui.AP_PreviewImageLabel->geometry().width();
		height = image.height() / (double)image.width() * ui.AP_PreviewImageLabel->geometry().width();
	}
	else
	{
		width = image.width() / (double)image.height() * ui.AP_PreviewImageLabel->geometry().height();
		height = ui.AP_PreviewImageLabel->geometry().height();
	}
	ui.AP_PreviewImageLabel->setPixmap(QPixmap::fromImage(image.scaled(width, height)));
}


void UrielQtFramework::onAP_PreviewTBtnClicked() {
	ui.AP_StackedWidget->setCurrentIndex(0);
}
void UrielQtFramework::onAP_ApplyTBtnClicked() {
	ui.AP_StackedWidget->setCurrentIndex(1);
	ui.AP_ApplyApplicantLineEdit->setText(m_pOptions->getAccount());
	ui.AP_ApplyDeclarationDateDateEdit->setDateTime(QDateTime::currentDateTime());
}
void UrielQtFramework::onAP_SearchTBtnClicked() {
	m_bIsMaterialSearchMode = true;
	ui.AP_FunctionFrame->hide();
	ui.AP_SearchFrame->show();
}
void UrielQtFramework::onAP_ReturnTBtnClicked() {
	m_bIsMaterialSearchMode = false;
	ui.AP_SearchFrame->hide();
	ui.AP_FunctionFrame->show();
	initializeApplyUi();
}

void UrielQtFramework::onAP_PreviewAddImageBtnClicked() {
	ui.AP_PreviewImageLabel->setScaledContents(false);
	m_sMaterialPurchaseModifyImagePath = QFileDialog::getOpenFileName(
		this, QStringLiteral("请选择图片"),
		QCoreApplication::applicationDirPath(),
		tr("All Files (*);;PNG File (*.png);;JPG Files (*.jpg);;JPGE Files (*.jpge);;BMP Files (*.bmp)"));
	if (!m_sMaterialPurchaseModifyImagePath.isEmpty())
	{
		setPreviewImage(QImage(m_sMaterialPurchaseModifyImagePath));
	}
}
void UrielQtFramework::onAP_PreviewLookImageBtnClicked() {
	UrielImageViewer imageViewer(this);
	if (!m_sMaterialPurchaseModifyImagePath.isEmpty())
		imageViewer.setImage(QImage(m_sMaterialPurchaseModifyImagePath));
	else
		imageViewer.setImage(m_imgPreviewMaterialImage);
	imageViewer.exec();
}
void UrielQtFramework::onAP_PreviewDeleteImageBtnClicked(){
	ui.AP_PreviewImageLabel->setScaledContents(true);
	ui.AP_PreviewImageLabel->setPixmap(QPixmap(""));
}

void UrielQtFramework::setMaterialPurchaseApplyImage(const QImage & image)
{
	int height, width;

	width = ui.AP_ApplyImageLabel->geometry().width();
	if ((image.width() / (double)image.height() * ui.AP_ApplyImageLabel->geometry().height()) > ui.AP_ApplyImageLabel->geometry().width())
	{
		width = ui.AP_ApplyImageLabel->geometry().width();
		height = image.height() / (double)image.width() * ui.AP_ApplyImageLabel->geometry().width();
	}
	else
	{
		width = image.width() / (double)image.height() * ui.AP_ApplyImageLabel->geometry().height();
		height = ui.AP_ApplyImageLabel->geometry().height();
	}
	ui.AP_ApplyImageLabel->setPixmap(QPixmap::fromImage(image.scaled(width, height)));
}

void UrielQtFramework::onAP_ApplyAddImageBtnClicked() {
	ui.AP_ApplyImageLabel->setScaledContents(false);
	m_sMaterialPurchaseApplyImagePath = QFileDialog::getOpenFileName(
		this, QStringLiteral("请选择图片"),
		QCoreApplication::applicationDirPath(),
		tr("All Files (*);;PNG File (*.png);;JPG Files (*.jpg);;JPGE Files (*.jpge);;BMP Files (*.bmp)"));
	if (!m_sMaterialPurchaseApplyImagePath.isEmpty())
	{
		setMaterialPurchaseApplyImage(QImage(m_sMaterialPurchaseApplyImagePath));
	}
}
void UrielQtFramework::onAP_ApplyLookImageBtnClicked() {
	UrielImageViewer imageViewer(this);
	if (!m_sMaterialPurchaseApplyImagePath.isEmpty())
		imageViewer.setImage(QImage(m_sMaterialPurchaseApplyImagePath));
	imageViewer.exec();
}
void UrielQtFramework::onAP_ApplyDeleteImageBtnClicked() {
	ui.AP_ApplyImageLabel->setScaledContents(true);
	ui.AP_ApplyImageLabel->setPixmap(QPixmap(""));
}

void UrielQtFramework::onAP_ApplyConfirmBtnClicked() {
	QList<sUrielMaterialDeviceItem> MaterialDeviceList;
	sUrielMaterialPurchaseApplyItem MaterialPurchaseApplyItem;
	MaterialPurchaseApplyItem.m_sApplicant = ui.AP_ApplyApplicantLineEdit->text();
	MaterialPurchaseApplyItem.m_tDeclarationDate = ui.AP_ApplyDeclarationDateDateEdit->dateTime();
	int lastCodeId= m_pDatabase->getLastMaterialPurchaseApplyCodeID();
	MaterialPurchaseApplyItem.m_sApplicationNumber=QDateTime::currentDateTime().toString("yyyy-MM-dd") + "_" + QString("%1").arg(lastCodeId + 1, 3, 10, QLatin1Char('0'));
	MaterialPurchaseApplyItem.m_sTotalAmount = ui.AP_ApplyTotalAmountLineEdit->text();
	MaterialPurchaseApplyItem.m_sRequisitionReasons = ui.AP_ApplyRequisitionReasonsPlainTextEdit->toPlainText();
	//MaterialPurchaseApplyItem.m_sAuditOpinion = ui.AP_ApplyAuditOpinionPlainTextEdit->toPlainText();
	//MaterialPurchaseApplyItem.m_sReviewer = "";
	//MaterialPurchaseApplyItem.m_tReviewTime = "";
	MaterialPurchaseApplyItem.m_sLinkAddress = ui.AP_ApplyLinkAddressLineEdit->text();
	m_pUrielFtp->mkdir(m_pUrielFtp->getRootPath() + "/MaterialPurchaseApply/" +m_pOptions->getAccount()+"/"+ MaterialPurchaseApplyItem.m_sApplicationNumber);
	if (!m_sMaterialPurchaseApplyImagePath.isEmpty()) {
		ProgressDialog *progressDialog = new ProgressDialog(this);
		progressDialog->setTotalProgressBarMax(1/*(ui.RP_FileListTreeWidget->currentItem()->text(3).split("K")[0].toInt() * 1024)*/);
		QObject::connect(m_pUrielFtp, static_cast<void (UrielFtp::*)(qint64 readBytes, qint64 totalBytes)>(&UrielFtp::updateDataTransferProgressSignal), \
			progressDialog, &ProgressDialog::updateProgressBarValue);
		progressDialog->setTotalProgressBarMax(1);
		m_pUrielFtp->uploadFile(m_sMaterialPurchaseApplyImagePath, m_pUrielFtp->getRootPath() \
			+ "/MaterialPurchaseApply/" + m_pOptions->getAccount() + "/" + MaterialPurchaseApplyItem.m_sApplicationNumber);
		progressDialog->exec();
		QEventLoop eventloop;
		QTimer::singleShot(50, &eventloop, SLOT(quit()));
		eventloop.exec();
	
	MaterialPurchaseApplyItem.m_sImagePath = m_pUrielFtp->getRootPath() \
		+ "/MaterialPurchaseApply/" + m_pOptions->getAccount() + "/" + MaterialPurchaseApplyItem.m_sApplicationNumber + "/" +QFileInfo(m_sMaterialPurchaseApplyImagePath).fileName();
	}
	else {
		MaterialPurchaseApplyItem.m_sImagePath = "";
	}
	if (!ui.AP_ApplySerialNumberLineEdit_1->text().isEmpty()) {
		sUrielMaterialDeviceItem item;
		item.m_sApplicationNumber = MaterialPurchaseApplyItem.m_sApplicationNumber;
		item.m_sSerialNumber = ui.AP_ApplySerialNumberLineEdit_1->text();
		item.m_sMaterialName = ui.AP_ApplyDeviceNameLineEdit_1->text();
		item.m_sModelSpecification = ui.AP_PreviewModelSpecificationLineEdit_1->text();
		item.m_sUnit = ui.AP_ApplyUnitLineEdit_1->text();
		item.m_sQuantity = ui.AP_ApplyNumberLineEdit_1->text();
		item.m_sUnitPrice = ui.AP_ApplyUnitPriceLineEdit_1->text();
		item.m_sTotal = ui.AP_ApplyTotalLineEdit_1->text();
		MaterialDeviceList.append(item);
	}
	if (!ui.AP_ApplySerialNumberLineEdit_2->text().isEmpty()) {
		sUrielMaterialDeviceItem item;
		item.m_sApplicationNumber = MaterialPurchaseApplyItem.m_sApplicationNumber;
		item.m_sSerialNumber = ui.AP_ApplySerialNumberLineEdit_2->text();
		item.m_sMaterialName = ui.AP_ApplyDeviceNameLineEdit_2->text();
		item.m_sModelSpecification = ui.AP_ApplyModelSpecificationLineEdit_2->text();
		item.m_sUnit = ui.AP_ApplyUnitLineEdit_2->text();
		item.m_sQuantity = ui.AP_ApplyNumberLineEdit_2->text();
		item.m_sUnitPrice = ui.AP_ApplyUnitPriceLineEdit_2->text();
		item.m_sTotal = ui.AP_ApplyTotalLineEdit_2->text();
		MaterialDeviceList.append(item);
	}
	if (!ui.AP_ApplySerialNumberLineEdit_3->text().isEmpty()) {
		sUrielMaterialDeviceItem item;
		item.m_sApplicationNumber = MaterialPurchaseApplyItem.m_sApplicationNumber;
		item.m_sSerialNumber = ui.AP_ApplySerialNumberLineEdit_3->text();
		item.m_sMaterialName = ui.AP_ApplyDeviceNameLineEdit_3->text();
		item.m_sModelSpecification = ui.AP_ApplyModelSpecificationLineEdit_3->text();
		item.m_sUnit = ui.AP_ApplyUnitLineEdit_3->text();
		item.m_sQuantity = ui.AP_ApplyNumberLineEdit_3->text();
		item.m_sUnitPrice = ui.AP_ApplyUnitPriceLineEdit_3->text();
		item.m_sTotal = ui.AP_ApplyTotalLineEdit_3->text();
		MaterialDeviceList.append(item);
	}
	if (!ui.AP_ApplySerialNumberLineEdit_4->text().isEmpty()) {
		sUrielMaterialDeviceItem item;
		item.m_sApplicationNumber = MaterialPurchaseApplyItem.m_sApplicationNumber;
		item.m_sSerialNumber = ui.AP_ApplySerialNumberLineEdit_4->text();
		item.m_sMaterialName = ui.AP_ApplyDeviceNameLineEdit_4->text();
		item.m_sModelSpecification = ui.AP_ApplyModelSpecificationLineEdit_4->text();
		item.m_sUnit = ui.AP_ApplyUnitLineEdit_4->text();
		item.m_sQuantity = ui.AP_ApplyNumberLineEdit_4->text();
		item.m_sUnitPrice = ui.AP_ApplyUnitPriceLineEdit_4->text();
		item.m_sTotal = ui.AP_ApplyTotalLineEdit_4->text();
		MaterialDeviceList.append(item);
	}
	if (!ui.AP_ApplySerialNumberLineEdit_5->text().isEmpty()) {
		sUrielMaterialDeviceItem item;
		item.m_sApplicationNumber = MaterialPurchaseApplyItem.m_sApplicationNumber;
		item.m_sSerialNumber = ui.AP_ApplySerialNumberLineEdit_5->text();
		item.m_sMaterialName = ui.AP_ApplyDeviceNameLineEdit_5->text();
		item.m_sModelSpecification = ui.AP_ApplyModelSpecificationLineEdit_5->text();
		item.m_sUnit = ui.AP_ApplyUnitLineEdit_5->text();
		item.m_sQuantity = ui.AP_ApplyNumberLineEdit_5->text();
		item.m_sUnitPrice = ui.AP_ApplyUnitPriceLineEdit_5->text();
		item.m_sTotal = ui.AP_ApplyTotalLineEdit_5->text();
		MaterialDeviceList.append(item);
	}
	if (!ui.AP_ApplySerialNumberLineEdit_6->text().isEmpty()) {
		sUrielMaterialDeviceItem item;
		item.m_sApplicationNumber = MaterialPurchaseApplyItem.m_sApplicationNumber;
		item.m_sSerialNumber = ui.AP_ApplySerialNumberLineEdit_6->text();
		item.m_sMaterialName = ui.AP_ApplyDeviceNameLineEdit_6->text();
		item.m_sModelSpecification = ui.AP_ApplyModelSpecificationLineEdit_6->text();
		item.m_sUnit = ui.AP_ApplyUnitLineEdit_6->text();
		item.m_sQuantity = ui.AP_ApplyNumberLineEdit_6->text();
		item.m_sUnitPrice = ui.AP_ApplyUnitPriceLineEdit_6->text();
		item.m_sTotal = ui.AP_ApplyTotalLineEdit_6->text();
		MaterialDeviceList.append(item);
	}
	m_pDatabase->insertMaterialDeviceApply(MaterialPurchaseApplyItem);
	for each (sUrielMaterialDeviceItem item in MaterialDeviceList)
	{
		m_pDatabase->insertMaterialDevice(item);
	}
	double t1 = ui.AP_ApplyTotalLineEdit_1->text().isEmpty() ? 0.0 : ui.AP_ApplyTotalLineEdit_1->text().toDouble();
	double t2 = ui.AP_ApplyTotalLineEdit_2->text().isEmpty() ? 0.0 : ui.AP_ApplyTotalLineEdit_2->text().toDouble();
	double t3 = ui.AP_ApplyTotalLineEdit_3->text().isEmpty() ? 0.0 : ui.AP_ApplyTotalLineEdit_3->text().toDouble();
	double t4 = ui.AP_ApplyTotalLineEdit_4->text().isEmpty() ? 0.0 : ui.AP_ApplyTotalLineEdit_4->text().toDouble();
	double t5 = ui.AP_ApplyTotalLineEdit_5->text().isEmpty() ? 0.0 : ui.AP_ApplyTotalLineEdit_5->text().toDouble();
	double t6 = ui.AP_ApplyTotalLineEdit_6->text().isEmpty() ? 0.0 : ui.AP_ApplyTotalLineEdit_6->text().toDouble();

	QStringList EmailList, NameList;
	if ((t1 + t2 + t3 + t4 + t5 + t6) > 1000) {
		m_pDatabase->getAllAuditor(EmailList, NameList, "UltimateAudit");
	}
	else if ((t1 + t2 + t3 + t4 + t5 + t6) > 200) {
		m_pDatabase->getAllAuditor(EmailList, NameList, "RoutineAudit");
	}

	if (EmailList.count()) {
		sSMTPEmailItem EmailItem;
		for (int i = 0; i<EmailList.size(); ++i)
		{
			EmailItem.recipient.insert(EmailList[i], NameList[i]);
		}
		EmailItem.subjectName = QStringLiteral("From:浙江大学精密微纳测量实验室管理系统-材料购买申请审核");
		EmailItem.text = QStringLiteral("申请人：%0\n总金额：%1\n申购理由：%2\n申请时间：%3\n   系统邮件，无需回复！请在系统上审核！")
			.arg(m_pOptions->getAccount())
			.arg(MaterialPurchaseApplyItem.m_sTotalAmount)
			.arg(MaterialPurchaseApplyItem.m_sRequisitionReasons)
			.arg(QDateTime::currentDateTime().toString("yyyy-MM-dd"));
		//QStringList fileNameList = m_sLoaclFilePaths.split(";");
		//for each (QString var in fileNameList) {
		//	EmailItem.attachment.insert(var, "");
		//}
		UrielSMTPEmail * EMail = UrielSMTPEmail::getInstance();
		int code = EMail->sendEmail(m_pDatabase, EmailItem);
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
	InformationDialog information(QStringLiteral("信息"), QStringLiteral("申请提交成功"), this);
	information.exec();
	initializeApplyUi();
}


#pragma endregion

#pragma region CheckIn
void UrielQtFramework::initializeCheckInUi()
{
	ui.CP_CheckInTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.CP_CheckInTableView->setSortingEnabled(true);
	ui.CP_CheckInTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	//ui.CP_CheckInTableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
	ui.CP_CheckInTableView->setShowGrid(false);
	ui.CP_CheckInTableView->horizontalHeader()->setVisible(true);
	ui.CP_CheckInTableView->verticalHeader()->setVisible(false);
	ui.CP_CheckInTableView->setAlternatingRowColors(true);
	ui.CP_CheckInTableView->setMouseTracking(true);
	ui.CP_CheckInTableView->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.CP_CheckInTableView->setContextMenuPolicy(Qt::ActionsContextMenu);
	ui.CP_CheckInTableView->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
	QAction *CheckInEventEditAction = new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/edits.png"), QStringLiteral("编辑"), this);
	QAction *CheckInEventDeleteAction = new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/delete.png"), QStringLiteral("删除"), this);
	QObject::connect(CheckInEventEditAction, &QAction::triggered, this, &UrielQtFramework::onCheckInEventEditActionTriggered);
	QObject::connect(CheckInEventDeleteAction, &QAction::triggered, this, &UrielQtFramework::onCheckInEventDeleteActionTriggered);
	ui.CP_CheckInTableView->addAction(CheckInEventEditAction);
	ui.CP_CheckInTableView->addAction(CheckInEventDeleteAction);
	//ID, Type, ApplyPerson, EventName, Descripation, ApplyTime, StartTime, EndTime, AuditState, Auditor, AuditorSuggest, AuditeTime
	m_pUrielCheckInTableModel = m_pDatabase->creatCheckInTableModel();
	m_pUrielCheckInTableSortFilterModel = new QSortFilterProxyModel;
	m_pUrielCheckInTableSortFilterModel->setDynamicSortFilter(true);
	m_pUrielCheckInTableSortFilterModel->setSourceModel(m_pUrielCheckInTableModel);
	ui.CP_CheckInTableView->setModel(m_pUrielCheckInTableSortFilterModel);
	ui.CP_CheckInTableView->setColumnHidden(0, true);
	ui.CP_CheckInTableView->setColumnHidden(4, true);
	ui.CP_CheckInTableView->setColumnHidden(5, true);
	ui.CP_CheckInTableView->setColumnHidden(6, true);
	ui.CP_CheckInTableView->setColumnHidden(7, true);
	ui.CP_CheckInTableView->setColumnHidden(9, true);
	ui.CP_CheckInTableView->setColumnHidden(10, true);
	ui.CP_CheckInTableView->setColumnHidden(11, true);
	QObject::connect(ui.CP_CheckInTableView, static_cast<void (QTableView::*)(const QModelIndex &)>(&QTableView::pressed), this, &UrielQtFramework::onCheckInTableViewPressed);
	QList<int> wdls;
	wdls << 0 << 30 << 80 << 100 << 0 << 0 << 0 << 0 << 30 <<0 << 0 << 0;
	for (int i = 0; i < wdls.size(); i++)
	{
		ui.CP_CheckInTableView->setColumnWidth(i, wdls[i]);
	}

	ui.CP_CalendarWidget->setSelectedDate(QDate::currentDate());
	onCP_CalendarWidgetClicked(QDate::currentDate());
	ui.CP_EventTypeCombox->addItem(QStringLiteral("节假日"));
	ui.CP_EventTypeCombox->addItem(QStringLiteral("其他"));
	ui.CP_EventTypeCombox->setCurrentIndex(-1);
	ui.CP_StartLeaveTime->setDateTime(QDateTime::currentDateTime());
	ui.CP_EndLeaveTime->setDateTime(QDateTime::currentDateTime());
	ui.CP_LeaveStaff->setText(m_pOptions->getAccount());
}

void UrielQtFramework::setCheckInSignalsAndSlots()
{
	QObject::connect(ui.CP_CalendarWidget, static_cast<void (QCalendarWidget::*)(const QDate &)>(&QCalendarWidget::clicked), this, &UrielQtFramework::onCP_CalendarWidgetClicked);
	QObject::connect(ui.CP_AddEventTBtn,&QToolButton::clicked, this, &UrielQtFramework::onCP_AddEventTBtnClicked);
	QObject::connect(ui.CP_LeaveConfirmApply, &QToolButton::clicked, this, &UrielQtFramework::onCP_LeaveConfirmApplyClicked);
	QObject::connect(ui.CP_EndLeaveTime, static_cast<void (QDateTimeEdit::*)(const QDateTime &)>(&QDateTimeEdit::dateTimeChanged),this, &UrielQtFramework::onCP_EndLeaveTimeChanged);
}

void UrielQtFramework::onCheckInEventEditActionTriggered()
{
	QModelIndex index = ui.CP_CheckInTableView->currentIndex();
	if (index.isValid())
	{
		int mIndex = index.row();
		QModelIndex idx = index.sibling(mIndex, 1);
		if (idx.isValid())
		{
			if (idx.data().toString() == QStringLiteral("Group"))
			{
				ui.CP_AddEventTBtn->setIcon(QIcon(":/Mainwindow/Resources/UrielQtFramework/edits.png"));
				ui.CP_AddEventTBtn->setToolTip(QStringLiteral("编辑模式"));
				ui.CP_LeaveStaff->setText("");
				ui.CP_EventTypeCombox->setCurrentText(index.sibling(mIndex, 3).data().toString());
				ui.CP_EventDetailDescription->setPlainText(index.sibling(mIndex, 4).data().toString());
				ui.CP_LeaveOfOther->setChecked(true);
				ui.CP_LeaveDescription->setPlainText("");
				ui.TotleTime->setText(QStringLiteral("xx天xx小时"));
				ui.AuditState->setText("");
				ui.Auditor->setText("");
				ui.AuditorSuggest->setText("");
			}
			else
			{
				ui.CP_LeaveConfirmApply->setIcon(QIcon(":/Mainwindow/Resources/UrielQtFramework/edits.png"));
				ui.CP_LeaveConfirmApply->setText(QStringLiteral("修改"));
				ui.CP_LeaveConfirmApply->setToolTip(QStringLiteral("编辑模式"));
				ui.CP_EventTypeCombox->setCurrentIndex(-1);
				ui.CP_EventDetailDescription->setPlainText("");
				ui.CP_LeaveStaff->setText(index.sibling(mIndex, 2).data().toString());
				const QString sEventName = index.sibling(mIndex, 3).data().toString();
				if (sEventName == QStringLiteral("事假")) ui.CP_LeaveOfAbsence->setChecked(true);
				else if (sEventName == QStringLiteral("病假")) ui.CP_LeaveOfSick->setChecked(true);
				else if (sEventName == QStringLiteral("出差")) ui.CP_LeaveOfBusiness->setChecked(true);
				else ui.CP_LeaveOfOther->setChecked(true);
				ui.CP_LeaveDescription->setPlainText(index.sibling(mIndex, 4).data().toString());

				QDateTime startTime = index.sibling(mIndex, 6).data().toDateTime();
				QDateTime endTime = index.sibling(mIndex, 7).data().toDateTime();
				ui.CP_StartLeaveTime->setDateTime(startTime);
				ui.CP_EndLeaveTime->setDateTime(endTime);
				qint64 sec = startTime.secsTo(endTime);
				qint64 dataCount = sec / (24 * 60 * 60);
				qint64 hourCount = (sec % (24 * 3600)) / 3600;
				ui.TotleTime->setText(QString::number(dataCount) + QStringLiteral("天") + QString::number(hourCount) + QStringLiteral("小时"));
				QString sCurrentState = index.sibling(mIndex, 8).data().toString();
				if (sCurrentState == "Audited") ui.AuditState->setText(QStringLiteral("审核通过"));
				else if (sCurrentState == "AuditNotThrough") ui.AuditState->setText(QStringLiteral("审核不通过"));
				else ui.AuditState->setText(QStringLiteral("尚未审核"));
				ui.Auditor->setText(index.sibling(mIndex, 9).data().toString());
				ui.AuditorSuggest->setText(index.sibling(mIndex, 10).data().toString());
			}
		}
	}
}

void UrielQtFramework::onCheckInEventDeleteActionTriggered()
{
	QModelIndex index = ui.CP_CheckInTableView->currentIndex();
	if (index.isValid())
	{
		QModelIndex idx = index.sibling(index.row(), 2);
		if (idx.isValid())
		{
			if (idx.data().toString() != m_pOptions->getAccount()) {
				CriticalDialog critical(QStringLiteral("错误"), QStringLiteral("非本人操作，无法删除！"), this);
				critical.exec();
				return;
			}
		}
		idx = index.sibling(index.row(), 0);
		if (idx.isValid()) {
			InformationDialog information(QStringLiteral("信息"), QStringLiteral("申请提交成功"), this);
			if(information.exec()==QDialog::Accepted)
			    m_pDatabase->deleteEventFromCheckInByID(idx.data().toString());
		}
			
	}

	onCP_CalendarWidgetClicked(QDate::currentDate());
}
void UrielQtFramework::onCheckInTableViewPressed(const QModelIndex & index)
{
	if (index.isValid())
	{
		int mIndex = index.row();
		QModelIndex idx = index.sibling(mIndex, 1);
		if (idx.isValid())
		{
			if (idx.data().toString() == QStringLiteral("Group"))
			{
				ui.CP_LeaveStaff->setText("");
				ui.CP_EventTypeCombox->setCurrentText(index.sibling(mIndex, 3).data().toString());
				ui.CP_EventDetailDescription->setPlainText(index.sibling(mIndex, 4).data().toString());
				ui.CP_LeaveOfOther->setChecked(true);
				ui.CP_LeaveDescription->setPlainText("");
				ui.TotleTime->setText( QStringLiteral("xx天xx小时") );
				ui.AuditState->setText("");
				ui.Auditor->setText("");
				ui.AuditorSuggest->setText("");
			}
			else
			{
				ui.CP_EventTypeCombox->setCurrentIndex(-1);
				ui.CP_EventDetailDescription->setPlainText("");
				ui.CP_LeaveStaff->setText(index.sibling(mIndex, 2).data().toString());
				const QString sEventName=index.sibling(mIndex, 3).data().toString();
				if (sEventName == QStringLiteral("事假")) ui.CP_LeaveOfAbsence->setChecked(true);
				else if (sEventName == QStringLiteral("病假")) ui.CP_LeaveOfSick->setChecked(true);
				else if (sEventName == QStringLiteral("出差")) ui.CP_LeaveOfBusiness->setChecked(true);
				else ui.CP_LeaveOfOther->setChecked(true);
				ui.CP_LeaveDescription->setPlainText(index.sibling(mIndex, 4).data().toString());
				
				QDateTime startTime= index.sibling(mIndex, 6).data().toDateTime();
				QDateTime endTime = index.sibling(mIndex, 7).data().toDateTime();
				ui.CP_StartLeaveTime->setDateTime(startTime);
				ui.CP_EndLeaveTime->setDateTime(endTime);
				qint64 sec=startTime.secsTo(endTime);
				qint64 dataCount=sec / (24 * 60 * 60);
				qint64 hourCount = (sec % (24 * 3600))/3600;
				ui.TotleTime->setText(QString::number(dataCount)+ QStringLiteral("天")+ QString::number(hourCount) + QStringLiteral("小时"));
				QString sCurrentState = index.sibling(mIndex, 8).data().toString();
				if(sCurrentState=="Audited") ui.AuditState->setText(QStringLiteral("审核通过"));
				else if (sCurrentState == "AuditNotThrough") ui.AuditState->setText(QStringLiteral("审核不通过"));
				else ui.AuditState->setText(QStringLiteral("尚未审核"));
				ui.Auditor->setText(index.sibling(mIndex, 9).data().toString());
				ui.AuditorSuggest->setText(index.sibling(mIndex, 10).data().toString());
			}
		}
			
	}
}

void UrielQtFramework::onCP_CalendarWidgetClicked(const QDate & date)
{
	ui.CP_DayLabel->setText(QString::number(date.day()));
	ui.CP_UDayLabel->setText(date.longDayName(date.dayOfWeek()));
	ui.CP_MonthYearLabel->setText(date.longMonthName(date.month())+" "+ QString::number(date.year()));
	ui.CP_DayLabel_2->setText(QString::number(date.day()));
	ui.CP_UDayLabel_2->setText(date.longDayName(date.dayOfWeek()));
	ui.CP_MonthYearLabel_2->setText(date.longMonthName(date.month()) + " " + QString::number(date.year()));
	QString sSQL = " WHERE StartTime <='" + date.toString("yyyy-MM-dd")+" 23:59:59" + "' AND EndTime>= '" + date.toString("yyyy-MM-dd") + " 00:00:00'";
	m_pDatabase->updateCheckInTableModel(sSQL);
}

void UrielQtFramework::onCP_AddEventTBtnClicked()
{
	sUrielVacationLeaveItem item;
	QModelIndex index = ui.CP_CheckInTableView->currentIndex();
	if (index.isValid())
	{
		int mIndex = index.row();
		QModelIndex idx = index.sibling(mIndex, 0);
		if (idx.isValid())
		{
			item.m_sId = idx.data().toString();
		}
	}
	item.m_sType = QStringLiteral("Group");
	item.m_sApplyPerson = m_pOptions->getAccount();
	item.m_sEventName = ui.CP_EventTypeCombox->currentText();
	item.m_sDescripation = ui.CP_EventDetailDescription->toPlainText();
	item.m_tApplyTime = QDateTime::currentDateTime();
	item.m_tStartTime = QDateTime::fromString(ui.CP_CalendarWidget->selectedDate().toString("yyyy-MM-dd")+" 00:00:00","yyyy-MM-dd hh:mm:ss");
	item.m_tEndTime = QDateTime::fromString(ui.CP_CalendarWidget->selectedDate().toString("yyyy-MM-dd") + " 23:59:59", "yyyy-MM-dd hh:mm:ss");
	item.m_sAuditState = QStringLiteral("Audited");
	item.m_sAuditor = QStringLiteral("Uriel");
	item.m_sAuditorSuggest = QStringLiteral("同意");
	item.m_tAuditTime = QDateTime::currentDateTime();
	if (ui.CP_AddEventTBtn->toolTip() == QStringLiteral("编辑模式"))
	{
		if (m_pDatabase->updateVacationLeaveEvent(item))
		{
			InformationDialog information(QStringLiteral("信息"), QStringLiteral("修改成功！"), this);
			information.exec();
		}
		else
		{
			InformationDialog information(QStringLiteral("信息"), QStringLiteral("修改失败，请联系数据库管理员解决问题！"), this);
			information.exec();
			ui.CP_AddEventTBtn->setToolTip(QStringLiteral("插入模式"));
			ui.CP_AddEventTBtn->setIcon(QIcon(":/CheckingIn/Resources/CheckingIn/addevent.png"));
			return;
		}
			
	}
	else
	{
		if (m_pDatabase->insertVacationLeaveEvent(item))
		{
			InformationDialog information(QStringLiteral("信息"), QStringLiteral("添加成功！"), this);
			information.exec();
		}
		else
		{
			InformationDialog information(QStringLiteral("信息"), QStringLiteral("添加失败，请联系数据库管理员解决问题！"), this);
			information.exec();
			
			return;
		}
	}
	ui.CP_AddEventTBtn->setToolTip(QStringLiteral("插入模式"));
	ui.CP_AddEventTBtn->setIcon(QIcon(":/CheckingIn/Resources/CheckingIn/addevent.png"));
	ui.CP_CalendarWidget->setSelectedDate(QDate::currentDate());
}

void UrielQtFramework::onCP_LeaveConfirmApplyClicked()
{
	
	sUrielVacationLeaveItem item;
	item.m_sType = QStringLiteral("Personal");
	item.m_sApplyPerson = m_pOptions->getAccount();
	//item.m_sApplyPerson = ui.CP_LeaveStaff->text();
	if (ui.CP_LeaveOfAbsence->isChecked()) item.m_sEventName = QStringLiteral("事假");
	else if (ui.CP_LeaveOfSick->isChecked()) item.m_sEventName = QStringLiteral("病假");
	else if (ui.CP_LeaveOfBusiness->isChecked()) item.m_sEventName = QStringLiteral("出差");
	else item.m_sEventName = QStringLiteral("其他");
	item.m_sDescripation = ui.CP_LeaveDescription->toPlainText();
	item.m_tApplyTime = QDateTime::currentDateTime();
	item.m_tStartTime = ui.CP_StartLeaveTime->dateTime();
	item.m_tEndTime = ui.CP_EndLeaveTime->dateTime();
	item.m_sAuditState = QStringLiteral("AuditNotThrough");
	item.m_sAuditor = QStringLiteral("");
	item.m_sAuditorSuggest = QStringLiteral("");
	item.m_tAuditTime = QDateTime::currentDateTime();
	if (ui.CP_LeaveConfirmApply->toolTip() == QStringLiteral("编辑模式"))
	{
		if (m_pDatabase->updateVacationLeaveEvent(item))
		{
			QStringList EmailList, NameList;
			m_pDatabase->getAllAuditor(EmailList, NameList, "RoutineAudit");

			if (EmailList.count()) {
				sSMTPEmailItem EmailItem;
				for (int i = 0; i<EmailList.size(); ++i)
				{
					EmailItem.recipient.insert(EmailList[i], NameList[i]);
				}
				EmailItem.subjectName = QStringLiteral("From:浙江大学精密微纳测量实验室管理系统-请假事件申请审核(修改)");
				EmailItem.text = QStringLiteral("申请人：%0\n请假时间：%1\n请假理由：%2\n   系统邮件，无需回复！请在系统上审核！")
					.arg(m_pOptions->getAccount())
					.arg(item.m_tStartTime.toString("yyyy-MM-dd hh:mm:ss") + "~" + item.m_tEndTime.toString("yyyy-MM-dd hh:mm:ss"))
					.arg(item.m_sDescripation);
				UrielSMTPEmail * EMail = UrielSMTPEmail::getInstance();
				int code = EMail->sendEmail(m_pDatabase, EmailItem);
				if (code == -1) {
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
			InformationDialog information(QStringLiteral("信息"), QStringLiteral("修改成功！"), this);
			information.exec();
		}
		else
		{
			InformationDialog information(QStringLiteral("信息"), QStringLiteral("修改失败，请联系数据库管理员解决问题！"), this);
			information.exec();
			ui.CP_LeaveConfirmApply->setToolTip(QStringLiteral("插入模式"));
			ui.CP_LeaveConfirmApply->setText(QStringLiteral("申请"));
			ui.CP_LeaveConfirmApply->setIcon(QIcon(":/CheckingIn/Resources/CheckingIn/apply.png"));
			return;
		}
	}
	else
	{
		if (!m_pDatabase->insertVacationLeaveEvent(item))
		{
			CriticalDialog critical(QStringLiteral("错误"), QStringLiteral("申请失败，请联系数据库管理员解决问题！"), this);
			critical.exec();
			return;
		}
		else
		{
			QStringList EmailList, NameList;
			m_pDatabase->getAllAuditor(EmailList, NameList, "RoutineAudit");

			if (EmailList.count()) {
				sSMTPEmailItem EmailItem;
				for (int i = 0; i<EmailList.size(); ++i)
				{
					EmailItem.recipient.insert(EmailList[i], NameList[i]);
				}
				EmailItem.subjectName = QStringLiteral("From:浙江大学精密微纳测量实验室管理系统-请假事件申请审核");
				EmailItem.text = QStringLiteral("申请人：%0\n请假时间：%1\n请假理由：%2\n   系统邮件，无需回复！请在系统上审核！")
					.arg(m_pOptions->getAccount())
					.arg(item.m_tStartTime.toString("yyyy-MM-dd hh:mm:ss") + "~" + item.m_tEndTime.toString("yyyy-MM-dd hh:mm:ss"))
					.arg(item.m_sDescripation);
				UrielSMTPEmail * EMail = UrielSMTPEmail::getInstance();
				int code = EMail->sendEmail(m_pDatabase, EmailItem);
				if (code == -1) {
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

			InformationDialog information(QStringLiteral("信息"), QStringLiteral("确定申请！"), this);
			information.exec();
		}
	}

	ui.CP_LeaveConfirmApply->setToolTip(QStringLiteral("插入模式"));
	ui.CP_LeaveConfirmApply->setText(QStringLiteral("申请"));
	ui.CP_LeaveConfirmApply->setIcon(QIcon(":/CheckingIn/Resources/CheckingIn/apply.png"));
	ui.CP_CalendarWidget->setSelectedDate(QDate::currentDate());
}

void UrielQtFramework::onCP_EndLeaveTimeChanged(const QDateTime &dateTime)
{
	QDateTime startTime = ui.CP_StartLeaveTime->dateTime();
	qint64 sec = startTime.secsTo(dateTime);
	qint64 dataCount = sec / (24 * 60 * 60);
	qint64 hourCount = (sec % (24 * 3600)) / 3600;
	ui.TotleTime->setText(QString::number(dataCount) + QStringLiteral("天") + QString::number(hourCount) + QStringLiteral("小时"));
}
#pragma endregion

#pragma region Resources
void UrielQtFramework::initializeMeetingReportUi() {
	ui.RP_ReportTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.RP_ReportTableView->setSortingEnabled(true);
	ui.RP_ReportTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.RP_ReportTableView->setShowGrid(false);
	ui.RP_ReportTableView->verticalHeader()->setVisible(false);
	ui.RP_ReportTableView->setAlternatingRowColors(true);
	ui.RP_ReportTableView->setMouseTracking(true);
	ui.RP_ReportTableView->setSelectionMode(QAbstractItemView::ContiguousSelection);//设置为连续选择模式
	ui.RP_ReportTableView->setContextMenuPolicy(Qt::ActionsContextMenu);//设置为action菜单模式


	//QAction * MeetingReportUploadAction = new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/uploader.png"), QStringLiteral("上传"), this);
	QAction * MeetingReportDownloadAction = new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/download01.png"), QStringLiteral("下载"), this);
	QAction * MeetingReportDeleteAction = new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/delete.png"), QStringLiteral("删除"), this);

	//ui.RP_ReportTableView->addAction(MeetingReportUploadAction);
	ui.RP_ReportTableView->addAction(MeetingReportDownloadAction);
	ui.RP_ReportTableView->addAction(MeetingReportDeleteAction);

	//connect(MeetingReportUploadAction, &QAction::triggered, this, &UrielQtFramework::onMeetingReportUploadActionTriggered);
	connect(MeetingReportDownloadAction, &QAction::triggered, this, &UrielQtFramework::onMeetingReportDownloadActionTriggered);
	connect(MeetingReportDeleteAction, &QAction::triggered, this, &UrielQtFramework::onMeetingReportDeleteActionTriggered);

	connect(ui.RP_ReportTableView, static_cast<void (QTableView::*)(const QModelIndex &)>(&QTableView::doubleClicked), this, &UrielQtFramework::onRP_ReportTableViewDoubleClicked);



	m_UrielMeetingReportTableModel = m_pDatabase->creatMeetingReportTableModel();
	m_pUrielMeetingReportTableSortFilterModel = new QSortFilterProxyModel;
	m_pUrielMeetingReportTableSortFilterModel->setDynamicSortFilter(true);
	m_pUrielMeetingReportTableSortFilterModel->setSourceModel(m_UrielMeetingReportTableModel);
	ui.RP_ReportTableView->setModel(m_pUrielMeetingReportTableSortFilterModel);
	QList<int> wdls;
	wdls << 60 << 120 << 500 << 150 << 100;
	for (int i = 0; i < wdls.size(); i++)
	{
		ui.RP_ReportTableView->setColumnWidth(i, wdls[i]);
	}

	m_pDatabase->updateMeetingReportTableModel();

	ui.RP_UploadTimerComboBox->addItem(QIcon(":/Mainwindow/Resources/UrielQtFramework/allTime.png"), QStringLiteral("全部时间"));
	ui.RP_UploadTimerComboBox->addItem(QIcon(":/Mainwindow/Resources/UrielQtFramework/oneDay.png"), QStringLiteral("近一天"));
	ui.RP_UploadTimerComboBox->addItem(QIcon(":/Mainwindow/Resources/UrielQtFramework/ThreeDay.png"), QStringLiteral("近三天"));
	ui.RP_UploadTimerComboBox->addItem(QIcon(":/Mainwindow/Resources/UrielQtFramework/oneWeek.png"), QStringLiteral("近一周"));
	ui.RP_UploadTimerComboBox->addItem(QIcon(":/Mainwindow/Resources/UrielQtFramework/oneMonth.png"), QStringLiteral("近一月"));
	ui.RP_UploadTimerComboBox->addItem(QIcon(":/Mainwindow/Resources/UrielQtFramework/oneYear.png"), QStringLiteral("近一年"));
	ui.RP_UploadTimerComboBox->setCurrentIndex(0);
	QStringList UserList;
	m_pDatabase->getAllUserName(UserList);
	ui.RP_ReporterComboBox->addItem(QIcon(":/Mainwindow/Resources/UrielQtFramework/staff.png"), QStringLiteral("全部人员"));
	for each (QString var in UserList)
		ui.RP_ReporterComboBox->addItem(QIcon(":/Mainwindow/Resources/UrielQtFramework/staff.png"), var);
	ui.RP_ReporterComboBox->setCurrentIndex(0);
}

void UrielQtFramework::onRP_ReportTableViewSignals(QStringList & fileNameList) {
	for each (QString var in fileNameList)
	{
		sUrielMeetingReportItem  MeetingReportItem;
		MeetingReportItem.m_sReporter = m_pOptions->getAccount();
		MeetingReportItem.ReportPath = m_pUrielFtp->getRootPath() + "/MeetingReport/" + m_pOptions->getAccount() + "/" + QFileInfo(var).fileName();
		MeetingReportItem.UploadTime = QDateTime::currentDateTime();
		MeetingReportItem.DownLoadCount = 0;
		ProgressDialog *progressDialog = new ProgressDialog(this);
		progressDialog->setTotalProgressBarMax(1);
		QObject::connect(m_pUrielFtp, static_cast<void (UrielFtp::*)(qint64 readBytes, qint64 totalBytes)>(&UrielFtp::updateDataTransferProgressSignal), \
			progressDialog, &ProgressDialog::updateProgressBarValue);
		progressDialog->setTotalProgressBarMax(1);

		m_pUrielFtp->uploadFile(var, m_pUrielFtp->getRootPath() + "/MeetingReport/" + m_pOptions->getAccount());
		progressDialog->exec();
		QEventLoop eventloop;
		QTimer::singleShot(100, &eventloop, SLOT(quit()));
		eventloop.exec();
		m_pDatabase->insertMeetingReport(MeetingReportItem);
	}
	m_pDatabase->updateMeetingReportTableModel(getRP_MeetingReportFilters());
}

QString UrielQtFramework::getRP_MeetingReportFilters() {
	QString str, strSQL = "";

	str = ui.RP_ReporterComboBox->currentText();

	if (!str.isEmpty()&& str!= QStringLiteral("全部人员"))
	{
		strSQL += " WHERE Reporter like '%" + str + "%'";
	}
	int number = 1;
	str = ui.RP_UploadTimerComboBox->currentText();
	if (str == QStringLiteral("近一天"))
		number = 1;
	else if (str == QStringLiteral("近三天"))
		number = 3;
	else if (str == QStringLiteral("近一周"))
		number = 7;
	else if (str == QStringLiteral("近一月"))
		number = 30;
	else if (str == QStringLiteral("近一年"))
		number = 365;
	if (!str.isEmpty() && str != QStringLiteral("全部时间") && !strSQL.isEmpty())
	{
		strSQL += " AND DATE_SUB(CURDATE(), INTERVAL " + QString::number(number) + " DAY) <= UploadTime";
	}
	else if (!str.isEmpty() && str != QStringLiteral("全部时间") && strSQL.isEmpty())
	{
		strSQL += " WHERE  DATE_SUB(CURDATE(), INTERVAL " + QString::number(number) + " DAY) <= UploadTime";
	}
	return strSQL;
}
void UrielQtFramework::onRP_ReporterComboBoxCurrentIndexChanged(int index) {
	m_pDatabase->updateMeetingReportTableModel(getRP_MeetingReportFilters());
}

void UrielQtFramework::onRP_UploadTimerComboBoxCurrentIndexChanged(int index) {
	m_pDatabase->updateMeetingReportTableModel(getRP_MeetingReportFilters());
}

//cancel function
void UrielQtFramework::onMeetingReportUploadActionTriggered() {
	
}

void UrielQtFramework::onMeetingReportDownloadActionTriggered() {
	QString file_path = QFileDialog::getExistingDirectory(nullptr, QStringLiteral("请选择文件保存路径..."), "./");
	QItemSelectionModel *selections = ui.RP_ReportTableView->selectionModel();
	QModelIndexList selectedIndexs = selections->selectedIndexes();
	for (int i = 0; i < selectedIndexs.size(); i += 5) {
		QModelIndex index = selectedIndexs[i];
		if (index.isValid())
		{
			QModelIndex idx = index.sibling(index.row(), 2);
			if (idx.isValid()) {
				ProgressDialog *progressDialog = new ProgressDialog(this);
				progressDialog->setTotalProgressBarMax(1/*(ui.RP_FileListTreeWidget->currentItem()->text(3).split("K")[0].toInt() * 1024)*/);
				QObject::connect(m_pUrielFtp, static_cast<void (UrielFtp::*)(qint64 readBytes, qint64 totalBytes)>(&UrielFtp::updateDataTransferProgressSignal), \
					progressDialog, &ProgressDialog::updateProgressBarValue);
				progressDialog->setTotalProgressBarMax(1);
				if (m_pUrielFtp->downloadFiles(file_path, m_pUrielFtp->getRootPath() + "/MeetingReport/" + index.sibling(index.row(), 1).data().toString() + "/" + idx.data().toString())) {
					progressDialog->exec();
					QEventLoop eventloop;
					QTimer::singleShot(100, &eventloop, SLOT(quit()));
					eventloop.exec();
					m_pDatabase->updateMeetingReportDownloadCount(index.sibling(index.row(), 0).data().toString());
				}
				else {
					QObject::disconnect(m_pUrielFtp, static_cast<void (UrielFtp::*)(qint64 readBytes, qint64 totalBytes)>(&UrielFtp::updateDataTransferProgressSignal), \
						progressDialog, &ProgressDialog::updateProgressBarValue);
					delete progressDialog;
				}
			}
		}
	}
	m_pDatabase->updateMeetingReportTableModel(getRP_MeetingReportFilters());
}
void UrielQtFramework::onMeetingReportDeleteActionTriggered() {
	InformationDialog information(QStringLiteral("信息"), QStringLiteral("确定删除？"), this);
	if (information.exec() == QDialog::Accepted) {
		QItemSelectionModel *selections = ui.RP_ReportTableView->selectionModel();
		QModelIndexList selectedIndexs = selections->selectedIndexes();
		for (int i = 0; i < selectedIndexs.size(); i += 5) {
			QModelIndex index = selectedIndexs[i];
			if (index.isValid())
			{
				if (index.sibling(index.row(), 1).data().toString() != m_pOptions->getAccount()) {
					CriticalDialog critical(QStringLiteral("错误"), QStringLiteral("非本人操作，无法删除！"), this);
					critical.exec();
					return;
				}
				else {
					QModelIndex idx = index.sibling(index.row(), 0);
					if (idx.isValid()) {

						m_pUrielFtp->Remove(m_pUrielFtp->getRootPath() + "/MeetingReport/" +
							m_pOptions->getAccount() + "/" + index.sibling(index.row(), 2).data().toString());
						m_pDatabase->delectMeetingReport(index.sibling(index.row(), 0).data().toString());
					}
				}
			}
		}
		m_pDatabase->updateMeetingReportTableModel(getRP_MeetingReportFilters());
	}
}

void UrielQtFramework::onRP_ReportTableViewDoubleClicked(const QModelIndex &index) {
	onMeetingReportDownloadActionTriggered();
}


void UrielQtFramework::initializePaperUi() {
	ui.RP_PaperTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.RP_PaperTableView->setSortingEnabled(true);
	ui.RP_PaperTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.RP_PaperTableView->setShowGrid(false);
	ui.RP_PaperTableView->verticalHeader()->setVisible(false);
	ui.RP_PaperTableView->setAlternatingRowColors(true);
	ui.RP_PaperTableView->setMouseTracking(true);
	ui.RP_PaperTableView->setSelectionMode(QAbstractItemView::ContiguousSelection);//设置为连续选择模式
	ui.RP_PaperTableView->setContextMenuPolicy(Qt::ActionsContextMenu);//设置为action菜单模式

	QAction * PaperAddAction = new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/add.png"), QStringLiteral("新增"), this);
	QAction * PaperEditAction = new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/edit.png"), QStringLiteral("编辑"), this);
	QAction * PaperDeleteAction = new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/delete.png"), QStringLiteral("删除"), this);
	QAction * PaperDownLoadAction = new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/download01.png"), QStringLiteral("下载"), this);

	ui.RP_PaperTableView->addAction(PaperAddAction);
	ui.RP_PaperTableView->addAction(PaperEditAction);
	ui.RP_PaperTableView->addAction(PaperDeleteAction);
	ui.RP_PaperTableView->addAction(PaperDownLoadAction);

	connect(PaperAddAction, &QAction::triggered, this, &UrielQtFramework::onPaperAddActionTriggered);
	connect(PaperEditAction, &QAction::triggered, this, &UrielQtFramework::onPaperEditActionTriggered);
	connect(PaperDeleteAction, &QAction::triggered, this, &UrielQtFramework::onPaperDeleteActionTriggered);
	connect(PaperDownLoadAction, &QAction::triggered, this, &UrielQtFramework::onPaperDownLoadActionTriggered);

	connect(ui.RP_PaperTableView, static_cast<void (QTableView::*)(const QModelIndex &)>(&QTableView::doubleClicked), this, &UrielQtFramework::onRP_PaperTableViewDoubleClicked);

	m_UrielPaperTableModel = m_pDatabase->creatPaperTableModel();
	m_pUrielPaperTableSortFilterModel = new QSortFilterProxyModel;
	m_pUrielPaperTableSortFilterModel->setDynamicSortFilter(true);
	m_pUrielPaperTableSortFilterModel->setSourceModel(m_UrielPaperTableModel);
	ui.RP_PaperTableView->setModel(m_pUrielPaperTableSortFilterModel);

	QList<int> wdls;
	wdls << 60 << 200 << 200 << 120 << 60 << 60 << 150 << 60 << 80 << 60 << 60 << 100 << 200 << 200 << 0 << 60 << 150 << 80;
	for (int i = 0; i < wdls.size(); i++)
	{
		ui.RP_PaperTableView->setColumnWidth(i, wdls[i]);
	}

	m_pDatabase->updatePaperTableModel();
	QStringList AuthorList;
	m_pDatabase->getAllPaperAuthorName(AuthorList);
	ui.RP_PaperAuthorCombox->addItem(QIcon(":/Mainwindow/Resources/UrielQtFramework/staff.png"), QStringLiteral("所有作者"));
	for each (QString var in AuthorList)
		ui.RP_PaperAuthorCombox->addItem(QIcon(":/Mainwindow/Resources/UrielQtFramework/staff.png"), var);
	ui.RP_PaperAuthorCombox->setCurrentIndex(0);

	ui.RP_PaperYearCombox->addItem(QIcon(":/Mainwindow/Resources/UrielQtFramework/time.png"), QStringLiteral("全部时间"));
	for(int i= QDateTime::currentDateTime().date().year();i>=2000; i--)
	    ui.RP_PaperYearCombox->addItem(QIcon(":/Mainwindow/Resources/UrielQtFramework/time.png"), QStringLiteral("%0年").arg(i));
	ui.RP_PaperYearCombox->setCurrentIndex(0);
}

void UrielQtFramework::setPaperSignalsAndSlots() {
	QObject::connect(ui.RP_AddPaperTBtn, &QToolButton::clicked, this, &UrielQtFramework::onPaperAddActionTriggered);
	QObject::connect(ui.RP_EditPaperTBtn, &QToolButton::clicked, this, &UrielQtFramework::onPaperEditActionTriggered);
	QObject::connect(ui.RP_DeletePaperTBtn, &QToolButton::clicked, this, &UrielQtFramework::onPaperDeleteActionTriggered);
	QObject::connect(ui.RP_PaperAuthorCombox, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
		this, &UrielQtFramework::onRP_PaperAuthorComboxCurrentIndexChanged);
	QObject::connect(ui.RP_PaperYearCombox, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
		this, &UrielQtFramework::onRP_PaperYearComboxCurrentIndexChanged);
	QObject::connect(ui.RP_PaperTitleLineEdit,&QLineEdit::editingFinished,this, &UrielQtFramework::onRP_PaperTitleLineEditingFinished);
	QObject::connect(ui.RP_PaperSearchPBtn, &QPushButton::clicked, this, &UrielQtFramework::onRP_PaperTitleLineEditingFinished);
}

void UrielQtFramework::onPaperDownLoadActionTriggered() {
	QItemSelectionModel *selections = ui.RP_PaperTableView->selectionModel();
	QModelIndexList selectedIndexs = selections->selectedIndexes();
	QMap <int, int> rowMap;
	QString file_path = QFileDialog::getExistingDirectory(nullptr, QStringLiteral("请选择文件保存路径..."), "./");
	for(int i=0;i<selectedIndexs.size(); i+=18)
	{
		QModelIndex index = selectedIndexs[i];
		sUrielPaperItem item;
		if (index.isValid())
		{
			int mIndex = index.row();
			QModelIndex idx = index.sibling(mIndex, 0);
			if (idx.isValid())
				m_pDatabase->getPaperInfoByID(item, idx.data().toString());
		}
		QStringList fileList = item.ServerFileAddress.split(";");
		if (fileList.count()) {	
			for each (QString var in fileList) {
				ProgressDialog *progressDialog = new ProgressDialog(this);
				QObject::connect(m_pUrielFtp, static_cast<void (UrielFtp::*)(qint64 readBytes, qint64 totalBytes)>(&UrielFtp::updateDataTransferProgressSignal), \
					progressDialog, &ProgressDialog::updateProgressBarValue);
				progressDialog->setTotalProgressBarMax(1);
				if (m_pUrielFtp->downloadFiles(file_path, var)) {
					progressDialog->exec();
					QEventLoop eventloop;
					QTimer::singleShot(100, &eventloop, SLOT(quit()));
					eventloop.exec();
				}
				else {
					QObject::disconnect(m_pUrielFtp, static_cast<void (UrielFtp::*)(qint64 readBytes, qint64 totalBytes)>(&UrielFtp::updateDataTransferProgressSignal), \
						progressDialog, &ProgressDialog::updateProgressBarValue);
					delete progressDialog;
				}
			}
		}
		m_pDatabase->updatePaperDownloadCount(QString::number(item.ID));
	}
	m_pDatabase->updatePaperTableModel(getRP_PaperFilters());
}

void UrielQtFramework::onPaperAddActionTriggered() {
	PaperInfo dlg(m_pDatabase,m_pOptions,this);
	dlg.exec();
	m_pDatabase->updatePaperTableModel(getRP_PaperFilters());
}

void UrielQtFramework::onPaperEditActionTriggered() {
	sUrielPaperItem item;
	QModelIndex index = ui.RP_PaperTableView->currentIndex();
	if (index.isValid())
	{
		int mIndex = index.row();
		QModelIndex idx = index.sibling(mIndex, 0);
		if (idx.isValid())

			m_pDatabase->getPaperInfoByID(item, idx.data().toString());
	}
	PaperInfo dlg(m_pDatabase, m_pOptions, this);
	dlg.openWithEditMode(item);
	dlg.exec();
	m_pDatabase->updatePaperTableModel(getRP_PaperFilters());
}

void UrielQtFramework::onPaperDeleteActionTriggered() {
	InformationDialog information(QStringLiteral("信息"), QStringLiteral("确定删除该论文么？"), this);
	if (information.exec() == QDialog::Accepted) {
		sUrielPaperItem item;
		QModelIndex index = ui.RP_PaperTableView->currentIndex();
		if (index.isValid())
		{
			int mIndex = index.row();
			QModelIndex idx = index.sibling(mIndex, 0);
			if (idx.isValid())

				m_pDatabase->getPaperInfoByID(item, idx.data().toString());
		}

		QStringList fileList = item.ServerFileAddress.split(";");
		for each (QString var in fileList)
			m_pUrielFtp->Remove(var);
		m_pDatabase->deletePaper(QString::number(item.ID));
		m_pDatabase->updatePaperTableModel(getRP_PaperFilters());
	}
	
}

void UrielQtFramework::onRP_PaperTableViewDoubleClicked(const QModelIndex &index) {
	onPaperEditActionTriggered();
	/*sUrielPaperItem item;
	if (index.isValid())
	{
		int mIndex = index.row();
		QModelIndex idx = index.sibling(mIndex, 0);
		if (idx.isValid())
			m_pDatabase->getPaperInfoByID(item, idx.data().toString());
	}
	QStringList fileList = item.ServerFileAddress.split(";");
	if (fileList.count()) {
		QString file_path = QFileDialog::getExistingDirectory(nullptr, QStringLiteral("请选择文件保存路径..."), "./");
		for each (QString var in fileList) {
			ProgressDialog *progressDialog = new ProgressDialog(this);
			QObject::connect(m_pUrielFtp, static_cast<void (UrielFtp::*)(qint64 readBytes, qint64 totalBytes)>(&UrielFtp::updateDataTransferProgressSignal), \
				progressDialog, &ProgressDialog::updateProgressBarValue);
			progressDialog->setTotalProgressBarMax(1);
			m_pUrielFtp->downloadFiles(file_path, var);
			progressDialog->exec();
			QEventLoop eventloop;
			QTimer::singleShot(100, &eventloop, SLOT(quit()));
			eventloop.exec();
		}
	}
	m_pDatabase->updatePaperDownloadCount(QString::number(item.ID));
	m_pDatabase->updatePaperTableModel(getRP_PaperFilters());*/
}

QString UrielQtFramework::getRP_PaperFilters() {
	QString str, strSQL = "";

	str = ui.RP_PaperAuthorCombox->currentText();

	if (!str.isEmpty() && str != QStringLiteral("所有作者"))
	{
		strSQL += " WHERE Author like '%" + str + "%'";
	}
	str = ui.RP_PaperYearCombox->currentText();
	str.left(4);
	if (!str.isEmpty() && str != QStringLiteral("全部时间") && !strSQL.isEmpty())
	{
		strSQL += " AND year(EmploymentTime) ='" + str + "'";
	}
	else if (!str.isEmpty() && str != QStringLiteral("全部时间") && strSQL.isEmpty())
	{
		strSQL += " WHERE year(EmploymentTime) ='" + str + "'";
	}
	str = ui.RP_PaperTitleLineEdit->text();
	if (!str.isEmpty() && !strSQL.isEmpty())
	{
		strSQL += " AND OriginalTitle  like '%" + str + "%'";
	}
	else if (!str.isEmpty()&& strSQL.isEmpty())
	{
		strSQL += " WHERE OriginalTitle  like '%" + str + "%'";
	}
	return strSQL;
}

void UrielQtFramework::onRP_PaperAuthorComboxCurrentIndexChanged(int index) {
	m_pDatabase->updatePaperTableModel(getRP_PaperFilters());
}
void UrielQtFramework::onRP_PaperYearComboxCurrentIndexChanged(int index) {
	m_pDatabase->updatePaperTableModel(getRP_PaperFilters());
}
void UrielQtFramework::onRP_PaperTitleLineEditingFinished() {
	m_pDatabase->updatePaperTableModel(getRP_PaperFilters());
}

void UrielQtFramework::initializeAcademicConferenceUi() {
	ui.RP_AcademicConferenceTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.RP_AcademicConferenceTableView->setSortingEnabled(true);
	ui.RP_AcademicConferenceTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.RP_AcademicConferenceTableView->setShowGrid(false);
	ui.RP_AcademicConferenceTableView->verticalHeader()->setVisible(false);
	ui.RP_AcademicConferenceTableView->setAlternatingRowColors(true);
	ui.RP_AcademicConferenceTableView->setMouseTracking(true);
	ui.RP_AcademicConferenceTableView->setSelectionMode(QAbstractItemView::ContiguousSelection);//设置为连续选择模式
	ui.RP_AcademicConferenceTableView->setContextMenuPolicy(Qt::ActionsContextMenu);//设置为action菜单模式

	QAction * AcademicConferenceAddAction = new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/add.png"), QStringLiteral("新增"), this);
	QAction * AcademicConferenceEditAction = new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/edit.png"), QStringLiteral("编辑"), this);
	QAction * AcademicConferenceDeleteAction = new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/delete.png"), QStringLiteral("删除"), this);
	QAction * AcademicConferenceDownLoadAction = new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/download01.png"), QStringLiteral("下载"), this);

	ui.RP_AcademicConferenceTableView->addAction(AcademicConferenceAddAction);
	ui.RP_AcademicConferenceTableView->addAction(AcademicConferenceEditAction);
	ui.RP_AcademicConferenceTableView->addAction(AcademicConferenceDeleteAction);
	ui.RP_AcademicConferenceTableView->addAction(AcademicConferenceDownLoadAction);

	connect(AcademicConferenceAddAction, &QAction::triggered, this, &UrielQtFramework::onAcademicConferenceAddActionTriggered);
	connect(AcademicConferenceEditAction, &QAction::triggered, this, &UrielQtFramework::onAcademicConferenceEditActionTriggered);
	connect(AcademicConferenceDeleteAction, &QAction::triggered, this, &UrielQtFramework::onAcademicConferenceDeleteActionTriggered);
	connect(AcademicConferenceDownLoadAction, &QAction::triggered, this, &UrielQtFramework::onAcademicConferenceDownLoadActionTriggered);

	connect(ui.RP_AcademicConferenceTableView, static_cast<void (QTableView::*)(const QModelIndex &)>(&QTableView::doubleClicked), this, &UrielQtFramework::onRP_AcademicConferenceTableViewDoubleClicked);

	m_UrielAcademicConferenceTableModel = m_pDatabase->creatAcademicConferenceTableModel();
	m_pUrielAcademicConferenceTableSortFilterModel = new QSortFilterProxyModel;
	m_pUrielAcademicConferenceTableSortFilterModel->setDynamicSortFilter(true);
	m_pUrielAcademicConferenceTableSortFilterModel->setSourceModel(m_UrielAcademicConferenceTableModel);
	ui.RP_AcademicConferenceTableView->setModel(m_pUrielAcademicConferenceTableSortFilterModel);

	//ID, OriginalTitle, TranslationTitle, ReleaseTime, ConferenceLanguage, "
	//	"PublicationForm,Author,ConferenceName,ConferenceSessionsNumber,IndexedAddress,ServerFileAddress,"
	//	"Uploader,UploadTime,DownloadCount

	QList<int> wdls;
	wdls << 60 << 200 << 200 << 150 << 60 << 80 << 200 << 200 << 80 << 200 << 0  << 80 << 150 << 60 ;
	for (int i = 0; i < wdls.size(); i++)
	{
		ui.RP_AcademicConferenceTableView->setColumnWidth(i, wdls[i]);
	}

	m_pDatabase->updateAcademicConferenceTableModel();
	QStringList AuthorList;
	m_pDatabase->getAllAcademicConferenceAuthorName(AuthorList);
	ui.RP_AcademicConferenceAuthorCombox->addItem(QIcon(":/Mainwindow/Resources/UrielQtFramework/staff.png"), QStringLiteral("所有作者"));
	for each (QString var in AuthorList)
		ui.RP_AcademicConferenceAuthorCombox->addItem(QIcon(":/Mainwindow/Resources/UrielQtFramework/staff.png"), var);
	ui.RP_AcademicConferenceAuthorCombox->setCurrentIndex(0);

	ui.RP_AcademicConferenceYearCombox->addItem(QIcon(":/Mainwindow/Resources/UrielQtFramework/time.png"), QStringLiteral("全部时间"));
	for (int i = QDateTime::currentDateTime().date().year(); i >= 2000; i--)
		ui.RP_AcademicConferenceYearCombox->addItem(QIcon(":/Mainwindow/Resources/UrielQtFramework/time.png"), QStringLiteral("%0年").arg(i));
	ui.RP_AcademicConferenceYearCombox->setCurrentIndex(0);
}
void UrielQtFramework::setAcademicConferenceSignalsAndSlots() {
	QObject::connect(ui.RP_AddAcademicConferenceTBtn, &QToolButton::clicked, this, &UrielQtFramework::onAcademicConferenceAddActionTriggered);
	QObject::connect(ui.RP_EditAcademicConferenceTBtn, &QToolButton::clicked, this, &UrielQtFramework::onAcademicConferenceEditActionTriggered);
	QObject::connect(ui.RP_DeleteAcademicConferenceTBtn, &QToolButton::clicked, this, &UrielQtFramework::onAcademicConferenceDeleteActionTriggered);
	QObject::connect(ui.RP_AcademicConferenceAuthorCombox, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
		this, &UrielQtFramework::onRP_AcademicConferenceAuthorComboxCurrentIndexChanged);
	QObject::connect(ui.RP_AcademicConferenceYearCombox, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
		this, &UrielQtFramework::onRP_AcademicConferenceYearComboxCurrentIndexChanged);
	QObject::connect(ui.RP_AcademicConferenceNameLineEdit, &QLineEdit::editingFinished, this, &UrielQtFramework::onRP_AcademicConferenceTitleLineEditingFinished);
	QObject::connect(ui.RP_AcademicConferenceSearchPBtn, &QPushButton::clicked, this, &UrielQtFramework::onRP_AcademicConferenceTitleLineEditingFinished);
}

void UrielQtFramework::onAcademicConferenceDownLoadActionTriggered() {
	QItemSelectionModel *selections = ui.RP_AcademicConferenceTableView->selectionModel();
	QModelIndexList selectedIndexs = selections->selectedIndexes();
	QMap <int, int> rowMap;
	QString file_path = QFileDialog::getExistingDirectory(nullptr, QStringLiteral("请选择文件保存路径..."), "./");
	for (int i = 0; i<selectedIndexs.size(); i += 18)
	{
		QModelIndex index = selectedIndexs[i];
		sUrielAcademicConferenceItem item;
		if (index.isValid())
		{
			int mIndex = index.row();
			QModelIndex idx = index.sibling(mIndex, 0);
			if (idx.isValid())
				m_pDatabase->getAcademicConferenceInfoByID(item, idx.data().toString());
		}
		QStringList fileList = item.ServerFileAddress.split(";");
		if (fileList.count()) {
			for each (QString var in fileList) {
				ProgressDialog *progressDialog = new ProgressDialog(this);
				QObject::connect(m_pUrielFtp, static_cast<void (UrielFtp::*)(qint64 readBytes, qint64 totalBytes)>(&UrielFtp::updateDataTransferProgressSignal), \
					progressDialog, &ProgressDialog::updateProgressBarValue);
				progressDialog->setTotalProgressBarMax(1);
				if (m_pUrielFtp->downloadFiles(file_path, var)) {
					progressDialog->exec();
					QEventLoop eventloop;
					QTimer::singleShot(100, &eventloop, SLOT(quit()));
					eventloop.exec();
				}
				else {
					QObject::disconnect(m_pUrielFtp, static_cast<void (UrielFtp::*)(qint64 readBytes, qint64 totalBytes)>(&UrielFtp::updateDataTransferProgressSignal), \
						progressDialog, &ProgressDialog::updateProgressBarValue);
					delete progressDialog;
				}
			}
		}
		m_pDatabase->updateAcademicConferenceDownloadCount(QString::number(item.ID));
	}
	m_pDatabase->updateAcademicConferenceTableModel(getRP_AcademicConferenceFilters());
}

void UrielQtFramework::onAcademicConferenceAddActionTriggered() {
	AcademicConferenceInfo dlg(m_pDatabase, m_pOptions, this);
	dlg.exec();
	m_pDatabase->updateAcademicConferenceTableModel(getRP_AcademicConferenceFilters());
}
void UrielQtFramework::onAcademicConferenceEditActionTriggered() {
	sUrielAcademicConferenceItem item;
	QModelIndex index = ui.RP_AcademicConferenceTableView->currentIndex();
	if (index.isValid())
	{
		int mIndex = index.row();
		QModelIndex idx = index.sibling(mIndex, 0);
		if (idx.isValid())
			m_pDatabase->getAcademicConferenceInfoByID(item, idx.data().toString());
	}
	AcademicConferenceInfo dlg(m_pDatabase, m_pOptions, this);
	dlg.openWithEditMode(item);
	dlg.exec();
	m_pDatabase->updateAcademicConferenceTableModel(getRP_AcademicConferenceFilters());
}
void UrielQtFramework::onAcademicConferenceDeleteActionTriggered() {
	InformationDialog information(QStringLiteral("信息"), QStringLiteral("确定删除该会议记录么？"), this);
	if (information.exec() == QDialog::Accepted) {
		sUrielAcademicConferenceItem item;
		QModelIndex index = ui.RP_AcademicConferenceTableView->currentIndex();
		if (index.isValid())
		{
			int mIndex = index.row();
			QModelIndex idx = index.sibling(mIndex, 0);
			if (idx.isValid())

				m_pDatabase->getAcademicConferenceInfoByID(item, idx.data().toString());
		}

		QStringList fileList = item.ServerFileAddress.split(";");
		for each (QString var in fileList)
			m_pUrielFtp->Remove(var);
		m_pDatabase->deleteAcademicConference(QString::number(item.ID));
		m_pDatabase->updateAcademicConferenceTableModel(getRP_AcademicConferenceFilters());
	}

}
void UrielQtFramework::onRP_AcademicConferenceTableViewDoubleClicked(const QModelIndex &index) {
	onAcademicConferenceEditActionTriggered();
	/*sUrielAcademicConferenceItem item;
	if (index.isValid())
	{
		int mIndex = index.row();
		QModelIndex idx = index.sibling(mIndex, 0);
		if (idx.isValid())
			m_pDatabase->getAcademicConferenceInfoByID(item, idx.data().toString());
	}
	QStringList fileList = item.ServerFileAddress.split(";");
	if (fileList.count()) {
		QString file_path = QFileDialog::getExistingDirectory(nullptr, QStringLiteral("请选择文件保存路径..."), "./");
		for each (QString var in fileList) {
			ProgressDialog *progressDialog = new ProgressDialog(this);
			QObject::connect(m_pUrielFtp, static_cast<void (UrielFtp::*)(qint64 readBytes, qint64 totalBytes)>(&UrielFtp::updateDataTransferProgressSignal), \
				progressDialog, &ProgressDialog::updateProgressBarValue);
			progressDialog->setTotalProgressBarMax(1);
			m_pUrielFtp->downloadFiles(file_path, var);
			progressDialog->exec();
			QEventLoop eventloop;
			QTimer::singleShot(100, &eventloop, SLOT(quit()));
			eventloop.exec();
		}
	}
	m_pDatabase->updateAcademicConferenceDownloadCount(QString::number(item.ID));
	m_pDatabase->updateAcademicConferenceTableModel(getRP_AcademicConferenceFilters());*/
}
QString UrielQtFramework::getRP_AcademicConferenceFilters() {
	QString str, strSQL = "";

	str = ui.RP_AcademicConferenceAuthorCombox->currentText();

	if (!str.isEmpty() && str != QStringLiteral("所有作者"))
	{
		strSQL += " WHERE Author like '%" + str + "%'";
	}
	str = ui.RP_AcademicConferenceYearCombox->currentText();
	str.left(4);
	if (!str.isEmpty() && str != QStringLiteral("全部时间") && !strSQL.isEmpty())
	{
		strSQL += " AND year(ReleaseTime) ='" + str + "'";
	}
	else if (!str.isEmpty() && str != QStringLiteral("全部时间") && strSQL.isEmpty())
	{
		strSQL += " WHERE year(ReleaseTime) ='" + str + "'";
	}
	str = ui.RP_AcademicConferenceNameLineEdit->text();
	if (!str.isEmpty() && !strSQL.isEmpty())
	{
		strSQL += " AND ConferenceName  like '%" + str + "%'";
	}
	else if (!str.isEmpty() && strSQL.isEmpty())
	{
		strSQL += " WHERE ConferenceName  like '%" + str + "%'";
	}
	return strSQL;
}

void UrielQtFramework::onRP_AcademicConferenceAuthorComboxCurrentIndexChanged(int index) {
	m_pDatabase->updateAcademicConferenceTableModel(getRP_AcademicConferenceFilters());
}
void UrielQtFramework::onRP_AcademicConferenceYearComboxCurrentIndexChanged(int index) {
	m_pDatabase->updateAcademicConferenceTableModel(getRP_AcademicConferenceFilters());
}
void UrielQtFramework::onRP_AcademicConferenceTitleLineEditingFinished() {
	m_pDatabase->updateAcademicConferenceTableModel(getRP_AcademicConferenceFilters());
}


void UrielQtFramework::initializePatentUi() {
	ui.RP_PatentTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.RP_PatentTableView->setSortingEnabled(true);
	ui.RP_PatentTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.RP_PatentTableView->setShowGrid(false);
	ui.RP_PatentTableView->verticalHeader()->setVisible(false);
	ui.RP_PatentTableView->setAlternatingRowColors(true);
	ui.RP_PatentTableView->setMouseTracking(true);
	ui.RP_PatentTableView->setSelectionMode(QAbstractItemView::ContiguousSelection);//设置为连续选择模式
	ui.RP_PatentTableView->setContextMenuPolicy(Qt::ActionsContextMenu);//设置为action菜单模式

	QAction * PatentAddAction = new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/add.png"), QStringLiteral("新增"), this);
	QAction * PatentEditAction = new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/edit.png"), QStringLiteral("编辑"), this);
	QAction * PatentDeleteAction = new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/delete.png"), QStringLiteral("删除"), this);
	QAction * PatentDownLoadAction = new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/download01.png"), QStringLiteral("下载"), this);

	ui.RP_PatentTableView->addAction(PatentAddAction);
	ui.RP_PatentTableView->addAction(PatentEditAction);
	ui.RP_PatentTableView->addAction(PatentDeleteAction);
	ui.RP_PatentTableView->addAction(PatentDownLoadAction);

	connect(PatentAddAction, &QAction::triggered, this, &UrielQtFramework::onPatentAddActionTriggered);
	connect(PatentEditAction, &QAction::triggered, this, &UrielQtFramework::onPatentEditActionTriggered);
	connect(PatentDeleteAction, &QAction::triggered, this, &UrielQtFramework::onPatentDeleteActionTriggered);
	connect(PatentDownLoadAction, &QAction::triggered, this, &UrielQtFramework::onPatentDownLoadActionTriggered);

	connect(ui.RP_PatentTableView, static_cast<void (QTableView::*)(const QModelIndex &)>(&QTableView::doubleClicked), this, &UrielQtFramework::onRP_PatentTableViewDoubleClicked);

	m_UrielPatentTableModel = m_pDatabase->creatPatentTableModel();
	m_pUrielPatentTableSortFilterModel = new QSortFilterProxyModel;
	m_pUrielPatentTableSortFilterModel->setDynamicSortFilter(true);
	m_pUrielPatentTableSortFilterModel->setSourceModel(m_UrielPatentTableModel);
	ui.RP_PatentTableView->setModel(m_pUrielPatentTableSortFilterModel);
	//ID, Type, Number, Name, ApplyTime, ReleaseTime, AuthorizationTime"
		//",CopyRightUnit,Author,IndexedAddress,ServerFileAddress,Uploader,UploadTime,DownloadCount
	QList<int> wdls;
	wdls << 60 << 100 << 150 << 300 << 150 << 150 << 150 << 150 << 200 << 200 << 200 << 80 << 150 << 60;
	for (int i = 0; i < wdls.size(); i++)
	{
		ui.RP_PatentTableView->setColumnWidth(i, wdls[i]);
	}

	m_pDatabase->updatePatentTableModel();
	QStringList AuthorList;
	m_pDatabase->getAllPatentAuthorName(AuthorList);
	ui.RP_PatentAuthorCombox->addItem(QIcon(":/Mainwindow/Resources/UrielQtFramework/staff.png"), QStringLiteral("所有作者"));
	for each (QString var in AuthorList)
		ui.RP_PatentAuthorCombox->addItem(QIcon(":/Mainwindow/Resources/UrielQtFramework/staff.png"), var);
	ui.RP_PatentAuthorCombox->setCurrentIndex(0);

	ui.RP_PatentYearCombox->addItem(QIcon(":/Mainwindow/Resources/UrielQtFramework/time.png"), QStringLiteral("全部时间"));
	for (int i = QDateTime::currentDateTime().date().year(); i >= 2000; i--)
		ui.RP_PatentYearCombox->addItem(QIcon(":/Mainwindow/Resources/UrielQtFramework/time.png"), QStringLiteral("%0年").arg(i));
	ui.RP_PatentYearCombox->setCurrentIndex(0);
}
void UrielQtFramework::setPatentSignalsAndSlots() {
	QObject::connect(ui.RP_AddPatentTBtn, &QToolButton::clicked, this, &UrielQtFramework::onPatentAddActionTriggered);
	QObject::connect(ui.RP_EditPatentTBtn, &QToolButton::clicked, this, &UrielQtFramework::onPatentEditActionTriggered);
	QObject::connect(ui.RP_DeletePatentTBtn, &QToolButton::clicked, this, &UrielQtFramework::onPatentDeleteActionTriggered);
	QObject::connect(ui.RP_PatentAuthorCombox, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
		this, &UrielQtFramework::onRP_PatentAuthorComboxCurrentIndexChanged);
	QObject::connect(ui.RP_PatentYearCombox, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
		this, &UrielQtFramework::onRP_PatentYearComboxCurrentIndexChanged);
	QObject::connect(ui.RP_PatentTitleLineEdit, &QLineEdit::editingFinished, this, &UrielQtFramework::onRP_PatentTitleLineEditingFinished);
	QObject::connect(ui.RP_PatentSearchPBtn, &QPushButton::clicked, this, &UrielQtFramework::onRP_PatentTitleLineEditingFinished);
}

void UrielQtFramework::onPatentDownLoadActionTriggered() {
	QItemSelectionModel *selections = ui.RP_PatentTableView->selectionModel();
	QModelIndexList selectedIndexs = selections->selectedIndexes();
	QMap <int, int> rowMap;
	QString file_path = QFileDialog::getExistingDirectory(nullptr, QStringLiteral("请选择文件保存路径..."), "./");
	for (int i = 0; i<selectedIndexs.size(); i += 18)
	{
		QModelIndex index = selectedIndexs[i];
		sUrielPatentItem item;
		if (index.isValid())
		{
			int mIndex = index.row();
			QModelIndex idx = index.sibling(mIndex, 0);
			if (idx.isValid())
				m_pDatabase->getPatentInfoByID(item, idx.data().toString());
		}
		QStringList fileList = item.ServerFileAddress.split(";");
		if (fileList.count()) {
			for each (QString var in fileList) {
				ProgressDialog *progressDialog = new ProgressDialog(this);
				QObject::connect(m_pUrielFtp, static_cast<void (UrielFtp::*)(qint64 readBytes, qint64 totalBytes)>(&UrielFtp::updateDataTransferProgressSignal), \
					progressDialog, &ProgressDialog::updateProgressBarValue);
				progressDialog->setTotalProgressBarMax(1);
				if (m_pUrielFtp->downloadFiles(file_path, var)) {
					progressDialog->exec();
					QEventLoop eventloop;
					QTimer::singleShot(100, &eventloop, SLOT(quit()));
					eventloop.exec();
				}
				else {
					QObject::disconnect(m_pUrielFtp, static_cast<void (UrielFtp::*)(qint64 readBytes, qint64 totalBytes)>(&UrielFtp::updateDataTransferProgressSignal), \
						progressDialog, &ProgressDialog::updateProgressBarValue);
					delete progressDialog;
				}
			}
		}
		m_pDatabase->updatePatentDownloadCount(QString::number(item.ID));
	}
	m_pDatabase->updatePatentTableModel(getRP_PatentFilters());
}

void UrielQtFramework::onPatentAddActionTriggered() {
	PatentInfo dlg(m_pDatabase, m_pOptions, this);
	dlg.exec();
	m_pDatabase->updatePatentTableModel(getRP_PatentFilters());

}
void UrielQtFramework::onPatentEditActionTriggered() {
	sUrielPatentItem item;
	QModelIndex index = ui.RP_PatentTableView->currentIndex();
	if (index.isValid())
	{
		int mIndex = index.row();
		QModelIndex idx = index.sibling(mIndex, 0);
		if (idx.isValid())
			m_pDatabase->getPatentInfoByID(item, idx.data().toString());
	}
	PatentInfo dlg(m_pDatabase, m_pOptions, this);
	dlg.openWithEditMode(item);
	dlg.exec();
	m_pDatabase->updatePatentTableModel(getRP_PatentFilters());
}
void UrielQtFramework::onPatentDeleteActionTriggered() {
	InformationDialog information(QStringLiteral("信息"), QStringLiteral("确定删除该专利记录么？"), this);
	if (information.exec() == QDialog::Accepted) {
		sUrielPatentItem item;
		QModelIndex index = ui.RP_PatentTableView->currentIndex();
		if (index.isValid())
		{
			int mIndex = index.row();
			QModelIndex idx = index.sibling(mIndex, 0);
			if (idx.isValid())

				m_pDatabase->getPatentInfoByID(item, idx.data().toString());
		}

		QStringList fileList = item.ServerFileAddress.split(";");
		for each (QString var in fileList)
			m_pUrielFtp->Remove(var);
		m_pDatabase->deletePatent(QString::number(item.ID));
		m_pDatabase->updatePatentTableModel(getRP_PatentFilters());
	}

}
void UrielQtFramework::onRP_PatentTableViewDoubleClicked(const QModelIndex &index) {
	onPatentEditActionTriggered();
	//sUrielPatentItem item;
	//if (index.isValid())
	//{
	//	int mIndex = index.row();
	//	QModelIndex idx = index.sibling(mIndex, 0);
	//	if (idx.isValid())
	//		m_pDatabase->getPatentInfoByID(item, idx.data().toString());
	//}
	//QStringList fileList = item.ServerFileAddress.split(";");
	//if (fileList.count()) {
	//	QString file_path = QFileDialog::getExistingDirectory(nullptr, QStringLiteral("请选择文件保存路径..."), "./");
	//	for each (QString var in fileList) {
	//		ProgressDialog *progressDialog = new ProgressDialog(this);
	//		QObject::connect(m_pUrielFtp, static_cast<void (UrielFtp::*)(qint64 readBytes, qint64 totalBytes)>(&UrielFtp::updateDataTransferProgressSignal), \
	//			progressDialog, &ProgressDialog::updateProgressBarValue);
	//		progressDialog->setTotalProgressBarMax(1);
	//		m_pUrielFtp->downloadFiles(file_path, var);
	//		progressDialog->exec();
	//		QEventLoop eventloop;
	//		QTimer::singleShot(100, &eventloop, SLOT(quit()));
	//		eventloop.exec();
	//	}
	//}
	//m_pDatabase->updatePatentDownloadCount(QString::number(item.ID));
	//m_pDatabase->updatePatentTableModel(getRP_PatentFilters());
}
QString UrielQtFramework::getRP_PatentFilters() {
	QString str, strSQL = "";

	str = ui.RP_PatentAuthorCombox->currentText();

	if (!str.isEmpty() && str != QStringLiteral("所有作者"))
	{
		strSQL += " WHERE Author like '%" + str + "%'";
	}
	str = ui.RP_PatentYearCombox->currentText();
	str.left(4);
	if (!str.isEmpty() && str != QStringLiteral("全部时间") && !strSQL.isEmpty())
	{
		strSQL += " AND year(AuthorizationTime) ='" + str + "'";
	}
	else if (!str.isEmpty() && str != QStringLiteral("全部时间") && strSQL.isEmpty())
	{
		strSQL += " WHERE year(AuthorizationTime) ='" + str + "'";
	}
	str = ui.RP_PatentTitleLineEdit->text();
	if (!str.isEmpty() && !strSQL.isEmpty())
	{
		strSQL += " AND Name  like '%" + str + "%'";
	}
	else if (!str.isEmpty() && strSQL.isEmpty())
	{
		strSQL += " WHERE Name  like '%" + str + "%'";
	}
	return strSQL;
}

void UrielQtFramework::onRP_PatentAuthorComboxCurrentIndexChanged(int index) {
	m_pDatabase->updatePatentTableModel(getRP_PatentFilters());
}
void UrielQtFramework::onRP_PatentYearComboxCurrentIndexChanged(int index) {
	m_pDatabase->updatePatentTableModel(getRP_PatentFilters());
}
void UrielQtFramework::onRP_PatentTitleLineEditingFinished() {
	m_pDatabase->updatePatentTableModel(getRP_PatentFilters());
}

void UrielQtFramework::initializeWorksUi() {
	ui.RP_WorksTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.RP_WorksTableView->setSortingEnabled(true);
	ui.RP_WorksTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.RP_WorksTableView->setShowGrid(false);
	ui.RP_WorksTableView->verticalHeader()->setVisible(false);
	ui.RP_WorksTableView->setAlternatingRowColors(true);
	ui.RP_WorksTableView->setMouseTracking(true);
	ui.RP_WorksTableView->setSelectionMode(QAbstractItemView::ContiguousSelection);//设置为连续选择模式
	ui.RP_WorksTableView->setContextMenuPolicy(Qt::ActionsContextMenu);//设置为action菜单模式

	QAction * WorksAddAction = new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/add.png"), QStringLiteral("新增"), this);
	QAction * WorksEditAction = new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/edit.png"), QStringLiteral("编辑"), this);
	QAction * WorksDeleteAction = new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/delete.png"), QStringLiteral("删除"), this);
	QAction * WorksDownLoadAction = new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/download01.png"), QStringLiteral("下载"), this);

	ui.RP_WorksTableView->addAction(WorksAddAction);
	ui.RP_WorksTableView->addAction(WorksEditAction);
	ui.RP_WorksTableView->addAction(WorksDeleteAction);
	ui.RP_WorksTableView->addAction(WorksDownLoadAction);

	connect(WorksAddAction, &QAction::triggered, this, &UrielQtFramework::onWorksAddActionTriggered);
	connect(WorksEditAction, &QAction::triggered, this, &UrielQtFramework::onWorksEditActionTriggered);
	connect(WorksDeleteAction, &QAction::triggered, this, &UrielQtFramework::onWorksDeleteActionTriggered);
	connect(WorksDownLoadAction, &QAction::triggered, this, &UrielQtFramework::onWorksDownLoadActionTriggered);

	connect(ui.RP_WorksTableView, static_cast<void (QTableView::*)(const QModelIndex &)>(&QTableView::doubleClicked), this, &UrielQtFramework::onRP_WorksTableViewDoubleClicked);

	m_UrielWorksTableModel = m_pDatabase->creatWorksTableModel();
	m_pUrielWorksTableSortFilterModel = new QSortFilterProxyModel;
	m_pUrielWorksTableSortFilterModel->setDynamicSortFilter(true);
	m_pUrielWorksTableSortFilterModel->setSourceModel(m_UrielWorksTableModel);
	ui.RP_WorksTableView->setModel(m_pUrielWorksTableSortFilterModel);
	QList<int> wdls;
	wdls << 60 << 100 << 250 << 150 << 150 << 150 << 100 << 80 << 200 << 200<< 80 << 150 << 60;
	for (int i = 0; i < wdls.size(); i++)
	{
		ui.RP_WorksTableView->setColumnWidth(i, wdls[i]);
	}
	m_pDatabase->updateWorksTableModel();
	QStringList AuthorList;
	m_pDatabase->getAllWorksAuthorName(AuthorList);
	ui.RP_WorksAuthorCombox->addItem(QIcon(":/Mainwindow/Resources/UrielQtFramework/staff.png"), QStringLiteral("所有作者"));
	for each (QString var in AuthorList)
		ui.RP_WorksAuthorCombox->addItem(QIcon(":/Mainwindow/Resources/UrielQtFramework/staff.png"), var);
	ui.RP_WorksAuthorCombox->setCurrentIndex(0);

	ui.RP_WorksYearCombox->addItem(QIcon(":/Mainwindow/Resources/UrielQtFramework/time.png"), QStringLiteral("全部时间"));
	for (int i = QDateTime::currentDateTime().date().year(); i >= 2000; i--)
		ui.RP_WorksYearCombox->addItem(QIcon(":/Mainwindow/Resources/UrielQtFramework/time.png"), QStringLiteral("%0年").arg(i));
	ui.RP_WorksYearCombox->setCurrentIndex(0);
}

void UrielQtFramework::setWorksSignalsAndSlots() {
	QObject::connect(ui.RP_AddWorksTBtn, &QToolButton::clicked, this, &UrielQtFramework::onWorksAddActionTriggered);
	QObject::connect(ui.RP_EditWorksTBtn, &QToolButton::clicked, this, &UrielQtFramework::onWorksEditActionTriggered);
	QObject::connect(ui.RP_DeleteWorksTBtn, &QToolButton::clicked, this, &UrielQtFramework::onWorksDeleteActionTriggered);
	QObject::connect(ui.RP_WorksAuthorCombox, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
		this, &UrielQtFramework::onRP_WorksAuthorComboxCurrentIndexChanged);
	QObject::connect(ui.RP_WorksYearCombox, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
		this, &UrielQtFramework::onRP_WorksYearComboxCurrentIndexChanged);
	QObject::connect(ui.RP_WorksTitleLineEdit, &QLineEdit::editingFinished, this, &UrielQtFramework::onRP_WorksTitleLineEditingFinished);
	QObject::connect(ui.RP_WorksSearchPBtn, &QPushButton::clicked, this, &UrielQtFramework::onRP_WorksTitleLineEditingFinished);
}

void UrielQtFramework::onWorksDownLoadActionTriggered() {
	QItemSelectionModel *selections = ui.RP_WorksTableView->selectionModel();
	QModelIndexList selectedIndexs = selections->selectedIndexes();
	QMap <int, int> rowMap;
	QString file_path = QFileDialog::getExistingDirectory(nullptr, QStringLiteral("请选择文件保存路径..."), "./");
	for (int i = 0; i<selectedIndexs.size(); i += 18)
	{
		QModelIndex index = selectedIndexs[i];
		sUrielWorksItem item;
		if (index.isValid())
		{
			int mIndex = index.row();
			QModelIndex idx = index.sibling(mIndex, 0);
			if (idx.isValid())
				m_pDatabase->getWorksInfoByID(item, idx.data().toString());
		}
		QStringList fileList = item.ServerFileAddress.split(";");
		if (fileList.count()) {
			for each (QString var in fileList) {
				ProgressDialog *progressDialog = new ProgressDialog(this);
				QObject::connect(m_pUrielFtp, static_cast<void (UrielFtp::*)(qint64 readBytes, qint64 totalBytes)>(&UrielFtp::updateDataTransferProgressSignal), \
					progressDialog, &ProgressDialog::updateProgressBarValue);
				progressDialog->setTotalProgressBarMax(1);
				if (m_pUrielFtp->downloadFiles(file_path, var)) {
					progressDialog->exec();
					QEventLoop eventloop;
					QTimer::singleShot(100, &eventloop, SLOT(quit()));
					eventloop.exec();
				}
				else {
					QObject::disconnect(m_pUrielFtp, static_cast<void (UrielFtp::*)(qint64 readBytes, qint64 totalBytes)>(&UrielFtp::updateDataTransferProgressSignal), \
						progressDialog, &ProgressDialog::updateProgressBarValue);
					delete progressDialog;
				}
			}
		}
		m_pDatabase->updateWorksDownloadCount(QString::number(item.ID));
	}
	m_pDatabase->updateWorksTableModel(getRP_WorksFilters());
}

void UrielQtFramework::onWorksAddActionTriggered() {
	WorksInfo dlg(m_pDatabase, m_pOptions, this);
	dlg.exec();
	m_pDatabase->updateWorksTableModel(getRP_WorksFilters());
}
void UrielQtFramework::onWorksEditActionTriggered() {
	sUrielWorksItem item;
	QModelIndex index = ui.RP_WorksTableView->currentIndex();
	if (index.isValid())
	{
		int mIndex = index.row();
		QModelIndex idx = index.sibling(mIndex, 0);
		if (idx.isValid())
			m_pDatabase->getWorksInfoByID(item, idx.data().toString());
	}
	WorksInfo dlg(m_pDatabase, m_pOptions, this);
	dlg.openWithEditMode(item);
	dlg.exec();
	m_pDatabase->updateWorksTableModel(getRP_WorksFilters());
}
void UrielQtFramework::onWorksDeleteActionTriggered() {
	InformationDialog information(QStringLiteral("信息"), QStringLiteral("确定删除该著作记录么？"), this);
	if (information.exec() == QDialog::Accepted) {
		sUrielWorksItem item;
		QModelIndex index = ui.RP_WorksTableView->currentIndex();
		if (index.isValid())
		{
			int mIndex = index.row();
			QModelIndex idx = index.sibling(mIndex, 0);
			if (idx.isValid())

				m_pDatabase->getWorksInfoByID(item, idx.data().toString());
		}

		QStringList fileList = item.ServerFileAddress.split(";");
		for each (QString var in fileList)
			m_pUrielFtp->Remove(var);
		m_pDatabase->deleteWorks(QString::number(item.ID));
		m_pDatabase->updateWorksTableModel(getRP_WorksFilters());
	}

}
void UrielQtFramework::onRP_WorksTableViewDoubleClicked(const QModelIndex &index) {
	onWorksEditActionTriggered();
	//sUrielWorksItem item;
	//if (index.isValid())
	//{
	//	int mIndex = index.row();
	//	QModelIndex idx = index.sibling(mIndex, 0);
	//	if (idx.isValid())
	//		m_pDatabase->getWorksInfoByID(item, idx.data().toString());
	//}
	//QStringList fileList = item.ServerFileAddress.split(";");
	//if (fileList.count()) {
	//	QString file_path = QFileDialog::getExistingDirectory(nullptr, QStringLiteral("请选择文件保存路径..."), "./");
	//	for each (QString var in fileList) {
	//		ProgressDialog *progressDialog = new ProgressDialog(this);
	//		QObject::connect(m_pUrielFtp, static_cast<void (UrielFtp::*)(qint64 readBytes, qint64 totalBytes)>(&UrielFtp::updateDataTransferProgressSignal), \
	//			progressDialog, &ProgressDialog::updateProgressBarValue);
	//		progressDialog->setTotalProgressBarMax(1);
	//		m_pUrielFtp->downloadFiles(file_path, var);
	//		progressDialog->exec();
	//		QEventLoop eventloop;
	//		QTimer::singleShot(100, &eventloop, SLOT(quit()));
	//		eventloop.exec();
	//	}
	//}
	//m_pDatabase->updateWorksDownloadCount(QString::number(item.ID));
	//m_pDatabase->updateWorksTableModel(getRP_WorksFilters());
}
QString UrielQtFramework::getRP_WorksFilters() {
	QString str, strSQL = "";

	str = ui.RP_WorksAuthorCombox->currentText();

	if (!str.isEmpty() && str != QStringLiteral("所有作者"))
	{
		strSQL += " WHERE Author like '%" + str + "%'";
	}
	str = ui.RP_WorksYearCombox->currentText();
	str.left(4);
	if (!str.isEmpty() && str != QStringLiteral("全部时间") && !strSQL.isEmpty())
	{
		strSQL += " AND year(PublishingTime) ='" + str + "'";
	}
	else if (!str.isEmpty() && str != QStringLiteral("全部时间") && strSQL.isEmpty())
	{
		strSQL += " WHERE year(PublishingTime) ='" + str + "'";
	}
	str = ui.RP_WorksTitleLineEdit->text();
	if (!str.isEmpty() && !strSQL.isEmpty())
	{
		strSQL += " AND Name  like '%" + str + "%'";
	}
	else if (!str.isEmpty() && strSQL.isEmpty())
	{
		strSQL += " WHERE Name  like '%" + str + "%'";
	}
	return strSQL;
}
void UrielQtFramework::onRP_WorksAuthorComboxCurrentIndexChanged(int index) {
	m_pDatabase->updateWorksTableModel(getRP_WorksFilters());
}
void UrielQtFramework::onRP_WorksYearComboxCurrentIndexChanged(int index) {
	m_pDatabase->updateWorksTableModel(getRP_WorksFilters());
}
void UrielQtFramework::onRP_WorksTitleLineEditingFinished() {
	m_pDatabase->updateWorksTableModel(getRP_WorksFilters());
}


void UrielQtFramework::initializeResearchProjectUi() {
	ui.RP_ResearchProjectTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.RP_ResearchProjectTableView->setSortingEnabled(true);
	ui.RP_ResearchProjectTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.RP_ResearchProjectTableView->setShowGrid(false);
	ui.RP_ResearchProjectTableView->verticalHeader()->setVisible(false);
	ui.RP_ResearchProjectTableView->setAlternatingRowColors(true);
	ui.RP_ResearchProjectTableView->setMouseTracking(true);
	ui.RP_ResearchProjectTableView->setSelectionMode(QAbstractItemView::ContiguousSelection);//设置为连续选择模式
	ui.RP_ResearchProjectTableView->setContextMenuPolicy(Qt::ActionsContextMenu);//设置为action菜单模式

	QAction * ResearchProjectAddAction = new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/add.png"), QStringLiteral("新增"), this);
	QAction * ResearchProjectEditAction = new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/edit.png"), QStringLiteral("编辑"), this);
	QAction * ResearchProjectDeleteAction = new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/delete.png"), QStringLiteral("删除"), this);
	QAction * ResearchProjectDataDownloadAction = new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/data.png"), QStringLiteral("下载实验资料"), this);
	QAction * ResearchProjectPaperDownloadAction = new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/Paper2.png"), QStringLiteral("下载毕业论文"), this);

	ui.RP_ResearchProjectTableView->addAction(ResearchProjectAddAction);
	ui.RP_ResearchProjectTableView->addAction(ResearchProjectEditAction);
	ui.RP_ResearchProjectTableView->addAction(ResearchProjectDeleteAction);
	ui.RP_ResearchProjectTableView->addAction(ResearchProjectDataDownloadAction);
	ui.RP_ResearchProjectTableView->addAction(ResearchProjectPaperDownloadAction);

	connect(ResearchProjectAddAction, &QAction::triggered, this, &UrielQtFramework::onResearchProjectAddActionTriggered);
	connect(ResearchProjectEditAction, &QAction::triggered, this, &UrielQtFramework::onResearchProjectEditActionTriggered);
	connect(ResearchProjectDeleteAction, &QAction::triggered, this, &UrielQtFramework::onResearchProjectDeleteActionTriggered);
	connect(ResearchProjectDataDownloadAction, &QAction::triggered, this, &UrielQtFramework::onResearchProjectDataDownloadActionTriggered);
	connect(ResearchProjectPaperDownloadAction, &QAction::triggered, this, &UrielQtFramework::onResearchProjectPaperDownloadActionTriggered);

	connect(ui.RP_ResearchProjectTableView, static_cast<void (QTableView::*)(const QModelIndex &)>(&QTableView::doubleClicked), this, &UrielQtFramework::onRP_ResearchProjectTableViewDoubleClicked);

	m_UrielResearchProjectTableModel = m_pDatabase->creatResearchProjectTableModel();
	m_pUrielResearchProjectTableSortFilterModel = new QSortFilterProxyModel;
	m_pUrielResearchProjectTableSortFilterModel->setDynamicSortFilter(true);
	m_pUrielResearchProjectTableSortFilterModel->setSourceModel(m_UrielResearchProjectTableModel);
	ui.RP_ResearchProjectTableView->setModel(m_pUrielResearchProjectTableSortFilterModel);
	//ID, Name, StartTime, EndTime, Type, Number, Funds"
	//	",Participants,ServerDataAddress,ServerPaperAddress,IndexedAddress,Graduates,UploadTime,"
	//	"AuditStatus,Auditor,AuditTime,DownloadCount

	QList<int> wdls;
	wdls << 60 <<250 << 150 << 150 << 100 << 80 << 80 <<200 << 0 << 0 << 250 << 80 << 150 << 100 << 80 << 150 << 80;
	for (int i = 0; i < wdls.size(); i++)
	{
		ui.RP_ResearchProjectTableView->setColumnWidth(i, wdls[i]);
	}
	m_pDatabase->updateResearchProjectTableModel();
	QStringList AuthorList;
	m_pDatabase->getAllResearchProjectAuthorName(AuthorList);
	ui.RP_ResearchProjectAuthorCombox->addItem(QIcon(":/Mainwindow/Resources/UrielQtFramework/staff.png"), QStringLiteral("所有人员"));
	for each (QString var in AuthorList)
		ui.RP_ResearchProjectAuthorCombox->addItem(QIcon(":/Mainwindow/Resources/UrielQtFramework/staff.png"), var);
	ui.RP_ResearchProjectAuthorCombox->setCurrentIndex(0);

	ui.RP_ResearchProjectYearCombox->addItem(QIcon(":/Mainwindow/Resources/UrielQtFramework/time.png"), QStringLiteral("全部时间"));
	for (int i = QDateTime::currentDateTime().date().year(); i >= 2000; i--)
		ui.RP_ResearchProjectYearCombox->addItem(QIcon(":/Mainwindow/Resources/UrielQtFramework/time.png"), QStringLiteral("%0年").arg(i));
	ui.RP_ResearchProjectYearCombox->setCurrentIndex(0);
}

void UrielQtFramework::setResearchProjectSignalsAndSlots() {
	QObject::connect(ui.RP_AddResearchProjectTBtn, &QToolButton::clicked, this, &UrielQtFramework::onResearchProjectAddActionTriggered);
	QObject::connect(ui.RP_EditResearchProjectTBtn, &QToolButton::clicked, this, &UrielQtFramework::onResearchProjectEditActionTriggered);
	QObject::connect(ui.RP_DeleteResearchProjectTBtn, &QToolButton::clicked, this, &UrielQtFramework::onResearchProjectDeleteActionTriggered);
	QObject::connect(ui.RP_ResearchProjectAuthorCombox, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
		this, &UrielQtFramework::onRP_ResearchProjectAuthorComboxCurrentIndexChanged);
	QObject::connect(ui.RP_ResearchProjectYearCombox, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
		this, &UrielQtFramework::onRP_ResearchProjectYearComboxCurrentIndexChanged);
	QObject::connect(ui.RP_ResearchProjectTitleLineEdit, &QLineEdit::editingFinished, this, &UrielQtFramework::onRP_ResearchProjectTitleLineEditingFinished);
	QObject::connect(ui.RP_ResearchProjectSearchPBtn, &QPushButton::clicked, this, &UrielQtFramework::onRP_ResearchProjectTitleLineEditingFinished);
}

void UrielQtFramework::onResearchProjectAddActionTriggered() {
	ResearchProject dlg(m_pDatabase, m_pOptions, this);
	dlg.exec();
	m_pDatabase->updateResearchProjectTableModel(getRP_ResearchProjectFilters());
}
void UrielQtFramework::onResearchProjectEditActionTriggered() {
	sUrielResearchProjectItem item;
	QModelIndex index = ui.RP_ResearchProjectTableView->currentIndex();
	if (index.isValid())
	{
		int mIndex = index.row();
		QModelIndex idx = index.sibling(mIndex, 0);
		if (idx.isValid())
			m_pDatabase->getResearchProjectInfoByID(item, idx.data().toString());
	}
	ResearchProject dlg(m_pDatabase, m_pOptions, this);
	dlg.openWithEditMode(item);
	dlg.exec();
	m_pDatabase->updateResearchProjectTableModel(getRP_ResearchProjectFilters());
}
void UrielQtFramework::onResearchProjectDeleteActionTriggered() {
	InformationDialog information(QStringLiteral("信息"), QStringLiteral("确定删除该科研项目记录么？"), this);
	if (information.exec() == QDialog::Accepted) {
		sUrielResearchProjectItem item;
		QModelIndex index = ui.RP_ResearchProjectTableView->currentIndex();
		if (index.isValid())
		{
			int mIndex = index.row();
			QModelIndex idx = index.sibling(mIndex, 0);
			if (idx.isValid())

				m_pDatabase->getResearchProjectInfoByID(item, idx.data().toString());
		}

		QStringList fileList = item.ServerDataAddress.split(";");
		for each (QString var in fileList)
			m_pUrielFtp->Remove(var);

		fileList = item.ServerPaperAddress.split(";");
		for each (QString var in fileList)
			m_pUrielFtp->Remove(var);

		m_pDatabase->deleteResearchProject(QString::number(item.ID));
		m_pDatabase->updateResearchProjectTableModel(getRP_ResearchProjectFilters());
	}

}

void UrielQtFramework::onResearchProjectDataDownloadActionTriggered() {
	sUrielResearchProjectItem item;
	QModelIndex index = ui.RP_ResearchProjectTableView->currentIndex();
	if (index.isValid())
	{
		int mIndex = index.row();
		QModelIndex idx = index.sibling(mIndex, 0);
		if (idx.isValid())
			m_pDatabase->getResearchProjectInfoByID(item, idx.data().toString());
	}
	QStringList fileList = item.ServerDataAddress.split(";");
	if (fileList.count()) {
		QString file_path = QFileDialog::getExistingDirectory(nullptr, QStringLiteral("请选择文件保存路径..."), "./");
		for each (QString var in fileList) {
			ProgressDialog *progressDialog = new ProgressDialog(this);
			QObject::connect(m_pUrielFtp, static_cast<void (UrielFtp::*)(qint64 readBytes, qint64 totalBytes)>(&UrielFtp::updateDataTransferProgressSignal), \
				progressDialog, &ProgressDialog::updateProgressBarValue);
			progressDialog->setTotalProgressBarMax(1);
			if (m_pUrielFtp->downloadFiles(file_path, var)) {
				progressDialog->exec();
				QEventLoop eventloop;
				QTimer::singleShot(100, &eventloop, SLOT(quit()));
				eventloop.exec();
			}
			else {
				QObject::disconnect(m_pUrielFtp, static_cast<void (UrielFtp::*)(qint64 readBytes, qint64 totalBytes)>(&UrielFtp::updateDataTransferProgressSignal), \
					progressDialog, &ProgressDialog::updateProgressBarValue);
				delete progressDialog;
			}
		}
	}
	m_pDatabase->updateResearchProjectDownloadCount(QString::number(item.ID));
	m_pDatabase->updateResearchProjectTableModel(getRP_ResearchProjectFilters());
}

void UrielQtFramework::onResearchProjectPaperDownloadActionTriggered() {
	sUrielResearchProjectItem item;
	QModelIndex index = ui.RP_ResearchProjectTableView->currentIndex();
	if (index.isValid())
	{
		int mIndex = index.row();
		QModelIndex idx = index.sibling(mIndex, 0);
		if (idx.isValid())
			m_pDatabase->getResearchProjectInfoByID(item, idx.data().toString());
	}
	QStringList fileList = item.ServerPaperAddress.split(";");
	if (fileList.count()) {
		QString file_path = QFileDialog::getExistingDirectory(nullptr, QStringLiteral("请选择文件保存路径..."), "./");
		for each (QString var in fileList) {
			ProgressDialog *progressDialog = new ProgressDialog(this);
			QObject::connect(m_pUrielFtp, static_cast<void (UrielFtp::*)(qint64 readBytes, qint64 totalBytes)>(&UrielFtp::updateDataTransferProgressSignal), \
				progressDialog, &ProgressDialog::updateProgressBarValue);
			progressDialog->setTotalProgressBarMax(1);
			if (m_pUrielFtp->downloadFiles(file_path, var)) {
				progressDialog->exec();
				QEventLoop eventloop;
				QTimer::singleShot(100, &eventloop, SLOT(quit()));
				eventloop.exec();
			}
			else {
				QObject::disconnect(m_pUrielFtp, static_cast<void (UrielFtp::*)(qint64 readBytes, qint64 totalBytes)>(&UrielFtp::updateDataTransferProgressSignal), \
					progressDialog, &ProgressDialog::updateProgressBarValue);
				delete progressDialog;
			}
		}
	}
	m_pDatabase->updateResearchProjectDownloadCount(QString::number(item.ID));
	m_pDatabase->updateResearchProjectTableModel(getRP_ResearchProjectFilters());
}

void UrielQtFramework::onRP_ResearchProjectTableViewDoubleClicked(const QModelIndex &index) {
	onResearchProjectPaperDownloadActionTriggered();
}
QString UrielQtFramework::getRP_ResearchProjectFilters() {
	QString str, strSQL = "";

	str = ui.RP_ResearchProjectAuthorCombox->currentText();

	if (!str.isEmpty() && str != QStringLiteral("所有人员"))
	{
		strSQL += " WHERE Participants like '%" + str + "%'";
	}
	str = ui.RP_ResearchProjectYearCombox->currentText();
	str.left(4);
	if (!str.isEmpty() && str != QStringLiteral("全部时间") && !strSQL.isEmpty())
	{
		strSQL += " AND year(EndTime) ='" + str + "'";
	}
	else if (!str.isEmpty() && str != QStringLiteral("全部时间") && strSQL.isEmpty())
	{
		strSQL += " WHERE year(EndTime) ='" + str + "'";
	}
	str = ui.RP_ResearchProjectTitleLineEdit->text();
	if (!str.isEmpty() && !strSQL.isEmpty())
	{
		strSQL += " AND Name  like '%" + str + "%'";
	}
	else if (!str.isEmpty() && strSQL.isEmpty())
	{
		strSQL += " WHERE Name  like '%" + str + "%'";
	}
	return strSQL;
}
void UrielQtFramework::onRP_ResearchProjectAuthorComboxCurrentIndexChanged(int index) {
	m_pDatabase->updateResearchProjectTableModel(getRP_ResearchProjectFilters());
}
void UrielQtFramework::onRP_ResearchProjectYearComboxCurrentIndexChanged(int index) {
	m_pDatabase->updateResearchProjectTableModel(getRP_ResearchProjectFilters());
}
void UrielQtFramework::onRP_ResearchProjectTitleLineEditingFinished() {
	m_pDatabase->updateResearchProjectTableModel(getRP_ResearchProjectFilters());
}

void UrielQtFramework::initializeResourcesUi()
{
	initializeMeetingReportUi();
	initializePaperUi();
	setPaperSignalsAndSlots();
	initializeAcademicConferenceUi();
	setAcademicConferenceSignalsAndSlots();
	initializePatentUi();
	setPatentSignalsAndSlots();
	initializeWorksUi();
	setWorksSignalsAndSlots();
	initializeResearchProjectUi();
	setResearchProjectSignalsAndSlots();
	ui.RP_FileListTreeWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.RP_FileListTreeWidget->setSortingEnabled(true);
	ui.RP_FileListTreeWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.RP_FileListTreeWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
	//ui.RP_FileListTreeWidget->setAlternatingRowColors(true);
	ui.RP_FileListTreeWidget->setMouseTracking(true);
	//QAbstractItemView.SelectionMode.MultiSelection//：多选（无需按ctrl）
	//QAbstractItemView.SelectionMode.ExtendedSelection//：//多选（按住ctrl，一次选一项）
	//QAbstractItemView.SelectionMode.ContiguousSelection//：//多选（一次选多项，相当于window下按住shift选文件）

	ui.RP_FileListTreeWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);//设置为连续选择模式
	ui.RP_FileListTreeWidget->setContextMenuPolicy(Qt::ActionsContextMenu);//设置为action菜单模式
	ui.RP_FileListTreeWidget->sortItems(0, Qt::AscendingOrder);
	//ui.RP_FileListTreeWidget->header()->setSectionResizeMode(QHeaderView::ResizeToContents);

	QAction * FTPDownloadAction{ new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/download01.png"), QStringLiteral("下载"), this) };
	QAction * FTPUploadAction{ new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/uploader.png"), QStringLiteral("上传"), this) };
	QAction * FTPNewFolderAction{ new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/add.png"), QStringLiteral("新建文件夹"), this) };
	QAction * FTPRenameAction{ new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/rename.png"), QStringLiteral("重命名"), this) };
	QAction * FTPdeleteFilesAction{ new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/deletefile.png"), QStringLiteral("删除文件"), this) };
	QAction * FTPDeleteEmptyFolderAction{ new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/delete.png"), QStringLiteral("删除空文件夹"), this) };

	ui.RP_FileListTreeWidget->addAction(FTPDownloadAction);
	ui.RP_FileListTreeWidget->addAction(FTPUploadAction);
	ui.RP_FileListTreeWidget->addAction(FTPNewFolderAction);
	ui.RP_FileListTreeWidget->addAction(FTPRenameAction);
	ui.RP_FileListTreeWidget->addAction(FTPdeleteFilesAction);
	ui.RP_FileListTreeWidget->addAction(FTPDeleteEmptyFolderAction);


	connect(FTPDownloadAction, &QAction::triggered, this, &UrielQtFramework::onRP_DownloadBtnClicked);
	connect(FTPUploadAction, &QAction::triggered, this, &UrielQtFramework::onRP_UploadBtnClicked);
	connect(FTPNewFolderAction, &QAction::triggered, this, &UrielQtFramework::onRP_NewFolderBtnClicked);
	connect(FTPRenameAction, &QAction::triggered, this, &UrielQtFramework::oRP_RenameBtnClicked);
	connect(FTPdeleteFilesAction, &QAction::triggered, this, &UrielQtFramework::oRP_deleteFilesBtnClicked);
	connect(FTPDeleteEmptyFolderAction, &QAction::triggered, this, &UrielQtFramework::onRP_DeleteBtnClicked);

	ui.RP_FileListTreeWidget->setEnabled(false);
	ui.RP_FileListTreeWidget->setRootIsDecorated(false);

	ui.RP_FileListTreeWidget->setHeaderLabels(QStringList() << QStringLiteral("名称") << QStringLiteral("修改日期") << QStringLiteral("类型") << QStringLiteral("大小") );
	QList<int> wdls;
	wdls << 400 << 145 << 145 << 145 << 145 ;
	for (int i = 0; i < wdls.size(); i++)
	{
		ui.RP_FileListTreeWidget->setColumnWidth(i, wdls[i]);
	}
	

	ui.RP_FileListTreeWidget->header()->setStretchLastSection(true);
	QObject::connect(ui.RP_FileListTreeWidget, static_cast<void (QTreeWidget::*)(QTreeWidgetItem*, int)>(&QTreeWidget::itemActivated),
		this, &UrielQtFramework::ftpProcessItem);
	QObject::connect(ui.RP_FileListTreeWidget, static_cast<void (QTreeWidget::*)(QTreeWidgetItem*, QTreeWidgetItem*)>(&QTreeWidget::currentItemChanged),
		this, &UrielQtFramework::ftpEnableDownload);
	
	//ftpConnectOrDisconnect();
	connect(m_pUrielFtp, SIGNAL(addToGuiList(const QUrielUrlInfo&)),
		this, SLOT(ftpAddToList(const QUrielUrlInfo &)));
	connect(m_pUrielFtp, SIGNAL(clearGUIList()),
		this, SLOT(ftpClearFileTreeWidget()));
	connect(m_pUrielFtp, SIGNAL(GUIClear()),
		this, SLOT(FileTreeWidgetClear()));
	connect(m_pUrielFtp, SIGNAL(GUISetCursor()),
		this, SLOT(onGUISetCursor()));
	onRP_RegularMeetingReportBtnClicked();

	ui.RP_PaperPatentBtn->setVisible(false);
	ui.RP_DeviceManualBtn->setVisible(false);
	ui.RP_SDKBtn->setVisible(false);
	ui.RP_GraduateBtn->setVisible(false);
}
#include "UrielGui\ResourcePage\ReportTableView\ReportTableView.h"
void UrielQtFramework::setResourcesSignalsAndSlots()
{
	QObject::connect(ui.RP_ReportTableView, static_cast<void (ReportTableView::*)(QStringList &)>(&ReportTableView::fileNameList),
		this, &UrielQtFramework::onRP_ReportTableViewSignals);
	QObject::connect(ui.RP_ReporterComboBox, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
		this, &UrielQtFramework::onRP_ReporterComboBoxCurrentIndexChanged);
	QObject::connect(ui.RP_UploadTimerComboBox, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
		this, &UrielQtFramework::onRP_UploadTimerComboBoxCurrentIndexChanged);
	QObject::connect(ui.RP_PaperBtn, &QToolButton::clicked, this, &UrielQtFramework::onRP_PaperBtnClicked);
	QObject::connect(ui.RP_AcademicConferenceBtn, &QToolButton::clicked, this, &UrielQtFramework::onRP_AcademicConferenceBtnClicked);
	QObject::connect(ui.RP_PatentBtn, &QToolButton::clicked, this, &UrielQtFramework::onRP_PatentBtnClicked);
	QObject::connect(ui.RP_WorksBtn, &QToolButton::clicked, this, &UrielQtFramework::onRP_WorksBtnClicked);
	QObject::connect(ui.RP_ResearchProjectBtn, &QToolButton::clicked, this, &UrielQtFramework::onRP_ResearchProjectBtnClicked);

	QObject::connect(ui.RP_RegularMeetingReportBtn, &QToolButton::clicked, this, &UrielQtFramework::onRP_RegularMeetingReportBtnClicked);
	QObject::connect(ui.RP_PaperPatentBtn, &QToolButton::clicked, this, &UrielQtFramework::onRP_PaperPatentBtnClicked);
	QObject::connect(ui.RP_DeviceManualBtn, &QToolButton::clicked, this, &UrielQtFramework::onRP_DeviceManualBtnClicked);
	QObject::connect(ui.RP_SDKBtn, &QToolButton::clicked, this, &UrielQtFramework::onRP_SDKBtnClicked);
	QObject::connect(ui.RP_GraduateBtn, &QToolButton::clicked, this, &UrielQtFramework::onRP_GraduateBtnClicked);
	QObject::connect(ui.RP_OtherBtn, &QToolButton::clicked, this, &UrielQtFramework::onRP_OtherBtnClicked); 
	QObject::connect(ui.RP_MyFileBtn, &QToolButton::clicked, this, &UrielQtFramework::onRP_MyFileBtnClicked);
	QObject::connect(ui.RP_NewFolderBtn, &QToolButton::clicked, this, &UrielQtFramework::onRP_NewFolderBtnClicked);
	QObject::connect(ui.RP_DeleteBtn, &QToolButton::clicked, this, &UrielQtFramework::onRP_DeleteBtnClicked);
	QObject::connect(ui.RP_UploadBtn, &QToolButton::clicked, this, &UrielQtFramework::onRP_UploadBtnClicked); 
	QObject::connect(ui.RP_DownloadBtn, &QToolButton::clicked, this, &UrielQtFramework::onRP_DownloadBtnClicked); 
	QObject::connect(ui.RP_deleteFilesBtn, &QToolButton::clicked, this, &UrielQtFramework::oRP_deleteFilesBtnClicked);
	QObject::connect(ui.RP_RenameBtn, &QToolButton::clicked, this, &UrielQtFramework::oRP_RenameBtnClicked);
}
void UrielQtFramework::onRP_RegularMeetingReportBtnClicked() {
	ui.ResourceStackedWidget->setCurrentIndex(0);
}

void UrielQtFramework::onRP_PaperBtnClicked() {
	ui.ResourceStackedWidget->setCurrentIndex(1);
}

void UrielQtFramework::onRP_AcademicConferenceBtnClicked() {
	ui.ResourceStackedWidget->setCurrentIndex(2);
}
void UrielQtFramework::onRP_PatentBtnClicked() {
	ui.ResourceStackedWidget->setCurrentIndex(3);
}
void UrielQtFramework::onRP_WorksBtnClicked() {
	ui.ResourceStackedWidget->setCurrentIndex(4);
}
void UrielQtFramework::onRP_ResearchProjectBtnClicked() {
	ui.ResourceStackedWidget->setCurrentIndex(5);
}

void UrielQtFramework::onRP_OtherBtnClicked() {
	ui.ResourceStackedWidget->setCurrentIndex(6);
	ui.RP_TitelLabel->setText(QStringLiteral("其他"));
	ui.label_95->setPixmap(QPixmap(":/Mainwindow/Resources/UrielQtFramework/other.png"));
	m_pUrielFtp->cdToSpecifiedPath(m_pUrielFtp->getRootPath());
}

void UrielQtFramework::ftpClearFileTreeWidget() {
	QHash<QString, bool> isDirectory= m_pUrielFtp-> getDirInfo();
	if (isDirectory.isEmpty()) {
		ui.RP_FileListTreeWidget->addTopLevelItem(new QTreeWidgetItem(QStringList() << tr("<empty>")));
		ui.RP_FileListTreeWidget->setEnabled(false);
	}
}

void UrielQtFramework::FileTreeWidgetClear() {
	ui.RP_FileListTreeWidget->clear();
}

void  UrielQtFramework::ftpProcessItem(QTreeWidgetItem *item, int column) {
	QString name = item->text(0);
	QHash<QString, bool> isDirectory = m_pUrielFtp->getDirInfo();
	if (isDirectory.value(name)) {
		ui.RP_FileListTreeWidget->clear();
		m_pUrielFtp->clearisDirectory();
		m_pUrielFtp->cdToNextPath(name);
		/*QString currentPath = m_pUrielFtp->getCurrentPath();
		currentPath += '/';
		currentPath += name;*/
	//	m_pUrielFtp->cdToSpecifiedPath(QStringLiteral("H:\\UrielFTPServer\LaboratoryResource\LaboratoryFile\例会报告\实验室例会"));
		//m_pUrielFtp->cd(currentPath);
		//m_pUrielFtp->cd(_ToSpecialEncoding(currentPath));
		//m_pUrielFtp->list();
#ifndef QT_NO_CURSOR
		setCursor(Qt::WaitCursor);
#endif
		return;
	}
}

void UrielQtFramework::onGUISetCursor() {
#ifndef QT_NO_CURSOR
	setCursor(Qt::ArrowCursor);
#endif
}
void UrielQtFramework::ftpEnableDownload(QTreeWidgetItem*, QTreeWidgetItem*) {
	/*QTreeWidgetItem *current = ui.RP_FileListTreeWidget->currentItem();
	if (current) {
		QString currentFile = current->text(0);
		FTPCancelDownloadAction->setEnabled(!isDirectory.value(currentFile));
	}
	else {
		FTPCancelDownloadAction->setEnabled(false);
	}*/
}

void UrielQtFramework::onRP_NewFolderBtnClicked() {
	InputDialog dlg(QStringLiteral("请输入新建文件夹名称"), this);
	QObject::connect(&dlg, static_cast<void (InputDialog::*)(const QString & value)>(&InputDialog::contentSignal), [&](const QString & value)
	{
		m_pUrielFtp->mkdir(m_pUrielFtp->getCurrentPath() + "/" + value);
	});
	dlg.exec();
	
}

void UrielQtFramework::oRP_RenameBtnClicked() {
	InputDialog dlg(QStringLiteral("请输入要修改的文件或者文件夹名称"), this);
	QObject::connect(&dlg, static_cast<void (InputDialog::*)(const QString & value)>(&InputDialog::contentSignal), [&](const QString & value)
	{
		m_pUrielFtp->rename(m_pUrielFtp->getCurrentPath() + "/" + ui.RP_FileListTreeWidget->currentItem()->text(0),\
			m_pUrielFtp->getCurrentPath() + "/" +value);
	});
	dlg.exec();
}
void UrielQtFramework::onRP_DeleteBtnClicked() {
	m_pUrielFtp->rmdir(m_pUrielFtp->getCurrentPath() + "/" + ui.RP_FileListTreeWidget->currentItem()->text(0));
}

void UrielQtFramework::oRP_deleteFilesBtnClicked() {
	m_pUrielFtp->Remove(m_pUrielFtp->getCurrentPath() + "/" + ui.RP_FileListTreeWidget->currentItem()->text(0));
}
void UrielQtFramework::onRP_UploadBtnClicked() {
	ProgressDialog *progressDialog = new ProgressDialog(this);
	QObject::connect(m_pUrielFtp, static_cast<void (UrielFtp::*)(qint64 readBytes, qint64 totalBytes)>(&UrielFtp::updateDataTransferProgressSignal), \
		progressDialog, &ProgressDialog::updateProgressBarValue);
	QFileDialog::Options options;
	QString selectedFilter;
	QDir dir;
	QStringList fileNames = QFileDialog::getOpenFileNames(nullptr,
		QStringLiteral("选择文件"),
		dir.absolutePath(),
		tr("All Files (*.*);;zip Files (*.zip);;ISO Files (*.iso)"),
		&selectedFilter,
		options);
	//progressDialog->setCurrentTotalValue(1);
	int i = 1;
	progressDialog->setTotalProgressBarMax(fileNames.size()/*(ui.RP_FileListTreeWidget->currentItem()->text(3).split("K")[0].toInt() * 1024)*/);
	for each (QString var in fileNames)
	{
		progressDialog->setCurrentTotalValue(i++);
		m_pUrielFtp->uploadFile(var);
	}

	//m_pUrielFtp->uploadFiles();
	progressDialog->exec();

	
}
void UrielQtFramework::onRP_DownloadBtnClicked() {
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//QString file_path = QFileDialog::getExistingDirectory(nullptr, QStringLiteral("请选择文件保存路径..."), "./");
	//ProgressDialog *progressDialog = new ProgressDialog(this);
	//progressDialog->setTotalProgressBarMax(1/*(ui.RP_FileListTreeWidget->currentItem()->text(3).split("K")[0].toInt() * 1024)*/);
	//QObject::connect(m_pUrielFtp, static_cast<void (UrielFtp::*)(qint64 readBytes, qint64 totalBytes)>(&UrielFtp::updateDataTransferProgressSignal), \
	//		progressDialog, &ProgressDialog::updateProgressBarValue);
	//progressDialog->setTotalProgressBarMax(1);
	//m_pUrielFtp->downloadFiles(file_path, m_pUrielFtp->getCurrentPath() + "/" + ui.RP_FileListTreeWidget->currentItem()->text(0));
	////m_pUrielFtp->downloadFile(m_pUrielFtp->getCurrentPath() + "/" + ui.RP_FileListTreeWidget->currentItem()->text(0));
	//progressDialog->exec();
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	QString file_path = QFileDialog::getExistingDirectory(nullptr, QStringLiteral("请选择文件保存路径..."), "./");
	QList<QTreeWidgetItem*> selectedItemList = ui.RP_FileListTreeWidget->selectedItems();
	for each (QTreeWidgetItem* var in selectedItemList)
	{
		ProgressDialog *progressDialog = new ProgressDialog(this);
		progressDialog->setTotalProgressBarMax(1/*(ui.RP_FileListTreeWidget->currentItem()->text(3).split("K")[0].toInt() * 1024)*/);
		QObject::connect(m_pUrielFtp, static_cast<void (UrielFtp::*)(qint64 readBytes, qint64 totalBytes)>(&UrielFtp::updateDataTransferProgressSignal), \
						progressDialog, &ProgressDialog::updateProgressBarValue);
		progressDialog->setTotalProgressBarMax(1);
		if (m_pUrielFtp->downloadFiles(file_path, m_pUrielFtp->getCurrentPath() + "/" + var->text(0))) {
			progressDialog->exec();
			QEventLoop eventloop;
			QTimer::singleShot(100, &eventloop, SLOT(quit()));
			eventloop.exec();
		}
		else {
			QObject::disconnect(m_pUrielFtp, static_cast<void (UrielFtp::*)(qint64 readBytes, qint64 totalBytes)>(&UrielFtp::updateDataTransferProgressSignal), \
				progressDialog, &ProgressDialog::updateProgressBarValue);
			delete progressDialog;
		}
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//QItemSelectionModel *selections = ui.RP_FileListTreeWidget->selectionModel();
	//QModelIndexList selectedIndexs = selections->selectedIndexes();
	//foreach(QModelIndex index, selectedIndexs)
	//{
	//	QModelIndex idx = index.sibling(index.row(), 0);
	//	if (index.isValid())
	//	{
	//		//ProgressDialog *progressDialog = new ProgressDialog(this);
	//		//progressDialog->setTotalProgressBarMax(1/*(ui.RP_FileListTreeWidget->currentItem()->text(3).split("K")[0].toInt() * 1024)*/);
	//		//QObject::connect(m_pUrielFtp, static_cast<void (UrielFtp::*)(qint64 readBytes, qint64 totalBytes)>(&UrielFtp::updateDataTransferProgressSignal), \
	//		//	progressDialog, &ProgressDialog::updateProgressBarValue);
	//		//progressDialog->setTotalProgressBarMax(1);
	//		//m_pUrielFtp->downloadFiles(file_path, m_pUrielFtp->getCurrentPath() + "/" + index.data().toString());
	//		//progressDialog->exec();
	//	}
	//}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//QString file_path = QFileDialog::getExistingDirectory(nullptr, QStringLiteral("请选择文件保存路径..."), "./");
	//ProgressDialog *progressDialog = new ProgressDialog(this);
	//progressDialog->setTotalProgressBarMax(1/*(ui.RP_FileListTreeWidget->currentItem()->text(3).split("K")[0].toInt() * 1024)*/);
	//QObject::connect(m_pUrielFtp, static_cast<void (UrielFtp::*)(qint64 readBytes, qint64 totalBytes)>(&UrielFtp::updateDataTransferProgressSignal), \
	//	progressDialog, &ProgressDialog::updateProgressBarValue);
	//

	//QItemSelectionModel *selections = ui.RP_FileListTreeWidget->selectionModel();
	//QModelIndexList selectedIndexs = selections->selectedIndexes();
	//QMap <int, int> rowMap;

	//int i = 1;
	//progressDialog->setTotalProgressBarMax(selectedIndexs.size()/*(ui.RP_FileListTreeWidget->currentItem()->text(3).split("K")[0].toInt() * 1024)*/);
	//progressDialog->exec();
	//foreach(QModelIndex index, selectedIndexs)
	//{
	//	if (index.isValid())
	//	{
	//		QModelIndex idx = index.sibling(index.row(), 0);//id
	//		if (idx.isValid()) {
	//			progressDialog->setCurrentTotalValue(i++);
	//			m_pUrielFtp->downloadFiles(file_path,m_pUrielFtp->getCurrentPath() + "/" + idx.data().toString());
	//		}
	//	}

	//}
}

void UrielQtFramework::ftpAddToList(const QUrielUrlInfo &urlInfo)
{
	QTreeWidgetItem *item = new QTreeWidgetItem;
	item->setText(0, _FromSpecialEncoding(urlInfo.name()));
	item->setText(1, urlInfo.lastModified().toString("MMM dd yyyy"));
	item->setText(2, urlInfo.isDir()?QStringLiteral("文件夹"): QStringLiteral("文件"));
	item->setText(3, urlInfo.isDir()?"":QString::number(urlInfo.size()/1024)+"KB");
	//item->setText(4, urlInfo.owner());
	//item->setText(4, urlInfo.group());
	
	QPixmap pixmap;
	if (urlInfo.isDir())
		pixmap = QPixmap(":/new/FileSuffix/Resources/filesuffix/dir.png");
	else {
		QString file_suffix = QFileInfo(urlInfo.name()).suffix();
		if(file_suffix=="ppt"|| file_suffix == "pptx"|| file_suffix == "pptm" || file_suffix == "ppsx" || file_suffix == "potx" || file_suffix == "potm" || file_suffix == "ppsx")
			pixmap = QPixmap(":/new/FileSuffix/Resources/filesuffix/ppt.png");
		else if (file_suffix == "xls" || file_suffix == "xlsx" || file_suffix == "xlsm"|| file_suffix == "xltx" || file_suffix == "xltm" || file_suffix == "xlsb" || file_suffix == "xlam")
			pixmap = QPixmap(":/new/FileSuffix/Resources/filesuffix/excel.png");
		else if (file_suffix == "doc" || file_suffix == "docx" || file_suffix == "docm" || file_suffix == "dotx" || file_suffix == "dotm" )
			pixmap = QPixmap(":/new/FileSuffix/Resources/filesuffix/word.png");
		else if (file_suffix == "pdf")
			pixmap = QPixmap(":/new/FileSuffix/Resources/filesuffix/pdf.png");
		else if (file_suffix == "c" || file_suffix == "cpp" || file_suffix == "h" || file_suffix == "py" || file_suffix == "cs" || file_suffix == "php" || file_suffix == "cs")
			pixmap = QPixmap(":/new/FileSuffix/Resources/filesuffix/code.png");
		else if (file_suffix == "exe" || file_suffix == "msi" )
			pixmap = QPixmap(":/new/FileSuffix/Resources/filesuffix/exe.png");
		else if (file_suffix == "html" || file_suffix == "htm" || file_suffix == "xhtml" || file_suffix == "asp" || file_suffix == "aspx" || file_suffix == "jsp")
			pixmap = QPixmap(":/new/FileSuffix/Resources/filesuffix/html.png");
		else if (file_suffix == "jpg" || file_suffix == "png" || file_suffix == "jpge" || file_suffix == "bmp" || file_suffix == "gif" || file_suffix == "svg")
			pixmap = QPixmap(":/new/FileSuffix/Resources/filesuffix/image.png");
		else if (file_suffix == "iso" || file_suffix == "gho")
			pixmap = QPixmap(":/new/FileSuffix/Resources/filesuffix/iso.png");
		else if (file_suffix == "avi" || file_suffix == "rm" || file_suffix == "rmvb" || file_suffix == "mp4" || file_suffix == "mov" || file_suffix == "qt" || file_suffix == "wmv")
			pixmap = QPixmap(":/new/FileSuffix/Resources/filesuffix/mov.png");
		else if (file_suffix == "mp3" || file_suffix == "wma" || file_suffix == "wav" || file_suffix == "asf")
			pixmap = QPixmap(":/new/FileSuffix/Resources/filesuffix/mp3.png");
		else if (file_suffix == "zip" || file_suffix == "rar" || file_suffix == "tar.gz" || file_suffix == "tar")
			pixmap = QPixmap(":/new/FileSuffix/Resources/filesuffix/rar.png");
		else if (file_suffix == "sys" || file_suffix == "dll")
			pixmap = QPixmap(":/new/FileSuffix/Resources/filesuffix/sys.png");
		else if (file_suffix == "txt")
			pixmap = QPixmap(":/new/FileSuffix/Resources/filesuffix/txt.png");
		else if (file_suffix == "txt")
			pixmap = QPixmap(":/new/FileSuffix/Resources/filesuffix/txt.png");
		else
			pixmap = QPixmap(":/Mainwindow/Resources/UrielQtFramework/file01.png");
	}
	
	
	//QPixmap pixmap(urlInfo.isDir() ? ":/Mainwindow/Resources/UrielQtFramework/dir.png" : ":/Mainwindow/Resources/UrielQtFramework/file01.png");
	item->setIcon(0, pixmap);

	//m_bIsDirectory[urlInfo.name()] = urlInfo.isDir();
	ui.RP_FileListTreeWidget->addTopLevelItem(item);
	if (!ui.RP_FileListTreeWidget->currentItem()) {
		ui.RP_FileListTreeWidget->setCurrentItem(ui.RP_FileListTreeWidget->topLevelItem(0));
		ui.RP_FileListTreeWidget->setEnabled(true);
	}
	
}
//urielFtp->mkdir(urielFtp->getRootPath() + "/Invoice/" + m_options->getAccount() + "/" + QDateTime::currentDateTime().toString("yyyy_MM_dd"));
//有FTP端编码转本地编码
QString UrielQtFramework::_FromSpecialEncoding(const QString &InputStr)
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
}
//put get等上传文件时，转换为FTP端编码
QString UrielQtFramework::_ToSpecialEncoding(const QString &InputStr)
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
}

//void UrielQtFramework::onRP_RegularMeetingReportBtnClicked() {
//	ui.ResourceStackedWidget->setCurrentIndex(0);
//	ui.RP_TitelLabel->setText(QStringLiteral("例会报告"));
//	ui.label_95->setPixmap(QPixmap(":/Mainwindow/Resources/UrielQtFramework/report.png"));
//	m_pUrielFtp->cdToSpecifiedPath(m_pUrielFtp->getRootPath() + QStringLiteral("/LaboratoryFile/%0").arg(QStringLiteral("例会报告")));
//}
void UrielQtFramework::onRP_PaperPatentBtnClicked() {
	ui.RP_TitelLabel->setText(QStringLiteral("论文专利"));
	ui.label_95->setPixmap(QPixmap(":/Mainwindow/Resources/UrielQtFramework/paper.png"));
	m_pUrielFtp->cdToSpecifiedPath(m_pUrielFtp->getRootPath() + QStringLiteral("/LaboratoryFile/%0").arg(QStringLiteral("论文专利")));
}
void UrielQtFramework::onRP_DeviceManualBtnClicked() {
	ui.RP_TitelLabel->setText(QStringLiteral("设备说明书"));
	ui.label_95->setPixmap(QPixmap(":/Mainwindow/Resources/UrielQtFramework/manual.png"));
	m_pUrielFtp->cdToSpecifiedPath(m_pUrielFtp->getRootPath() + QStringLiteral("/LaboratoryFile/%0").arg(QStringLiteral("设备说明书")));
}
void UrielQtFramework::onRP_SDKBtnClicked() {
	ui.RP_TitelLabel->setText(QStringLiteral("软件开发包"));
	ui.label_95->setPixmap(QPixmap(":/Mainwindow/Resources/UrielQtFramework/sdk.png"));
	m_pUrielFtp->cdToSpecifiedPath(m_pUrielFtp->getRootPath() + QStringLiteral("/LaboratoryFile/%0").arg(QStringLiteral("软件开发包")));
}
void UrielQtFramework::onRP_GraduateBtnClicked() {
	ui.RP_TitelLabel->setText(QStringLiteral("毕业生资料"));
	ui.label_95->setPixmap(QPixmap(":/Mainwindow/Resources/UrielQtFramework/GraduateRes.png"));
	m_pUrielFtp->cdToSpecifiedPath(m_pUrielFtp->getRootPath() + QStringLiteral("/LaboratoryFile/%0").arg(QStringLiteral("毕业生资料")));
}

void UrielQtFramework::onRP_MyFileBtnClicked() {
	ui.RP_TitelLabel->setText(QStringLiteral("个人文件"));
}
#pragma endregion

#pragma region Statistics
void UrielQtFramework::initializeStatisticsUi()
{
	onSP_UserCountBtnClicked();
	ui.SP_OtherBtn->setVisible(false);
}
void UrielQtFramework::setStatisticsSignalsAndSlots()
{
	QObject::connect(ui.SP_UserCountBtn, &QToolButton::clicked, this, &UrielQtFramework::onSP_UserCountBtnClicked);
	QObject::connect(ui.SP_LeaveInfoBtn, &QToolButton::clicked, this, &UrielQtFramework::onSP_LeaveInfoBtnClicked); 
	QObject::connect(ui.SP_FilterSearchPBtn, &QToolButton::clicked, this, &UrielQtFramework::onSP_FilterSearchPBtnClicked); 
	QObject::connect(ui.SP_AccountDeleteBtn, &QToolButton::clicked, this, &UrielQtFramework::onSP_AccountDeleteBtnClicked);
	QObject::connect(ui.SP_AccountSearch, &QPushButton::clicked, this, &UrielQtFramework::onSP_AccountSearchPBtnClicked);
	QObject::connect(ui.SP_AccountUserName, &QLineEdit::returnPressed, this, &UrielQtFramework::onSP_AccountUserNameReturnPressed);
	QObject::connect(ui.SP_AccountStudentNumber, &QLineEdit::returnPressed, this, &UrielQtFramework::onSP_AccountStudentNumberReturnPressed);
	QObject::connect(ui.SP_AccountProjectCombox, static_cast<void (QComboBox::*)(const QString &)>(&QComboBox::currentTextChanged), this, &UrielQtFramework::onSP_AccountProjectComboxCurrentTextChanged);
}


void UrielQtFramework::onSP_UserCountBtnClicked() {
	ui.StatisticsStackedWidget->setCurrentIndex(0);
	ui.SP_UserCountModelTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.SP_UserCountModelTableView->setSortingEnabled(true);
	ui.SP_UserCountModelTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.SP_UserCountModelTableView->setShowGrid(true);
	ui.SP_UserCountModelTableView->verticalHeader()->setVisible(false);
	ui.SP_UserCountModelTableView->setAlternatingRowColors(true);
	ui.SP_UserCountModelTableView->setMouseTracking(true);
	ui.SP_UserCountModelTableView->setSelectionMode(QAbstractItemView::SingleSelection);//设置为连续选择模式
	ui.SP_UserCountModelTableView->setContextMenuPolicy(Qt::ActionsContextMenu);//设置为action菜单模式

	m_UrielUserCountTableModel = m_pDatabase->creatUserCountTableModel();
	m_pUrielUserCountTableSortFilterModel = new QSortFilterProxyModel;
	m_pUrielUserCountTableSortFilterModel->setDynamicSortFilter(true);
	m_pUrielUserCountTableSortFilterModel->setSourceModel(m_UrielUserCountTableModel);
	ui.SP_UserCountModelTableView->setModel(m_pUrielUserCountTableSortFilterModel);
	//ui.SP_UserCountModelTableView->setColumnHidden(0, true);
	//ID,ReimburseCode,Type,Name,Model,Quantity,Unit,Univalent,AggregateAmount,Description,InvoiceImagePath,BuyScreenshotPath,VerificationImagePath,ReimbursePerson,ReimburseTime,FilingState,Remark
	QList<int> wdls;
	//ID, NAME, SCHOOL_WORK_NUMBER, EMAIL, PHONE_NUMBER, BANK_TYPE, BANK_CARD_NUMBER, PROJECT_TEAM, APPLY_TIME
	wdls << 40 << 80 << 100 << 180 << 120 << 60 << 200 << 300 << 120;
	for (int i = 0; i < wdls.size(); i++)
	{
		ui.SP_UserCountModelTableView->setColumnWidth(i, wdls[i]);
	}

	QStringList ProjectList;
	m_pDatabase->getAllProjectListByAccount(ProjectList);
	ui.SP_AccountProjectCombox->clear();
	ui.SP_AccountProjectCombox->addItem("");
	ui.SP_AccountProjectCombox->addItems(ProjectList);
	ui.SP_AccountProjectCombox->setCurrentIndex(0);
	m_pDatabase->updateUserCountTableModel();
}

QString  UrielQtFramework::getSPAccountFilters() {
	QString str, strSQL = "";

	str = ui.SP_AccountUserName->text();

	if (!str.isEmpty())
	{
		strSQL += " WHERE NAME like '%" + str + "%'";
	}
	str = ui.SP_AccountStudentNumber->text();
	str.left(4);
	if (!str.isEmpty() && !strSQL.isEmpty())
	{
		strSQL += " AND SCHOOL_WORK_NUMBER like '%" + str + "%'";
	}
	else if (!str.isEmpty() && strSQL.isEmpty())
	{
		strSQL += " WHERE SCHOOL_WORK_NUMBER like '%" + str + "%'";
	}
	str = ui.SP_AccountProjectCombox->currentText();
	if (!str.isEmpty() && !strSQL.isEmpty())
	{
		strSQL += " AND PROJECT_TEAM  like '%" + str + "%'";
	}
	else if (!str.isEmpty() && strSQL.isEmpty())
	{
		strSQL += " WHERE PROJECT_TEAM  like '%" + str + "%'";
	}
	return strSQL;
}

void UrielQtFramework::onSP_AccountDeleteBtnClicked() {
	sUrielAccountInfo account;
	m_pDatabase->getUserAccount(account, m_pOptions->getAccount());
	if (account.m_sPermision == "regular user") {
		CriticalDialog dlg(QStringLiteral("无权限"), QStringLiteral("非管理员账号，不能删除账号信息！"), this);
		dlg.exec();
		return;
	}
	InformationDialog information(QStringLiteral("信息"), QStringLiteral("确定删除该账号么？"), this);
	if (information.exec() == QDialog::Accepted) {
		QModelIndex index = ui.SP_UserCountModelTableView->currentIndex();
		if (index.isValid())
		{
			int mIndex = index.row();
			QModelIndex idx = index.sibling(mIndex, 0); //ID
			if (idx.isValid())
			{
				m_pDatabase->deleteUserAccountByID(idx.data().toString());
				m_pDatabase->updateUserCountTableModel(getSPAccountFilters());
			}
		}
	}
}

void UrielQtFramework::onSP_AccountUserNameReturnPressed() {
	m_pDatabase->updateUserCountTableModel(getSPAccountFilters());
}
void UrielQtFramework::onSP_AccountStudentNumberReturnPressed() {
	m_pDatabase->updateUserCountTableModel(getSPAccountFilters());
}
void UrielQtFramework::onSP_AccountProjectComboxCurrentTextChanged(const QString &) {
	m_pDatabase->updateUserCountTableModel(getSPAccountFilters());
}

void UrielQtFramework::onSP_AccountSearchPBtnClicked() {
	m_pDatabase->updateUserCountTableModel(getSPAccountFilters());
}


void UrielQtFramework::onSP_LeaveInfoBtnClicked() {
	ui.StatisticsStackedWidget->setCurrentIndex(1);
	ui.SP_LeaveInfoModelTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.SP_LeaveInfoModelTableView->setSortingEnabled(true);
	ui.SP_LeaveInfoModelTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.SP_LeaveInfoModelTableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
	ui.SP_LeaveInfoModelTableView->setShowGrid(true);
	ui.SP_LeaveInfoModelTableView->verticalHeader()->setVisible(false);
	ui.SP_LeaveInfoModelTableView->setAlternatingRowColors(true);
	ui.SP_LeaveInfoModelTableView->setMouseTracking(true);
	ui.SP_LeaveInfoModelTableView->setSelectionMode(QAbstractItemView::ContiguousSelection);//设置为连续选择模式
	ui.SP_LeaveInfoModelTableView->setContextMenuPolicy(Qt::ActionsContextMenu);//设置为action菜单模式

	m_UrielLeaveInfoTableModel = m_pDatabase->creatLeaveInfoTableModel();
	m_pUrielLeaveInfoTableSortFilterModel = new QSortFilterProxyModel;
	m_pUrielLeaveInfoTableSortFilterModel->setDynamicSortFilter(true);
	m_pUrielLeaveInfoTableSortFilterModel->setSourceModel(m_UrielLeaveInfoTableModel);
	ui.SP_LeaveInfoModelTableView->setModel(m_pUrielLeaveInfoTableSortFilterModel);
	//ui.SP_LeaveInfoModelTableView->setColumnHidden(0, true);
	//ID,ReimburseCode,Type,Name,Model,Quantity,Unit,Univalent,AggregateAmount,Description,InvoiceImagePath,BuyScreenshotPath,VerificationImagePath,ReimbursePerson,ReimburseTime,FilingState,Remark
	QList<int> spwdls;
	//ID,Type,ApplyPerson,EventName,Descripation,ApplyTime,StartTime,EndTime,AuditState,Auditor,AuditorSuggest,AuditTime
	spwdls << 40 << 80 << 80 << 80 << 200 << 100 << 100 << 100 << 80 << 60 << 100 << 100;
	for (int i = 0; i < spwdls.size(); i++)
	{
		ui.SP_LeaveInfoModelTableView->setColumnWidth(i, spwdls[i]);
	}
	QStringList userList;
	m_pDatabase->getAllUserName(userList);
	ui.SP_UserCombox->clear();
	ui.SP_UserCombox->addItem(QStringLiteral("所有人员"));
	ui.SP_UserCombox->addItems(userList);
	ui.SP_YearMonthDateEdit->setDateTime(QDateTime::currentDateTime());
	ui.SP_PublicHolidaysCheckBox->setChecked(false);
	m_pDatabase->updateLeaveInfoTableModel(getSPLeaveInfoFilters());

	
}

void UrielQtFramework::onSP_FilterSearchPBtnClicked() {
	if (m_pDatabase)
	{
		m_pDatabase->updateLeaveInfoTableModel(getSPLeaveInfoFilters());
	}
}

QString UrielQtFramework::getSPLeaveInfoFilters()
{
	QString str, strSQL = "";

	str = ui.SP_UserCombox->currentText();

	if (!str.isEmpty()&& str!= QStringLiteral("所有人员"))
	{
		strSQL += " WHERE ApplyPerson like '%" + str + "%'";
	}
	str = ui.SP_YearMonthDateEdit->date().toString("yyyy-MM");

	if (!str.isEmpty() && !strSQL.isEmpty())
	{
		strSQL += " AND StartTime like '%" + str + "%'";
	}
	else if (!str.isEmpty() && strSQL.isEmpty())
	{
		strSQL += " WHERE StartTime like '%" + str + "%'";
	}
	
	if (ui.SP_PublicHolidaysCheckBox->isChecked())
		str = "";
	else
		str = QStringLiteral("Personal");
	if (!str.isEmpty() && !strSQL.isEmpty())
	{
		strSQL += " AND Type = '" + str + "'";
	}
	else if (!str.isEmpty() && strSQL.isEmpty())
	{
		strSQL += " WHERE Type = '" + str + "'";
	}
	return strSQL;
}


#pragma endregion

#pragma region Todo
void UrielQtFramework::initializeTodoUi() {
	queryAndUpdateNumberOfUnprocessedEvents(true);
	onTP_NewUserApplyBtnClicked();
}

void UrielQtFramework::setTodoSignalsAndSlots() {
	QObject::connect(ui.TP_NewUserApplyBtn, &QToolButton::clicked, this, &UrielQtFramework::onTP_NewUserApplyBtnClicked);
	QObject::connect(ui.TP_MaterialPurchaseApplyBtn, &QToolButton::clicked, this, &UrielQtFramework::onTP_MaterialPurchaseApplyBtnClicked);
	QObject::connect(ui.TP_LeaveApplyBtn, &QToolButton::clicked, this, &UrielQtFramework::onTP_LeaveApplyBtnClicked);

	QObject::connect(ui.TP_NewUserAllPassTBtn, &QToolButton::clicked, this, &UrielQtFramework::onTP_NewUserAllPassTBtnClicked);
	QObject::connect(ui.TP_NewUserSinglePassTBtn, &QToolButton::clicked, this, &UrielQtFramework::onTP_NewUserSinglePassTBtnClicked);
	QObject::connect(ui.TP_NewUserRejectTBtn, &QToolButton::clicked, this, &UrielQtFramework::onTP_NewUserRejectTBtnClicked);

	QObject::connect(ui.TP_MaterialPurchaseAllPassTBtn, &QToolButton::clicked, this, &UrielQtFramework::onTP_MaterialPurchaseAllPassTBtnClicked);
	QObject::connect(ui.TP_MaterialPurchaseRejectTBtn, &QToolButton::clicked, this, &UrielQtFramework::onTP_MaterialPurchaseRejectTBtnClicked);
	QObject::connect(ui.TP_MaterialPurchaseSinglePassTBtn, &QToolButton::clicked, this, &UrielQtFramework::onTP_MaterialPurchaseSinglePassTBtnClicked);

	QObject::connect(ui.TP_LeaveAllPassTBtn, &QToolButton::clicked, this, &UrielQtFramework::onTP_LeaveAllPassTBtnClicked);
	QObject::connect(ui.TP_LeaveRejectTBtn, &QToolButton::clicked, this, &UrielQtFramework::onTP_LeaveRejectTBtnClicked);
	QObject::connect(ui.TP_LeaveSinglePassTBtn, &QToolButton::clicked, this, &UrielQtFramework::onTP_LeaveSinglePassTBtnClicked);
}

void UrielQtFramework::queryAndUpdateNumberOfUnprocessedEvents(bool show) {
	int UnAuditedUserAccountNumber = m_pDatabase->getNumberOfUnAuditedAccount();
	int UnAuditedLeaveApplyNumber = m_pDatabase->getNumberOfUnAuditedLeaveApply();
	int UnAuditedMaterialPurchaseApplyNumber = m_pDatabase->getNumberOfUnAuditedMaterialPurchaseApply();
	if (UnAuditedUserAccountNumber > 0) 
		ui.TP_NewUserApplyTip->setIcon(QIcon(":/Mainwindow/Resources/UrielQtFramework/something.png"));
	else
		ui.TP_NewUserApplyTip->setIcon(QIcon(":/Mainwindow/Resources/UrielQtFramework/nothing.png"));
	if (UnAuditedMaterialPurchaseApplyNumber > 0) 
		ui.TP_MaterialPurchaseApplyTip->setIcon(QIcon(":/Mainwindow/Resources/UrielQtFramework/something.png"));
	else
		ui.TP_MaterialPurchaseApplyTip->setIcon(QIcon(":/Mainwindow/Resources/UrielQtFramework/nothing.png"));
	if (UnAuditedLeaveApplyNumber > 0) 
		ui.TP_LeaveApplyTip->setIcon(QIcon(":/Mainwindow/Resources/UrielQtFramework/something.png"));
	else
		ui.TP_LeaveApplyTip->setIcon(QIcon(":/Mainwindow/Resources/UrielQtFramework/nothing.png"));
	if (show) {
		QSystemTrayIcon *trayIcon = new QSystemTrayIcon();
		QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon(0);
		if (QSystemTrayIcon::isSystemTrayAvailable()) {
			trayIcon->setIcon(QIcon(":/Mainwindow/Resources/UrielQtFramework/applogo.png"));
			trayIcon->show();
			trayIcon->showMessage(QStringLiteral("待办事宜"), QStringLiteral("新用户申请+%0\n材料购买申请+%1\n请假申请+%2")
				.arg(UnAuditedUserAccountNumber).arg(UnAuditedMaterialPurchaseApplyNumber).arg(UnAuditedLeaveApplyNumber), icon);
			trayIcon->hide();
		}
	}
}

void UrielQtFramework::onTP_NewUserApplyBtnClicked() {
	ui.TP_StackedWidget->setCurrentIndex(0);

	ui.TP_NewUserApplyTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.TP_NewUserApplyTableView->setSortingEnabled(true);
	ui.TP_NewUserApplyTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.TP_NewUserApplyTableView->setShowGrid(true);
	ui.TP_NewUserApplyTableView->verticalHeader()->setVisible(false);
	ui.TP_NewUserApplyTableView->setAlternatingRowColors(true);
	ui.TP_NewUserApplyTableView->setMouseTracking(true);
	//ui.TP_NewUserApplyTableView->setSelectionMode(QAbstractItemView::ContiguousSelection);//设置为连续选择模式
	ui.TP_NewUserApplyTableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
	ui.TP_NewUserApplyTableView->setContextMenuPolicy(Qt::ActionsContextMenu);//设置为action菜单模式

	ui.TP_NewUserApplyTableView->addAction(NewUserApplyPassAction);
	ui.TP_NewUserApplyTableView->addAction(NewUserApplyRejectAction);

	connect(NewUserApplyPassAction, &QAction::triggered, this, &UrielQtFramework::onNewUserApplyPassActionTriggered);
	connect(NewUserApplyRejectAction, &QAction::triggered, this, &UrielQtFramework::onNewUserApplyRejectActionTriggered);
	
	//connect(ui.TP_NewUserApplyTableView, static_cast<void (QTableView::*)(const QModelIndex &)>(&QTableView::doubleClicked), this, &UrielQtFramework::onDP_InstrumentTableViewDoubleClicked);

	m_UrielNewUserApplyTableModel = m_pDatabase->creatNewUserApplyTableModel();
	m_pUrielNewUserApplyTableSortFilterModel = new QSortFilterProxyModel;
	m_pUrielNewUserApplyTableSortFilterModel->setDynamicSortFilter(true);
	m_pUrielNewUserApplyTableSortFilterModel->setSourceModel(m_UrielNewUserApplyTableModel);
	ui.TP_NewUserApplyTableView->setModel(m_pUrielNewUserApplyTableSortFilterModel);

	//QObject::connect(ui.TP_NewUserApplyTableView, static_cast<void (QTableView::*)(const QModelIndex &)>(&QTableView::pressed), this, &UrielQtFramework::onInstrumentTableViewItemPressed);
	QList<int> wdls;
	wdls << 60 << 80 << 150 << 150 << 100 << 80 << 200 << 300 << 150 << 150 ;
	for (int i = 0; i < wdls.size(); i++)
	{
		ui.TP_NewUserApplyTableView->setColumnWidth(i, wdls[i]);
	}
	m_pDatabase->updateNewUserApplyTableModel();
}


void UrielQtFramework::onTP_MaterialPurchaseApplyBtnClicked() {
	ui.TP_StackedWidget->setCurrentIndex(1);
	ui.TP_MaterialPurchaseApplyTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.TP_MaterialPurchaseApplyTableView->setSortingEnabled(true);
	ui.TP_MaterialPurchaseApplyTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.TP_MaterialPurchaseApplyTableView->setShowGrid(true);
	ui.TP_MaterialPurchaseApplyTableView->verticalHeader()->setVisible(false);
	ui.TP_MaterialPurchaseApplyTableView->setAlternatingRowColors(true);
	ui.TP_MaterialPurchaseApplyTableView->setMouseTracking(true);
	//ui.TP_MaterialPurchaseApplyTableView->setSelectionMode(QAbstractItemView::ContiguousSelection);//设置为连续选择模式
	ui.TP_MaterialPurchaseApplyTableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
	ui.TP_MaterialPurchaseApplyTableView->setContextMenuPolicy(Qt::ActionsContextMenu);//设置为action菜单模式


	ui.TP_MaterialPurchaseApplyTableView->addAction(MaterialPurchaseApplyDetailAction);
	ui.TP_MaterialPurchaseApplyTableView->addAction(MaterialPurchaseApplyPassAction);
	ui.TP_MaterialPurchaseApplyTableView->addAction(MaterialPurchaseApplyRejectAction);
	
	connect(MaterialPurchaseApplyDetailAction, &QAction::triggered, this, &UrielQtFramework::onMaterialPurchaseApplyDetailActionTriggered);
	connect(MaterialPurchaseApplyPassAction, &QAction::triggered, this, &UrielQtFramework::onMaterialPurchaseApplyPassActionTriggered);
	connect(MaterialPurchaseApplyRejectAction, &QAction::triggered, this, &UrielQtFramework::onMaterialPurchaseApplyRejectActionTriggered);

	connect(ui.TP_MaterialPurchaseApplyTableView, static_cast<void (QTableView::*)(const QModelIndex &)>(&QTableView::doubleClicked), this, &UrielQtFramework::onTP_MaterialPurchaseApplyTableViewDoubleClicked);


	m_pUrielMaterialPurchaseApplyTableModel = m_pDatabase->creatMaterialPurchaseApplyTableModel();
	m_pUrielMaterialPurchaseApplyTableSortFilterModel = new QSortFilterProxyModel;
	m_pUrielMaterialPurchaseApplyTableSortFilterModel->setDynamicSortFilter(true);
	m_pUrielMaterialPurchaseApplyTableSortFilterModel->setSourceModel(m_pUrielMaterialPurchaseApplyTableModel);
	ui.TP_MaterialPurchaseApplyTableView->setModel(m_pUrielMaterialPurchaseApplyTableSortFilterModel);

	//QObject::connect(ui.TP_MaterialPurchaseApplyTableView, static_cast<void (QTableView::*)(const QModelIndex &)>(&QTableView::pressed), this, &UrielQtFramework::onInstrumentTableViewItemPressed);
	
	QList<int> wdls;
	//ID, ApplicationNumber, TotalAmount, RequisitionReasons, Applicant, DeclarationDate, AuditStatus, LinkAddress
	wdls << 60 << 100 << 200 << 300 << 80 << 150 << 100 << 300 ;
	for (int i = 0; i < wdls.size(); i++)
	{
		ui.TP_MaterialPurchaseApplyTableView->setColumnWidth(i, wdls[i]);
	}
	m_pDatabase->updateMaterialPurchaseApplyTableMode();
}


void UrielQtFramework::onTP_LeaveApplyBtnClicked() {
	ui.TP_StackedWidget->setCurrentIndex(2);

	ui.TP_LeaveApplyTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.TP_LeaveApplyTableView->setSortingEnabled(true);
	ui.TP_LeaveApplyTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.TP_LeaveApplyTableView->setShowGrid(true);
	ui.TP_LeaveApplyTableView->verticalHeader()->setVisible(false);
	ui.TP_LeaveApplyTableView->setAlternatingRowColors(true);
	ui.TP_LeaveApplyTableView->setMouseTracking(true);
	//ui.TP_LeaveApplyTableView->setSelectionMode(QAbstractItemView::ContiguousSelection);//设置为连续选择模式
	ui.TP_LeaveApplyTableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
	ui.TP_LeaveApplyTableView->setContextMenuPolicy(Qt::ActionsContextMenu);//设置为action菜单模式

	
	ui.TP_LeaveApplyTableView->addAction(LeaveApplyPassAction);
	ui.TP_LeaveApplyTableView->addAction(LeaveApplyRejectAction);

	connect(LeaveApplyPassAction, &QAction::triggered, this, &UrielQtFramework::onLeaveApplyPassActionTriggered);
	connect(LeaveApplyRejectAction, &QAction::triggered, this, &UrielQtFramework::onLeaveApplyRejectActionTriggered);

	//connect(ui.TP_LeaveApplyTableView, static_cast<void (QTableView::*)(const QModelIndex &)>(&QTableView::doubleClicked), this, &UrielQtFramework::onDP_InstrumentTableViewDoubleClicked);

	m_UrielLeaveApplyTableModel = m_pDatabase->creatLeaveApplyTableModel();
	m_pUrielLeaveApplyTableSortFilterModel = new QSortFilterProxyModel;
	m_pUrielLeaveApplyTableSortFilterModel->setDynamicSortFilter(true);
	m_pUrielLeaveApplyTableSortFilterModel->setSourceModel(m_UrielLeaveApplyTableModel);
	ui.TP_LeaveApplyTableView->setModel(m_pUrielLeaveApplyTableSortFilterModel);

	//QObject::connect(ui.TP_LeaveApplyTableView, static_cast<void (QTableView::*)(const QModelIndex &)>(&QTableView::pressed), this, &UrielQtFramework::onInstrumentTableViewItemPressed);
	QList<int> wdls;
	wdls << 40 << 80 << 80 << 80 << 200 << 100 << 100 << 100 << 80 << 60 << 100 << 100;
	for (int i = 0; i < wdls.size(); i++)
	{
		ui.TP_LeaveApplyTableView->setColumnWidth(i, wdls[i]);
	}
	m_pDatabase->updateLeaveApplyTableModel();
}

void UrielQtFramework::NewUserAccountAuditOperation(const UserAccountStatus & status) {
	QModelIndex index = ui.TP_NewUserApplyTableView->currentIndex();
	if (index.isValid())
	{
		int mIndex = index.row();
		QModelIndex idx = index.sibling(mIndex, 1);
		if (idx.isValid())
		{
			m_pDatabase->auditedNewUserApply(idx.data().toString(), m_pOptions->getAccount(), status);
		}
	}
	m_pDatabase->updateNewUserApplyTableModel();
	queryAndUpdateNumberOfUnprocessedEvents();
}

void UrielQtFramework::onNewUserApplyPassActionTriggered() {
	NewUserAccountAuditOperation(UserAccountStatus::Aduited);
}
void UrielQtFramework::onNewUserApplyRejectActionTriggered() {
	NewUserAccountAuditOperation(UserAccountStatus::Rejected);
}

void UrielQtFramework::onTP_NewUserAllPassTBtnClicked() {
	m_pDatabase->auditedAllNewUserApply(m_pOptions->getAccount());
	m_pDatabase->updateNewUserApplyTableModel();
	queryAndUpdateNumberOfUnprocessedEvents();
}
void UrielQtFramework::onTP_NewUserSinglePassTBtnClicked() {
	NewUserAccountAuditOperation(UserAccountStatus::Aduited);
}
void UrielQtFramework::onTP_NewUserRejectTBtnClicked() {
	NewUserAccountAuditOperation(UserAccountStatus::Rejected);
}

void UrielQtFramework::MaterialPurchaseApplyAuditOperation(const MaterialPurchaseApplyStatus & status) {
	QModelIndex index = ui.TP_MaterialPurchaseApplyTableView->currentIndex();
	if (index.isValid())
	{
		int mIndex = index.row();
		QModelIndex idx = index.sibling(mIndex, 0);
		if (idx.isValid())
		{
			m_pDatabase->auditedMaterialPurchaseApply(idx.data().toString(), m_pOptions->getAccount(), status);
		}
	}
	m_pDatabase->updateMaterialPurchaseApplyTableMode();
	queryAndUpdateNumberOfUnprocessedEvents();
	
}

void UrielQtFramework::onMaterialPurchaseApplyDetailActionTriggered() {
	QString ApplicationNumber;
	QModelIndex index = ui.TP_MaterialPurchaseApplyTableView->currentIndex();
	if (index.isValid())
	{
		int mIndex = index.row();
		QModelIndex idx = index.sibling(mIndex, 1);
		if (idx.isValid())
		{
			ApplicationNumber=idx.data().toString();
		}
	}
	MaterialPurchaseApplyTable dlg(m_pDatabase,m_pOptions, ApplicationNumber,this);
	dlg.exec();
}

void UrielQtFramework::onTP_MaterialPurchaseApplyTableViewDoubleClicked(const QModelIndex &index)
{
	onMaterialPurchaseApplyDetailActionTriggered();
}

void UrielQtFramework::onMaterialPurchaseApplyPassActionTriggered() {
	MaterialPurchaseApplyAuditOperation(MaterialPurchaseApplyStatus::Aduited);
}
void UrielQtFramework::onMaterialPurchaseApplyRejectActionTriggered() {
	MaterialPurchaseApplyAuditOperation(MaterialPurchaseApplyStatus::Rejected);
}


void UrielQtFramework::onTP_MaterialPurchaseAllPassTBtnClicked() {
	m_pDatabase->auditedAllMaterialPurchaseApply(m_pOptions->getAccount());
	m_pDatabase->updateMaterialPurchaseApplyTableMode();
	queryAndUpdateNumberOfUnprocessedEvents();
}
void UrielQtFramework::onTP_MaterialPurchaseRejectTBtnClicked() {
	MaterialPurchaseApplyAuditOperation(MaterialPurchaseApplyStatus::Rejected);
}
void UrielQtFramework::onTP_MaterialPurchaseSinglePassTBtnClicked() {
	MaterialPurchaseApplyAuditOperation(MaterialPurchaseApplyStatus::Aduited);
}

void UrielQtFramework::LeaveAuditOperation(const LeaveStatus & status) {
	QModelIndex index = ui.TP_LeaveApplyTableView->currentIndex();
	if (index.isValid())
	{
		int mIndex = index.row();
		QModelIndex idx = index.sibling(mIndex, 0);
		if (idx.isValid())
		{
			m_pDatabase->auditedLeaveApply(idx.data().toString(), m_pOptions->getAccount(), status);
		}
	}
	m_pDatabase->updateLeaveApplyTableModel();
	queryAndUpdateNumberOfUnprocessedEvents();
}

void UrielQtFramework::onLeaveApplyPassActionTriggered() {
	LeaveAuditOperation(LeaveStatus::Aduited);
}
void UrielQtFramework::onLeaveApplyRejectActionTriggered() {
	LeaveAuditOperation(LeaveStatus::AuditNotThrough);
}

void UrielQtFramework::onTP_LeaveAllPassTBtnClicked() {
	m_pDatabase->auditedAllLeaveApply(m_pOptions->getAccount());
	m_pDatabase->updateLeaveApplyTableModel();
	queryAndUpdateNumberOfUnprocessedEvents();
}
void UrielQtFramework::onTP_LeaveRejectTBtnClicked() {
	LeaveAuditOperation(LeaveStatus::AuditNotThrough);
}
void UrielQtFramework::onTP_LeaveSinglePassTBtnClicked() {
	LeaveAuditOperation(LeaveStatus::Aduited);
}

#pragma endregion
#pragma region Settings
void UrielQtFramework::initializeSettingsUi()
{
	onSP_PersonalSettingBtnClicked();
	initializeSystemSettingsUi();

}

void UrielQtFramework::initializeSystemSettingsUi(){

	sUrielSystemSettingsItem systemSettings;
	m_pDatabase->getSystemSettings(systemSettings);
	ui.SPSS_SystemEmail->setText(systemSettings.SystemEMail);
	QStringList AccountList;
	m_pDatabase->getAllUserName(AccountList);
	ui.SPSS_AuditorComboBox->clear();
	ui.SPSS_AuditorComboBox->addItems(AccountList);
	ui.SPA_CurrentVersionLabel->setText("V" + systemSettings.SystemVersion);
	ui.SPSS_UltimateAuditTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.SPSS_UltimateAuditTableView->setSortingEnabled(true);
	ui.SPSS_UltimateAuditTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.SPSS_UltimateAuditTableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
	ui.SPSS_UltimateAuditTableView->setShowGrid(true);
	ui.SPSS_UltimateAuditTableView->verticalHeader()->setVisible(false);
	ui.SPSS_UltimateAuditTableView->setAlternatingRowColors(true);
	ui.SPSS_UltimateAuditTableView->setMouseTracking(true);
	ui.SPSS_UltimateAuditTableView->setSelectionMode(QAbstractItemView::ContiguousSelection);//设置为连续选择模式
	ui.SPSS_UltimateAuditTableView->setContextMenuPolicy(Qt::ActionsContextMenu);//设置为action菜单模式

	QAction * UltimateAuditDeleteAction = new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/delete.png"), QStringLiteral("删除审核人"), this);
	ui.SPSS_UltimateAuditTableView->addAction(UltimateAuditDeleteAction);
	connect(UltimateAuditDeleteAction, &QAction::triggered, this, &UrielQtFramework::onSPSS_UltimateAuditDeleteActionClicked);

	m_UrielUltimateAuditTableModel = m_pDatabase->creatUltimateAuditTableModel();
	m_pUrielUltimateAuditTableSortFilterModel = new QSortFilterProxyModel;
	m_pUrielUltimateAuditTableSortFilterModel->setDynamicSortFilter(true);
	m_pUrielUltimateAuditTableSortFilterModel->setSourceModel(m_UrielUltimateAuditTableModel);
	ui.SPSS_UltimateAuditTableView->setModel(m_pUrielUltimateAuditTableSortFilterModel);

	QList<int> wdls;
	//ID, NAME, SCHOOL_WORK_NUMBER, EMAIL, PHONE_NUMBER, BANK_TYPE, BANK_CARD_NUMBER, PROJECT_TEAM, APPLY_TIME
	wdls << 40 << 80 << 100 << 180 << 120 << 60 << 200 << 300 << 120;
	for (int i = 0; i < wdls.size(); i++)
	{
		ui.SPSS_UltimateAuditTableView->setColumnWidth(i, wdls[i]);
	}

	ui.SPSS_RoutineAuditTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.SPSS_RoutineAuditTableView->setSortingEnabled(true);
	ui.SPSS_RoutineAuditTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.SPSS_RoutineAuditTableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
	ui.SPSS_RoutineAuditTableView->setShowGrid(true);
	ui.SPSS_RoutineAuditTableView->verticalHeader()->setVisible(false);
	ui.SPSS_RoutineAuditTableView->setAlternatingRowColors(true);
	ui.SPSS_RoutineAuditTableView->setMouseTracking(true);
	ui.SPSS_RoutineAuditTableView->setSelectionMode(QAbstractItemView::ContiguousSelection);//设置为连续选择模式
	ui.SPSS_RoutineAuditTableView->setContextMenuPolicy(Qt::ActionsContextMenu);//设置为action菜单模式

	QAction * RoutineAuditDeleteAction = new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/delete.png"), QStringLiteral("删除审核人"), this);
	ui.SPSS_RoutineAuditTableView->addAction(RoutineAuditDeleteAction);
	connect(RoutineAuditDeleteAction, &QAction::triggered, this, &UrielQtFramework::onSPSS_RoutineAuditDeleteActionClicked);

	m_UrielRoutineAuditTableModel = m_pDatabase->creatRoutineAuditTableModel();
	m_pUrielRoutineAuditTableSortFilterModel = new QSortFilterProxyModel;
	m_pUrielRoutineAuditTableSortFilterModel->setDynamicSortFilter(true);
	m_pUrielRoutineAuditTableSortFilterModel->setSourceModel(m_UrielRoutineAuditTableModel);
	ui.SPSS_RoutineAuditTableView->setModel(m_pUrielRoutineAuditTableSortFilterModel);

	for (int i = 0; i < wdls.size(); i++) {
		ui.SPSS_RoutineAuditTableView->setColumnWidth(i, wdls[i]);
	}
}
void UrielQtFramework::setSettingsSignalsAndSlots()
{
	QObject::connect(ui.SP_PersonalSettingBtn,&QToolButton::clicked,this,&UrielQtFramework::onSP_PersonalSettingBtnClicked);
	QObject::connect(ui.SP_SaftySettingBtn, &QToolButton::clicked, this, &UrielQtFramework::onSP_SaftySettingBtnClicked);
	QObject::connect(ui.SP_ClientSettingBtn, &QToolButton::clicked, this, &UrielQtFramework::onSP_ClientSettingBtnClicked);
	QObject::connect(ui.SP_SystemSettingBtn, &QToolButton::clicked, this, &UrielQtFramework::onSP_SystemSettingBtnClicked);
	QObject::connect(ui.SP_AboutBtn, &QToolButton::clicked, this, &UrielQtFramework::onSP_AboutBtnClicked);

	QObject::connect(ui.SPPS_UserNameEditBtn, &QToolButton::clicked, this, &UrielQtFramework::onSPPS_UserNameEditBtnClicked);
	QObject::connect(ui.SPPS_SchoolNumberEditBtn, &QToolButton::clicked, this, &UrielQtFramework::onSPPS_SchoolNumberEditBtnClicked);
	QObject::connect(ui.SPPS_EmailEditBtn, &QToolButton::clicked, this, &UrielQtFramework::onSPPS_EmailEditBtnClicked);
	QObject::connect(ui.SPPS_PhoneEditBtn, &QToolButton::clicked, this, &UrielQtFramework::onSPPS_PhoneEditBtnClicked);
	QObject::connect(ui.SPPS_BankTypeEditBtn, &QToolButton::clicked, this, &UrielQtFramework::onSPPS_BankTypeEditBtnClicked);
	QObject::connect(ui.SPPS_BankNumberEditBtn, &QToolButton::clicked, this, &UrielQtFramework::onSPPS_BankNumberEditBtnClicked);
	QObject::connect(ui.SPPS_ProjectEditBtn, &QToolButton::clicked, this, &UrielQtFramework::onSPPS_ProjectEditBtnClicked); 
	QObject::connect(ui.SPPS_ComfirmBtn, &QToolButton::clicked, this, &UrielQtFramework::onSPPS_ComfirmBtnClicked);
	QObject::connect(ui.SPPS_UserHeadIcoBtn, &QToolButton::clicked, this, &UrielQtFramework::onSPPS_UserHeadIcoBtnClicked);
	
	QObject::connect(ui.SPSS_SecrecyCheckBox, &QCheckBox::clicked, this, &UrielQtFramework::onSPSS_SecrecyCheckBoxClicked);

	QObject::connect(ui.SPCS_AutoStartCheckBox, &QCheckBox::clicked, this, &UrielQtFramework::onSPCS_AutoStartCheckBoxClicked);
	QObject::connect(ui.SPCS_DownloadPathEditBtn, &QToolButton::clicked, this, &UrielQtFramework::onSPCS_DownloadPathEditBtnClicked);
	QObject::connect(ui.SPCS_DatabaseNameEditBtn, &QToolButton::clicked, this, &UrielQtFramework::onSPCS_DatabaseNameEditBtnClicked);
	QObject::connect(ui.SPCS_DatabaseVersionEditBtn, &QToolButton::clicked, this, &UrielQtFramework::onSPCS_DatabaseVersionEditBtnClicked);
	QObject::connect(ui.SPCS_DatabaseHostEditBtn, &QToolButton::clicked, this, &UrielQtFramework::onSPCS_DatabaseHostEditBtnClicked);
	QObject::connect(ui.SPCS_DatabasePortEditBtn, &QToolButton::clicked, this, &UrielQtFramework::onSPCS_DatabasePortEditBtnClicked);
	QObject::connect(ui.SPCS_DatabaseUserNameEditBtn, &QToolButton::clicked, this, &UrielQtFramework::onSPCS_DatabaseUserNameEditBtnClicked);
	QObject::connect(ui.SPCS_DatabasePasswordEditBtn, &QToolButton::clicked, this, &UrielQtFramework::onSPCS_DatabasePasswordEditBtnClicked);
	QObject::connect(ui.SPCS_DatabaseFrameConstructionEditBtn, &QToolButton::clicked, this, &UrielQtFramework::onSPCS_DatabaseFrameConstructionEditBtnClicked);
	QObject::connect(ui.SPCS_DatabaseConversationalModeEditBtn, &QToolButton::clicked, this, &UrielQtFramework::onSPCS_DatabaseConversationalModeEditBtnClicked);
	QObject::connect(ui.SPCS_DatabaseOverTimeEditBtn, &QToolButton::clicked, this, &UrielQtFramework::onSPCS_DatabaseOverTimeEditBtnClicked);
	QObject::connect(ui.SPCS_FileServerHostEditBtn, &QToolButton::clicked, this, &UrielQtFramework::onSPCS_FileServerHostEditBtnClicked);
	QObject::connect(ui.SPCS_FileServerPortEditBtn, &QToolButton::clicked, this, &UrielQtFramework::onSPCS_FileServerPortEditBtnClicked);
	QObject::connect(ui.SPCS_FileServerUserNameEditBtn, &QToolButton::clicked, this, &UrielQtFramework::onSPCS_FileServerUserNameEditBtnClicked);
	QObject::connect(ui.SPCS_FileServerPasswordEditBtn, &QToolButton::clicked, this, &UrielQtFramework::onSPCS_FileServerPasswordEditBtnClicked);

	QObject::connect(ui.SPA_ReadLogBtn, &QToolButton::clicked, this, &UrielQtFramework::onSPA_ReadLogBtnClicked); 
	QObject::connect(ui.SPA_DeleteLogBtn, &QToolButton::clicked, this, &UrielQtFramework::onSPA_DeleteLogBtnClicked); 
	QObject::connect(ui.SPA_CheakUpdate, &QToolButton::clicked, this, &UrielQtFramework::onCheckUpdateClicked);
	QObject::connect(ui.SPSS_AddUltimateAudit, &QToolButton::clicked, this, &UrielQtFramework::onSPSS_AddUltimateAuditClicked);
	QObject::connect(ui.SPSS_RoutineAudit, &QToolButton::clicked, this, &UrielQtFramework::onSPSS_RoutineAuditClicked);
	QObject::connect(ui.SPSS_SystemEMailComfirmBtn, &QToolButton::clicked, this, &UrielQtFramework::onSPSS_SystemEMailComfirmBtnClicked);
}

void UrielQtFramework::onSP_PersonalSettingBtnClicked() {
	ui.SP_PersonalSettingSW->setCurrentIndex(0);
	sUrielAccountInfo accountInfo;
	m_pDatabase->getUserAccount(accountInfo, m_pOptions->getAccount());
	ui.SPPS_UserNameLabel->setText(accountInfo.m_sName);
	ui.SPPS_SchoolNumberLabel->setText(accountInfo.m_sSchoolWorkNumber);
	ui.SPPS_EmailLabel->setText(accountInfo.m_sEmail);
	ui.SPPS_PhoneLabel->setText(accountInfo.m_sPhoneNumber);

	ui.SPPS_BankTypeLabel->setText(accountInfo.m_sBankType);
	ui.SPPS_BankNumberLabel->setText(accountInfo.m_sBankCardNumber);
	ui.SPPS_ProjectLabel->setText(accountInfo.m_sProjectTeam);
	ui.SPPS_UserHeadIcoBtn->setIcon(QIcon(m_pOptions->getHeadIcoPath()));
}

void UrielQtFramework::onSP_SaftySettingBtnClicked(){
	ui.SP_PersonalSettingSW->setCurrentIndex(1);

	ui.SPSS_LoginTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.SPSS_LoginTableView->setSortingEnabled(true);
	ui.SPSS_LoginTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.SPSS_LoginTableView->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.SPSS_LoginTableView->setShowGrid(true);
	ui.SPSS_LoginTableView->verticalHeader()->setVisible(false);
	ui.SPSS_LoginTableView->setAlternatingRowColors(true);
	ui.SPSS_LoginTableView->setMouseTracking(true);
	ui.SPSS_LoginTableView->setSelectionMode(QAbstractItemView::ContiguousSelection);//设置为连续选择模式
	ui.SPSS_LoginTableView->setContextMenuPolicy(Qt::ActionsContextMenu);//设置为action菜单模式
	ui.SPSS_LoginTableView->resizeColumnsToContents();
	//ui.SPSS_LoginTableView->resizeRowsToContents();
	m_UrielLoginTableModel = m_pDatabase->creatLoginTableModel(m_pOptions->getAccount());
	m_pUrielLoginTableSortFilterModel = new QSortFilterProxyModel;
	m_pUrielLoginTableSortFilterModel->setDynamicSortFilter(true);
	m_pUrielLoginTableSortFilterModel->setSourceModel(m_UrielLoginTableModel);
	ui.SPSS_LoginTableView->setModel(m_pUrielLoginTableSortFilterModel);
	QList<int> wdls;
	wdls << 60 << 150 << 100 << 120 << 120 ;
	for (int i = 0; i < wdls.size(); i++)
	{
		ui.SPSS_LoginTableView->setColumnWidth(i, wdls[i]);
	}
	//m_pDatabase->updateUserCountTableModel();
}
void UrielQtFramework::onSP_ClientSettingBtnClicked() {
	ui.SP_PersonalSettingSW->setCurrentIndex(2);
	ui.SPCS_AutoStartCheckBox->setChecked(m_pOptions->g_bAppAutoStart);
	ui.SPCS_DownloadPathLabel->setText(m_pOptions->sDefalutFilesDownloadPath);
	ui.SPCS_DatabaseNameLabel->setText(m_pOptions->stUrielDBItem.m_strDBType);
	ui.SPCS_DatabaseVersionLabel->setText(m_pOptions->stUrielDBItem.m_strVersion);
	ui.SPCS_DatabaseHostLabel->setText(m_pOptions->stUrielDBItem.m_strHost);
	ui.SPCS_DatabasePortLabel->setText(QString::number(m_pOptions->stUrielDBItem.m_iPort));
	ui.SPCS_DatabaseUserNameLabel->setText(m_pOptions->stUrielDBItem.m_strUser);
	ui.SPCS_DatabasePasswordLineEdit->setText(m_pOptions->stUrielDBItem.m_strPwd);
	ui.SPCS_DatabaseFrameConstructionLineEdit->setText(m_pOptions->stUrielDBItem.m_strSchema);
	ui.SPCS_DatabaseConversationalModeLineEdit->setText(m_pOptions->stUrielDBItem.m_bLinking?QStringLiteral("连接式"):QStringLiteral("断开式"));
	ui.SPCS_DatabaseOverTimeLineEdit->setText(QString::number(m_pOptions->stUrielDBItem.m_iTimeOut)+"s");

	ui.SPCS_FileServerHostLabel->setText(m_pOptions->getFTPConfigParameter().m_sHostIp);
	ui.SPCS_FileServerPortLabel->setText(QString::number(m_pOptions->getFTPConfigParameter().m_iPort));
	ui.SPCS_FileServerUserNameLabel->setText(m_pOptions->getFTPConfigParameter().m_sUserName);
	ui.SPCS_FileServerPasswordLineEdit->setText(m_pOptions->getFTPConfigParameter().m_sPassword);
}

void UrielQtFramework::onSP_SystemSettingBtnClicked() {
	ui.SP_PersonalSettingSW->setCurrentIndex(3);
	m_pDatabase->updateUltimateTableModel();
	m_pDatabase->updateRoutineTableModel();
}

void UrielQtFramework::onSPSS_UltimateAuditDeleteActionClicked() {
	QModelIndex index = ui.SPSS_UltimateAuditTableView->currentIndex();
	if (index.isValid())
	{
		int mIndex = index.row();
		QModelIndex idx = index.sibling(mIndex, 0);
		if (idx.isValid())
			m_pDatabase->resetAuditlevel(idx.data().toString());
	}
	m_pDatabase->updateUltimateTableModel();
	
}

void UrielQtFramework::onSPSS_RoutineAuditDeleteActionClicked() {
	QModelIndex index = ui.SPSS_RoutineAuditTableView->currentIndex();
	if (index.isValid())
	{
		int mIndex = index.row();
		QModelIndex idx = index.sibling(mIndex, 0);
		if (idx.isValid())
			m_pDatabase->resetAuditlevel(idx.data().toString());
	}
	m_pDatabase->updateRoutineTableModel();
}

void UrielQtFramework::onSPSS_AddUltimateAuditClicked() {
	m_pDatabase->setAuditlevel(ui.SPSS_AuditorComboBox->currentText(),"UltimateAudit");
	m_pDatabase->updateUltimateTableModel();
}
void UrielQtFramework::onSPSS_RoutineAuditClicked() {
	m_pDatabase->setAuditlevel(ui.SPSS_AuditorComboBox->currentText(), "RoutineAudit");
	m_pDatabase->updateRoutineTableModel();
}

void UrielQtFramework::onSPSS_SystemEMailComfirmBtnClicked() {
	sUrielAccountInfo account;
	m_pDatabase->getUserAccount(account, m_pOptions->getAccount());
	//'super administrator','administrator','regular user'
	if (account.m_sPermision == "regular user") {
		InformationDialog infodlg(QStringLiteral("信息"), QStringLiteral("非管理员，无权限修改！"), this);
		infodlg.exec();
		return;
	}
	//m_pOptions->setSystemEmailAccount(ui.SPSS_SystemEmail->text());
	sUrielSystemSettingsItem system_info;
	m_pDatabase->getSystemSettings(system_info);
	if (ui.SPSS_NewSystemEMailPassword->text() == ui.SPSS_RepeatSystemEMailPassword->text()) {
		system_info.SystemEMail = ui.SPSS_SystemEmail->text();
		system_info.SystemEMailPassword = ui.SPSS_NewSystemEMailPassword->text();
		m_pDatabase->updateSystemEMailSettings(system_info);
		//m_pOptions->setSystemEmailPassword(ui.SPSS_NewSystemEMailPassword->text());
		InformationDialog infodlg(QStringLiteral("信息"), QStringLiteral("系统邮件已更新！"), this);
		infodlg.exec();
	}
	else {
		CriticalDialog dlg(QStringLiteral("错误"), QStringLiteral("密码不一致！"), this);
		dlg.exec();
	}
}
		
void UrielQtFramework::onSP_AboutBtnClicked(){
	ui.SP_PersonalSettingSW->setCurrentIndex(4);
}

void UrielQtFramework::modifySPPSInfo(const QString & info, const QString & sModifyField) {
	InputDialog dlg(QStringLiteral("请输入修改的") + info, this);
	QObject::connect(&dlg, static_cast<void (InputDialog::*)(const QString & value)>(&InputDialog::contentSignal), [&](const QString & value)
	{
		this->m_pDatabase->updateUserCountInfo(sModifyField, value, "NAME", m_pOptions->getAccount());
	});
	if (dlg.exec() == QDialog::Accepted) {
		InformationDialog infodlg(QStringLiteral("信息"), QStringLiteral("信息已修改至数据库，软件重启后生效！"), this);
		infodlg.exec();
	}
}

void UrielQtFramework::onSPPS_UserNameEditBtnClicked() {
	modifySPPSInfo(QStringLiteral("用户名"), "NAME");
}
void UrielQtFramework::onSPPS_SchoolNumberEditBtnClicked() {
	modifySPPSInfo(QStringLiteral("学（工）号"), "SCHOOL_WORK_NUMBER");
}
void UrielQtFramework::onSPPS_EmailEditBtnClicked() {
	modifySPPSInfo(QStringLiteral("邮箱"), "EMAIL");
}
void UrielQtFramework::onSPPS_PhoneEditBtnClicked() {
	modifySPPSInfo(QStringLiteral("电话号码"), "PHONE_NUMBER");
}
void UrielQtFramework::onSPPS_BankTypeEditBtnClicked() {
	modifySPPSInfo(QStringLiteral("银行"), "BANK_TYPE");
}
void UrielQtFramework::onSPPS_BankNumberEditBtnClicked() {
	modifySPPSInfo(QStringLiteral("银行卡号"), "BANK_CARD_NUMBER");
}
void UrielQtFramework::onSPPS_ProjectEditBtnClicked() {
	modifySPPSInfo(QStringLiteral("项目"), "PROJECT_TEAM");
}
void UrielQtFramework::onSPPS_UserHeadIcoBtnClicked() {
	QString sUserHeadIcoLocalPath = QFileDialog::getOpenFileName(
		this, QStringLiteral("请选择头像图片"),
		QCoreApplication::applicationDirPath(),
		tr("All Files (*);;PNG File (*.png);;JPG Files (*.jpg);;JPGE Files (*.jpge);;BMP Files (*.bmp)"));
	if (!sUserHeadIcoLocalPath.isEmpty())
	{
		
		m_pDatabase->updateUserHeadIco(QImage(sUserHeadIcoLocalPath),m_pOptions->getAccount());
		QImage(sUserHeadIcoLocalPath)/*.scaled(QSize(45,45))*/.save(m_pOptions->getHeadIcoPath());
		ui.SPPS_UserHeadIcoBtn->setIcon(QIcon(sUserHeadIcoLocalPath));
	}
}

void UrielQtFramework::onSPPS_ComfirmBtnClicked() {
	if (ui.SPPS_CurrentPasswordLabel->text() != m_pOptions->getPassword()) {
		CriticalDialog dlg(QStringLiteral("错误"), QStringLiteral("当前密码错误！"), this);
		dlg.exec();
	}
	else if (ui.SPPS_NewPasswordLabel->text() != ui.SPPS_RepeattPasswordLabel->text()) {
		CriticalDialog dlg(QStringLiteral("错误"), QStringLiteral("密码验证不一致！"), this);
		dlg.exec();
	}
	else {
		this->m_pDatabase->updateUserCountInfo("PASSWORD", ui.SPPS_NewPasswordLabel->text(), "NAME", m_pOptions->getAccount());
		InformationDialog infodlg(QStringLiteral("信息"), QStringLiteral("密码已更新，软件重启后生效！"), this);
		infodlg.exec();
	}

}

void UrielQtFramework::onSPSS_SecrecyCheckBoxClicked() {
	if(ui.SPSS_SecrecyCheckBox->isChecked())
		this->m_pDatabase->updateUserCountInfo("SAFE_MODE", "Y", "NAME", m_pOptions->getAccount());
	else
		this->m_pDatabase->updateUserCountInfo("SAFE_MODE", "N", "NAME", m_pOptions->getAccount());
}

void UrielQtFramework::appAutoRun(bool bAutoRun)
{
	//HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Run
	QSettings  reg("HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", QSettings::NativeFormat);
	if (bAutoRun)
	{
		QString strAppPath = QDir::toNativeSeparators(QCoreApplication::applicationFilePath());
		//strAppPath.replace(QChar('/'),QChar('\\'),Qt::CaseInsensitive);
		reg.setValue("wirtepad", strAppPath);
	}
	else
	{
		reg.setValue("wirtepad", "");
	}
}

void UrielQtFramework::onSPCS_AutoStartCheckBoxClicked() {
	if (ui.SPCS_AutoStartCheckBox->isChecked()) {
		appAutoRun(true);
		m_pOptions->g_bAppAutoStart = true;
	}
	else {
		appAutoRun(false);
		m_pOptions->g_bAppAutoStart = false;
	}
		
}


void UrielQtFramework::onSPCS_DownloadPathEditBtnClicked() {
	QString sDownloadPath = QFileDialog::getExistingDirectory(
		this, QStringLiteral("默认下载路径"),
		QCoreApplication::applicationDirPath());
	if (!sDownloadPath.isEmpty())
	{
		ui.SPCS_DownloadPathLabel->setText(sDownloadPath);
		m_pOptions->setDefalutFilesDownloadPath(sDownloadPath);
	}
}
void UrielQtFramework::onSPCS_DatabaseNameEditBtnClicked() {
	InputDialog dlg(QStringLiteral("请输入修改的数据库类型"), this);
	QObject::connect(&dlg, static_cast<void (InputDialog::*)(const QString & value)>(&InputDialog::contentSignal), [&](const QString & value)
	{
		ui.SPCS_DatabaseNameLabel->setText(value);
		m_pOptions->stUrielDBItem.m_strDBType=value;
	});
	dlg.exec();
}
void UrielQtFramework::onSPCS_DatabaseVersionEditBtnClicked() {
	InputDialog dlg(QStringLiteral("请输入修改的数据库版本"), this);
	QObject::connect(&dlg, static_cast<void (InputDialog::*)(const QString & value)>(&InputDialog::contentSignal), [&](const QString & value)
	{
		ui.SPCS_DatabaseVersionLabel->setText(value);
		m_pOptions->stUrielDBItem.m_strVersion = value;
	});
	dlg.exec();
}
void UrielQtFramework::onSPCS_DatabaseHostEditBtnClicked() {
	InputDialog dlg(QStringLiteral("请输入修改的主机IP地址"), this);
	QObject::connect(&dlg, static_cast<void (InputDialog::*)(const QString & value)>(&InputDialog::contentSignal), [&](const QString & value)
	{
		ui.SPCS_DatabaseHostLabel->setText(value);
		m_pOptions->stUrielDBItem.m_strHost = value;
	});
	dlg.exec();
}
void UrielQtFramework::onSPCS_DatabasePortEditBtnClicked() {
	InputDialog dlg(QStringLiteral("请输入修改的数据库端口"), this);
	QObject::connect(&dlg, static_cast<void (InputDialog::*)(const QString & value)>(&InputDialog::contentSignal), [&](const QString & value)
	{
		ui.SPCS_DatabasePortLabel->setText(value);
		m_pOptions->stUrielDBItem.m_iPort = value.toInt();
	});
	dlg.exec();
}
void UrielQtFramework::onSPCS_DatabaseUserNameEditBtnClicked() {
	InputDialog dlg(QStringLiteral("请输入修改的数据库用户名"), this);
	QObject::connect(&dlg, static_cast<void (InputDialog::*)(const QString & value)>(&InputDialog::contentSignal), [&](const QString & value)
	{
		ui.SPCS_DatabaseUserNameLabel->setText(value);
		m_pOptions->stUrielDBItem.m_strUser = value;
	});
	dlg.exec();
}
void UrielQtFramework::onSPCS_DatabasePasswordEditBtnClicked() {
	InputDialog dlg(QStringLiteral("请输入修改的数据库密码"), this);
	QObject::connect(&dlg, static_cast<void (InputDialog::*)(const QString & value)>(&InputDialog::contentSignal), [&](const QString & value)
	{
		ui.SPCS_DatabasePasswordLineEdit->setText(value);
		m_pOptions->stUrielDBItem.m_strPwd = value;
	});
	dlg.exec();
}
void UrielQtFramework::onSPCS_DatabaseFrameConstructionEditBtnClicked() {
	InputDialog dlg(QStringLiteral("请输入修改的数据库框架结构"), this);
	QObject::connect(&dlg, static_cast<void (InputDialog::*)(const QString & value)>(&InputDialog::contentSignal), [&](const QString & value)
	{
		ui.SPCS_DatabaseFrameConstructionLineEdit->setText(value);
		m_pOptions->stUrielDBItem.m_strSchema = value;
	});
	dlg.exec();
}
void UrielQtFramework::onSPCS_DatabaseConversationalModeEditBtnClicked() {
	InputDialog dlg(QStringLiteral("请输入修改的数据库会话方式(0:断开式，1：连接式)"), this);
	QObject::connect(&dlg, static_cast<void (InputDialog::*)(const QString & value)>(&InputDialog::contentSignal), [&](const QString & value)
	{
		ui.SPCS_DatabaseConversationalModeLineEdit->setText(value);
		m_pOptions->stUrielDBItem.m_bLinking = value.toInt();
	});
	dlg.exec();
}
void UrielQtFramework::onSPCS_DatabaseOverTimeEditBtnClicked() {
	InputDialog dlg(QStringLiteral("请输入修改的数据库超时时长(s)"), this);
	QObject::connect(&dlg, static_cast<void (InputDialog::*)(const QString & value)>(&InputDialog::contentSignal), [&](const QString & value)
	{
		ui.SPCS_DatabaseOverTimeLineEdit->setText(value);
		m_pOptions->stUrielDBItem.m_iTimeOut = value.toInt();
	});
	dlg.exec();
}
void UrielQtFramework::onSPCS_FileServerHostEditBtnClicked() {
	InputDialog dlg(QStringLiteral("请输入修改的文件服务器主机IP"), this);
	QObject::connect(&dlg, static_cast<void (InputDialog::*)(const QString & value)>(&InputDialog::contentSignal), [&](const QString & value)
	{
		ui.SPCS_FileServerHostLabel->setText(value);
		m_pOptions->stUrielFTPItem.m_sHostIp = value;
	});
	dlg.exec();
}
void UrielQtFramework::onSPCS_FileServerPortEditBtnClicked() {
	InputDialog dlg(QStringLiteral("请输入修改的文件服务器主机端口"), this);
	QObject::connect(&dlg, static_cast<void (InputDialog::*)(const QString & value)>(&InputDialog::contentSignal), [&](const QString & value)
	{
		ui.SPCS_FileServerPortLabel->setText(value);
		m_pOptions->stUrielFTPItem.m_iPort = value.toInt();
	});
	dlg.exec();
}
void UrielQtFramework::onSPCS_FileServerUserNameEditBtnClicked() {
	InputDialog dlg(QStringLiteral("请输入修改的文件服务器用户名"), this);
	QObject::connect(&dlg, static_cast<void (InputDialog::*)(const QString & value)>(&InputDialog::contentSignal), [&](const QString & value)
	{
		ui.SPCS_FileServerUserNameLabel->setText(value);
		m_pOptions->stUrielFTPItem.m_sUserName = value;
	});
	dlg.exec();
}
void UrielQtFramework::onSPCS_FileServerPasswordEditBtnClicked() {
	InputDialog dlg(QStringLiteral("请输入修改的文件服务器密码"), this);
	QObject::connect(&dlg, static_cast<void (InputDialog::*)(const QString & value)>(&InputDialog::contentSignal), [&](const QString & value)
	{
		ui.SPCS_FileServerPasswordLineEdit->setText(value);
		m_pOptions->stUrielFTPItem.m_sPassword = value;
	});
	dlg.exec();
}

void UrielQtFramework::onSPA_ReadLogBtnClicked() {

}
void UrielQtFramework::onSPA_DeleteLogBtnClicked() {

}
#include "ThirdPartyLibraries\QSimpleUpdater\UrielUpdater\UrielUpdater.h"
void UrielQtFramework::onCheckUpdateClicked() {
	UrielUpdater * window=new UrielUpdater;
	window->show();
}

#pragma endregion


void UrielQtFramework::setWindowLogAndTitle()
{
	this->setWindowTitle(QObject::tr("UrielQtFramework"));
	this->setWindowIcon(QIcon(":/Mainwindow/Resources/UrielQtFramework/applogo.png"));
}

void UrielQtFramework::setupToolBar()
{
	m_pFileMenu = menuBar()->addMenu(QObject::tr("File"));
	m_pFileMenu->addAction(tr("Save layout..."), this, &UrielQtFramework::saveLayout);
	m_pFileMenu->addAction(tr("Load layout..."), this, &UrielQtFramework::loadLayout);
	m_pFileMenu->addSeparator();
	m_pFileMenu->addAction(tr("&Quit"), this, &QWidget::close);


}

void UrielQtFramework::setupMenuBar()
{

}



bool UrielQtFramework::eventFilter(QObject *obj, QEvent *event)
{
	//if (obj == ui.HomePageTB)
	//{
	//	if (event->type() == QEvent::MouseButtonPress) {
	//		ui.stackedWidget->setCurrentIndex(0);
	//		return true;
	//	}
	//	else
	//		return false;
	//}
	//else {
	//	// pass the event on to the parent class
	//	return QMainWindow::eventFilter(obj, event);
	//}
	return QMainWindow::eventFilter(obj, event);
}

void UrielQtFramework::onHomePageTBClicked()
{
	ui.stackedWidget->setCurrentIndex(0);
}
void UrielQtFramework::onDevicesTBClicked()
{
	ui.stackedWidget->setCurrentIndex(1);
}
void UrielQtFramework::onExpenseTBClicked()
{
	ui.stackedWidget->setCurrentIndex(2);
}
void UrielQtFramework::onApplyTBClicked() {
	ui.stackedWidget->setCurrentIndex(3);
}
void UrielQtFramework::onCheckInTBClicked()
{
	ui.stackedWidget->setCurrentIndex(4);
}
void UrielQtFramework::onResourcesTBClicked()
{
	ui.stackedWidget->setCurrentIndex(5);
}
void UrielQtFramework::onStatisticsTBClicked()
{
	ui.stackedWidget->setCurrentIndex(6);
}
void UrielQtFramework::onTodoTBClicked() {
	ui.stackedWidget->setCurrentIndex(7);
}
void UrielQtFramework::onSettingsTBClicked()
{
	ui.stackedWidget->setCurrentIndex(8);
}

void UrielQtFramework::onAppMinimizeClicked()
{
	this->hide();

}

void UrielQtFramework::onSystemTrayIconClicked(QSystemTrayIcon::ActivationReason reason)
{
	switch (reason) {
	case QSystemTrayIcon::Trigger:
		this->showNormal();
		//this->m_pSystemTrayIcon->hide();
		break;
	default:
		break;
	}
}

void UrielQtFramework::onAppMaximizeClicked()
{
	if (this->isMaximized())
	{
		ui.AppClose->show();
		ui.AppMaximize->setIcon(QIcon(":/Mainwindow/Resources/UrielQtFramework/maximization.png"));
		this->showNormal();
	}
	else
	{
		ui.AppClose->hide();
		ui.AppMaximize->setIcon(QIcon(":/Mainwindow/Resources/UrielQtFramework/normalization.png"));
		this->showMaximized();
	}
}

void UrielQtFramework::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		m_bPressed = true;
		m_point = event->pos();
	}
}

void UrielQtFramework::mouseMoveEvent(QMouseEvent *event)
{
	if (m_bPressed)
		move(event->pos() - m_point + pos());
}

void UrielQtFramework::mouseReleaseEvent(QMouseEvent *event)
{
	Q_UNUSED(event);
	m_bPressed = false;
}

void UrielQtFramework::mouseDoubleClickEvent(QMouseEvent *event)
{
	Q_UNUSED(event);
	onAppMaximizeClicked();
}

bool UrielQtFramework::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
	Q_UNUSED(eventType)

		MSG *param = static_cast<MSG *>(message);

	switch (param->message)
	{
	case WM_NCHITTEST:
	{
		int nX = GET_X_LPARAM(param->lParam) - this->geometry().x();
		int nY = GET_Y_LPARAM(param->lParam) - this->geometry().y();

		if (childAt(nX, nY) != NULL)
			return QWidget::nativeEvent(eventType, message, result);

		*result = HTCAPTION;

		if ((nX > 0) && (nX < m_nBorder))
			*result = HTLEFT;

		if ((nX > this->width() - m_nBorder) && (nX < this->width()))
			*result = HTRIGHT;

		if ((nY > 0) && (nY < m_nBorder))
			*result = HTTOP;

		if ((nY > this->height() - m_nBorder) && (nY < this->height()))
			*result = HTBOTTOM;

		if ((nX > 0) && (nX < m_nBorder) && (nY > 0)
			&& (nY < m_nBorder))
			*result = HTTOPLEFT;

		if ((nX > this->width() - m_nBorder) && (nX < this->width())
			&& (nY > 0) && (nY < m_nBorder))
			*result = HTTOPRIGHT;

		if ((nX > 0) && (nX < m_nBorder)
			&& (nY > this->height() - m_nBorder) && (nY < this->height()))
			*result = HTBOTTOMLEFT;

		if ((nX > this->width() - m_nBorder) && (nX < this->width())
			&& (nY > this->height() - m_nBorder) && (nY < this->height()))
			*result = HTBOTTOMRIGHT;

		return true;
	}
	}

	return QMainWindow::nativeEvent(eventType, message, result);
}



void UrielQtFramework::saveLayout()
{
	QString fileName
		= QFileDialog::getSaveFileName(this, tr("Save layout"));
	if (fileName.isEmpty())
		return;
	QFile file(fileName);
	if (!file.open(QFile::WriteOnly)) {
		QString msg = tr("Failed to open %1\n%2")
			.arg(QDir::toNativeSeparators(fileName), file.errorString());
		QMessageBox::warning(this, tr("Error"), msg);
		return;
	}

	QByteArray geo_data = saveGeometry();
	QByteArray layout_data = saveState();

	bool ok = file.putChar((uchar)geo_data.size());
	if (ok)
		ok = file.write(geo_data) == geo_data.size();
	if (ok)
		ok = file.write(layout_data) == layout_data.size();

	if (!ok) {
		QString msg = tr("Error writing to %1\n%2")
			.arg(QDir::toNativeSeparators(fileName), file.errorString());
		QMessageBox::warning(this, tr("Error"), msg);
		return;
	}
}

void UrielQtFramework::loadLayout()
{
	QString fileName
		= QFileDialog::getOpenFileName(this, tr("Load layout"));
	if (fileName.isEmpty())
		return;
	QFile file(fileName);
	if (!file.open(QFile::ReadOnly)) {
		QString msg = tr("Failed to open %1\n%2")
			.arg(QDir::toNativeSeparators(fileName), file.errorString());
		QMessageBox::warning(this, tr("Error"), msg);
		return;
	}

	uchar geo_size;
	QByteArray geo_data;
	QByteArray layout_data;

	bool ok = file.getChar((char*)&geo_size);
	if (ok) {
		geo_data = file.read(geo_size);
		ok = geo_data.size() == geo_size;
	}
	if (ok) {
		layout_data = file.readAll();
		ok = layout_data.size() > 0;
	}

	if (ok)
		ok = restoreGeometry(geo_data);
	if (ok)
		ok = restoreState(layout_data);

	if (!ok) {
		QString msg = tr("Error reading %1").arg(QDir::toNativeSeparators(fileName));
		QMessageBox::warning(this, tr("Error"), msg);
		return;
	}
}