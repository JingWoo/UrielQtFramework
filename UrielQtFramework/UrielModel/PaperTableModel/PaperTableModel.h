#pragma once

#include <QObject>
#include <QSqlQueryModel>
#include <QStringList>
class UrielPaperTableModel : public QSqlQueryModel
{
	Q_OBJECT

public:
	UrielPaperTableModel(QString strQuery, QStringList hlist, QSqlDatabase&db, QObject *parent = nullptr);
	~UrielPaperTableModel();

public:
	QVariant data(const QModelIndex &item, int role) const;
private:
	QString m_strQuery;
	QStringList m_cHeaderList;

};
