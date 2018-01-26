#pragma once

#include <QDialog>
#include "ui_SmallInvoice.h"
#include "UrielDefinition\UrielDefinition.h"
QT_FORWARD_DECLARE_CLASS(UrielDatabase)
QT_FORWARD_DECLARE_CLASS(UrielQtFrameworkOptions)
class SmallInvoice : public QDialog
{
	Q_OBJECT

public:
	SmallInvoice(UrielDatabase * database, UrielQtFrameworkOptions *option, QWidget *parent = Q_NULLPTR);
	~SmallInvoice();
	void setReimburseCodeAndInvoiceType(const QString & Code, const QString & type);
private:
	void initializeUI(QWidget *parent = Q_NULLPTR);
	void setSignalsAndSlots();
	private slots:
	void onLocalTransportationTBtnClicked();
	void onMailingFeeTBtnClicked();
	void onOtherTBtnClicked();
	void onStatisticsTBtnClicked();
	void onConfirmTBtnClicked();
	void onAmountEditingFinished();
	void onAmount_2EditingFinished();
	void onAmount_3EditingFinished();
	void onAmount_4EditingFinished();
	void onAmount_5EditingFinished();
	void onAmount_6EditingFinished();
	void onAmount_7EditingFinished();
	void onAmount_8EditingFinished();
	void onAmount_9EditingFinished();
	void onAmount_10EditingFinished();
	void onAmount_11EditingFinished();
	void onAmount_12EditingFinished();
	void onAmount_13EditingFinished();
	void onAmount_14EditingFinished();
	void onAmount_15EditingFinished();
	void onAmount_16EditingFinished();
private:
	Ui::SmallInvoice ui;
	UrielDatabase *m_database{ nullptr };
	UrielQtFrameworkOptions *m_options{ nullptr };
	QString m_InvoiceType;
	QString m_sReimburseCode;
	sUrielInvoiceInfoItem m_stInvoiceInfoItem;
};
