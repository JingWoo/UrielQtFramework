#include "Login.h"
#include "UrielDatabase\UrielDatabase.h"
#include "UrielQtFrameworkOptions/UrielQtFrameworkOptions.h"
#include "UrielGui\UserRegister\UserRegisterFirstStep\UserRegisterFirstStep.h"
Login::Login(UrielDatabase * database, UrielQtFrameworkOptions * options, QWidget *parent)
	: QDialog(parent), m_databse(database),m_options(options)
{
	ui.setupUi(this);
	setSignalsAndSlots();
	initializeUI();
}

Login::~Login()
{
}

void Login::initializeUI()
{
	this->setWindowIcon(QIcon(":/Mainwindow/Resources/UrielQtFramework/Login.png"));
	setLoginErrorShow(false);
	this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
	ui.HeadIco->setPixmap(QPixmap::fromImage(QImage(m_options->getHeadIcoPath())));
	ui.Account->setText(m_options->getAccount());
	if (m_options->getRememberPassword())
	{
		ui.RememberPassword->setChecked(true);
		ui.Password->setText(m_options->getPassword());
	}
}

void Login::setSignalsAndSlots()
{
	QObject::connect(ui.AppClose,&QToolButton::clicked,this,&Login::onAppCloseClicked);
	QObject::connect(ui.RememberPassword,&QCheckBox::clicked,this,&Login::onRememberPasswordClicked);
	QObject::connect(ui.AutoLogin, &QCheckBox::clicked, this, &Login::onAutoLoginClicked);
	QObject::connect(ui.ConfirmLogin, &QToolButton::clicked, this, &Login::onConfirmLoginClicked);
	QObject::connect(ui.RegisterAccount, &QToolButton::clicked, this, &Login::onRegisterAccountClicked);
	QObject::connect(ui.FindPassword, &QToolButton::clicked, this, &Login::onFindPasswordClicked);
	QObject::connect(ui.Account, &QLineEdit::editingFinished, this, &Login::onAccountEditingFinished);
}

void Login::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		m_bPressed = true;
		m_point = event->pos();
	}
}

void Login::mouseMoveEvent(QMouseEvent *event)
{
	if (m_bPressed)
		move(event->pos() - m_point + pos());
}

void Login::mouseReleaseEvent(QMouseEvent *event)
{
	Q_UNUSED(event);
	m_bPressed = false;
}

void Login::onRememberPasswordClicked()
{
	m_options->setRememberPassword(ui.RememberPassword->isChecked());
}

void Login::onAutoLoginClicked()
{
	m_options->setAutoLogin(ui.AutoLogin->isChecked());
}

void Login::onConfirmLoginClicked()
{
	//ui.HeadIco->pixmap()->toImage().save(QCoreApplication::applicationDirPath() + "/TempFiles/HeadIco.png", "PNG");
	m_options->setHeadIcoPath(QCoreApplication::applicationDirPath() + "/TempFiles/HeadIco.png");
	if (ui.RememberPassword->isChecked())
		m_options->setPassword(ui.Password->text());

	QString sAccountStatus;
	bool exist{false};
	QString AccountName;
	if (m_databse->verifyUserNameAndPassword(ui.Account->text(), ui.Password->text(), exist, sAccountStatus, AccountName))
	{
		sUrielAccountInfo account;
		m_databse->getUserAccount(account, AccountName);
		m_options->setAccount(AccountName);
		account.m_imgHeadIco.save(QCoreApplication::applicationDirPath() + "/TempFiles/HeadIco.png", "PNG");
		this->accept();
	}
	else
	{
		if (!exist) setLoginErrorShow(true, QStringLiteral("²éÎŞ´ËÕËºÅ£¡"));
		else if(sAccountStatus=="PASSWORD ERROR!") setLoginErrorShow(true, QStringLiteral("ÃÜÂë´íÎó£¡"));
		else  setLoginErrorShow(true, QStringLiteral("ÕËºÅÎ´ÉóºË»òÕßÉóºË²»Í¨¹ı£¡"));
	}
}

void Login::onAccountEditingFinished() {
	sUrielAccountInfo account;
	m_databse->getUserAccount(account, ui.Account->text());
	ui.HeadIco->setPixmap(QPixmap::fromImage(account.m_imgHeadIco));
	account.m_imgHeadIco.save(QCoreApplication::applicationDirPath() + "/TempFiles/HeadIco.png", "PNG");
}
void Login::onRegisterAccountClicked()
{
	this->hide();
	UserRegisterFirstStep register_dlg(m_databse);
	register_dlg.exec();
}

void Login::onFindPasswordClicked()
{

}

void Login::setLoginErrorShow(bool v, const QString & str)
{
	ui.LoginError->setText(str);
	ui.LoginError->setVisible(v);
}

void Login::onAppCloseClicked()
{
	this->reject();
}