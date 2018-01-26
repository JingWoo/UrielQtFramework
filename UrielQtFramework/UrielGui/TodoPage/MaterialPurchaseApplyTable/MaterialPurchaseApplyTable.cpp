#include "MaterialPurchaseApplyTable.h"
#include "UrielDatabase\UrielDatabase.h"
#include "UrielQtFrameworkOptions\UrielQtFrameworkOptions.h"
#include "UrielGui\CommonDialog\InformationDialog\InformationDialog.h"
#include "UrielGui\CommonDialog\UrielImageViewer\UrielImageViewer.h"
#include "UrielFileTransfer\FTP\UrielFTP.h"
#include "UrielGui\CommonDialog\ProgressDialog\ProgressDialog.h"
MaterialPurchaseApplyTable::MaterialPurchaseApplyTable(UrielDatabase * database, UrielQtFrameworkOptions *option, const QString & ApplicationNumber,QWidget *parent)
	: QDialog(parent), m_pDatabase(database), m_pOptions(option), m_szApplicationNumber(ApplicationNumber), m_pParent(parent)
{
	ui.setupUi(this);
	initializeUI(parent);
	setSignalsAndSlots();

}

MaterialPurchaseApplyTable::~MaterialPurchaseApplyTable()
{

}

void MaterialPurchaseApplyTable::setTable(const sUrielMaterialDeviceItem & item, QLineEdit * SerialNumber, QLineEdit * DeviceName, QLineEdit * ModelSpecification,
	QLineEdit * Unit, QLineEdit * Number, QLineEdit * UnitPrice, QLineEdit * Total) {
	SerialNumber->setText(item.m_sSerialNumber);
	DeviceName->setText(item.m_sMaterialName);
	ModelSpecification->setText(item.m_sModelSpecification);
	Unit->setText(item.m_sUnit);
	Number->setText(item.m_sQuantity);
	UnitPrice->setText(item.m_sUnitPrice);
	Total->setText(item.m_sTotal);
}


void MaterialPurchaseApplyTable::initializeUI(QWidget *parent)
{
	this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());
	//this->setAttribute(Qt::WA_TranslucentBackground, true);

	this->resize(parent->geometry().width(), parent->geometry().height() - 45);
	this->move(parent->x(), parent->y() + 45);
	//set as Transparent degree
	//setWindowOpacity(0.7);

	sUrielMaterialPurchaseApplyItem MaterialPurchaseApplyItem;
	m_pDatabase->getMaterialPurchaseApplyByApplicationNumber(MaterialPurchaseApplyItem, m_szApplicationNumber);
	ui.ApplicantLineEdit->setText(MaterialPurchaseApplyItem.m_sApplicant);
	ui.DeclarationDateDateEdit->setDateTime(MaterialPurchaseApplyItem.m_tDeclarationDate);
	ui.TotalAmountLineEdit->setText(MaterialPurchaseApplyItem.m_sTotalAmount);
	ui.RequisitionReasonsPlainTextEdit->setPlainText(MaterialPurchaseApplyItem.m_sRequisitionReasons);
	ui.AuditOpinionPlainTextEdit->setPlainText("");
	ui.ReviewerLabel->setText(MaterialPurchaseApplyItem.m_sReviewer);
	ui.ReviewTimeDateEdit->setDateTime(MaterialPurchaseApplyItem.m_tReviewTime);
	ui.LinkAddressLineEdit->setText(MaterialPurchaseApplyItem.m_sLinkAddress);

	QString file_path = QCoreApplication::applicationDirPath() + "/TempFiles";
	QFileInfo fileInfo(MaterialPurchaseApplyItem.m_sImagePath);
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
		urielFtp->downloadImageFile(MaterialPurchaseApplyItem.m_sImagePath);
		progressDialog->exec();
		QEventLoop eventloop;
		QTimer::singleShot(50, &eventloop, SLOT(quit()));
		eventloop.exec();
	}
	m_imgCurrentImage = QImage(sfileName);
	setPreviewImage(QImage(sfileName));
	m_imgMaterial = QImage(sfileName);

	//setPreviewImage(MaterialPurchaseApplyItem.m_Image);
	//m_imgMaterial = MaterialPurchaseApplyItem.m_Image;
	QList<sUrielMaterialDeviceItem> MaterialDeviceList;
	m_pDatabase->getAllMaterialDeviceListByApplicationNumber(MaterialDeviceList, m_szApplicationNumber);
	if (MaterialDeviceList.size() > 0)
		setTable(MaterialDeviceList[0], ui.SerialNumberLineEdit_1, ui.DeviceNameLineEdit_1,
			ui.ModelSpecificationLineEdit_1, ui.UnitLineEdit_1, ui.NumberLineEdit_1,
			ui.UnitPriceLineEdit_1, ui.TotalLineEdit_1);
	if (MaterialDeviceList.size() > 1)
		setTable(MaterialDeviceList[1], ui.SerialNumberLineEdit_2, ui.DeviceNameLineEdit_2,
			ui.ModelSpecificationLineEdit_2, ui.UnitLineEdit_2, ui.NumberLineEdit_2,
			ui.UnitPriceLineEdit_2, ui.TotalLineEdit_2);
	if (MaterialDeviceList.size() > 2)
		setTable(MaterialDeviceList[2], ui.SerialNumberLineEdit_3, ui.DeviceNameLineEdit_3,
			ui.ModelSpecificationLineEdit_3, ui.UnitLineEdit_3, ui.NumberLineEdit_3,
			ui.UnitPriceLineEdit_3, ui.TotalLineEdit_3);
	if (MaterialDeviceList.size() > 3)
		setTable(MaterialDeviceList[3], ui.SerialNumberLineEdit_4, ui.DeviceNameLineEdit_4,
			ui.ModelSpecificationLineEdit_4, ui.UnitLineEdit_4, ui.NumberLineEdit_4,
			ui.UnitPriceLineEdit_4, ui.TotalLineEdit_4);
	if (MaterialDeviceList.size() > 4)
		setTable(MaterialDeviceList[4], ui.SerialNumberLineEdit_5, ui.DeviceNameLineEdit_5,
			ui.ModelSpecificationLineEdit_5, ui.UnitLineEdit_5, ui.NumberLineEdit_5,
			ui.UnitPriceLineEdit_5, ui.TotalLineEdit_5);
	if (MaterialDeviceList.size() > 5)
		setTable(MaterialDeviceList[5], ui.SerialNumberLineEdit_6, ui.DeviceNameLineEdit_6,
			ui.ModelSpecificationLineEdit_6, ui.UnitLineEdit_6, ui.NumberLineEdit_6,
			ui.UnitPriceLineEdit_6, ui.TotalLineEdit_6);
	ui.ReviewerLabel->setText(m_pOptions->getAccount());
	ui.ReviewTimeDateEdit->setDateTime(QDateTime::currentDateTime());

}

void MaterialPurchaseApplyTable::setPreviewImage(const QImage & image)
{

	ui.ImageLabel->setScaledContents(false);
	int height, width;

	width = ui.ImageLabel->geometry().width();
	if ((image.width() / (double)image.height() * ui.ImageLabel->geometry().height()) > ui.ImageLabel->geometry().width())
	{
		width = ui.ImageLabel->geometry().width();
		height = image.height() / (double)image.width() * ui.ImageLabel->geometry().width();
	}
	else
	{
		width = image.width() / (double)image.height() * ui.ImageLabel->geometry().height();
		height = ui.ImageLabel->geometry().height();
	}
	ui.ImageLabel->setPixmap(QPixmap::fromImage(image.scaled(width, height)));
}

void MaterialPurchaseApplyTable::setSignalsAndSlots()
{
	QObject::connect(ui.AppClose, &QToolButton::clicked, this, &MaterialPurchaseApplyTable::close);
	QObject::connect(ui.ConfirmPassBtn, &QToolButton::clicked, this, &MaterialPurchaseApplyTable::onConfirmPassBtnClicked);
	QObject::connect(ui.ConfirmRejectBtn, &QToolButton::clicked, this, &MaterialPurchaseApplyTable::onConfirmRejectBtnClicked);
	QObject::connect(ui.AddImageBtn, &QToolButton::clicked, this, &MaterialPurchaseApplyTable::onAddImageBtnClicked);
	QObject::connect(ui.LookImageBtn, &QToolButton::clicked, this, &MaterialPurchaseApplyTable::onLookImageBtnClicked);
	QObject::connect(ui.DeleteImageBtn, &QToolButton::clicked, this, &MaterialPurchaseApplyTable::onDeleteImageBtnClicked);
}

void MaterialPurchaseApplyTable::onConfirmPassBtnClicked() {
	InformationDialog information(QStringLiteral("信息"), QStringLiteral("确定通过！"), this);
	if (information.exec() == QDialog::Accepted) {
		int id = m_pDatabase->getMaterialPurchaseApplyIdByApplicationNumber(m_szApplicationNumber);
		m_pDatabase->auditedMaterialPurchaseApply(QString::number(id), m_pOptions->getAccount(), MaterialPurchaseApplyStatus::Aduited, ui.AuditOpinionPlainTextEdit->toPlainText());
		m_pDatabase->updateMaterialPurchaseApplyTableMode();
		accept();
	}

}
void MaterialPurchaseApplyTable::onConfirmRejectBtnClicked() {
	InformationDialog information(QStringLiteral("信息"), QStringLiteral("确定拒绝！"), this);
	if (information.exec() == QDialog::Accepted) {
		int id = m_pDatabase->getMaterialPurchaseApplyIdByApplicationNumber(m_szApplicationNumber);
		m_pDatabase->auditedMaterialPurchaseApply(QString::number(id), m_pOptions->getAccount(), MaterialPurchaseApplyStatus::Rejected, ui.AuditOpinionPlainTextEdit->toPlainText());
		m_pDatabase->updateMaterialPurchaseApplyTableMode();
		accept();
	}
}
#include <QFileDialog>
void MaterialPurchaseApplyTable::onAddImageBtnClicked() {
	ui.ImageLabel->setScaledContents(false);
	m_sMaterialPurchaseApplyImagePath = QFileDialog::getOpenFileName(
		this, QStringLiteral("请选择图片"),
		QCoreApplication::applicationDirPath(),
		tr("All Files (*);;PNG File (*.png);;JPG Files (*.jpg);;JPGE Files (*.jpge);;BMP Files (*.bmp)"));
	if (!m_sMaterialPurchaseApplyImagePath.isEmpty())
	{
		setPreviewImage(QImage(m_sMaterialPurchaseApplyImagePath));
	}
	m_imgCurrentImage = QImage(m_sMaterialPurchaseApplyImagePath);
}
void MaterialPurchaseApplyTable::onLookImageBtnClicked() {
	UrielImageViewer imageViewer(m_pParent);
	if (!m_imgCurrentImage.isNull())
		imageViewer.setImage(m_imgCurrentImage/*QImage(m_sMaterialPurchaseApplyImagePath)*/);
	imageViewer.exec();
}
void MaterialPurchaseApplyTable::onDeleteImageBtnClicked() {
	ui.ImageLabel->setScaledContents(true);
	ui.ImageLabel->setPixmap(QPixmap(""));
}

