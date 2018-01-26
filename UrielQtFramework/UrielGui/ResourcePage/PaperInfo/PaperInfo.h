#pragma once

#include <QDialog>
#include "ui_PaperInfo.h"
QT_FORWARD_DECLARE_CLASS(UrielDatabase)
QT_FORWARD_DECLARE_CLASS(UrielQtFrameworkOptions)
#include "UrielDefinition\UrielDefinition.h"
class PaperInfo : public QDialog
{
	Q_OBJECT

public:
	PaperInfo(UrielDatabase * database, UrielQtFrameworkOptions *option, QWidget *parent = Q_NULLPTR);
	~PaperInfo();
	void openWithEditMode(const sUrielPaperItem & item);
private:
	void initializeUI(QWidget *parent = Q_NULLPTR);
	void setSignalsAndSlots();

	private slots:
	void onPaperFileBrowerClicked();
	void onConfirmClicked();

private:
	Ui::PaperInfo ui;
	UrielDatabase *m_database{ nullptr };
	UrielQtFrameworkOptions *m_options{ nullptr };
	bool m_bIsEditMode{ false };
	bool m_bPaperChange{ false };
	sUrielPaperItem m_stPaperInfo;
	QString m_sLoaclFilePaths{ "" };
	QString m_sRemoteFilePaths{ "" };
};
