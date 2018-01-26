#pragma once

#include <QObject>
#include <QSqlQueryModel>
#include <QStringList>
class UrielCheckInTableModel : public QSqlQueryModel
{
	Q_OBJECT

public:
	UrielCheckInTableModel(QString strQuery, QStringList hlist, QSqlDatabase&db, QObject *parent = nullptr);
	~UrielCheckInTableModel();

public:
	QVariant data(const QModelIndex &item, int role) const;
private:
	QString m_strQuery;
	QStringList m_cHeaderList;

};
