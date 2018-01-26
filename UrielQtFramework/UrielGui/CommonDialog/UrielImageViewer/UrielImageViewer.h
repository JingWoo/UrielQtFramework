#pragma once

#include <QDialog>
#include <QLabel>
#include <QPrinter>
#include <QScrollBar>
#include "ui_UrielImageViewer.h"

class UrielImageViewer : public QDialog
{
	Q_OBJECT

public:
	UrielImageViewer(QWidget *parent = Q_NULLPTR);
	~UrielImageViewer();
	bool loadFile(const QString &);
	void setImage(const QImage &newImage);
	private slots:
	void open();
	void saveAs();
	void print();
	void copy();
	void paste();
	void zoomIn();
	void zoomOut();
	void normalSize();
	void fitToWindow();

private:
	void initializeUI(QWidget *parent = Q_NULLPTR);
	void InitializeActions();
	void createMenus();
	void updateActions();
	bool saveFile(const QString &fileName);
	
	void scaleImage(double factor);
	void adjustScrollBar(QScrollBar *scrollBar, double factor);

	QImage image;
	QLabel *imageLabel;
	double scaleFactor;

#ifndef QT_NO_PRINTER
	QPrinter printer;
#endif
private:
	Ui::UrielImageViewer ui;
};
