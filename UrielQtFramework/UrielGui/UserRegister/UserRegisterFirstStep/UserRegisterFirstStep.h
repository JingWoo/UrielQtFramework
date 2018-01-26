#pragma once

#include <QDialog>
#include "ui_UserRegisterFirstStep.h"

QT_FORWARD_DECLARE_CLASS(UrielDatabase)

class UserRegisterFirstStep : public QDialog
{
	Q_OBJECT

public:
	UserRegisterFirstStep(UrielDatabase * database, QWidget *parent = Q_NULLPTR);
	~UserRegisterFirstStep();

protected:
	virtual void mouseMoveEvent(QMouseEvent *event) override;
	virtual void mousePressEvent(QMouseEvent *event) override;
	virtual void mouseReleaseEvent(QMouseEvent *event) override;

private:
	Ui::UserRegisterFirstStep ui;
	UrielDatabase *m_databse{ nullptr };
	bool m_bPressed{ false };
	QPoint m_point;
};
