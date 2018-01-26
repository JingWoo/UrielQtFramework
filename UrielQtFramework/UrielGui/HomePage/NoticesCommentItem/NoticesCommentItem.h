#pragma once

#include <QWidget>
#include "ui_NoticesCommentItem.h"
#include "UrielDefinition\UrielDefinition.h"
class NoticesCommentItem : public QWidget
{
	Q_OBJECT

public:
	NoticesCommentItem(QWidget *parent = Q_NULLPTR);
	~NoticesCommentItem();
	void setValue(const sUrielCommentData & st);

signals:
	void CommentSiganl(const QString & name);
	private slots:
	void onCommentClicked();
private:
	Ui::NoticesCommentItem ui;
};
