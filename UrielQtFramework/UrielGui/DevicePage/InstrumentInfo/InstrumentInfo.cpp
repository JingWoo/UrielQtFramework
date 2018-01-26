#include "InstrumentInfo.h"
#include <QFileDialog>
#include <QMessageBox>
#include "UrielDatabase\UrielDatabase.h"
#include "UrielFileTransfer\FTP\UrielFTP.h"
#include "UrielGui\CommonDialog\ProgressDialog\ProgressDialog.h"
InstrumentInfo::InstrumentInfo(UrielDatabase * database, QWidget *parent)
	: QDialog(parent), m_database(database)
{
	ui.setupUi(this);
	initializeUI(parent);
	setSignalsAndSlots();
}

InstrumentInfo::~InstrumentInfo()
{
}

void InstrumentInfo::setValue(const sUrielInstrumentItem & item)
{
	m_bIsEditMode = true;
	m_stUrielInstrumentItem = item;
	if(!item.m_sSDKAddress.isEmpty())
		ui.SDKDownLoad->setVisible(true);
	ui.InstrumentName->setText(item.m_sName);
	ui.InstrumentModel->setText(item.m_sModel);
	ui.InstrumentVender->setText(item.m_sVender);
	ui.InstrumentPrice->setValue(item.m_dPrice);
	ui.InstrumentPurchaseTime->setDateTime(item.m_tPurchaseTime);
	ui.InstrumentGuaranteePeriod->setValue(item.m_iGuaranteePeriod);
	ui.ProjectTeamCombox->setCurrentText(item.m_sProjectTeam);
	ui.InstrumentPresentPersonInCharge->setText(item.m_sPresentPersonInCharge);
	if (item.m_sStatus == QStringLiteral("存放")) ui.ReturnStatus->setChecked(true);
	else ui.LendStatus->setChecked(true);
	ui.InstrumentAddress->setText(item.m_sInstrumentAddress);

	QStringList SDKFileNameList = item.m_sSDKAddress.split(";");
	QString sFileNames;
	for each (QString var in SDKFileNameList)
	{
		QFileInfo fileInfo(var);
		sFileNames += fileInfo.fileName() + ";";
	}
	sFileNames.resize(sFileNames.length() - 1);
	ui.InstrumentSDKAddress->setText(sFileNames);

	if (!item.m_sInstrumentImage.isEmpty())
	{
		QString file_path = QCoreApplication::applicationDirPath() + "/TempFiles";
		QFileInfo fileInfo(item.m_sInstrumentImage);
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
			urielFtp->downloadImageFile( item.m_sInstrumentImage);
			progressDialog->exec();
			QEventLoop eventloop;
			QTimer::singleShot(100, &eventloop, SLOT(quit()));
			eventloop.exec();
		}
		QImage image(sfileName);
		int height, width;
		width = ui.InstrumentImage->geometry().width();
		if ((image.width() / (double)image.height() * ui.InstrumentImage->geometry().height()) > ui.InstrumentImage->geometry().width())
		{
			width = ui.InstrumentImage->geometry().width();
			height = image.height() / (double)image.width() * ui.InstrumentImage->geometry().width();
		}
		else
		{
			width = image.width() / (double)image.height() * ui.InstrumentImage->geometry().height();
			height = ui.InstrumentImage->geometry().height();
		}
		ui.InstrumentImage->setPixmap(QPixmap::fromImage(image.scaled(width, height)));
		//ui.InstrumentImage->setPixmap(QPixmap(sfileName));
	}
	else
		ui.InstrumentImage->setPixmap(QPixmap(":/Mainwindow/Resources/UrielQtFramework/device.png"));
	ui.InstrumentDescription->setPlainText(item.m_sDescription);
	ui.ConfirmOperation->setText(QStringLiteral("修改设备"));

}

void InstrumentInfo::initializeUI(QWidget *parent)
{
	this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());
	//this->setAttribute(Qt::WA_TranslucentBackground, true);

	this->resize(parent->geometry().width(), parent->geometry().height() - 45);
	this->move(parent->x(), parent->y() + 45);
	//set as Transparent degree
	//setWindowOpacity(0.7);

	ui.InstrumentImage->setScaledContents(false);
	QStringList slProjectList;
	m_database->getDistinctProjectFromInstrument(slProjectList);
	ui.ProjectTeamCombox->addItems(slProjectList);
	ui.SDKDownLoad->setVisible(false);
}

void InstrumentInfo::setSignalsAndSlots()
{
	QObject::connect(ui.AppClose, &QToolButton::clicked, this, &InstrumentInfo::reject);
	QObject::connect(ui.ConfirmOperation, &QToolButton::clicked, this, &InstrumentInfo::onConfirmOperationClicked);
	QObject::connect(ui.ChangeImageTB, &QToolButton::clicked, this, &InstrumentInfo::onChangeImageTBClicked); 
	QObject::connect(ui.InstrumentSDKBrowerTB, &QToolButton::clicked, this, &InstrumentInfo::onInstrumentSDKBrowerTBClicked);
	QObject::connect(ui.SDKDownLoad, &QToolButton::clicked, this, &InstrumentInfo::onSDKDownLoadTBClicked);
}

void InstrumentInfo::onSDKDownLoadTBClicked() {
	UrielFtp *urielFtp = UrielFtp::getInstance();
	QStringList fileList = m_stUrielInstrumentItem.m_sSDKAddress.split(";");
	if (fileList.count()) {
		QString file_path = QFileDialog::getExistingDirectory(nullptr, QString::fromLocal8Bit("请选择文件保存路径..."), "./");
		for each (QString var in fileList) {
			ProgressDialog *progressDialog = new ProgressDialog(this);
			QObject::connect(urielFtp, static_cast<void (UrielFtp::*)(qint64 readBytes, qint64 totalBytes)>(&UrielFtp::updateDataTransferProgressSignal), \
				progressDialog, &ProgressDialog::updateProgressBarValue);
			progressDialog->setTotalProgressBarMax(1);
			if (urielFtp->downloadFiles(file_path, var)) {
				progressDialog->exec();
				QEventLoop eventloop;
				QTimer::singleShot(100, &eventloop, SLOT(quit()));
				eventloop.exec();
			}
			else {
				QObject::disconnect(urielFtp, static_cast<void (UrielFtp::*)(qint64 readBytes, qint64 totalBytes)>(&UrielFtp::updateDataTransferProgressSignal), \
					progressDialog, &ProgressDialog::updateProgressBarValue);
				delete progressDialog;
			}
		}
	}
}

void InstrumentInfo::onConfirmOperationClicked()
{
	m_stUrielInstrumentItem.m_sName = ui.InstrumentName->text();
	m_stUrielInstrumentItem.m_sModel = ui.InstrumentModel->text();
	m_stUrielInstrumentItem.m_sVender = ui.InstrumentVender->text();
	m_stUrielInstrumentItem.m_dPrice = ui.InstrumentPrice->value();
	m_stUrielInstrumentItem.m_tPurchaseTime = ui.InstrumentPurchaseTime->dateTime();
	m_stUrielInstrumentItem.m_iGuaranteePeriod = ui.InstrumentGuaranteePeriod->value();
	m_stUrielInstrumentItem.m_sProjectTeam = ui.ProjectTeamCombox->currentText();
	m_stUrielInstrumentItem.m_sPresentPersonInCharge = ui.InstrumentPresentPersonInCharge->text();
	if (ui.ReturnStatus->isChecked()) m_stUrielInstrumentItem.m_sStatus = QStringLiteral("存放");
	else m_stUrielInstrumentItem.m_sStatus = QStringLiteral("借出");
	m_stUrielInstrumentItem.m_sInstrumentAddress = ui.InstrumentAddress->text();

	m_stUrielInstrumentItem.m_sDescription = ui.InstrumentDescription->toPlainText();

	UrielFtp *urielFtp = UrielFtp::getInstance();

	QString RemoteNoticesFilePath = urielFtp->getRootPath() + "/InstrumentSDK/" + m_stUrielInstrumentItem.m_sName;
	QStringList remoteFileNameList = m_sRemoteFilePaths.split(";");
	m_sRemoteFilePaths = "";
	for each (QString var in remoteFileNameList)
	{
		if (!var.isEmpty())
			m_sRemoteFilePaths += (RemoteNoticesFilePath + "/" + var + ";");
	}
	if (!m_sRemoteFilePaths.isEmpty())
		m_sRemoteFilePaths.resize(m_sRemoteFilePaths.size() - 1);
	m_stUrielInstrumentItem.m_sSDKAddress = m_sRemoteFilePaths;

	if(!m_sLoaclImagePaths.isEmpty())
	    m_stUrielInstrumentItem.m_sInstrumentImage = urielFtp->getRootPath() + "/InstrumentSDK/" + \
		              m_stUrielInstrumentItem.m_sName + "/" + QFileInfo(m_sLoaclImagePaths).fileName();

	if (!m_bIsEditMode)
	{
		
		QString errorInfo;
		m_database->insertInstrument(m_stUrielInstrumentItem, errorInfo);
		if (!errorInfo.isEmpty())
		{
			QMessageBox::critical(nullptr, QStringLiteral("错误"), QStringLiteral("数据库添加设备信息失败，请联系管理员修复数据库！"));
		}
		else
		{
			urielFtp->mkdir(urielFtp->getRootPath() + "/InstrumentSDK/" + m_stUrielInstrumentItem.m_sName);
			if (!m_sLoaclFilePaths.isEmpty()) {
				QStringList fileNameList = m_sLoaclFilePaths.split(";");

				int i = 1;
				for each (QString var in fileNameList)
				{
					ProgressDialog *progressDialog = new ProgressDialog(this);
					progressDialog->setTotalProgressBarMax(1/*(ui.RP_FileListTreeWidget->currentItem()->text(3).split("K")[0].toInt() * 1024)*/);
					QObject::connect(urielFtp, static_cast<void (UrielFtp::*)(qint64 readBytes, qint64 totalBytes)>(&UrielFtp::updateDataTransferProgressSignal), \
						progressDialog, &ProgressDialog::updateProgressBarValue);
					progressDialog->setTotalProgressBarMax(1);
					urielFtp->uploadFile(var, urielFtp->getRootPath() + "/InstrumentSDK/" + m_stUrielInstrumentItem.m_sName);
					progressDialog->exec();
					QEventLoop eventloop;
					QTimer::singleShot(100, &eventloop, SLOT(quit()));
					eventloop.exec();
				}
			}
			
			if(!m_sLoaclImagePaths.isEmpty())
			    urielFtp->uploadFile(m_sLoaclImagePaths, urielFtp->getRootPath() + "/InstrumentSDK/" + m_stUrielInstrumentItem.m_sName);
			QMessageBox::information(nullptr, QStringLiteral("信息"), QStringLiteral("添加设备信息成功！"));
			this->accept();
		}
	}
	else //Edit Mode
	{
		if (!m_sLoaclImagePaths.isEmpty()) {
			urielFtp->uploadFile(m_sLoaclImagePaths, urielFtp->getRootPath() + "/InstrumentSDK/" + m_stUrielInstrumentItem.m_sName);
		}
		QString SDKFileNames;
		m_database->getInstrumentSDKFiles(SDKFileNames, QString::number(m_stUrielInstrumentItem.m_iId));

		m_database->updateInstrument(m_stUrielInstrumentItem);

		QStringList sFileNameList = m_sLoaclFilePaths.split(";");

		for each (QString var in sFileNameList)
		{
			QFileInfo fileInfo(var);
			if (!SDKFileNames.contains(fileInfo.fileName()))
				urielFtp->uploadFile(var, urielFtp->getRootPath() + "/InstrumentSDK/" + m_stUrielInstrumentItem.m_sName);
		}

		
		QMessageBox::information(nullptr, QStringLiteral("信息"), QStringLiteral("修改设备信息成功！"));
		this->accept();
	}
}

void InstrumentInfo::onChangeImageTBClicked()
{
	m_sLoaclImagePaths = QFileDialog::getOpenFileName(
		this, QStringLiteral("请选择设备图片"),
		QCoreApplication::applicationDirPath(),
		tr("All Files (*);;PNG File (*.png);;JPG Files (*.jpg);;JPGE Files (*.jpge);;BMP Files (*.bmp)"));
	if (!m_sLoaclImagePaths.isEmpty())
	{
		QImage image(m_sLoaclImagePaths);

		int height, width;
		width = ui.InstrumentImage->geometry().width();
		if ((image.width() / (double)image.height() * ui.InstrumentImage->geometry().height()) > ui.InstrumentImage->geometry().width())
		{
			width = ui.InstrumentImage->geometry().width();
			height = image.height() / (double)image.width() * ui.InstrumentImage->geometry().width();
		}
		else
		{
			width = image.width() / (double)image.height() * ui.InstrumentImage->geometry().height();
			height = ui.InstrumentImage->geometry().height();
		}
		ui.InstrumentImage->setPixmap(QPixmap::fromImage(image.scaled(width, height)));
	}
	isImageChange = true;
}

void InstrumentInfo::onInstrumentSDKBrowerTBClicked()
{
	QStringList files = QFileDialog::getOpenFileNames(
		this, tr("QFileDialog::getOpenFileNames()"),
		QCoreApplication::applicationDirPath(),
		tr("All Files (*);;RAR Files (*.rar);;ZIP Files (*.zip);;IOS Files (*.ios)"));
	if (files.count()) {
		for each (auto file in files)
		{

			m_sLoaclFilePaths += file + ";";
			QFileInfo fileInfo(file);
			m_sRemoteFilePaths += fileInfo.fileName() + ";";
		}
	}
	m_sRemoteFilePaths.resize(m_sRemoteFilePaths.length() - 1);
	m_sLoaclFilePaths.resize(m_sLoaclFilePaths.length() - 1);
	ui.InstrumentSDKAddress->setText(m_sRemoteFilePaths);
	isFileChange = true;
}