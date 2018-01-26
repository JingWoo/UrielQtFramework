#pragma once

#include <QDialog>
#include "ui_WorksInfo.h"
QT_FORWARD_DECLARE_CLASS(UrielDatabase)
QT_FORWARD_DECLARE_CLASS(UrielQtFrameworkOptions)
#include "UrielDefinition\UrielDefinition.h"
class WorksInfo : public QDialog
{
	Q_OBJECT

public:
	WorksInfo(UrielDatabase * database, UrielQtFrameworkOptions *option, QWidget *parent = Q_NULLPTR);
	~WorksInfo();
	void openWithEditMode(const sUrielWorksItem & item);
private:
	void initializeUI(QWidget *parent = Q_NULLPTR);
	void setSignalsAndSlots();

	private slots:
	void onFileBrowerClicked();
	void onConfirmClicked();
private:
	Ui::WorksInfo ui;
	UrielDatabase *m_database{ nullptr };
	UrielQtFrameworkOptions *m_options{ nullptr };
	bool m_bIsEditMode{ false };
	bool m_bWorksChange{ false };
	sUrielWorksItem m_stWorksInfo;
	QString m_sLoaclFilePaths{ "" };
	QString m_sRemoteFilePaths{ "" };
};
