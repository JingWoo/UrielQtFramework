#include "LiftingProhibitionDialog.h"
#include "UrielDatabase\UrielDatabase.h"
LiftingProhibitionDialog::LiftingProhibitionDialog(UrielDatabase *database, QWidget *parent)
	: QDialog(parent), m_pDatabase(database)
{
	ui.setupUi(this);
	initializeUI(parent);
	setSignalsAndSlots();
	//ui.Title->setText(title);
}

LiftingProhibitionDialog::~LiftingProhibitionDialog()
{
}

void LiftingProhibitionDialog::initializeUI(QWidget *parent)
{
	this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());
	//this->setAttribute(Qt::WA_TranslucentBackground, true);

	this->resize(parent->geometry().width(), parent->geometry().height() - 45);
	this->move(parent->x(), parent->y() + 45);
	//set as Transparent degree
	//setWindowOpacity(0.7);
	QStringList FinishReimburseCodeList;
	m_pDatabase->getFinishReimburseCode(FinishReimburseCodeList);
	if (!FinishReimburseCodeList.size())
		ui.comboBox->addItem(QStringLiteral("无可解禁代号"));
	else
	   ui.comboBox->addItems(FinishReimburseCodeList);
}

void LiftingProhibitionDialog::setSignalsAndSlots() 
{
	QObject::connect(ui.Cancel, &QToolButton::clicked, [&]() {
		this->reject(); });
	QObject::connect(ui.OK, &QToolButton::clicked, [&]() {
		emit contentSignal(ui.comboBox->currentText());
		this->accept(); });
}