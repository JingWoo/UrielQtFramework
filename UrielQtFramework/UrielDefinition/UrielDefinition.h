#ifndef __URIEL_DEFINITION_H__
#define __URIEL_DEFINITION_H__

#include <QDateTime>
#include <QIcon>
#include <QImage>
#include "ThirdPartyLibraries\SMTPEmail\SmtpMime"
typedef struct _SUrielDBItem
{
	bool	m_bLinking;		//���ݿ����ӷ�ʽ��False���Ͽ�ʽ���ӣ�True������ʽ
	int		m_iTimeOut;		//���ӳ�ʱ�޶� Ĭ��5s ��λ����
	QString m_strDBType;	//���ݿ����ͣ�MySQL
	QString m_strVersion;	//���ݿ�汾
	QString m_strHost;		//��������
	int		m_iPort;		//�����˿�
	QString m_strSchema;	//���ݿ���
	QString m_strUser;		//���������û���
	QString m_strPwd;		//�û�����
	/*_SUrielDBItem & operator=(const _SUrielDBItem &item)
	{
	if (this=&item)
	{
	return *this;
	}
	this->m_bLinking=item.m_bLinking;
	this->m_iPort=item.m_iPort;
	this->m_iTimeOut=item.m_iTimeOut;
	this->m_strDBType=item.m_strDBType;
	this->m_strHost=item.m_strHost;
	this->m_strPwd=item.m_strPwd;
	this->m_strSchema=item.m_strUser;
	this->m_strUser=item.m_strUser;
	this->m_strVersion=item.m_strVersion;
	return *this;
	}*/
}sUrielDBItem, *pUrielDBItem;


typedef struct _SUrielFTPItem
{
	QString m_sHostIp;
	int m_iPort;
	QString m_sUserName;
	QString m_sPassword;
	QString m_sProfile;
	_SUrielFTPItem() :m_sHostIp("127.0.0.1"), m_iPort(21), m_sUserName("root"), m_sPassword("123456"), m_sProfile("Public") {}


}sUrielFTPItem,*pUrielFTPItem;

typedef struct _SUrielAccountInfo
{
	QString m_sName;
	QString m_sSchoolWorkNumber;
	QString m_sEmail;
	QString m_sPhoneNumber;
	QString m_sBankType;
	QString m_sBankCardNumber;
	QString m_sProjectTeam;
	QImage m_imgHeadIco;
	QString m_sPassword;
	QString m_sSafeMode;
	int m_iCouldDiskSpaceSize;
	int m_iUsedCouldDiskSpaceSize;
	QDateTime m_tApplyTime;
	QString m_sAuditor;
	QDateTime m_sAuditorTime;
	QString m_sStatus;
	QString m_sPermision;

	_SUrielAccountInfo() :m_sName(""), m_sSchoolWorkNumber(""), m_sEmail(""), m_sPhoneNumber(""), m_sBankType(QStringLiteral("")),\
		m_sBankCardNumber(""), m_sProjectTeam(""), m_imgHeadIco(""), m_sPassword("123456"), m_sSafeMode('N'), \
		m_iCouldDiskSpaceSize(50), m_iUsedCouldDiskSpaceSize(0), m_tApplyTime(QDateTime::currentDateTime()), m_sAuditor(""), \
		m_sAuditorTime(QDateTime::currentDateTime()), m_sStatus("NOT AUDITED"), m_sPermision("regular user") {}


}sUrielAccountInfo, *pUrielAccountInfo;


typedef struct _SUrielNotificationsItem
{
	QString m_sCode;	//֪ͨ���
	QString m_sTitle;    
	QString m_sImportantDegree;
	QString m_sFilePaths;
	QString m_sContent;
	QDateTime m_tReleaseTime;
	QString m_sNotifingPublisher;
}sUrielNotificationsItem, *pUrielNotificationsItem;


typedef struct _SUrielNotificationsMenuItem
{
	QString m_sCode;	//֪ͨ���
	QString m_sTitle;
	QString m_sImportantDegree;
	QString m_sContent;
	QDateTime m_tReleaseTime;
}sUrielNotificationsMenuItem, *pUrielNotificationsMenuItem;

typedef struct _SUrielCommentItem
{
	QString m_sCodeId;
	QString m_sComment;
	QString m_sStaff;
	QDateTime m_sTime;
	QString m_sAtStaff;
} sUrielCommentItem, *pUrielCommentItem;

typedef struct _SUrielCommentData
{
	QImage m_imgHeadIco;
	QString m_sName;
	QString m_sContent;
	QString m_sTime;
} sUrielCommentData, *pUrielCommentData;

typedef struct _SUrielInstrumentUseLog
{
	QString m_sUseLogId{ "" };
	QString m_sInstrumentKey{ "" };
	QString m_sInstrumentName{ "" };
	QString m_sBorrowReturnStaff{ "" };
	QString m_sAuditor{ "" };
	QString m_sBorrowReturnAddress{ "" };
	QDateTime m_sBorrowReturnTime{ QDateTime::currentDateTime() };
	QString m_sBorrowReturnStatus{ "" };
	QString m_sDescription{ "" };
} sUrielInstrumentUseLog, *pUrielInstrumentUseLog;

typedef struct _SUrielVacationLeaveItem
{
	QString m_sId{ "" };
	QString m_sType{ "" };
	QString m_sApplyPerson{ "" };
	QString m_sEventName{ "" };
	QString m_sDescripation{ "" };
	QDateTime m_tApplyTime{ QDateTime::currentDateTime() };
	QDateTime m_tStartTime{ QDateTime::currentDateTime() };
	QDateTime m_tEndTime{ QDateTime::currentDateTime() };
	QString m_sAuditState{ "" };
	QString m_sAuditor{ "" };
	QString m_sAuditorSuggest{ QStringLiteral("δ���") };
	QDateTime m_tAuditTime{ QDateTime::currentDateTime() };
} sUrielVacationLeaveItem, *pUrielVacationLeaveItem;

enum class TimeFilterEnum
{
	NEARLY_A_DAT,
	NEARLY_A_WEEK,
	NEARLY_A_MONTH,
	NEARLY_A_YEAR,
	ALL
};
Q_DECLARE_METATYPE(TimeFilterEnum);

enum class ExpenseItemEnum
{
	LocalTransportation,//���ڽ�ͨ��
	OfficeSupplies,//�칫��Ʒ
	PurchaseOfProfessionalMaterials, //רҵ���Ϲ��÷�
	PurchaseOfExperimentalMaterials,//ʵ����Ϲ��÷�
	SportingGoodsPurchaseFee,//������Ʒ���÷�
	XeroxFee,//���ϸ�ӡ��
	Typography,//����ӡˢ��
	MaterialTestingAndProcessingFee,//���ϲ��Լӹ���
	LodgingExpenses,//ʵϰ��
	StudentActivityFee,//ѧ�����
	Correspondence,//ͨѶ��
	PostFee,//�ʼķ�
	SelfServiceCost,//�Ա�������
	MotorVehicleMaintenance,//������ά�޷�
	OfficeEquipmentMaintenance,//�칫�豸ά�޷�
	EquipmentMaintenanceFee,//�����豸ά�޷�
	TrainingFees,//��ѵ��
	EntertainmentExpense,//�д���
	ConstructionOfFixedAssets,//�̶��ʲ�������
	Streamer,//���
	Other//����
};
Q_DECLARE_METATYPE(ExpenseItemEnum);

typedef struct _SUrielInstrumentItem
{
	int m_iId{0};
	QString m_sName{""};
	QString m_sModel{ "" };
	QString m_sVender{ "" };
	double m_dPrice{0.0};
	QDateTime m_tPurchaseTime{ QDateTime::currentDateTime() };
	int m_iGuaranteePeriod{0};
	QString m_sProjectTeam{ "" };
	QString m_sPresentPersonInCharge{ "" };
	QString m_sStatus{ "" };
	QString m_sInstrumentAddress{ "" };
	QString m_sSDKAddress{ "" };
	QString m_sDescription{ "" };
	QString m_sInstrumentImage{ "" };
} sUrielInstrumentItem, *pUrielInstrumentItem;

typedef struct _SUrielInvoiceInfoItem
{
	int m_iId{ 0 };
	QString m_sReimburseCode{ "" };
	QString m_sType{ "" };
	QString m_sName{ "" };
	QString m_sModel{ "" };
	int m_iQuantity{ 0 };
	QString m_sUnit{ "" };
	double m_dUnivalent{ 0.00 };
	double m_dAggregateAmount{ 0.00 };
	QString m_sDescription{ "" };
	QString m_sInvoiceImagePath{ "" };
	QString m_sBuyScreenshotPath{ "" };
	QString m_sVerificationImagePath{ "" };
	QString m_sReimbursePerson{ "" };
	QDateTime m_tReimburseTime{ QDateTime::currentDateTime() };
	QString m_sFilingState{ QStringLiteral("δ�鵵") }; 
	QString m_sArchivesName{ "" };
	QString m_sRemark{ "" };
} sUrielInvoiceInfoItem, *pUrielInvoiceInfoItem;

typedef struct _SUrielReimburseArchivesItem
{
	int m_iId{ 0 };
	QString m_sReimburseCode{ "" };
	QString m_sArchivesName{ "" };
	int m_iInvoiceQuantity{ 0 };
} sUrielReimburseArchivesItem, *pUrielReimburseArchivesItem;

typedef struct _SUrielLoginInfoItem
{
	QString m_sUserName{ "" };
	QString m_sHostName{ "" };
	QString m_sIP{ "" };
	QString m_sMac{ "" };
	QDateTime m_tLoginTime{ QDateTime::currentDateTime() };
} sUrielLoginInfoItem, *pUrielLoginInfoItem;

enum class UserAccountStatus
{
	Aduited,
	UnAduited,
	Rejected
};

enum class MaterialPurchaseApplyStatus
{
	Aduited,
	UnAduited,
	Rejected
};

enum class LeaveStatus
{
	Aduited,
	UnAduited,
	AuditNotThrough
};



typedef struct _SUrielMaterialDeviceItem
{
	int m_iId{ 0 };
	QString m_sApplicationNumber{ "" };
	QString m_sSerialNumber{ "" };
	QString m_sMaterialName{ "" };
	QString m_sModelSpecification{ "" };
	QString m_sUnit{ "" };
	QString m_sQuantity{ "" };
	QString m_sUnitPrice{ "" };
	QString m_sTotal{ "" };
} sUrielMaterialDeviceItem, *pUrielMaterialDeviceItem;

typedef struct _SUrielMaterialPurchaseApplyItem
{
	int m_iId{ 0 };
	QString m_sApplicationNumber{ "" };
	QString m_sTotalAmount{ "" };
	QString m_sRequisitionReasons{ "" };
	QString m_sApplicant{ "" };
	QDateTime m_tDeclarationDate{ QDateTime::currentDateTime() };
	QString m_sAuditStatus{ "UnAudited" };
	QString m_sAuditOpinion{ "" };
	QString m_sReviewer{ "" };
	QDateTime m_tReviewTime{ QDateTime::currentDateTime() };
	QString m_sLinkAddress{ "" };
	QString m_sImagePath;
} sUrielMaterialPurchaseApplyItem, *pUrielMaterialPurchaseApplyItem;

enum class ExpenseOperationModel
{
	HistoryModel,
	PersonalModel,
	CollectModel
};

typedef struct _SUrielReimburseStatusItem
{
	int m_iId{ 0 };
	QString m_sReimburseCode{ "" };
	QString m_sStatus{ QStringLiteral("������") };
	int m_iReimbursedInvoicesNumber{ 0 };
	int m_iUnReimbursedInvoicesNumber{ 0 };
	double m_dTotalReimbursement{ 0.0 };
	double m_dTotalReturned{ 0.0 };
	QString m_sAggregator{ "" };
	QDateTime m_tFilingEndTime{ QDateTime::currentDateTime() };
} sUrielReimburseStatusItem, *pUrielReimburseStatusItem;

typedef struct _SUrielMeetingReportItem
{
	int m_iId{ 0 };
	QString m_sReporter{ "" };
	QString ReportPath{ "" };
	QDateTime UploadTime{ QDateTime::currentDateTime() };
	int DownLoadCount{ 0 };
} sUrielMeetingReportItem, *pUrielMeetingReportItem;

typedef struct _SUrielPaperItem
{
	int ID{ 0 };
	QString OriginalTitle{ "" };
	QString TranslationTitle{ "" };
	QString PeriodicalName{ "" };
	QString PeriodicalLevel{ "SCI" };
	QString PeriodicalLanguage{ QStringLiteral("Ӣ��") };
	QDateTime EmploymentTime{ QDateTime::currentDateTime() };
	QString VolumeNumber{ "" };
	QString StartAndEndPageNumber{ "" };
	QString InfluenceFactor{ "" };
	QString IsThesisContent{ "" };
	QString CommunicationUnit{ "" };
	QString Author{  "" };
	QString IndexedAddress{ "" }; 
	QString ServerFileAddress{ "" };
	QString Abstract{ "" };
	QString Uploader{ "" };
	QDateTime UploadTime{ QDateTime::currentDateTime() };
	int DownloadCount{ 0 };
} sUrielPaperItem, *pUrielPaperItem;

typedef struct _SUrielPatentItem
{
	int ID{ 0 };
	QString Type{ "" };
	QString Number{ "" };
	QString Name{ "" };
	QDateTime ApplyTime{ QDateTime::currentDateTime() };
	QDateTime ReleaseTime{ QDateTime::currentDateTime() };
	QDateTime AuthorizationTime{ QDateTime::currentDateTime() };
	QString CopyRightUnit{ "" };
	QString Author{ "" };
	QString IndexedAddress{ "" };
	QString ServerFileAddress{ "" };
	QString Abstract{ "" };
	QString Uploader{ "" };
	QDateTime UploadTime{ QDateTime::currentDateTime() };
	int DownloadCount{ 0 };
} sUrielPatentItem, *pUrielPatentItem;

typedef struct _SUrielWorksItem
{
	int ID{ 0 };
	QString Type{ "" };
	QString Name{ "" };
	QString PublishingHouse{ "" };
	QDateTime EmploymentTime{ QDateTime::currentDateTime() };
	QDateTime PublishingTime{ QDateTime::currentDateTime() };
	QString ISBN{ "" };
	QString PrintingTimes{ "" };
	QString Author{ "" };
	QString ServerFileAddress{ "" };
	QString Abstract{ "" };
	QString Uploader{ "" };
	QDateTime UploadTime{ QDateTime::currentDateTime() };
	int DownloadCount{ 0 };
} sUrielWorksItem, *pUrielWorksItem;


typedef struct _SUrielAcademicConferenceItem
{
	int ID{ 0 };
	QString OriginalTitle{ "" };
	QString TranslationTitle{ "" };
	QDateTime ReleaseTime{ QDateTime::currentDateTime() };
	QString ConferenceLanguage{ QStringLiteral("Ӣ��") };
	QString PublicationForm{ QStringLiteral("������") };
	QString Author{ "" };
	QString ConferenceName{ "" };
	QString ConferenceSessionsNumber{ "" };
	QString IndexedAddress{ "" };
	QString ServerFileAddress{ "" };
	QString Abstract{ "" };
	QString Uploader{ "" };
	QDateTime UploadTime{ QDateTime::currentDateTime() };
	int DownloadCount{ 0 };
} sUrielAcademicConferenceItem, *pUrielAcademicConferenceItem;


typedef struct _SAcademicConferenceLanguage{
	QString English{ QStringLiteral("Ӣ��") };
	QString Chinese{ QStringLiteral("����") };
}sAcademicConferenceLanguage, *pAcademicConferenceLanguage;

typedef struct _SUrielResearchProjectItem
{
	int ID{ 0 };
	QString Name{ "" };
	QDateTime StartTime{ QDateTime::currentDateTime() };
	QDateTime EndTime{ QDateTime::currentDateTime() };
	QString Type{ QStringLiteral("���Ҽ�") };
	QString Number{ "" };
	QString Funds{ "" };
	QString Participants{ "" };
	QString ServerDataAddress{ "" };
	QString ServerPaperAddress{ "" };
	QString IndexedAddress{ "" };
	QString Abstract{ "" };
	QString Graduates{ "" };
	QDateTime UploadTime{ QDateTime::currentDateTime() };
	QString AuditStatus{ "" };
	QString Auditor{ "" };
	QDateTime AuditTime{ QDateTime::currentDateTime() };
	int DownloadCount{ 0 };
} sUrielResearchProjectItem, *pUrielResearchProjectItem;

typedef struct _SResearchProjectType{
	QString NationalLevel{ QStringLiteral("���Ҽ�") };
	QString ProvincialLevel{ QStringLiteral("ʡ����") };
	QString InternationalSTCProject{ QStringLiteral("���ʿƼ�������Ŀ") };
	QString HorizontalProject{ QStringLiteral("���������Ŀ") };
}sResearchProjectType, *pResearchProjectType;


typedef struct _SSMTPEmailItem {

	QString subjectName{ QStringLiteral("") };
	QMap<QString, QString> recipient;//EMail - Name
	QString text{ QStringLiteral("") };
	QMap<QString, QString> attachment;
}sSMTPEmailItem, *pSMTPEmailItem;

typedef struct _SUrielSystemSettingsItem
{
	int ID{ 1 };
	QString SystemEMail{ "" };
	QString SystemEMailPassword{ "" };
	QString SystemEmailName{ "" };
	QString SystemEmailSendServer{ "" };
	QString SystemEmailSendServerPort{ "" };
	QString SystemEmailProtocol{ "SSL" };
	QString SystemVersion{ "" };
} sUrielSystemSettingsItem, *pUrielSystemSettingsItem;

#endif /*__URIEL_DEFINITION_H__*/