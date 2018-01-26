#include "UserRegisterThirdStep.h"
#include "UrielDatabase\UrielDatabase.h"
#include "UrielGui\UserRegister\UserRegisterLastStep\UserRegisterLastStep.h"
#include <QMessageBox>
#include <QMouseEvent>
#include <QCryptographicHash> 
#include "UrielFileTransfer\FTP\UrielFTP.h"
UserRegisterThirdStep::UserRegisterThirdStep(const sUrielAccountInfo & sAcountInfo ,UrielDatabase * database, QWidget *parent)
	: QDialog(parent), m_databse(database), m_sAcountInfo(sAcountInfo)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
	ui.ErrorInfo->setVisible(false);

	QObject::connect(ui.AppClose, &QToolButton::clicked, [&] {
		qApp->quit(); });
	QObject::connect(ui.PasswordShow, &QToolButton::clicked, [&] {
		if (ui.Password->echoMode() == QLineEdit::EchoMode::Password)
		{
			ui.Password->setEchoMode(QLineEdit::EchoMode::Normal);
			ui.PasswordShow->setIcon(QIcon(":/UserRegister/Resources/UserRegister/dontshow.png"));
		}
		else
		{
			ui.Password->setEchoMode(QLineEdit::EchoMode::Password);
			ui.PasswordShow->setIcon(QIcon(":/UserRegister/Resources/UserRegister/eye.png"));
		}
			
	});
	QObject::connect(ui.RepeatShow, &QToolButton::clicked, [&] {
		if (ui.Repeat->echoMode() == QLineEdit::EchoMode::Password)
		{
			ui.Repeat->setEchoMode(QLineEdit::EchoMode::Normal);
			ui.RepeatShow->setIcon(QIcon(":/UserRegister/Resources/UserRegister/dontshow.png"));
		}
			
		else
		{
			ui.Repeat->setEchoMode(QLineEdit::EchoMode::Password);
			ui.RepeatShow->setIcon(QIcon(":/UserRegister/Resources/UserRegister/eye.png"));
		}
			
	});

	QObject::connect(ui.NextStep, &QToolButton::clicked, [&] {
		if (ui.Password->text() != ui.Repeat->text())
		{
			ui.ErrorInfo->setText(QStringLiteral("密码不一致！重新输入..."));
			ui.ErrorInfo->setVisible(true);
			return;
		}

		if (ui.Password->text() =="")
		{
			ui.ErrorInfo->setText(QStringLiteral("密码不可为空！重新输入..."));
			ui.ErrorInfo->setVisible(true);
			return;
		}


		
		QString sErrorInfo;

		QByteArray byteArray;
		byteArray.append(ui.Password->text());
		QCryptographicHash hash(QCryptographicHash::Sha3_512);
		hash.addData(byteArray);  // 添加数据到加密哈希值
		m_sAcountInfo.m_sPassword = hash.result().toHex();

		if (!m_databse->insertUserAccount(m_sAcountInfo, sErrorInfo))
		{
			QMessageBox::critical(NULL, QObject::tr("Error"), sErrorInfo);
			return;
		}
		//creat folder for account
		UrielFtp *urielFtp = UrielFtp::getInstance();
		//urielFtp->cdToSpecifiedPath();
		urielFtp->mkdir(urielFtp->getRootPath() + "/MeetingReport/" + sAcountInfo.m_sName);
		urielFtp->mkdir(urielFtp->getRootPath() + "/Notices/"+sAcountInfo.m_sName);
		urielFtp->mkdir(urielFtp->getRootPath() + "/Invoice/"+ sAcountInfo.m_sName);
		urielFtp->mkdir(urielFtp->getRootPath() + "/MaterialPurchaseApply/" + sAcountInfo.m_sName);
		this->hide();
		UserRegisterLastStep register_dlg;
		register_dlg.exec();
	});
}

UserRegisterThirdStep::~UserRegisterThirdStep()
{
}


void UserRegisterThirdStep::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		m_bPressed = true;
		m_point = event->pos();
	}
}

void UserRegisterThirdStep::mouseMoveEvent(QMouseEvent *event)
{
	if (m_bPressed)
		move(event->pos() - m_point + pos());
}

void UserRegisterThirdStep::mouseReleaseEvent(QMouseEvent *event)
{
	Q_UNUSED(event);
	m_bPressed = false;
}