#include "InformationDialog.h"

InformationDialog::InformationDialog(const QString & title, const QString & content, QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	initializeUI(parent);
	setSignalsAndSlots();
	ui.Title->setText(title);
	ui.Content->setText(content);
	//this->exec();
}

InformationDialog::~InformationDialog()
{
}


void InformationDialog::initializeUI(QWidget *parent)
{
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
	if(parent!=nullptr)
	   this->move(parent->x() + parent->geometry().width() / 2 - 250, parent->y() + parent->geometry().height()/2 - 100);

}

void InformationDialog::setSignalsAndSlots()//onCancelClicked
{
	QObject::connect(ui.Sure,&QToolButton::clicked,this,&InformationDialog::onSureClicked);
	QObject::connect(ui.Cancel, &QToolButton::clicked, this, &InformationDialog::onCancelClicked);
}


void InformationDialog::onSureClicked()
{
	this->accept();
}

void InformationDialog::onCancelClicked()
{
	this->reject();
}