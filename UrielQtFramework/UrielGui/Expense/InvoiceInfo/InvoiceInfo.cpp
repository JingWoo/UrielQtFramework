#include "InvoiceInfo.h"
#include <QFileDialog>
#include <QFile>
#include "UrielDatabase\UrielDatabase.h"
#include "UrielQtFrameworkOptions\UrielQtFrameworkOptions.h"
#include "UrielFileTransfer\FTP\UrielFTP.h"
#include "UrielGui\CommonDialog\UrielImageViewer\UrielImageViewer.h"
#include "UrielGui\CommonDialog\InformationDialog\InformationDialog.h"
#include "UrielGui\CommonDialog\CriticalDialog\CriticalDialog.h"
#include "UrielFileTransfer\NetworkAccessManager\UrielNetworkAccessManager.h"
#include "UrielGui\CommonDialog\ProgressDialog\ProgressDialog.h"
InvoiceInfo::InvoiceInfo(UrielDatabase * database, UrielQtFrameworkOptions *option, QWidget *parent)
	: QDialog(parent), m_database(database), m_options(option)
{
	ui.setupUi(this);
	initializeUI(parent);
	setSignalsAndSlots();
	//m_pUrielNetworkAccessManager=UrielNetworkAccessManager::getInstance();
	//connect(m_pUrielNetworkAccessManager,SIGNAL(UrielReplyFinished()),this,SIGNAL(transferFinish()));
	//connect(m_pUrielNetworkAccessManager, SIGNAL(replyFinished(QNetworkReply*)), this, SLOT(onTransferFinished(QNetworkReply*)));
}

InvoiceInfo::~InvoiceInfo()
{
	m_pUrielNetworkAccessManager = nullptr;
}

void InvoiceInfo::initializeUI(QWidget *parent)
{
	this->m_pParent = parent;
	this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());
	//this->setAttribute(Qt::WA_TranslucentBackground, true);

	this->resize(parent->geometry().width(), parent->geometry().height() - 45);
	this->move(parent->x(), parent->y() + 45);
	//set as Transparent degree
	//setWindowOpacity(0.7);
	ui.InvoiceImage->setScaledContents(false);
	ui.BuyScreenshot->setScaledContents(false);
	ui.VerificationImage->setScaledContents(false);
	QStringList unitList;
	unitList << QStringLiteral("个") << QStringLiteral("套") << QStringLiteral("批") << QStringLiteral("条") << QStringLiteral("项") << QStringLiteral("块")\
		<< QStringLiteral("只") << QStringLiteral("台") << QStringLiteral("根") << QStringLiteral("组") << QStringLiteral("盒") << QStringLiteral("件");
	ui.Unit->addItems(unitList);
}

void InvoiceInfo::setSignalsAndSlots()
{
	QObject::connect(ui.AppClose, &QToolButton::clicked, this, &InvoiceInfo::reject);
	QObject::connect(ui.Calculate, &QToolButton::clicked, this, &InvoiceInfo::onCalculateClicked);
	QObject::connect(ui.Cancel, &QToolButton::clicked, this, &InvoiceInfo::onCancelClicked);
	QObject::connect(ui.OK, &QToolButton::clicked, this, &InvoiceInfo::onOKClicked);

	QObject::connect(ui.AddInvoiceImage, &QToolButton::clicked, this, &InvoiceInfo::onAddInvoiceImageClicked);
	QObject::connect(ui.PreviewInvoiceImage, &QToolButton::clicked, this, &InvoiceInfo::onPreviewInvoiceImageClicked);
	QObject::connect(ui.DeleteInvoiceImage, &QToolButton::clicked, this, &InvoiceInfo::onOKDeleteInvoiceImageClicked);

	QObject::connect(ui.AddBuyScreenshot, &QToolButton::clicked, this, &InvoiceInfo::onAddBuyScreenshotClicked);
	QObject::connect(ui.PreviewBuyScreenshot, &QToolButton::clicked, this, &InvoiceInfo::onPreviewBuyScreenshotClicked);
	QObject::connect(ui.DeleteBuyScreenshot, &QToolButton::clicked, this, &InvoiceInfo::onOKDeleteBuyScreenshotClicked);

	QObject::connect(ui.AddVerificationImage, &QToolButton::clicked, this, &InvoiceInfo::onAddVerificationImageClicked);
	QObject::connect(ui.PreviewVerificationImage, &QToolButton::clicked, this, &InvoiceInfo::onPreviewVerificationImageClicked);
	QObject::connect(ui.DeleteVerificationImage, &QToolButton::clicked, this, &InvoiceInfo::onOKDeleteVerificationImageClicked);
}

void InvoiceInfo::setInvoiceImage()
{
	int height, width;

	width = ui.InvoiceImage->geometry().width();
	if ((m_InvoiceImage.width() / (double)m_InvoiceImage.height() * ui.InvoiceImage->geometry().height()) > ui.InvoiceImage->geometry().width())
	{
		width = ui.InvoiceImage->geometry().width();
		height = m_InvoiceImage.height() / (double)m_InvoiceImage.width() * ui.InvoiceImage->geometry().width();
	}
	else
	{
		width = m_InvoiceImage.width() / (double)m_InvoiceImage.height() * ui.InvoiceImage->geometry().height();
		height = ui.InvoiceImage->geometry().height();
	}
	ui.InvoiceImage->setPixmap(QPixmap::fromImage(m_InvoiceImage.scaled(width, height)));
}

void InvoiceInfo::setBuyScreenshot()
{
	int height, width;
	width = ui.BuyScreenshot->geometry().width();
	if ((m_BuyScreenshot.width() / (double)m_BuyScreenshot.height() * ui.BuyScreenshot->geometry().height()) > ui.BuyScreenshot->geometry().width())
	{
		width = ui.BuyScreenshot->geometry().width();
		height = m_BuyScreenshot.height() / (double)m_BuyScreenshot.width() * ui.BuyScreenshot->geometry().width();
	}
	else
	{
		width = m_BuyScreenshot.width() / (double)m_BuyScreenshot.height() * ui.BuyScreenshot->geometry().height();
		height = ui.BuyScreenshot->geometry().height();
	}
	ui.BuyScreenshot->setPixmap(QPixmap::fromImage(m_BuyScreenshot.scaled(width, height)));
}
void InvoiceInfo::setVerificationImage()
{

	int height, width;
	width = ui.VerificationImage->geometry().width();
	if ((m_VerificationImage.width() / (double)m_VerificationImage.height() * ui.VerificationImage->geometry().height()) > ui.VerificationImage->geometry().width())
	{
		width = ui.VerificationImage->geometry().width();
		height = m_VerificationImage.height() / (double)m_VerificationImage.width() * ui.VerificationImage->geometry().width();
	}
	else
	{
		width = m_VerificationImage.width() / (double)m_VerificationImage.height() * ui.VerificationImage->geometry().height();
		height = ui.VerificationImage->geometry().height();
	}
	ui.VerificationImage->setPixmap(QPixmap::fromImage(m_VerificationImage.scaled(width, height)));
}

void InvoiceInfo::onUpdateDataTransferProgressSlot(qint64 readBytes, qint64 totalBytes)
{
	if (readBytes >= totalBytes)
		emit transferFinish();
}

void InvoiceInfo::onTransferFinished(QNetworkReply* reply)
{
	if (reply->error() == QNetworkReply::NoError)
	{
		QByteArray jpegData = reply->readAll();
		m_TempImage.loadFromData(jpegData);
	}
	else {
		qDebug() << "error";
	}
	reply->deleteLater();
	emit transferFinish();
}

void InvoiceInfo::setInvoiceInfoItem(const sUrielInvoiceInfoItem& item)
{
	isEditMode = true;
	m_stInvoiceInfoItem = item;
	ui.Name->setText(item.m_sName);
	ui.Model->setText(item.m_sModel);
	ui.Quantity->setValue(item.m_iQuantity);
	ui.Unit->setCurrentText(item.m_sUnit);
	ui.Univalent->setText(QString::number(item.m_dUnivalent));
	ui.AggregateAmount->setText(QString::number(item.m_dAggregateAmount));
	UrielFtp *urielFtp = UrielFtp::getInstance();
	
	//connect(urielFtp,SIGNAL(updateDataTransferProgressSignal(qint64, qint64)),this,SLOT(onUpdateDataTransferProgressSlot(qint64, qint64)));

	if (!item.m_sInvoiceImagePath.isEmpty())
	{
		QString file_path = QCoreApplication::applicationDirPath() + "/TempFiles";
		QFileInfo fileInfo(item.m_sInvoiceImagePath);
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
			urielFtp->downloadImageFile(item.m_sInvoiceImagePath);
			progressDialog->exec();
			QEventLoop eventloop;
			QTimer::singleShot(100, &eventloop, SLOT(quit()));
			eventloop.exec();
		}
		m_InvoiceImage=QImage(sfileName);
		int height, width;
		width = 620;
		if ((m_InvoiceImage.width() / (double)m_InvoiceImage.height() * 277) > 620)
		{
			width = 620;
			height = m_InvoiceImage.height() / (double)m_InvoiceImage.width() * 277;
		}
		else
		{
			width = m_InvoiceImage.width() / (double)m_InvoiceImage.height() * 277;
			height = 277;
		}
		ui.InvoiceImage->setPixmap(QPixmap::fromImage(m_InvoiceImage.scaled(width, height)));

		///*QString remotFile = QString::fromLatin1(QTextCodec::codecForName("UTF-8")->fromUnicode(item.m_sInvoiceImagePath));
		//m_pUrielNetworkAccessManager->get(item.m_sInvoiceImagePath);
		//
		//QEventLoop loop;
		//QObject::connect(this, SIGNAL(transferFinish()), &loop, SLOT(quit()));
		//loop.exec();
		//m_InvoiceImage = m_TempImage;*/
		////m_InvoiceImage = urielFtp->downloadImageFile(item.m_sInvoiceImagePath);
		//QUrl url; //该QUrl类提供了一个方便的接口,用于处理URL  
		//url.setScheme("ftp");//设置该计划描述了URL的类型（或协议）  
		//url.setHost("127.0.0.1");//设置主机地址  
		////url.setPath(QString::fromLatin1(QTextCodec::codecForName("UTF-8")->fromUnicode(item.m_sInvoiceImagePath)));//设置URL路径。该路径是自带权限后的URL的一部分，但在查询字符串之前  
		//url.setPath(item.m_sInvoiceImagePath);
		//url.setPort(21);//设置URL的端口。该端口是URL的权限的一部分，如setAuthority（描述）。端口必须是介于0和65535（含）。端口设置为-1表示该端口是不确定的。  
		//url.setPassword("141592"); //设置ftp用户密码  
		//url.setUserName("Uriel");//设置tfp用户名  

		//QNetworkRequest request;//该QNetworkReply类包含的数据和标题,对QNetworkAccessManager发送请求  
		//request.setUrl(url); //这只request的请求  
		//manager = new QNetworkAccessManager;//QNetworkAccessManager 允许发送网络请求和接收回复  
		//QNetworkReply *reply = manager->get(request);//发送请求，以获得目标要求的内容，并返回一个新的QNetworkReply对象打开阅读，每当新的数据到达发射的readyRead（）信号。要求的内容以及相关的头文件会被下载。  
		//							  //连接信号从发送对象到该对象的方法。相当于连接（发件人，信号，接收方，方法，类型）。  
		//							  //每个连接都会发射信号，所以复制连接发会出两个信号。可以使用disconnect()断开了连接。  

		///*connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(slotError(QNetworkReply::NetworkError)));
		//connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));*/

		/////*reply = manager->get(QNetworkRequest(url));*/
		//QEventLoop loop;
		//QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
		//loop.exec();

		//if (reply->error() == QNetworkReply::NoError)
		//{
		//	QByteArray jpegData = reply->readAll();
		//	m_InvoiceImage.loadFromData(jpegData);
		//}
		//else {
		//	qDebug() << "error";
		//}
		////reply->deleteLater();
		//if (reply->isRunning())
		//	reply->abort();
		//delete reply;
		////reply->deleteLater();

		////QEventLoop loop;
		////connect(this, &InvoiceInfo::transferFinish, &loop, &QEventLoop::quit);
		////loop.exec(/*QEventLoop::ExcludeUserInputEvents*/);
		////setInvoiceImage();
		//int height, width;
		//width = 620;
		//if ((m_InvoiceImage.width() / (double)m_InvoiceImage.height() * 277) > 620)
		//{
		//	width = 620;
		//	height = m_InvoiceImage.height() / (double)m_InvoiceImage.width() * 277;
		//}
		//else
		//{
		//	width = m_InvoiceImage.width() / (double)m_InvoiceImage.height() * 277;
		//	height = 277;
		//}
		//ui.InvoiceImage->setPixmap(QPixmap::fromImage(m_InvoiceImage.scaled(width, height)));
	}

	if (!item.m_sBuyScreenshotPath.isEmpty())
	{

		QString file_path = QCoreApplication::applicationDirPath() + "/TempFiles";
		QFileInfo fileInfo(item.m_sBuyScreenshotPath);
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
			urielFtp->downloadImageFile(item.m_sBuyScreenshotPath);
			progressDialog->exec();
			QEventLoop eventloop;
			QTimer::singleShot(100, &eventloop, SLOT(quit()));
			eventloop.exec();
		}
		m_BuyScreenshot = QImage(sfileName);
		int height, width;
		width = 620;
		if ((m_BuyScreenshot.width() / (double)m_BuyScreenshot.height() * 277) > 620)
		{
			width = 620;
			height = m_BuyScreenshot.height() / (double)m_BuyScreenshot.width() * 277;
		}
		else
		{
			width = m_BuyScreenshot.width() / (double)m_BuyScreenshot.height() * 277;
			height = 277;
		}
		ui.BuyScreenshot->setPixmap(QPixmap::fromImage(m_BuyScreenshot.scaled(width, height)));
		///*QString remotFile = QString::fromLatin1(QTextCodec::codecForName("UTF-8")->fromUnicode(item.m_sBuyScreenshotPath));
		//m_pUrielNetworkAccessManager->get(remotFile);
		//QEventLoop loop;
		//QObject::connect(this, SIGNAL(transferFinish()), &loop, SLOT(quit()));
		//loop.exec();
		//m_BuyScreenshot = m_TempImage;*/

		////m_BuyScreenshot = urielFtp->downloadImageFile(item.m_sBuyScreenshotPath);
		///*QString remotFile = QString::fromLatin1(QTextCodec::codecForName("UTF-8")->fromUnicode(item.m_sBuyScreenshotPath));
		//QString file_path = QCoreApplication::applicationDirPath() + "/TempFiles";
		//QFileInfo fileInfo(item.m_sBuyScreenshotPath);
		//QString tempPath = file_path + "/" + fileInfo.fileName();

		//m_pUrielNetworkAccessManager->get(remotFile, tempPath);
		//QEventLoop loop;
		//QObject::connect(this, SIGNAL(transferFinish()), &loop, SLOT(quit()));
		//loop.exec();
		//m_BuyScreenshot = QImage(tempPath);*/
		//QUrl url; //该QUrl类提供了一个方便的接口,用于处理URL  
		//url.setScheme("ftp");//设置该计划描述了URL的类型（或协议）  
		//url.setHost("127.0.0.1");//设置主机地址  
		////url.setPath(QString::fromLatin1(QTextCodec::codecForName("UTF-8")->fromUnicode(item.m_sBuyScreenshotPath)));//设置URL路径。该路径是自带权限后的URL的一部分，但在查询字符串之前  
		//url.setPath(item.m_sBuyScreenshotPath);
		//url.setPort(21);//设置URL的端口。该端口是URL的权限的一部分，如setAuthority（描述）。端口必须是介于0和65535（含）。端口设置为-1表示该端口是不确定的。  
		//url.setPassword("141592"); //设置ftp用户密码  
		//url.setUserName("Uriel");//设置tfp用户名  

		//QNetworkRequest request;//该QNetworkReply类包含的数据和标题,对QNetworkAccessManager发送请求  
		//request.setUrl(url); //这只request的请求  
		////manager = new QNetworkAccessManager;//QNetworkAccessManager 允许发送网络请求和接收回复  
		//QNetworkReply *reply = manager->get(request);//发送请求，以获得目标要求的内容，并返回一个新的QNetworkReply对象打开阅读，每当新的数据到达发射的readyRead（）信号。要求的内容以及相关的头文件会被下载。  
		//							  //连接信号从发送对象到该对象的方法。相当于连接（发件人，信号，接收方，方法，类型）。  
		//							  //每个连接都会发射信号，所以复制连接发会出两个信号。可以使用disconnect()断开了连接。  

		//							  /*connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(slotError(QNetworkReply::NetworkError)));
		//							  connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));*/

		//							  ///*reply = manager->get(QNetworkRequest(url));*/
		//QEventLoop loop;
		//QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
		//loop.exec();

		//if (reply->error() == QNetworkReply::NoError)
		//{
		//	QByteArray jpegData = reply->readAll();
		//	m_BuyScreenshot.loadFromData(jpegData);
		//}
		//else {
		//	qDebug() << "error";
		//}
		//
		//if (reply->isRunning())
		//	reply->abort();
		//delete reply;
		////reply->deleteLater();

		////setBuyScreenshot();
		//int xx = m_BuyScreenshot.width();
		//xx = m_BuyScreenshot.height();
		//int height, width;
		//width = 620;
		//if ((m_BuyScreenshot.width() / (double)m_BuyScreenshot.height() * 277) > 620)
		//{
		//	width = 620;
		//	height = m_BuyScreenshot.height() / (double)m_BuyScreenshot.width() * 277;
		//}
		//else
		//{
		//	width = m_BuyScreenshot.width() / (double)m_BuyScreenshot.height() * 277;
		//	height = 277;
		//}
		//ui.BuyScreenshot->setPixmap(QPixmap::fromImage(m_BuyScreenshot.scaled(width, height)));
	}

	if (!item.m_sVerificationImagePath.isEmpty())
	{
		QString file_path = QCoreApplication::applicationDirPath() + "/TempFiles";
		QFileInfo fileInfo(item.m_sVerificationImagePath);
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
			urielFtp->downloadImageFile(item.m_sVerificationImagePath);
			progressDialog->exec();
			QEventLoop eventloop;
			QTimer::singleShot(100, &eventloop, SLOT(quit()));
			eventloop.exec();
		}
		m_VerificationImage = QImage(sfileName);
		int height, width;
		width = 620;
		if ((m_VerificationImage.width() / (double)m_VerificationImage.height() * 277) > 620)
		{
			width = 620;
			height = m_VerificationImage.height() / (double)m_VerificationImage.width() * 277;
		}
		else
		{
			width = m_VerificationImage.width() / (double)m_VerificationImage.height() * 277;
			height = 277;
		}
		ui.VerificationImage->setPixmap(QPixmap::fromImage(m_VerificationImage.scaled(width, height)));

		//m_VerificationImage = urielFtp->downloadImageFile(item.m_sVerificationImagePath);
		/*QString remotFile = QString::fromLatin1(QTextCodec::codecForName("UTF-8")->fromUnicode(item.m_sVerificationImagePath));
		m_pUrielNetworkAccessManager->get(remotFile);
		QEventLoop loop;
		QObject::connect(this, SIGNAL(transferFinish()), &loop, SLOT(quit()));
		loop.exec();
		m_VerificationImage = m_TempImage;*/

	//	QUrl url; //该QUrl类提供了一个方便的接口,用于处理URL  
	//	url.setScheme("ftp");//设置该计划描述了URL的类型（或协议）  
	//	url.setHost("127.0.0.1");//设置主机地址  
	//	//url.setPath(QString::fromLatin1(QTextCodec::codecForName("UTF-8")->fromUnicode(item.m_sVerificationImagePath)));//设置URL路径。该路径是自带权限后的URL的一部分，但在查询字符串之前  
	//	url.setPath(item.m_sVerificationImagePath);
	//	url.setPort(21);//设置URL的端口。该端口是URL的权限的一部分，如setAuthority（描述）。端口必须是介于0和65535（含）。端口设置为-1表示该端口是不确定的。  
	//	url.setPassword("141592"); //设置ftp用户密码  
	//	url.setUserName("Uriel");//设置tfp用户名  

	//	QNetworkRequest request;//该QNetworkReply类包含的数据和标题,对QNetworkAccessManager发送请求  
	//	request.setUrl(url); //这只request的请求  
	//						 //manager = new QNetworkAccessManager;//QNetworkAccessManager 允许发送网络请求和接收回复  
	//	QNetworkReply *reply = manager->get(request);//发送请求，以获得目标要求的内容，并返回一个新的QNetworkReply对象打开阅读，每当新的数据到达发射的readyRead（）信号。要求的内容以及相关的头文件会被下载。  
	//								  //连接信号从发送对象到该对象的方法。相当于连接（发件人，信号，接收方，方法，类型）。  
	//								  //每个连接都会发射信号，所以复制连接发会出两个信号。可以使用disconnect()断开了连接。  

	//								  /*connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(slotError(QNetworkReply::NetworkError)));
	//								  connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));*/

	//								  ///*reply = manager->get(QNetworkRequest(url));*/
	//	QEventLoop loop;
	//	QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
	//	loop.exec();

	//	if (reply->error() == QNetworkReply::NoError)
	//	{
	//		QByteArray jpegData = reply->readAll();
	//		m_VerificationImage.loadFromData(jpegData);
	//	}
	//	else {
	//		qDebug() << "error";
	//	}
	//	if (reply->isRunning())
	//		reply->abort();
	//	delete reply;
	//	//reply->deleteLater();

	///*	QString remotFile = QString::fromLatin1(QTextCodec::codecForName("UTF-8")->fromUnicode(item.m_sVerificationImagePath));
	//	QString file_path = QCoreApplication::applicationDirPath() + "/TempFiles";
	//	QFileInfo fileInfo(item.m_sVerificationImagePath);
	//	QString tempPath = file_path + "/" + fileInfo.fileName();

	//	m_pUrielNetworkAccessManager->get(remotFile, tempPath);
	//	QEventLoop loop;
	//	QObject::connect(this, SIGNAL(transferFinish()), &loop, SLOT(quit()));
	//	loop.exec();
	//	m_VerificationImage = QImage(tempPath);*/

	///*	m_pUrielNetworkAccessManager->get(QString::fromLatin1(QTextCodec::codecForName("UTF-8")->fromUnicode(item.m_sVerificationImagePath)));
	//	QEventLoop loop;
	//	QObject::connect(this, SIGNAL(transferFinish()), &loop, SLOT(quit()));
	//	loop.exec();
	//	m_VerificationImage = m_TempImage;*/
	//	//setVerificationImage();
	//	int height, width;
	//	width = 620;
	//	if ((m_VerificationImage.width() / (double)m_VerificationImage.height() * 277) > 620)
	//	{
	//		width = 620;
	//		height = m_VerificationImage.height() / (double)m_VerificationImage.width() * 277;
	//	}
	//	else
	//	{
	//		width = m_VerificationImage.width() / (double)m_VerificationImage.height() * 277;
	//		height = 277;
	//	}
	//	ui.VerificationImage->setPixmap(QPixmap::fromImage(m_VerificationImage.scaled(width, height)));
	}

	ui.Description->setPlainText(item.m_sDescription);

}

void InvoiceInfo::onCalculateClicked()
{
	if (!ui.Univalent->text().isEmpty())
		ui.AggregateAmount->setText(QString::number(ui.Univalent->text().toDouble()*ui.Quantity->value()));
	if (!ui.AggregateAmount->text().isEmpty() && ui.Univalent->text().isEmpty())
		ui.Univalent->setText(QString::number(ui.AggregateAmount->text().toDouble()/ui.Quantity->value()));
	
}

void InvoiceInfo::setReimburseCodeAndInvoiceType(const QString & Code,const QString & type)
{
	this->m_sReimburseCode = Code;
	this->m_InvoiceType = type;
}
void InvoiceInfo::onCancelClicked()
{
	this->reject();
}

void InvoiceInfo::onOKClicked()
{
	if (!isEditMode) {
		sUrielInvoiceInfoItem item;
		item.m_sReimburseCode = this->m_sReimburseCode;
		item.m_sType = this->m_InvoiceType;
		item.m_sName = ui.Name->text();
		item.m_sModel = ui.Model->text();
		item.m_iQuantity = ui.Quantity->value();
		item.m_sUnit = ui.Unit->currentText();
		item.m_dUnivalent = ui.Univalent->text().toDouble();
		item.m_dAggregateAmount = ui.AggregateAmount->text().toDouble();
		item.m_sDescription = ui.Description->toPlainText();

		UrielFtp *urielFtp = UrielFtp::getInstance();
		//urielFtp->mkdir(urielFtp->getRootPath() + "/Invoice/" + m_options->getAccount() + "/" + QDateTime::currentDateTime().toString("yyyy_MM_dd"));
		if (!m_sInvoiceImageLocalPath.isEmpty())
		{
			ProgressDialog *progressDialog = new ProgressDialog(this);
			progressDialog->setTotalProgressBarMax(1/*(ui.RP_FileListTreeWidget->currentItem()->text(3).split("K")[0].toInt() * 1024)*/);
			QObject::connect(urielFtp, static_cast<void (UrielFtp::*)(qint64 readBytes, qint64 totalBytes)>(&UrielFtp::updateDataTransferProgressSignal), \
				progressDialog, &ProgressDialog::updateProgressBarValue);
			progressDialog->setTotalProgressBarMax(1);
			QFileInfo fileInfo(m_sInvoiceImageLocalPath);
			QString sRemoteFileName = QDateTime::currentDateTime().toString("yyyy_MM_dd-hhmm_Invoice_") + item.m_sName + "." + fileInfo.suffix();
			item.m_sInvoiceImagePath = urielFtp->getRootPath() + "/Invoice/" + m_options->getAccount() + "/" + sRemoteFileName;
			urielFtp->uploadFileWithRemoteName(m_sInvoiceImageLocalPath, sRemoteFileName, urielFtp->getRootPath() + "/Invoice/" + m_options->getAccount());
			progressDialog->exec();
			QEventLoop eventloop;
			QTimer::singleShot(100, &eventloop, SLOT(quit()));
			eventloop.exec();

			
		}

		if (!m_sBuyScreenshotLocalPath.isEmpty())
		{
			ProgressDialog *progressDialog = new ProgressDialog(this);
			progressDialog->setTotalProgressBarMax(1/*(ui.RP_FileListTreeWidget->currentItem()->text(3).split("K")[0].toInt() * 1024)*/);
			QObject::connect(urielFtp, static_cast<void (UrielFtp::*)(qint64 readBytes, qint64 totalBytes)>(&UrielFtp::updateDataTransferProgressSignal), \
				progressDialog, &ProgressDialog::updateProgressBarValue);
			progressDialog->setTotalProgressBarMax(1);
			QFileInfo fileInfo(m_sBuyScreenshotLocalPath);
			QString sRemoteFileName = QDateTime::currentDateTime().toString("yyyy_MM_dd-hhmm_BuyP_") + item.m_sName + "." + fileInfo.suffix();
			item.m_sBuyScreenshotPath = urielFtp->getRootPath() + "/Invoice/" + m_options->getAccount() + "/" + sRemoteFileName;
			urielFtp->uploadFileWithRemoteName(m_sBuyScreenshotLocalPath, sRemoteFileName, urielFtp->getRootPath() + "/Invoice/" + m_options->getAccount());
			progressDialog->exec();
			QEventLoop eventloop;
			QTimer::singleShot(100, &eventloop, SLOT(quit()));
			eventloop.exec();

			
		}

		if (!m_sVerificationImageLocalPath.isEmpty())
		{
			ProgressDialog *progressDialog = new ProgressDialog(this);
			progressDialog->setTotalProgressBarMax(1/*(ui.RP_FileListTreeWidget->currentItem()->text(3).split("K")[0].toInt() * 1024)*/);
			QObject::connect(urielFtp, static_cast<void (UrielFtp::*)(qint64 readBytes, qint64 totalBytes)>(&UrielFtp::updateDataTransferProgressSignal), \
				progressDialog, &ProgressDialog::updateProgressBarValue);
			progressDialog->setTotalProgressBarMax(1);
			QFileInfo fileInfo(m_sVerificationImageLocalPath);
			QString sRemoteFileName = QDateTime::currentDateTime().toString("yyyy_MM_dd-hhmm_Verif_") + item.m_sName + "." + fileInfo.suffix();
			item.m_sVerificationImagePath = urielFtp->getRootPath() + "/Invoice/" + m_options->getAccount() + "/" + sRemoteFileName;
			urielFtp->uploadFileWithRemoteName(m_sVerificationImageLocalPath, sRemoteFileName, urielFtp->getRootPath() + "/Invoice/" + m_options->getAccount());
			progressDialog->exec();
			QEventLoop eventloop;
			QTimer::singleShot(100, &eventloop, SLOT(quit()));
			eventloop.exec();
		}

		item.m_sReimbursePerson = m_options->getAccount();
		item.m_tReimburseTime = QDateTime::currentDateTime();
		QString error;
		m_database->insertInvoice(item, error);
		if (!error.isEmpty())
		{
			CriticalDialog Critical(QStringLiteral("错误"), QStringLiteral("发票信息登录失败，请联系数据库管理员解决！"), this);
			Critical.exec();
			return;
		}
		else
		{
			InformationDialog information(QStringLiteral("信息"), QStringLiteral("发票信息登录成功！"), this);
			information.exec();
			this->accept();
		}
	}
	else 
	{
		sUrielInvoiceInfoItem item= m_stInvoiceInfoItem;
		item.m_sName = ui.Name->text();
		item.m_sModel = ui.Model->text();
		item.m_iQuantity = ui.Quantity->value();
		item.m_sUnit = ui.Unit->currentText();
		item.m_dUnivalent = ui.Univalent->text().toDouble();
		item.m_dAggregateAmount = ui.AggregateAmount->text().toDouble();
		item.m_sDescription = ui.Description->toPlainText();
		if (isInvoiceImageChange || isBuyScreenshotChange || isVerificationImageChange)
		{
			UrielFtp *urielFtp = UrielFtp::getInstance();
			if (isInvoiceImageChange) {
				if (!m_sInvoiceImageLocalPath.isEmpty()) {
					ProgressDialog *progressDialog = new ProgressDialog(this);
					progressDialog->setTotalProgressBarMax(1/*(ui.RP_FileListTreeWidget->currentItem()->text(3).split("K")[0].toInt() * 1024)*/);
					QObject::connect(urielFtp, static_cast<void (UrielFtp::*)(qint64 readBytes, qint64 totalBytes)>(&UrielFtp::updateDataTransferProgressSignal), \
						progressDialog, &ProgressDialog::updateProgressBarValue);
					progressDialog->setTotalProgressBarMax(1);
					QFileInfo fileInfo(m_sInvoiceImageLocalPath);
					QString sRemoteFileName = QDateTime::currentDateTime().toString("yyyy_MM_dd-hhmm_Invoice_") + item.m_sName + "." + fileInfo.suffix();
					item.m_sInvoiceImagePath = urielFtp->getRootPath() + "/Invoice/" + m_options->getAccount() + "/" + sRemoteFileName;
					urielFtp->uploadFileWithRemoteName(m_sInvoiceImageLocalPath, sRemoteFileName, urielFtp->getRootPath() + "/Invoice/" + m_options->getAccount());
					progressDialog->exec();
					QEventLoop eventloop;
					QTimer::singleShot(100, &eventloop, SLOT(quit()));
					eventloop.exec();
				}
				else {
					item.m_sInvoiceImagePath = "";
				}
				

			}
			if (isBuyScreenshotChange ) {
				if (!m_sBuyScreenshotLocalPath.isEmpty()) {
					ProgressDialog *progressDialog = new ProgressDialog(this);
					progressDialog->setTotalProgressBarMax(1/*(ui.RP_FileListTreeWidget->currentItem()->text(3).split("K")[0].toInt() * 1024)*/);
					QObject::connect(urielFtp, static_cast<void (UrielFtp::*)(qint64 readBytes, qint64 totalBytes)>(&UrielFtp::updateDataTransferProgressSignal), \
						progressDialog, &ProgressDialog::updateProgressBarValue);
					progressDialog->setTotalProgressBarMax(1);
					QFileInfo fileInfo(m_sBuyScreenshotLocalPath);
					QString sRemoteFileName = QDateTime::currentDateTime().toString("yyyy_MM_dd-hhmm_BuyP_") + item.m_sName + "." + fileInfo.suffix();
					item.m_sBuyScreenshotPath = urielFtp->getRootPath() + "/Invoice/" + m_options->getAccount() + "/" + sRemoteFileName;
					urielFtp->uploadFileWithRemoteName(m_sBuyScreenshotLocalPath, sRemoteFileName, urielFtp->getRootPath() + "/Invoice/" + m_options->getAccount());
					progressDialog->exec();
					QEventLoop eventloop;
					QTimer::singleShot(100, &eventloop, SLOT(quit()));
					eventloop.exec();
				}
				else {
					item.m_sBuyScreenshotPath = "";
				}
				
			}
			if (isVerificationImageChange ) {
				if (!m_sVerificationImageLocalPath.isEmpty()) {
					ProgressDialog *progressDialog = new ProgressDialog(this);
					progressDialog->setTotalProgressBarMax(1/*(ui.RP_FileListTreeWidget->currentItem()->text(3).split("K")[0].toInt() * 1024)*/);
					QObject::connect(urielFtp, static_cast<void (UrielFtp::*)(qint64 readBytes, qint64 totalBytes)>(&UrielFtp::updateDataTransferProgressSignal), \
						progressDialog, &ProgressDialog::updateProgressBarValue);
					progressDialog->setTotalProgressBarMax(1);
					QFileInfo fileInfo(m_sVerificationImageLocalPath);
					QString sRemoteFileName = QDateTime::currentDateTime().toString("yyyy_MM_dd-hhmm_Verif_") + item.m_sName + "." + fileInfo.suffix();
					item.m_sVerificationImagePath = urielFtp->getRootPath() + "/Invoice/" + m_options->getAccount() + "/" + sRemoteFileName;
					urielFtp->uploadFileWithRemoteName(m_sVerificationImageLocalPath, sRemoteFileName, urielFtp->getRootPath() + "/Invoice/" + m_options->getAccount());
					progressDialog->exec();
					QEventLoop eventloop;
					QTimer::singleShot(100, &eventloop, SLOT(quit()));
					eventloop.exec();
				}
				else {
					item.m_sVerificationImagePath = "";
				}
				
			}
		}
		
		//urielFtp->mkdir(urielFtp->getRootPath() + "/Invoice/" + m_options->getAccount() + "/" + QDateTime::currentDateTime().toString("yyyy_MM_dd"));
		item.m_sReimbursePerson = m_options->getAccount();
		item.m_tReimburseTime = QDateTime::currentDateTime();
		QString error;
		m_database->updateInvoice(item, error);
		if (!error.isEmpty())
		{
			CriticalDialog Critical(QStringLiteral("错误"), QStringLiteral("发票信息登录失败，请联系数据库管理员解决！"), this);
			Critical.exec();
			return;
		}
		else
		{
			InformationDialog information(QStringLiteral("信息"), QStringLiteral("发票信息登录成功！"), this);
			information.exec();
			this->accept();
		}
	}
	
}

void InvoiceInfo::onAddInvoiceImageClicked()
{
	ui.InvoiceImage->setScaledContents(false);
	m_sInvoiceImageLocalPath = QFileDialog::getOpenFileName(
		this, QStringLiteral("请选择发票图片"),
		QCoreApplication::applicationDirPath(),
		tr("All Files (*);;PNG File (*.png);;JPG Files (*.jpg);;JPGE Files (*.jpge);;BMP Files (*.bmp)"));
	if (!m_sInvoiceImageLocalPath.isEmpty())
	{
		m_InvoiceImage = QImage(m_sInvoiceImageLocalPath);
		setInvoiceImage(); 
	}
	if (isEditMode) {
		isInvoiceImageChange = true;
	}
}

void InvoiceInfo::onPreviewInvoiceImageClicked()
{
	UrielImageViewer imageViewer(this->m_pParent);
	if(m_InvoiceImage.isNull())
	    imageViewer.setImage(QImage(":/Expense/Resources/Expense/nopicture.png"));
	else
		imageViewer.setImage(m_InvoiceImage);
	imageViewer.exec();
}

void InvoiceInfo::onOKDeleteInvoiceImageClicked()
{
	ui.InvoiceImage->setScaledContents(true);
	ui.InvoiceImage->setPixmap(QPixmap::fromImage(QImage(":/Expense/Resources/Expense/nopicture.png")));
	m_InvoiceImage = QImage();
	if (isEditMode) {
		isInvoiceImageChange = true;
		m_sInvoiceImageLocalPath = "";
	}
}

void InvoiceInfo::onAddBuyScreenshotClicked()
{
	ui.BuyScreenshot->setScaledContents(false);
	m_sBuyScreenshotLocalPath = QFileDialog::getOpenFileName(
		this, QStringLiteral("请选择发票图片"),
		QCoreApplication::applicationDirPath(),
		tr("All Files (*);;PNG File (*.png);;JPG Files (*.jpg);;JPGE Files (*.jpge);;BMP Files (*.bmp)"));
	if (!m_sBuyScreenshotLocalPath.isEmpty())
	{
		m_BuyScreenshot = QImage(m_sBuyScreenshotLocalPath);

		setBuyScreenshot();
	}
	if (isEditMode) {
		isBuyScreenshotChange = true;
	}
}

void InvoiceInfo::onPreviewBuyScreenshotClicked()
{
	UrielImageViewer imageViewer(this->m_pParent);
	if (m_BuyScreenshot.isNull())
		imageViewer.setImage(QImage(":/Expense/Resources/Expense/nopicture.png"));
	else
		imageViewer.setImage(m_BuyScreenshot);
	imageViewer.exec();
}

void InvoiceInfo::onOKDeleteBuyScreenshotClicked()
{
	ui.BuyScreenshot->setScaledContents(true);
	ui.BuyScreenshot->setPixmap(QPixmap::fromImage(QImage(":/Expense/Resources/Expense/nopicture.png")));
	m_BuyScreenshot = QImage();
	if (isEditMode) {
		isBuyScreenshotChange = true;
		m_sBuyScreenshotLocalPath = "";
	}
}

void InvoiceInfo::onAddVerificationImageClicked()
{
	ui.VerificationImage->setScaledContents(false);
	m_sVerificationImageLocalPath = QFileDialog::getOpenFileName(
		this, QStringLiteral("请选择发票图片"),
		QCoreApplication::applicationDirPath(),
		tr("All Files (*);;PNG File (*.png);;JPG Files (*.jpg);;JPGE Files (*.jpge);;BMP Files (*.bmp)"));
	if (!m_sVerificationImageLocalPath.isEmpty())
	{
		m_VerificationImage = QImage(m_sVerificationImageLocalPath);
		setVerificationImage();
	}
	if (isEditMode) {
		isVerificationImageChange = true;
	}
}

void InvoiceInfo::onPreviewVerificationImageClicked()
{
	UrielImageViewer imageViewer(this->m_pParent);
	if (m_VerificationImage.isNull())
		imageViewer.setImage(QImage(":/Expense/Resources/Expense/nopicture.png"));
	else
		imageViewer.setImage(m_VerificationImage);
	imageViewer.exec();
}

void InvoiceInfo::onOKDeleteVerificationImageClicked()
{
	ui.VerificationImage->setScaledContents(true);
	ui.VerificationImage->setPixmap(QPixmap::fromImage(QImage(":/Expense/Resources/Expense/nopicture.png")));
	m_VerificationImage = QImage();
	if (isEditMode) {
		isVerificationImageChange = true;
		m_sVerificationImageLocalPath = "";
	}
}