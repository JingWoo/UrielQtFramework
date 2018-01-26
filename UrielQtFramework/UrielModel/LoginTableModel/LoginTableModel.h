#pragma once
#include <QObject>
#include <QSqlQueryModel>
#include <QStringList>
class UrielLoginTableModel : public QSqlQueryModel
{
	Q_OBJECT

public:
	UrielLoginTableModel(QString strQuery, QStringList hlist, QSqlDatabase&db, QObject *parent = nullptr);
	~UrielLoginTableModel();

public:
	QVariant data(const QModelIndex &item, int role) const;
private:
	QString m_strQuery;
	QStringList m_cHeaderList;

};
