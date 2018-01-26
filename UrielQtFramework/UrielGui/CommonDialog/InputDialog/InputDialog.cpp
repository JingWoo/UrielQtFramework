#include "InputDialog.h"

InputDialog::InputDialog(const QString & title, QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	initializeUI(parent);
	setSignalsAndSlots();
	ui.Title->setText(title);
}

InputDialog::~InputDialog()
{
}

void InputDialog::initializeUI(QWidget *parent)
{
	this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());
	//this->setAttribute(Qt::WA_TranslucentBackground, true);

	this->resize(parent->geometry().width(), parent->geometry().height() - 45);
	this->move(parent->x(), parent->y() + 45);
	//set as Transparent degree
	//setWindowOpacity(0.7);

}

void InputDialog::setSignalsAndSlots()
{
	QObject::connect(ui.Cancel, &QToolButton::clicked, [&]() {
		this->reject(); });
	QObject::connect(ui.OK, &QToolButton::clicked, [&]() {
		emit contentSignal(ui.ContentLineEdit->text());
		this->accept(); });
}