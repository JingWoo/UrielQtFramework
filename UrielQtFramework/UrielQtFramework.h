#pragma once

#include <QtWidgets/QMainWindow>
#include <QList>
#include "ui_UrielQtFramework.h"
#if QT_VERSION >= 0x50000
	#include <QtWidgets>
#else
	#include <QtGui>
#endif

#include "UrielDefinition\UrielDefinition.h"
#include <QHash>
#include <QNetworkConfigurationManager>
#include <QtNetwork>
#include "qtrpt.h"
QT_FORWARD_DECLARE_CLASS(QFtp)
QT_FORWARD_DECLARE_CLASS(QUrielUrlInfo)

QT_FORWARD_DECLARE_CLASS(UrielQtFrameworkOptions)
QT_FORWARD_DECLARE_CLASS(QMenu)
QT_FORWARD_DECLARE_CLASS(UrielDatabase)
QT_FORWARD_DECLARE_CLASS(NoticesListMenuItem)
QT_FORWARD_DECLARE_CLASS(UrielNoticesMenuTableModel)
QT_FORWARD_DECLARE_CLASS(NoticesCommentItem)
QT_FORWARD_DECLARE_CLASS(UrielFtp)
QT_FORWARD_DECLARE_CLASS(UrielInstrumentTableModel)
QT_FORWARD_DECLARE_CLASS(QAction)
QT_FORWARD_DECLARE_CLASS(UrielCheckInTableModel)
QT_FORWARD_DECLARE_CLASS(UrielInvoiceTableModel)
QT_FORWARD_DECLARE_CLASS(UrielUserCountTableModel)
QT_FORWARD_DECLARE_CLASS(UrielLeaveInfoTableModel)
QT_FORWARD_DECLARE_CLASS(UrielLoginTableModel)
QT_FORWARD_DECLARE_CLASS(UrielMaterialPurchaseApplyTableModel)
QT_FORWARD_DECLARE_CLASS(UrielMeetingReportTableModel)
QT_FORWARD_DECLARE_CLASS(UrielPaperTableModel)
QT_FORWARD_DECLARE_CLASS(UrielAcademicConferenceTableModel)
QT_FORWARD_DECLARE_CLASS(UrielPatentTableModel)
QT_FORWARD_DECLARE_CLASS(UrielWorksTableModel)
QT_FORWARD_DECLARE_CLASS(UrielResearchProjectTableModel)
class UrielQtFramework : public QMainWindow
{
	Q_OBJECT

public:
	UrielQtFramework(UrielDatabase *database, UrielQtFrameworkOptions *option,QWidget *parent = Q_NULLPTR);
	~UrielQtFramework();
	void setUpOptions(UrielQtFrameworkOptions *option);
	void setDatabase(UrielDatabase *database);
	static UrielQtFramework* instance() {
		return mw;
	}

///QtSingleApplication Message Handle
public slots:
	void handleSingleApplicationMessage(const QString& message)
	{
		QMessageBox::information(nullptr,QObject::tr("QtSingleApplication"), QObject::tr("Message received: \"") + message + "\"");
	}

	void saveLayout();
	void loadLayout();

protected:
	virtual void mouseMoveEvent(QMouseEvent *event) override;
	virtual void mousePressEvent(QMouseEvent *event) override;
	virtual void mouseReleaseEvent(QMouseEvent *event) override;
	virtual bool nativeEvent(const QByteArray &eventType, void *message, long *result) override;
	virtual void mouseDoubleClickEvent(QMouseEvent *event) override;

	bool eventFilter(QObject *obj, QEvent *event) override;


private slots:
   void onAppMinimizeClicked();
   void onAppMaximizeClicked();
   void onSystemTrayIconClicked(QSystemTrayIcon::ActivationReason);
   void onGlobelSearchBtnClicked();
   void onAccountInfoTBtnClicked();
   void onHomePageTBClicked();
   void onDevicesTBClicked();
   void onExpenseTBClicked();
   void onApplyTBClicked();
   void onCheckInTBClicked();
   void onResourcesTBClicked();
   void onStatisticsTBClicked();
   void onTodoTBClicked();
   void onSettingsTBClicked();

   void onHP_SearchTBClicked();
   void onHP_ReturnTBClicked();
   void onHP_FiltrateTBClicked();
   void onHP_ReleasingNoticesTBClicked();
   void onTimeFilterSlot(const TimeFilterEnum & v);
   void onNoticesListMenuItemCodeSignal(const QString &);
   void onNoticesEditActionTriggered();
   void onNoticesDeleteActionTriggered();
   void onNoticesFlagActionTriggered();
   void onNoticesMenuItemPressed(const QModelIndex &);
   void onNoticesCommentReply(const QString &name);
   void onHP_ReleasingNoticesCommentTBClicked();
   void onHP_NoticesFilePreViewTBtnClicked();
   void onHP_Search_CTBClicked();


   void onInstrumentTableViewItemPressed(const QModelIndex &);
   void onDP_SearchTBtnClicked();
   void onDP_ReturnTBtnClicked();
   void onInstrumentAddActionTriggered();
   void onInstrumentEditActionTriggered();
   void onInstrumentDeleteActionTriggered();
   void onInstrumentUseManageBorrowActionTriggered();
   void onInstrumentUseManageReturnActionTriggered();
   void onInstrumentHistoryBorrowReturnActionTriggered();
   void onDP_InstrumentTableViewDoubleClicked();
   void onDP_ProjectTBtnClicked();
   void onDP_ClassTBtnClicked();
   void onDP_TreeWidgetItemDoubleClicked(QTreeWidgetItem*, int);
   void onDP_SearchConfirmTBtnClicked();
   void onDP_SerachLineEditClicked();
   void onDP_AddInstrumentTBtnClicked();
   void onDP_EditInstrumentTBtnClicked();
   void onDP_DeleteInstrumentTBtnClicked();
   void ReturnOrBorrowInstrument();
   void onDP_BorrowInstrumentTBtnClicked();
   void onDP_ReturnInstrumentTBtnClicked();
   void onDP_ExportInstrumentTBtnClicked();
   void onDP_BRInstrumentHistroyTBtnClicked();
   void onDP_StatisticsInstrumentTBtnClicked();
   void Table2ExcelByHtml(QTableWidget *table, QString title);
   QString getDPFilters();
   void onDP_FilterSearchPBtnClicked();
   void onDP_ProjectManagerComboxCurrentIndexChanged(int index);
   void onDP_InStoreCheckBoxClicked(bool value);
   void setInstrumentReportValue(const int recNo, const QString paramName, QVariant &paramValue, const int reportPage);

   void onCheckInEventEditActionTriggered();
   void onCheckInEventDeleteActionTriggered();
   void onCheckInTableViewPressed(const QModelIndex &);
   void onCP_CalendarWidgetClicked(const QDate & date);
   void onCP_AddEventTBtnClicked();
   void onCP_LeaveConfirmApplyClicked();
   void onCP_EndLeaveTimeChanged(const QDateTime &dateTime);

   void onAP_PreviewTBtnClicked();
   void onAP_ApplyTBtnClicked();
   void onAP_SearchTBtnClicked();
   void onAP_ReturnTBtnClicked();
   void onAP_SearchConfirmTBtnClicked();
   void onAP_ApplyConfirmBtnClicked();
   void onAP_PreviewAddImageBtnClicked();
   void onAP_PreviewLookImageBtnClicked();
   void onAP_PreviewDeleteImageBtnClicked();
   void onAP_SerachLineEditClicked();
   void onAP_ApplyAddImageBtnClicked();
   void onAP_ApplyLookImageBtnClicked();
   void onAP_ApplyDeleteImageBtnClicked();
   void onAP_TreeWidgetItemDoubleClicked(QTreeWidgetItem*, int);
   
   void onAP_ApplyUnitPriceLineEdit_1EditingFinished();
   void onAP_ApplyUnitPriceLineEdit_2EditingFinished(); 
   void onAP_ApplyUnitPriceLineEdit_3EditingFinished();
   void onAP_ApplyUnitPriceLineEdit_4EditingFinished();
   void onAP_ApplyUnitPriceLineEdit_5EditingFinished();
   void onAP_ApplyUnitPriceLineEdit_6EditingFinished();
   void onAP_ApplyTotalAmountLineEditReturnPressed();
   void onEP_HistoryModelTBtnClicked();
   void onEP_PersonalModelTBtnClicked();
   void onEP_CollectModelTBtnClicked();
   void onEP_PersonalModelSelectProjectTBtnClicked();
   void onEP_TreeWidgetItemDoubleClicked(QTreeWidgetItem*, int);
   void onEP_StaffTreeWidgetItemDoubleClicked(QTreeWidgetItem*, int);
   void onExpenseItemSlot(const ExpenseItemEnum & v);
   void setSummarySheetValue(const int recNo, const QString paramName, QVariant &paramValue, const int reportPage);
   void setSummarySheetValueImage(const int recNo, const QString paramName, QImage &paramValue, const int reportPage);
   void setStorageSheetValue(const int recNo, const QString paramName, QVariant &paramValue, const int reportPage);
   void setStorageSheetValueImage(const int recNo, const QString paramName, QImage &paramValue, const int reportPage);

   void setCollectModelSummarySheetValue(const int recNo, const QString paramName, QVariant &paramValue, const int reportPage);
   void setCollectModelSummarySheetValueImage(const int recNo, const QString paramName, QImage &paramValue, const int reportPage);
   void onSP_PersonalSettingBtnClicked();
   void onSP_SaftySettingBtnClicked();
   void onSP_ClientSettingBtnClicked();
   void onSP_AboutBtnClicked();

   void setEP_TreeWidgetContent(const QString & content);
   void onEP_PersonalModelAddTBtnClicked();
   void onEP_PersonalModelEditTBtnClicked();
   void onEP_PersonalModelDeleteTBtnClicked();
   void onEP_PersonalModelCollectSheerPreviewTBtnClicked();
   void onEP_PersonalModelGodownEntryPreviewTBtnClicked();
   void onEP_PersonalModelExportPreviewTBtnClicked();
   void onEP_PersonalModelStatisticsPreviewTBtnClicked();
   void onEP_PersonalModelHistoryTBtnClicked();
   void onEP_PersonalModelCreateCodeTBtnClicked();
   void onEP_PersonalModelSelectCodeTBtnClicked();
   void onEP_PersonalModelTableViewDoubleClicked(const QModelIndex &index);
   void onEP_CodeComboBoxCurrentIndexChanged(const QString & text);
   
   void onEP_CollectModelNewCollectTBtnClicked();
   void onEP_CollectModelArchiveTBtnClicked();
   void onEP_CollectModelSheerPreviewTBtnClicked();
   void onEP_CollectModelGodownEntryPreviewTBtnClicked();
   void onEP_CollectModelScreenshotPreviewTBtnClicked();
   void onEP_CollectModelInvoiceVerificationTBtnClicked();
   void onEP_CollectModelBusinessApprovalTBtnClicked();
   void onEP_CollectModelPayWarrantTBtnClicked();
   void onEP_CollectModelExportTBtnClicked();
   void onEP_CollectModelStatisticsTBtnClicked();
   void onEP_CollectModelHistoryTBtnClicked();
   void onEP_CollectModelUnArchiveTBtnClicked();
   void onEP_CollectModelRefreshTBtnClicked();
   void onEP_CollectModelLiftingProhibitionTBtnClicked();
   void onPersonalModelTableViewItemPressed(const QModelIndex &index);
   void onEP_CollectModelTableViewDoubleClicked(const QModelIndex &index);
   void onCollectModelTableViewItemPressed(const QModelIndex &index);
   void onEP_CollectModelAddLockTBtnTBtnClicked();
   void onEP_TreeWidgetDeleteActionTriggered();
   void onEP_TreeWidgetRenameActionTriggered();

   void onSP_UserCountBtnClicked();
   void onSP_LeaveInfoBtnClicked();
   void onSP_FilterSearchPBtnClicked();
   QString getSPLeaveInfoFilters();
   void onSP_AccountDeleteBtnClicked();
   void onSP_AccountSearchPBtnClicked();
   void onSP_AccountUserNameReturnPressed();
   void onSP_AccountStudentNumberReturnPressed();
   void onSP_AccountProjectComboxCurrentTextChanged(const QString &);
   QString getSPAccountFilters();

   void onTP_NewUserApplyBtnClicked();
   void onTP_MaterialPurchaseApplyBtnClicked();
   void onTP_LeaveApplyBtnClicked();
   void onNewUserApplyPassActionTriggered();
   void onNewUserApplyRejectActionTriggered();
   void onTP_NewUserAllPassTBtnClicked();
   void onTP_NewUserSinglePassTBtnClicked();
   void onTP_NewUserRejectTBtnClicked();
   void onTP_MaterialPurchaseAllPassTBtnClicked();
   void onTP_MaterialPurchaseRejectTBtnClicked();
   void onTP_MaterialPurchaseSinglePassTBtnClicked();
   void onTP_LeaveAllPassTBtnClicked();
   void onTP_LeaveRejectTBtnClicked();
   void onTP_LeaveSinglePassTBtnClicked();
   void onTP_MaterialPurchaseApplyTableViewDoubleClicked(const QModelIndex &index);
   void onLeaveApplyPassActionTriggered();
   void onLeaveApplyRejectActionTriggered();
   void onMaterialPurchaseApplyPassActionTriggered();
   void onMaterialPurchaseApplyRejectActionTriggered();
   void onMaterialPurchaseApplyDetailActionTriggered();
   
   void onRP_RegularMeetingReportBtnClicked();
   void onRP_PaperPatentBtnClicked();
   void onRP_DeviceManualBtnClicked();
   void onRP_SDKBtnClicked();
   void onRP_GraduateBtnClicked();
   void onRP_OtherBtnClicked();
   void onRP_MyFileBtnClicked();
   void onRP_NewFolderBtnClicked();
   void onRP_DeleteBtnClicked();
   void onRP_UploadBtnClicked();
   void onRP_DownloadBtnClicked();
   void oRP_deleteFilesBtnClicked();
   void oRP_RenameBtnClicked();
   void onRP_ReportTableViewSignals(QStringList & fileNameList);
   void onMeetingReportUploadActionTriggered();
   void onMeetingReportDownloadActionTriggered();
   void onMeetingReportDeleteActionTriggered();
   void onRP_ReportTableViewDoubleClicked(const QModelIndex &index);
   void onRP_PaperBtnClicked();
   void onRP_AcademicConferenceBtnClicked();
   void onRP_PatentBtnClicked();
   void onRP_WorksBtnClicked();
   void onRP_ResearchProjectBtnClicked();
   void onPaperAddActionTriggered();
   void onPaperEditActionTriggered();
   void onPaperDeleteActionTriggered();
   void onRP_PaperTableViewDoubleClicked(const QModelIndex &index);
   QString getRP_PaperFilters();
   void onRP_PaperAuthorComboxCurrentIndexChanged(int index);
   void onRP_PaperYearComboxCurrentIndexChanged(int index);
   void onRP_PaperTitleLineEditingFinished();
   void onPaperDownLoadActionTriggered();


   void onAcademicConferenceAddActionTriggered();
   void onAcademicConferenceEditActionTriggered();
   void onAcademicConferenceDeleteActionTriggered();
   void onRP_AcademicConferenceTableViewDoubleClicked(const QModelIndex &index);
   QString getRP_AcademicConferenceFilters();
   void onRP_AcademicConferenceAuthorComboxCurrentIndexChanged(int index);
   void onRP_AcademicConferenceYearComboxCurrentIndexChanged(int index);
   void onRP_AcademicConferenceTitleLineEditingFinished();
   void onAcademicConferenceDownLoadActionTriggered();

   void onPatentAddActionTriggered();
   void onPatentEditActionTriggered();
   void onPatentDeleteActionTriggered();
   void onRP_PatentTableViewDoubleClicked(const QModelIndex &index);
   QString getRP_PatentFilters();
   void onRP_PatentAuthorComboxCurrentIndexChanged(int index);
   void onRP_PatentYearComboxCurrentIndexChanged(int index);
   void onRP_PatentTitleLineEditingFinished();
   void onPatentDownLoadActionTriggered();

   void onWorksAddActionTriggered();
   void onWorksEditActionTriggered();
   void onWorksDeleteActionTriggered();
   void onRP_WorksTableViewDoubleClicked(const QModelIndex &index);
   QString getRP_WorksFilters();
   void onRP_WorksAuthorComboxCurrentIndexChanged(int index);
   void onRP_WorksYearComboxCurrentIndexChanged(int index);
   void onRP_WorksTitleLineEditingFinished();
   void onResearchProjectDataDownloadActionTriggered();
   void onResearchProjectPaperDownloadActionTriggered();
   void onWorksDownLoadActionTriggered();

   void onResearchProjectAddActionTriggered();
   void onResearchProjectEditActionTriggered();
   void onResearchProjectDeleteActionTriggered();
   void onRP_ResearchProjectTableViewDoubleClicked(const QModelIndex &index);
   QString getRP_ResearchProjectFilters();
   void onRP_ResearchProjectAuthorComboxCurrentIndexChanged(int index);
   void onRP_ResearchProjectYearComboxCurrentIndexChanged(int index);
   void onRP_ResearchProjectTitleLineEditingFinished();

   QString getRP_MeetingReportFilters();
   void onRP_ReporterComboBoxCurrentIndexChanged(int index);
   void onRP_UploadTimerComboBoxCurrentIndexChanged(int index);
   void onSPPS_UserNameEditBtnClicked();
   void onSPPS_SchoolNumberEditBtnClicked();
   void onSPPS_EmailEditBtnClicked();
   void onSPPS_PhoneEditBtnClicked();
   void onSPPS_BankTypeEditBtnClicked();
   void onSPPS_BankNumberEditBtnClicked();
   void onSPPS_ProjectEditBtnClicked();
   void onSPPS_UserHeadIcoBtnClicked();
   void onSPPS_ComfirmBtnClicked();

   void onSPSS_SecrecyCheckBoxClicked();

   void onSPCS_AutoStartCheckBoxClicked();
   void onSPCS_DownloadPathEditBtnClicked();
   void onSPCS_DatabaseNameEditBtnClicked();
   void onSPCS_DatabaseVersionEditBtnClicked();
   void onSPCS_DatabaseHostEditBtnClicked();
   void onSPCS_DatabasePortEditBtnClicked();
   void onSPCS_DatabaseUserNameEditBtnClicked();
   void onSPCS_DatabasePasswordEditBtnClicked();
   void onSPCS_DatabaseFrameConstructionEditBtnClicked();
   void onSPCS_DatabaseConversationalModeEditBtnClicked();
   void onSPCS_DatabaseOverTimeEditBtnClicked();
   void onSPCS_FileServerHostEditBtnClicked();
   void onSPCS_FileServerPortEditBtnClicked();
   void onSPCS_FileServerUserNameEditBtnClicked();
   void onSPCS_FileServerPasswordEditBtnClicked();

   void onSPA_ReadLogBtnClicked();
   void onSPA_DeleteLogBtnClicked();
   void onCheckUpdateClicked();
   void setField(RptFieldObject &);

   void onSP_SystemSettingBtnClicked();
   void onSPSS_UltimateAuditDeleteActionClicked();
   void onSPSS_RoutineAuditDeleteActionClicked();
   void onSPSS_AddUltimateAuditClicked();
   void onSPSS_RoutineAuditClicked();
   void onSPSS_SystemEMailComfirmBtnClicked();

private:
	void initializeUi();
	void initializeHomePageUi();
	void initializeDevicesUi();
	void initializeExpenseUi();
	void initializePersonalModelUi();
	void initializeCollectModelUi();
	void initializeApplyUi();
	void initializeCheckInUi();
	void initializeResourcesUi();
	void initializeMeetingReportUi();
	void initializePaperUi();
	void initializePatentUi();
	void initializeAcademicConferenceUi();
	void initializeWorksUi();
	void initializeResearchProjectUi();
	void initializeStatisticsUi();
	void initializeTodoUi();
	void initializeSettingsUi();
	void initializeSystemSettingsUi();

	void setWindowLogAndTitle();
	void setupToolBar();
	void setupMenuBar();
	void setSignalsAndSlots();
	void setHomePageSignalsAndSlots();
	void setDevicesSignalsAndSlots();
	void setExpenseSignalsAndSlots();
	void setPersonalModelSignalsAndSlots();
	void setCollectModelSignalsAndSlots();
	void setApplySignalsAndSlots();
	void setCheckInSignalsAndSlots();
	void setResourcesSignalsAndSlots();
	void setStatisticsSignalsAndSlots();
	void setTodoSignalsAndSlots();
	void setSettingsSignalsAndSlots();
	void setPaperSignalsAndSlots();
	void setAcademicConferenceSignalsAndSlots();
	void setPatentSignalsAndSlots();
	void setWorksSignalsAndSlots();
	void setResearchProjectSignalsAndSlots();
	void setNoticesMenuList(const QList<sUrielNotificationsMenuItem> & list);
	void NewUserAccountAuditOperation(const UserAccountStatus & status);
	void MaterialPurchaseApplyAuditOperation(const MaterialPurchaseApplyStatus & status);
	void LeaveAuditOperation(const LeaveStatus & status);
	void setMaterialPurchaseApplyImage(const QImage & image);
	void setPreviewImage(const QImage & image);
	void setAP_PreviewTable(const sUrielMaterialDeviceItem & item, QLineEdit * SerialNumber, QLineEdit * DeviceName, QLineEdit * ModelSpecification,
		QLineEdit * Unit, QLineEdit * Number, QLineEdit * UnitPrice, QLineEdit * Total);
	void queryAndUpdateNumberOfUnprocessedEvents(bool show=false);
	void setEP_HistoryModelTreeWidgetContent();
	void setEP_CollectModelTreeWidgetContent();
	void updateEP_StaffTreeWidget();
	void updateReimburseCode();
	QString getBankType(const QString &sbankType);
	QString _ToSpecialEncoding(const QString &InputStr);
	QString _FromSpecialEncoding(const QString &InputStr);
private:
	void modifySPPSInfo(const QString & info, const QString & sModifyField);
	void appAutoRun(bool bAutoRun);
private:
	Ui::UrielQtFrameworkClass ui;
	static UrielQtFramework* mw;
	UrielFtp *m_pUrielFtp{nullptr};
	QSystemTrayIcon *m_pSystemTrayIcon{ nullptr };
	QMenu * m_pFileMenu{ nullptr };
	UrielDatabase * m_pDatabase;
	UrielQtFrameworkOptions * m_pOptions{ nullptr };

	bool m_bPressed{ false };
	QPoint m_point;
	int m_nBorder{ 5 }; 

	QList<NoticesListMenuItem* > NoticesListMenuItemListWidget;
	QSpacerItem *NoticeListVerticalLayoutSpacerItem = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);


	UrielNoticesMenuTableModel * m_pUrielNoticesMenuTableModel{ nullptr };
	QSortFilterProxyModel *m_pUrielNoticesMenuTableSortFilterModel{ nullptr };
	QList<NoticesCommentItem*> m_pNoticesCommentItemList;
	QSpacerItem * m_pCommentSpacerItem{ nullptr };
	QString m_sCurrentAtStaff;

	UrielInstrumentTableModel *m_pUrielInstrumentTableModel{ nullptr };
	QSortFilterProxyModel *m_pUrielInstrumentTableSortFilterModel{ nullptr };
	bool m_bIsInstrumentSearchMode{false};
	QAction * m_pactInstrumentUseManageBorrowAction{ nullptr };
	QAction * m_pactInstrumentUseManageReturnAction{ nullptr };

	UrielCheckInTableModel *m_pUrielCheckInTableModel{ nullptr };
	QSortFilterProxyModel *m_pUrielCheckInTableSortFilterModel{ nullptr };

	QTreeWidgetItem *m_pEP_TreeWidgetRootItem{ nullptr };
	QTreeWidgetItem *m_pEP_StaffTreeWidgetRootItem{ nullptr };
	QString m_sCurrentReimburseCode;

	UrielInvoiceTableModel *m_pUrielInvoiceTableModel{ nullptr };
	QSortFilterProxyModel *m_pUrielInvoiceTableSortFilterModel{ nullptr };

	UrielInvoiceTableModel *m_pUrielInvoiceArchiveTableModel{ nullptr };
	QSortFilterProxyModel *m_pUrielInvoiceArchiveTableSortFilterModel{ nullptr };

	UrielUserCountTableModel *m_UrielUserCountTableModel{ nullptr };
	QSortFilterProxyModel *m_pUrielUserCountTableSortFilterModel{ nullptr }; 

	UrielLeaveInfoTableModel *m_UrielLeaveInfoTableModel{ nullptr };
	QSortFilterProxyModel *m_pUrielLeaveInfoTableSortFilterModel{ nullptr };

	UrielLoginTableModel *m_UrielLoginTableModel{ nullptr };
	QSortFilterProxyModel *m_pUrielLoginTableSortFilterModel{ nullptr };

	UrielUserCountTableModel  *m_UrielNewUserApplyTableModel{ nullptr };
	QSortFilterProxyModel *m_pUrielNewUserApplyTableSortFilterModel{ nullptr };

	UrielLeaveInfoTableModel *m_UrielLeaveApplyTableModel{ nullptr };
	QSortFilterProxyModel *m_pUrielLeaveApplyTableSortFilterModel{ nullptr };

	QAction * NewUserApplyPassAction{ new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/pass.png"), QStringLiteral("通过"), this) };
	QAction * NewUserApplyRejectAction{ new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/reject.png"), QStringLiteral("拒绝"), this) };

	QAction * LeaveApplyPassAction{ new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/pass.png"), QStringLiteral("通过"), this) };
	QAction * LeaveApplyRejectAction{ new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/reject.png"), QStringLiteral("拒绝"), this) };

	QAction * MaterialPurchaseApplyDetailAction{ new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/detail01.png"), QStringLiteral("详情"), this) };
	QAction * MaterialPurchaseApplyPassAction{ new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/pass.png"), QStringLiteral("通过"), this) };
	QAction * MaterialPurchaseApplyRejectAction{ new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/reject.png"), QStringLiteral("拒绝"), this) };
	
	QString m_sMaterialPurchaseApplyImagePath;
	QString m_sMaterialPurchaseModifyImagePath;
	QImage m_imgPreviewMaterialImage;

	bool m_bIsMaterialSearchMode{ false };

	UrielMaterialPurchaseApplyTableModel *m_pUrielMaterialPurchaseApplyTableModel{ nullptr };
	QSortFilterProxyModel *m_pUrielMaterialPurchaseApplyTableSortFilterModel{ nullptr };

	ExpenseOperationModel m_eExpenseOperationModel{ ExpenseOperationModel::HistoryModel};
	QList<sUrielInvoiceInfoItem> m_sMaterialList;

	QStringList m_sCollectModelStaffList;
	QList<sUrielAccountInfo> m_listCollectModelStaff;

	UrielMeetingReportTableModel *m_UrielMeetingReportTableModel{ nullptr };
	QSortFilterProxyModel *m_pUrielMeetingReportTableSortFilterModel{ nullptr };

	UrielPaperTableModel *m_UrielPaperTableModel{ nullptr };
	QSortFilterProxyModel *m_pUrielPaperTableSortFilterModel{ nullptr };

	UrielAcademicConferenceTableModel *m_UrielAcademicConferenceTableModel;
	QSortFilterProxyModel *m_pUrielAcademicConferenceTableSortFilterModel{ nullptr };

	UrielPatentTableModel *m_UrielPatentTableModel;
	QSortFilterProxyModel *m_pUrielPatentTableSortFilterModel{ nullptr };

	UrielWorksTableModel *m_UrielWorksTableModel;
	QSortFilterProxyModel *m_pUrielWorksTableSortFilterModel{ nullptr };

	UrielResearchProjectTableModel *m_UrielResearchProjectTableModel;
	QSortFilterProxyModel *m_pUrielResearchProjectTableSortFilterModel{ nullptr };

	UrielUserCountTableModel *m_UrielUltimateAuditTableModel{ nullptr };
	QSortFilterProxyModel *m_pUrielUltimateAuditTableSortFilterModel{ nullptr };

	UrielUserCountTableModel *m_UrielRoutineAuditTableModel{ nullptr };
	QSortFilterProxyModel *m_pUrielRoutineAuditTableSortFilterModel{ nullptr };

	QString m_CollectModeCurrentStaff;
	QString m_CollectModeCurrentProject;

	QAction * m_pEP_TreeWidgetDeleteAction{ nullptr };
	QAction * m_pEP_TreeWidgetRenameAction{ nullptr };
	//QHash<QString, bool> m_bIsDirectory;
	//QString m_sCurrentPath;
	//QFtp *m_pFtp;
	//QFile *m_pFile;

	//QNetworkSession *m_pNetworkSession;
	//QNetworkConfigurationManager m_Manager;
	//QString m_strUrl;
	//QString m_sRootPath;
	//private slots:
	//void  ftpConnectOrDisconnect();
	////void  ftpDownloadFile();
	////void  ftpCancelDownload();
	//void  ConnectToFtp();
	//void  ftpCommandFinished(int commandId, bool error);
	
	//void  ftpProcessItem(QTreeWidgetItem *item, int column);
	//void  ftpCdToParent();
	//void  ftpUpdateDataTransferProgress(qint64 readBytes,
	//	qint64 totalBytes);
	
	private slots:
	void  ftpProcessItem(QTreeWidgetItem *item, int column);
	void ftpEnableDownload(QTreeWidgetItem*, QTreeWidgetItem*);
	void  ftpAddToList(const QUrielUrlInfo &urlInfo);
	void ftpClearFileTreeWidget();
	void FileTreeWidgetClear();
	void onGUISetCursor();
}; 
