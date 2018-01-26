#ifndef _NoticesMenuTableMode_H_
#define _NoticesMenuTableMode_H_

#include <QStringList>
#include <QSqlQueryModel>

class UrielNoticesMenuTableModel :public QSqlQueryModel
{
	Q_OBJECT
public:
	UrielNoticesMenuTableModel(QString strQuery, QStringList hlist, QSqlDatabase&db, QObject *parent = 0);
	~UrielNoticesMenuTableModel();

public:
	QVariant data(const QModelIndex &item, int role) const;
private:
	QString m_strQuery;
	QStringList m_cHeaderList;
};
#endif /*_NoticesMenuTableMode_H_*/

