#include "CriticalDialog.h"

CriticalDialog::CriticalDialog(const QString & title, const QString & content, QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	initializeUI(parent);
	setSignalsAndSlots();
	ui.Title->setText(title);
	ui.Content->setText(content);
	//this->exec();
}

CriticalDialog::~CriticalDialog()
{
}

void CriticalDialog::initializeUI(QWidget *parent)
{
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);

	this->move(parent->x() + parent->geometry().width() / 2 - 250, parent->y() + parent->geometry().height() / 2 - 100);

}

void CriticalDialog::setSignalsAndSlots()//onCancelClicked
{
	QObject::connect(ui.Sure, &QToolButton::clicked, this, &CriticalDialog::onSureClicked);
	QObject::connect(ui.Cancel, &QToolButton::clicked, this, &CriticalDialog::onCancelClicked);
}


void CriticalDialog::onSureClicked()
{
	this->accept();
}

void CriticalDialog::onCancelClicked()
{
	this->reject();
}