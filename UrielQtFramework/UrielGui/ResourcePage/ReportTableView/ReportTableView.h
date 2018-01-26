#pragma once
#include <QTableView>

class ReportTableView : public QTableView
{
	Q_OBJECT

public:

	explicit ReportTableView(QWidget *parent = 0);

signals:
	void fileNameList(QStringList & fileNameList);
protected:

	void dragEnterEvent(QDragEnterEvent *event);
	void dragMoveEvent(QDragMoveEvent *event);
	void dropEvent(QDropEvent *event);
};