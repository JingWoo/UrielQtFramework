#include "UrielModel\NoticesMenuTableModel\NoticesMenuTableItemDelegate.h"
#include <QPainter>
#include <QEvent>
NoticesMenuTableItemDelegate::NoticesMenuTableItemDelegate(QObject * parent)
	:QItemDelegate(parent),
	m_pixGeneralNotice(QPixmap(":/Mainwindow/Resources/UrielQtFramework/generalNotices.png")),
	m_pixImportantNotice(QPixmap(":/Mainwindow/Resources/UrielQtFramework/importantNotices.png")),
	m_pixEmergencyNotice(QPixmap(":/Mainwindow/Resources/UrielQtFramework/emergencyNotice.png"))
{}

void NoticesMenuTableItemDelegate::paint(QPainter * painter,
	const QStyleOptionViewItem & option,
	const QModelIndex & index) const
{
	if (index.column() != 1) {
		QItemDelegate::paint(painter, option, index);
		return;
	}
	const QAbstractItemModel * model = index.model();
	QVariant var = model->data(index, Qt::DisplayRole);
	QPixmap pixTemp;
	if (var == QStringLiteral("一般通知"))
		pixTemp=m_pixGeneralNotice.scaled(20, 20);
	else if(var == QStringLiteral("重要通知"))
		pixTemp = m_pixImportantNotice.scaled(20, 20);
	else
		pixTemp = m_pixEmergencyNotice.scaled(20, 20);

	int width = pixTemp.width();
	int height = pixTemp.height();
	QRect rect = option.rect;
	int x = rect.x() + rect.width() / 2 - width / 2;
	int y = rect.y() + rect.height() / 2 - height / 2;
	painter->drawPixmap(x, y, pixTemp);
}


bool NoticesMenuTableItemDelegate::editorEvent(QEvent * event,
	QAbstractItemModel * model,
	const QStyleOptionViewItem & /*option*/,
	const QModelIndex & index)
{
	if (event->type() == QEvent::MouseButtonPress &&
		index.column() == 0) {
		QVariant var = model->data(index, Qt::CheckStateRole);
		bool isFavourite = var.toBool();
		if (var.isValid())
			isFavourite = isFavourite ? false : true;
		else
			isFavourite = true;
		model->setData(index, isFavourite, Qt::CheckStateRole);
		return true;//I have handled the event  
	}

	return false;
}
