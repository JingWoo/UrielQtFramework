#pragma once

#include <QDialog>
#include "ui_TimeFilter.h"
#include "UrielDefinition\UrielDefinition.h"

class TimeFilter : public QDialog
{
	Q_OBJECT

public:
	TimeFilter(QPoint point,QWidget *parent = Q_NULLPTR);
	~TimeFilter();

signals:
	void timeFilterSignal(const TimeFilterEnum & v);

	private slots:
	void onNearlyADayClicked();
	void onNearlyAWeekClicked();
	void onNearlyAMonthClicked();
	void onNearlyAYearClicked();
	void onAllClicked();

private:
	void initializeUI(QPoint point);
	void setSignalsAndSlots();

private:
	Ui::TimeFilter ui;
};
