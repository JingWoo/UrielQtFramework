#include "TimeFilter.h"
#include <QRadioButton>
TimeFilter::TimeFilter(QPoint point, QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	initializeUI(point);
	setSignalsAndSlots();
}

TimeFilter::~TimeFilter()
{

}


void TimeFilter::initializeUI(QPoint point)
{
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);

	this->move(point.x() + 45, point.y()-20);
}

void TimeFilter::setSignalsAndSlots()
{
	QObject::connect(ui.NearlyADay,&QRadioButton::clicked,this,&TimeFilter::onNearlyADayClicked);
	QObject::connect(ui.NearlyAWeek, &QRadioButton::clicked, this, &TimeFilter::onNearlyAWeekClicked);
	QObject::connect(ui.NearlyAMonth, &QRadioButton::clicked, this, &TimeFilter::onNearlyAMonthClicked);
	QObject::connect(ui.NearlyAYear, &QRadioButton::clicked, this, &TimeFilter::onNearlyAYearClicked);
	QObject::connect(ui.All, &QRadioButton::clicked, this, &TimeFilter::onAllClicked);

}


void TimeFilter::onNearlyADayClicked()
{
	emit timeFilterSignal(TimeFilterEnum::NEARLY_A_DAT);
	this->accept();
}
void TimeFilter::onNearlyAWeekClicked()
{
	emit timeFilterSignal(TimeFilterEnum::NEARLY_A_WEEK);
	this->accept();
}
void TimeFilter::onNearlyAMonthClicked()
{
	emit timeFilterSignal(TimeFilterEnum::NEARLY_A_MONTH);
	this->accept();
}
void TimeFilter::onNearlyAYearClicked()
{
	emit timeFilterSignal(TimeFilterEnum::NEARLY_A_YEAR);
	this->accept();
}
void TimeFilter::onAllClicked()
{
	emit timeFilterSignal(TimeFilterEnum::ALL);
	this->accept();
}

