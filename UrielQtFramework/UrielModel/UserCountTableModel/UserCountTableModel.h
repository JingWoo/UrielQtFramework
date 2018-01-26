#pragma once

#include <QObject>
#include <QSqlQueryModel>
#include <QStringList>
class UrielUserCountTableModel : public QSqlQueryModel
{
	Q_OBJECT

public:
	UrielUserCountTableModel(QString strQuery, QStringList hlist, QSqlDatabase&db, QObject *parent = nullptr);
	~UrielUserCountTableModel();

public:
	QVariant data(const QModelIndex &item, int role) const;
private:
	QString m_strQuery;
	QStringList m_cHeaderList;

};
