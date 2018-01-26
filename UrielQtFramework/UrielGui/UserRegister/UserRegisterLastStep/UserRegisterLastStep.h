#pragma once

#include <QDialog>
#include "ui_UserRegisterLastStep.h"

class UserRegisterLastStep : public QDialog
{
	Q_OBJECT

public:
	UserRegisterLastStep(QWidget *parent = Q_NULLPTR);
	~UserRegisterLastStep();
protected:
	virtual void mouseMoveEvent(QMouseEvent *event) override;
	virtual void mousePressEvent(QMouseEvent *event) override;
	virtual void mouseReleaseEvent(QMouseEvent *event) override;

private:
	Ui::UserRegisterLastStep ui;
	bool m_bPressed{ false };
	QPoint m_point;
};
