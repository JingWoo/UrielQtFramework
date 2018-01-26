#include "UrielModel\MeetingReportTableModel\MeetingReportTableModel.h"
#include <QColor>
#include <QFont>
#include <QPixmap>
#include <QDateTime>
#include <QFileInfo>
UrielMeetingReportTableModel::UrielMeetingReportTableModel(QString strQuery, QStringList hlist, QSqlDatabase&db, QObject *parent)
	:QSqlQueryModel(parent)
{
	setQuery(strQuery, db);
	for (int i = 0; i < hlist.size(); i++)
	{
		setHeaderData(i, Qt::Horizontal, hlist[i]);
	}
}

UrielMeetingReportTableModel::~UrielMeetingReportTableModel()
{
}

QVariant UrielMeetingReportTableModel::data(const QModelIndex &index, int role) const
{
	if (index.column() == 2)
	{
		switch (role)
		{
		case Qt::DisplayRole:
		{
			QVariant value = QSqlQueryModel::data(index, role);
			value.setValue(QFileInfo(value.value<QString>()).fileName());
			return value;
			break;
		}
		default:
			break;
		}

	}

	QVariant value = QSqlQueryModel::data(index, role);
	if (role == Qt::TextAlignmentRole)
		return Qt::AlignCenter;
	return value;
}