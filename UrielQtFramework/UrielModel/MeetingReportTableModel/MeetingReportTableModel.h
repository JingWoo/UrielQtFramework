#ifndef _MeetingReportTableModel_H_
#define _MeetingReportTableModel_H_

#include <QStringList>
#include <QSqlQueryModel>

class UrielMeetingReportTableModel :public QSqlQueryModel
{
	Q_OBJECT
public:
	UrielMeetingReportTableModel(QString strQuery, QStringList hlist, QSqlDatabase&db, QObject *parent = 0);
	~UrielMeetingReportTableModel();

public:
	QVariant data(const QModelIndex &item, int role) const;
private:
	QString m_strQuery;
	QStringList m_cHeaderList;
};
#endif /*_MeetingReportTableModel_H_*/

