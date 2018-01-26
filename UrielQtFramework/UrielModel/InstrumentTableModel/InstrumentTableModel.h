#pragma once

#include <QObject>
#include <QSqlQueryModel>
#include <QStringList>
class UrielInstrumentTableModel : public QSqlQueryModel
{
	Q_OBJECT

public:
	UrielInstrumentTableModel(QString strQuery, QStringList hlist, QSqlDatabase&db, QObject *parent=nullptr);
	~UrielInstrumentTableModel();

public:
	QVariant data(const QModelIndex &item, int role) const;
private:
	QString m_strQuery;
	QStringList m_cHeaderList;

};
