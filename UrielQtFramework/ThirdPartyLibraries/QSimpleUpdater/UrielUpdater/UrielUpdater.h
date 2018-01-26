#pragma once

#include <QMainWindow>
#include "ui_UrielUpdater.h"

#include <QMainWindow>
#include <QApplication>

QT_FORWARD_DECLARE_CLASS(QSimpleUpdater)
class UrielUpdater : public QMainWindow
{
	Q_OBJECT

public:
	explicit UrielUpdater(QWidget *parent = Q_NULLPTR);
	~UrielUpdater();
public slots:
	void resetFields();
	void checkForUpdates();
	void updateChangelog(const QString& url);
	void displayAppcast(const QString& url, const QByteArray& reply);

private:
	Ui::UrielUpdater ui;
	QSimpleUpdater* m_updater;
	QString DEFS_URL;
	
};
