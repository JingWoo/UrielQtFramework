#include "UserRegisterFirstStep.h"
#include "UrielGui\UserRegister\UserRegisterSecondStep\UserRegisterSecondStep.h"
#include <QMouseEvent>
UserRegisterFirstStep::UserRegisterFirstStep(UrielDatabase * database, QWidget *parent)
	: QDialog(parent), m_databse(database)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
	QObject::connect(ui.AppClose, &QToolButton::clicked, [&] {
		qApp->quit(); });
	QObject::connect(ui.RegisterNewAccount, &QToolButton::clicked, [&] {
		this->hide();
		UserRegisterSecondStep register_dlg(m_databse,this);
		register_dlg.exec();
	});
}

UserRegisterFirstStep::~UserRegisterFirstStep()
{
}

void UserRegisterFirstStep::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		m_bPressed = true;
		m_point = event->pos();
	}
}

void UserRegisterFirstStep::mouseMoveEvent(QMouseEvent *event)
{
	if (m_bPressed)
		move(event->pos() - m_point + pos());
}

void UserRegisterFirstStep::mouseReleaseEvent(QMouseEvent *event)
{
	Q_UNUSED(event);
	m_bPressed = false;
}
