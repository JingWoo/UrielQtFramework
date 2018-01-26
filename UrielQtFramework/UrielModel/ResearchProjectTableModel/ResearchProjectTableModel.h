#ifndef _ResearchProjectTableModel_H_
#define _ResearchProjectTableModel_H_

#include <QStringList>
#include <QSqlQueryModel>

class UrielResearchProjectTableModel :public QSqlQueryModel
{
	Q_OBJECT
public:
	UrielResearchProjectTableModel(QString strQuery, QStringList hlist, QSqlDatabase&db, QObject *parent = 0);
	~UrielResearchProjectTableModel();

public:
	QVariant data(const QModelIndex &item, int role) const;
private:
	QString m_strQuery;
	QStringList m_cHeaderList;
};
#endif /*ResearchProjectTableModel*/
