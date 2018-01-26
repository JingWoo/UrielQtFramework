#include "ProgressDialog.h"

ProgressDialog::ProgressDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	initializeUI(parent);
	setSignalsAndSlots();
	ui.TotalProgressBar->setStyleSheet("QProgressBar{ border:2px solid grey; border-radius:5px; text-align: center;}"
		"QProgressBar::chunk{ background-color:#05B8CC;width:10px;margin:0px;}");
	ui.ReadProgressBar->setStyleSheet("QProgressBar{ border:2px solid grey; border-radius:5px; text-align: center;}"
		"QProgressBar::chunk{ background-color:#05B8CC;width:10px;margin:0.5px;}");
	this->resize(500,46);
}

ProgressDialog::~ProgressDialog()
{
}

void ProgressDialog::initializeUI(QWidget *parent)
{
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);

	this->move(parent->x()+parent->geometry().width()/2-250, parent->y() +parent->geometry().height()-120);

}

void ProgressDialog::setSignalsAndSlots()
{
}

void ProgressDialog::setCurrentTotalValue(qint64 total)
{
	ui.TotalProgressBar->setValue(total);
	m_iRead = total;
}
void ProgressDialog::setTotalProgressBarMax(qint64 total)
{
	
	m_iTotal = total;
	if (m_iTotal == 1)
	{
		ui.TotalProgressBar->hide();
		this->resize(this->geometry().width(), this->geometry().height()/2);
	}
	ui.TotalProgressBar->setMaximum(total);
}

void ProgressDialog::updateProgressBarValue(qint64 read, qint64 total)
{
	ui.ReadProgressBar->setMaximum(total);
	ui.ReadProgressBar->setValue(read);
	if (m_iRead >= m_iTotal && read >= ui.ReadProgressBar->maximum())
		this->accept();
}