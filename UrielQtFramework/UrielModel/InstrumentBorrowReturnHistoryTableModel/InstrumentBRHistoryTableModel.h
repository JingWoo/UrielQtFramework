#pragma once

#include <QObject>
#include <QSqlQueryModel>
#include <QStringList>
class UrielInstrumentBorrowReturnHistoryTableModel : public QSqlQueryModel
{
	Q_OBJECT

public:
	UrielInstrumentBorrowReturnHistoryTableModel(QString strQuery, QStringList hlist, QSqlDatabase&db, QObject *parent = nullptr);
	~UrielInstrumentBorrowReturnHistoryTableModel();

public:
	QVariant data(const QModelIndex &item, int role) const;
private:
	QString m_strQuery;
	QStringList m_cHeaderList;

};
