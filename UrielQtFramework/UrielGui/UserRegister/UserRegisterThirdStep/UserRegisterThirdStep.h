#pragma once

#include <QDialog>
#include "ui_UserRegisterThirdStep.h"
#include "UrielDefinition\UrielDefinition.h"
QT_FORWARD_DECLARE_CLASS(UrielDatabase)
class UserRegisterThirdStep : public QDialog
{
	Q_OBJECT

public:
	UserRegisterThirdStep(const sUrielAccountInfo & m_sAcountInfo ,UrielDatabase * database, QWidget *parent = Q_NULLPTR);
	~UserRegisterThirdStep();
	QString sName;
	QString sID;
	QString sPhone;
	QString sEmail;

protected:
	virtual void mouseMoveEvent(QMouseEvent *event) override;
	virtual void mousePressEvent(QMouseEvent *event) override;
	virtual void mouseReleaseEvent(QMouseEvent *event) override;

private:
	Ui::UserRegisterThirdStep ui;
	UrielDatabase *m_databse{ nullptr };
	bool m_bPressed{ false };
	QPoint m_point;
	sUrielAccountInfo m_sAcountInfo;
};
