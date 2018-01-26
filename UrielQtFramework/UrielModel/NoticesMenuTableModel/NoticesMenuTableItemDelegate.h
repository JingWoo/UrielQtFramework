#ifndef _NoticesMenuTableItemDelegate_H_
#define _NoticesMenuTableItemDelegate_H_

#include <QItemDelegate>


class NoticesMenuTableItemDelegate :public QItemDelegate
{
public:
	NoticesMenuTableItemDelegate(QObject * parent = 0);
	virtual ~NoticesMenuTableItemDelegate() {}

	void paint(QPainter * painter,
		const QStyleOptionViewItem & option,
		const QModelIndex & index) const;
	bool editorEvent(QEvent * event,
		QAbstractItemModel * model,
		const QStyleOptionViewItem & option,
		const QModelIndex & index);
private:
	QPixmap m_pixGeneralNotice;
	QPixmap m_pixImportantNotice;
	QPixmap m_pixEmergencyNotice;
};
#endif // !_NoticesMenuTableItemDelegate_H_