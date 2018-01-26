#pragma once

#include <QDialog>
#include "ui_CashPaymentCertificate.h"

class CashPaymentCertificate : public QDialog
{
	Q_OBJECT

public:
	CashPaymentCertificate(QWidget *parent = Q_NULLPTR);
	~CashPaymentCertificate();

private:
	Ui::CashPaymentCertificate ui;
};
