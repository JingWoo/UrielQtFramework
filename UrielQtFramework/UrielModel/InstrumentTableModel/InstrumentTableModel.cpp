#include "InstrumentTableModel.h"

UrielInstrumentTableModel::UrielInstrumentTableModel(QString strQuery, QStringList hlist, QSqlDatabase&db, QObject *parent)
	: QSqlQueryModel(parent)
{
	setQuery(strQuery, db);
	for (int i = 0; i < hlist.size(); i++)
	{
		setHeaderData(i, Qt::Horizontal, hlist[i]);
	}
}

UrielInstrumentTableModel::~UrielInstrumentTableModel()
{
}

QVariant UrielInstrumentTableModel::data(const QModelIndex &index, int role) const
{
	//if (index.column() == 1)
	//{
	//	switch (role)
	//	{
	//	case Qt::DecorationRole:
	//	{
	//		QVariant var = QSqlQueryModel::data(index, Qt::DisplayRole);
	//		if (var == QStringLiteral("一般通知"))
	//			return QPixmap(":/Mainwindow/Resources/UrielQtFramework/generalNotices.png").scaled(20, 20);
	//		else if (var == QStringLiteral("重要通知"))
	//			return QPixmap(":/Mainwindow/Resources/UrielQtFramework/importantNotices.png").scaled(20, 20);
	//		else
	//			return QPixmap(":/Mainwindow/Resources/UrielQtFramework/emergencyNotice.png").scaled(20, 20);
	//		break;
	//	}
	//	case Qt::ToolTipRole:
	//	{
	//		QVariant var = QSqlQueryModel::data(index, Qt::DisplayRole);
	//		return var;
	//		break;
	//	}
	//	default:
	//		break;
	//	}

	//}

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
