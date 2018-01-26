#pragma once

#include <QDialog>
#include "ui_InputDialog.h"

class InputDialog : public QDialog
{
	Q_OBJECT

public:
	InputDialog(const QString & title,QWidget *parent = Q_NULLPTR);
	~InputDialog();
signals:
	void contentSignal(const QString & content);
private:
	void initializeUI(QWidget *parent = Q_NULLPTR);
	void setSignalsAndSlots();

private:
	Ui::InputDialog ui;
};
