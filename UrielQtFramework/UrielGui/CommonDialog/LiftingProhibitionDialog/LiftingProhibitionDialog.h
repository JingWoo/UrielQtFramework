#pragma once

#include <QDialog>
#include "ui_LiftingProhibitionDialog.h"
QT_FORWARD_DECLARE_CLASS(UrielDatabase)
class LiftingProhibitionDialog : public QDialog
{
	Q_OBJECT

public:
	LiftingProhibitionDialog(UrielDatabase *database, QWidget *parent = Q_NULLPTR);
	~LiftingProhibitionDialog();
signals:
	void contentSignal(const QString & content);
private:
	void initializeUI(QWidget *parent = Q_NULLPTR);
	void setSignalsAndSlots();
private:
	Ui::LiftingProhibitionDialog ui;
	UrielDatabase * m_pDatabase;
	
};
