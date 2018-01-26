#include "UrielDatabase.h"
#include "UrielModel\NoticesMenuTableModel\NoticesMenuTableModel.h"
#include "UrielModel\InstrumentTableModel\InstrumentTableModel.h"
#include "UrielModel\InstrumentBorrowReturnHistoryTableModel\InstrumentBRHistoryTableModel.h"
#include "UrielModel\CheckInTableModel\CheckInTableModel.h"
#include "UrielModel\InvoiceTableModel\InvoiceTableModel.h"
#include "UrielModel\UserCountTableModel\UserCountTableModel.h"
#include "UrielModel\LeaveInfoTableModel\LeaveInfoTableModel.h"
#include "UrielModel\LoginTableModel\LoginTableModel.h"
#include "UrielModel\MaterialPurchaseApplyTableModel\MaterialPurchaseApplyTableModel.h"
#include "UrielQtFrameworkOptions\UrielQtFrameworkOptions.h"
#include "UrielModel\MeetingReportTableModel\MeetingReportTableModel.h"
#include "UrielModel\PaperTableModel\PaperTableModel.h"
#include "UrielModel\AcademicConferenceTableModel\AcademicConferenceTableModel.h"
#include "UrielModel\PatentTableModel\PatentTableModel.h"
#include "UrielModel\WorksTableModel\WorksTableModel.h"
#include "UrielModel\ResearchProjectTableModel\ResearchProjectTableModel.h"
UrielDatabase::UrielDatabase(UrielQtFrameworkOptions *option)
	:m_stUrielDBItem(option->stUrielDBItem), m_pOptions(option)
{
	setDatabaseParameters(m_stUrielDBItem);
}

UrielDatabase::~UrielDatabase()
{
	if (!m_pUrielNoticesMenuTableModel)
	{
		delete m_pUrielNoticesMenuTableModel;
		m_pUrielNoticesMenuTableModel = nullptr;
	}
}

void UrielDatabase::setDatabaseParameters(const sUrielDBItem & item)
{
	if (item.m_strDBType == "MySQL")
	{
		m_Database = QSqlDatabase::addDatabase("QMYSQL");
		m_Database.setHostName(item.m_strHost);
		m_Database.setDatabaseName(item.m_strSchema);
		m_Database.setUserName(item.m_strUser);
		m_Database.setPassword(item.m_strPwd);
		m_Database.setPort(item.m_iPort);
	}
}

bool UrielDatabase::connectDatabase(QString & sReslut)
{
	if (!m_Database.open())
	{
		sReslut = QObject::tr("Connect the Database Failed. Error:") + m_Database.lastError().text() + QObject::tr("\nPlease Contact the Database Administrator");
		return false;
	}

	if (!m_stUrielDBItem.m_bLinking)
	{
		m_Database.close();
	}
	return true;
}

bool UrielDatabase::reconnectDatabase(const sUrielDBItem & item, QString & sReslut)
{
	if (m_Database.isOpen())
	{
		m_Database.close();
	}
	if (item.m_strDBType == "MySQL")
	{
		m_Database = QSqlDatabase::addDatabase("QMYSQL");
		m_Database.setHostName(item.m_strHost);
		m_Database.setDatabaseName(item.m_strSchema);
		m_Database.setUserName(item.m_strUser);
		m_Database.setPassword(item.m_strPwd);
		m_Database.setPort(item.m_iPort);
	}
	return m_Database.open();
}

bool UrielDatabase::verifyUserNameAndPassword(const QString & user_name, const QString &pwd, bool & exist, QString & status, QString & AccountName)
{
	QString strSQL = "SELECT NAME,PASSWORD,STATUS FROM account_number WHERE NAME  = '" + user_name + "' OR SCHOOL_WORK_NUMBER= '" + user_name + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	QStringList names;
	QStringList query_reslut;
	QStringList status_reslut;
	while (mQuery.next())
	{
		exist = true;
		names<< (mQuery.value(0).toString());
		query_reslut << (mQuery.value(1).toString());
		status_reslut<< (mQuery.value(2).toString());
	}

	for (int i = 0; i<query_reslut.size(); ++i)
	{
		QByteArray byteArray;
		byteArray.append(pwd);
		QCryptographicHash hash(QCryptographicHash::Sha3_512);
		hash.addData(byteArray);  // 添加数据到加密哈希值
		QString strSha_512 = hash.result().toHex();

		if (strSha_512 == query_reslut[i] && status_reslut[i] == "AUDITED")
		{
			AccountName = names[i];
			status = status_reslut[i];
			return true;
		}
	}
	if (!exist) status = "NO SUCH ACCOUNT!";
	else if(status=="")status = "PASSWORD ERROR!";
	return false;
}

bool UrielDatabase::insertUserAccount(const QString &sName, const QString & sID, const QString & sPhone, const QString & sEmail, const QString & sPassword,QString & errorInfo)
{
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("INSERT INTO account_number (NAME,SCHOOL_WORK_NUMBER,PHONE_NUMBER,EMAIL,PASSWORD,APPLY_TIME)"
		" VALUES (:NAME,:SCHOOL_WORK_NUMBER,:PHONE_NUMBER,:EMAIL,:PASSWORD,:APPLY_TIME)");
	sQuery.bindValue(":NAME", sName);
	sQuery.bindValue(":SCHOOL_WORK_NUMBER", sID);
	sQuery.bindValue(":PHONE_NUMBER", sPhone);
	sQuery.bindValue(":EMAIL", sEmail);
	sQuery.bindValue(":PASSWORD", sPassword);
	sQuery.bindValue(":APPLY_TIME", QDateTime::currentDateTime());
	if (sQuery.exec())
	{
		return true;
	}

	errorInfo= sQuery.lastError().text();
	return false;
}


bool UrielDatabase::insertUserAccount(const sUrielAccountInfo &account, QString & errorInfo)
{
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("INSERT INTO ilabmanagementsystem.account_number( NAME, SCHOOL_WORK_NUMBER, EMAIL, PHONE_NUMBER, BANK_TYPE,"
		" BANK_CARD_NUMBER, PROJECT_TEAM, HEAD_ICO, PASSWORD, SAFE_MODE, CLOUD_DISK_SPACE_SIZE, USED_CLOUD_DISK_SPACE,"
		" APPLY_TIME, AUDITOR, AUDITOR_TIME, STATUS, PERMISSION)"
		" VALUES (:NAME,:SCHOOL_WORK_NUMBER,:EMAIL,:PHONE_NUMBER,:BANK_TYPE,:BANK_CARD_NUMBER,:PROJECT_TEAM,:HEAD_ICO,:PASSWORD,:SAFE_MODE"
		",:CLOUD_DISK_SPACE_SIZE,:USED_CLOUD_DISK_SPACE,:APPLY_TIME,:AUDITOR,:AUDITOR_TIME,:STATUS,:PERMISSION)");
	sQuery.bindValue(":NAME", account.m_sName);
	sQuery.bindValue(":SCHOOL_WORK_NUMBER", account.m_sSchoolWorkNumber);
	sQuery.bindValue(":EMAIL", account.m_sEmail);
	sQuery.bindValue(":PHONE_NUMBER", account.m_sPhoneNumber);
	sQuery.bindValue(":BANK_TYPE", account.m_sBankType);
	sQuery.bindValue(":BANK_CARD_NUMBER", account.m_sBankCardNumber);
	sQuery.bindValue(":PROJECT_TEAM", account.m_sProjectTeam);
	sQuery.bindValue(":PASSWORD", account.m_sPassword);
	sQuery.bindValue(":SAFE_MODE", account.m_sSafeMode);
	sQuery.bindValue(":CLOUD_DISK_SPACE_SIZE", QString::number(account.m_iCouldDiskSpaceSize));
	sQuery.bindValue(":USED_CLOUD_DISK_SPACE", QString::number(account.m_iUsedCouldDiskSpaceSize));
	sQuery.bindValue(":APPLY_TIME", account.m_tApplyTime.toString("yyyy-MM-dd hh:mm:ss"));
	sQuery.bindValue(":AUDITOR", account.m_sAuditor);
	sQuery.bindValue(":AUDITOR_TIME", account.m_sAuditorTime.toString("yyyy-MM-dd hh:mm:ss"));
	sQuery.bindValue(":STATUS", account.m_sStatus);
	sQuery.bindValue(":PERMISSION", account.m_sPermision);
	QByteArray bytes;
	QBuffer buffer(&bytes);
	buffer.open(QIODevice::WriteOnly);
	account.m_imgHeadIco.save(&buffer, "PNG");
	sQuery.bindValue(":HEAD_ICO", bytes);
	if (sQuery.exec())
	{
		return true;
	}

	errorInfo = sQuery.lastError().text();
	return false;
}

bool UrielDatabase::getUserAccount(sUrielAccountInfo &account, const QString & sName)
{
	QString strSQL = "SELECT NAME, SCHOOL_WORK_NUMBER, EMAIL, PHONE_NUMBER, BANK_TYPE, "
		"BANK_CARD_NUMBER, PROJECT_TEAM, HEAD_ICO, PASSWORD, SAFE_MODE, CLOUD_DISK_SPACE_SIZE, USED_CLOUD_DISK_SPACE, "
		"APPLY_TIME, AUDITOR, AUDITOR_TIME, STATUS, PERMISSION FROM ilabmanagementsystem.account_number WHERE NAME  = '" + sName + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		account.m_sName = mQuery.value(0).toString();
		account.m_sSchoolWorkNumber = mQuery.value(1).toString();
		account.m_sEmail = mQuery.value(2).toString();
		account.m_sPhoneNumber = mQuery.value(3).toString();
		account.m_sBankType = mQuery.value(4).toString();
		account.m_sBankCardNumber = mQuery.value(5).toString();
		account.m_sProjectTeam = mQuery.value(6).toString();
		account.m_sPassword = mQuery.value(8).toString();
		account.m_sSafeMode = mQuery.value(9).toString();
		account.m_iCouldDiskSpaceSize = mQuery.value(10).toInt();
		account.m_iUsedCouldDiskSpaceSize = mQuery.value(11).toInt();
		account.m_tApplyTime = mQuery.value(12).toDateTime();
		account.m_sAuditor = mQuery.value(13).toString();
		account.m_sAuditorTime = mQuery.value(14).toDateTime();
		account.m_sStatus = mQuery.value(15).toString();
		account.m_sPermision = mQuery.value(16).toString();
		QImage Head_Ico;
		QByteArray barray = mQuery.value(7).toByteArray();
		Head_Ico.loadFromData(barray);
		account.m_imgHeadIco = Head_Ico;
		return true;
	}
	return false;
}

bool UrielDatabase::deleteUserAccountByID(const QString &id) {
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("DELETE FROM ilabmanagementsystem.account_number WHERE ID ='" + id + "'");
	if (sQuery.exec())
		return true;
	return false;
}

bool UrielDatabase::getAllUserName(QStringList &UserList) {
	QString strSQL = "SELECT NAME FROM ilabmanagementsystem.account_number ";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		UserList << (mQuery.value(0).toString());
	}
	return true;
}

bool UrielDatabase::getAllProjectListByAccount(QStringList & ProjectList) {
	QString strSQL = "SELECT DISTINCT PROJECT_TEAM FROM ilabmanagementsystem.account_number";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		ProjectList << (mQuery.value(0).toString());
	}
	return true;
}

bool UrielDatabase::getAllAccountEmail(QStringList & EMailList, QStringList & NameList) {
	QString strSQL = "SELECT DISTINCT EMAIL,NAME FROM ilabmanagementsystem.account_number where STATUS ='AUDITED'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		EMailList << (mQuery.value(0).toString());
		NameList << (mQuery.value(1).toString());
	}
	return true;
}


bool UrielDatabase::updateUserCountInfo(const QString & sModifyField, const QString & value , const QString & sSearchField, const QString & SearchValue) {
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	QString strSQL;
	if (sModifyField == "PASSWORD")
	{
		QByteArray byteArray;
		byteArray.append(value);
		QCryptographicHash hash(QCryptographicHash::Sha3_512);
		hash.addData(byteArray);  
		QString strSha_512 = hash.result().toHex();
		strSQL = "UPDATE ilabmanagementsystem.account_number  SET " + sModifyField + "= '" + strSha_512 + "' WHERE " + sSearchField + " = '" + SearchValue + "'";
	}else
	    strSQL = "UPDATE ilabmanagementsystem.account_number  SET "+ sModifyField +"= '" + value  + "' WHERE "+ sSearchField +" = '" + SearchValue + "'";
	sQuery.prepare(strSQL);
	if (sQuery.exec())
	{
		return true;
	}
	QString error = sQuery.lastError().text();
	return false;
}

bool UrielDatabase::updateUserHeadIco(const QImage & value, const QString & SearchValue) {
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("UPDATE ilabmanagementsystem.account_number SET HEAD_ICO=? WHERE NAME='" + SearchValue + "'");
	QByteArray bytes;
	QBuffer buffer(&bytes);
	buffer.open(QIODevice::WriteOnly);
	value.save(&buffer, "PNG");
	sQuery.bindValue(0, bytes);

	if (sQuery.exec())
	{
		return true;
	}
	//QString ss = sQuery.lastError().text();
	return false;
}

bool UrielDatabase::getCurrentDataNotificationCount(int & count)
{
	QString strSQL = "SELECT COUNT(*) FROM notifications WHERE RELEASE_TIME  = '" + QDateTime::currentDateTime().toString("yyyy-MM-dd") + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		count = (mQuery.value(0).toInt());
		return true;
	}
	return false;
}

bool UrielDatabase::getLastNoticesCodeID(int &code)
{
	QString strSQL = "SELECT CODE FROM notifications WHERE RELEASE_TIME  = '" + QDateTime::currentDateTime().toString("yyyy-MM-dd") + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	QString codeId;
	while (mQuery.next())
	{
		codeId = mQuery.value(0).toString();
	}
	code=(codeId.mid(11,3)).toInt();
	return false;
}




bool UrielDatabase::insertNotification(const sUrielNotificationsItem & notifycationItem, QString & sReslut)
{
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("INSERT INTO notifications (CODE,TITLE,IMPORTANT_DEGREE,FILES_PATH,CONTENT,RELEASE_TIME,NOTIFYING_PUBLISHER)"
		" VALUES (:CODE,:TITLE,:IMPORTANT_DEGREE,:FILES_PATH,:CONTENT,:RELEASE_TIME,:NOTIFYING_PUBLISHER)");
	sQuery.bindValue(":CODE", notifycationItem.m_sCode);
	sQuery.bindValue(":TITLE", notifycationItem.m_sTitle);
	sQuery.bindValue(":IMPORTANT_DEGREE", notifycationItem.m_sImportantDegree);
	sQuery.bindValue(":FILES_PATH", notifycationItem.m_sFilePaths);
	sQuery.bindValue(":CONTENT", notifycationItem.m_sContent);
	sQuery.bindValue(":RELEASE_TIME", notifycationItem.m_tReleaseTime.toString("yyyy-MM-dd"));
	sQuery.bindValue(":NOTIFYING_PUBLISHER", notifycationItem.m_sNotifingPublisher);
	if (sQuery.exec())
	{
		return true;
	}

	sReslut = sQuery.lastError().text();
	return false;
}

bool UrielDatabase::deleteNotification(const QString & sCodeId)
{
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("DELETE FROM notifications  WHERE CODE ='" + sCodeId + "'");
	if (sQuery.exec())
		return true;
	return false;
}

bool UrielDatabase::getNotification(sUrielNotificationsItem & item, const QString & sCodeId)
{
	QString strSQL = "SELECT CODE,IMPORTANT_DEGREE,TITLE,FILES_PATH,CONTENT,RELEASE_TIME,NOTIFYING_PUBLISHER FROM notifications WHERE CODE  = '" + sCodeId + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		item.m_sCode = mQuery.value(0).toString();
		item.m_sImportantDegree = mQuery.value(1).toString();
		item.m_sTitle = mQuery.value(2).toString();
		item.m_sFilePaths = mQuery.value(3).toString();
		item.m_sContent = mQuery.value(4).toString();
		item.m_tReleaseTime = mQuery.value(5).toDateTime();
		item.m_sNotifingPublisher = mQuery.value(6).toString();
		return true;
	}
	return false;
}

bool UrielDatabase::updateNotification(sUrielNotificationsItem & notifycationItem)
{
	QSqlQuery sQuery(m_Database);
	QSqlError er;

	/*sQuery.prepare("UPDATE notifications(TITLE,IMPORTANT_DEGREE,FILES_PATH,CONTENT,RELEASE_TIME,NOTIFYING_PUBLISHER)"
		"  VALUES (:TITLE,:IMPORTANT_DEGREE,:FILES_PATH,:CONTENT,:RELEASE_TIME,:NOTIFYING_PUBLISHER)"
		"  WHERE CODE='" + notifycationItem.m_sCode + "'");*/
	//sQuery.prepare("UPDATE notifications SET TITLE=?,IMPORTANT_DEGREE=?,FILES_PATH=?,CONTENT=?,RELEASE_TIME=?,NOTIFYING_PUBLISHER=? WHERE CODE='" + notifycationItem.m_sCode + "'");
	//sQuery.bindValue(":TITLE", notifycationItem.m_sTitle);
	//sQuery.bindValue(":IMPORTANT_DEGREE", notifycationItem.m_sImportantDegree);
	//sQuery.bindValue(":FILES_PATH", notifycationItem.m_sFilePaths);
	//sQuery.bindValue(":CONTENT", notifycationItem.m_sContent);
	//sQuery.bindValue(":RELEASE_TIME", notifycationItem.m_tReleaseTime.toString("yyyy-MM-dd"));
	//sQuery.bindValue(":NOTIFYING_PUBLISHER", notifycationItem.m_sNotifingPublisher);

	QString strSQL = "UPDATE notifications SET TITLE= '" + notifycationItem.m_sTitle + "',IMPORTANT_DEGREE= '" + notifycationItem.m_sImportantDegree +
		"',FILES_PATH= '" + notifycationItem.m_sFilePaths + "',CONTENT= '" + notifycationItem.m_sContent + "',RELEASE_TIME='" + notifycationItem.m_tReleaseTime.toString("yyyy-MM-dd")
		+ "',NOTIFYING_PUBLISHER= '" + notifycationItem.m_sNotifingPublisher + "' WHERE CODE = '" + notifycationItem.m_sCode + "'";
	sQuery.prepare(strSQL);
	if (sQuery.exec())
	{
		return true;
	}
	QString error= sQuery.lastError().text();
	return false;
}

UrielNoticesMenuTableModel * UrielDatabase::creatNoticesMenuTableModel()
{
	if (m_pUrielNoticesMenuTableModel != nullptr)
		return m_pUrielNoticesMenuTableModel;
	m_szNoticesBrowserQuery = "select CODE,IMPORTANT_DEGREE,TITLE,FILES_PATH,CONTENT,RELEASE_TIME,NOTIFYING_PUBLISHER from notifications";
	QStringList list;
	list << "CODE" << "IMPORTANT_DEGREE" << "TITLE" << "FILES_PATH" << "CONTENT" << "RELEASE_TIME" << "NOTIFYING_PUBLISHER";
	m_szNoticesPreviousQuery = m_szNoticesBrowserQuery + " order by RELEASE_TIME desc";
	m_pUrielNoticesMenuTableModel = new UrielNoticesMenuTableModel(m_szNoticesPreviousQuery, list, m_Database);
	return m_pUrielNoticesMenuTableModel;
}

bool UrielDatabase::updateNoticesMenuTableModel(QString  strSQL)
{
	if (strSQL.isEmpty())
	{
		if (m_pUrielNoticesMenuTableModel)
		{
			m_pUrielNoticesMenuTableModel->setQuery(m_szNoticesPreviousQuery);
		}
		//	std::string ssss = previous_query_.toStdString();
		return true;
	}
	QString previous_query_current = m_szNoticesBrowserQuery + strSQL + " order by RELEASE_TIME desc";

	if (m_pUrielNoticesMenuTableModel)
	{
		m_pUrielNoticesMenuTableModel->setQuery(previous_query_current);
	}
	return true;
}


bool UrielDatabase::getAllNotificationsInATimePeriod(QList<sUrielNotificationsMenuItem> &NotificationsMenuItem, int daynum)
{
	QString strSQL;
	if(daynum!=0)
		strSQL = "select CODE,IMPORTANT_DEGREE,TITLE,CONTENT,RELEASE_TIME from notifications where DATE_SUB(CURDATE(), INTERVAL " + QString::number(daynum) + " DAY) <= RELEASE_TIME";
	else
		strSQL = "select CODE,IMPORTANT_DEGREE,TITLE,CONTENT,RELEASE_TIME from notifications";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		sUrielNotificationsMenuItem item;
		item.m_sCode = (mQuery.value(0).toString());
		item.m_sImportantDegree = (mQuery.value(1).toString());
		item.m_sTitle = (mQuery.value(2).toString());
		item.m_sContent = (mQuery.value(3).toString());
		item.m_tReleaseTime = (mQuery.value(3).toDateTime());
		NotificationsMenuItem.append(item);
	}
	return true;
}



bool UrielDatabase::insertNoticesComment(const sUrielCommentItem & comment,QString &errorInfo)
{
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("INSERT INTO ilabmanagementsystem.notifications_comment( CODE_ID, COMMENT, COMMENT_STAFF, COMMENT_TIME, AT_STAFF)"
		" VALUES (:CODE_ID,:COMMENT,:COMMENT_STAFF,:COMMENT_TIME,:AT_STAFF)");
	sQuery.bindValue(":CODE_ID", comment.m_sCodeId);
	sQuery.bindValue(":COMMENT", comment.m_sComment);
	sQuery.bindValue(":COMMENT_STAFF", comment.m_sStaff);
	sQuery.bindValue(":COMMENT_TIME", comment.m_sTime.toString("yyyy-MM-dd"));
	sQuery.bindValue(":AT_STAFF", comment.m_sAtStaff);
	if (sQuery.exec())
	{
		return true;
	}

	errorInfo = sQuery.lastError().text();
	return false;
}

bool UrielDatabase::getNoticesCommentList(QList<sUrielCommentItem> & commentList, const QString & codeId)
{
	QString strSQL = "SELECT CODE_ID, COMMENT, COMMENT_STAFF, COMMENT_TIME, AT_STAFF"
		" FROM ilabmanagementsystem.notifications_comment WHERE CODE_ID  = '" + codeId + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		sUrielCommentItem item;
		item.m_sCodeId = mQuery.value(0).toString();
		item.m_sComment = mQuery.value(1).toString();
		item.m_sStaff = mQuery.value(2).toString();
		item.m_sTime = mQuery.value(3).toDateTime();
		item.m_sAtStaff= mQuery.value(4).toString();
		commentList << item;
	}
	return false;
}


UrielInstrumentTableModel * UrielDatabase::creatInstrumentTableModel()
{
	if (m_pUrielInstrumentTableModel != nullptr)
		return m_pUrielInstrumentTableModel;
	m_szInstrumentBrowserQuery = "select INSTRUMENT_KEY,INSTRUMENT_NAME,INSTRUMENT_MODEL,INSTRUMENT_VENDER,INSTRUMENT_PRICE,INSTRUMENT_PURCHASE_TIME,"
		"INSTRUMENT_GUARANTEE_PERIOD,INSTRUMENT_PROJECT_TEAM,INSTRUMENT_PRESENT_PERSON_IN_CHARGE,INSTRUMENT_STORE_LOCATION,INSTRUMENT_STATUS,INSTRUMENT_SDK_LOCATION "
		"from instrument";
	QStringList list;
	list << QStringLiteral("仪器ID") << QStringLiteral("名称") << QStringLiteral("型号") << QStringLiteral("厂家")\
		<< QStringLiteral("价格") << QStringLiteral("购买时间") << QStringLiteral("保质期(月)")\
		<< QStringLiteral("所属项目") << QStringLiteral("负责人") << QStringLiteral("位置") << QStringLiteral("状态")
		<< QStringLiteral("开发包位置");
	m_szInstrumentPreviousQuery = m_szInstrumentBrowserQuery + " order by INSTRUMENT_KEY asc";
	m_pUrielInstrumentTableModel = new UrielInstrumentTableModel(m_szInstrumentPreviousQuery, list, m_Database);
	return m_pUrielInstrumentTableModel;
}

bool UrielDatabase::deleteInstrumentByID(const QString & sId)
{
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("DELETE FROM instrument  WHERE INSTRUMENT_KEY ='" + sId + "'");
	if (sQuery.exec())
		return true;
	return false;
}

bool UrielDatabase::updateInstrumentTableModel(QString  strSQL )
{
	if (strSQL.isEmpty())
	{
		if (m_pUrielInstrumentTableModel)
		{
			m_pUrielInstrumentTableModel->setQuery(m_szInstrumentPreviousQuery);
		}
		//	std::string ssss = previous_query_.toStdString();
		return true;
	}
	QString previous_query_current = m_szInstrumentBrowserQuery + strSQL + " order by INSTRUMENT_KEY desc";

	if (m_pUrielInstrumentTableModel)
	{
		m_pUrielInstrumentTableModel->setQuery(previous_query_current);
	}
	return true;
}

bool UrielDatabase::getInstrumentByID(sUrielInstrumentItem & item, const QString & sId)
{
	QString strSQL = "select INSTRUMENT_KEY,INSTRUMENT_NAME,INSTRUMENT_MODEL,INSTRUMENT_VENDER,INSTRUMENT_PRICE,INSTRUMENT_PURCHASE_TIME,"
		"INSTRUMENT_GUARANTEE_PERIOD,INSTRUMENT_PROJECT_TEAM,INSTRUMENT_PRESENT_PERSON_IN_CHARGE,INSTRUMENT_STORE_LOCATION,INSTRUMENT_STATUS,INSTRUMENT_PICTURE,"
		"INSTRUMENT_SDK_LOCATION,INSTRUMENT_DESCRIPTION  FROM ilabmanagementsystem.instrument WHERE INSTRUMENT_KEY  = '" + sId + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		item.m_iId = mQuery.value(0).toInt();
		item.m_sName = mQuery.value(1).toString();
		item.m_sModel = mQuery.value(2).toString();
		item.m_sVender = mQuery.value(3).toString();
		item.m_dPrice = mQuery.value(4).toDouble();
		item.m_tPurchaseTime = mQuery.value(5).toDateTime();
		item.m_iGuaranteePeriod = mQuery.value(6).toInt();
		item.m_sProjectTeam = mQuery.value(7).toString();
		item.m_sPresentPersonInCharge = mQuery.value(8).toString();
		item.m_sInstrumentAddress = mQuery.value(9).toString();
		item.m_sStatus = mQuery.value(10).toString();
		//QByteArray barray = mQuery.value(11).toByteArray();
		//item.m_imgInstrument.loadFromData(barray);
		item.m_sInstrumentImage = mQuery.value(11).toString();
		item.m_sSDKAddress = mQuery.value(12).toString();
		item.m_sDescription = mQuery.value(13).toString();
		return true;
	}
	return false;
}

bool UrielDatabase::getInstrumentStatusByID(QString & status, const QString & sId)
{
	QString strSQL = "select INSTRUMENT_STATUS FROM ilabmanagementsystem.instrument WHERE INSTRUMENT_KEY  = '" + sId + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		status = mQuery.value(0).toString();
		return true;
	}
	return false;
}
bool UrielDatabase::getInstrumentByName(sUrielInstrumentItem & item, const QString & Name)
{
	QString strSQL = "select INSTRUMENT_KEY,INSTRUMENT_NAME,INSTRUMENT_MODEL,INSTRUMENT_VENDER,INSTRUMENT_PRICE,INSTRUMENT_PURCHASE_TIME,"
		"INSTRUMENT_GUARANTEE_PERIOD,INSTRUMENT_PROJECT_TEAM,INSTRUMENT_PRESENT_PERSON_IN_CHARGE,INSTRUMENT_STORE_LOCATION,INSTRUMENT_STATUS,INSTRUMENT_PICTURE,"
		"INSTRUMENT_SDK_LOCATION,INSTRUMENT_DESCRIPTION  FROM ilabmanagementsystem.instrument WHERE INSTRUMENT_NAME  = '" + Name + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		item.m_iId = mQuery.value(0).toInt();
		item.m_sName = mQuery.value(1).toString();
		item.m_sModel = mQuery.value(2).toString();
		item.m_sVender = mQuery.value(3).toString();
		item.m_dPrice = mQuery.value(4).toDouble();
		item.m_tPurchaseTime = mQuery.value(5).toDateTime();
		item.m_iGuaranteePeriod = mQuery.value(6).toInt();
		item.m_sProjectTeam = mQuery.value(7).toString();
		item.m_sPresentPersonInCharge = mQuery.value(8).toString();
		item.m_sInstrumentAddress = mQuery.value(9).toString();
		item.m_sStatus = mQuery.value(10).toString();
		//QByteArray barray = mQuery.value(11).toByteArray();
		//item.m_imgInstrument.loadFromData(barray);
		item.m_sInstrumentImage= mQuery.value(11).toString();
		item.m_sSDKAddress = mQuery.value(12).toString();
		item.m_sDescription = mQuery.value(13).toString();
		return true;
	}
	return false;
}

bool UrielDatabase::insertInstrument(const sUrielInstrumentItem& item, QString & error)
{
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("INSERT INTO instrument (INSTRUMENT_NAME,INSTRUMENT_MODEL,INSTRUMENT_VENDER,INSTRUMENT_PRICE,INSTRUMENT_PURCHASE_TIME,"
	"INSTRUMENT_GUARANTEE_PERIOD,INSTRUMENT_PROJECT_TEAM,INSTRUMENT_PRESENT_PERSON_IN_CHARGE,INSTRUMENT_STORE_LOCATION,INSTRUMENT_STATUS,INSTRUMENT_PICTURE,"
		"INSTRUMENT_SDK_LOCATION,INSTRUMENT_DESCRIPTION )"
		" VALUES (:INSTRUMENT_NAME,:INSTRUMENT_MODEL,:INSTRUMENT_VENDER,:INSTRUMENT_PRICE,:INSTRUMENT_PURCHASE_TIME,:INSTRUMENT_GUARANTEE_PERIOD,"
		":INSTRUMENT_PROJECT_TEAM,:INSTRUMENT_PRESENT_PERSON_IN_CHARGE,:INSTRUMENT_STORE_LOCATION,:INSTRUMENT_STATUS,:INSTRUMENT_PICTURE,:INSTRUMENT_SDK_LOCATION,:INSTRUMENT_DESCRIPTION)");
	sQuery.bindValue(":INSTRUMENT_NAME", item.m_sName);
	sQuery.bindValue(":INSTRUMENT_MODEL", item.m_sModel);
	sQuery.bindValue(":INSTRUMENT_VENDER", item.m_sVender);
	sQuery.bindValue(":INSTRUMENT_PRICE", QString::number(item.m_dPrice));
	sQuery.bindValue(":INSTRUMENT_PURCHASE_TIME", item.m_tPurchaseTime.toString("yyyy-MM-dd"));
	sQuery.bindValue(":INSTRUMENT_GUARANTEE_PERIOD", QString::number(item.m_iGuaranteePeriod));
	sQuery.bindValue(":INSTRUMENT_PROJECT_TEAM", item.m_sProjectTeam);
	sQuery.bindValue(":INSTRUMENT_PRESENT_PERSON_IN_CHARGE", item.m_sPresentPersonInCharge);
	sQuery.bindValue(":INSTRUMENT_STORE_LOCATION", item.m_sInstrumentAddress);
	sQuery.bindValue(":INSTRUMENT_STATUS", item.m_sStatus);
	sQuery.bindValue(":INSTRUMENT_PICTURE", item.m_sInstrumentImage);
	//QByteArray bytes;
	//QBuffer buffer(&bytes);
	//buffer.open(QIODevice::WriteOnly);
	//item.m_imgInstrument.save(&buffer, "PNG");
	//sQuery.bindValue(":INSTRUMENT_PICTURE", bytes);
	sQuery.bindValue(":INSTRUMENT_SDK_LOCATION", item.m_sSDKAddress);
	sQuery.bindValue(":INSTRUMENT_DESCRIPTION", item.m_sDescription);
	if (sQuery.exec())
	{
		return true;
	}
	error = sQuery.lastError().text();
	return false;
}

bool UrielDatabase::updateInstrument(const sUrielInstrumentItem& item)
{
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("UPDATE instrument SET INSTRUMENT_NAME=?,INSTRUMENT_MODEL=?,INSTRUMENT_VENDER=?,INSTRUMENT_PRICE=?,INSTRUMENT_PURCHASE_TIME=?,"
		"INSTRUMENT_GUARANTEE_PERIOD=?,INSTRUMENT_PROJECT_TEAM=?,INSTRUMENT_PRESENT_PERSON_IN_CHARGE=?,INSTRUMENT_STORE_LOCATION=?,INSTRUMENT_STATUS=?,INSTRUMENT_PICTURE=?,"
		"INSTRUMENT_SDK_LOCATION=?,INSTRUMENT_DESCRIPTION=? WHERE INSTRUMENT_KEY='" + QString::number(item.m_iId) + "'");
	sQuery.bindValue(0, item.m_sName);
	sQuery.bindValue(1, item.m_sModel);
	sQuery.bindValue(2, item.m_sVender);
	sQuery.bindValue(3, QString::number(item.m_dPrice));
	sQuery.bindValue(4, item.m_tPurchaseTime.toString("yyyy-MM-dd"));
	sQuery.bindValue(5, QString::number(item.m_iGuaranteePeriod));
	sQuery.bindValue(6, item.m_sProjectTeam);
	sQuery.bindValue(7, item.m_sPresentPersonInCharge);
	sQuery.bindValue(8, item.m_sInstrumentAddress);
	sQuery.bindValue(9, item.m_sStatus);
	sQuery.bindValue(10, item.m_sInstrumentImage);
	/*QByteArray bytes;
	QBuffer buffer(&bytes);
	buffer.open(QIODevice::WriteOnly);
	item.m_imgInstrument.save(&buffer, "PNG");
	sQuery.bindValue(10, bytes);*/
	sQuery.bindValue(11, item.m_sSDKAddress);
	sQuery.bindValue(12, item.m_sDescription);

	if (sQuery.exec())
	{
		return true;
	}
	QString ss = sQuery.lastError().text();
	return false;
}


bool UrielDatabase::updateInstrumentWithStatusAndAddressByID(const QString &status, const QString &address, const QString & sId)
{
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("UPDATE instrument SET INSTRUMENT_STORE_LOCATION=?,INSTRUMENT_STATUS=? WHERE INSTRUMENT_KEY='" + sId + "'");
	sQuery.bindValue(0, address);
	sQuery.bindValue(1, status);

	if (sQuery.exec())
	{
		return true;
	}
	//QString ss = sQuery.lastError().text();
	return false;
}

bool  UrielDatabase::getInstrumentSDKFiles(QString & files, const QString & sId)
{
	QString strSQL = "select INSTRUMENT_SDK_LOCATION FROM ilabmanagementsystem.instrument WHERE INSTRUMENT_KEY  = '" + sId + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		files = mQuery.value(0).toString();
		return true;
	}
	return false;
}

bool UrielDatabase::getDistinctProjectFromInstrument(QStringList &ProjectList)
{
	QString strSQL = "SELECT DISTINCT INSTRUMENT_PROJECT_TEAM FROM ilabmanagementsystem.instrument ";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		ProjectList << (mQuery.value(0).toString());
	}
	return true;
}

bool UrielDatabase::getInstrumentByProjectTeam(QStringList &Instrumentlist, const QString &ProjectTeam)
{
	QString strSQL = "SELECT INSTRUMENT_NAME FROM ilabmanagementsystem.instrument  WHERE INSTRUMENT_PROJECT_TEAM = '"+ ProjectTeam+"'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		Instrumentlist << (mQuery.value(0).toString());
	}
	return true;
}

bool UrielDatabase::getInstrumentByInstrumentNameAndProjectTeam(sUrielInstrumentItem &item, const QString & ProjectTeam, const QString &  InstrumentName)
{
	QString strSQL = "select INSTRUMENT_KEY,INSTRUMENT_NAME,INSTRUMENT_MODEL,INSTRUMENT_VENDER,INSTRUMENT_PRICE,INSTRUMENT_PURCHASE_TIME,"
		"INSTRUMENT_GUARANTEE_PERIOD,INSTRUMENT_PROJECT_TEAM,INSTRUMENT_PRESENT_PERSON_IN_CHARGE,INSTRUMENT_STORE_LOCATION,INSTRUMENT_STATUS,INSTRUMENT_PICTURE,"
		"INSTRUMENT_SDK_LOCATION,INSTRUMENT_DESCRIPTION  FROM ilabmanagementsystem.instrument WHERE INSTRUMENT_PROJECT_TEAM  = '" + ProjectTeam + "' AND INSTRUMENT_NAME = '" + InstrumentName + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		item.m_iId = mQuery.value(0).toInt();
		item.m_sName = mQuery.value(1).toString();
		item.m_sModel = mQuery.value(2).toString();
		item.m_sVender = mQuery.value(3).toString();
		item.m_dPrice = mQuery.value(4).toDouble();
		item.m_tPurchaseTime = mQuery.value(5).toDateTime();
		item.m_iGuaranteePeriod = mQuery.value(6).toInt();
		item.m_sProjectTeam = mQuery.value(7).toString();
		item.m_sPresentPersonInCharge = mQuery.value(8).toString();
		item.m_sInstrumentAddress = mQuery.value(9).toString();
		item.m_sStatus = mQuery.value(10).toString();
		//QByteArray barray = mQuery.value(11).toByteArray();
		//item.m_imgInstrument.loadFromData(barray);
		item.m_sInstrumentImage= mQuery.value(11).toString();
		item.m_sSDKAddress = mQuery.value(12).toString();
		item.m_sDescription = mQuery.value(13).toString();
		return true;
	}
	return false;
}

bool UrielDatabase::getDistinctChargerFromInstrument(QStringList &ChargerList)
{
	QString strSQL = "SELECT DISTINCT INSTRUMENT_PRESENT_PERSON_IN_CHARGE FROM ilabmanagementsystem.instrument ";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		ChargerList << (mQuery.value(0).toString());
	}
	return true;
}

bool UrielDatabase::getInstrumentByCharger(QStringList &Instrument, const QString &Charger)
{
	QString strSQL = "SELECT INSTRUMENT_NAME FROM ilabmanagementsystem.instrument  WHERE INSTRUMENT_PRESENT_PERSON_IN_CHARGE = '" + Charger + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		Instrument << (mQuery.value(0).toString());
	}
	return true;
}

bool UrielDatabase::getInstrumentByInstrumentNameAndCharger(sUrielInstrumentItem &item, const QString &Charger, const QString & InstrumentName)
{
	QString strSQL = "select INSTRUMENT_KEY,INSTRUMENT_NAME,INSTRUMENT_MODEL,INSTRUMENT_VENDER,INSTRUMENT_PRICE,INSTRUMENT_PURCHASE_TIME,"
		"INSTRUMENT_GUARANTEE_PERIOD,INSTRUMENT_PROJECT_TEAM,INSTRUMENT_PRESENT_PERSON_IN_CHARGE,INSTRUMENT_STORE_LOCATION,INSTRUMENT_STATUS,INSTRUMENT_PICTURE,"
		"INSTRUMENT_SDK_LOCATION,INSTRUMENT_DESCRIPTION  FROM ilabmanagementsystem.instrument WHERE INSTRUMENT_PRESENT_PERSON_IN_CHARGE  = '" + Charger + "' AND INSTRUMENT_NAME = '" + InstrumentName + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		item.m_iId = mQuery.value(0).toInt();
		item.m_sName = mQuery.value(1).toString();
		item.m_sModel = mQuery.value(2).toString();
		item.m_sVender = mQuery.value(3).toString();
		item.m_dPrice = mQuery.value(4).toDouble();
		item.m_tPurchaseTime = mQuery.value(5).toDateTime();
		item.m_iGuaranteePeriod = mQuery.value(6).toInt();
		item.m_sProjectTeam = mQuery.value(7).toString();
		item.m_sPresentPersonInCharge = mQuery.value(8).toString();
		item.m_sInstrumentAddress = mQuery.value(9).toString();
		item.m_sStatus = mQuery.value(10).toString();
		//QByteArray barray = mQuery.value(11).toByteArray();
		//item.m_imgInstrument.loadFromData(barray);
		item.m_sInstrumentImage = mQuery.value(11).toString();
		item.m_sSDKAddress = mQuery.value(12).toString();
		item.m_sDescription = mQuery.value(13).toString();
		return true;
	}
	return false;
}

bool UrielDatabase::getInstrumentBySearch(QStringList &InstrumentList, const QString &  searchName)
{
	//WHERE INSTRUMENT_MODEL like '%" + str + "%'"
	QString strSQL = "SELECT INSTRUMENT_NAME FROM ilabmanagementsystem.instrument  WHERE INSTRUMENT_NAME like '%" + searchName + "%'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		InstrumentList << (mQuery.value(0).toString());
	}
	return true;
}

bool UrielDatabase::insertInstrumentUseLog(const sUrielInstrumentUseLog& item, QString & error)
{
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("INSERT INTO instrument_use_log (INSTRUMENT_KEY,INSTRUMENT_NAME,BORROWRETURN_ADDRESS,BORROWRETURN_TIME,BORROWRETURN_STAFF,AUDITOR,BORROWRETURN_STATUS,DESCRIPTION )"
		" VALUES (:INSTRUMENT_KEY,:INSTRUMENT_NAME,:BORROWRETURN_ADDRESS,:BORROWRETURN_TIME,:BORROWRETURN_STAFF,:AUDITOR,:BORROWRETURN_STATUS,:DESCRIPTION )");
	sQuery.bindValue(":INSTRUMENT_KEY", item.m_sInstrumentKey);
	sQuery.bindValue(":INSTRUMENT_NAME", item.m_sInstrumentName);
	sQuery.bindValue(":BORROWRETURN_ADDRESS", item.m_sBorrowReturnAddress);
	sQuery.bindValue(":BORROWRETURN_TIME", item.m_sBorrowReturnTime.toString("yyyy-MM-dd hh:mm"));
	sQuery.bindValue(":BORROWRETURN_STAFF", item.m_sBorrowReturnStaff);
	sQuery.bindValue(":AUDITOR", item.m_sAuditor);
	sQuery.bindValue(":BORROWRETURN_STATUS", item.m_sBorrowReturnStatus);
	sQuery.bindValue(":DESCRIPTION", item.m_sDescription);
	if (sQuery.exec())
	{
		return true;
	}
	error = sQuery.lastError().text();
	return false;
}

UrielInstrumentBorrowReturnHistoryTableModel * UrielDatabase::creatInstrumentBorrowReturnHistoryTableModel()
{
	if (m_pUrielInstrumentBorrowReturnHistoryTableModel != nullptr)
		return m_pUrielInstrumentBorrowReturnHistoryTableModel;
	m_szInstrumentBorrowReturnHistoryBrowserQuery = "select USELOG_ID,INSTRUMENT_KEY,INSTRUMENT_NAME,BORROWRETURN_STATUS,BORROWRETURN_ADDRESS,BORROWRETURN_TIME,BORROWRETURN_STAFF,AUDITOR from instrument_use_log";
	QStringList list;
	list << QStringLiteral("ID") << QStringLiteral("仪器ID") << QStringLiteral("仪器名称") << QStringLiteral("借还状态") << QStringLiteral("借还地址")\
		<< QStringLiteral("借还时间") << QStringLiteral("借还人员") << QStringLiteral("审核人员");
	m_szInstrumentBorrowReturnHistoryPreviousQuery = m_szInstrumentBorrowReturnHistoryBrowserQuery + " order by BORROWRETURN_TIME asc";
	m_pUrielInstrumentBorrowReturnHistoryTableModel = new UrielInstrumentBorrowReturnHistoryTableModel(m_szInstrumentBorrowReturnHistoryPreviousQuery, list, m_Database);
	return m_pUrielInstrumentBorrowReturnHistoryTableModel;
}

bool UrielDatabase::updateInstrumentBorrowReturnHistoryTableModel(QString  strSQL )
{
	if (strSQL.isEmpty())
	{
		if (m_pUrielInstrumentBorrowReturnHistoryTableModel)
		{
			m_pUrielInstrumentBorrowReturnHistoryTableModel->setQuery(m_szInstrumentBorrowReturnHistoryPreviousQuery);
		}
		//	std::string ssss = previous_query_.toStdString();
		return true;
	}
	QString previous_query_current = m_szInstrumentBorrowReturnHistoryBrowserQuery + strSQL + " order by BORROWRETURN_TIME asc";

	if (m_pUrielInstrumentBorrowReturnHistoryTableModel)
	{
		m_pUrielInstrumentBorrowReturnHistoryTableModel->setQuery(previous_query_current);
	}
	return true;
}

bool UrielDatabase::getInstrumentUseLogByID(sUrielInstrumentUseLog & item, const QString & id)
{
	QString strSQL = "select USELOG_ID,INSTRUMENT_KEY,INSTRUMENT_NAME,BORROWRETURN_ADDRESS,BORROWRETURN_TIME,BORROWRETURN_STAFF,AUDITOR,"
		"BORROWRETURN_STATUS,DESCRIPTION  FROM ilabmanagementsystem.instrument_use_log WHERE USELOG_ID  = '" + id +  "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		item.m_sUseLogId = mQuery.value(0).toString();
		item.m_sInstrumentKey = mQuery.value(1).toString();
		item.m_sInstrumentName = mQuery.value(2).toString();
		item.m_sBorrowReturnAddress = mQuery.value(3).toString();
		item.m_sBorrowReturnTime = mQuery.value(4).toDateTime();
		item.m_sBorrowReturnStaff = mQuery.value(5).toString();
		item.m_sAuditor = mQuery.value(6).toString();
		item.m_sBorrowReturnStatus = mQuery.value(7).toString();
		item.m_sDescription = mQuery.value(8).toString();
		return true;
	}
	return false;
}

UrielCheckInTableModel* UrielDatabase::creatCheckInTableModel()
{
	if (m_pUrielCheckInTableModel != nullptr)
		return m_pUrielCheckInTableModel;
	m_szCheckInBrowserQuery = "select ID,Type,ApplyPerson,EventName,Descripation,ApplyTime,StartTime,EndTime,AuditState,Auditor,AuditorSuggest,AuditTime from vacation_leave";
	QStringList list;
	list << QStringLiteral("ID") << QStringLiteral("类型") << QStringLiteral("申请人") << QStringLiteral("理由") << QStringLiteral("描述")\
		<< QStringLiteral("申请时间") << QStringLiteral("开始时间") << QStringLiteral("结束时间") << QStringLiteral("状态") << QStringLiteral("审核人") << QStringLiteral("审核建议") << QStringLiteral("审核时间");
	m_szCheckInPreviousQuery = m_szCheckInBrowserQuery + " order by ID asc";
	m_pUrielCheckInTableModel = new UrielCheckInTableModel(m_szCheckInPreviousQuery, list, m_Database);
	return m_pUrielCheckInTableModel;
}

bool UrielDatabase::updateCheckInTableModel(QString  strSQL)
{
	if (strSQL.isEmpty())
	{
		if (m_pUrielCheckInTableModel)
		{
			m_pUrielCheckInTableModel->setQuery(m_szCheckInPreviousQuery);
		}
		return true;
	}
	QString previous_query_current = m_szCheckInBrowserQuery + strSQL + " order by ID asc";

	if (m_pUrielCheckInTableModel)
	{
		m_pUrielCheckInTableModel->setQuery(previous_query_current);
	}
	return true;
}

bool UrielDatabase::deleteEventFromCheckInByID(const QString & sId)
{
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("DELETE FROM vacation_leave  WHERE ID ='" + sId + "'");
	if (sQuery.exec())
		return true;
	return false;
}

bool UrielDatabase::insertVacationLeaveEvent(const sUrielVacationLeaveItem & item)
{
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("INSERT INTO vacation_leave (Type,ApplyPerson,EventName,Descripation,ApplyTime,StartTime,EndTime,AuditState,Auditor,AuditorSuggest,AuditTime )"
		" VALUES (:Type,:ApplyPerson,:EventName,:Descripation,:ApplyTime,:StartTime,:EndTime,:AuditState,:Auditor,:AuditorSuggest,:AuditTime )");
	sQuery.bindValue(":Type", item.m_sType);
	sQuery.bindValue(":ApplyPerson", item.m_sApplyPerson);
	sQuery.bindValue(":EventName", item.m_sEventName);
	sQuery.bindValue(":Descripation", item.m_sDescripation);//
	sQuery.bindValue(":ApplyTime", item.m_tApplyTime.toString("yyyy-MM-dd hh:mm"));
	sQuery.bindValue(":StartTime", item.m_tStartTime.toString("yyyy-MM-dd hh:mm"));
	sQuery.bindValue(":EndTime", item.m_tEndTime.toString("yyyy-MM-dd hh:mm"));
	sQuery.bindValue(":AuditState", item.m_sAuditState);
	sQuery.bindValue(":Auditor", item.m_sAuditor);
	sQuery.bindValue(":AuditorSuggest", item.m_sAuditorSuggest);
	sQuery.bindValue(":AuditTime", item.m_tAuditTime);
	if (sQuery.exec())
	{
		return true;
	}
	QString error = sQuery.lastError().text();
	return false;
}

bool UrielDatabase::updateVacationLeaveEvent(const sUrielVacationLeaveItem & item)
{
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("UPDATE vacation_leave SET Type=?,ApplyPerson=?,EventName=?,Descripation=?,ApplyTime=?,StartTime=?,EndTime=?,AuditState=?,Auditor=?,AuditorSuggest=?,AuditTime=? WHERE ID='" + item.m_sId + "'");
	sQuery.bindValue(0, item.m_sType);
	sQuery.bindValue(1, item.m_sApplyPerson);
	sQuery.bindValue(2, item.m_sEventName);
	sQuery.bindValue(3, item.m_sDescripation);
	sQuery.bindValue(4, item.m_tApplyTime);
	sQuery.bindValue(5, item.m_tStartTime);
	sQuery.bindValue(6, item.m_tEndTime);
	sQuery.bindValue(7, item.m_sAuditState);
	sQuery.bindValue(8, item.m_sAuditor);
	sQuery.bindValue(9, item.m_sAuditorSuggest);
	sQuery.bindValue(10, item.m_tAuditTime);

	if (sQuery.exec())
	{
		return true;
	}
	//QString ss = sQuery.lastError().text();
	return false;
}

bool UrielDatabase::insertReimburseCode(const QString &ReimburseCode)
{
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("INSERT INTO ilabmanagementsystem.reimburse_code (ReimburseCode ) VALUES (:ReimburseCode)");
	sQuery.bindValue(":ReimburseCode", ReimburseCode);
	if (sQuery.exec())
	{
		return true;
	}
	//error = sQuery.lastError().text();
	return false;
}

bool UrielDatabase::getAvailableReimburseCodeList(QStringList &AvailableReimburseCodeList)
{
	QString strSQL = "select ReimburseCode FROM ilabmanagementsystem.reimburse_code WHERE Status  = '" + QStringLiteral("进行中") + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		AvailableReimburseCodeList<< mQuery.value(0).toString();
	}
	return false;
}

bool UrielDatabase::getAllReimburseCodes(QStringList &ReimburseCodeList) {
	QString strSQL = "select ReimburseCode FROM ilabmanagementsystem.reimburse_code";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		ReimburseCodeList << mQuery.value(0).toString();
	}
	return false;
}

bool UrielDatabase::getAllProjectByReimburseCode(QStringList &ProjectList, const QString & ReimburseCode) {
	QString strSQL = "select DISTINCT Type FROM ilabmanagementsystem.reimburse_management where ReimburseCode='"+ ReimburseCode+"'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		ProjectList << mQuery.value(0).toString();
	}
	return false;
}

int  UrielDatabase::getInvoiceIDByReimburseCode_Project_Name(const QString & ReimburseCode, const QString & szInvoiceProject, const QString &szInvoiceName) {
	QString strSQL = "select ID FROM ilabmanagementsystem.reimburse_management where ReimburseCode ='" 
		+ ReimburseCode + "' and Type ='"+ szInvoiceProject+"' and Name ='"+ szInvoiceName+"'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	int result;
	while (mQuery.next())
	{
		result= mQuery.value(0).toInt();
	}
	return result;
}
bool UrielDatabase::getInvoiceListbyReimburseCodeAndType(QStringList & childList, const QString & ReimburseCode, const QString &sProject,const QString &ReimbursePerson)
{
	QString strSQL = "select Name,AggregateAmount FROM ilabmanagementsystem.reimburse_management WHERE ReimburseCode  = '" + ReimburseCode + "' AND Type ='"+ sProject+"' AND ReimbursePerson ='"+ ReimbursePerson+"'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		childList << mQuery.value(0).toString()+ "("+ mQuery.value(1).toString()+QStringLiteral("元）");
	}
	return false;
}

bool UrielDatabase::insertInvoice(const sUrielInvoiceInfoItem & item,QString &error)
{
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("INSERT INTO reimburse_management (ReimburseCode,Type,Name,Model,Quantity,Unit,Univalent,AggregateAmount,Description,InvoiceImagePath,"
		"BuyScreenshotPath,VerificationImagePath,ReimbursePerson,ReimburseTime,FilingState,ArchivesName,Remark )"
		" VALUES (:ReimburseCode,:Type,:Name,:Model,:Quantity,:Unit,:Univalent,:AggregateAmount,:Description,:InvoiceImagePath,:BuyScreenshotPath,"
		":VerificationImagePath,:ReimbursePerson,:ReimburseTime,:FilingState,:ArchivesName,:Remark )");
	sQuery.bindValue(":ReimburseCode", item.m_sReimburseCode);
	sQuery.bindValue(":Type", item.m_sType);
	sQuery.bindValue(":Name", item.m_sName);
	sQuery.bindValue(":Model", item.m_sModel);
	sQuery.bindValue(":Quantity", QString::number(item.m_iQuantity));
	sQuery.bindValue(":Unit", item.m_sUnit);
	sQuery.bindValue(":Univalent", QString::number(item.m_dUnivalent));
	sQuery.bindValue(":AggregateAmount", QString::number(item.m_dAggregateAmount));
	sQuery.bindValue(":Description", item.m_sDescription);
	sQuery.bindValue(":InvoiceImagePath", item.m_sInvoiceImagePath);
	sQuery.bindValue(":BuyScreenshotPath", item.m_sBuyScreenshotPath);
	sQuery.bindValue(":VerificationImagePath", item.m_sVerificationImagePath);
	sQuery.bindValue(":ReimbursePerson", item.m_sReimbursePerson);
	sQuery.bindValue(":ReimburseTime", item.m_tReimburseTime.toString("yyyy-MM-dd hh:mm:ss"));
	sQuery.bindValue(":FilingState", item.m_sFilingState);
	sQuery.bindValue(":ArchivesName", item.m_sArchivesName);
	sQuery.bindValue(":Remark", item.m_sRemark);

	if (sQuery.exec())
	{
		return true;
	}
	error = sQuery.lastError().text();
	return false;
}

bool UrielDatabase::updateInvoice(const sUrielInvoiceInfoItem & item, QString &error) {
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("UPDATE reimburse_management SET ReimburseCode=?,Type=?,Name=?,Model=?,Quantity=?,Unit=?,Univalent=?,AggregateAmount=?,Description=?,InvoiceImagePath=?,"
		"BuyScreenshotPath=?,VerificationImagePath=?,ReimbursePerson=?,ReimburseTime=?,FilingState=?,ArchivesName=?,Remark=?"
		"WHERE ID='" + QString::number(item.m_iId) + "'");
	sQuery.bindValue(0, item.m_sReimburseCode);
	sQuery.bindValue(1, item.m_sType);
	sQuery.bindValue(2, item.m_sName);
	sQuery.bindValue(3, item.m_sModel);
	sQuery.bindValue(4, item.m_iQuantity);
	sQuery.bindValue(5, item.m_sUnit);
	sQuery.bindValue(6, item.m_dUnivalent);
	sQuery.bindValue(7, item.m_dAggregateAmount);
	sQuery.bindValue(8, item.m_sDescription);
	sQuery.bindValue(9, item.m_sInvoiceImagePath);
	sQuery.bindValue(10, item.m_sBuyScreenshotPath);
	sQuery.bindValue(11, item.m_sVerificationImagePath);
	sQuery.bindValue(12, item.m_sReimbursePerson);
	sQuery.bindValue(13, item.m_tReimburseTime);
	sQuery.bindValue(14, item.m_sFilingState);
	sQuery.bindValue(15, item.m_sArchivesName);
	sQuery.bindValue(16, item.m_sRemark);

	if (sQuery.exec())
	{
		return true;
	}
	//QString ss = sQuery.lastError().text();
	return false;
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

QString UrielDatabase::getProjectName(const ExpenseItemEnum &ExpenseItem) {
	QString sProject;
	switch (ExpenseItem)
	{
	case ExpenseItemEnum::LocalTransportation:
		sProject = QStringLiteral("市内交通费");
		break;
	case ExpenseItemEnum::OfficeSupplies:
		sProject = QStringLiteral("办公用品");
		break;
	case ExpenseItemEnum::PurchaseOfProfessionalMaterials:
		sProject = QStringLiteral("专业材料购置费");
		break;
	case ExpenseItemEnum::PurchaseOfExperimentalMaterials:
		sProject = QStringLiteral("实验材料购置费");
		break;
	case ExpenseItemEnum::SportingGoodsPurchaseFee:
		sProject = QStringLiteral("体育用品购置费");
		break;
	case ExpenseItemEnum::XeroxFee:
		sProject = QStringLiteral("资料复印费");
		break;
	case ExpenseItemEnum::Typography:
		sProject = QStringLiteral("版面印刷费");
		break;
	case ExpenseItemEnum::MaterialTestingAndProcessingFee:
		sProject = QStringLiteral("材料测试加工费");
		break;
	case ExpenseItemEnum::LodgingExpenses:
		sProject = QStringLiteral("实习费");
		break;
	case ExpenseItemEnum::StudentActivityFee:
		sProject = QStringLiteral("学生活动费");
		break;
	case ExpenseItemEnum::Correspondence:
		sProject = QStringLiteral("通讯费");
		break;
	case ExpenseItemEnum::PostFee:
		sProject = QStringLiteral("邮寄费");
		break;
	case ExpenseItemEnum::SelfServiceCost:
		sProject = QStringLiteral("自备车费用");
		break;
	case ExpenseItemEnum::MotorVehicleMaintenance:
		sProject = QStringLiteral("机动车维修费");
		break;
	case ExpenseItemEnum::OfficeEquipmentMaintenance:
		sProject = QStringLiteral("办公设备维修费");
		break;
	case ExpenseItemEnum::EquipmentMaintenanceFee:
		sProject = QStringLiteral("仪器设备维修费");
		break;
	case ExpenseItemEnum::TrainingFees:
		sProject = QStringLiteral("培训费");
		break;
	case ExpenseItemEnum::EntertainmentExpense:
		sProject = QStringLiteral("招待费");
		break;
	case ExpenseItemEnum::ConstructionOfFixedAssets:
		sProject = QStringLiteral("固定资产构建费");
		break;
	case ExpenseItemEnum::Streamer:
		sProject = QStringLiteral("横幅");
		break;
	case ExpenseItemEnum::Other:
		sProject = QStringLiteral("其他");
		break;
	default:
		break;
	}
	return sProject;
}
double UrielDatabase::getSumOfClaimSummaryProject(const ExpenseItemEnum &ExpenseItem, const QString & ReimburseCode) {
	QString sProject=getProjectName(ExpenseItem);
	QString strSQL = "select AggregateAmount FROM ilabmanagementsystem.reimburse_management WHERE ReimburseCode  = '"
		+ ReimburseCode + "' AND Type ='" + sProject + "' and ReimbursePerson='" + m_pOptions->getAccount()+"'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	double result = 0.0;
	while (mQuery.next())
	{
		result += mQuery.value(0).toDouble();
	}
	return result;
}

double UrielDatabase::getSumOfClaimSummaryProject(const ExpenseItemEnum &ExpenseItem, const QString & ReimburseCode, const QString &ArchiveName) {
	QString sProject = getProjectName(ExpenseItem);
	QString strSQL = "select AggregateAmount FROM ilabmanagementsystem.reimburse_management WHERE ReimburseCode  = '"
		+ ReimburseCode + "' AND Type ='" + sProject + "' and ArchivesName= '" + ArchiveName + "' and FilingState='" + QStringLiteral("已归档") + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	double result = 0.0;
	while (mQuery.next())
	{
		result += mQuery.value(0).toDouble();
	}
	return result;
}

double UrielDatabase::getTotalSumOfClaimSummary(const QString & ReimburseCode) {
	QString strSQL = "select AggregateAmount FROM ilabmanagementsystem.reimburse_management WHERE ReimburseCode  = '" \
		+ ReimburseCode + "' and ReimbursePerson='" + m_pOptions->getAccount() + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	double result = 0.0;
	while (mQuery.next())
	{
		result += mQuery.value(0).toDouble();
	}
	return result;
}

double UrielDatabase::getTotalSumOfClaimSummary(const QString & ReimburseCode, const QString &ArchiveName) {
	QString strSQL = "select AggregateAmount FROM ilabmanagementsystem.reimburse_management WHERE ReimburseCode  = '" \
		+ ReimburseCode + "' and ArchivesName= '" + ArchiveName + "' and FilingState='" + QStringLiteral("已归档") + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	double result = 0.0;
	while (mQuery.next())
	{
		result += mQuery.value(0).toDouble();
	}
	return result;
}

int UrielDatabase::getTotalBillCount(const QString & ReimburseCode) {
	QString strSQL = "select count(*) FROM ilabmanagementsystem.reimburse_management WHERE ReimburseCode  = '" \
		+ ReimburseCode + "' and ReimbursePerson='" + m_pOptions->getAccount() + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	int result;
	while (mQuery.next())
	{
		result = mQuery.value(0).toDouble();
	}
	return result;
}

int UrielDatabase::getTotalBillCount(const QString & ReimburseCode, const QString &ArchiveName) {
	QString strSQL = "select count(*) FROM ilabmanagementsystem.reimburse_management WHERE ReimburseCode  = '" \
		+ ReimburseCode + "' and ArchivesName= '" + ArchiveName + "' and FilingState='" + QStringLiteral("已归档") + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	int result;
	while (mQuery.next())
	{
		result = mQuery.value(0).toDouble();
	}
	return result;
}

double UrielDatabase::getTotalSumOfClaimSummaryOfStaff(const QString & ReimburseCode, const QString &ArchiveName, const QString & staff) {
	QString strSQL = "select AggregateAmount FROM ilabmanagementsystem.reimburse_management WHERE ReimburseCode  = '" \
		+ ReimburseCode + "' and ArchivesName= '" + ArchiveName + "' and ReimbursePerson='"+ staff+"' and FilingState='" + QStringLiteral("已归档") + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	double result = 0.0;
	while (mQuery.next())
	{
		result += mQuery.value(0).toDouble();
	}
	return result;
}
bool UrielDatabase::updateInvoiceTableModel(QString  strSQL)
{
	if (strSQL.isEmpty())
	{
		if (m_pUrielInvoiceTableModel)
		{
			m_pUrielInvoiceTableModel->setQuery(m_szInvoicePreviousQuery);
		}
		return true;
	}
	QString previous_query_current = m_szInvoiceBrowserQuery + strSQL + " order by ID asc";

	if (m_pUrielInvoiceTableModel)
	{
		m_pUrielInvoiceTableModel->setQuery(previous_query_current);
	}
	return true;
}

bool UrielDatabase::getStaffListByReimburseCodeAndArchivesName(QStringList & staffList,const QString&sReimburseCode, const QString&sArchivesName) {
	QString strSQL = "select distinct ReimbursePerson FROM ilabmanagementsystem.reimburse_management WHERE ReimburseCode  = '"
		+ sReimburseCode + "' and ArchivesName='"+ sArchivesName+"'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		staffList << mQuery.value(0).toString();
	}
	return false;
}


UrielInvoiceTableModel * UrielDatabase::creatInvoiceTableModel()
{
	if (m_pUrielInvoiceTableModel != nullptr)
		return m_pUrielInvoiceTableModel;
	m_szInvoiceBrowserQuery = "select ID,ReimburseCode,Type,Name,Model,Quantity,Unit,Univalent,AggregateAmount,ReimbursePerson,ReimburseTime,"
		"FilingState,ArchivesName,Remark from reimburse_management ";
	QStringList list;
	list<< QStringLiteral("ID") << QStringLiteral("报销代号") << QStringLiteral("报销项目") << QStringLiteral("材料名称") << QStringLiteral("材料型号") << QStringLiteral("数量")\
		<< QStringLiteral("单位") << QStringLiteral("单价") << QStringLiteral("总额") << QStringLiteral("报销人") << QStringLiteral("录入时间") \
		<< QStringLiteral("归档状态") <<  QStringLiteral("档案名称") << QStringLiteral("备注");
	m_szInvoicePreviousQuery = m_szInvoiceBrowserQuery + " order by ID asc";
	m_pUrielInvoiceTableModel = new UrielInvoiceTableModel(m_szInvoicePreviousQuery, list, m_Database);
	return m_pUrielInvoiceTableModel;
}

bool UrielDatabase::getInvoiceInfoByID(sUrielInvoiceInfoItem & item, const QString & sId)
{
	QString strSQL = "select ID,ReimburseCode,Type,Name,Model,Quantity,Unit,Univalent,AggregateAmount,Description,InvoiceImagePath,"
		"BuyScreenshotPath,VerificationImagePath,ReimbursePerson,ReimburseTime,FilingState,ArchivesName,Remark FROM ilabmanagementsystem.reimburse_management WHERE ID  = '" + sId + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		item.m_iId = mQuery.value(0).toInt();
		item.m_sReimburseCode = mQuery.value(1).toString();
		item.m_sType = mQuery.value(2).toString();
		item.m_sName = mQuery.value(3).toString();
		item.m_sModel = mQuery.value(4).toString();
		item.m_iQuantity = mQuery.value(5).toInt();
		item.m_sUnit = mQuery.value(6).toString();
		item.m_dUnivalent = mQuery.value(7).toDouble();
		item.m_dAggregateAmount = mQuery.value(8).toDouble();
		item.m_sDescription = mQuery.value(9).toString();
		item.m_sInvoiceImagePath = mQuery.value(10).toString();
		item.m_sBuyScreenshotPath = mQuery.value(11).toString();
		item.m_sVerificationImagePath = mQuery.value(12).toString();
		item.m_sReimbursePerson = mQuery.value(13).toString();
		item.m_tReimburseTime = mQuery.value(14).toDateTime();
		item.m_sFilingState = mQuery.value(15).toString();
		item.m_sArchivesName = mQuery.value(16).toString();
		item.m_sRemark = mQuery.value(17).toString();
		return true;
	}
	return false;
}

bool UrielDatabase::getMaterialCostInvoiceListByReimburseCode(QList<sUrielInvoiceInfoItem> & itemlist, const QString & sReimburseCode) {
	QString strSQL = "select ID,ReimburseCode,Type,Name,Model,Quantity,Unit,Univalent,AggregateAmount,Description,InvoiceImagePath,"
		"BuyScreenshotPath,VerificationImagePath,ReimbursePerson,ReimburseTime,FilingState,ArchivesName,Remark FROM ilabmanagementsystem.reimburse_management WHERE ReimburseCode  = '" 
		+ sReimburseCode + "' and Type='"+QStringLiteral("实验材料购置费")+"' and ReimbursePerson='"+m_pOptions->getAccount()+"'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		sUrielInvoiceInfoItem item;
		item.m_iId = mQuery.value(0).toInt();
		item.m_sReimburseCode = mQuery.value(1).toString();
		item.m_sType = mQuery.value(2).toString();
		item.m_sName = mQuery.value(3).toString();
		item.m_sModel = mQuery.value(4).toString();
		item.m_iQuantity = mQuery.value(5).toInt();
		item.m_sUnit = mQuery.value(6).toString();
		item.m_dUnivalent = mQuery.value(7).toDouble();
		item.m_dAggregateAmount = mQuery.value(8).toDouble();
		item.m_sDescription = mQuery.value(9).toString();
		item.m_sInvoiceImagePath = mQuery.value(10).toString();
		item.m_sBuyScreenshotPath = mQuery.value(11).toString();
		item.m_sVerificationImagePath = mQuery.value(12).toString();
		item.m_sReimbursePerson = mQuery.value(13).toString();
		item.m_tReimburseTime = mQuery.value(14).toDateTime();
		item.m_sFilingState = mQuery.value(15).toString();
		item.m_sArchivesName = mQuery.value(16).toString();
		item.m_sRemark = mQuery.value(17).toString();
		itemlist << item;
	}
	return false;
}

bool UrielDatabase::getMaterialCostInvoiceListByReimburseCode(QList<sUrielInvoiceInfoItem> & itemlist,
	const QString & sReimburseCode, const QString &sArchiveName) {
	QString strSQL = "select ID,ReimburseCode,Type,Name,Model,Quantity,Unit,Univalent,AggregateAmount,Description,InvoiceImagePath,"
		"BuyScreenshotPath,VerificationImagePath,ReimbursePerson,ReimburseTime,FilingState,ArchivesName,Remark FROM ilabmanagementsystem.reimburse_management WHERE ReimburseCode  = '"
		+ sReimburseCode + "' and Type='" + QStringLiteral("实验材料购置费") + "' and ArchivesName='" + sArchiveName + "' and FilingState='" + QStringLiteral("已归档") + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		sUrielInvoiceInfoItem item;
		item.m_iId = mQuery.value(0).toInt();
		item.m_sReimburseCode = mQuery.value(1).toString();
		item.m_sType = mQuery.value(2).toString();
		item.m_sName = mQuery.value(3).toString();
		item.m_sModel = mQuery.value(4).toString();
		item.m_iQuantity = mQuery.value(5).toInt();
		item.m_sUnit = mQuery.value(6).toString();
		item.m_dUnivalent = mQuery.value(7).toDouble();
		item.m_dAggregateAmount = mQuery.value(8).toDouble();
		item.m_sDescription = mQuery.value(9).toString();
		item.m_sInvoiceImagePath = mQuery.value(10).toString();
		item.m_sBuyScreenshotPath = mQuery.value(11).toString();
		item.m_sVerificationImagePath = mQuery.value(12).toString();
		item.m_sReimbursePerson = mQuery.value(13).toString();
		item.m_tReimburseTime = mQuery.value(14).toDateTime();
		item.m_sFilingState = mQuery.value(15).toString();
		item.m_sArchivesName = mQuery.value(16).toString();
		item.m_sRemark = mQuery.value(17).toString();
		itemlist << item;
	}
	return false;
}

bool UrielDatabase::getAllInvoiceListByReimburseCode(QList<sUrielInvoiceInfoItem> & itemlist, const QString & sReimburseCode) {
	QString strSQL = "select ID,ReimburseCode,Type,Name,Model,Quantity,Unit,Univalent,AggregateAmount,Description,InvoiceImagePath,"
		"BuyScreenshotPath,VerificationImagePath,ReimbursePerson,ReimburseTime,FilingState,ArchivesName,Remark FROM ilabmanagementsystem.reimburse_management WHERE ReimburseCode  = '"
		+ sReimburseCode + "' and ReimbursePerson='" + m_pOptions->getAccount() + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		sUrielInvoiceInfoItem item;
		item.m_iId = mQuery.value(0).toInt();
		item.m_sReimburseCode = mQuery.value(1).toString();
		item.m_sType = mQuery.value(2).toString();
		item.m_sName = mQuery.value(3).toString();
		item.m_sModel = mQuery.value(4).toString();
		item.m_iQuantity = mQuery.value(5).toInt();
		item.m_sUnit = mQuery.value(6).toString();
		item.m_dUnivalent = mQuery.value(7).toDouble();
		item.m_dAggregateAmount = mQuery.value(8).toDouble();
		item.m_sDescription = mQuery.value(9).toString();
		item.m_sInvoiceImagePath = mQuery.value(10).toString();
		item.m_sBuyScreenshotPath = mQuery.value(11).toString();
		item.m_sVerificationImagePath = mQuery.value(12).toString();
		item.m_sReimbursePerson = mQuery.value(13).toString();
		item.m_tReimburseTime = mQuery.value(14).toDateTime();
		item.m_sFilingState = mQuery.value(15).toString();
		item.m_sArchivesName = mQuery.value(16).toString();
		item.m_sRemark = mQuery.value(17).toString();
		itemlist << item;
	}
	return false;
}

bool UrielDatabase::getAllInvoiceListByReimburseCodeAndPersonAndArchives(QList<sUrielInvoiceInfoItem> & itemlist,
	const QString & sReimburseCode, const QString & sPerson, const QString & sArchives) {
	QString strSQL = "select ID,ReimburseCode,Type,Name,Model,Quantity,Unit,Univalent,AggregateAmount,Description,InvoiceImagePath,"
		"BuyScreenshotPath,VerificationImagePath,ReimbursePerson,ReimburseTime,FilingState,ArchivesName,Remark FROM ilabmanagementsystem.reimburse_management WHERE ReimburseCode  = '"
		+ sReimburseCode + "' and ReimbursePerson='" + sPerson + "' and ArchivesName='"+ sArchives + "' and FilingState='" + QStringLiteral("已归档") + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		sUrielInvoiceInfoItem item;
		item.m_iId = mQuery.value(0).toInt();
		item.m_sReimburseCode = mQuery.value(1).toString();
		item.m_sType = mQuery.value(2).toString();
		item.m_sName = mQuery.value(3).toString();
		item.m_sModel = mQuery.value(4).toString();
		item.m_iQuantity = mQuery.value(5).toInt();
		item.m_sUnit = mQuery.value(6).toString();
		item.m_dUnivalent = mQuery.value(7).toDouble();
		item.m_dAggregateAmount = mQuery.value(8).toDouble();
		item.m_sDescription = mQuery.value(9).toString();
		item.m_sInvoiceImagePath = mQuery.value(10).toString();
		item.m_sBuyScreenshotPath = mQuery.value(11).toString();
		item.m_sVerificationImagePath = mQuery.value(12).toString();
		item.m_sReimbursePerson = mQuery.value(13).toString();
		item.m_tReimburseTime = mQuery.value(14).toDateTime();
		item.m_sFilingState = mQuery.value(15).toString();
		item.m_sArchivesName = mQuery.value(16).toString();
		item.m_sRemark = mQuery.value(17).toString();
		itemlist << item;
	}
	return false;
}
bool UrielDatabase::getReimbursePersonListByReimburseCodeAndArchives(QStringList & ReimbursePersonList,
	const QString & sReimburseCode, const QString & sArchives) {
	QString strSQL = "select distinct ReimbursePerson FROM ilabmanagementsystem.reimburse_management "
		"WHERE ReimburseCode  = '"+ sReimburseCode +  "' and ArchivesName='" + sArchives +\
		"' and FilingState='" + QStringLiteral("已归档") + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		ReimbursePersonList<< mQuery.value(0).toString();
	}
	return false;
}

bool UrielDatabase::getImageListByReimburseCodeAndArchives(QStringList & ImageList, const QString & sReimburseCode, const QString & sArchives) {
	QString strSQL = "select BuyScreenshotPath FROM ilabmanagementsystem.reimburse_management "
		"WHERE ReimburseCode  = '" + sReimburseCode + "' and ArchivesName='" + sArchives + \
		"' and FilingState='" + QStringLiteral("已归档") + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		ImageList << mQuery.value(0).toString();
	}
	return false;
}

bool UrielDatabase::getVerifyImageListByReimburseCodeAndArchives(QStringList & ImageList, const QString & sReimburseCode, const QString & sArchives) {
	QString strSQL = "select VerificationImagePath FROM ilabmanagementsystem.reimburse_management "
		"WHERE ReimburseCode  = '" + sReimburseCode + "' and ArchivesName='" + sArchives + \
		"' and FilingState='" + QStringLiteral("已归档") + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		ImageList << mQuery.value(0).toString();
	}
	return false;
}
bool UrielDatabase::deleteInvoiceInfoByID(const QString & sId)
{
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("DELETE FROM reimburse_management  WHERE ID ='" + sId + "'");
	if (sQuery.exec())
		return true;
	return false;
}

bool UrielDatabase::insertReimburseArchives(const sUrielReimburseArchivesItem & item) {
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("INSERT INTO ilabmanagementsystem.reimburse_archives(ReimburseCode, ArchivesName)"
		" VALUES (:ReimburseCode,:ArchivesName)");
	sQuery.bindValue(":ReimburseCode", item.m_sReimburseCode);
	sQuery.bindValue(":ArchivesName", item.m_sArchivesName);
	if (sQuery.exec())
	{
		return true;
	}

	//errorInfo = sQuery.lastError().text();
	return false;
}

bool UrielDatabase::deleteReimburseArchives(const sUrielReimburseArchivesItem & item) {
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("DELETE FROM ilabmanagementsystem.reimburse_archives  WHERE ReimburseCode  = '"
		+ item.m_sReimburseCode + "' And ArchivesName='"+ item.m_sArchivesName+"'");
	if (sQuery.exec())
		return true;
	return false;
}

bool UrielDatabase::renameReimburseArchives(const sUrielReimburseArchivesItem & item, const QString & newName) {
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("UPDATE ilabmanagementsystem.reimburse_archives  SET ArchivesName=? WHERE  ReimburseCode  = '"
		+ item.m_sReimburseCode + "' And ArchivesName='" + item.m_sArchivesName + "'");
	sQuery.bindValue(0, newName);

	if (sQuery.exec())
	{
		return true;
	}
	return false;
}

bool UrielDatabase::getArchivesByReimburseCode(QList<sUrielReimburseArchivesItem> & ArchivesList, const QString &sReimburseCode) {
	QString strSQL = "select ID,ReimburseCode,ArchivesName,InvoiceQuantity FROM ilabmanagementsystem.reimburse_archives WHERE ReimburseCode  = '"
		+ sReimburseCode + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		sUrielReimburseArchivesItem item;
		item.m_iId = mQuery.value(0).toInt();
		item.m_sReimburseCode = mQuery.value(1).toString();
		item.m_sArchivesName = mQuery.value(2).toString();
		item.m_iInvoiceQuantity = mQuery.value(3).toInt();
		ArchivesList << item;
	}
	return false;
}

bool UrielDatabase::getProjectListbyReimburseCodeAndArchives(QStringList& ProjectItemList, 
	const QString &sReimburseCode, const QString &sArchivesName) {
	QString strSQL = "select distinct Type FROM ilabmanagementsystem.reimburse_management WHERE ReimburseCode  = '"
		+ sReimburseCode + "' and ArchivesName = '"+ sArchivesName+"'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		ProjectItemList << mQuery.value(0).toString();
	}
	return false;
}
bool UrielDatabase::getProjectListByReimburseCodeAndStaff(QStringList &ProjectItemList, const QString & sReimburseCode, const QString &staff) {
	QString strSQL = "select distinct Type FROM ilabmanagementsystem.reimburse_management WHERE ReimburseCode  = '"
		+ sReimburseCode + "' and ReimbursePerson = '" + staff + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		ProjectItemList << mQuery.value(0).toString();
	}
	return false;
}
bool UrielDatabase::getInvoicetListByReimburseCodeAndStaff(QList<sUrielInvoiceInfoItem>& InvoiceList, const QString & sReimburseCode, const QString &staff) {
	QString strSQL = "select ID,ReimburseCode,Type,Name,Model,Quantity,Unit,Univalent,AggregateAmount,Description,InvoiceImagePath,"
		"BuyScreenshotPath,VerificationImagePath,ReimbursePerson,ReimburseTime,FilingState,ArchivesName,Remark FROM ilabmanagementsystem.reimburse_management WHERE ReimburseCode  = '"
		+ sReimburseCode + "' and ReimbursePerson='" + staff +  "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		sUrielInvoiceInfoItem item;
		item.m_iId = mQuery.value(0).toInt();
		item.m_sReimburseCode = mQuery.value(1).toString();
		item.m_sType = mQuery.value(2).toString();
		item.m_sName = mQuery.value(3).toString();
		item.m_sModel = mQuery.value(4).toString();
		item.m_iQuantity = mQuery.value(5).toInt();
		item.m_sUnit = mQuery.value(6).toString();
		item.m_dUnivalent = mQuery.value(7).toDouble();
		item.m_dAggregateAmount = mQuery.value(8).toDouble();
		item.m_sDescription = mQuery.value(9).toString();
		item.m_sInvoiceImagePath = mQuery.value(10).toString();
		item.m_sBuyScreenshotPath = mQuery.value(11).toString();
		item.m_sVerificationImagePath = mQuery.value(12).toString();
		item.m_sReimbursePerson = mQuery.value(13).toString();
		item.m_tReimburseTime = mQuery.value(14).toDateTime();
		item.m_sFilingState = mQuery.value(15).toString();
		item.m_sArchivesName = mQuery.value(16).toString();
		item.m_sRemark = mQuery.value(17).toString();
		InvoiceList << item;
	}
	return false;
}

int UrielDatabase::getunArchivedCountByReimburseCodeAndProjectAndStaff(const QString &sReimburseCode, const QString &staff, 
	const QString &sProject) {
	QString strSQL = "select count(*) FROM ilabmanagementsystem.reimburse_management WHERE ReimburseCode  = '" \
		+ sReimburseCode + "' and ReimbursePerson='" + staff + "' and Type='"+ sProject+"' and FilingState='"+QStringLiteral("未归档")+"'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		return mQuery.value(0).toInt();;
	}
	return false;
}

int UrielDatabase::getInvoiceCountByReimburseCodeAndProjectAndStaff(const QString &sReimburseCode, const QString &staff, 
	const QString &sProject) {
	QString strSQL = "select count(*) FROM ilabmanagementsystem.reimburse_management WHERE ReimburseCode  = '" \
		+ sReimburseCode + "' and ReimbursePerson='" + staff + "' and Type='" + sProject + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		return mQuery.value(0).toInt();;
	}
	return false;
}
bool UrielDatabase::getInvoiceListbyReimburseCodeAndArchivesAndProject(QList<sUrielInvoiceInfoItem>& InvoiceList,
	const QString &sReimburseCode, const QString &sArchivesName, const QString &sProject)
{
	QString strSQL = "select ID,ReimburseCode,Type,Name,Model,Quantity,Unit,Univalent,AggregateAmount,Description,InvoiceImagePath,"
		"BuyScreenshotPath,VerificationImagePath,ReimbursePerson,ReimburseTime,FilingState,ArchivesName,Remark FROM ilabmanagementsystem.reimburse_management WHERE ReimburseCode  = '"
		+ sReimburseCode + "' and Type='" + sProject + "' and ArchivesName='"+ sArchivesName+"'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		sUrielInvoiceInfoItem item;
		item.m_iId = mQuery.value(0).toInt();
		item.m_sReimburseCode = mQuery.value(1).toString();
		item.m_sType = mQuery.value(2).toString();
		item.m_sName = mQuery.value(3).toString();
		item.m_sModel = mQuery.value(4).toString();
		item.m_iQuantity = mQuery.value(5).toInt();
		item.m_sUnit = mQuery.value(6).toString();
		item.m_dUnivalent = mQuery.value(7).toDouble();
		item.m_dAggregateAmount = mQuery.value(8).toDouble();
		item.m_sDescription = mQuery.value(9).toString();
		item.m_sInvoiceImagePath = mQuery.value(10).toString();
		item.m_sBuyScreenshotPath = mQuery.value(11).toString();
		item.m_sVerificationImagePath = mQuery.value(12).toString();
		item.m_sReimbursePerson = mQuery.value(13).toString();
		item.m_tReimburseTime = mQuery.value(14).toDateTime();
		item.m_sFilingState = mQuery.value(15).toString();
		item.m_sArchivesName = mQuery.value(16).toString();
		item.m_sRemark = mQuery.value(17).toString();
		InvoiceList << item;
	}
	return false;
}

bool UrielDatabase::getunArchivedStaffByReimburseCode(QStringList &unArchivedStaffList, const QString &sReimburseCode) {
	QString strSQL = "select distinct ReimbursePerson FROM ilabmanagementsystem.reimburse_management WHERE ReimburseCode  = '"
		+ sReimburseCode + "' and FilingState = '" + QStringLiteral("未归档") + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		unArchivedStaffList << mQuery.value(0).toString();
	}
	return false;
}
bool UrielDatabase::getArchivedStaffByReimburseCode(QStringList &ArchivedStaffList, const QString &sReimburseCode) {
	QString strSQL = "select distinct ReimbursePerson FROM ilabmanagementsystem.reimburse_management WHERE ReimburseCode  = '"
		+ sReimburseCode + "' and FilingState = '" + QStringLiteral("已归档") + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		ArchivedStaffList << mQuery.value(0).toString();
	}
	return false;
}

int UrielDatabase::getunArchivedCountByReimburseCodeAndStaff(const QString &sReimburseCode, const QString &staff) {
	QString strSQL = "select count(*) FROM ilabmanagementsystem.reimburse_management WHERE ReimburseCode  = '"
		+ sReimburseCode + "' and ReimbursePerson = '" + staff + "' and FilingState = '" + QStringLiteral("未归档") + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	int result;
	while (mQuery.next())
	{
		result= mQuery.value(0).toInt();
	}
	return result;
}

int UrielDatabase::getArchivedCountByReimburseCodeAndStaff(const QString &sReimburseCode, const QString &staff) {
	QString strSQL = "select count(*) FROM ilabmanagementsystem.reimburse_management WHERE ReimburseCode  = '"
		+ sReimburseCode + "' and ReimbursePerson = '" + staff + "' and FilingState = '" + QStringLiteral("已归档") + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	int result;
	while (mQuery.next())
	{
		result = mQuery.value(0).toInt();
	}
	return result;
}

UrielInvoiceTableModel * UrielDatabase::creatInvoiceArchiveTableModel() {
	if (m_pUrielInvoiceArchiveTableModel != nullptr)
		return m_pUrielInvoiceArchiveTableModel;
	m_szInvoiceArchiveBrowserQuery = "select ID,Type,Name,Model,Quantity,Unit,Univalent,AggregateAmount,ReimbursePerson,ReimburseTime,"
		"FilingState,ArchivesName,Remark from reimburse_management";
	QStringList list;
	list << QStringLiteral("ID") << QStringLiteral("报销项目") << QStringLiteral("材料名称") << QStringLiteral("材料型号") << QStringLiteral("数量")\
		<< QStringLiteral("单位") << QStringLiteral("单价") << QStringLiteral("总额") << QStringLiteral("报销人") << QStringLiteral("录入时间") \
		<< QStringLiteral("归档状态") << QStringLiteral("档案名称") << QStringLiteral("备注");
	m_szInvoiceArchivePreviousQuery = m_szInvoiceArchiveBrowserQuery + " order by ID asc";
	m_pUrielInvoiceArchiveTableModel = new UrielInvoiceTableModel(m_szInvoiceArchivePreviousQuery, list, m_Database);
	return m_pUrielInvoiceArchiveTableModel;
}

bool UrielDatabase::updateInvoiceArchiveTableModel(QString  strSQL) {
	if (strSQL.isEmpty())
	{
		if (m_pUrielInvoiceArchiveTableModel)
		{
			m_pUrielInvoiceArchiveTableModel->setQuery(m_szInvoiceArchivePreviousQuery);
		}
		return true;
	}
	QString previous_query_current = m_szInvoiceArchiveBrowserQuery + strSQL + " order by ID asc";

	if (m_pUrielInvoiceArchiveTableModel)
	{
		m_pUrielInvoiceArchiveTableModel->setQuery(previous_query_current);
	}
	return true;
}

bool UrielDatabase::archiveInvoiceIntoSummarySheet(const QString & sid, const QString &sArchivesName) {
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("UPDATE reimburse_management SET FilingState=?,ArchivesName=? WHERE ID='" + sid + "'");
	sQuery.bindValue(0, QStringLiteral("已归档"));
	sQuery.bindValue(1, sArchivesName);

	if (sQuery.exec())
	{
		return true;
	}
	//QString ss = sQuery.lastError().text();
	return false;
}

bool UrielDatabase::unArchiveInvoiceFromSummarySheet(const QString & sid, const QString &sArchivesName) {
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("UPDATE reimburse_management SET FilingState=?,ArchivesName=? WHERE ID='" + sid + "'");
	sQuery.bindValue(0, QStringLiteral("未归档"));
	sQuery.bindValue(1, "");

	if (sQuery.exec())
	{
		return true;
	}
	//QString ss = sQuery.lastError().text();
	return false;
}

bool UrielDatabase::unArchiveAllInvoiceFromSpecifiedSummarySheet(const QString&sReimburseCode, const QString& ArchivesName) {
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("UPDATE reimburse_management SET FilingState=?,ArchivesName=? WHERE ReimburseCode='" + sReimburseCode + "' And ArchivesName= '"+ ArchivesName+"'");
	sQuery.bindValue(0, QStringLiteral("未归档"));
	sQuery.bindValue(1, "");

	if (sQuery.exec())
	{
		return true;
	}
	return false;

}

bool UrielDatabase::renameAllInvoiceArchiveFromSpecifiedSummarySheet(const QString&sReimburseCode, const QString& ArchivesName, const QString& newArchivesName) {
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("UPDATE reimburse_management SET ArchivesName=? WHERE ReimburseCode='" + sReimburseCode + "' And ArchivesName= '" + ArchivesName + "'");
	sQuery.bindValue(0, newArchivesName);

	if (sQuery.exec())
	{
		return true;
	}
	return false;
}

int UrielDatabase::isAllInvoiceArchived(const QString&sReimburseCode) {
	QString strSQL = "select count(*) FROM ilabmanagementsystem.reimburse_management WHERE ReimburseCode  = '"
		+ sReimburseCode +  "' and FilingState = '" + QStringLiteral("未归档") + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	int result=0;
	while (mQuery.next())
	{
		result = mQuery.value(0).toInt();
	}
	return result;
}

bool UrielDatabase::getReimburseStatusByReimburseCode(sUrielReimburseStatusItem & item,const QString &sReimburseCode) {
	QString strSQL = "select ID,ReimburseCode,Status,ReimbursedInvoicesNumber,UnReimbursedInvoicesNumber,TotalReimbursement,TotalReturned,Aggregator,FilingEndTime "
		"FROM ilabmanagementsystem.reimburse_code WHERE ReimburseCode  = '"+ sReimburseCode +  "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		item.m_iId = mQuery.value(0).toInt();
		item.m_sReimburseCode = mQuery.value(1).toString();
		item.m_sStatus = mQuery.value(2).toString();
		item.m_iReimbursedInvoicesNumber = mQuery.value(3).toInt();
		item.m_iUnReimbursedInvoicesNumber = mQuery.value(4).toInt();
		item.m_dTotalReimbursement = mQuery.value(5).toDouble();
		item.m_dTotalReturned = mQuery.value(6).toDouble();
		item.m_sAggregator = mQuery.value(7).toString();
		item.m_tFilingEndTime = mQuery.value(8).toDateTime();
	}
	return false;
}

bool UrielDatabase::getFinishReimburseCode(QStringList& FinishReimburseCodeList) {
	QString strSQL = "select ReimburseCode FROM ilabmanagementsystem.reimburse_code WHERE Status  = '" + QStringLiteral("已完成") + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		FinishReimburseCodeList<< mQuery.value(0).toString();
		
	}
	return false;
}
//updateInvoiceTableModel
bool UrielDatabase::liftingProhibitReimburseCode(const QString &sReimburseCode) {
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("UPDATE reimburse_code SET Status=? WHERE ReimburseCode='" + sReimburseCode + "'");
	sQuery.bindValue(0, QStringLiteral("进行中"));
	if (sQuery.exec())
	{
		return true;
	}
	return false;
}
bool UrielDatabase::ReimburseCodeAddLock(const QString &sReimburseCode) {
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("UPDATE reimburse_code SET Status=? WHERE ReimburseCode='" + sReimburseCode + "'");
	sQuery.bindValue(0, QStringLiteral("已完成"));
	if (sQuery.exec())
	{
		return true;
	}
	return false;
}
bool UrielDatabase::updateReimburseStatusByReimburseCode(sUrielReimburseStatusItem & item, const QString &sReimburseCode) {
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("UPDATE reimburse_code SET ReimburseCode=?,Status=?,ReimbursedInvoicesNumber=?,UnReimbursedInvoicesNumber=?,"
		"TotalReimbursement=?,TotalReturned=?,Aggregator=?,FilingEndTime=? WHERE ReimburseCode='" + sReimburseCode + "'");
	sQuery.bindValue(0, item.m_sReimburseCode);
	sQuery.bindValue(1, item.m_sStatus);
	sQuery.bindValue(2, QString::number(item.m_iReimbursedInvoicesNumber));
	sQuery.bindValue(3, QString::number(item.m_iUnReimbursedInvoicesNumber));
	sQuery.bindValue(4, QString::number(item.m_dTotalReimbursement));
	sQuery.bindValue(5, QString::number(item.m_dTotalReturned));
	sQuery.bindValue(6, item.m_sAggregator);
	sQuery.bindValue(7, item.m_tFilingEndTime.toString("yyyy-MM-dd hh:mm:ss"));
	if (sQuery.exec())
	{
		return true;
	}
	//QString ss = sQuery.lastError().text();
	return false;
}
UrielUserCountTableModel * UrielDatabase::creatUserCountTableModel() {
	if (m_pUrielUserCountTableModel != nullptr)
		return m_pUrielUserCountTableModel;
	m_szUserCountBrowserQuery = "select ID,NAME,SCHOOL_WORK_NUMBER,EMAIL,PHONE_NUMBER,BANK_TYPE,BANK_CARD_NUMBER,PROJECT_TEAM,APPLY_TIME "
		"from account_number";
	QStringList list;
	list << QStringLiteral("ID") << QStringLiteral("姓名") << QStringLiteral("学(工)号") << QStringLiteral("邮箱") << QStringLiteral("电话号码") << QStringLiteral("银行")\
		<< QStringLiteral("银行卡号") << QStringLiteral("项目") << QStringLiteral("申请时间");
	m_szUserCountPreviousQuery = m_szUserCountBrowserQuery + " order by NAME asc";
	m_pUrielUserCountTableModel = new UrielUserCountTableModel(m_szUserCountPreviousQuery, list, m_Database);
	return m_pUrielUserCountTableModel;
}


bool UrielDatabase::updateUserCountTableModel(QString  strSQL)
{
	if (strSQL.isEmpty())
	{
		if (m_pUrielUserCountTableModel)
		{
			m_pUrielUserCountTableModel->setQuery(m_szUserCountPreviousQuery);
		}
		return true;
	}
	QString previous_query_current = m_szUserCountBrowserQuery + strSQL + " order by NAME asc";

	if (m_pUrielUserCountTableModel)
	{
		m_pUrielUserCountTableModel->setQuery(previous_query_current);
	}
	return true;
}

int UrielDatabase::getInvoiceCountByReimburseCodeAndStaff(const QString&sReimburseCode, const QString& staff) {
	QString strSQL = "select count(*) FROM ilabmanagementsystem.reimburse_management WHERE ReimburseCode  = '" \
		+ sReimburseCode + "' and ReimbursePerson='" + staff + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		return mQuery.value(0).toInt();;
	}
	return false;
}

UrielLeaveInfoTableModel * UrielDatabase::creatLeaveInfoTableModel() {
	if (m_pUrielLeaveInfoTableModel != nullptr)
		return m_pUrielLeaveInfoTableModel;
	m_szLeaveInfoBrowserQuery = "select ID,Type,ApplyPerson,EventName,Descripation,ApplyTime,StartTime,EndTime,AuditState,Auditor,AuditorSuggest,AuditTime "
		"from vacation_leave";
	QStringList list;
	list << QStringLiteral("ID") << QStringLiteral("类型") << QStringLiteral("申请人") << QStringLiteral("请假类型") << QStringLiteral("具体原因") << QStringLiteral("申请时间")\
		<< QStringLiteral("开始时间") << QStringLiteral("结束时间") << QStringLiteral("审核状态") << QStringLiteral("审核人") << QStringLiteral("审核建议") << QStringLiteral("审核时间");
	m_szLeaveInfoPreviousQuery = m_szLeaveInfoBrowserQuery + " order by StartTime asc";
	m_pUrielLeaveInfoTableModel = new UrielLeaveInfoTableModel(m_szLeaveInfoPreviousQuery, list, m_Database);
	return m_pUrielLeaveInfoTableModel;
}
bool UrielDatabase::updateLeaveInfoTableModel(QString  strSQL) {
	if (strSQL.isEmpty())
	{
		if (m_pUrielLeaveInfoTableModel)
		{
			m_pUrielLeaveInfoTableModel->setQuery(m_szLeaveInfoPreviousQuery);
		}
		return true;
	}
	QString previous_query_current = m_szLeaveInfoBrowserQuery + strSQL + " order by StartTime asc";

	if (m_pUrielLeaveInfoTableModel)
	{
		m_pUrielLeaveInfoTableModel->setQuery(previous_query_current);
	}
	return true;
}

bool UrielDatabase::insertLoginInfo(const sUrielLoginInfoItem& loginInfoItem) {
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("INSERT INTO ilabmanagementsystem.user_login_info(UserName, HostName, IP, Mac, LoginTime)"
		" VALUES (:UserName,:HostName,:IP,:Mac,:LoginTime)");
	sQuery.bindValue(":UserName", loginInfoItem.m_sUserName);
	sQuery.bindValue(":HostName", loginInfoItem.m_sHostName);
	sQuery.bindValue(":IP", loginInfoItem.m_sIP);
	sQuery.bindValue(":Mac", loginInfoItem.m_sMac);
	sQuery.bindValue(":LoginTime", loginInfoItem.m_tLoginTime.toString("yyyy-MM-dd hh:mm:ss"));
	if (sQuery.exec())
	{
		return true;
	}

	//errorInfo = sQuery.lastError().text();
	return false;
}

UrielLoginTableModel * UrielDatabase::creatLoginTableModel(const QString & userName) {
	if (m_pUrielLoginTableModel != nullptr)
		return m_pUrielLoginTableModel;
	//select * from table order by id desc limit n
	m_szLoginBrowserQuery = "select UserName,HostName,IP,Mac,LoginTime "
		"from user_login_info where UserName='"+ userName+"'";
	QStringList list;
	list << QStringLiteral("用户名") << QStringLiteral("主机名") << QStringLiteral("IP") << QStringLiteral("Mac") << QStringLiteral("最近登录");
	m_szLoginPreviousQuery = m_szLoginBrowserQuery + " order by LoginTime desc limit 5";
	m_pUrielLoginTableModel = new UrielLoginTableModel(m_szLoginPreviousQuery, list, m_Database);
	return m_pUrielLoginTableModel;
}

UrielUserCountTableModel * UrielDatabase::creatNewUserApplyTableModel() {
	if (m_UrielNewUserApplyTableModel != nullptr)
		return m_UrielNewUserApplyTableModel;
	m_szNewUserApplyBrowserQuery = "select ID,NAME,SCHOOL_WORK_NUMBER,EMAIL,PHONE_NUMBER,BANK_TYPE,BANK_CARD_NUMBER,PROJECT_TEAM,PERMISSION,APPLY_TIME "
		"from account_number where STATUS = 'NOT AUDITED'";
	QStringList list;
	list << QStringLiteral("ID") << QStringLiteral("姓名") << QStringLiteral("学(工)号") << QStringLiteral("邮箱") << QStringLiteral("电话号码") << QStringLiteral("银行")\
		<< QStringLiteral("银行卡号") << QStringLiteral("项目") << QStringLiteral("权限") << QStringLiteral("申请时间");
	m_szNewUserApplyPreviousQuery = m_szNewUserApplyBrowserQuery + " order by APPLY_TIME asc";
	m_UrielNewUserApplyTableModel = new UrielUserCountTableModel(m_szNewUserApplyPreviousQuery, list, m_Database);
	return m_UrielNewUserApplyTableModel;
}

bool UrielDatabase::updateNewUserApplyTableModel(QString  strSQL)
{
	if (strSQL.isEmpty())
	{
		if (m_UrielNewUserApplyTableModel)
		{
			m_UrielNewUserApplyTableModel->setQuery(m_szNewUserApplyPreviousQuery);
		}
		return true;
	}
	QString previous_query_current = m_szNewUserApplyBrowserQuery + strSQL + " order by NAME asc";

	if (m_UrielNewUserApplyTableModel)
	{
		m_UrielNewUserApplyTableModel->setQuery(previous_query_current);
	}
	return true;
}

int UrielDatabase::getNumberOfUnAuditedAccount() {
	QString strSQL = "select count(*) FROM ilabmanagementsystem.account_number where STATUS = 'NOT AUDITED'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	int result;
	while (mQuery.next())
	{
		result = mQuery.value(0).toInt();
	}
	return result;
}

bool UrielDatabase::auditedNewUserApply(const QString & name, const QString & admin, const UserAccountStatus& status) {
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("UPDATE ilabmanagementsystem.account_number SET STATUS=?,AUDITOR=?,AUDITOR_TIME=? WHERE NAME='" + name + "'");
	QString sStatus;
	switch (status)
	{
	case UserAccountStatus::Aduited: sStatus = "AUDITED"; break;
	case UserAccountStatus::Rejected: sStatus = "REJECTED"; break;
	default:
		sStatus = "NOT AUDITED";
		break;
	}
	sQuery.bindValue(0, sStatus);
	sQuery.bindValue(1, admin);
	sQuery.bindValue(2, QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));

	if (sQuery.exec())
	{
		return true;
	}
	return false;
}

bool UrielDatabase::auditedAllNewUserApply(const QString & admin) {
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("UPDATE ilabmanagementsystem.account_number SET STATUS=?,AUDITOR=?,AUDITOR_TIME=? WHERE STATUS = 'NOT AUDITED'");
	sQuery.bindValue(0, "AUDITED");
	sQuery.bindValue(1, admin);
	sQuery.bindValue(2, QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));

	if (sQuery.exec())
	{
		return true;
	}
	return false;
}

UrielMaterialPurchaseApplyTableModel * UrielDatabase::creatMaterialPurchaseApplyTableModel() {
	if (m_pUrielMaterialPurchaseApplyTableModel != nullptr)
		return m_pUrielMaterialPurchaseApplyTableModel;
	m_szMaterialPurchaseApplyBrowserQuery = "select ID,ApplicationNumber,TotalAmount,RequisitionReasons,Applicant,DeclarationDate,AuditStatus,LinkAddress "
		"from ilabmanagementsystem.material_purchase_apply where AuditStatus= 'UnAudited'";
	QStringList list;
	list << QStringLiteral("ID") << QStringLiteral("申请号") << QStringLiteral("总金额") << QStringLiteral("采购理由") << QStringLiteral("申请人") << QStringLiteral("申请时间")\
		<< QStringLiteral("状态") << QStringLiteral("链接地址");
	m_szMaterialPurchaseApplyPreviousQuery = m_szMaterialPurchaseApplyBrowserQuery + " order by DeclarationDate asc";
	m_pUrielMaterialPurchaseApplyTableModel = new UrielMaterialPurchaseApplyTableModel(m_szMaterialPurchaseApplyPreviousQuery, list, m_Database);
	return m_pUrielMaterialPurchaseApplyTableModel;
}

bool UrielDatabase::updateMaterialPurchaseApplyTableMode(QString  strSQL) {
	if (strSQL.isEmpty())
	{
		if (m_pUrielMaterialPurchaseApplyTableModel)
		{
			m_pUrielMaterialPurchaseApplyTableModel->setQuery(m_szMaterialPurchaseApplyPreviousQuery);
		}
		return true;
	}
	QString previous_query_current = m_szMaterialPurchaseApplyBrowserQuery + strSQL + " order by DeclarationDate asc";

	if (m_pUrielMaterialPurchaseApplyTableModel)
	{
		m_pUrielMaterialPurchaseApplyTableModel->setQuery(previous_query_current);
	}
	return true;
}

int UrielDatabase::getNumberOfUnAuditedMaterialPurchaseApply() {
	QString strSQL = "select count(*) FROM ilabmanagementsystem.material_purchase_apply where AuditStatus = 'UnAudited'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	int result;
	while (mQuery.next())
	{
		result = mQuery.value(0).toInt();
	}
	return result;
}

int UrielDatabase::getMaterialPurchaseApplyIdByApplicationNumber(const QString &ApplicationNumber) {
	int result;
	QString strSQL = "select ID FROM ilabmanagementsystem.material_purchase_apply where ApplicationNumber = '"+ ApplicationNumber+"'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		result = mQuery.value(0).toInt();
	}
	return result;
}

bool UrielDatabase::auditedMaterialPurchaseApply(const QString & id, const QString & admin,
	const MaterialPurchaseApplyStatus &status, const QString & suggest) {
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("UPDATE ilabmanagementsystem.material_purchase_apply SET AuditStatus=?,Reviewer=?,ReviewTime=?,AuditOpinion=? WHERE ID = '" + id + "'");
	QString sStatus;
	switch (status)
	{
	case MaterialPurchaseApplyStatus::Aduited: sStatus = "Audited"; break;
	case MaterialPurchaseApplyStatus::Rejected: sStatus = "Rejected";  break;
	default:
		sStatus = "UnAudited";
		break;
	}
	sQuery.bindValue(0, sStatus);
	sQuery.bindValue(1, admin);
	sQuery.bindValue(2, QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
	sQuery.bindValue(3, suggest);

	if (sQuery.exec())
	{
		return true;
	}
	std::string xxx = sQuery.lastError().text().toStdString();
	return false;
}
bool UrielDatabase::auditedAllMaterialPurchaseApply(const QString & admin) {
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("UPDATE ilabmanagementsystem.material_purchase_apply SET AuditStatus=?,Reviewer=?,ReviewTime=? WHERE AuditStatus = 'UnAudited'");
	sQuery.bindValue(0, "Audited");
	sQuery.bindValue(1, admin);
	sQuery.bindValue(2, QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
	if (sQuery.exec())
	{
		return true;
	}
	return false;
}

UrielLeaveInfoTableModel *UrielDatabase::creatLeaveApplyTableModel() {
	if (m_UrielLeaveApplyTableModel != nullptr)
		return m_UrielLeaveApplyTableModel;
	m_szLeaveApplyBrowserQuery =  "select ID,Type,ApplyPerson,EventName,Descripation,ApplyTime,StartTime,EndTime,AuditState,Auditor,AuditorSuggest,AuditTime "
		"from vacation_leave where AuditState= 'UnAudit'";
	QStringList list;
	list << QStringLiteral("ID") << QStringLiteral("类型") << QStringLiteral("申请人") << QStringLiteral("请假类型") << QStringLiteral("具体原因") << QStringLiteral("申请时间")\
		<< QStringLiteral("开始时间") << QStringLiteral("结束时间") << QStringLiteral("审核状态") << QStringLiteral("审核人") << QStringLiteral("审核建议") << QStringLiteral("审核时间");
	m_szLeaveApplyPreviousQuery = m_szLeaveApplyBrowserQuery + " order by ApplyTime asc";
	m_UrielLeaveApplyTableModel = new UrielLeaveInfoTableModel(m_szLeaveApplyPreviousQuery, list, m_Database);
	return m_UrielLeaveApplyTableModel;
}

bool UrielDatabase::updateLeaveApplyTableModel(QString  strSQL) {
	if (strSQL.isEmpty())
	{
		if (m_UrielLeaveApplyTableModel)
		{
			m_UrielLeaveApplyTableModel->setQuery(m_szLeaveApplyPreviousQuery);
		}
		return true;
	}
	QString previous_query_current = m_szLeaveApplyBrowserQuery + strSQL + " order by ApplyTime asc";

	if (m_UrielLeaveApplyTableModel)
	{
		m_UrielLeaveApplyTableModel->setQuery(previous_query_current);
	}
	return true;
}

int UrielDatabase::getNumberOfUnAuditedLeaveApply() {
	QString strSQL = "select count(*) FROM ilabmanagementsystem.vacation_leave where AuditState = 'UnAudit'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	int result;
	while (mQuery.next())
	{
		result = mQuery.value(0).toInt();
	}
	return result;
}

bool UrielDatabase::auditedLeaveApply(const QString & id, const QString & admin, const LeaveStatus& status) {
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("UPDATE ilabmanagementsystem.vacation_leave SET AuditState=?,Auditor=?,AuditTime=?,AuditorSuggest=? WHERE ID = '"+ id+"'");
	QString sStatus;
	QString sSuggest;
	switch (status)
	{
	case LeaveStatus::Aduited: sStatus = "Audited"; sSuggest = QStringLiteral("通过"); break;
	case LeaveStatus::AuditNotThrough: sStatus = "AuditNotThrough"; sSuggest = QStringLiteral("不通过"); break;
	default:
		sStatus = "UnAudit";
		sSuggest = QStringLiteral("未审核");
		break;
	}
	sQuery.bindValue(0, sStatus);
	sQuery.bindValue(1, admin);
	sQuery.bindValue(2, QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
	sQuery.bindValue(3, sSuggest);

	if (sQuery.exec())
	{
		return true;
	}
	return false;
}

bool UrielDatabase::auditedAllLeaveApply(const QString & admin) {
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("UPDATE ilabmanagementsystem.vacation_leave SET AuditState=?,Auditor=?,AuditTime=?,AuditorSuggest=? WHERE AuditState = 'UnAudit'");
	sQuery.bindValue(0, "Audited");
	sQuery.bindValue(1, admin);
	sQuery.bindValue(2, QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
	sQuery.bindValue(3, QStringLiteral("通过"));
	if (sQuery.exec())
	{
		return true;
	}
	return false;
}


int UrielDatabase::getLastMaterialPurchaseApplyCodeID() {
	QString strSQL = "SELECT ApplicationNumber FROM ilabmanagementsystem.material_purchase_apply WHERE date_format(DeclarationDate,'%Y-%m-%d') = '"
		+ QDateTime::currentDateTime().toString("yyyy-MM-dd") + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	QString codeId;
	while (mQuery.next())
	{
		codeId = mQuery.value(0).toString();
	}
	int code = (codeId.mid(11, 3)).toInt();
	return code;
}

bool UrielDatabase::insertMaterialDeviceApply(const sUrielMaterialPurchaseApplyItem & MaterialPurchaseApplyItem) {
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("INSERT INTO ilabmanagementsystem.material_purchase_apply( ApplicationNumber, TotalAmount, RequisitionReasons, Applicant, DeclarationDate,"
		" AuditStatus, AuditOpinion, Reviewer, ReviewTime, LinkAddress, Image)"
		" VALUES (:ApplicationNumber,:TotalAmount,:RequisitionReasons,:Applicant,:DeclarationDate,:AuditStatus,:AuditOpinion,:Reviewer,:ReviewTime,:LinkAddress,:Image)");
	sQuery.bindValue(":ApplicationNumber", MaterialPurchaseApplyItem.m_sApplicationNumber);
	sQuery.bindValue(":TotalAmount", MaterialPurchaseApplyItem.m_sTotalAmount);
	sQuery.bindValue(":RequisitionReasons", MaterialPurchaseApplyItem.m_sRequisitionReasons);
	sQuery.bindValue(":Applicant", MaterialPurchaseApplyItem.m_sApplicant);
	sQuery.bindValue(":DeclarationDate", MaterialPurchaseApplyItem.m_tDeclarationDate.toString("yyyy-MM-dd hh:mm:ss"));
	sQuery.bindValue(":AuditStatus", MaterialPurchaseApplyItem.m_sAuditStatus);
	sQuery.bindValue(":AuditOpinion", MaterialPurchaseApplyItem.m_sAuditOpinion);
	sQuery.bindValue(":Reviewer", MaterialPurchaseApplyItem.m_sReviewer);
	sQuery.bindValue(":ReviewTime", MaterialPurchaseApplyItem.m_tReviewTime.toString("yyyy-MM-dd hh:mm:ss"));
	sQuery.bindValue(":LinkAddress", MaterialPurchaseApplyItem.m_sLinkAddress);
	sQuery.bindValue(":Image", MaterialPurchaseApplyItem.m_sImagePath);

	if (sQuery.exec())
	{
		return true;
	}

	//errorInfo = sQuery.lastError().text();
	return false;
}

bool UrielDatabase::insertMaterialDevice(const sUrielMaterialDeviceItem & MaterialDeviceItem) {
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("INSERT INTO ilabmanagementsystem.material_device( ApplicationNumber, SerialNumber, MaterialName, ModelSpecification, Unit,"
		" Quantity, UnitPrice, Total)"
		" VALUES (:ApplicationNumber,:SerialNumber,:MaterialName,:ModelSpecification,:Unit,:Quantity,:UnitPrice,:Total)");
	sQuery.bindValue(":ApplicationNumber", MaterialDeviceItem.m_sApplicationNumber);
	sQuery.bindValue(":SerialNumber", MaterialDeviceItem.m_sSerialNumber);
	sQuery.bindValue(":MaterialName", MaterialDeviceItem.m_sMaterialName);
	sQuery.bindValue(":ModelSpecification", MaterialDeviceItem.m_sModelSpecification);
	sQuery.bindValue(":Unit", MaterialDeviceItem.m_sUnit);
	sQuery.bindValue(":Quantity", MaterialDeviceItem.m_sQuantity);
	sQuery.bindValue(":UnitPrice", MaterialDeviceItem.m_sUnitPrice);
	sQuery.bindValue(":Total", MaterialDeviceItem.m_sTotal);
	if (sQuery.exec())
	{
		return true;
	}
	//errorInfo = sQuery.lastError().text();
	return false;
}

bool UrielDatabase::getDistinctApplicationNumberFromMaterialPurchaseApply(QStringList &ProjectList, const QString & name) {
	QString strSQL = "SELECT DISTINCT ApplicationNumber FROM ilabmanagementsystem.material_purchase_apply where Applicant ='"+name+"'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		ProjectList << (mQuery.value(0).toString());
	}
	return true;
}

bool UrielDatabase::getMaterialNameByApplicationNumber(QStringList & MaterialList, const QString & var) {
	QString strSQL = "SELECT MaterialName FROM ilabmanagementsystem.material_device WHERE ApplicationNumber = '" + var + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		MaterialList << (mQuery.value(0).toString());
	}
	return true;
}

bool UrielDatabase::getMaterialPurchaseApplyByApplicationNumber(sUrielMaterialPurchaseApplyItem & MaterialPurchaseApplyItem, const QString & sApplicationNumber) {
	QString strSQL = "select ID,ApplicationNumber,TotalAmount,RequisitionReasons,Applicant,DeclarationDate,AuditStatus,AuditOpinion,Reviewer,ReviewTime,LinkAddress,Image"
		" FROM ilabmanagementsystem.material_purchase_apply WHERE ApplicationNumber  = '" + sApplicationNumber + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		MaterialPurchaseApplyItem.m_iId = mQuery.value(0).toInt();
		MaterialPurchaseApplyItem.m_sApplicationNumber = mQuery.value(1).toString();
		MaterialPurchaseApplyItem.m_sTotalAmount = mQuery.value(2).toString();
		MaterialPurchaseApplyItem.m_sRequisitionReasons = mQuery.value(3).toString();
		MaterialPurchaseApplyItem.m_sApplicant = mQuery.value(4).toString();
		MaterialPurchaseApplyItem.m_tDeclarationDate = mQuery.value(5).toDateTime();
		MaterialPurchaseApplyItem.m_sAuditStatus = mQuery.value(6).toString();
		MaterialPurchaseApplyItem.m_sAuditOpinion = mQuery.value(7).toString();
		MaterialPurchaseApplyItem.m_sReviewer = mQuery.value(8).toString();
		MaterialPurchaseApplyItem.m_tReviewTime = mQuery.value(9).toDateTime();
		MaterialPurchaseApplyItem.m_sLinkAddress = mQuery.value(10).toString();
		MaterialPurchaseApplyItem.m_sImagePath= mQuery.value(11).toString();
		return true;
	}
	return false;
}

bool UrielDatabase::getAllMaterialDeviceListByApplicationNumber(QList<sUrielMaterialDeviceItem> &MaterialDeviceList, const QString & sApplicationNumber) {
	QString strSQL = "select ID,ApplicationNumber,SerialNumber,MaterialName,ModelSpecification,Unit,Quantity,UnitPrice,Total"
		" FROM ilabmanagementsystem.material_device WHERE ApplicationNumber  = '" + sApplicationNumber + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		sUrielMaterialDeviceItem item;
		item.m_iId = mQuery.value(0).toInt();
		item.m_sApplicationNumber = mQuery.value(1).toString();
		item.m_sSerialNumber = mQuery.value(2).toString();
		item.m_sMaterialName = mQuery.value(3).toString();
		item.m_sModelSpecification = mQuery.value(4).toString();
		item.m_sUnit = mQuery.value(5).toString();
		item.m_sQuantity = mQuery.value(6).toString();
		item.m_sUnitPrice = mQuery.value(7).toString();
		item.m_sTotal = mQuery.value(8).toString();
		MaterialDeviceList << item;
	}
	return false;
}

bool UrielDatabase::getMaterialBySearch(QStringList &MaterialList, const QString & searchName) {
	QString strSQL = "SELECT MaterialName FROM ilabmanagementsystem.material_device  WHERE MaterialName like '%" + searchName + "%'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		MaterialList << (mQuery.value(0).toString());
	}
	return true;
}

QString UrielDatabase::getApplicationNumberByMaterialName(const QString & name) {
	QString strSQL = "SELECT ApplicationNumber FROM ilabmanagementsystem.material_device WHERE MaterialName = '" + name + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	QString result;
	while (mQuery.next())
	{
		result = (mQuery.value(0).toString());
	}
	return result;
}



UrielMeetingReportTableModel* UrielDatabase::creatMeetingReportTableModel() {
	if (m_pUrielMeetingReportTableModel != nullptr)
		return m_pUrielMeetingReportTableModel;
	m_szMeetingReportBrowserQuery = "select ID,Reporter,ReportPath,UploadTime,DownLoadCount from meeting_report";
	QStringList list;
	list << QStringLiteral("ID") << QStringLiteral("汇报人") << QStringLiteral("文件名") << QStringLiteral("上传时间") << QStringLiteral("下载次数");
	m_szMeetingReportPreviousQuery = m_szMeetingReportBrowserQuery + " order by UploadTime desc";
	m_pUrielMeetingReportTableModel = new UrielMeetingReportTableModel(m_szMeetingReportPreviousQuery, list, m_Database);
	return m_pUrielMeetingReportTableModel;
}

bool UrielDatabase::updateMeetingReportTableModel(QString  strSQL) {
	if (strSQL.isEmpty())
	{
		if (m_pUrielMeetingReportTableModel)
		{
			m_pUrielMeetingReportTableModel->setQuery(m_szMeetingReportPreviousQuery);
		}
		return true;
	}
	QString previous_query_current = m_szMeetingReportBrowserQuery + strSQL + " order by UploadTime desc";

	if (m_pUrielMeetingReportTableModel)
	{
		m_pUrielMeetingReportTableModel->setQuery(previous_query_current);
	}
	return true;
}

bool UrielDatabase::insertMeetingReport(const sUrielMeetingReportItem & meetingReport) {
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("INSERT INTO ilabmanagementsystem.meeting_report( Reporter, ReportPath, UploadTime, DownLoadCount)"
		" VALUES (:Reporter,:ReportPath,:UploadTime,:DownLoadCount)");
	sQuery.bindValue(":Reporter", meetingReport.m_sReporter);
	sQuery.bindValue(":ReportPath", meetingReport.ReportPath);
	sQuery.bindValue(":UploadTime", meetingReport.UploadTime.toString("yyyy-MM-dd hh:mm:ss"));
	sQuery.bindValue(":DownLoadCount", meetingReport.DownLoadCount);
	if (sQuery.exec())
	{
		return true;
	}
	//errorInfo = sQuery.lastError().text();
	return false;
}

bool UrielDatabase::updateMeetingReportDownloadCount(const QString & id) {
	QString strSQL = "UPDATE meeting_report SET DownLoadCount=DownLoadCount+1 WHERE ID = '" + id + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		return true;
	}
	return false;
}

bool UrielDatabase::delectMeetingReport(const QString & id) {
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("DELETE FROM meeting_report WHERE ID ='" + id + "'");
	if (sQuery.exec())
		return true;
	return false;
}




UrielPaperTableModel *UrielDatabase::creatPaperTableModel() {
	if (m_pUrielPaperTableModel != nullptr)
		return m_pUrielPaperTableModel;
	m_szPaperBrowserQuery = "select ID,OriginalTitle,TranslationTitle,PeriodicalName,PeriodicalLevel,PeriodicalLanguage,EmploymentTime"
		" ,VolumeNumber,StartAndEndPageNumber,InfluenceFactor,IsThesisContent,CommunicationUnit,Author,IndexedAddress,ServerFileAddress"
		" ,Uploader,UploadTime,DownloadCount from paper";
	QStringList list;
	list << QStringLiteral("ID") << QStringLiteral("原刊题目") << QStringLiteral("翻译题目") << QStringLiteral("期刊名称") 
		<< QStringLiteral("期刊级别") << QStringLiteral("期刊语言") << QStringLiteral("录用时间") << QStringLiteral("卷期号")
		<< QStringLiteral("起止页码") << QStringLiteral("影响因子") << QStringLiteral("学位论文内容") << QStringLiteral("通讯单位")
		<< QStringLiteral("作者信息") << QStringLiteral("收录地址") << QStringLiteral("服务器文件位置") << QStringLiteral("上传者")
		<< QStringLiteral("上传时间") << QStringLiteral("下载次数");
	m_szPaperPreviousQuery = m_szPaperBrowserQuery + " order by EmploymentTime desc";
	m_pUrielPaperTableModel = new UrielPaperTableModel(m_szPaperPreviousQuery, list, m_Database);
	return m_pUrielPaperTableModel;
}


bool UrielDatabase::updatePaperTableModel(QString  strSQL) {
	if (strSQL.isEmpty())
	{
		if (m_pUrielPaperTableModel)
		{
			m_pUrielPaperTableModel->setQuery(m_szPaperPreviousQuery);
		}
		return true;
	}
	QString previous_query_current = m_szPaperBrowserQuery + strSQL + " order by EmploymentTime desc";

	if (m_pUrielPaperTableModel)
	{
		m_pUrielPaperTableModel->setQuery(previous_query_current);
	}
	return true;
}

bool UrielDatabase::getAllPaperAuthorName(QStringList& AuthorList) {
	QString strSQL = "SELECT Author FROM ilabmanagementsystem.paper ";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		AuthorList << (mQuery.value(0).toString());
	}
	QSet<QString> sAuthor;
	for each (QString var in AuthorList)
	{
		QStringList list = var.split(";");
		for each (QString var_ in list)
			sAuthor.insert(var_);
	}
	AuthorList = sAuthor.toList();
	return true;
}

bool UrielDatabase::insertPaper(sUrielPaperItem Paper) {
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("INSERT INTO ilabmanagementsystem.paper( OriginalTitle,TranslationTitle,PeriodicalName,"
		"PeriodicalLevel,PeriodicalLanguage,EmploymentTime,VolumeNumber,StartAndEndPageNumber,InfluenceFactor,"
		"IsThesisContent,CommunicationUnit,Author,IndexedAddress,ServerFileAddress,Abstract,Uploader,UploadTime,DownloadCount)"
		" VALUES (:OriginalTitle,:TranslationTitle,:PeriodicalName,:PeriodicalLevel,:PeriodicalLanguage,:EmploymentTime,:VolumeNumber"
	",:StartAndEndPageNumber,:InfluenceFactor,:IsThesisContent,:CommunicationUnit,:Author,:IndexedAddress,:ServerFileAddress,:Abstract"
		",:Uploader,:UploadTime,:DownloadCount)");
	sQuery.bindValue(":OriginalTitle", Paper.OriginalTitle);
	sQuery.bindValue(":TranslationTitle", Paper.TranslationTitle);
	sQuery.bindValue(":PeriodicalName", Paper.PeriodicalName);
	sQuery.bindValue(":PeriodicalLevel", Paper.PeriodicalLevel);
	sQuery.bindValue(":PeriodicalLanguage", Paper.PeriodicalLanguage);
	sQuery.bindValue(":EmploymentTime", Paper.EmploymentTime.toString("yyyy-MM-dd hh:mm:ss"));
	sQuery.bindValue(":VolumeNumber", Paper.VolumeNumber);
	sQuery.bindValue(":StartAndEndPageNumber", Paper.StartAndEndPageNumber);
	sQuery.bindValue(":InfluenceFactor", Paper.InfluenceFactor);
	sQuery.bindValue(":IsThesisContent", Paper.IsThesisContent);
	sQuery.bindValue(":CommunicationUnit", Paper.CommunicationUnit);
	sQuery.bindValue(":Author", Paper.Author);
	sQuery.bindValue(":IndexedAddress", Paper.IndexedAddress);
	sQuery.bindValue(":ServerFileAddress", Paper.ServerFileAddress);
	sQuery.bindValue(":Abstract", Paper.Abstract);
	sQuery.bindValue(":Uploader", Paper.Uploader);
	sQuery.bindValue(":UploadTime", Paper.UploadTime.toString("yyyy-MM-dd hh:mm:ss"));
	sQuery.bindValue(":DownloadCount", QString::number(Paper.DownloadCount));
	if (sQuery.exec())
	{
		return true;
	}
	return false;
}

bool UrielDatabase::updatePaper(sUrielPaperItem Paper) {
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("UPDATE ilabmanagementsystem.paper SET OriginalTitle=?,TranslationTitle=?,PeriodicalName=?,"
		"PeriodicalLevel=?,PeriodicalLanguage=?,EmploymentTime=?,VolumeNumber=?,StartAndEndPageNumber=?,InfluenceFactor=?,"
		"IsThesisContent=?,CommunicationUnit=?,Author=?,IndexedAddress=?,ServerFileAddress=?,Abstract=?,Uploader=?,UploadTime=?,"
		"DownloadCount=? WHERE ID = '"+QString::number(Paper.ID)+"'");
	sQuery.bindValue(0, Paper.OriginalTitle);
	sQuery.bindValue(1, Paper.TranslationTitle);
	sQuery.bindValue(2, Paper.PeriodicalName);
	sQuery.bindValue(3, Paper.PeriodicalLevel);
	sQuery.bindValue(4, Paper.PeriodicalLanguage);
	sQuery.bindValue(5, Paper.EmploymentTime.toString("yyyy-MM-dd hh:mm:ss"));
	sQuery.bindValue(6, Paper.VolumeNumber);
	sQuery.bindValue(7, Paper.StartAndEndPageNumber);
	sQuery.bindValue(8, Paper.InfluenceFactor);
	sQuery.bindValue(9, Paper.IsThesisContent);
	sQuery.bindValue(10, Paper.CommunicationUnit);
	sQuery.bindValue(11, Paper.Author);
	sQuery.bindValue(12, Paper.IndexedAddress);
	sQuery.bindValue(13, Paper.ServerFileAddress);
	sQuery.bindValue(14, Paper.Abstract);
	sQuery.bindValue(15, Paper.Uploader);
	sQuery.bindValue(16, Paper.UploadTime.toString("yyyy-MM-dd hh:mm:ss"));
	sQuery.bindValue(17, QString::number(Paper.DownloadCount));

	if (sQuery.exec())
	{
		return true;
	}
	return false;
}

bool UrielDatabase::getPaperInfoByID(sUrielPaperItem& item, const QString & id) {
	QString strSQL = "select ID,OriginalTitle,TranslationTitle,PeriodicalName,PeriodicalLevel,PeriodicalLanguage,EmploymentTime"
		" ,VolumeNumber,StartAndEndPageNumber,InfluenceFactor,IsThesisContent,CommunicationUnit,Author,IndexedAddress,ServerFileAddress"
		" ,Abstract,Uploader,UploadTime,DownloadCount FROM ilabmanagementsystem.paper WHERE ID  = '" + id + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		item.ID = mQuery.value(0).toInt();
		item.OriginalTitle = mQuery.value(1).toString();
		item.TranslationTitle = mQuery.value(2).toString();
		item.PeriodicalName = mQuery.value(3).toString();
		item.PeriodicalLevel = mQuery.value(4).toString();
		item.PeriodicalLanguage = mQuery.value(5).toString();
		item.EmploymentTime = mQuery.value(6).toDateTime();
		item.VolumeNumber = mQuery.value(7).toString();
		item.StartAndEndPageNumber = mQuery.value(8).toString();
		item.InfluenceFactor = mQuery.value(9).toString();
		item.IsThesisContent = mQuery.value(10).toString();
		item.CommunicationUnit = mQuery.value(11).toString();
		item.Author = mQuery.value(12).toString();
		item.IndexedAddress = mQuery.value(13).toString();
		item.ServerFileAddress = mQuery.value(14).toString();
		item.Abstract = mQuery.value(15).toString();
		item.Uploader = mQuery.value(16).toString();
		item.UploadTime = mQuery.value(17).toDateTime();
		item.DownloadCount = mQuery.value(18).toInt();
		return true;
	}
	return false;
}

bool UrielDatabase::deletePaper(const QString & id) {
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("DELETE FROM paper  WHERE ID ='" + id + "'");
	if (sQuery.exec())
		return true;
	return false;
}

bool UrielDatabase::updatePaperDownloadCount(const QString & id) {
	QString strSQL = "UPDATE paper SET DownLoadCount=DownLoadCount+1 WHERE ID = '" + id + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		return true;
	}
	return false;
}


UrielAcademicConferenceTableModel *UrielDatabase::creatAcademicConferenceTableModel() {
	if (m_pUrielAcademicConferenceTableModel != nullptr)
		return m_pUrielAcademicConferenceTableModel;
	m_szAcademicConferenceBrowserQuery = "select ID,OriginalTitle,TranslationTitle,ReleaseTime,ConferenceLanguage,PublicationForm,Author"
		",ConferenceName,ConferenceSessionsNumber,IndexedAddress,ServerFileAddress,Uploader,UploadTime,DownloadCount from academic_conference";
	QStringList list;
	list << QStringLiteral("ID") << QStringLiteral("论文题目") << QStringLiteral("翻译题目") << QStringLiteral("发表时间")
		<< QStringLiteral("会议语言") << QStringLiteral("发表形式") << QStringLiteral("作者信息") << QStringLiteral("会议名称")
		<< QStringLiteral("会议届数") << QStringLiteral("收录地址") << QStringLiteral("服务器文件位置") 
		<< QStringLiteral("上传者")<< QStringLiteral("上传时间") << QStringLiteral("下载次数");
	m_szAcademicConferencePreviousQuery = m_szAcademicConferenceBrowserQuery + " order by ReleaseTime desc";
	m_pUrielAcademicConferenceTableModel = new UrielAcademicConferenceTableModel(m_szAcademicConferencePreviousQuery, list, m_Database);
	return m_pUrielAcademicConferenceTableModel;
}
bool UrielDatabase::updateAcademicConferenceTableModel(QString  strSQL) {
	if (strSQL.isEmpty())
	{
		if (m_pUrielAcademicConferenceTableModel)
		{
			m_pUrielAcademicConferenceTableModel->setQuery(m_szAcademicConferencePreviousQuery);
		}
		return true;
	}
	QString previous_query_current = m_szAcademicConferenceBrowserQuery + strSQL + " order by ReleaseTime desc";

	if (m_pUrielAcademicConferenceTableModel)
	{
		m_pUrielAcademicConferenceTableModel->setQuery(previous_query_current);
	}
	return true;
}
bool UrielDatabase::getAllAcademicConferenceAuthorName(QStringList& AuthorList) {
	QString strSQL = "SELECT Author FROM ilabmanagementsystem.academic_conference ";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		AuthorList << (mQuery.value(0).toString());
	}
	QSet<QString> sAuthor;
	for each (QString var in AuthorList)
	{
		QStringList list = var.split(";");
		for each (QString var_ in list)
			sAuthor.insert(var_);
	}
	AuthorList = sAuthor.toList();
	return true;
}
bool UrielDatabase::insertAcademicConference(sUrielAcademicConferenceItem AcademicConference) {
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("INSERT INTO ilabmanagementsystem.academic_conference(OriginalTitle,TranslationTitle,ReleaseTime,ConferenceLanguage,"
		"PublicationForm,Author,ConferenceName,ConferenceSessionsNumber,IndexedAddress,ServerFileAddress,Abstract,Uploader,UploadTime,DownloadCount)"
		" VALUES (:OriginalTitle,:TranslationTitle,:ReleaseTime,:ConferenceLanguage,:PublicationForm,:Author,:ConferenceName"
		",:ConferenceSessionsNumber,:IndexedAddress,:ServerFileAddress,:Abstract,:Uploader,:UploadTime,:DownloadCount)");
	sQuery.bindValue(":OriginalTitle", AcademicConference.OriginalTitle);
	sQuery.bindValue(":TranslationTitle", AcademicConference.TranslationTitle);
	sQuery.bindValue(":ReleaseTime", AcademicConference.ReleaseTime.toString("yyyy-MM-dd hh:mm:ss"));
	sQuery.bindValue(":ConferenceLanguage", AcademicConference.ConferenceLanguage);
	sQuery.bindValue(":PublicationForm", AcademicConference.PublicationForm);
	sQuery.bindValue(":Author", AcademicConference.Author);
	sQuery.bindValue(":ConferenceName", AcademicConference.ConferenceName);
	sQuery.bindValue(":ConferenceSessionsNumber", AcademicConference.ConferenceSessionsNumber);
	sQuery.bindValue(":IndexedAddress", AcademicConference.IndexedAddress);
	sQuery.bindValue(":ServerFileAddress", AcademicConference.ServerFileAddress);
	sQuery.bindValue(":Abstract", AcademicConference.Abstract);
	sQuery.bindValue(":Uploader", AcademicConference.Uploader);
	sQuery.bindValue(":UploadTime", AcademicConference.UploadTime.toString("yyyy-MM-dd hh:mm:ss"));
	sQuery.bindValue(":DownloadCount", QString::number(AcademicConference.DownloadCount));

	if (sQuery.exec())
	{
		return true;
	}
	return false;
}
bool UrielDatabase::updateAcademicConference(sUrielAcademicConferenceItem AcademicConference) {
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("UPDATE ilabmanagementsystem.academic_conference SET OriginalTitle=?,TranslationTitle=?,ReleaseTime=?,"
		"ConferenceLanguage=?,PublicationForm=?,Author=?,ConferenceName=?,ConferenceSessionsNumber=?,IndexedAddress=?,"
		"ServerFileAddress=?,Abstract=?,Uploader=?,UploadTime=?,DownloadCount=? WHERE ID = '" + QString::number(AcademicConference.ID) + "'");
	sQuery.bindValue(0, AcademicConference.OriginalTitle);
	sQuery.bindValue(1, AcademicConference.TranslationTitle);
	sQuery.bindValue(2, AcademicConference.ReleaseTime.toString("yyyy-MM-dd hh:mm:ss"));
	sQuery.bindValue(3, AcademicConference.ConferenceLanguage);
	sQuery.bindValue(4, AcademicConference.PublicationForm);
	sQuery.bindValue(5, AcademicConference.Author);
	sQuery.bindValue(6, AcademicConference.ConferenceName);
	sQuery.bindValue(7, AcademicConference.ConferenceSessionsNumber);
	sQuery.bindValue(8, AcademicConference.IndexedAddress);
	sQuery.bindValue(9, AcademicConference.ServerFileAddress);
	sQuery.bindValue(10, AcademicConference.Abstract);
	sQuery.bindValue(11, AcademicConference.Uploader);
	sQuery.bindValue(12, AcademicConference.UploadTime.toString("yyyy-MM-dd hh:mm:ss"));
	sQuery.bindValue(13, QString::number(AcademicConference.DownloadCount));

	if (sQuery.exec())
	{
		return true;
	}
	return false;
}
bool UrielDatabase::getAcademicConferenceInfoByID(sUrielAcademicConferenceItem& item, const QString & id) {
	QString strSQL = "select ID,OriginalTitle,TranslationTitle,ReleaseTime,ConferenceLanguage,"
		"PublicationForm,Author,ConferenceName,ConferenceSessionsNumber,IndexedAddress,ServerFileAddress,"
		"Abstract,Uploader,UploadTime,DownloadCount FROM ilabmanagementsystem.academic_conference WHERE ID  = '" + id + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		item.ID = mQuery.value(0).toInt();
		item.OriginalTitle = mQuery.value(1).toString();
		item.TranslationTitle = mQuery.value(2).toString();
		item.ReleaseTime = mQuery.value(3).toDateTime();
		item.ConferenceLanguage = mQuery.value(4).toString();
		item.PublicationForm = mQuery.value(5).toString();
		item.Author = mQuery.value(6).toString();
		item.ConferenceName = mQuery.value(7).toString();
		item.ConferenceSessionsNumber = mQuery.value(8).toString();
		item.IndexedAddress = mQuery.value(9).toString();
		item.ServerFileAddress = mQuery.value(10).toString();
		item.Abstract = mQuery.value(11).toString();
		item.Uploader = mQuery.value(12).toString();
		item.UploadTime = mQuery.value(13).toDateTime();
		item.DownloadCount = mQuery.value(14).toInt();;
		return true;
	}
	return false;
}
bool UrielDatabase::deleteAcademicConference(const QString & id) {
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("DELETE FROM academic_conference  WHERE ID ='" + id + "'");
	if (sQuery.exec())
		return true;
	return false;
}
bool UrielDatabase::updateAcademicConferenceDownloadCount(const QString & id) {
	QString strSQL = "UPDATE academic_conference SET DownLoadCount=DownLoadCount+1 WHERE ID = '" + id + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		return true;
	}
	return false;
}

UrielPatentTableModel *UrielDatabase::creatPatentTableModel() {
	if (m_pUrielPatentTableModel != nullptr)
		return m_pUrielPatentTableModel;
	m_szPatentBrowserQuery = "select ID,Type,Number,Name,ApplyTime,ReleaseTime,AuthorizationTime"
		",CopyRightUnit,Author,IndexedAddress,ServerFileAddress,Uploader,UploadTime,DownloadCount from patent";
	QStringList list;
	list << QStringLiteral("ID") << QStringLiteral("专利类型") << QStringLiteral("专利号") << QStringLiteral("专利名称")
		<< QStringLiteral("申请时间") << QStringLiteral("公布时间") << QStringLiteral("授权时间") << QStringLiteral("专利所有单位")
		<< QStringLiteral("作者信息") << QStringLiteral("收录地址") << QStringLiteral("服务器文件位置")
		<< QStringLiteral("上传者") << QStringLiteral("上传时间") << QStringLiteral("下载次数");
	m_szPatentPreviousQuery = m_szPatentBrowserQuery + " order by AuthorizationTime desc";
	m_pUrielPatentTableModel = new UrielPatentTableModel(m_szPatentPreviousQuery, list, m_Database);
	return m_pUrielPatentTableModel;
}
bool UrielDatabase::updatePatentTableModel(QString  strSQL) {
	if (strSQL.isEmpty())
	{
		if (m_pUrielPatentTableModel)
		{
			m_pUrielPatentTableModel->setQuery(m_szPatentPreviousQuery);
		}
		return true;
	}
	QString previous_query_current = m_szPatentBrowserQuery + strSQL + " order by AuthorizationTime desc";

	if (m_pUrielPatentTableModel)
	{
		m_pUrielPatentTableModel->setQuery(previous_query_current);
	}
	return true;
}
bool UrielDatabase::getAllPatentAuthorName(QStringList& AuthorList) {
	QString strSQL = "SELECT Author FROM ilabmanagementsystem.patent ";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		AuthorList << (mQuery.value(0).toString());
	}
	QSet<QString> sAuthor;
	for each (QString var in AuthorList)
	{
		QStringList list = var.split(";");
		for each (QString var_ in list)
			sAuthor.insert(var_);
	}
	AuthorList = sAuthor.toList();
	return true;
}
bool UrielDatabase::insertPatent(sUrielPatentItem Patent) {
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("INSERT INTO ilabmanagementsystem.patent(Type,Number,Name,ApplyTime,ReleaseTime,AuthorizationTime"
		",CopyRightUnit,Author,IndexedAddress,ServerFileAddress,Abstract,Uploader,UploadTime,DownloadCount)"
		" VALUES (:Type,:Number,:Name,:ApplyTime,:ReleaseTime,:AuthorizationTime,:CopyRightUnit"
		",:Author,:IndexedAddress,:ServerFileAddress,:Abstract,:Uploader,:UploadTime,:DownloadCount)");
	sQuery.bindValue(":Type", Patent.Type);
	sQuery.bindValue(":Number", Patent.Number);
	sQuery.bindValue(":Name", Patent.Name);
	sQuery.bindValue(":ApplyTime", Patent.ApplyTime.toString("yyyy-MM-dd hh:mm:ss"));
	sQuery.bindValue(":ReleaseTime", Patent.ReleaseTime.toString("yyyy-MM-dd hh:mm:ss"));
	sQuery.bindValue(":AuthorizationTime", Patent.AuthorizationTime.toString("yyyy-MM-dd hh:mm:ss"));
	sQuery.bindValue(":CopyRightUnit", Patent.CopyRightUnit);
	sQuery.bindValue(":Author", Patent.Author);
	sQuery.bindValue(":IndexedAddress", Patent.IndexedAddress);
	sQuery.bindValue(":ServerFileAddress", Patent.ServerFileAddress);
	sQuery.bindValue(":Abstract", Patent.Abstract);
	sQuery.bindValue(":Uploader", Patent.Uploader);
	sQuery.bindValue(":UploadTime", Patent.UploadTime.toString("yyyy-MM-dd hh:mm:ss"));
	sQuery.bindValue(":DownloadCount", QString::number(Patent.DownloadCount));

	if (sQuery.exec())
	{
		return true;
	}
	return false;
}
bool UrielDatabase::updatePatent(sUrielPatentItem Patent) {
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("UPDATE ilabmanagementsystem.patent SET Type=?,Number=?,Name=?,"
		"ApplyTime=?,ReleaseTime=?,AuthorizationTime=?,CopyRightUnit=?,Author=?,IndexedAddress=?,"
		"ServerFileAddress=?,Abstract=?,Uploader=?,UploadTime=?,DownloadCount=? WHERE ID = '" + QString::number(Patent.ID) + "'");
	sQuery.bindValue(0, Patent.Type);
	sQuery.bindValue(1, Patent.Number);
	sQuery.bindValue(2, Patent.Name);
	sQuery.bindValue(3, Patent.ApplyTime.toString("yyyy-MM-dd hh:mm:ss"));
	sQuery.bindValue(4, Patent.ReleaseTime.toString("yyyy-MM-dd hh:mm:ss"));
	sQuery.bindValue(5, Patent.AuthorizationTime.toString("yyyy-MM-dd hh:mm:ss"));
	sQuery.bindValue(6, Patent.CopyRightUnit);
	sQuery.bindValue(7, Patent.Author);
	sQuery.bindValue(8, Patent.IndexedAddress);
	sQuery.bindValue(9, Patent.ServerFileAddress);
	sQuery.bindValue(10, Patent.Abstract);
	sQuery.bindValue(11, Patent.Uploader);
	sQuery.bindValue(12, Patent.UploadTime.toString("yyyy-MM-dd hh:mm:ss"));
	sQuery.bindValue(13, QString::number(Patent.DownloadCount));

	if (sQuery.exec())
	{
		return true;
	}
	return false;
}
bool UrielDatabase::getPatentInfoByID(sUrielPatentItem& item, const QString & id) {
	QString strSQL = "select ID,Type,Number,Name,ApplyTime,ReleaseTime,AuthorizationTime"
		",CopyRightUnit,Author,IndexedAddress,ServerFileAddress,Abstract,Uploader,UploadTime,DownloadCount"
		" FROM ilabmanagementsystem.patent WHERE ID  = '" + id + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		item.ID = mQuery.value(0).toInt();
		item.Type = mQuery.value(1).toString();
		item.Number = mQuery.value(2).toString();
		item.Name = mQuery.value(3).toString();
		item.ApplyTime = mQuery.value(4).toDateTime();
		item.ReleaseTime = mQuery.value(5).toDateTime();
		item.AuthorizationTime = mQuery.value(6).toDateTime();
		item.CopyRightUnit = mQuery.value(7).toString();
		item.Author = mQuery.value(8).toString();
		item.IndexedAddress = mQuery.value(9).toString();
		item.ServerFileAddress = mQuery.value(10).toString();
		item.Abstract = mQuery.value(11).toString();
		item.Uploader = mQuery.value(12).toString();
		item.UploadTime = mQuery.value(13).toDateTime();
		item.DownloadCount = mQuery.value(14).toInt();;
		return true;
	}
	return false;
}
bool UrielDatabase::deletePatent(const QString & id) {
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("DELETE FROM patent WHERE ID ='" + id + "'");
	if (sQuery.exec())
		return true;
	return false;
}
bool UrielDatabase::updatePatentDownloadCount(const QString & id) {
	QString strSQL = "UPDATE patent SET DownLoadCount=DownLoadCount+1 WHERE ID = '" + id + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		return true;
	}
	return false;
}


UrielWorksTableModel *UrielDatabase::creatWorksTableModel() {
	if (m_pUrielWorksTableModel != nullptr)
		return m_pUrielWorksTableModel;
	m_szWorksBrowserQuery = "select ID,Type,Name,PublishingHouse,EmploymentTime,PublishingTime,ISBN"
		",PrintingTimes,Author,ServerFileAddress,Uploader,UploadTime,DownloadCount from works";
	QStringList list;
	list << QStringLiteral("ID") << QStringLiteral("著作类型") << QStringLiteral("著作名称") << QStringLiteral("出版社")
		<< QStringLiteral("录用时间") << QStringLiteral("出版时间") << QStringLiteral("ISBN") << QStringLiteral("印刷次数")
		<< QStringLiteral("作者信息") << QStringLiteral("服务器文件位置")<< QStringLiteral("上传者") << QStringLiteral("上传时间") << QStringLiteral("下载次数");
	m_szWorksPreviousQuery = m_szWorksBrowserQuery + " order by PublishingTime desc";
	m_pUrielWorksTableModel = new UrielWorksTableModel(m_szWorksPreviousQuery, list, m_Database);
	return m_pUrielWorksTableModel;
}
bool UrielDatabase::updateWorksTableModel(QString  strSQL) {
	if (strSQL.isEmpty())
	{
		if (m_pUrielWorksTableModel)
		{
			m_pUrielWorksTableModel->setQuery(m_szWorksPreviousQuery);
		}
		return true;
	}
	QString previous_query_current = m_szWorksBrowserQuery + strSQL + " order by PublishingTime desc";

	if (m_pUrielWorksTableModel)
	{
		m_pUrielWorksTableModel->setQuery(previous_query_current);
	}
	return true;
}
bool UrielDatabase::getAllWorksAuthorName(QStringList& AuthorList) {
	QString strSQL = "SELECT Author FROM ilabmanagementsystem.works ";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		AuthorList << (mQuery.value(0).toString());
	}
	QSet<QString> sAuthor;
	for each (QString var in AuthorList)
	{
		QStringList list = var.split(";");
		for each (QString var_ in list)
			sAuthor.insert(var_);
	}
	AuthorList = sAuthor.toList();
	return true;
}
bool UrielDatabase::insertWorks(sUrielWorksItem Works) {
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("INSERT INTO ilabmanagementsystem.works(Type,Name,PublishingHouse,EmploymentTime,PublishingTime,ISBN"
		",PrintingTimes,Author,ServerFileAddress,Abstract,Uploader,UploadTime,DownloadCount)"
		" VALUES (:Type,:Name,:PublishingHouse,:EmploymentTime,:PublishingTime,:ISBN,:PrintingTimes"
		",:Author,:ServerFileAddress,:Abstract,:Uploader,:UploadTime,:DownloadCount)");
	sQuery.bindValue(":Type", Works.Type);
	sQuery.bindValue(":Name", Works.Name);
	sQuery.bindValue(":PublishingHouse", Works.PublishingHouse);
	sQuery.bindValue(":EmploymentTime", Works.EmploymentTime.toString("yyyy-MM-dd hh:mm:ss"));
	sQuery.bindValue(":PublishingTime", Works.PublishingTime.toString("yyyy-MM-dd hh:mm:ss"));
	sQuery.bindValue(":ISBN", Works.ISBN);
	sQuery.bindValue(":PrintingTimes", Works.PrintingTimes);
	sQuery.bindValue(":Author", Works.Author);
	sQuery.bindValue(":ServerFileAddress", Works.ServerFileAddress);
	sQuery.bindValue(":Abstract", Works.Abstract);
	sQuery.bindValue(":Uploader", Works.Uploader);
	sQuery.bindValue(":UploadTime", Works.UploadTime.toString("yyyy-MM-dd hh:mm:ss"));
	sQuery.bindValue(":DownloadCount", QString::number(Works.DownloadCount));

	if (sQuery.exec())
	{
		return true;
	}
	return false;
}
bool UrielDatabase::updateWorks(sUrielWorksItem Works) {
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("UPDATE ilabmanagementsystem.works SET Type=?,Name=?,PublishingHouse=?,EmploymentTime=?,PublishingTime=?,ISBN=?"
		",PrintingTimes=?,Author=?,ServerFileAddress=?,Abstract=?,Uploader=?,UploadTime=?,DownloadCount=? WHERE ID = '" + QString::number(Works.ID) + "'");
	sQuery.bindValue(0, Works.Type);
	sQuery.bindValue(1, Works.Name);
	sQuery.bindValue(2, Works.PublishingHouse);
	sQuery.bindValue(3, Works.EmploymentTime.toString("yyyy-MM-dd hh:mm:ss"));
	sQuery.bindValue(4, Works.PublishingTime.toString("yyyy-MM-dd hh:mm:ss"));
	sQuery.bindValue(5, Works.ISBN);
	sQuery.bindValue(6, Works.PrintingTimes);
	sQuery.bindValue(7, Works.Author);
	sQuery.bindValue(8, Works.ServerFileAddress);
	sQuery.bindValue(9, Works.Abstract);
	sQuery.bindValue(10, Works.Uploader);
	sQuery.bindValue(11, Works.UploadTime.toString("yyyy-MM-dd hh:mm:ss"));
	sQuery.bindValue(12, QString::number(Works.DownloadCount));

	if (sQuery.exec())
	{
		return true;
	}
	return false;
}
bool UrielDatabase::getWorksInfoByID(sUrielWorksItem& item, const QString & id) {
	QString strSQL = "select ID,Type,Name,PublishingHouse,EmploymentTime,PublishingTime,ISBN"
		",PrintingTimes,Author,ServerFileAddress,Abstract,Uploader,UploadTime,DownloadCount"
		" FROM ilabmanagementsystem.works WHERE ID  = '" + id + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		item.ID = mQuery.value(0).toInt();
		item.Type = mQuery.value(1).toString();
		item.Name = mQuery.value(2).toString();
		item.PublishingHouse = mQuery.value(3).toString();
		item.EmploymentTime = mQuery.value(4).toDateTime();
		item.PublishingTime = mQuery.value(5).toDateTime();
		item.ISBN = mQuery.value(6).toString();
		item.PrintingTimes = mQuery.value(7).toString();
		item.Author = mQuery.value(8).toString();
		item.ServerFileAddress = mQuery.value(9).toString();
		item.Abstract = mQuery.value(10).toString();
		item.Uploader = mQuery.value(11).toString();
		item.UploadTime = mQuery.value(12).toDateTime();
		item.DownloadCount = mQuery.value(13).toInt();;
		return true;
	}
	return false;
}
bool UrielDatabase::deleteWorks(const QString & id) {
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("DELETE FROM works WHERE ID ='" + id + "'");
	if (sQuery.exec())
		return true;
	return false;
}
bool UrielDatabase::updateWorksDownloadCount(const QString & id) {
	QString strSQL = "UPDATE works SET DownLoadCount=DownLoadCount+1 WHERE ID = '" + id + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		return true;
	}
	return false;
}

UrielResearchProjectTableModel *UrielDatabase::creatResearchProjectTableModel() {
	if (m_pUrielResearchProjectTableModel != nullptr)
		return m_pUrielResearchProjectTableModel;
	m_szResearchProjectBrowserQuery = "select ID,Name,StartTime,EndTime,Type,Number,Funds"
		",Participants,ServerDataAddress,ServerPaperAddress,IndexedAddress,Graduates,UploadTime,"
		"AuditStatus,Auditor,AuditTime,DownloadCount from researchproject";
	QStringList list;
	list << QStringLiteral("ID") << QStringLiteral("项目名称") << QStringLiteral("开始时间") << QStringLiteral("结束时间")
		<< QStringLiteral("项目类别") << QStringLiteral("项目编号") << QStringLiteral("项目经费") << QStringLiteral("参与人员")
		<< QStringLiteral("服务器实验数据位置") << QStringLiteral("服务器论文位置") << QStringLiteral("收录地址") 
		<< QStringLiteral("毕业生") << QStringLiteral("上传时间") << QStringLiteral("审核状态") << QStringLiteral("审核人员") 
		<< QStringLiteral("审核时间") << QStringLiteral("下载次数");
	m_szResearchProjectPreviousQuery = m_szResearchProjectBrowserQuery + " order by ID desc";
	m_pUrielResearchProjectTableModel = new UrielResearchProjectTableModel(m_szResearchProjectPreviousQuery, list, m_Database);
	return m_pUrielResearchProjectTableModel;
}
bool UrielDatabase::updateResearchProjectTableModel(QString  strSQL) {
	if (strSQL.isEmpty())
	{
		if (m_pUrielResearchProjectTableModel)
		{
			m_pUrielResearchProjectTableModel->setQuery(m_szResearchProjectPreviousQuery);
		}
		return true;
	}
	QString previous_query_current = m_szResearchProjectBrowserQuery + strSQL + " order by ID desc";

	if (m_pUrielResearchProjectTableModel)
	{
		m_pUrielResearchProjectTableModel->setQuery(previous_query_current);
	}
	return true;
}
bool UrielDatabase::getAllResearchProjectAuthorName(QStringList& AuthorList) {
	QString strSQL = "SELECT Participants FROM ilabmanagementsystem.researchproject ";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		AuthorList << (mQuery.value(0).toString());
	}
	QSet<QString> sAuthor;
	for each (QString var in AuthorList)
	{
		QStringList list = var.split(";");
		for each (QString var_ in list)
			sAuthor.insert(var_);
	}
	AuthorList = sAuthor.toList();
	return true;
}
bool UrielDatabase::insertResearchProject(sUrielResearchProjectItem ResearchProject) {
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("INSERT INTO ilabmanagementsystem.researchproject(Name,StartTime,EndTime,Type,Number,Funds"
		",Participants,ServerDataAddress,ServerPaperAddress,IndexedAddress,Abstract,Graduates,UploadTime,"
		"AuditStatus,Auditor,AuditTime,DownloadCount)"
		" VALUES (:Name,:StartTime,:EndTime,:Type,:Number,:Funds,:Participants"
		",:ServerDataAddress,:ServerPaperAddress,:IndexedAddress,:Abstract,:Graduates"
		",:UploadTime,:AuditStatus,:Auditor,:AuditTime,:DownloadCount)");
	sQuery.bindValue(":Name", ResearchProject.Name);
	sQuery.bindValue(":StartTime", ResearchProject.StartTime.toString("yyyy-MM-dd hh:mm:ss"));
	sQuery.bindValue(":EndTime", ResearchProject.EndTime.toString("yyyy-MM-dd hh:mm:ss"));
	sQuery.bindValue(":Type", ResearchProject.Type);
	sQuery.bindValue(":Number", ResearchProject.Number);
	sQuery.bindValue(":Funds", ResearchProject.Funds);
	sQuery.bindValue(":Participants", ResearchProject.Participants);
	sQuery.bindValue(":ServerDataAddress", ResearchProject.ServerDataAddress);
	sQuery.bindValue(":ServerPaperAddress", ResearchProject.ServerPaperAddress);
	sQuery.bindValue(":IndexedAddress", ResearchProject.IndexedAddress);
	sQuery.bindValue(":Abstract", ResearchProject.Abstract);
	sQuery.bindValue(":Graduates", ResearchProject.Graduates);
	sQuery.bindValue(":UploadTime", ResearchProject.UploadTime.toString("yyyy-MM-dd hh:mm:ss"));
	sQuery.bindValue(":AuditStatus", ResearchProject.AuditStatus);
	sQuery.bindValue(":Auditor", ResearchProject.Auditor);
	sQuery.bindValue(":AuditTime", ResearchProject.AuditTime.toString("yyyy-MM-dd hh:mm:ss"));
	sQuery.bindValue(":DownloadCount", QString::number(ResearchProject.DownloadCount));

	if (sQuery.exec())
	{
		return true;
	}
	return false;
}
bool UrielDatabase::updateResearchProject(sUrielResearchProjectItem ResearchProject) {
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("UPDATE ilabmanagementsystem.researchproject SET Name=?,StartTime=?,EndTime=?,Type=?,Number=?,Funds=?"
		",Participants=?,ServerDataAddress=?,ServerPaperAddress=?,IndexedAddress=?,Abstract=?,Graduates=?,UploadTime=?,"
		"AuditStatus=?,Auditor=?,AuditTime=?,DownloadCount=? WHERE ID = '" + QString::number(ResearchProject.ID) + "'");
	sQuery.bindValue(0, ResearchProject.Name);
	sQuery.bindValue(1, ResearchProject.StartTime.toString("yyyy-MM-dd hh:mm:ss"));
	sQuery.bindValue(2, ResearchProject.EndTime.toString("yyyy-MM-dd hh:mm:ss"));
	sQuery.bindValue(3, ResearchProject.Type);
	sQuery.bindValue(4, ResearchProject.Number);
	sQuery.bindValue(5, ResearchProject.Funds);
	sQuery.bindValue(6, ResearchProject.Participants);
	sQuery.bindValue(7, ResearchProject.ServerDataAddress);
	sQuery.bindValue(8, ResearchProject.ServerPaperAddress);
	sQuery.bindValue(9, ResearchProject.IndexedAddress);
	sQuery.bindValue(10, ResearchProject.Abstract);
	sQuery.bindValue(11, ResearchProject.Graduates);
	sQuery.bindValue(12, ResearchProject.UploadTime.toString("yyyy-MM-dd hh:mm:ss"));
	sQuery.bindValue(13, ResearchProject.AuditStatus);
	sQuery.bindValue(14, ResearchProject.Auditor);
	sQuery.bindValue(15, ResearchProject.AuditTime.toString("yyyy-MM-dd hh:mm:ss"));
	sQuery.bindValue(16, QString::number(ResearchProject.DownloadCount));

	if (sQuery.exec())
	{
		return true;
	}
	return false;
}
bool UrielDatabase::getResearchProjectInfoByID(sUrielResearchProjectItem& item, const QString & id) {
	QString strSQL = "select ID,Name,StartTime,EndTime,Type,Number,Funds"
		",Participants,ServerDataAddress,ServerPaperAddress,IndexedAddress,Abstract,Graduates,UploadTime,"
		"AuditStatus,Auditor,AuditTime,DownloadCount FROM ilabmanagementsystem.researchproject WHERE ID  = '" + id + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		item.ID = mQuery.value(0).toInt();
		item.Name = mQuery.value(1).toString();
		item.StartTime = mQuery.value(2).toDateTime();
		item.EndTime = mQuery.value(3).toDateTime();
		item.Type = mQuery.value(4).toString();
		item.Number = mQuery.value(5).toString();
		item.Funds = mQuery.value(6).toString();
		item.Participants = mQuery.value(7).toString();
		item.ServerDataAddress = mQuery.value(8).toString();
		item.ServerPaperAddress = mQuery.value(9).toString();
		item.IndexedAddress = mQuery.value(10).toString();
		item.Abstract = mQuery.value(11).toString();
		item.Graduates = mQuery.value(12).toString();
		item.UploadTime = mQuery.value(13).toDateTime();
		item.AuditStatus = mQuery.value(14).toString();
		item.Auditor = mQuery.value(15).toString();
		item.AuditTime = mQuery.value(16).toDateTime();
		item.DownloadCount = mQuery.value(17).toInt();
		return true;
	}
	//std::string error = mQuery.lastError().text().toStdString();
	return false;
}
bool UrielDatabase::deleteResearchProject(const QString & id) {
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("DELETE FROM researchproject WHERE ID ='" + id + "'");
	if (sQuery.exec())
		return true;
	return false;
}
bool UrielDatabase::updateResearchProjectDownloadCount(const QString & id) {
	QString strSQL = "UPDATE researchproject SET DownLoadCount=DownLoadCount+1 WHERE ID = '" + id + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		return true;
	}
	return false;
}


QString UrielDatabase::encode(const QString &str) {
	QString strSQL = "SELECT ENCODE('"+ str+"','UrielAbcDefGhiWuJingxyZw')";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	QString result = "";
	while (mQuery.next())
	{
		QByteArray barray = mQuery.value(0).toByteArray();
		result = barray;
		return result;
	}
	return result;
}
QString UrielDatabase::decode(const QString &str) {
	QString strSQL = "SELECT DECODE('" + str + "','UrielAbcDefGhiWuJingxyZw')";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	QString result = "";
	while (mQuery.next())
	{
		QByteArray barray = mQuery.value(0).toByteArray();
		result = barray;
		return result;
	}
	return result;
}

bool UrielDatabase::getSystemSettings(sUrielSystemSettingsItem & item) {
	QString strSQL = "select ID,SystemEMail,SystemEMailPassword,SystemEmailName,SystemEmailSendServer,SystemEmailSendServerPort,SystemEmailProtocol,SystemVersion"
		" FROM ilabmanagementsystem.systemsettings";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		item.ID = mQuery.value(0).toInt();
		item.SystemEMail = mQuery.value(1).toString();
		item.SystemEMailPassword = mQuery.value(2).toString();
		item.SystemEmailName = mQuery.value(3).toString();
		item.SystemEmailSendServer = mQuery.value(4).toString();
		item.SystemEmailSendServerPort = mQuery.value(5).toString();
		item.SystemEmailProtocol = mQuery.value(6).toString();
		item.SystemVersion = mQuery.value(7).toString();
		return true;
	}
	//std::string error = mQuery.lastError().text().toStdString();
	return false;
}

bool UrielDatabase::updateSystemEMailSettings(sUrielSystemSettingsItem & item) {
	QSqlQuery sQuery(m_Database);
	QSqlError er;
	sQuery.prepare("UPDATE systemsettings SET SystemEMail=?,"
	"SystemEMailPassword=?,SystemEmailName=?,SystemEmailSendServer=?,SystemEmailSendServerPort=?,"
	"SystemEmailProtocol=? WHERE ID='" + QString::number(item.ID) + "'");
	sQuery.bindValue(0, item.SystemEMail);
	sQuery.bindValue(1, item.SystemEMailPassword);
	sQuery.bindValue(2, item.SystemEmailName);
	sQuery.bindValue(3, item.SystemEmailSendServer);
	sQuery.bindValue(4, item.SystemEmailSendServerPort);
	sQuery.bindValue(5, item.SystemEmailProtocol);

	if (sQuery.exec())
	{
		return true;
	}
	//QString ss = sQuery.lastError().text();
	return false;
}

UrielUserCountTableModel* UrielDatabase::creatUltimateAuditTableModel() {
	if (m_UrielUltimateAuditTableModel != nullptr)
		return m_UrielUltimateAuditTableModel;
	m_szUltimateAuditBrowserQuery = "select ID,NAME,SCHOOL_WORK_NUMBER,EMAIL,PHONE_NUMBER,BANK_TYPE,BANK_CARD_NUMBER,PROJECT_TEAM,PERMISSION,APPLY_TIME "
		"from account_number where AUDITLEVEL = 'UltimateAudit'";
	QStringList list;
	list << QStringLiteral("ID") << QStringLiteral("姓名") << QStringLiteral("学(工)号") << QStringLiteral("邮箱") << QStringLiteral("电话号码") << QStringLiteral("银行")\
		<< QStringLiteral("银行卡号") << QStringLiteral("项目") << QStringLiteral("权限") << QStringLiteral("申请时间");
	m_szUltimateAuditPreviousQuery = m_szUltimateAuditBrowserQuery + " order by APPLY_TIME asc";
	m_UrielUltimateAuditTableModel = new UrielUserCountTableModel(m_szUltimateAuditPreviousQuery, list, m_Database);
	return m_UrielUltimateAuditTableModel;
}
bool UrielDatabase::updateUltimateTableModel(QString  strSQL) {
	if (strSQL.isEmpty())
	{
		if (m_UrielUltimateAuditTableModel)
		{
			m_UrielUltimateAuditTableModel->setQuery(m_szUltimateAuditPreviousQuery);
		}
		return true;
	}
	QString previous_query_current = m_szUltimateAuditBrowserQuery + strSQL + " order by NAME asc";

	if (m_UrielUltimateAuditTableModel)
	{
		m_UrielUltimateAuditTableModel->setQuery(previous_query_current);
	}
	return true;
}

UrielUserCountTableModel* UrielDatabase::creatRoutineAuditTableModel() {
	if (m_UrielRoutineAuditTableModel != nullptr)
		return m_UrielRoutineAuditTableModel;
	m_szRoutineAuditBrowserQuery = "select ID,NAME,SCHOOL_WORK_NUMBER,EMAIL,PHONE_NUMBER,BANK_TYPE,BANK_CARD_NUMBER,PROJECT_TEAM,PERMISSION,APPLY_TIME "
		"from account_number where AUDITLEVEL = 'RoutineAudit'";
	QStringList list;
	list << QStringLiteral("ID") << QStringLiteral("姓名") << QStringLiteral("学(工)号") << QStringLiteral("邮箱") << QStringLiteral("电话号码") << QStringLiteral("银行")\
		<< QStringLiteral("银行卡号") << QStringLiteral("项目") << QStringLiteral("权限") << QStringLiteral("申请时间");
	m_szRoutineAuditPreviousQuery = m_szRoutineAuditBrowserQuery + " order by APPLY_TIME asc";
	m_UrielRoutineAuditTableModel = new UrielUserCountTableModel(m_szRoutineAuditPreviousQuery, list, m_Database);
	return m_UrielRoutineAuditTableModel;
}
bool UrielDatabase::updateRoutineTableModel(QString  strSQL) {
	if (strSQL.isEmpty())
	{
		if (m_UrielRoutineAuditTableModel)
		{
			m_UrielRoutineAuditTableModel->setQuery(m_szRoutineAuditPreviousQuery);
		}
		return true;
	}
	QString previous_query_current = m_szRoutineAuditBrowserQuery + strSQL + " order by NAME asc";

	if (m_UrielRoutineAuditTableModel)
	{
		m_UrielRoutineAuditTableModel->setQuery(previous_query_current);
	}
	return true;
}


bool UrielDatabase::resetAuditlevel(const QString & id) {
	QString strSQL = "UPDATE account_number SET AUDITLEVEL='None' WHERE ID = '" + id + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		return true;
	}
	return false;
}

bool UrielDatabase::setAuditlevel(const QString & name, const QString & level) {
	QString strSQL = "UPDATE account_number SET AUDITLEVEL='"+ level+"' WHERE NAME = '" + name + "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		return true;
	}
	return false;
}

bool UrielDatabase::getAllAuditor(QStringList & email, QStringList & name, const QString & level) {
	QString strSQL = "SELECT EMAIL,NAME FROM ilabmanagementsystem.account_number where AUDITLEVEL = '"+ level+ "'";
	QSqlQuery mQuery(m_Database);
	mQuery.exec(strSQL);
	while (mQuery.next())
	{
		email << (mQuery.value(0).toString());
		name << (mQuery.value(1).toString());
	}
	return true;
}