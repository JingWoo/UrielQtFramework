#include <QStringList>

#include "UrielModel\NoticesMenuTreeModel\NoticesMenuTreeItem.h"

NoticesMenuTreeItem::NoticesMenuTreeItem(const QList<QVariant> &data, NoticesMenuTreeItem *parent)
{
	m_parentItem = parent;
	m_itemData = data;
}

NoticesMenuTreeItem::~NoticesMenuTreeItem()
{
	qDeleteAll(m_childItems);
}

void NoticesMenuTreeItem::appendChild(NoticesMenuTreeItem *item)
{
	m_childItems.append(item);
}

NoticesMenuTreeItem *NoticesMenuTreeItem::child(int row)
{
	return m_childItems.value(row);
}

int NoticesMenuTreeItem::childCount() const
{
	return m_childItems.count();
}

int NoticesMenuTreeItem::columnCount() const
{
	return m_itemData.count();
}

QVariant NoticesMenuTreeItem::data(int column) const
{
	return m_itemData.value(column);
}

NoticesMenuTreeItem *NoticesMenuTreeItem::parentItem()
{
	return m_parentItem;
}

int NoticesMenuTreeItem::row() const
{
	if (m_parentItem)
		return m_parentItem->m_childItems.indexOf(const_cast<NoticesMenuTreeItem*>(this));

	return 0;
}