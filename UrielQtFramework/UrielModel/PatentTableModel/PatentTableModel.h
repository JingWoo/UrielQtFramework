#ifndef _PatentTableModel_H_
#define _PatentTableModel_H_

#include <QStringList>
#include <QSqlQueryModel>

class UrielPatentTableModel :public QSqlQueryModel
{
	Q_OBJECT
public:
	UrielPatentTableModel(QString strQuery, QStringList hlist, QSqlDatabase&db, QObject *parent = 0);
	~UrielPatentTableModel();

public:
	QVariant data(const QModelIndex &item, int role) const;
private:
	QString m_strQuery;
	QStringList m_cHeaderList;
};
#endif /*PatentTableModel*/

