#include "UrielQtFrameworkOptions.h"
#include <QCoreApplication>
#include <QLocale>
#include <QBuffer>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QHostAddress>  
#include <QHostInfo>  
#include <QNetworkInterface>  
#include <QProcess>  
#include <QDebug>

// Singleton instance pointer.
//std::atomic<UrielQtFrameworkOptions*> UrielQtFrameworkOptions::g_pOptions;
//std::mutex UrielQtFrameworkOptions::m_mutex;

// Singleton instance pointer.
UrielQtFrameworkOptions *UrielQtFrameworkOptions::g_pOptions = nullptr;

// Singleton instance accessor (static).
UrielQtFrameworkOptions *UrielQtFrameworkOptions::getInstance(void)
{
	return g_pOptions;
	//UrielQtFrameworkOptions* tmp = g_pOptions.load(std::memory_order_relaxed);
	//std::atomic_thread_fence(std::memory_order_acquire);//获取内存fence
	//if (tmp == nullptr) {
	//	std::lock_guard<std::mutex> lock(m_mutex);
	//	tmp = g_pOptions.load(std::memory_order_relaxed);
	//	if (tmp == nullptr) {
	//		tmp = new UrielQtFrameworkOptions;
	//		std::atomic_thread_fence(std::memory_order_release);//释放内存fence
	//		g_pOptions.store(tmp, std::memory_order_relaxed);
	//	}
	//}
	//return tmp;
	
}

UrielQtFrameworkOptions::UrielQtFrameworkOptions(void)
	:m_settings(QCoreApplication::applicationDirPath() + "/setting.ini", QSettings::IniFormat)
{
	m_settings.setIniCodec("UTF-8");
	//UrielDeEncryptionKit * pDeEncryptionKit= UrielDeEncryptionKit::getInstance();
	//QString paramSource = "WuJing3.1415926";
	//QString paramDest;
	//pDeEncryptionKit->getEncryByAES(paramSource, paramDest);
	//m_settings.beginGroup("/Options");
	//m_settings.beginGroup(QLatin1String("/SystemE-Mail"));
	//m_settings.setValue(QLatin1String("/SystemEmailPassword"), paramDest);
	//m_settings.endGroup();
	//// Preferences
	//m_settings.endGroup();
	//m_settings.sync();

	// And go into general options group.
	//m_settings.beginGroup("/Options");
	//m_settings.beginGroup("/DataBaseConnection");
	//QString xxx = m_settings.value(QLatin1String("/Password"), "").toString();
	//m_settings.endGroup();
	//// Preferences
	//m_settings.endGroup();

	//QString paramde;
	//pDeEncryptionKit->decryptByAES(xxx, paramde);
	//qDebug() << paramde;
	// Pseudo-singleton reference setup.
	g_pOptions = this;
	loadOptions();
}

UrielQtFrameworkOptions::~UrielQtFrameworkOptions(void)
{
	saveOptions();
	// Pseudo-singleton reference shut-down.
	g_pOptions = NULL;
}

// Explicit load method.
void UrielQtFrameworkOptions::loadOptions(void)
{
	
	// And go into general options group.
	m_settings.beginGroup("/Options");

	//Application language options
	m_settings.beginGroup("/language");
	sSystemLocal=m_settings.value("/language", QLocale::system().name()).toString();
	m_settings.endGroup();

	//Application Database(MySQL) connect item
	m_settings.beginGroup("/DataBaseConnection");
	stUrielDBItem.m_bLinking = m_settings.value("/Linking", true).toBool();  //connect mothod
	stUrielDBItem.m_strDBType = m_settings.value("/Type", "MySQL").toString(); 
	stUrielDBItem.m_strSchema = m_settings.value("/Schema", "ilabmanagementsystem").toString();
	stUrielDBItem.m_strUser = m_settings.value("/User", "root").toString();
	stUrielDBItem.m_strPwd = m_settings.value("/Password", "ZJU9506").toString();
	stUrielDBItem.m_strVersion = m_settings.value("/Version", "5.7").toString();
	stUrielDBItem.m_iTimeOut = m_settings.value("/TimeOut", 5).toInt();
	stUrielDBItem.m_strHost = m_settings.value("/Host", "HostLocal").toString();
	stUrielDBItem.m_iPort = m_settings.value("/Port", 3306).toInt();
	m_settings.endGroup();

	// Save display options.
	m_settings.beginGroup("/Display");
	iBaseFontSize=m_settings.value("/BaseFontSize", 16).toInt();
	m_settings.endGroup();

	//Application custom theme options
	m_settings.beginGroup("/Custom");
	sCustomColorTheme=m_settings.value("/ColorTheme").toString();
	sCustomStyleTheme=m_settings.value("/StyleTheme").toString();
	m_settings.endGroup();


	//login account info
	m_settings.beginGroup("/Login");
	sAccount = m_settings.value("/Account", "").toString();
	sPassword = m_settings.value("/Password", "123456").toString();
	bRememberPassword = m_settings.value("/RememberPassword", false).toBool();
	bAutoLogin = m_settings.value("/AutoLogin", false).toBool();
	imgHeadIcoPath = m_settings.value("/HeadIco", ":/Login/Resources/Login/HeadIco.png").toString();
	m_settings.endGroup();

	m_settings.beginGroup(QLatin1String("/QtNetwork"));
	sDefaultNetworkConfiguration = m_settings.value(QLatin1String("/DefaultNetworkConfiguration")).toString();
	m_settings.endGroup();

	m_settings.beginGroup(QLatin1String("/FTP"));
	stUrielFTPItem.m_sHostIp = m_settings.value(QLatin1String("/HostIp"),"127.0.0.1").toString();
	stUrielFTPItem.m_iPort = m_settings.value(QLatin1String("/Port"), 21).toInt();
	stUrielFTPItem.m_sUserName = m_settings.value(QLatin1Literal("/UserName"), "root").toString();
	stUrielFTPItem.m_sPassword = m_settings.value(QLatin1Literal("/Password"), "123456").toString();
	stUrielFTPItem.m_sProfile = m_settings.value(QLatin1Literal("/Profile"), "Public").toString();
	m_settings.endGroup();

	m_settings.beginGroup(QLatin1String("/Files"));
	sDefalutFilesDownloadPath = m_settings.value(QLatin1String("/DefalutFilesDownloadPath"),"D:/").toString();
	m_settings.endGroup();

	m_settings.beginGroup(QLatin1String("/SystemE-Mail"));
	sSystemEmailAccount = m_settings.value(QLatin1String("/SystemEmailAccount"), "").toString();
	sSystemEmailName = m_settings.value(QLatin1String("/SystemEmailName"), QStringLiteral("浙江大学精密微纳测量实验室管理系统")).toString();
	sSystemEmailPassword = m_settings.value(QLatin1String("/SystemEmailPassword"), "").toString();
	sSystemEmailSendServer = m_settings.value(QLatin1String("/SystemEmailSendServer"), "smtp.zju.edu.cn").toString();
	nSystemEmailSendServerPort = m_settings.value(QLatin1String("/SystemEmailSendServerPort"), 994).toInt();
	bSystemEmailUseSSL = m_settings.value(QLatin1String("/SystemEmailUseSSL"), true).toBool();
	m_settings.endGroup();

	m_settings.beginGroup(QLatin1String("/Application"));
	g_bAppAutoStart=m_settings.value(QLatin1String("/AppAutoStart"), false).toBool();
	sVersion = m_settings.value(QLatin1String("/Version"),  "1.0.1").toString();
	m_settings.endGroup();

	// Options group end. 
	m_settings.endGroup();

	//Decryption Password
	UrielDeEncryptionKit * pDeEncryptionKit = UrielDeEncryptionKit::getInstance();
	QString Decryption;
	pDeEncryptionKit->decryptByAES(stUrielDBItem.m_strPwd, Decryption);
	stUrielDBItem.m_strPwd = Decryption;
	pDeEncryptionKit->decryptByAES(sPassword, Decryption);
	sPassword= Decryption;
	pDeEncryptionKit->decryptByAES(stUrielFTPItem.m_sPassword, Decryption);
	stUrielFTPItem.m_sPassword = Decryption;
	pDeEncryptionKit->decryptByAES(sSystemEmailPassword, Decryption);
	sSystemEmailPassword = Decryption;
}

// Explicit save method.
void UrielQtFrameworkOptions::saveOptions(void)
{
	UrielDeEncryptionKit * pDeEncryptionKit = UrielDeEncryptionKit::getInstance();
	QString Encryption;
	pDeEncryptionKit->getEncryByAES(stUrielDBItem.m_strPwd, Encryption);
	stUrielDBItem.m_strPwd = Encryption;
	pDeEncryptionKit->getEncryByAES(sPassword, Encryption);
	sPassword = Encryption;
	pDeEncryptionKit->getEncryByAES(stUrielFTPItem.m_sPassword, Encryption);
	stUrielFTPItem.m_sPassword = Encryption;
	pDeEncryptionKit->getEncryByAES(sSystemEmailPassword, Encryption);
	sSystemEmailPassword = Encryption;

	// And go into general options group.
	m_settings.beginGroup("/Options");

	//Application language options
	m_settings.beginGroup("/language");
	m_settings.setValue("/language", sSystemLocal);
	m_settings.endGroup();

	//Application Database(MySQL) connect item
	m_settings.beginGroup("/DataBaseConnection");
	m_settings.setValue("/Linking", stUrielDBItem.m_bLinking);  //connect mothod
	m_settings.setValue("/Type",  stUrielDBItem.m_strDBType);
	m_settings.setValue("/Schema", stUrielDBItem.m_strSchema);
	m_settings.setValue("/User", stUrielDBItem.m_strUser);
	m_settings.setValue("/Password", stUrielDBItem.m_strPwd);
	m_settings.setValue("/Version", stUrielDBItem.m_strVersion);
	m_settings.setValue("/TimeOut", stUrielDBItem.m_iTimeOut);
	m_settings.setValue("/Host", stUrielDBItem.m_strHost);
	m_settings.setValue("/Port", stUrielDBItem.m_iPort);
	m_settings.endGroup();

	// Save display options.
	m_settings.beginGroup("/Display");
	m_settings.setValue("/BaseFontSize", iBaseFontSize);
	m_settings.endGroup();

	//Application custom theme options
	m_settings.beginGroup("/Custom");
	m_settings.setValue("/ColorTheme", sCustomColorTheme);
	m_settings.setValue("/StyleTheme", sCustomStyleTheme);
	m_settings.endGroup();


	//login account info
	m_settings.beginGroup("/Login");
	m_settings.setValue("/Account", sAccount);
	m_settings.setValue("/Password", sPassword);
	m_settings.setValue("/RememberPassword", bRememberPassword);
	m_settings.setValue("/AutoLogin",bAutoLogin);
	m_settings.setValue("/HeadIco", imgHeadIcoPath);
	m_settings.endGroup();

	m_settings.beginGroup(QLatin1String("/QtNetwork"));
	m_settings.setValue(QLatin1String("/DefaultNetworkConfiguration"), sDefaultNetworkConfiguration);
	m_settings.endGroup();

	m_settings.beginGroup(QLatin1String("/FTP"));
	m_settings.setValue(QLatin1String("/HostIp"), stUrielFTPItem.m_sHostIp);
	m_settings.setValue(QLatin1String("/Port"), stUrielFTPItem.m_iPort);
	m_settings.setValue(QLatin1Literal("/UserName"), stUrielFTPItem.m_sUserName);
	m_settings.setValue(QLatin1Literal("/Password"), stUrielFTPItem.m_sPassword);
	m_settings.setValue(QLatin1Literal("/Profile"), stUrielFTPItem.m_sProfile);
	m_settings.endGroup();

	m_settings.beginGroup(QLatin1String("/Files"));
	m_settings.setValue(QLatin1String("/DefalutFilesDownloadPath"), sDefalutFilesDownloadPath);
	m_settings.endGroup();
	//
	m_settings.beginGroup(QLatin1String("/SystemE-Mail"));
	m_settings.setValue(QLatin1String("/SystemEmailAccount"), sSystemEmailAccount);
	m_settings.setValue(QLatin1String("/SystemEmailName"), sSystemEmailName);
	m_settings.setValue(QLatin1String("/SystemEmailPassword"), sSystemEmailPassword);
	m_settings.setValue(QLatin1String("/SystemEmailSendServer"), sSystemEmailSendServer);
	m_settings.setValue(QLatin1String("/SystemEmailSendServerPort"), nSystemEmailSendServerPort);
	m_settings.setValue(QLatin1String("/SystemEmailUseSSL"), bSystemEmailUseSSL);
	m_settings.endGroup();

	m_settings.beginGroup(QLatin1String("/Application"));
	m_settings.setValue(QLatin1String("/AppAutoStart"), g_bAppAutoStart);
	m_settings.setValue(QLatin1String("/Version"), sVersion);
	m_settings.endGroup();
	// Preferences
	m_settings.endGroup();

	m_settings.sync();
}

void UrielQtFrameworkOptions::getIpAndLocation(QString & address) {
	////上面ip38网站有时会失效，失效时可以使用：http://iframe.ip138.com/ic.asp
	//QEventLoop loop;

	//QNetworkAccessManager manager;//
	//QNetworkReply *pReply = manager.get(QNetworkRequest(QUrl("http://www.ip38.com/")));   // http://www.ip38.com/index.php?ip=180.106.128.94
	//QObject::connect(pReply, SIGNAL(finished()), &loop, SLOT(quit()));
	//loop.exec();
	//QByteArray byte = pReply->readAll();
	//QString strTemp;

	//strTemp = strTemp.fromLocal8Bit(byte.data());
	//int nStartIndex = strTemp.indexOf("<div id=\"ipadcode\" style=\"display:none\">");
	//if (nStartIndex >= 0)
	//{
	//	nStartIndex += strlen("<div id=\"ipadcode\" style=\"display:none\">");
	//	int nEndIndex = strTemp.indexOf("</div>", nStartIndex);
	//	if (nEndIndex > nStartIndex)
	//	{
	//		address = strTemp.mid(nStartIndex + 1, nEndIndex - nStartIndex - 1);
	//	}
	//}
	//else
	//	address = "";

}

QString UrielQtFrameworkOptions::getlocalHost() {
	QString localHost = QHostInfo::localHostName();
	return localHost;
}


//获取用户名  
QString UrielQtFrameworkOptions::getHostUserName()
{
#if 1  
	QStringList envVariables;
	envVariables << "USERNAME.*" << "USER.*" << "USERDOMAIN.*"
		<< "HOSTNAME.*" << "DOMAINNAME.*";
	QStringList environment = QProcess::systemEnvironment();
	foreach(QString string, envVariables) {
		int index = environment.indexOf(QRegExp(string));
		if (index != -1) {
			QStringList stringList = environment.at(index).split('=');
			if (stringList.size() == 2) {
				return stringList.at(1);
				break;
			}
		}
	}
	return "unknown";
#else  
	QString userName = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
	userName = userName.section("/", -1, -1);
	return userName;
#endif  
}

//获取本机IP  
QString UrielQtFrameworkOptions::getIP(QString localHost)
{
	QString ipAddr;
#if 0  
	QList<QHostAddress> AddressList = QNetworkInterface::allAddresses();
	foreach(QHostAddress address, AddressList) {
		if (address.protocol() == QAbstractSocket::IPv4Protocol &&
			address != QHostAddress::Null &&
			address != QHostAddress::LocalHost) {
			if (address.toString().contains("127.0.")) {
				continue;
			}
			ipAddr = address.toString();
			break;
		}
	}
#else  
	QHostInfo info = QHostInfo::fromName(localHost);
	info.addresses();//QHostInfo的address函数获取本机ip地址  
					 //如果存在多条ip地址ipv4和ipv6：  
	foreach(QHostAddress address, info.addresses())
	{
		if (address.protocol() == QAbstractSocket::IPv4Protocol) {//只取ipv4协议的地址  
			qDebug() << address.toString();
			ipAddr = address.toString();
		}
	}
#endif  
	return ipAddr;
}
//#include <QMessageBox>
//获取计算机详细信息  
void UrielQtFrameworkOptions::slotDetail()
{
	QString detail = "";
	QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();
	for (int i = 0; i<list.count(); i++)
	{
		QNetworkInterface interface = list.at(i);
		detail = detail + QStringLiteral("设备：") + interface.name() + "\n";
		detail = detail + QStringLiteral("硬件地址：") + interface.hardwareAddress() + "\n";
		QList<QNetworkAddressEntry> entryList = interface.addressEntries();
		for (int j = 0; j<entryList.count(); j++)
		{
			QNetworkAddressEntry entry = entryList.at(j);
			detail = detail + "\t" + QStringLiteral("IP 地址：") + entry.ip().toString() + "\n";
			detail = detail + "\t" + QStringLiteral("子网掩码：") + entry.netmask().toString() + "\n";
			detail = detail + "\t" + QStringLiteral("广播地址：") + entry.broadcast().toString() + "\n";
		}
	}
	//QMessageBox::about(nullptr, QStringLiteral("Detail"), detail);
}



QString UrielQtFrameworkOptions::gethostMac()
{
	QList<QNetworkInterface> nets = QNetworkInterface::allInterfaces();// 获取所有网络接口列表
	int nCnt = nets.count();
	QString strMacAddr = "";
	for (int i = 0; i < nCnt; i++)
	{
		// 如果此网络接口被激活并且正在运行并且不是回环地址，则就是我们需要找的Mac地址
		if (nets[i].flags().testFlag(QNetworkInterface::IsUp) && nets[i].flags().testFlag(QNetworkInterface::IsRunning)
			&& !nets[i].flags().testFlag(QNetworkInterface::IsLoopBack))
		{
			strMacAddr = nets[i].hardwareAddress();
			break;
		}
	}
	return strMacAddr;
}


QString UrielQtFrameworkOptions::DigitalChineseUppercase(const double &value) {
	int intergePart = static_cast<int>(value);
	if (value < 0.001)
		return QStringLiteral("人民币零元整");
	const QStringList sUnit = { QStringLiteral("元"),QStringLiteral("拾"),QStringLiteral("佰"),
		QStringLiteral("仟"),QStringLiteral("万"),QStringLiteral("拾"),QStringLiteral("佰"),QStringLiteral("仟"),
		QStringLiteral("亿"),QStringLiteral("拾"),QStringLiteral("佰"),QStringLiteral("仟"),QStringLiteral("万")};
	const QStringList sData = { QStringLiteral("零"),QStringLiteral("壹"),QStringLiteral("贰"),QStringLiteral("叁"),
		QStringLiteral("肆"),QStringLiteral("伍"),QStringLiteral("陆"),QStringLiteral("柒"),QStringLiteral("捌"),QStringLiteral("玖") };
	const QStringList sDecimalUnit = { QStringLiteral("角"),QStringLiteral("分"),QStringLiteral("厘") };
	QString  result = QStringLiteral("人民币");

	QString sIntergePart = QString::number(intergePart);
	int len = sIntergePart.size();
	QString szHead;
	const QChar zero = '0';
	if (len == 1)
		result += sData[sIntergePart.at(sIntergePart.size() - len).unicode() - '0'] + sUnit[len - 1];
	else {
		while (len) {
			
			if (sIntergePart[sIntergePart.size() - len] == "0"&&len%4 == 1)
				result += sUnit[len - 1];
			else if (sIntergePart[sIntergePart.size() - len] == "0"&&szHead == "0"&&(len+1) % 4 != 1) {
				len--;
				continue;
			}
			else if (sIntergePart[sIntergePart.size() - len] == "0"&&szHead != "0"|| 
				(sIntergePart[sIntergePart.size() - len] == "0"&&szHead == "0"&&(len + 1) % 4 == 1))
				result += sData[sIntergePart.at(sIntergePart.size() - len).unicode() - '0'];
			else
				result += sData[sIntergePart.at(sIntergePart.size() - len).unicode() - '0'] + sUnit[len - 1];

			bool bUriel = true;
			int k = len - 1;
			if (k != 0) {
				while (k) {
					if (sIntergePart[sIntergePart.size() - k] != "0")
						bUriel = false;
					--k;
				}
				if (bUriel) {
					result += sUnit[0];
					break;
				}
			}
			szHead = sIntergePart[sIntergePart.size() - len];
			len--;
		}
	}

	QString sDecimalPart;
	QStringList nlist=QString::number(value).trimmed().split(".");
	
	if (nlist.size() > 1) {
		if(sIntergePart.size()==1&& sIntergePart.at(0)=="0")
			result = QStringLiteral("人民币");
		sDecimalPart = nlist[1];
		len = sDecimalPart.size();
		while (len) {
			if (sDecimalPart.size() - len > 2)
				break;
			if (sDecimalPart[sDecimalPart.size() - len] == "0") {
				len--;
				continue;
			}
			else
				result += sData[sDecimalPart.at(sDecimalPart.size() - len).unicode() - '0'] + sDecimalUnit[sDecimalPart.size() - len];
			len--;
		}
	}
	else
		result += QStringLiteral("整");
	return result;
}