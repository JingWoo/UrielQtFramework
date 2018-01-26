#include "UserRegisterLastStep.h"
#include <QMouseEvent>
#include <QToolButton>
UserRegisterLastStep::UserRegisterLastStep(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
	QObject::connect(ui.AppClose, &QToolButton::clicked, [&] {
		qApp->quit(); });
	QObject::connect(ui.Finish, &QToolButton::clicked, [&] {
		qApp->quit();
	});
}

UserRegisterLastStep::~UserRegisterLastStep()
{
}

void UserRegisterLastStep::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		m_bPressed = true;
		m_point = event->pos();
	}
}

void UserRegisterLastStep::mouseMoveEvent(QMouseEvent *event)
{
	if (m_bPressed)
		move(event->pos() - m_point + pos());
}

void UserRegisterLastStep::mouseReleaseEvent(QMouseEvent *event)
{
	Q_UNUSED(event);
	m_bPressed = false;
}
