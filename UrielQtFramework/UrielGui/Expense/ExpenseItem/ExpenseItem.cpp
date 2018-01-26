#include "ExpenseItem.h"

ExpenseItem::ExpenseItem(QPoint point, QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	initializeUI(point);
	setSignalsAndSlots();
}

ExpenseItem::~ExpenseItem()
{
}

void ExpenseItem::initializeUI(QPoint point)
{
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);

	this->move(point.x() + 45, point.y() - 20);
}

void ExpenseItem::setSignalsAndSlots()
{
	QObject::connect(ui.LocalTransportation, &QRadioButton::clicked, [&]() {
		emit expenseItemSignal(ExpenseItemEnum::LocalTransportation); this->accept(); });
	QObject::connect(ui.OfficeSupplies, &QRadioButton::clicked, [&]() {
		emit expenseItemSignal(ExpenseItemEnum::OfficeSupplies); this->accept(); });
	QObject::connect(ui.PurchaseOfProfessionalMaterials, &QRadioButton::clicked, [&]() {
		emit expenseItemSignal(ExpenseItemEnum::PurchaseOfProfessionalMaterials); this->accept(); });
	QObject::connect(ui.PurchaseOfExperimentalMaterials, &QRadioButton::clicked, [&]() {
		emit expenseItemSignal(ExpenseItemEnum::PurchaseOfExperimentalMaterials); this->accept(); });
	QObject::connect(ui.SportingGoodsPurchaseFee, &QRadioButton::clicked, [&]() {
		emit expenseItemSignal(ExpenseItemEnum::SportingGoodsPurchaseFee); this->accept(); });
	QObject::connect(ui.XeroxFee, &QRadioButton::clicked, [&]() {
		emit expenseItemSignal(ExpenseItemEnum::XeroxFee);  this->accept(); });
	QObject::connect(ui.Typography, &QRadioButton::clicked, [&]() {
		emit expenseItemSignal(ExpenseItemEnum::Typography); this->accept(); });
	QObject::connect(ui.MaterialTestingAndProcessingFee, &QRadioButton::clicked, [&]() {
		emit expenseItemSignal(ExpenseItemEnum::MaterialTestingAndProcessingFee);  this->accept(); });

	QObject::connect(ui.LodgingExpenses, &QRadioButton::clicked, [&]() {
		emit expenseItemSignal(ExpenseItemEnum::LodgingExpenses); this->accept(); });
	QObject::connect(ui.StudentActivityFee, &QRadioButton::clicked, [&]() {
		emit expenseItemSignal(ExpenseItemEnum::StudentActivityFee); this->accept(); });
	QObject::connect(ui.Correspondence, &QRadioButton::clicked, [&]() {
		emit expenseItemSignal(ExpenseItemEnum::Correspondence); this->accept(); });
	QObject::connect(ui.PostFee, &QRadioButton::clicked, [&]() {
		emit expenseItemSignal(ExpenseItemEnum::PostFee); this->accept(); });
	QObject::connect(ui.SelfServiceCost, &QRadioButton::clicked, [&]() {
		emit expenseItemSignal(ExpenseItemEnum::SelfServiceCost);  this->accept(); });
	QObject::connect(ui.MotorVehicleMaintenance, &QRadioButton::clicked, [&]() {
		emit expenseItemSignal(ExpenseItemEnum::MotorVehicleMaintenance); this->accept(); });
	QObject::connect(ui.OfficeEquipmentMaintenance, &QRadioButton::clicked, [&]() {
		emit expenseItemSignal(ExpenseItemEnum::OfficeEquipmentMaintenance);  this->accept(); });
	QObject::connect(ui.EquipmentMaintenanceFee, &QRadioButton::clicked, [&]() {
		emit expenseItemSignal(ExpenseItemEnum::EquipmentMaintenanceFee);  this->accept(); });

	QObject::connect(ui.TrainingFees, &QRadioButton::clicked, [&]() {
		emit expenseItemSignal(ExpenseItemEnum::TrainingFees); this->accept(); });
	QObject::connect(ui.EntertainmentExpense, &QRadioButton::clicked, [&]() {
		emit expenseItemSignal(ExpenseItemEnum::EntertainmentExpense);  this->accept(); });
	QObject::connect(ui.ConstructionOfFixedAssets, &QRadioButton::clicked, [&]() {
		emit expenseItemSignal(ExpenseItemEnum::ConstructionOfFixedAssets); this->accept(); });
	QObject::connect(ui.Streamer, &QRadioButton::clicked, [&]() {
		emit expenseItemSignal(ExpenseItemEnum::Streamer);  this->accept(); });
	QObject::connect(ui.Other, &QRadioButton::clicked, [&]() {
		emit expenseItemSignal(ExpenseItemEnum::Other);  this->accept(); });
}