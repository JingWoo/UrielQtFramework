#include "InstrumentBorrowReturnHistory.h"
#include <QAction>
#include <QSortFilterProxyModel>
#include "UrielDatabase\UrielDatabase.h"
#include "UrielModel\InstrumentBorrowReturnHistoryTableModel\InstrumentBRHistoryTableModel.h"
#include "UrielGui\DevicePage\InstrumentBorrowReturn\InstrumentBorrowReturn.h"
InstrumentBorrowReturnHistory::InstrumentBorrowReturnHistory(UrielDatabase * database, const QString & id, QWidget *parent)
	: QDialog(parent), m_database(database), m_sInstrumemtId(id), m_pInstrumentBorrowReturnDialog(new InstrumentBorrowReturn(database, parent))
{
	ui.setupUi(this);
	initializeUI(parent);
	setSignalsAndSlots();
}

InstrumentBorrowReturnHistory::~InstrumentBorrowReturnHistory()
{
	if (m_pInstrumentBorrowReturnDialog)
	{
		delete m_pInstrumentBorrowReturnDialog;
		m_pInstrumentBorrowReturnDialog = nullptr;
	}
}

void InstrumentBorrowReturnHistory::initializeUI(QWidget *parent)
{
	this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());
	//this->setAttribute(Qt::WA_TranslucentBackground, true);

	this->resize(parent->geometry().width(), parent->geometry().height() - 45);
	this->move(parent->x(), parent->y() + 45);
	//set as Transparent degree
	//setWindowOpacity(0.7);
	ui.tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableView->setSortingEnabled(true);
	ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	//ui.tableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
	ui.tableView->setShowGrid(false);
	ui.tableView->horizontalHeader()->setVisible(true);
	ui.tableView->verticalHeader()->setVisible(false);
	ui.tableView->setAlternatingRowColors(true);
	ui.tableView->setMouseTracking(true);
	ui.tableView->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.tableView->setContextMenuPolicy(Qt::ActionsContextMenu);
	ui.tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
	QAction *ViewDetailAction = new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/detail.png"), QStringLiteral("查看细节"), this);
	QAction *CurrentInstrumentAction = new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/currentInstrument.png"), QStringLiteral("当前仪器"), this);
	QAction *AllInstrumentAction = new QAction(QIcon(":/Mainwindow/Resources/UrielQtFramework/allInstrument.png"), QStringLiteral("所有仪器"), this);
	ui.tableView->addAction(ViewDetailAction);
	ui.tableView->addAction(CurrentInstrumentAction);
	ui.tableView->addAction(AllInstrumentAction);
	QObject::connect(ViewDetailAction, &QAction::triggered, this, &InstrumentBorrowReturnHistory::onViewDetailActionTriggered);
	QObject::connect(CurrentInstrumentAction, &QAction::triggered, this, &InstrumentBorrowReturnHistory::onCurrentInstrumentActionTriggered);
	QObject::connect(AllInstrumentAction, &QAction::triggered, this, &InstrumentBorrowReturnHistory::onAllInstrumentActionTriggered);
	m_pUrielInstrumentBorrowReturnHistoryTableModel = m_database->creatInstrumentBorrowReturnHistoryTableModel();
	m_pUrielInstrumentBorrowReturnHistoryTableSortFilterModel = new QSortFilterProxyModel;
	m_pUrielInstrumentBorrowReturnHistoryTableSortFilterModel->setDynamicSortFilter(true);
	m_pUrielInstrumentBorrowReturnHistoryTableSortFilterModel->setSourceModel(m_pUrielInstrumentBorrowReturnHistoryTableModel);
	ui.tableView->setModel(m_pUrielInstrumentBorrowReturnHistoryTableSortFilterModel);
	QObject::connect(ui.tableView, static_cast<void (QTableView::*)(const QModelIndex &)>(&QTableView::pressed), this, &InstrumentBorrowReturnHistory::onInstrumentBorrowReturnHistoryItemPressed);
	ui.tableView->setColumnHidden(0, true);
	QList<int> wdls;
	wdls << 0 << 80 << 250 << 80 << 250 << 120 << 80 << 80;
	for (int i = 0; i < wdls.size(); i++)
	{
		ui.tableView->setColumnWidth(i, wdls[i]);
	}
	onCurrentInstrumentActionTriggered();
}

void InstrumentBorrowReturnHistory::setSignalsAndSlots()
{
	QObject::connect(ui.AppClose, &QToolButton::clicked, this, &InstrumentBorrowReturnHistory::reject);
}

void  InstrumentBorrowReturnHistory::onCurrentInstrumentActionTriggered()
{
	QString strSQL = " WHERE INSTRUMENT_KEY = '" + m_sInstrumemtId + "'";
	m_database->updateInstrumentBorrowReturnHistoryTableModel(strSQL);
}

void  InstrumentBorrowReturnHistory::onAllInstrumentActionTriggered()
{
	m_database->updateInstrumentBorrowReturnHistoryTableModel();
}

void InstrumentBorrowReturnHistory::onInstrumentBorrowReturnHistoryItemPressed(const QModelIndex &)
{

}

void InstrumentBorrowReturnHistory::onViewDetailActionTriggered()
{
	QString useId;
	sUrielInstrumentUseLog logItem;
	QModelIndex index = ui.tableView->currentIndex();
	if (index.isValid())
	{
		int mIndex = index.row();
		QModelIndex idx = index.sibling(mIndex, 0);
		if (idx.isValid())
			useId = idx.data().toString();
	}
	if (m_database->getInstrumentUseLogByID(logItem, useId))
	{
		m_pInstrumentBorrowReturnDialog->setValueInViewModel(logItem);
		m_pInstrumentBorrowReturnDialog->exec();
	}
		
}