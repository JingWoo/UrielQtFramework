#pragma once

#include <QDialog>
#include "ui_UserRegisterSecondStep.h"
#include "UrielDefinition\UrielDefinition.h"
QT_FORWARD_DECLARE_CLASS(UrielDatabase)
class UserRegisterSecondStep : public QDialog
{
	Q_OBJECT

public:
	UserRegisterSecondStep(UrielDatabase * database, QWidget *parent = Q_NULLPTR);
	~UserRegisterSecondStep();
protected:
	virtual void mouseMoveEvent(QMouseEvent *event) override;
	virtual void mousePressEvent(QMouseEvent *event) override;
	virtual void mouseReleaseEvent(QMouseEvent *event) override;

private:
	Ui::UserRegisterSecondStep ui;
	UrielDatabase *m_databse{ nullptr };
	bool m_bPressed{ false };
	QPoint m_point;
	sUrielAccountInfo m_sAcountInfo;
};
