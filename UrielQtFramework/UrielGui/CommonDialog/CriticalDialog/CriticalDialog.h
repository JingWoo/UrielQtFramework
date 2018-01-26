#pragma once

#include <QDialog>
#include "ui_CriticalDialog.h"

class CriticalDialog : public QDialog
{
	Q_OBJECT

public:
	CriticalDialog(const QString & title, const QString & content, QWidget *parent = Q_NULLPTR);
	~CriticalDialog();
	private slots:
	void onSureClicked();
	void onCancelClicked();
private:
	void initializeUI(QWidget *parent = Q_NULLPTR);
	void setSignalsAndSlots();
private:
	Ui::CriticalDialog ui;
};
