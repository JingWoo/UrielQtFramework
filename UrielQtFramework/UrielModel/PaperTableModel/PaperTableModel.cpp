#include "PaperTableModel.h"

UrielPaperTableModel::UrielPaperTableModel(QString strQuery, QStringList hlist, QSqlDatabase&db, QObject *parent)
	: QSqlQueryModel(parent)
{
	setQuery(strQuery, db);
	for (int i = 0; i < hlist.size(); i++)
	{
		setHeaderData(i, Qt::Horizontal, hlist[i]);
	}
}

UrielPaperTableModel::~UrielPaperTableModel()
{
}

QVariant UrielPaperTableModel::data(const QModelIndex &index, int role) const
{
	QVariant value = QSqlQueryModel::data(index, role);
	if (role == Qt::TextAlignmentRole)
		return Qt::AlignCenter;
	return value;
}
