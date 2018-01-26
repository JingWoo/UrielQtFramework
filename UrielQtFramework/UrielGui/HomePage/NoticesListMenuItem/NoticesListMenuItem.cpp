#include "NoticesListMenuItem.h"
#include <QPixmap>
NoticesListMenuItem::NoticesListMenuItem(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

NoticesListMenuItem::~NoticesListMenuItem()
{

}


void NoticesListMenuItem::mousePressEvent(QMouseEvent *event)
{
	emit NoticeCodeSignal(m_NotificationsMenuItem.m_sCode);
	QPalette Pal(palette());
	Pal.setColor(QPalette::Background, Qt::blue);
}

void NoticesListMenuItem::setNoticesListMenuItemContent(const sUrielNotificationsMenuItem & item)
{
	this->m_NotificationsMenuItem = item;
	if (item.m_sImportantDegree == QStringLiteral("一般通知"))
		ui.Ico->setPixmap(QPixmap(":/Mainwindow/Resources/UrielQtFramework/generalNotices.png"));
	else if (item.m_sImportantDegree == QStringLiteral("重要通知"))
		ui.Ico->setPixmap(QPixmap(":/Mainwindow/Resources/UrielQtFramework/importantNotices.png"));
	else if (item.m_sImportantDegree == QStringLiteral("紧急通知"))
		ui.Ico->setPixmap(QPixmap(":/Mainwindow/Resources/UrielQtFramework/emergencyNotice.png"));
	else
		ui.Ico->setPixmap(QPixmap(":/Mainwindow/Resources/UrielQtFramework/note.png"));

	ui.Title->setText(item.m_sTitle.left(10)+"...");
	ui.Time->setText(item.m_tReleaseTime.toString("yyyy-MM-dd"));
	ui.Content->setText(item.m_sContent.left(20) + "...");
}