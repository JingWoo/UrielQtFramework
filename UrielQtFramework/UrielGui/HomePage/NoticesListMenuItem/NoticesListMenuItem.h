#pragma once

#include <QWidget>
#include "ui_NoticesListMenuItem.h"
#include "UrielDefinition/UrielDefinition.h"

class NoticesListMenuItem : public QWidget
{
	Q_OBJECT

public:
	NoticesListMenuItem(QWidget *parent = Q_NULLPTR);
	~NoticesListMenuItem();
	void setNoticesListMenuItemContent(const sUrielNotificationsMenuItem & item);
signals:
	void NoticeCodeSignal(const QString & code);
protected:
	virtual void mousePressEvent(QMouseEvent *event) override;

private:
	Ui::NoticesListMenuItem ui;
	sUrielNotificationsMenuItem m_NotificationsMenuItem;
};
