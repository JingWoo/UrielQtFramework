#pragma once

#include <QDialog>
#include "ui_ProgressDialog.h"

class ProgressDialog : public QDialog
{
	Q_OBJECT

public:
	ProgressDialog(QWidget *parent = Q_NULLPTR);
	~ProgressDialog();
	void setTotalProgressBarMax(qint64 total=1);
	void setCurrentTotalValue(qint64 total);
public slots:
	void updateProgressBarValue(qint64 read, qint64 total);
private:
	void initializeUI(QWidget *parent = Q_NULLPTR);
	void setSignalsAndSlots();

private:
	Ui::ProgressDialog ui;
	qint64 m_iRead{ 100 };
	qint64 m_iTotal{ 1 };
};
