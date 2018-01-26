#include "ReportTableView.h"
#include <QEvent>
#include <QDragEnterEvent>
#include <QDebug>
#include <QList>
#include <QMimeData>
ReportTableView::ReportTableView(QWidget *parent)
	: QTableView(parent)
{
	setAcceptDrops(true);
	setDragDropMode(QAbstractItemView::DragDrop);
	setDragEnabled(true);
	setDropIndicatorShown(true);
}

void ReportTableView::dragEnterEvent(QDragEnterEvent *event)
{
	event->mimeData()->hasFormat("text/uri-list");
	if (event->mimeData()->hasFormat("text/uri-list"))
		event->acceptProposedAction();
	//qDebug() << "drag enter";
}

void ReportTableView::dropEvent(QDropEvent *drop_event)
{
	QList<QUrl> urls = drop_event->mimeData()->urls();
	if (urls.isEmpty())
		return;
	QStringList fileList;
	foreach(QUrl url, urls) {
		QString file_name = url.toLocalFile();
		fileList<< file_name;
		//qDebug() << file_name;
	}
	emit fileNameList(fileList);
}

void ReportTableView::dragMoveEvent(QDragMoveEvent *event)
{
	//qDebug() << "drag move";
}