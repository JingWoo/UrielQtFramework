#ifndef URIEL_NOTICES_TREE_ITEM_H_
#define URIEL_NOTICES_TREE_ITEM_H_

#include <QList>
#include <QVariant>

class NoticesMenuTreeItem
{
public:
	explicit NoticesMenuTreeItem(const QList<QVariant> &data, NoticesMenuTreeItem *parentItem = 0);
	~NoticesMenuTreeItem();

	void appendChild(NoticesMenuTreeItem *child);

	NoticesMenuTreeItem *child(int row);
	int childCount() const;
	int columnCount() const;
	QVariant data(int column) const;
	int row() const;
	NoticesMenuTreeItem *parentItem();

private:
	QList<NoticesMenuTreeItem*> m_childItems;
	QList<QVariant> m_itemData;
	NoticesMenuTreeItem *m_parentItem;
};

#endif // URIEL_NOTICES_TREE_ITEM_H_