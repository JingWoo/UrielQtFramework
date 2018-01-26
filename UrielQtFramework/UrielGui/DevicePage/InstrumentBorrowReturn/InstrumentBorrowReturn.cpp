#include "InstrumentBorrowReturn.h"
#include <QMessageBox>
#include "UrielDatabase\UrielDatabase.h"
#include "UrielQtFrameworkOptions\UrielQtFrameworkOptions.h"
InstrumentBorrowReturn::InstrumentBorrowReturn(UrielDatabase * database, QWidget *parent)
	: QDialog(parent), m_database(database)
{
	ui.setupUi(this);
	initializeUI(parent);
	setSignalsAndSlots();
}

InstrumentBorrowReturn::~InstrumentBorrowReturn()
{
}

void InstrumentBorrowReturn::initializeUI(QWidget *parent)
{
	this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());
	//this->setAttribute(Qt::WA_TranslucentBackground, true);

	this->resize(parent->geometry().width(), parent->geometry().height() - 45);
	this->move(parent->x(), parent->y() + 45);
	//set as Transparent degree
	//setWindowOpacity(0.7);

	ui.InstrumentName->setEnabled(false);
	ui.Auditor->setEnabled(false);
	ui.BorrowReturnTime->setEnabled(false); 
	ui.LendStatus->setEnabled(false);
	ui.ReturnStatus->setEnabled(false);
}

void InstrumentBorrowReturn::setSignalsAndSlots()
{
	QObject::connect(ui.AppClose, &QToolButton::clicked, this, &InstrumentBorrowReturn::reject);
	QObject::connect(ui.ConfirmOperation, &QToolButton::clicked, this, &InstrumentBorrowReturn::onConfirmOperationClicked);
	
}

void InstrumentBorrowReturn::setSomeInfo(const sUrielInstrumentItem &InstrumentItem)
{
	m_stUrielInstrumentUseLog.m_sInstrumentKey = QString::number(InstrumentItem.m_iId);
	m_stUrielInstrumentUseLog.m_sInstrumentName = InstrumentItem.m_sName;
	m_stUrielInstrumentUseLog.m_sBorrowReturnStatus = InstrumentItem.m_sStatus;
	ui.InstrumentName->setText(m_stUrielInstrumentUseLog.m_sInstrumentName);
	if (m_stUrielInstrumentUseLog.m_sBorrowReturnStatus == QStringLiteral("借出"))
	{
		ui.LendStatus->setChecked(true);
		ui.ConfirmOperation->setText(QStringLiteral("确认归还"));
	}
	else
	{
		ui.ReturnStatus->setChecked(true);
		ui.ConfirmOperation->setText(QStringLiteral("确认借出"));
	}
	UrielQtFrameworkOptions *gOptions = UrielQtFrameworkOptions::getInstance();
	m_stUrielInstrumentUseLog.m_sAuditor = gOptions->getAccount();
	ui.Auditor->setText(gOptions->getAccount());
	gOptions = nullptr;
	ui.BorrowReturnTime->setDateTime(QDateTime::currentDateTime());
}


void InstrumentBorrowReturn::setValueInViewModel(const sUrielInstrumentUseLog & item)
{
	ui.BorrowReturnStatus->setText(QStringLiteral("借还状态"));
	ui.InstrumentName->setText(item.m_sInstrumentName);
	ui.BorrowReturnAddress->setText(item.m_sBorrowReturnAddress);
	ui.BorrowReturnStaffName->setText(item.m_sBorrowReturnStaff);
	ui.Auditor->setText(item.m_sAuditor);
	ui.BorrowReturnTime->setDateTime(item.m_sBorrowReturnTime);
	if (item.m_sBorrowReturnStatus == QStringLiteral("借出"))
		ui.LendStatus->setChecked(true);
	else
		ui.ReturnStatus->setChecked(true);
	ui.UseDescription->setPlainText(item.m_sDescription);
	ui.ConfirmOperation->setVisible(false);
}

void InstrumentBorrowReturn::onConfirmOperationClicked()
{
	m_stUrielInstrumentUseLog.m_sBorrowReturnStaff = ui.BorrowReturnStaffName->text();
	m_stUrielInstrumentUseLog.m_sBorrowReturnTime = ui.BorrowReturnTime->dateTime();
	m_stUrielInstrumentUseLog.m_sBorrowReturnAddress = ui.BorrowReturnAddress->text();
	if (ui.ConfirmOperation->text() == QStringLiteral("确认归还"))
		m_stUrielInstrumentUseLog.m_sBorrowReturnStatus = QStringLiteral("归还");
	else
		m_stUrielInstrumentUseLog.m_sBorrowReturnStatus = QStringLiteral("借出");
	m_stUrielInstrumentUseLog.m_sDescription = ui.UseDescription->toPlainText();

	QString sError;
	m_database->insertInstrumentUseLog(m_stUrielInstrumentUseLog, sError);
	if (!sError.isEmpty())
	{
		QMessageBox::critical(this, QStringLiteral("错误"), QStringLiteral("添加至数据库失败，请联系管理员修复问题！"));
		return;
	}
	m_database->updateInstrumentWithStatusAndAddressByID(m_stUrielInstrumentUseLog.m_sBorrowReturnStatus, ui.BorrowReturnAddress->text(), m_stUrielInstrumentUseLog.m_sInstrumentKey);
	this->accept();
}