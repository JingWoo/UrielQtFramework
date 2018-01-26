#pragma once

#include <QDialog>
#include "ui_InstrumentInfo.h"
#include "UrielDefinition\UrielDefinition.h"
QT_FORWARD_DECLARE_CLASS(UrielDatabase)
class InstrumentInfo : public QDialog
{
	Q_OBJECT

public:
	InstrumentInfo(UrielDatabase * database, QWidget *parent = Q_NULLPTR);
	~InstrumentInfo();
	void setValue(const sUrielInstrumentItem & item);
	
private slots:
	void onConfirmOperationClicked();
	void onChangeImageTBClicked();
	void onInstrumentSDKBrowerTBClicked();
	void onSDKDownLoadTBClicked();
private:
	void initializeUI(QWidget *parent = Q_NULLPTR);
	void setSignalsAndSlots();
private:
	Ui::InstrumentInfo ui;
	bool m_bIsEditMode{ false };
	sUrielInstrumentItem m_stUrielInstrumentItem;
	UrielDatabase *m_database{ nullptr };
	QString m_sRemoteFilePaths;
	QString m_sLoaclFilePaths;

	QString m_sRemoteImagePaths{ "" };
	QString m_sLoaclImagePaths{ "" };
	bool isImageChange{ false };
	bool isFileChange{ false };
};
