#pragma once

#include <QDialog>
#include "ui_ReleasingNotices.h"
QT_FORWARD_DECLARE_CLASS(UrielDatabase)
QT_FORWARD_DECLARE_CLASS(UrielQtFrameworkOptions)
#include "UrielDefinition\UrielDefinition.h"
class ReleasingNotices : public QDialog
{
	Q_OBJECT

public:
	ReleasingNotices(UrielDatabase * database, UrielQtFrameworkOptions *option, QWidget *parent = Q_NULLPTR);
	~ReleasingNotices();
	void openWithEditMode(const sUrielNotificationsItem & item);
	private slots:
	void onNoticeFileBrowerClicked();
	void onConfirmReleaseNoticeClicked();
private:
	void initializeUI(QWidget *parent = Q_NULLPTR);
	void setSignalsAndSlots();

protected:
	virtual void paintEvent(QPaintEvent*) override;



private:
	Ui::ReleasingNotices ui;
	UrielDatabase *m_database{ nullptr };
	UrielQtFrameworkOptions *m_options{ nullptr };
	QString m_sLoaclFilePaths{""};
	QString m_sRemoteFilePaths{ "" };
	bool m_bIsEditMode{ false };
};
