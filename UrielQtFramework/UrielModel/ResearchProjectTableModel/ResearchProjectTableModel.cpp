#include "ResearchProjectTableModel.h"
#include <QColor>
#include <QFont>
#include <QPixmap>
#include <QDateTime>
#include <QFileInfo>
UrielResearchProjectTableModel::UrielResearchProjectTableModel(QString strQuery, QStringList hlist, QSqlDatabase&db, QObject *parent)
	:QSqlQueryModel(parent)
{
	setQuery(strQuery, db);
	for (int i = 0; i < hlist.size(); i++)
	{
		setHeaderData(i, Qt::Horizontal, hlist[i]);
	}
}

UrielResearchProjectTableModel::~UrielResearchProjectTableModel()
{
}

QVariant UrielResearchProjectTableModel::data(const QModelIndex &index, int role) const
{
	QVariant value = QSqlQueryModel::data(index, role);
	if (role == Qt::TextAlignmentRole)
		return Qt::AlignCenter;
	return value;
}