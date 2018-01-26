#pragma once

#include <QDialog>
#include "ui_InformationDialog.h"

class InformationDialog : public QDialog
{
	Q_OBJECT

public:
	InformationDialog(const QString & title,const QString & content,QWidget *parent = Q_NULLPTR);
	~InformationDialog();
	private slots:
	void onSureClicked();
	void onCancelClicked();
private:
	void initializeUI(QWidget *parent = Q_NULLPTR);
	void setSignalsAndSlots();
private:
	Ui::InformationDialog ui;
};
