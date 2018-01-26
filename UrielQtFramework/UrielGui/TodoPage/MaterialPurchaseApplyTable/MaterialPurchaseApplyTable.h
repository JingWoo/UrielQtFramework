#pragma once

#include <QDialog>
#include "ui_MaterialPurchaseApplyTable.h"
QT_FORWARD_DECLARE_CLASS(UrielDatabase)
QT_FORWARD_DECLARE_CLASS(UrielQtFrameworkOptions)
#include "UrielDefinition\UrielDefinition.h"

class MaterialPurchaseApplyTable : public QDialog
{
	Q_OBJECT

public:
	MaterialPurchaseApplyTable(UrielDatabase * database, UrielQtFrameworkOptions *option, const QString & ApplicationNumber, QWidget *parent = Q_NULLPTR);
	~MaterialPurchaseApplyTable();
	private slots:
	void onConfirmPassBtnClicked();
	void onConfirmRejectBtnClicked();
	void onAddImageBtnClicked();
	void onLookImageBtnClicked();
	void onDeleteImageBtnClicked();
private:
	void initializeUI(QWidget *parent = Q_NULLPTR);
	void setSignalsAndSlots();
	void setPreviewImage(const QImage & image);
	void setTable(const sUrielMaterialDeviceItem & item, QLineEdit * SerialNumber, QLineEdit * DeviceName, QLineEdit * ModelSpecification,
		QLineEdit * Unit, QLineEdit * Number, QLineEdit * UnitPrice, QLineEdit * Total);

private:
	Ui::MaterialPurchaseApplyTable ui;
	UrielDatabase *m_pDatabase{ nullptr };
	UrielQtFrameworkOptions *m_pOptions{ nullptr };
	QString m_szApplicationNumber;
	QImage m_imgMaterial;
	QString m_sMaterialPurchaseApplyImagePath;
	QImage m_imgCurrentImage;
	QWidget *m_pParent{ nullptr };
};
