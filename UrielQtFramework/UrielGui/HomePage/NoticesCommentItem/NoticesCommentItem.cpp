#include "NoticesCommentItem.h"
#include <QToolButton>
NoticesCommentItem::NoticesCommentItem(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.Comment, &QToolButton::clicked, this, &NoticesCommentItem::onCommentClicked);
}

NoticesCommentItem::~NoticesCommentItem()
{
}

void NoticesCommentItem::onCommentClicked()
{
	emit CommentSiganl(ui.Name->text());
}

void NoticesCommentItem::setValue(const sUrielCommentData & st)
{
	ui.HeadIco->setIcon(QPixmap::fromImage(st.m_imgHeadIco));
	ui.Name->setText(st.m_sName);
	ui.Content->setText(st.m_sContent);
	ui.Time->setText(st.m_sTime);
	ui.Content->adjustSize();
	//this->setFixedHeight(80);

}
