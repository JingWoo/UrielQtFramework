#pragma once
#include <QObject>
#include <QSqlQueryModel>
#include <QStringList>
class UrielMaterialPurchaseApplyTableModel : public QSqlQueryModel
{
	Q_OBJECT

public:
	UrielMaterialPurchaseApplyTableModel(QString strQuery, QStringList hlist, QSqlDatabase&db, QObject *parent = nullptr);
	~UrielMaterialPurchaseApplyTableModel();

public:
	QVariant data(const QModelIndex &item, int role) const;
private:
	QString m_strQuery;
	QStringList m_cHeaderList;

};
