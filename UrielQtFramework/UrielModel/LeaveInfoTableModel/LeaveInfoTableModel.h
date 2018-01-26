#pragma once
#include <QObject>
#include <QSqlQueryModel>
#include <QStringList>
class UrielLeaveInfoTableModel : public QSqlQueryModel
{
	Q_OBJECT

public:
	UrielLeaveInfoTableModel(QString strQuery, QStringList hlist, QSqlDatabase&db, QObject *parent = nullptr);
	~UrielLeaveInfoTableModel();

public:
	QVariant data(const QModelIndex &item, int role) const;
private:
	QString m_strQuery;
	QStringList m_cHeaderList;

};
