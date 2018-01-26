#ifndef _WorksTableModel_H_
#define _WorksTableModel_H_

#include <QStringList>
#include <QSqlQueryModel>

class UrielWorksTableModel :public QSqlQueryModel
{
	Q_OBJECT
public:
	UrielWorksTableModel(QString strQuery, QStringList hlist, QSqlDatabase&db, QObject *parent = 0);
	~UrielWorksTableModel();

public:
	QVariant data(const QModelIndex &item, int role) const;
private:
	QString m_strQuery;
	QStringList m_cHeaderList;
};
#endif /*WorksTableModel*/

