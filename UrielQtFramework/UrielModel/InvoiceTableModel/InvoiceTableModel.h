#pragma once

#include <QObject>
#include <QSqlQueryModel>
#include <QStringList>
class UrielInvoiceTableModel : public QSqlQueryModel
{
	Q_OBJECT

public:
	UrielInvoiceTableModel(QString strQuery, QStringList hlist, QSqlDatabase&db, QObject *parent=nullptr);
	~UrielInvoiceTableModel();

public:
	QVariant data(const QModelIndex &item, int role) const;
private:
	QString m_strQuery;
	QStringList m_cHeaderList;

};
