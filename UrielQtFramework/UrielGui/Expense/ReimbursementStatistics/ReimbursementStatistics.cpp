#include "ReimbursementStatistics.h"
#include <QToolButton>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <QtCharts/QChartView>
#include <QTime>
#include "UrielGui\CommonDialog\UrielPieCharts\donutbreakdownchart.h"

//enum class ExpenseItemEnum
//{
//	LocalTransportation,//���ڽ�ͨ��
//	OfficeSupplies,//�칫��Ʒ
//	PurchaseOfProfessionalMaterials, //רҵ���Ϲ��÷�
//	PurchaseOfExperimentalMaterials,//ʵ����Ϲ��÷�
//	SportingGoodsPurchaseFee,//������Ʒ���÷�
//	XeroxFee,//���ϸ�ӡ��
//	Typography,//����ӡˢ��
//	MaterialTestingAndProcessingFee,//���ϲ��Լӹ���
//	LodgingExpenses,//ʵϰ��
//	StudentActivityFee,//ѧ�����
//	Correspondence,//ͨѶ��
//	PostFee,//�ʼķ�
//	SelfServiceCost,//�Ա�������
//	MotorVehicleMaintenance,//������ά�޷�
//	OfficeEquipmentMaintenance,//�칫�豸ά�޷�
//	EquipmentMaintenanceFee,//�����豸ά�޷�
//	TrainingFees,//��ѵ��
//	EntertainmentExpense,//�д���
//	ConstructionOfFixedAssets,//�̶��ʲ�������
//	Streamer,//���
//	Other//����
//};
void ReimbursementStatistics::setPMInvoiceList(const QList<sUrielInvoiceInfoItem>& InvoiceList) {
	m_PMInvoiceList = InvoiceList;
}
void ReimbursementStatistics::setExpenseOperationModel(const ExpenseOperationModel & OperationModel) {
   m_eExpenseOperationModel= OperationModel;
}

void ReimbursementStatistics::setCMInvoiceList(const QHash<QString, QList<sUrielInvoiceInfoItem>> & CMInvoiceList) {
	m_hCMInvoiceList = CMInvoiceList;
}
QVector<QList<sUrielInvoiceInfoItem>> ReimbursementStatistics::getInvoiceListVectorByProject(const QList<sUrielInvoiceInfoItem>& InvoiceList){
	QVector<QList<sUrielInvoiceInfoItem>> invoiceListVector(21);
	for each (sUrielInvoiceInfoItem var in InvoiceList)
	{
		if (var.m_sType == QStringLiteral("���ڽ�ͨ��")) {
			invoiceListVector[static_cast<int>(ExpenseItemEnum::LocalTransportation)] << var;
		}
		else if (var.m_sType == QStringLiteral("�칫��Ʒ")) {
			invoiceListVector[static_cast<int>(ExpenseItemEnum::OfficeSupplies)] << var;
		}
		else if (var.m_sType == QStringLiteral("רҵ���Ϲ��÷�")) {
			invoiceListVector[static_cast<int>(ExpenseItemEnum::PurchaseOfProfessionalMaterials)] << var;
		}
		else if (var.m_sType == QStringLiteral("ʵ����Ϲ��÷�")) {
			invoiceListVector[static_cast<int>(ExpenseItemEnum::PurchaseOfExperimentalMaterials)] << var;
		}
		else if (var.m_sType == QStringLiteral("������Ʒ���÷�")) {
			invoiceListVector[static_cast<int>(ExpenseItemEnum::SportingGoodsPurchaseFee)] << var;
		}
		else if (var.m_sType == QStringLiteral("���ϸ�ӡ��")) {
			invoiceListVector[static_cast<int>(ExpenseItemEnum::XeroxFee)] << var;
		}
		else if (var.m_sType == QStringLiteral("����ӡˢ��")) {
			invoiceListVector[static_cast<int>(ExpenseItemEnum::Typography)] << var;
		}
		else if (var.m_sType == QStringLiteral("���ϲ��Լӹ���")) {
			invoiceListVector[static_cast<int>(ExpenseItemEnum::MaterialTestingAndProcessingFee)] << var;
		}
		else if (var.m_sType == QStringLiteral("ʵϰ��")) {
			invoiceListVector[static_cast<int>(ExpenseItemEnum::LodgingExpenses)] << var;
		}
		else if (var.m_sType == QStringLiteral("ѧ�����")) {
			invoiceListVector[static_cast<int>(ExpenseItemEnum::StudentActivityFee)] << var;
		}
		else if (var.m_sType == QStringLiteral("ͨѶ��")) {
			invoiceListVector[static_cast<int>(ExpenseItemEnum::Correspondence)] << var;
		}
		else if (var.m_sType == QStringLiteral("�ʼķ�")) {
			invoiceListVector[static_cast<int>(ExpenseItemEnum::PostFee)] << var;
		}
		else if (var.m_sType == QStringLiteral("�Ա�������")) {
			invoiceListVector[static_cast<int>(ExpenseItemEnum::SelfServiceCost)] << var;
		}
		else if (var.m_sType == QStringLiteral("������ά�޷�")) {
			invoiceListVector[static_cast<int>(ExpenseItemEnum::MotorVehicleMaintenance)] << var;
		}
		else if (var.m_sType == QStringLiteral("�칫�豸ά�޷�")) {
			invoiceListVector[static_cast<int>(ExpenseItemEnum::OfficeEquipmentMaintenance)] << var;
		}
		else if (var.m_sType == QStringLiteral("�����豸ά�޷�")) {
			invoiceListVector[static_cast<int>(ExpenseItemEnum::EquipmentMaintenanceFee)] << var;
		}
		else if (var.m_sType == QStringLiteral("��ѵ��")) {
			invoiceListVector[static_cast<int>(ExpenseItemEnum::TrainingFees)] << var;
		}
		else if (var.m_sType == QStringLiteral("�д���")) {
			invoiceListVector[static_cast<int>(ExpenseItemEnum::EntertainmentExpense)] << var;
		}
		else if (var.m_sType == QStringLiteral("�̶��ʲ�������")) {
			invoiceListVector[static_cast<int>(ExpenseItemEnum::ConstructionOfFixedAssets)] << var;
		}
		else if (var.m_sType == QStringLiteral("���")) {
			invoiceListVector[static_cast<int>(ExpenseItemEnum::Streamer)] << var;
		}
		else if (var.m_sType == QStringLiteral("����")) {
			invoiceListVector[static_cast<int>(ExpenseItemEnum::Other)] << var;
		}
	}
	return invoiceListVector;
}
ReimbursementStatistics::ReimbursementStatistics(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	initializeUI(parent);
}
void ReimbursementStatistics::showReport() {
	DonutBreakdownChart *donutBreakdown = new DonutBreakdownChart();
	donutBreakdown->setAnimationOptions(QChart::AllAnimations);
	donutBreakdown->legend()->setAlignment(Qt::AlignRight);

	QList<QPieSeries*> SeriesList;
	if (m_eExpenseOperationModel == ExpenseOperationModel::PersonalModel || m_eExpenseOperationModel == ExpenseOperationModel::HistoryModel)
	{
		donutBreakdown->setTitle(QStringLiteral("�㽭��ѧ���˱�������ͳ��"));
		QVector<QList<sUrielInvoiceInfoItem>> invoiceListVector = getInvoiceListVectorByProject(m_PMInvoiceList);

		if (invoiceListVector[static_cast<int>(ExpenseItemEnum::LocalTransportation)].size()) {
			QPieSeries * series = new QPieSeries();
			series->setName(QStringLiteral("���ڽ�ͨ��"));
			for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::LocalTransportation)])
			{
				series->append(var.m_sName, var.m_dAggregateAmount);
			}
			SeriesList << series;
		}
		if (invoiceListVector[static_cast<int>(ExpenseItemEnum::OfficeSupplies)].size()) {
			QPieSeries *series = new QPieSeries();
			series->setName(QStringLiteral("�칫��Ʒ"));
			for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::OfficeSupplies)])
			{
				series->append(var.m_sName, var.m_dAggregateAmount);
			}
			SeriesList << series;
		}
		if (invoiceListVector[static_cast<int>(ExpenseItemEnum::PurchaseOfProfessionalMaterials)].size()) {
			QPieSeries *series = new QPieSeries();
			series->setName(QStringLiteral("רҵ���Ϲ��÷�"));
			for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::PurchaseOfProfessionalMaterials)])
			{
				series->append(var.m_sName, var.m_dAggregateAmount);
			}
			SeriesList << series;
		}
		if (invoiceListVector[static_cast<int>(ExpenseItemEnum::PurchaseOfExperimentalMaterials)].size()) {
			QPieSeries *series = new QPieSeries();
			series->setName(QStringLiteral("ʵ����Ϲ��÷�"));
			for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::PurchaseOfExperimentalMaterials)])
			{
				series->append(var.m_sName, var.m_dAggregateAmount);
			}
			SeriesList << series;
		}
		if (invoiceListVector[static_cast<int>(ExpenseItemEnum::SportingGoodsPurchaseFee)].size()) {
			QPieSeries *series = new QPieSeries();
			series->setName(QStringLiteral("������Ʒ���÷�"));
			for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::SportingGoodsPurchaseFee)])
			{
				series->append(var.m_sName, var.m_dAggregateAmount);
			}
			SeriesList << series;
		}
		if (invoiceListVector[static_cast<int>(ExpenseItemEnum::XeroxFee)].size()) {
			QPieSeries *series = new QPieSeries();
			series->setName(QStringLiteral("���ϸ�ӡ��"));
			for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::XeroxFee)])
			{
				series->append(var.m_sName, var.m_dAggregateAmount);
			}
			SeriesList << series;
		}
		if (invoiceListVector[static_cast<int>(ExpenseItemEnum::Typography)].size()) {
			QPieSeries *series = new QPieSeries();
			series->setName(QStringLiteral("����ӡˢ��"));
			for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::Typography)])
			{
				series->append(var.m_sName, var.m_dAggregateAmount);
			}
			SeriesList << series;
		}
		if (invoiceListVector[static_cast<int>(ExpenseItemEnum::MaterialTestingAndProcessingFee)].size()) {
			QPieSeries *series = new QPieSeries();
			series->setName(QStringLiteral("���ϲ��Լӹ���"));
			for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::MaterialTestingAndProcessingFee)])
			{
				series->append(var.m_sName, var.m_dAggregateAmount);
			}
			SeriesList << series;
		}
		if (invoiceListVector[static_cast<int>(ExpenseItemEnum::LodgingExpenses)].size()) {
			QPieSeries *series = new QPieSeries();
			series->setName(QStringLiteral("ʵϰ��"));
			for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::LodgingExpenses)])
			{
				series->append(var.m_sName, var.m_dAggregateAmount);
			}
			SeriesList << series;
		}
		if (invoiceListVector[static_cast<int>(ExpenseItemEnum::StudentActivityFee)].size()) {
			QPieSeries *series = new QPieSeries();
			series->setName(QStringLiteral("ѧ�����"));
			for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::StudentActivityFee)])
			{
				series->append(var.m_sName, var.m_dAggregateAmount);
			}
			SeriesList << series;
		}
		if (invoiceListVector[static_cast<int>(ExpenseItemEnum::Correspondence)].size()) {
			QPieSeries *series = new QPieSeries();
			series->setName(QStringLiteral("ͨѶ��"));
			for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::Correspondence)])
			{
				series->append(var.m_sName, var.m_dAggregateAmount);
			}
			SeriesList << series;
		}
		if (invoiceListVector[static_cast<int>(ExpenseItemEnum::PostFee)].size()) {
			QPieSeries *series = new QPieSeries();
			series->setName(QStringLiteral("�ʼķ�"));
			for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::PostFee)])
			{
				series->append(var.m_sName, var.m_dAggregateAmount);
			}
			SeriesList << series;
		}
		if (invoiceListVector[static_cast<int>(ExpenseItemEnum::SelfServiceCost)].size()) {
			QPieSeries *series = new QPieSeries();
			series->setName(QStringLiteral("�Ա�������"));
			for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::SelfServiceCost)])
			{
				series->append(var.m_sName, var.m_dAggregateAmount);
			}
			SeriesList << series;
		}
		if (invoiceListVector[static_cast<int>(ExpenseItemEnum::MotorVehicleMaintenance)].size()) {
			QPieSeries *series = new QPieSeries();
			series->setName(QStringLiteral("������ά�޷�"));
			for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::MotorVehicleMaintenance)])
			{
				series->append(var.m_sName, var.m_dAggregateAmount);
			}
			SeriesList << series;
		}
		if (invoiceListVector[static_cast<int>(ExpenseItemEnum::OfficeEquipmentMaintenance)].size()) {
			QPieSeries *series = new QPieSeries();
			series->setName(QStringLiteral("�칫�豸ά�޷�"));
			for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::OfficeEquipmentMaintenance)])
			{
				series->append(var.m_sName, var.m_dAggregateAmount);
			}
			SeriesList << series;
		}
		if (invoiceListVector[static_cast<int>(ExpenseItemEnum::EquipmentMaintenanceFee)].size()) {
			QPieSeries *series = new QPieSeries();
			series->setName(QStringLiteral("�����豸ά�޷�"));
			for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::EquipmentMaintenanceFee)])
			{
				series->append(var.m_sName, var.m_dAggregateAmount);
			}
			SeriesList << series;
		}
		if (invoiceListVector[static_cast<int>(ExpenseItemEnum::TrainingFees)].size()) {
			QPieSeries *series = new QPieSeries();
			series->setName(QStringLiteral("��ѵ��"));
			for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::TrainingFees)])
			{
				series->append(var.m_sName, var.m_dAggregateAmount);
			}
			SeriesList << series;
		}
		if (invoiceListVector[static_cast<int>(ExpenseItemEnum::EntertainmentExpense)].size()) {
			QPieSeries *series = new QPieSeries();
			series->setName(QStringLiteral("�д���"));
			for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::EntertainmentExpense)])
			{
				series->append(var.m_sName, var.m_dAggregateAmount);
			}
			SeriesList << series;
		}
		if (invoiceListVector[static_cast<int>(ExpenseItemEnum::ConstructionOfFixedAssets)].size()) {
			QPieSeries *series = new QPieSeries();
			series->setName(QStringLiteral("�̶��ʲ�������"));
			for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::ConstructionOfFixedAssets)])
			{
				series->append(var.m_sName, var.m_dAggregateAmount);
			}
			SeriesList << series;
		}
		if (invoiceListVector[static_cast<int>(ExpenseItemEnum::Streamer)].size()) {
			QPieSeries *series = new QPieSeries();
			series->setName(QStringLiteral("���"));
			for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::Streamer)])
			{
				series->append(var.m_sName, var.m_dAggregateAmount);
			}
			SeriesList << series;
		}
		if (invoiceListVector[static_cast<int>(ExpenseItemEnum::Other)].size()) {
			QPieSeries *series = new QPieSeries();
			series->setName(QStringLiteral("����"));
			for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::Other)])
			{
				series->append(var.m_sName, var.m_dAggregateAmount);
			}
			SeriesList << series;
		}
	}
	else {
		donutBreakdown->setTitle(QStringLiteral("�㽭��ѧ��������ͳ��"));
		//QHash<QString, QList<sUrielInvoiceInfoItem>> m_hCMInvoiceList;
		QHash<QString, QList<sUrielInvoiceInfoItem>>::const_iterator iter = m_hCMInvoiceList.constBegin();
		for (iter; iter != m_hCMInvoiceList.constEnd(); ++iter) {
			QPieSeries *series = new QPieSeries();
			series->setName(iter.key());
			QVector<QList<sUrielInvoiceInfoItem>> invoiceListVector = getInvoiceListVectorByProject(iter.value());
			if (invoiceListVector[static_cast<int>(ExpenseItemEnum::LocalTransportation)].size()) {
				double value = 0.0;
				for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::LocalTransportation)])
				{
					value += var.m_dAggregateAmount;
				}
				series->append(QStringLiteral("���ڽ�ͨ��"), value);
			}
			if (invoiceListVector[static_cast<int>(ExpenseItemEnum::OfficeSupplies)].size()) {
				double value = 0.0;
				for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::OfficeSupplies)])
				{
					value += var.m_dAggregateAmount;
				}
				series->append(QStringLiteral("�칫��Ʒ"), value);
			}
			if (invoiceListVector[static_cast<int>(ExpenseItemEnum::PurchaseOfProfessionalMaterials)].size()) {
				double value = 0.0;
				for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::PurchaseOfProfessionalMaterials)])
				{
					value += var.m_dAggregateAmount;
				}
				series->append(QStringLiteral("רҵ���Ϲ��÷�"), value);
			}
			if (invoiceListVector[static_cast<int>(ExpenseItemEnum::PurchaseOfExperimentalMaterials)].size()) {
				double value = 0.0;
				for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::PurchaseOfExperimentalMaterials)])
				{
					value += var.m_dAggregateAmount;
				}
				series->append(QStringLiteral("ʵ����Ϲ��÷�"), value);
			}
			if (invoiceListVector[static_cast<int>(ExpenseItemEnum::SportingGoodsPurchaseFee)].size()) {
				double value = 0.0;
				for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::SportingGoodsPurchaseFee)])
				{
					value += var.m_dAggregateAmount;
				}
				series->append(QStringLiteral("������Ʒ���÷�"), value);
			}
			if (invoiceListVector[static_cast<int>(ExpenseItemEnum::XeroxFee)].size()) {
				double value = 0.0;
				for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::XeroxFee)])
				{
					value += var.m_dAggregateAmount;
				}
				series->append(QStringLiteral("���ϸ�ӡ��"), value);
			}
			if (invoiceListVector[static_cast<int>(ExpenseItemEnum::Typography)].size()) {
				double value = 0.0;
				for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::Typography)])
				{
					value += var.m_dAggregateAmount;
				}
				series->append(QStringLiteral("����ӡˢ��"), value);
			}
			if (invoiceListVector[static_cast<int>(ExpenseItemEnum::MaterialTestingAndProcessingFee)].size()) {
				double value = 0.0;
				for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::MaterialTestingAndProcessingFee)])
				{
					value += var.m_dAggregateAmount;
				}
				series->append(QStringLiteral("���ϲ��Լӹ���"), value);
			}
			if (invoiceListVector[static_cast<int>(ExpenseItemEnum::LodgingExpenses)].size()) {
				double value = 0.0;
				for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::LodgingExpenses)])
				{
					value += var.m_dAggregateAmount;
				}
				series->append(QStringLiteral("ʵϰ��"), value);
			}
			if (invoiceListVector[static_cast<int>(ExpenseItemEnum::StudentActivityFee)].size()) {
				double value = 0.0;
				for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::StudentActivityFee)])
				{
					value += var.m_dAggregateAmount;
				}
				series->append(QStringLiteral("ѧ�����"), value);
			}
			if (invoiceListVector[static_cast<int>(ExpenseItemEnum::Correspondence)].size()) {
				double value = 0.0;
				for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::Correspondence)])
				{
					value += var.m_dAggregateAmount;
				}
				series->append(QStringLiteral("ͨѶ��"), value);
			}
			if (invoiceListVector[static_cast<int>(ExpenseItemEnum::PostFee)].size()) {
				double value = 0.0;
				for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::PostFee)])
				{
					value += var.m_dAggregateAmount;
				}
				series->append(QStringLiteral("�ʼķ�"), value);
			}
			if (invoiceListVector[static_cast<int>(ExpenseItemEnum::SelfServiceCost)].size()) {
				double value = 0.0;
				for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::SelfServiceCost)])
				{
					value += var.m_dAggregateAmount;
				}
				series->append(QStringLiteral("�Ա�������"), value);
			}
			if (invoiceListVector[static_cast<int>(ExpenseItemEnum::MotorVehicleMaintenance)].size()) {
				double value = 0.0;
				for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::MotorVehicleMaintenance)])
				{
					value += var.m_dAggregateAmount;
				}
				series->append(QStringLiteral("������ά�޷�"), value);
			}
			if (invoiceListVector[static_cast<int>(ExpenseItemEnum::OfficeEquipmentMaintenance)].size()) {
				double value = 0.0;
				for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::OfficeEquipmentMaintenance)])
				{
					value += var.m_dAggregateAmount;
				}
				series->append(QStringLiteral("�칫�豸ά�޷�"), value);
			}
			if (invoiceListVector[static_cast<int>(ExpenseItemEnum::EquipmentMaintenanceFee)].size()) {
				double value = 0.0;
				for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::EquipmentMaintenanceFee)])
				{
					value += var.m_dAggregateAmount;
				}
				series->append(QStringLiteral("�����豸ά�޷�"), value);
			}
			if (invoiceListVector[static_cast<int>(ExpenseItemEnum::TrainingFees)].size()) {
				double value = 0.0;
				for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::TrainingFees)])
				{
					value += var.m_dAggregateAmount;
				}
				series->append(QStringLiteral("��ѵ��"), value);
			}
			if (invoiceListVector[static_cast<int>(ExpenseItemEnum::EntertainmentExpense)].size()) {
				double value = 0.0;
				for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::EntertainmentExpense)])
				{
					value += var.m_dAggregateAmount;
				}
				series->append(QStringLiteral("�д���"), value);
			}
			if (invoiceListVector[static_cast<int>(ExpenseItemEnum::ConstructionOfFixedAssets)].size()) {
				double value = 0.0;
				for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::ConstructionOfFixedAssets)])
				{
					value += var.m_dAggregateAmount;
				}
				series->append(QStringLiteral("�̶��ʲ�������"), value);
			}
			if (invoiceListVector[static_cast<int>(ExpenseItemEnum::Streamer)].size()) {
				double value = 0.0;
				for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::Streamer)])
				{
					value += var.m_dAggregateAmount;
				}
				series->append(QStringLiteral("���"), value);
			}
			if (invoiceListVector[static_cast<int>(ExpenseItemEnum::Other)].size()) {
				double value = 0.0;
				for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::Other)])
				{
					value += var.m_dAggregateAmount;
				}
				series->append(QStringLiteral("����"), value);
			}
			SeriesList << series;
		}
	}

	QTime time;
	time = QTime::currentTime();
	qsrand(time.msec() + time.second() * 1000);
	for each (QPieSeries* var in SeriesList)
	{
		donutBreakdown->addBreakdownSeries(var, QColor(qrand() % 255, qrand() % 255, qrand() % 255));
	}

	QChartView *chartView = new QChartView(donutBreakdown);
	chartView->setRenderHint(QPainter::Antialiasing);
	ui.horizontalLayout->addWidget(chartView);
	//QSpacerItem *horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
	//ui.horizontalLayout->addItem(horizontalSpacer);
	QFrame* frame = new QFrame(this);
	frame->setObjectName(QStringLiteral("frame"));
	frame->setMinimumSize(QSize(40, 0));
	frame->setFrameShape(QFrame::StyledPanel);
	frame->setFrameShadow(QFrame::Raised);
	QVBoxLayout *verticalLayout = new QVBoxLayout(frame);
	verticalLayout->setSpacing(0);
	verticalLayout->setContentsMargins(11, 11, 11, 11);
	verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
	verticalLayout->setContentsMargins(0, 0, 0, 0);
	QToolButton* toolButton = new QToolButton(frame);
	toolButton->setObjectName(QStringLiteral("toolButton"));
	toolButton->setMinimumSize(QSize(40, 40));
	QIcon icon;
	icon.addFile(QStringLiteral(":/Mainwindow/Resources/UrielQtFramework/close.png"), QSize(), QIcon::Normal, QIcon::Off);
	toolButton->setIcon(icon);
	toolButton->setIconSize(QSize(40, 40));
	toolButton->setAutoRaise(true);
	QObject::connect(toolButton, &QToolButton::clicked, [&]() {
		this->accept(); });
	verticalLayout->addWidget(toolButton);
	QSpacerItem* verticalSpacer = new QSpacerItem(20, 608, QSizePolicy::Minimum, QSizePolicy::Expanding);
	verticalLayout->addItem(verticalSpacer);
	ui.horizontalLayout->addWidget(frame);
}
ReimbursementStatistics::~ReimbursementStatistics()
{
}

void ReimbursementStatistics::initializeUI(QWidget *parent)
{
	this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());
	//this->setAttribute(Qt::WA_TranslucentBackground, true);

	this->resize(parent->geometry().width(), parent->geometry().height() - 45);
	this->move(parent->x(), parent->y() + 45);
	//set as Transparent degree
	//setWindowOpacity(0.7);
}