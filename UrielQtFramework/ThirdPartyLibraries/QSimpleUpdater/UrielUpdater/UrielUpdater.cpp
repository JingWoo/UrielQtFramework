#include "UrielUpdater.h"
#include "ThirdPartyLibraries\QSimpleUpdater\include\QSimpleUpdater.h"
#include "UrielQtFrameworkOptions\UrielQtFrameworkOptions.h"
//==============================================================================
// Define the URL of the Update Definitions file
//==============================================================================
//ftp://test:test@192.168.0.1:21/profile

//static const QString DEFS_URL = "https://raw.githubusercontent.com/"
//"alex-spataru/QSimpleUpdater/master/tutorial/"
//"definitions/updates.json";

#include<QMovie>
UrielUpdater::UrielUpdater(QWidget* parent) 
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());
	setWindowTitle(qApp->applicationName());
	QMovie* movie = new QMovie(":/Mainwindow/Resources/update.gif");
	ui.label_2->setScaledContents(true);
	ui.label_2->setMovie(movie);
	movie->start();

	UrielQtFrameworkOptions* option = UrielQtFrameworkOptions::getInstance();
	ui.groupBox->setVisible(false);
	ui.resetButton->setVisible(false);
	sUrielFTPItem ftpItem= option->getFTPConfigParameter();
	DEFS_URL = "ftp://" + ftpItem.m_sUserName + ":" + ftpItem.m_sPassword + "@" +
		ftpItem.m_sHostIp + ":21/LaboratoryResource/updateInfo/updates.json";


	/* QSimpleUpdater is single-instance */
	m_updater = QSimpleUpdater::getInstance();

	/* Check for updates when the "Check For Updates" button is clicked */
	connect(m_updater, SIGNAL(checkingFinished(QString)),
		this, SLOT(updateChangelog(QString)));
	connect(m_updater, SIGNAL(appcastDownloaded(QString, QByteArray)),
		this, SLOT(displayAppcast(QString, QByteArray)));

	/* React to button clicks */
	connect(ui.resetButton, SIGNAL(clicked()),
		this, SLOT(resetFields()));
	connect(ui.closeButton, SIGNAL(clicked()),
		this, SLOT(close()));
	connect(ui.checkButton, SIGNAL(clicked()),
		this, SLOT(checkForUpdates()));

	/* Resize the dialog to fit */
	setMinimumSize(minimumSizeHint());
	resize(minimumSizeHint());

	/* Reset the UI state */
	resetFields();
}
UrielUpdater::~UrielUpdater() {

}


void UrielUpdater::resetFields()
{
	ui.installedVersion->setText("0.1");
	ui.customAppcast->setChecked(false);
	ui.enableDownloader->setChecked(true);
	ui.showAllNotifcations->setChecked(false);
	ui.showUpdateNotifications->setChecked(true);
}

//==============================================================================
// Window::checkForUpdates
//==============================================================================

void UrielUpdater::checkForUpdates()
{
	/* Get settings from the UI */
	QString version = ui.installedVersion->text();
	bool customAppcast = ui.customAppcast->isChecked();
	bool downloaderEnabled = ui.enableDownloader->isChecked();
	bool notifyOnFinish = ui.showAllNotifcations->isChecked();
	bool notifyOnUpdate = ui.showUpdateNotifications->isChecked();

	/* Apply the settings */
	m_updater->setModuleVersion(DEFS_URL, version);
	m_updater->setNotifyOnFinish(DEFS_URL, notifyOnFinish);
	m_updater->setNotifyOnUpdate(DEFS_URL, notifyOnUpdate);
	m_updater->setUseCustomAppcast(DEFS_URL, customAppcast);
	m_updater->setDownloaderEnabled(DEFS_URL, downloaderEnabled);

	/* Check for updates */
	m_updater->checkForUpdates(DEFS_URL);
}


void UrielUpdater::updateChangelog(const QString& url)
{
	if (url == DEFS_URL)
		ui.changelogText->setText(m_updater->getChangelog(url));
}


void UrielUpdater::displayAppcast(const QString& url, const QByteArray& reply)
{
	if (url == DEFS_URL) {
		QString text = "This is the downloaded appcast: <p><pre>" +
			QString::fromUtf8(reply) +
			"</pre></p><p> If you need to store more information on the "
			"appcast (or use another format), just use the "
			"<b>QSimpleUpdater::setCustomAppcast()</b> function. "
			"It allows your application to interpret the appcast "
			"using your code and not QSU's code.</p>";

		ui.changelogText->setText(text);
	}
}

