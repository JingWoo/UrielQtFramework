#pragma once

#include <QDialog>
#include "ui_InstrumentBorrowReturn.h"
#include "UrielDefinition\UrielDefinition.h"
QT_FORWARD_DECLARE_CLASS(UrielDatabase)
class InstrumentBorrowReturn : public QDialog
{
	Q_OBJECT

public:
	InstrumentBorrowReturn(UrielDatabase * database, QWidget *parent = Q_NULLPTR);
	~InstrumentBorrowReturn();
	void setSomeInfo(const sUrielInstrumentItem &InstrumentItem);
	void setValueInViewModel(const sUrielInstrumentUseLog & item);
	private slots:
	void onConfirmOperationClicked();
private:
	void initializeUI(QWidget *parent = Q_NULLPTR);
	void setSignalsAndSlots();
private:
	Ui::InstrumentBorrowReturn ui;
	UrielDatabase *m_database{ nullptr };
	sUrielInstrumentUseLog m_stUrielInstrumentUseLog;
};
