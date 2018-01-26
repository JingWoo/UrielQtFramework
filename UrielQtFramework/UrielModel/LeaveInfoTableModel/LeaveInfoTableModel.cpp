#include "LeaveInfoTableModel.h"
#include <QFont>
#include <QColor>
UrielLeaveInfoTableModel::UrielLeaveInfoTableModel(QString strQuery, QStringList hlist, QSqlDatabase&db, QObject *parent)
	: QSqlQueryModel(parent)
{
	setQuery(strQuery, db);
	for (int i = 0; i < hlist.size(); i++)
	{
		setHeaderData(i, Qt::Horizontal, hlist[i]);
	}
}

UrielLeaveInfoTableModel::~UrielLeaveInfoTableModel()
{
}

QVariant UrielLeaveInfoTableModel::data(const QModelIndex &index, int role) const
{
	if (index.column() == 4)
	{
		switch (role)
		{
		case Qt::ToolTipRole:
		{
			QVariant var = QSqlQueryModel::data(index, Qt::DisplayRole);
			return var;
			break;
		}
		case Qt::FontRole:
		{
			QFont font;
			font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
			font.setPointSize(12);
			return qVariantFromValue(font);
			break;
		}
		case Qt::TextColorRole:
		{
			return qVariantFromValue(QColor(Qt::blue));
			break;
		}
		default:
			break;
		}

	}

	if (index.column() == 8)
	{
		if (role == Qt::DisplayRole)
		{
			QVariant value = QSqlQueryModel::data(index, role);
			QString str = value.toString();
			if (str == "UnAudit")
			{
				value.setValue(QStringLiteral("δ���"));
				return value;
			}
			else if (str == "Audited")
			{
				value.setValue(QStringLiteral("ͨ�����"));
				return value;
			}
			else
			{
				value.setValue(QStringLiteral("δͨ�����"));
				return value;
			}
		}
		if (role == Qt::TextColorRole) {
			QVariant value = QSqlQueryModel::data(index, role);
			QString str = value.toString();
			if (str == "UnAudited")
			{
				return qVariantFromValue(QColor(Qt::blue));
			}
			else if (str == "Audited")
			{
				return qVariantFromValue(QColor(Qt::green));
			}
			else
			{
				return qVariantFromValue(QColor(Qt::red));
			}
		}
	}


	QVariant value = QSqlQueryModel::data(index, role);
	if (role == Qt::TextAlignmentRole)
		return Qt::AlignCenter;
	return value;
}
