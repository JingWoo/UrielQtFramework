/*
Name: UrielQtFramework
Version: 0.0.1
Web-site: https://UrielProgram.net
Programmer: Uriel WuJing
E-mail: jing.Woo@outlook.com
Web-site: https://UrielProgram.net

Copyright 2012-2017 Uriel WuJing

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include "UrielQtFramework.h"
#include <QtWidgets/QApplication>
#include <QtSingleApplication>
#include <QTextCodec>
#include <QTranslator>
#include <QLocale>
#include <QSettings>

#include "UrielQtFrameworkOptions/UrielQtFrameworkOptions.h"
#include "glog\logging.h"
#include "UrielDataStructure\UserInfo\UserInfo.h"
#include "UrielDatabase\UrielDatabase.h"
#include "UrielDefinition\UrielDefinition.h"
#include "Login.h"
#include "UrielFileTransfer\FTP\UrielFTP.h"
#include "UrielFileTransfer\NetworkAccessManager\UrielNetworkAccessManager.h"

static bool update_palette(QPalette& pal, const QString& sCustomColorTheme);

//! [register meta-type for communications]
void registerMetaType();

int main(int argc, char *argv[])
{
	QtSingleApplication instance(QLatin1String("UrielQtFramework"),argc, argv);
	if (instance.isRunning())
	{
		if (instance.sendMessage(QObject::tr("The application has already run !")))
			return EXIT_SUCCESS;
	}

	//QApplication instance(argc, argv);

	//Register Custom MetaType for Siganls and Slots
	registerMetaType();

	instance.setApplicationName(QStringLiteral("浙江大学精密微纳实验室管理系统"));
	instance.setOrganizationName(QObject::tr("Zhejiang University Uriel WuJing"));
	instance.setOrganizationDomain("https://UrielProgram.net/projects/UrielQtFramework/"); 
	instance.setApplicationVersion("1.0.1");

	Q_INIT_RESOURCE(UrielQtFramework);
	QTextCodec *codec = QTextCodec::codecForName("UTF-8");
	QTextCodec::setCodecForLocale(codec);

	QString app_path = QCoreApplication::applicationDirPath();
	QFileInfo file_info(app_path + "\\GlogFiles");

	if (!file_info.isDir() || !file_info.exists())
	{
		system(QString("cd " + app_path).toStdString().c_str());
		system("mkdir -p GlogFiles");
	}
		
	//Init Google Logging model
	google::InitGoogleLogging((const char *)argv[0]);
	google::SetLogDestination(google::GLOG_INFO, "./GlogFiles/log_info_");  //use LOG(INFO)<<"xxx";
	google::SetLogDestination(google::GLOG_WARNING, "./GlogFiles/log_warning_"); //use LOG(WARNING)<<"xxx";
	google::SetLogDestination(google::GLOG_ERROR, "./GlogFiles/log_error_"); //use LOG(ERROR)<<"xxx";
	google::SetLogDestination(google::GLOG_FATAL, "./GlogFiles/log_fatal_"); //use LOG(FATAL)<<"xxx";
	google::SetLogFilenameExtension("win_");
	//Buffered log output defaults to 30 seconds, which is changed to immediate output 
	FLAGS_logbufsecs = 0;
	//set log file size (MB)
	FLAGS_max_log_size = 15; 
	//When the disk is full, stop logging output
	FLAGS_stop_logging_if_full_disk = true;
	//Set the output to the screen log to display the appropriate color
	FLAGS_colorlogtostderr = true;
	
	//UrielQtFrameworkOptions *UrielQtFrameworkOptions::getInstance(void)
	UrielQtFrameworkOptions options;


	//QString sz= options.DigitalChineseUppercase(6008.9);
	//small file downloader
	/*UrielNetworkAccessManager *networkAccessManager= UrielNetworkAccessManager::getInstance();
	networkAccessManager->get();*/
	options.sVersion = instance.applicationVersion();
	QTranslator qTranslator;
	QString locale = QLocale::system().name(); //reading system locale


	//if language is set then ignore system locale
	if (options.sSystemLocal != "")
		locale = options.sSystemLocal;
	//! NOTE: windows and linux system locale are different for serbian language, sr_RS is latin not cyril, this differenc is corrected in code

	if (qTranslator.load(":/language/Version/UrielQtFramework_" + locale + ".qm")) { instance.installTranslator(&qTranslator); }

	//NOTE: Arabic language is the same for all Arabic countries (ex. ar_SY = ar_LY) for that we've to use language name instaed of locale name

	if (locale.left(2) == "ar") {
		instance.setLayoutDirection(Qt::RightToLeft);
	}

	// Custom style theme...
	if (!options.sCustomStyleTheme.isEmpty())
		instance.setStyle(QStyleFactory::create(options.sCustomStyleTheme));

	// Custom color theme (eg. "iLab Studio")...
	QPalette pal(instance.palette());
	unsigned int iUpdatePalette = 0;
	if (update_palette(pal, options.sCustomColorTheme))
		++iUpdatePalette;
	// Dark themes grayed/disabled color group fix...
	if (pal.base().color().value() < 0x7f) {
		const QColor& color = pal.window().color();
		const int iGroups = int(QPalette::Active | QPalette::Inactive) + 1;
		for (int i = 0; i < iGroups; ++i) {
			const QPalette::ColorGroup group = QPalette::ColorGroup(i);
			pal.setBrush(group, QPalette::Light, color.lighter(140));
			pal.setBrush(group, QPalette::Midlight, color.lighter(100));
			pal.setBrush(group, QPalette::Mid, color.lighter(90));
			pal.setBrush(group, QPalette::Dark, color.darker(160));
			pal.setBrush(group, QPalette::Shadow, color.darker(180));
		}
		pal.setColorGroup(QPalette::Disabled,
			pal.windowText().color().darker(),
			pal.button(),
			pal.light(),
			pal.dark(),
			pal.mid(),
			pal.text().color().darker(),
			pal.text().color().lighter(),
			pal.base(),
			pal.window());
#if QT_VERSION >= 0x050000
		pal.setColor(QPalette::Disabled,
			QPalette::Highlight, pal.mid().color());
		pal.setColor(QPalette::Disabled,
			QPalette::ButtonText, pal.mid().color());
#endif
		++iUpdatePalette;
	}


	// New palette update?
	if (iUpdatePalette > 0)
		instance.setPalette(pal);

	// Set default base font...
	if (options.iBaseFontSize > 0)
		instance.setFont(QFont(instance.font().family(), options.iBaseFontSize));

	///////////////////////////////////////////
	UrielFtp* pUrielFTP= UrielFtp::getInstance();
	//pUrielFTP->cdToSpecifiedPath(pUrielFTP->getRootPath() + "/Notices/" + options.getAccount());//
	//pUrielFTP->downloadFile(pUrielFTP->getRootPath() + "/Notices/" + options.getAccount() + "/protobuf-c-master.zip");
	//pUrielFTP->downloadFile(pUrielFTP->getRootPath() + "/Notices/" + options.getAccount()+"/2017年苏州国际精英创业周活动报名表.doc");
	//pUrielFTP->downloadFile("1 001.jpg");
	//pUrielFTP->downloadFile(QString::fromLatin1(QTextCodec::codecForName("UTF-8")->fromUnicode(pUrielFTP->getRootPath() + "/设备检测报告——滚动体外观缺陷光学自动检测机.pdf")));
	//pUrielFTP->uploadFile();
	///pUrielFTP->mkdir("MkdirTest");
	//pUrielFTP->rmdir("/LaboratoryResource/Notices/Uriel/MkdirTest2");
	//pUrielFTP->rmdir("MkdirTest");
	//pUrielFTP->rmdir("MkdirTest2");
	//pUrielFTP->uploadFile("C:/Users/Jing.Woo/Desktop/Ftp-Client-master.zip","/LaboratoryResource/Notices/Uriel");
	/*pUrielFTP->downloadFile("/LaboratoryResource/Invoice/Uriel/WJ.png");
	pUrielFTP->downloadFile("/LaboratoryResource/Invoice/Uriel/wifi-0.png");*/
	UrielDatabase database(&options);
	QString temp_str;
	if (!database.connectDatabase(temp_str))
	{
		QMessageBox::critical(NULL, QObject::tr("Error"), temp_str);
		return 0;
	}

	if (options.getAutoLogin())
	{
		QString sAccountStatus;
		bool exist{ false };
		QString Name;
		if (!database.verifyUserNameAndPassword(options.getAccount(), options.getPassword(), exist, sAccountStatus, Name))
		{
			Login login_w(&database, &options, nullptr);
			login_w.setLoginErrorShow(true, sAccountStatus);
			if (login_w.exec() == QDialog::Rejected)
				return 0;
		}
	}
	else {
		Login login_w(&database, &options, nullptr);
		if (login_w.exec() == QDialog::Rejected)
			return 0;
	}

	sUrielLoginInfoItem loginInfoItem;
	loginInfoItem.m_sUserName = options.getAccount();
	loginInfoItem.m_sHostName=options.getHostUserName()+"-Windows";
	loginInfoItem.m_sIP= options.getIP(options.getlocalHost());
	loginInfoItem.m_sMac = options.gethostMac();
	loginInfoItem.m_tLoginTime = QDateTime::currentDateTime();
	database.insertLoginInfo(loginInfoItem);
	UrielQtFramework w(&database,&options);

	w.show();

	//return instance.exec();

	instance.setActivationWindow(&w);

	QObject::connect(&instance, SIGNAL(messageReceived(const QString&)),
		&w, SLOT(handleSingleApplicationMessage(const QString&)));

	return instance.exec();
}

//! [main start] //! [register meta-type for  communications
//! [register meta-type for communications]

void registerMetaType()
{
	//! [main start] //! [register meta-type for communications]
	qRegisterMetaType<UserInfo>();
	qRegisterMetaType<TimeFilterEnum>();
	qRegisterMetaType<ExpenseItemEnum>();

	//! [register meta-type for queued communications]

}

//-------------------------------------------------------------------------
// update_palette() - Application palette settler.
//

static bool update_palette(QPalette& pal, const QString& sCustomColorTheme)
{
	if (sCustomColorTheme.isEmpty())
		return false;

	if (sCustomColorTheme == "Uriel Theme") {
		pal.setColor(QPalette::Active, QPalette::Window, QColor(73, 78, 88));
		pal.setColor(QPalette::Inactive, QPalette::Window, QColor(73, 78, 88));
		pal.setColor(QPalette::Disabled, QPalette::Window, QColor(64, 68, 77));
		pal.setColor(QPalette::Active, QPalette::WindowText, QColor(182, 193, 208));
		pal.setColor(QPalette::Inactive, QPalette::WindowText, QColor(182, 193, 208));
		pal.setColor(QPalette::Disabled, QPalette::WindowText, QColor(97, 104, 114));
		pal.setColor(QPalette::Active, QPalette::Base, QColor(60, 64, 72));
		pal.setColor(QPalette::Inactive, QPalette::Base, QColor(60, 64, 72));
		pal.setColor(QPalette::Disabled, QPalette::Base, QColor(52, 56, 63));
		pal.setColor(QPalette::Active, QPalette::AlternateBase, QColor(67, 71, 80));
		pal.setColor(QPalette::Inactive, QPalette::AlternateBase, QColor(67, 71, 80));
		pal.setColor(QPalette::Disabled, QPalette::AlternateBase, QColor(59, 62, 70));
		pal.setColor(QPalette::Active, QPalette::ToolTipBase, QColor(182, 193, 208));
		pal.setColor(QPalette::Inactive, QPalette::ToolTipBase, QColor(182, 193, 208));
		pal.setColor(QPalette::Disabled, QPalette::ToolTipBase, QColor(182, 193, 208));
		pal.setColor(QPalette::Active, QPalette::ToolTipText, QColor(42, 44, 48));
		pal.setColor(QPalette::Inactive, QPalette::ToolTipText, QColor(42, 44, 48));
		pal.setColor(QPalette::Disabled, QPalette::ToolTipText, QColor(42, 44, 48));
		pal.setColor(QPalette::Active, QPalette::Text, QColor(210, 222, 240));
		pal.setColor(QPalette::Inactive, QPalette::Text, QColor(210, 222, 240));
		pal.setColor(QPalette::Disabled, QPalette::Text, QColor(99, 105, 115));
		pal.setColor(QPalette::Active, QPalette::Button, QColor(82, 88, 99));
		pal.setColor(QPalette::Inactive, QPalette::Button, QColor(82, 88, 99));
		pal.setColor(QPalette::Disabled, QPalette::Button, QColor(72, 77, 87));
		pal.setColor(QPalette::Active, QPalette::ButtonText, QColor(210, 222, 240));
		pal.setColor(QPalette::Inactive, QPalette::ButtonText, QColor(210, 222, 240));
		pal.setColor(QPalette::Disabled, QPalette::ButtonText, QColor(111, 118, 130));
		pal.setColor(QPalette::Active, QPalette::BrightText, QColor(255, 255, 255));
		pal.setColor(QPalette::Inactive, QPalette::BrightText, QColor(255, 255, 255));
		pal.setColor(QPalette::Disabled, QPalette::BrightText, QColor(255, 255, 255));
		pal.setColor(QPalette::Active, QPalette::Light, QColor(95, 101, 114));
		pal.setColor(QPalette::Inactive, QPalette::Light, QColor(95, 101, 114));
		pal.setColor(QPalette::Disabled, QPalette::Light, QColor(86, 92, 104));
		pal.setColor(QPalette::Active, QPalette::Midlight, QColor(84, 90, 101));
		pal.setColor(QPalette::Inactive, QPalette::Midlight, QColor(84, 90, 101));
		pal.setColor(QPalette::Disabled, QPalette::Midlight, QColor(75, 81, 91));
		pal.setColor(QPalette::Active, QPalette::Dark, QColor(40, 43, 49));
		pal.setColor(QPalette::Inactive, QPalette::Dark, QColor(40, 43, 49));
		pal.setColor(QPalette::Disabled, QPalette::Dark, QColor(35, 38, 43));
		pal.setColor(QPalette::Active, QPalette::Mid, QColor(63, 68, 76));
		pal.setColor(QPalette::Inactive, QPalette::Mid, QColor(63, 68, 76));
		pal.setColor(QPalette::Disabled, QPalette::Mid, QColor(56, 59, 67));
		pal.setColor(QPalette::Active, QPalette::Shadow, QColor(29, 31, 35));
		pal.setColor(QPalette::Inactive, QPalette::Shadow, QColor(29, 31, 35));
		pal.setColor(QPalette::Disabled, QPalette::Shadow, QColor(25, 27, 30));
		pal.setColor(QPalette::Active, QPalette::Highlight, QColor(120, 136, 156));
		pal.setColor(QPalette::Inactive, QPalette::Highlight, QColor(81, 90, 103));
		pal.setColor(QPalette::Disabled, QPalette::Highlight, QColor(64, 68, 77));
		pal.setColor(QPalette::Active, QPalette::HighlightedText, QColor(209, 225, 244));
		pal.setColor(QPalette::Inactive, QPalette::HighlightedText, QColor(182, 193, 208));
		pal.setColor(QPalette::Disabled, QPalette::HighlightedText, QColor(97, 104, 114));
		pal.setColor(QPalette::Active, QPalette::Link, QColor(156, 212, 255));
		pal.setColor(QPalette::Inactive, QPalette::Link, QColor(156, 212, 255));
		pal.setColor(QPalette::Disabled, QPalette::Link, QColor(82, 102, 119));
		pal.setColor(QPalette::Active, QPalette::LinkVisited, QColor(64, 128, 255));
		pal.setColor(QPalette::Inactive, QPalette::LinkVisited, QColor(64, 128, 255));
		pal.setColor(QPalette::Disabled, QPalette::LinkVisited, QColor(54, 76, 119));
		return true;
	}
	else
		if (sCustomColorTheme == "iLab Studio") {
			pal.setColor(QPalette::Active, QPalette::Window, QColor(17, 17, 17));
			pal.setColor(QPalette::Inactive, QPalette::Window, QColor(17, 17, 17));
			pal.setColor(QPalette::Disabled, QPalette::Window, QColor(14, 14, 14));
			pal.setColor(QPalette::Active, QPalette::WindowText, QColor(240, 240, 240));
			pal.setColor(QPalette::Inactive, QPalette::WindowText, QColor(240, 240, 240));
			pal.setColor(QPalette::Disabled, QPalette::WindowText, QColor(83, 83, 83));
			pal.setColor(QPalette::Active, QPalette::Base, QColor(7, 7, 7));
			pal.setColor(QPalette::Inactive, QPalette::Base, QColor(7, 7, 7));
			pal.setColor(QPalette::Disabled, QPalette::Base, QColor(6, 6, 6));
			pal.setColor(QPalette::Active, QPalette::AlternateBase, QColor(14, 14, 14));
			pal.setColor(QPalette::Inactive, QPalette::AlternateBase, QColor(14, 14, 14));
			pal.setColor(QPalette::Disabled, QPalette::AlternateBase, QColor(12, 12, 12));
			pal.setColor(QPalette::Active, QPalette::ToolTipBase, QColor(4, 4, 4));
			pal.setColor(QPalette::Inactive, QPalette::ToolTipBase, QColor(4, 4, 4));
			pal.setColor(QPalette::Disabled, QPalette::ToolTipBase, QColor(4, 4, 4));
			pal.setColor(QPalette::Active, QPalette::ToolTipText, QColor(230, 230, 230));
			pal.setColor(QPalette::Inactive, QPalette::ToolTipText, QColor(230, 230, 230));
			pal.setColor(QPalette::Disabled, QPalette::ToolTipText, QColor(230, 230, 230));
			pal.setColor(QPalette::Active, QPalette::Text, QColor(230, 230, 230));
			pal.setColor(QPalette::Inactive, QPalette::Text, QColor(230, 230, 230));
			pal.setColor(QPalette::Disabled, QPalette::Text, QColor(74, 74, 74));
			pal.setColor(QPalette::Active, QPalette::Button, QColor(28, 28, 28));
			pal.setColor(QPalette::Inactive, QPalette::Button, QColor(28, 28, 28));
			pal.setColor(QPalette::Disabled, QPalette::Button, QColor(24, 24, 24));
			pal.setColor(QPalette::Active, QPalette::ButtonText, QColor(240, 240, 240));
			pal.setColor(QPalette::Inactive, QPalette::ButtonText, QColor(240, 240, 240));
			pal.setColor(QPalette::Disabled, QPalette::ButtonText, QColor(90, 90, 90));
			pal.setColor(QPalette::Active, QPalette::BrightText, QColor(255, 255, 255));
			pal.setColor(QPalette::Inactive, QPalette::BrightText, QColor(255, 255, 255));
			pal.setColor(QPalette::Disabled, QPalette::BrightText, QColor(255, 255, 255));
			pal.setColor(QPalette::Active, QPalette::Light, QColor(191, 191, 191));
			pal.setColor(QPalette::Inactive, QPalette::Light, QColor(191, 191, 191));
			pal.setColor(QPalette::Disabled, QPalette::Light, QColor(191, 191, 191));
			pal.setColor(QPalette::Active, QPalette::Midlight, QColor(155, 155, 155));
			pal.setColor(QPalette::Inactive, QPalette::Midlight, QColor(155, 155, 155));
			pal.setColor(QPalette::Disabled, QPalette::Midlight, QColor(155, 155, 155));
			pal.setColor(QPalette::Active, QPalette::Dark, QColor(129, 129, 129));
			pal.setColor(QPalette::Inactive, QPalette::Dark, QColor(129, 129, 129));
			pal.setColor(QPalette::Disabled, QPalette::Dark, QColor(129, 129, 129));
			pal.setColor(QPalette::Active, QPalette::Mid, QColor(94, 94, 94));
			pal.setColor(QPalette::Inactive, QPalette::Mid, QColor(94, 94, 94));
			pal.setColor(QPalette::Disabled, QPalette::Mid, QColor(94, 94, 94));
			pal.setColor(QPalette::Active, QPalette::Shadow, QColor(155, 155, 155));
			pal.setColor(QPalette::Inactive, QPalette::Shadow, QColor(155, 155, 155));
			pal.setColor(QPalette::Disabled, QPalette::Shadow, QColor(155, 155, 155));
			pal.setColor(QPalette::Active, QPalette::Highlight, QColor(60, 60, 60));
			pal.setColor(QPalette::Inactive, QPalette::Highlight, QColor(34, 34, 34));
			pal.setColor(QPalette::Disabled, QPalette::Highlight, QColor(14, 14, 14));
			pal.setColor(QPalette::Active, QPalette::HighlightedText, QColor(255, 255, 255));
			pal.setColor(QPalette::Inactive, QPalette::HighlightedText, QColor(240, 240, 240));
			pal.setColor(QPalette::Disabled, QPalette::HighlightedText, QColor(83, 83, 83));
			pal.setColor(QPalette::Active, QPalette::Link, QColor(100, 100, 230));
			pal.setColor(QPalette::Inactive, QPalette::Link, QColor(100, 100, 230));
			pal.setColor(QPalette::Disabled, QPalette::Link, QColor(34, 34, 74));
			pal.setColor(QPalette::Active, QPalette::LinkVisited, QColor(230, 100, 230));
			pal.setColor(QPalette::Inactive, QPalette::LinkVisited, QColor(230, 100, 230));
			pal.setColor(QPalette::Disabled, QPalette::LinkVisited, QColor(74, 34, 74));
			return true;
		}

	return false;
}


//QPoint getPopPoint(QWidget *parent, QWidget *popwidget)
//{
//	QPoint pos = (parent->layoutDirection() == Qt::RightToLeft) ? parent->rect().bottomRight() : parent->rect().bottomLeft();
//	QPoint pos2 = (parent->layoutDirection() == Qt::RightToLeft) ? parent->rect().topRight() : parent->rect().topLeft();
//	pos = parent->mapToGlobal(pos);
//	pos2 = parent->mapToGlobal(pos2);
//	QSize size = popwidget->sizeHint();
//	QRect screen = QApplication::desktop()->availableGeometry(pos);
//	if (parent->layoutDirection() == Qt::RightToLeft) {
//		pos.setX(pos.x() - size.width());
//		pos2.setX(pos2.x() - size.width());
//		if (pos.x() < screen.left())
//			pos.setX(qMax(pos.x(), screen.left()));
//		else if (pos.x() + size.width() > screen.right())
//			pos.setX(qMax(pos.x() - size.width(), screen.right() - size.width()));
//	}
//	else {
//		if (pos.x() + size.width() > screen.right())
//			pos.setX(screen.right() - size.width());
//		pos.setX(qMax(pos.x(), screen.left()));
//	}
//	if (pos.y() + size.height() > screen.bottom())
//		pos.setY(pos2.y() - size.height());
//	else if (pos.y() < screen.top())
//		pos.setY(screen.top());
//	if (pos.y() < screen.top())
//		pos.setY(screen.top());
//	if (pos.y() + size.height() > screen.bottom())
//		pos.setY(screen.bottom() - size.height());
//	return pos;
//}