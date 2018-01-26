#pragma once

#include <QDialog>
#include <QNetworkAccessManager>  
#include <QUrl>  
#include <QNetworkRequest>  
#include <QNetworkReply>  

#include "ui_InvoiceInfo.h"
QT_FORWARD_DECLARE_CLASS(UrielDatabase)
QT_FORWARD_DECLARE_CLASS(UrielQtFrameworkOptions)
QT_FORWARD_DECLARE_CLASS(UrielNetworkAccessManager)
#include "UrielDefinition\UrielDefinition.h"
class InvoiceInfo : public QDialog
{
	Q_OBJECT

public:
	InvoiceInfo(UrielDatabase * database, UrielQtFrameworkOptions *option, QWidget *parent = Q_NULLPTR);
	~InvoiceInfo();
	void setInvoiceInfoItem(const sUrielInvoiceInfoItem& item);
	void setReimburseCodeAndInvoiceType(const QString & Code, const QString & type);
signals:
	void transferFinish();
	private slots:
	void onCalculateClicked();
	void onCancelClicked();
	void onOKClicked();
	void onAddInvoiceImageClicked();
	void onPreviewInvoiceImageClicked();
	void onOKDeleteInvoiceImageClicked();
	void onAddBuyScreenshotClicked();
	void onPreviewBuyScreenshotClicked();
	void onOKDeleteBuyScreenshotClicked();
	void onAddVerificationImageClicked();
	void onPreviewVerificationImageClicked();
	void onOKDeleteVerificationImageClicked();
	void onUpdateDataTransferProgressSlot(qint64, qint64);
	void onTransferFinished(QNetworkReply* reply);
private:
	void initializeUI(QWidget *parent = Q_NULLPTR);
	void setSignalsAndSlots();
	void setInvoiceImage();
	void setBuyScreenshot();
	void setVerificationImage();
private:
	Ui::InvoiceInfo ui;
	UrielDatabase *m_database{ nullptr };
	UrielQtFrameworkOptions *m_options{ nullptr };
	QWidget * m_pParent{ nullptr };
	QImage m_TempImage;
	QImage m_InvoiceImage;
	QImage m_BuyScreenshot;
	QImage m_VerificationImage;
	QString m_sInvoiceImageLocalPath{ "" };
	QString m_sBuyScreenshotLocalPath{ "" };
	QString m_sVerificationImageLocalPath{ "" };

	QString m_sInvoiceImageRemotePath{ "" };
	QString m_sBuyScreenshotRemotePath{ "" };
	QString m_sVerificationImageRemotePath{ "" };

	QString m_InvoiceType;
	QString m_sReimburseCode;

	QNetworkAccessManager *manager;
	//QNetworkReply *reply;

	UrielNetworkAccessManager *m_pUrielNetworkAccessManager{ nullptr };

	bool isEditMode{ false };
	bool isInvoiceImageChange{ false };
	bool isBuyScreenshotChange{ false };
	bool isVerificationImageChange{ false };
	sUrielInvoiceInfoItem m_stInvoiceInfoItem;

};
