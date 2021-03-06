#ifndef URIEL_NOTICES_TREE_MODEL_H_
#define URIEL_NOTICES_TREE_MODEL_H_

#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVariant>


class NoticesMenuTreeItem;

class NoticesMenuTreeModel : public QAbstractItemModel
{
	Q_OBJECT

public:
	explicit NoticesMenuTreeModel(const QStringList &data, QObject *parent = 0);
	~NoticesMenuTreeModel();

	QVariant data(const QModelIndex &index, int role) const override;
	Qt::ItemFlags flags(const QModelIndex &index) const override;
	QVariant headerData(int section, Qt::Orientation orientation,
		int role = Qt::DisplayRole) const override;
	QModelIndex index(int row, int column,
		const QModelIndex &parent = QModelIndex()) const override;
	QModelIndex parent(const QModelIndex &index) const override;
	int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	int columnCount(const QModelIndex &parent = QModelIndex()) const override;

	void updateData(const QStringList &data);

private:
	void setupModelData(const QStringList &lines, NoticesMenuTreeItem *parent);

	NoticesMenuTreeItem *rootItem;
};

#endif // TREEMODEL_H