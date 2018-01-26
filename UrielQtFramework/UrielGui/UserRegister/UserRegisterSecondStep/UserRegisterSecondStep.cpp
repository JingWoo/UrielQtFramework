#include "UserRegisterSecondStep.h"
#include "UrielGui\UserRegister\UserRegisterThirdStep\UserRegisterThirdStep.h"
#include <QMouseEvent>
UserRegisterSecondStep::UserRegisterSecondStep(UrielDatabase * database, QWidget *parent)
	: QDialog(parent), m_databse(database)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
	ui.namelabel->setVisible(false);
	ui.idlabel->setVisible(false);
	ui.phonelabel->setVisible(false);
	ui.emaillabel->setVisible(false);

	ui.banklabel->setVisible(false);
	ui.banknumberlabel->setVisible(false);
	ui.projectlabel->setVisible(false);

	QStringList bankList;
	bankList << QStringLiteral("中国银行") << QStringLiteral("中国工商银行") << QStringLiteral("中信银行") << QStringLiteral("中国农业银行") << QStringLiteral("中国建设银行");
	ui.BankType->addItems(bankList);
	ui.BankType->setCurrentIndex(-1);

	QObject::connect(ui.AppClose, &QToolButton::clicked, [&] {
		qApp->quit(); });

	QObject::connect(ui.NextStep, &QToolButton::clicked, [&] {
		
		if (ui.Name->text() == "" || ui.ID->text() == "" || ui.Phone->text() == "" || ui.Email->text() == "" \
			|| ui.BankType->currentText() == "" || ui.BankNumber->text() == "")
		{
			ui.namelabel->setVisible(true);
			ui.idlabel->setVisible(true);
			ui.phonelabel->setVisible(true);
			ui.emaillabel->setVisible(true);
			ui.banklabel->setVisible(true);
			ui.banknumberlabel->setVisible(true);
			return;
		}
		this->hide();
		m_sAcountInfo.m_sName = ui.Name->text();
		m_sAcountInfo.m_sSchoolWorkNumber = ui.ID->text();
		m_sAcountInfo.m_sPhoneNumber = ui.Phone->text();
		m_sAcountInfo.m_sEmail = ui.Email->text();
		m_sAcountInfo.m_sBankType = ui.BankType->currentText();
		m_sAcountInfo.m_sBankCardNumber = ui.BankNumber->text();
		m_sAcountInfo.m_sProjectTeam = ui.Project->text();

		UserRegisterThirdStep register_dlg(m_sAcountInfo,m_databse,this);
		register_dlg.exec();
	});
}

UserRegisterSecondStep::~UserRegisterSecondStep()
{
}


void UserRegisterSecondStep::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		m_bPressed = true;
		m_point = event->pos();
	}
}

void UserRegisterSecondStep::mouseMoveEvent(QMouseEvent *event)
{
	if (m_bPressed)
		move(event->pos() - m_point + pos());
}

void UserRegisterSecondStep::mouseReleaseEvent(QMouseEvent *event)
{
	Q_UNUSED(event);
	m_bPressed = false;
}
