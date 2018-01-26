#pragma once

#include <QDialog>
#include "ui_AcademicConferenceInfo.h"
QT_FORWARD_DECLARE_CLASS(UrielDatabase)
QT_FORWARD_DECLARE_CLASS(UrielQtFrameworkOptions)
#include "UrielDefinition\UrielDefinition.h"
class AcademicConferenceInfo : public QDialog
{
	Q_OBJECT

public:
	AcademicConferenceInfo(UrielDatabase * database, UrielQtFrameworkOptions *option, QWidget *parent = Q_NULLPTR);
	~AcademicConferenceInfo();
	void openWithEditMode(const sUrielAcademicConferenceItem & item);
private:
	void initializeUI(QWidget *parent = Q_NULLPTR);
	void setSignalsAndSlots();

	private slots:
	void onFileBrowerClicked();
	void onConfirmClicked();

private:
	Ui::AcademicConferenceInfo ui;
	UrielDatabase *m_database{ nullptr };
	UrielQtFrameworkOptions *m_options{ nullptr };
	bool m_bIsEditMode{ false };
	bool m_bAcademicConferenceChange{ false };
	sUrielAcademicConferenceItem m_stAcademicConferenceInfo;
	QString m_sLoaclFilePaths{ "" };
	QString m_sRemoteFilePaths{ "" };
};
