#pragma once

#include <QDialog>
#include "ui_ExpenseItem.h"
#include "UrielDefinition\UrielDefinition.h"
class ExpenseItem : public QDialog
{
	Q_OBJECT

public:
	ExpenseItem(QPoint point, QWidget *parent = Q_NULLPTR);
	~ExpenseItem();
signals:
	void expenseItemSignal(const ExpenseItemEnum & v);
private:
	void initializeUI(QPoint point);
	void setSignalsAndSlots();
private:
	Ui::ExpenseItem ui;
};
