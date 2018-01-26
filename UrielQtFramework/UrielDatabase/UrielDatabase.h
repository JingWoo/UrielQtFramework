#ifndef __URIEL_DATABASE_H__
#define __URIEL_DATABASE_H__

#include <QtSQL>
#include "UrielDefinition/UrielDefinition.h"
QT_FORWARD_DECLARE_CLASS(UrielQtFrameworkOptions)
QT_FORWARD_DECLARE_CLASS(UrielNoticesMenuTableModel)
QT_FORWARD_DECLARE_CLASS(UrielInstrumentTableModel)
QT_FORWARD_DECLARE_CLASS(UrielInstrumentBorrowReturnHistoryTableModel)
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
class UrielDatabase
{
public:
	UrielDatabase(UrielQtFrameworkOptions *option);
	~UrielDatabase();
	
public:
	void setDatabaseParameters(const sUrielDBItem & item);
	bool connectDatabase( QString & sReslut);
	bool reconnectDatabase(const sUrielDBItem & item, QString & sReslut);

	bool verifyUserNameAndPassword(const QString & user_name, const QString &pwd ,bool & exist, QString & status, QString & name);

	bool insertUserAccount(const QString &sName, const QString & sID, const QString & sPhone, const QString & sEmail, const QString & sPassword, QString & errorInfo);
	bool insertUserAccount(const sUrielAccountInfo &account, QString & errorInfo);
	bool getUserAccount(sUrielAccountInfo &account,const QString & sName);
	bool getAllUserName(QStringList &UserList);
	bool updateUserCountInfo(const QString & sModifyField, const QString & value, const QString & sSearchField, const QString & SearchValue);
	bool updateUserHeadIco( const QImage & value,const QString & SearchValue);
	bool deleteUserAccountByID(const QString &id);
	bool getAllProjectListByAccount(QStringList & ProjectList);
	bool getAllAccountEmail(QStringList & EMailList,QStringList & NameList);

	bool getCurrentDataNotificationCount(int & count);
	bool getLastNoticesCodeID(int &code );
	bool insertNotification(const sUrielNotificationsItem & notifycationItem, QString & sReslut);
	bool deleteNotification(const QString & sCodeId);
	bool getNotification(sUrielNotificationsItem & item,const QString & sCodeId);
	bool updateNotification(sUrielNotificationsItem & item);
	bool updateNoticesMenuTableModel(QString  strSQL = "");
	bool getAllNotificationsInATimePeriod(QList<sUrielNotificationsMenuItem> &NotificationsMenuItem, int daynum);
	UrielNoticesMenuTableModel * creatNoticesMenuTableModel();

	bool insertNoticesComment(const sUrielCommentItem & comment, QString &errorInfo);
	bool getNoticesCommentList(QList<sUrielCommentItem>&  commentList,const QString & codeId);

	UrielInstrumentTableModel * creatInstrumentTableModel();
	bool insertInstrument(const sUrielInstrumentItem& item, QString & error);
	bool deleteInstrumentByID(const QString & sId);
	bool updateInstrument(const sUrielInstrumentItem& item);
	bool updateInstrumentWithStatusAndAddressByID(const QString &status, const QString &address,const QString & sId);
	bool updateInstrumentTableModel(QString  strSQL = "");
	bool getInstrumentByID(sUrielInstrumentItem & item, const QString & sId);
	bool getInstrumentByName(sUrielInstrumentItem & item, const QString & Name);
	bool getInstrumentStatusByID(QString & status, const QString & sId);
	bool getInstrumentSDKFiles(QString & files, const QString & sId);
	bool getDistinctProjectFromInstrument(QStringList &ProjectList);
	bool getInstrumentByProjectTeam(QStringList &Instrument,const QString &ProjectTeam);
	bool getInstrumentByInstrumentNameAndProjectTeam(sUrielInstrumentItem &instrumentItem, const QString & ProjectTeam, const QString &  InstrumentName);
	bool getDistinctChargerFromInstrument(QStringList &ChargerList);
	bool getInstrumentByCharger(QStringList &Instrument, const QString &Charger);
	bool getInstrumentByInstrumentNameAndCharger(sUrielInstrumentItem &instrumentItem, const QString &Charger, const QString & InstrumentName);
	bool getInstrumentBySearch(QStringList &InstrumentList, const QString &  searchName);
	
	bool insertInstrumentUseLog(const sUrielInstrumentUseLog& item, QString & error);

	UrielInstrumentBorrowReturnHistoryTableModel * creatInstrumentBorrowReturnHistoryTableModel();
	bool updateInstrumentBorrowReturnHistoryTableModel(QString  strSQL = "");
	bool getInstrumentUseLogByID(sUrielInstrumentUseLog & item,const QString & id);

	UrielCheckInTableModel* creatCheckInTableModel();
	bool updateCheckInTableModel(QString  strSQL = "");
	bool deleteEventFromCheckInByID(const QString & sId);
	bool insertVacationLeaveEvent(const sUrielVacationLeaveItem & item);
	bool updateVacationLeaveEvent(const sUrielVacationLeaveItem & item);

	bool insertReimburseCode(const QString &ReimburseCode);
	bool getAvailableReimburseCodeList(QStringList &AvailableReimburseCodeList);
	bool getAllReimburseCodes(QStringList &ReimburseCodeList);
	bool getAllProjectByReimburseCode(QStringList &ProjecteList,const QString & ReimburseCode);
	int  getInvoiceIDByReimburseCode_Project_Name(const QString & ReimburseCode, const QString & szInvoiceProject, const QString &szInvoiceName);
	UrielInvoiceTableModel * creatInvoiceTableModel();
	bool insertInvoice(const sUrielInvoiceInfoItem & item, QString &error);
	bool updateInvoice(const sUrielInvoiceInfoItem & item, QString &error);
	bool updateInvoiceTableModel(QString  strSQL = "");
	bool getInvoiceListbyReimburseCodeAndType(QStringList & childList, const QString & ReimburseCode, const QString &sProject, const QString &ReimbursePerson);
	bool getInvoiceInfoByID(sUrielInvoiceInfoItem & item,const QString & sId);
	bool getMaterialCostInvoiceListByReimburseCode(QList<sUrielInvoiceInfoItem> & itemlist, const QString & ReimburseCode);
	bool getMaterialCostInvoiceListByReimburseCode(QList<sUrielInvoiceInfoItem> & itemlist, const QString & ReimburseCode,const QString &ArchiveName);
	bool getAllInvoiceListByReimburseCode(QList<sUrielInvoiceInfoItem> & itemlist, const QString & ReimburseCode);
	bool deleteInvoiceInfoByID(const QString & sId);
	bool getAllInvoiceListByReimburseCodeAndPersonAndArchives(QList<sUrielInvoiceInfoItem> & itemlist, 
		const QString & sReimburseCode, const QString & sPerson, const QString & sArchives);
	bool getReimbursePersonListByReimburseCodeAndArchives(QStringList & ReimbursePersonList, const QString & sReimburseCode, const QString & sArchives);
	bool getImageListByReimburseCodeAndArchives(QStringList & ImageList, const QString & sReimburseCode, const QString & sArchives);
	bool getVerifyImageListByReimburseCodeAndArchives(QStringList & ImageList, const QString & sReimburseCode, const QString & sArchives);
	double getSumOfClaimSummaryProject(const ExpenseItemEnum &ExpenseItem, const QString & ReimburseCode);
	double getSumOfClaimSummaryProject(const ExpenseItemEnum &ExpenseItem, const QString & ReimburseCode,const QString &ArchiveName);
	double getTotalSumOfClaimSummary(const QString & ReimburseCode);
	double getTotalSumOfClaimSummary(const QString & ReimburseCode, const QString &ArchiveName);
	int getTotalBillCount(const QString & ReimburseCode);
	int getTotalBillCount(const QString & ReimburseCode, const QString &ArchiveName);
	double getTotalSumOfClaimSummaryOfStaff(const QString & ReimburseCode, const QString &ArchiveName,const QString & staff);

	bool insertReimburseArchives(const sUrielReimburseArchivesItem & item);
	bool getArchivesByReimburseCode(QList<sUrielReimburseArchivesItem> & ArchivesList, const QString &ReimburseCode);
	bool deleteReimburseArchives(const sUrielReimburseArchivesItem & item);
	bool renameReimburseArchives(const sUrielReimburseArchivesItem & item,const QString & newName);
	bool getProjectListbyReimburseCodeAndArchives(QStringList& ProjectItemList, const QString &ReimburseCode, const QString &ArchivesName);
	bool getInvoiceListbyReimburseCodeAndArchivesAndProject(QList<sUrielInvoiceInfoItem>& InvoiceList,
		const QString &sReimburseCode, const QString &sArchivesName, const QString &sProject);
	bool getunArchivedStaffByReimburseCode(QStringList &unArchivedStaffList, const QString &sReimburseCode);
	bool getArchivedStaffByReimburseCode(QStringList &ArchivedStaffList, const QString &sReimburseCode);
	int getunArchivedCountByReimburseCodeAndStaff(const QString &sReimburseCode, const QString &staff);
	int getArchivedCountByReimburseCodeAndStaff(const QString &sReimburseCode, const QString &staff);
	bool getInvoicetListByReimburseCodeAndStaff(QList<sUrielInvoiceInfoItem>& InvoicetList, const QString & ReimburseCode, const QString &staff);
	bool getProjectListByReimburseCodeAndStaff(QStringList &ProjecteList, const QString & ReimburseCode, const QString &staff);
	int getunArchivedCountByReimburseCodeAndProjectAndStaff(const QString &sReimburseCode, const QString &staff, const QString &sProject);
	int getInvoiceCountByReimburseCodeAndProjectAndStaff(const QString &sReimburseCode, const QString &staff, const QString &sProject);

	UrielInvoiceTableModel * creatInvoiceArchiveTableModel();
	bool updateInvoiceArchiveTableModel(QString  strSQL = "");
	UrielUserCountTableModel * creatUserCountTableModel();
	bool updateUserCountTableModel(QString  strSQL = "");
	bool archiveInvoiceIntoSummarySheet(const QString & sid, const QString &ArchivesName);
	bool unArchiveInvoiceFromSummarySheet(const QString & sid, const QString &ArchivesName);
	bool unArchiveAllInvoiceFromSpecifiedSummarySheet(const QString&sReimburseCode, const QString& ArchivesName);
	bool renameAllInvoiceArchiveFromSpecifiedSummarySheet(const QString&sReimburseCode, const QString& ArchivesName, const QString& newArchivesName);
	bool getReimburseStatusByReimburseCode(sUrielReimburseStatusItem & item, const QString &sReimburseCode);
	bool updateReimburseStatusByReimburseCode(sUrielReimburseStatusItem & item, const QString &sReimburseCode);
	int getInvoiceCountByReimburseCodeAndStaff(const QString&sReimburseCode, const QString& staff);
	int isAllInvoiceArchived(const QString&sReimburseCode);
	bool getStaffListByReimburseCodeAndArchivesName( QStringList& Staff,const QString&sReimburseCode, const QString&sArchivesName);
	bool getFinishReimburseCode(QStringList& FinishReimburseCodeList);
	bool liftingProhibitReimburseCode(const QString &ReimburseCode);
	bool ReimburseCodeAddLock(const QString &sReimburseCode);

	UrielLeaveInfoTableModel * creatLeaveInfoTableModel();
	bool updateLeaveInfoTableModel(QString  strSQL = "");
	bool insertLoginInfo(const sUrielLoginInfoItem& loginInfoItem);
	UrielLoginTableModel * creatLoginTableModel(const QString & userName);

	UrielUserCountTableModel *creatNewUserApplyTableModel();
	bool updateNewUserApplyTableModel(QString  strSQL = "");
	int getNumberOfUnAuditedAccount();
	bool auditedNewUserApply(const QString & name, const QString & admin, const UserAccountStatus& status);
	bool auditedAllNewUserApply(const QString & admin);

	UrielMaterialPurchaseApplyTableModel * creatMaterialPurchaseApplyTableModel();
	bool updateMaterialPurchaseApplyTableMode(QString  strSQL = "");
	int getNumberOfUnAuditedMaterialPurchaseApply();
	int getMaterialPurchaseApplyIdByApplicationNumber(const QString &ApplicationNumber);
	bool auditedMaterialPurchaseApply(const QString & id, const QString & admin, const MaterialPurchaseApplyStatus &status, const QString & suggest = "");
	bool auditedAllMaterialPurchaseApply(const QString & admin);

	UrielLeaveInfoTableModel *creatLeaveApplyTableModel();
	bool updateLeaveApplyTableModel(QString  strSQL = "");
	int getNumberOfUnAuditedLeaveApply();
	bool auditedLeaveApply(const QString & name, const QString & admin, const LeaveStatus& status);
	bool auditedAllLeaveApply(const QString & admin);

	int getLastMaterialPurchaseApplyCodeID();
	bool insertMaterialDeviceApply(const sUrielMaterialPurchaseApplyItem & MaterialPurchaseApplyItem);
	bool insertMaterialDevice(const sUrielMaterialDeviceItem & MaterialDeviceItem);
	bool getDistinctApplicationNumberFromMaterialPurchaseApply(QStringList &ProjectList,const QString & name);
	bool getMaterialNameByApplicationNumber(QStringList & MaterialList, const QString & var);
	bool getMaterialPurchaseApplyByApplicationNumber(sUrielMaterialPurchaseApplyItem & MaterialPurchaseApplyItem, const QString & ApplicationNumber);
	bool getAllMaterialDeviceListByApplicationNumber(QList<sUrielMaterialDeviceItem> &MaterialDeviceList, const QString & ApplicationNumber);
	bool getMaterialBySearch(QStringList &MaterialList, const QString & searchName);
	QString getApplicationNumberByMaterialName(const QString & name);
	QString getProjectName(const ExpenseItemEnum &ExpenseItem);

	UrielMeetingReportTableModel* creatMeetingReportTableModel();
	bool updateMeetingReportTableModel(QString  strSQL = "");
	bool insertMeetingReport(const sUrielMeetingReportItem & meetingReport);
	bool updateMeetingReportDownloadCount(const QString & id);
	bool delectMeetingReport(const QString & id);

	UrielPaperTableModel *creatPaperTableModel();
	bool updatePaperTableModel(QString  strSQL = "");
	bool getAllPaperAuthorName(QStringList& AuthorList);
	bool insertPaper(sUrielPaperItem Paper);
	bool updatePaper(sUrielPaperItem Paper);
	bool getPaperInfoByID(sUrielPaperItem& item, const QString & id);
	bool deletePaper(const QString & id);
	bool updatePaperDownloadCount(const QString & id);

	UrielAcademicConferenceTableModel *creatAcademicConferenceTableModel();
	bool updateAcademicConferenceTableModel(QString  strSQL = "");
	bool getAllAcademicConferenceAuthorName(QStringList& AuthorList);
	bool insertAcademicConference(sUrielAcademicConferenceItem AcademicConference);
	bool updateAcademicConference(sUrielAcademicConferenceItem AcademicConference);
	bool getAcademicConferenceInfoByID(sUrielAcademicConferenceItem& item, const QString & id);
	bool deleteAcademicConference(const QString & id);
	bool updateAcademicConferenceDownloadCount(const QString & id);


	UrielPatentTableModel *creatPatentTableModel();
	bool updatePatentTableModel(QString  strSQL = "");
	bool getAllPatentAuthorName(QStringList& AuthorList);
	bool insertPatent(sUrielPatentItem Patent);
	bool updatePatent(sUrielPatentItem Patent);
	bool getPatentInfoByID(sUrielPatentItem& item, const QString & id);
	bool deletePatent(const QString & id);
	bool updatePatentDownloadCount(const QString & id);

	UrielWorksTableModel *creatWorksTableModel();
	bool updateWorksTableModel(QString  strSQL = "");
	bool getAllWorksAuthorName(QStringList& AuthorList);
	bool insertWorks(sUrielWorksItem Works);
	bool updateWorks(sUrielWorksItem Works);
	bool getWorksInfoByID(sUrielWorksItem& item, const QString & id);
	bool deleteWorks(const QString & id);
	bool updateWorksDownloadCount(const QString & id);

	UrielResearchProjectTableModel *creatResearchProjectTableModel();
	bool updateResearchProjectTableModel(QString  strSQL = "");
	bool getAllResearchProjectAuthorName(QStringList& AuthorList);
	bool insertResearchProject(sUrielResearchProjectItem ResearchProject);
	bool updateResearchProject(sUrielResearchProjectItem ResearchProject);
	bool getResearchProjectInfoByID(sUrielResearchProjectItem& item, const QString & id);
	bool deleteResearchProject(const QString & id);
	bool updateResearchProjectDownloadCount(const QString & id);
	QString encode(const QString &);
	QString decode(const QString &);

	bool getSystemSettings(sUrielSystemSettingsItem & item);
	bool updateSystemEMailSettings(sUrielSystemSettingsItem & item);

	UrielUserCountTableModel* creatUltimateAuditTableModel();
	bool updateUltimateTableModel(QString  strSQL = "");
	bool getAllAuditor(QStringList & email, QStringList & name,const QString & level);
	
	UrielUserCountTableModel* creatRoutineAuditTableModel();
	bool updateRoutineTableModel(QString  strSQL = "");

	bool resetAuditlevel(const QString & id);
	bool setAuditlevel(const QString & name, const QString & level);
private:
	QSqlDatabase m_Database;
	sUrielDBItem m_stUrielDBItem;

	UrielQtFrameworkOptions * m_pOptions{ nullptr };

	UrielNoticesMenuTableModel * m_pUrielNoticesMenuTableModel{ nullptr };
	QString m_szNoticesBrowserQuery;
	QString m_szNoticesPreviousQuery;

	UrielInstrumentTableModel *m_pUrielInstrumentTableModel{ nullptr };
	QString m_szInstrumentBrowserQuery;
	QString m_szInstrumentPreviousQuery;

	UrielInstrumentBorrowReturnHistoryTableModel *m_pUrielInstrumentBorrowReturnHistoryTableModel{ nullptr };
	QString m_szInstrumentBorrowReturnHistoryBrowserQuery;
	QString m_szInstrumentBorrowReturnHistoryPreviousQuery;

	UrielCheckInTableModel *m_pUrielCheckInTableModel{ nullptr };
	QString m_szCheckInBrowserQuery;
	QString m_szCheckInPreviousQuery;

	UrielInvoiceTableModel *m_pUrielInvoiceTableModel{ nullptr };
	QString m_szInvoiceBrowserQuery;
	QString m_szInvoicePreviousQuery;

	UrielInvoiceTableModel *m_pUrielInvoiceArchiveTableModel{ nullptr };
	QString m_szInvoiceArchiveBrowserQuery;
	QString m_szInvoiceArchivePreviousQuery;

	UrielUserCountTableModel *m_pUrielUserCountTableModel{ nullptr };
	QString m_szUserCountBrowserQuery;
	QString m_szUserCountPreviousQuery;

	UrielLeaveInfoTableModel *m_pUrielLeaveInfoTableModel{ nullptr };
	QString m_szLeaveInfoBrowserQuery;
	QString m_szLeaveInfoPreviousQuery;

	UrielLoginTableModel *m_pUrielLoginTableModel{ nullptr };
	QString m_szLoginBrowserQuery;
	QString m_szLoginPreviousQuery;

	UrielUserCountTableModel *m_UrielNewUserApplyTableModel{ nullptr };
	QString m_szNewUserApplyBrowserQuery;
	QString m_szNewUserApplyPreviousQuery;

	UrielLeaveInfoTableModel *m_UrielLeaveApplyTableModel{ nullptr };
	QString m_szLeaveApplyBrowserQuery;
	QString m_szLeaveApplyPreviousQuery;

	UrielMaterialPurchaseApplyTableModel *m_pUrielMaterialPurchaseApplyTableModel{ nullptr };
	QString m_szMaterialPurchaseApplyBrowserQuery;
	QString m_szMaterialPurchaseApplyPreviousQuery;

	UrielMeetingReportTableModel *m_pUrielMeetingReportTableModel{ nullptr };
	QString m_szMeetingReportBrowserQuery;
	QString m_szMeetingReportPreviousQuery;

	UrielPaperTableModel *m_pUrielPaperTableModel{ nullptr };
	QString m_szPaperBrowserQuery;
	QString m_szPaperPreviousQuery;

	UrielAcademicConferenceTableModel *m_pUrielAcademicConferenceTableModel{ nullptr };
	QString m_szAcademicConferenceBrowserQuery;
	QString m_szAcademicConferencePreviousQuery;

	UrielPatentTableModel *m_pUrielPatentTableModel{ nullptr };
	QString m_szPatentBrowserQuery;
	QString m_szPatentPreviousQuery;

	UrielWorksTableModel *m_pUrielWorksTableModel{ nullptr };
	QString m_szWorksBrowserQuery;
	QString m_szWorksPreviousQuery;

	UrielResearchProjectTableModel *m_pUrielResearchProjectTableModel{ nullptr };
	QString m_szResearchProjectBrowserQuery;
	QString m_szResearchProjectPreviousQuery;

	UrielUserCountTableModel *m_UrielUltimateAuditTableModel{ nullptr };
	QString m_szUltimateAuditBrowserQuery;
	QString m_szUltimateAuditPreviousQuery;

	UrielUserCountTableModel *m_UrielRoutineAuditTableModel{ nullptr };
	QString m_szRoutineAuditBrowserQuery;
	QString m_szRoutineAuditPreviousQuery;
};

#endif /*__URIEL_DATABASE_H__*/