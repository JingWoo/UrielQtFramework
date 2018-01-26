#ifndef __URIEL_QT_FRAMEWORK_H__
#define __URIEL_QT_FRAMEWORK_H__
#include <atomic>
#include <mutex>
#include <QSettings>
#include <QImage>
#include "UrielDefinition/UrielDefinition.h"
#include "UrielDeEncryptionKit\UrielDeEncryptionKit.h"
class UrielQtFrameworkOptions
{

public:
	// Constructor.
	UrielQtFrameworkOptions();
	// Default destructor.
	~UrielQtFrameworkOptions();

	// The settings object accessor.
	QSettings& settings() { return m_settings; };

	// Explicit I/O methods.
	void loadOptions();
	void saveOptions();

	// Command line arguments parser.
	bool parse_args(const QStringList& args);
	// Command line usage helper.
	void print_usage(const QString& arg0);

	// Singleton instance accessor.
	static UrielQtFrameworkOptions *getInstance();

	// The singleton instance.
	static UrielQtFrameworkOptions* g_pOptions;

	//reading system locale
	QString sSystemLocal;

	// Display options...
	int     iBaseFontSize;

	// Custom display options.
	QString sCustomColorTheme;
	QString sCustomStyleTheme;

	QString sVersion;
	//Database Item option
	sUrielDBItem stUrielDBItem;

	bool g_bAppAutoStart;

	sUrielFTPItem stUrielFTPItem;
	//defalut files download path
	QString sDefalutFilesDownloadPath;
	//login account info
	void setAccount(const QString & account) { sAccount = account; }
	void setPassword(const QString & password) { sPassword = password; }
	void setRememberPassword(bool v) { bRememberPassword = v; }
	void setAutoLogin(bool v) { bAutoLogin = v; }
	void setHeadIcoPath(const QString & img) { imgHeadIcoPath = img; }
	void setDefaultNetworkConfiguration(const QString & id) { sDefaultNetworkConfiguration = id; }
	void setFTPConfigParameter(const sUrielFTPItem &);
	void setDefalutFilesDownloadPath(const QString & path) { sDefalutFilesDownloadPath = path; }
	void setDatabaseConfigParameter(const sUrielDBItem & item) { stUrielDBItem = item; }

	const QString & getAccount() const { return sAccount; }
	const QString & getPassword()const { return sPassword; }
	bool getRememberPassword()const { return bRememberPassword; }
	bool getAutoLogin()const { return bAutoLogin; }
	const QString &  getHeadIcoPath()const { return imgHeadIcoPath; }
	const QString & getDefaultNetworkConfiguration() const { return sDefaultNetworkConfiguration; }
	const sUrielFTPItem & getFTPConfigParameter() const { return stUrielFTPItem; }
	const QString & getDefalutFilesDownloadPath()const { return sDefalutFilesDownloadPath; }
	void getIpAndLocation(QString & address);

	QString getlocalHost();
	QString getHostUserName();
	QString getIP(QString localHost);
	void slotDetail();
	QString gethostMac();
	QString DigitalChineseUppercase(const double &Fnumber);

	void setSystemEmailAccount(const QString & str) { sSystemEmailAccount = str; }
	QString getSystemEmailAccount() { return sSystemEmailAccount; }

	void setSystemEmailPassword(const QString & str) { sSystemEmailPassword = str; }
	QString getSystemEmailPassword() { return sSystemEmailPassword; }

	void setSystemEmailName(const QString & str) { sSystemEmailName = str; }
	QString getSystemEmailName() { return sSystemEmailName; }

	void setSystemEmailSendServer(const QString & str) { sSystemEmailSendServer = str; }
	QString getSystemEmailSendServer() { return sSystemEmailSendServer; }

	void setSystemEmailSendServerPort(int n) { nSystemEmailSendServerPort = n; }
	int getSystemEmailSendServerPort() { return nSystemEmailSendServerPort; }

	void setSystemEmailUseSSL(bool b) { bSystemEmailUseSSL = b; }
	bool getSystemEmailUseSSL() { return bSystemEmailUseSSL; }

private:

	// Settings member variables.
	QSettings m_settings;

	//login account info
	QString sAccount;
	QString sPassword;
	bool bRememberPassword;
	bool bAutoLogin;
	QString imgHeadIcoPath;

	//FTP Info
	QString sDefaultNetworkConfiguration;

	QString sSystemEmailAccount;
	QString sSystemEmailName;
	QString sSystemEmailPassword;
	QString sSystemEmailSendServer;
	int nSystemEmailSendServerPort;
	bool bSystemEmailUseSSL;
	
};

#endif