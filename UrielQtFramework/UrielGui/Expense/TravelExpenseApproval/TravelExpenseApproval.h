#pragma once

#include <QDialog>
#include "ui_TravelExpenseApproval.h"

class TravelExpenseApproval : public QDialog
{
	Q_OBJECT

public:
	TravelExpenseApproval(QWidget *parent = Q_NULLPTR);
	~TravelExpenseApproval();

private:
	Ui::TravelExpenseApproval ui;
};
