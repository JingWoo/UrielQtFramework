#pragma once

#include <QDialog>
#include "ui_ResearchProject.h"
QT_FORWARD_DECLARE_CLASS(UrielDatabase)
QT_FORWARD_DECLARE_CLASS(UrielQtFrameworkOptions)
#include "UrielDefinition\UrielDefinition.h"
class ResearchProject : public QDialog
{
	Q_OBJECT

public:
	ResearchProject(UrielDatabase * database, UrielQtFrameworkOptions *option, QWidget *parent = Q_NULLPTR);
	~ResearchProject();
	void openWithEditMode(const sUrielResearchProjectItem & item);
private:
	void initializeUI(QWidget *parent = Q_NULLPTR);
	void setSignalsAndSlots();

	private slots:
	void onConfirmClicked();
	void onDataFileBrowerClicked();
	void onPaperFileBrowerClicked();

private:
	Ui::ResearchProject ui;
	UrielDatabase *m_database{ nullptr };
	UrielQtFrameworkOptions *m_options{ nullptr };
	bool m_bIsEditMode{ false };
	bool m_bResearchProjectDataChange{ false };
	bool m_bResearchProjectPaperChange{ false };
	sUrielResearchProjectItem m_stResearchProject;
	QString m_sLoaclDataFilePaths{ "" };
	QString m_sRemoteDataFilePaths{ "" };
	QString m_sLoaclPaperFilePaths{ "" };
	QString m_sRemotePaperFilePaths{ "" };
};
