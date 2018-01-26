#ifndef _AcademicConferenceTableModel_H_
#define _AcademicConferenceTableModel_H_

#include <QStringList>
#include <QSqlQueryModel>

class UrielAcademicConferenceTableModel :public QSqlQueryModel
{
	Q_OBJECT
public:
	UrielAcademicConferenceTableModel(QString strQuery, QStringList hlist, QSqlDatabase&db, QObject *parent = 0);
	~UrielAcademicConferenceTableModel();

public:
	QVariant data(const QModelIndex &item, int role) const;
private:
	QString m_strQuery;
	QStringList m_cHeaderList;
};
#endif /*AcademicConferenceTableModel*/

