#pragma once

#include <QWidget>
#include "ui_PatentInfo.h"
QT_FORWARD_DECLARE_CLASS(UrielDatabase)
QT_FORWARD_DECLARE_CLASS(UrielQtFrameworkOptions)
#include "UrielDefinition\UrielDefinition.h"
class PatentInfo : public QDialog
{
	Q_OBJECT

public:
	PatentInfo(UrielDatabase * database, UrielQtFrameworkOptions *option, QWidget *parent = Q_NULLPTR);
	~PatentInfo();
	void openWithEditMode(const sUrielPatentItem & item);
private:
	void initializeUI(QWidget *parent = Q_NULLPTR);
	void setSignalsAndSlots();

	private slots:
	void onFileBrowerClicked();
	void onConfirmClicked();
private:
	Ui::PatentInfo ui;
	UrielDatabase *m_database{ nullptr };
	UrielQtFrameworkOptions *m_options{ nullptr };
	bool m_bIsEditMode{ false };
	bool m_bPatentChange{ false };
	sUrielPatentItem m_stPatentInfo;
	QString m_sLoaclFilePaths{ "" };
	QString m_sRemoteFilePaths{ "" };
};
