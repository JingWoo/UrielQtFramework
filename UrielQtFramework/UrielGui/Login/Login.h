#pragma once

#include <QDialog>
#include "ui_Login.h"
#if QT_VERSION >= 0x50000
#include <QtWidgets>
#else
#include <QtGui>
#endif


QT_FORWARD_DECLARE_CLASS(UrielDatabase)
QT_FORWARD_DECLARE_CLASS(UrielQtFrameworkOptions)

class Login : public QDialog
{
	Q_OBJECT

public:
	Login(UrielDatabase * database, UrielQtFrameworkOptions * options, QWidget *parent = Q_NULLPTR);
	~Login();

	void setLoginErrorShow( bool b,const QString & str="" );
protected:
	virtual void mouseMoveEvent(QMouseEvent *event) override;
	virtual void mousePressEvent(QMouseEvent *event) override;
	virtual void mouseReleaseEvent(QMouseEvent *event) override;

private:
	void initializeUI();
	void setSignalsAndSlots();

private slots:
	void onAppCloseClicked();
	void onRememberPasswordClicked();
	void onAutoLoginClicked();
	void onConfirmLoginClicked();
	void onRegisterAccountClicked();
	void onFindPasswordClicked();
	void onAccountEditingFinished();

private:
	Ui::Login ui;
	UrielDatabase *m_databse{ nullptr };
	UrielQtFrameworkOptions *m_options{ nullptr };
	bool m_bPressed{ false };
	QPoint m_point;
};
