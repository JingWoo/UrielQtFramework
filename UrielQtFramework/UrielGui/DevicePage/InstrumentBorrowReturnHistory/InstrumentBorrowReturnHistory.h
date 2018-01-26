#pragma once
#include <QDialog>
#include "ui_InstrumentBorrowReturnHistory.h"
QT_FORWARD_DECLARE_CLASS(UrielDatabase)
QT_FORWARD_DECLARE_CLASS(UrielInstrumentBorrowReturnHistoryTableModel)
QT_FORWARD_DECLARE_CLASS(QSortFilterProxyModel)
QT_FORWARD_DECLARE_CLASS(InstrumentBorrowReturn)
class InstrumentBorrowReturnHistory : public QDialog
{
	Q_OBJECT

public:
	InstrumentBorrowReturnHistory(UrielDatabase * database, const QString & id, QWidget *parent = Q_NULLPTR);
	~InstrumentBorrowReturnHistory();
	private slots:
	void onViewDetailActionTriggered();
	void onCurrentInstrumentActionTriggered();
	void onAllInstrumentActionTriggered();
	void onInstrumentBorrowReturnHistoryItemPressed(const QModelIndex &);
private:
	void initializeUI(QWidget *parent = Q_NULLPTR);
	void setSignalsAndSlots();
private:
	Ui::InstrumentBorrowReturnHistory ui;
	UrielDatabase *m_database{ nullptr };
	UrielInstrumentBorrowReturnHistoryTableModel *m_pUrielInstrumentBorrowReturnHistoryTableModel{ nullptr };
	QSortFilterProxyModel *m_pUrielInstrumentBorrowReturnHistoryTableSortFilterModel{ nullptr };
	QString m_sInstrumemtId;
	InstrumentBorrowReturn * m_pInstrumentBorrowReturnDialog{ nullptr };
};
