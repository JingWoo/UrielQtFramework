#pragma once

#include <QDialog>
#include "ui_UserInfo.h"
#include "UrielDefinition\UrielDefinition.h"
class UserInfo : public QDialog
{
	Q_OBJECT

public:
	UserInfo(QPoint point, QWidget *parent = Q_NULLPTR);
	~UserInfo();
	void setvalue(const sUrielAccountInfo &item);

private:
	void initializeUI(QPoint point);
	void setSignalsAndSlots();

private:
	Ui::UserInfo ui;
};
