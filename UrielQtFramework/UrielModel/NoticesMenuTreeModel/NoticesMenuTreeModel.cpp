#include "UrielModel\NoticesMenuTreeModel\NoticesMenuTreeModel.h"
#include "UrielModel\NoticesMenuTreeModel\NoticesMenuTreeItem.h"
#include <QStringList>


NoticesMenuTreeModel::NoticesMenuTreeModel(const QStringList &data, QObject *parent)
	: QAbstractItemModel(parent)
{
	QList<QVariant> rootData;
	rootData << QStringLiteral("֪ͨ");
	rootItem = new NoticesMenuTreeItem(rootData);
	setupModelData(data, rootItem);
}

NoticesMenuTreeModel::~NoticesMenuTreeModel()
{
	delete rootItem;
}

int NoticesMenuTreeModel::columnCount(const QModelIndex &parent) const
{
	if (parent.isValid())
		return static_cast<NoticesMenuTreeItem*>(parent.internalPointer())->columnCount();
	else
		return rootItem->columnCount();
}

QVariant NoticesMenuTreeModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid())
		return QVariant();

	if (role != Qt::DisplayRole)
		return QVariant();

	NoticesMenuTreeItem *item = static_cast<NoticesMenuTreeItem*>(index.internalPointer());

	return item->data(index.column());
}

Qt::ItemFlags NoticesMenuTreeModel::flags(const QModelIndex &index) const
{
	if (!index.isValid())
		return 0;

	return QAbstractItemModel::flags(index);
}

QVariant NoticesMenuTreeModel::headerData(int section, Qt::Orientation orientation,
	int role) const
{
	if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
		return rootItem->data(section);

	return QVariant();
}

QModelIndex NoticesMenuTreeModel::index(int row, int column, const QModelIndex &parent) const
{
	if (!hasIndex(row, column, parent))
		return QModelIndex();

	NoticesMenuTreeItem *parentItem;

	if (!parent.isValid())
		parentItem = rootItem;
	else
		parentItem = static_cast<NoticesMenuTreeItem*>(parent.internalPointer());

	NoticesMenuTreeItem *childItem = parentItem->child(row);
	if (childItem)
		return createIndex(row, column, childItem);
	else
		return QModelIndex();
}

QModelIndex NoticesMenuTreeModel::parent(const QModelIndex &index) const
{
	if (!index.isValid())
		return QModelIndex();

	NoticesMenuTreeItem *childItem = static_cast<NoticesMenuTreeItem*>(index.internalPointer());
	NoticesMenuTreeItem *parentItem = childItem->parentItem();

	if (parentItem == rootItem)
		return QModelIndex();

	return createIndex(parentItem->row(), 0, parentItem);
}

int NoticesMenuTreeModel::rowCount(const QModelIndex &parent) const
{
	NoticesMenuTreeItem *parentItem;
	if (parent.column() > 0)
		return 0;

	if (!parent.isValid())
		parentItem = rootItem;
	else
		parentItem = static_cast<NoticesMenuTreeItem*>(parent.internalPointer());

	return parentItem->childCount();
}

void NoticesMenuTreeModel::updateData(const QStringList &data )
{
	if (rootItem)
	{
		delete rootItem;
		rootItem = nullptr;
	}

	QList<QVariant> rootData;
	rootData << QStringLiteral("֪ͨ");

	rootItem = new NoticesMenuTreeItem(rootData);
	setupModelData(data, rootItem);

	//QAbstractItemModel::reset();

}

void NoticesMenuTreeModel::setupModelData(const QStringList &lines, NoticesMenuTreeItem *parent)
{
	int number = 0;
	while (number < lines.count())
	{
		QList<QVariant> MainNodeContent;
		MainNodeContent.append(lines[number]);
		NoticesMenuTreeItem *primar = new NoticesMenuTreeItem(MainNodeContent, parent);
		parent->appendChild(primar);
		QList<QVariant> childNode;
		//ToDo set childNode
		for (int i = 0; i < childNode.size(); ++i)
		{
			QList<QVariant> childNodeContent;
			childNodeContent.append(childNode[i]);
			primar->appendChild(new NoticesMenuTreeItem(childNodeContent, primar));
		}
		++number;
	}
	//QList<NoticesMenuTreeItem*> parents;
	//QList<int> indentations;
	//parents << parent;
	//indentations << 0;

	//int number = 0;
	//
	//while (number < lines.count()) {
	//	int position = 0;
	//	while (position < lines[number].length()) {
	//		if (lines[number].at(position) != ' ')
	//			break;
	//		position++;
	//	}

	//	QString lineData = lines[number].mid(position).trimmed();

	//	if (!lineData.isEmpty()) {
	//		// Read the column data from the rest of the line.
	//		QStringList columnStrings = lineData.split("\t", QString::SkipEmptyParts);
	//		QList<QVariant> columnData;
	//		for (int column = 0; column < columnStrings.count(); ++column)
	//			columnData << columnStrings[column];

	//		if (position > indentations.last()) {
	//			// The last child of the current parent is now the new parent
	//			// unless the current parent has no children.

	//			if (parents.last()->childCount() > 0) {
	//				parents << parents.last()->child(parents.last()->childCount() - 1);
	//				indentations << position;
	//			}
	//		}
	//		else {
	//			while (position < indentations.last() && parents.count() > 0) {
	//				parents.pop_back();
	//				indentations.pop_back();
	//			}
	//		}

	//		// Append a new item to the current parent's list of children.
	//		parents.last()->appendChild(new NoticesMenuTreeItem(columnData, parents.last()));
	//	}

	//	++number;
	//}
}
