#include "CheckInTableModel.h"
#include <QPixmap>
UrielCheckInTableModel::UrielCheckInTableModel(QString strQuery, QStringList hlist, QSqlDatabase&db, QObject *parent)
	: QSqlQueryModel(parent)
{
	setQuery(strQuery, db);
	for (int i = 0; i < hlist.size(); i++)
	{
		setHeaderData(i, Qt::Horizontal, hlist[i]);
	}
}

UrielCheckInTableModel::~UrielCheckInTableModel()
{
}

QVariant UrielCheckInTableModel::data(const QModelIndex &index, int role) const
{
	if (index.column() == 1)
	{
		switch (role)
		{
		case Qt::DecorationRole:
		{
			QVariant var = QSqlQueryModel::data(index, Qt::DisplayRole);
			if (var == QStringLiteral("Group"))
				return QPixmap(":/Mainwindow/Resources/UrielQtFramework/group.png").scaled(20, 20);
			else 
				return QPixmap(":/Mainwindow/Resources/UrielQtFramework/personal.png").scaled(20, 20);
			break;
		}
		case Qt::ToolTipRole:
		{
			QVariant var = QSqlQueryModel::data(index, Qt::DisplayRole);
			return var;
			break;
		}
		default:
			break;
		}
	}

	if (index.column() == 8)
	{
		switch (role)
		{
		case Qt::DecorationRole:
		{
			QVariant var = QSqlQueryModel::data(index, Qt::DisplayRole);
			if (var == QStringLiteral("Audited"))
				return QPixmap(":/Mainwindow/Resources/UrielQtFramework/audited.png").scaled(20, 20);
			else if (var == QStringLiteral("UnAudit"))
				return QPixmap(":/Mainwindow/Resources/UrielQtFramework/UnAudit.png").scaled(20, 20);
			else
				return QPixmap(":/Mainwindow/Resources/UrielQtFramework/auditNoThrough.png").scaled(20, 20);
			break;
		}
		case Qt::ToolTipRole:
		{
			QVariant var = QSqlQueryModel::data(index, Qt::DisplayRole);
			if (var == QStringLiteral("Audited"))
				return QStringLiteral("ÉóºËÍ¨¹ý");
			else if (var == QStringLiteral("UnAudit"))
				return QStringLiteral("ÉÐÎ´ÉóºË");
			else
				return QStringLiteral("ÉóºË²»Í¨¹ý");
			break;
		}
		default:
			break;
		}
	}


	//if (index.column() == 2)
	//{
	//	switch (role)
	//	{
	//	case Qt::ToolTipRole:
	//	{
	//		QVariant var = QSqlQueryModel::data(index, Qt::DisplayRole);
	//		return var;
	//		break;
	//	}
	//	case Qt::FontRole:
	//	{
	//		QFont font;
	//		font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
	//		font.setPointSize(12);
	//		return qVariantFromValue(font);
	//		break;
	//	}
	//	default:
	//		break;
	//	}

	//}

	//if (index.column() == 5)
	//{
	//	switch (role)
	//	{
	//	case Qt::DisplayRole:
	//	{
	//		QVariant value = QSqlQueryModel::data(index, role);
	//		value.setValue(value.value<QDateTime>().toString("yyyy-MM-dd"));
	//		return value;
	//		break;
	//	}
	//	default:
	//		break;
	//	}
	//}

	QVariant value = QSqlQueryModel::data(index, role);
	if (role == Qt::TextAlignmentRole)
		return Qt::AlignCenter;
	return value;
}
