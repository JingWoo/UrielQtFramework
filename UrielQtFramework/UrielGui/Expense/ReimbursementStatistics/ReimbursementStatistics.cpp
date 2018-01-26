#include "ReimbursementStatistics.h"
#include <QToolButton>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <QtCharts/QChartView>
#include <QTime>
#include "UrielGui\CommonDialog\UrielPieCharts\donutbreakdownchart.h"

//enum class ExpenseItemEnum
//{
//	LocalTransportation,//市内交通费
//	OfficeSupplies,//办公用品
//	PurchaseOfProfessionalMaterials, //专业材料购置费
//	PurchaseOfExperimentalMaterials,//实验材料购置费
//	SportingGoodsPurchaseFee,//体育用品购置费
//	XeroxFee,//资料复印费
//	Typography,//版面印刷费
//	MaterialTestingAndProcessingFee,//材料测试加工费
//	LodgingExpenses,//实习费
//	StudentActivityFee,//学生活动费
//	Correspondence,//通讯费
//	PostFee,//邮寄费
//	SelfServiceCost,//自备车费用
//	MotorVehicleMaintenance,//机动车维修费
//	OfficeEquipmentMaintenance,//办公设备维修费
//	EquipmentMaintenanceFee,//仪器设备维修费
//	TrainingFees,//培训费
//	EntertainmentExpense,//招待费
//	ConstructionOfFixedAssets,//固定资产构建费
//	Streamer,//横幅
//	Other//其他
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
		if (var.m_sType == QStringLiteral("市内交通费")) {
			invoiceListVector[static_cast<int>(ExpenseItemEnum::LocalTransportation)] << var;
		}
		else if (var.m_sType == QStringLiteral("办公用品")) {
			invoiceListVector[static_cast<int>(ExpenseItemEnum::OfficeSupplies)] << var;
		}
		else if (var.m_sType == QStringLiteral("专业材料购置费")) {
			invoiceListVector[static_cast<int>(ExpenseItemEnum::PurchaseOfProfessionalMaterials)] << var;
		}
		else if (var.m_sType == QStringLiteral("实验材料购置费")) {
			invoiceListVector[static_cast<int>(ExpenseItemEnum::PurchaseOfExperimentalMaterials)] << var;
		}
		else if (var.m_sType == QStringLiteral("体育用品购置费")) {
			invoiceListVector[static_cast<int>(ExpenseItemEnum::SportingGoodsPurchaseFee)] << var;
		}
		else if (var.m_sType == QStringLiteral("资料复印费")) {
			invoiceListVector[static_cast<int>(ExpenseItemEnum::XeroxFee)] << var;
		}
		else if (var.m_sType == QStringLiteral("版面印刷费")) {
			invoiceListVector[static_cast<int>(ExpenseItemEnum::Typography)] << var;
		}
		else if (var.m_sType == QStringLiteral("材料测试加工费")) {
			invoiceListVector[static_cast<int>(ExpenseItemEnum::MaterialTestingAndProcessingFee)] << var;
		}
		else if (var.m_sType == QStringLiteral("实习费")) {
			invoiceListVector[static_cast<int>(ExpenseItemEnum::LodgingExpenses)] << var;
		}
		else if (var.m_sType == QStringLiteral("学生活动费")) {
			invoiceListVector[static_cast<int>(ExpenseItemEnum::StudentActivityFee)] << var;
		}
		else if (var.m_sType == QStringLiteral("通讯费")) {
			invoiceListVector[static_cast<int>(ExpenseItemEnum::Correspondence)] << var;
		}
		else if (var.m_sType == QStringLiteral("邮寄费")) {
			invoiceListVector[static_cast<int>(ExpenseItemEnum::PostFee)] << var;
		}
		else if (var.m_sType == QStringLiteral("自备车费用")) {
			invoiceListVector[static_cast<int>(ExpenseItemEnum::SelfServiceCost)] << var;
		}
		else if (var.m_sType == QStringLiteral("机动车维修费")) {
			invoiceListVector[static_cast<int>(ExpenseItemEnum::MotorVehicleMaintenance)] << var;
		}
		else if (var.m_sType == QStringLiteral("办公设备维修费")) {
			invoiceListVector[static_cast<int>(ExpenseItemEnum::OfficeEquipmentMaintenance)] << var;
		}
		else if (var.m_sType == QStringLiteral("仪器设备维修费")) {
			invoiceListVector[static_cast<int>(ExpenseItemEnum::EquipmentMaintenanceFee)] << var;
		}
		else if (var.m_sType == QStringLiteral("培训费")) {
			invoiceListVector[static_cast<int>(ExpenseItemEnum::TrainingFees)] << var;
		}
		else if (var.m_sType == QStringLiteral("招待费")) {
			invoiceListVector[static_cast<int>(ExpenseItemEnum::EntertainmentExpense)] << var;
		}
		else if (var.m_sType == QStringLiteral("固定资产构建费")) {
			invoiceListVector[static_cast<int>(ExpenseItemEnum::ConstructionOfFixedAssets)] << var;
		}
		else if (var.m_sType == QStringLiteral("横幅")) {
			invoiceListVector[static_cast<int>(ExpenseItemEnum::Streamer)] << var;
		}
		else if (var.m_sType == QStringLiteral("其他")) {
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
		donutBreakdown->setTitle(QStringLiteral("浙江大学个人报销汇总统计"));
		QVector<QList<sUrielInvoiceInfoItem>> invoiceListVector = getInvoiceListVectorByProject(m_PMInvoiceList);

		if (invoiceListVector[static_cast<int>(ExpenseItemEnum::LocalTransportation)].size()) {
			QPieSeries * series = new QPieSeries();
			series->setName(QStringLiteral("市内交通费"));
			for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::LocalTransportation)])
			{
				series->append(var.m_sName, var.m_dAggregateAmount);
			}
			SeriesList << series;
		}
		if (invoiceListVector[static_cast<int>(ExpenseItemEnum::OfficeSupplies)].size()) {
			QPieSeries *series = new QPieSeries();
			series->setName(QStringLiteral("办公用品"));
			for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::OfficeSupplies)])
			{
				series->append(var.m_sName, var.m_dAggregateAmount);
			}
			SeriesList << series;
		}
		if (invoiceListVector[static_cast<int>(ExpenseItemEnum::PurchaseOfProfessionalMaterials)].size()) {
			QPieSeries *series = new QPieSeries();
			series->setName(QStringLiteral("专业材料购置费"));
			for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::PurchaseOfProfessionalMaterials)])
			{
				series->append(var.m_sName, var.m_dAggregateAmount);
			}
			SeriesList << series;
		}
		if (invoiceListVector[static_cast<int>(ExpenseItemEnum::PurchaseOfExperimentalMaterials)].size()) {
			QPieSeries *series = new QPieSeries();
			series->setName(QStringLiteral("实验材料购置费"));
			for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::PurchaseOfExperimentalMaterials)])
			{
				series->append(var.m_sName, var.m_dAggregateAmount);
			}
			SeriesList << series;
		}
		if (invoiceListVector[static_cast<int>(ExpenseItemEnum::SportingGoodsPurchaseFee)].size()) {
			QPieSeries *series = new QPieSeries();
			series->setName(QStringLiteral("体育用品购置费"));
			for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::SportingGoodsPurchaseFee)])
			{
				series->append(var.m_sName, var.m_dAggregateAmount);
			}
			SeriesList << series;
		}
		if (invoiceListVector[static_cast<int>(ExpenseItemEnum::XeroxFee)].size()) {
			QPieSeries *series = new QPieSeries();
			series->setName(QStringLiteral("资料复印费"));
			for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::XeroxFee)])
			{
				series->append(var.m_sName, var.m_dAggregateAmount);
			}
			SeriesList << series;
		}
		if (invoiceListVector[static_cast<int>(ExpenseItemEnum::Typography)].size()) {
			QPieSeries *series = new QPieSeries();
			series->setName(QStringLiteral("版面印刷费"));
			for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::Typography)])
			{
				series->append(var.m_sName, var.m_dAggregateAmount);
			}
			SeriesList << series;
		}
		if (invoiceListVector[static_cast<int>(ExpenseItemEnum::MaterialTestingAndProcessingFee)].size()) {
			QPieSeries *series = new QPieSeries();
			series->setName(QStringLiteral("材料测试加工费"));
			for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::MaterialTestingAndProcessingFee)])
			{
				series->append(var.m_sName, var.m_dAggregateAmount);
			}
			SeriesList << series;
		}
		if (invoiceListVector[static_cast<int>(ExpenseItemEnum::LodgingExpenses)].size()) {
			QPieSeries *series = new QPieSeries();
			series->setName(QStringLiteral("实习费"));
			for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::LodgingExpenses)])
			{
				series->append(var.m_sName, var.m_dAggregateAmount);
			}
			SeriesList << series;
		}
		if (invoiceListVector[static_cast<int>(ExpenseItemEnum::StudentActivityFee)].size()) {
			QPieSeries *series = new QPieSeries();
			series->setName(QStringLiteral("学生活动费"));
			for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::StudentActivityFee)])
			{
				series->append(var.m_sName, var.m_dAggregateAmount);
			}
			SeriesList << series;
		}
		if (invoiceListVector[static_cast<int>(ExpenseItemEnum::Correspondence)].size()) {
			QPieSeries *series = new QPieSeries();
			series->setName(QStringLiteral("通讯费"));
			for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::Correspondence)])
			{
				series->append(var.m_sName, var.m_dAggregateAmount);
			}
			SeriesList << series;
		}
		if (invoiceListVector[static_cast<int>(ExpenseItemEnum::PostFee)].size()) {
			QPieSeries *series = new QPieSeries();
			series->setName(QStringLiteral("邮寄费"));
			for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::PostFee)])
			{
				series->append(var.m_sName, var.m_dAggregateAmount);
			}
			SeriesList << series;
		}
		if (invoiceListVector[static_cast<int>(ExpenseItemEnum::SelfServiceCost)].size()) {
			QPieSeries *series = new QPieSeries();
			series->setName(QStringLiteral("自备车费用"));
			for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::SelfServiceCost)])
			{
				series->append(var.m_sName, var.m_dAggregateAmount);
			}
			SeriesList << series;
		}
		if (invoiceListVector[static_cast<int>(ExpenseItemEnum::MotorVehicleMaintenance)].size()) {
			QPieSeries *series = new QPieSeries();
			series->setName(QStringLiteral("机动车维修费"));
			for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::MotorVehicleMaintenance)])
			{
				series->append(var.m_sName, var.m_dAggregateAmount);
			}
			SeriesList << series;
		}
		if (invoiceListVector[static_cast<int>(ExpenseItemEnum::OfficeEquipmentMaintenance)].size()) {
			QPieSeries *series = new QPieSeries();
			series->setName(QStringLiteral("办公设备维修费"));
			for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::OfficeEquipmentMaintenance)])
			{
				series->append(var.m_sName, var.m_dAggregateAmount);
			}
			SeriesList << series;
		}
		if (invoiceListVector[static_cast<int>(ExpenseItemEnum::EquipmentMaintenanceFee)].size()) {
			QPieSeries *series = new QPieSeries();
			series->setName(QStringLiteral("仪器设备维修费"));
			for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::EquipmentMaintenanceFee)])
			{
				series->append(var.m_sName, var.m_dAggregateAmount);
			}
			SeriesList << series;
		}
		if (invoiceListVector[static_cast<int>(ExpenseItemEnum::TrainingFees)].size()) {
			QPieSeries *series = new QPieSeries();
			series->setName(QStringLiteral("培训费"));
			for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::TrainingFees)])
			{
				series->append(var.m_sName, var.m_dAggregateAmount);
			}
			SeriesList << series;
		}
		if (invoiceListVector[static_cast<int>(ExpenseItemEnum::EntertainmentExpense)].size()) {
			QPieSeries *series = new QPieSeries();
			series->setName(QStringLiteral("招待费"));
			for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::EntertainmentExpense)])
			{
				series->append(var.m_sName, var.m_dAggregateAmount);
			}
			SeriesList << series;
		}
		if (invoiceListVector[static_cast<int>(ExpenseItemEnum::ConstructionOfFixedAssets)].size()) {
			QPieSeries *series = new QPieSeries();
			series->setName(QStringLiteral("固定资产构建费"));
			for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::ConstructionOfFixedAssets)])
			{
				series->append(var.m_sName, var.m_dAggregateAmount);
			}
			SeriesList << series;
		}
		if (invoiceListVector[static_cast<int>(ExpenseItemEnum::Streamer)].size()) {
			QPieSeries *series = new QPieSeries();
			series->setName(QStringLiteral("横幅"));
			for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::Streamer)])
			{
				series->append(var.m_sName, var.m_dAggregateAmount);
			}
			SeriesList << series;
		}
		if (invoiceListVector[static_cast<int>(ExpenseItemEnum::Other)].size()) {
			QPieSeries *series = new QPieSeries();
			series->setName(QStringLiteral("其他"));
			for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::Other)])
			{
				series->append(var.m_sName, var.m_dAggregateAmount);
			}
			SeriesList << series;
		}
	}
	else {
		donutBreakdown->setTitle(QStringLiteral("浙江大学报销汇总统计"));
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
				series->append(QStringLiteral("市内交通费"), value);
			}
			if (invoiceListVector[static_cast<int>(ExpenseItemEnum::OfficeSupplies)].size()) {
				double value = 0.0;
				for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::OfficeSupplies)])
				{
					value += var.m_dAggregateAmount;
				}
				series->append(QStringLiteral("办公用品"), value);
			}
			if (invoiceListVector[static_cast<int>(ExpenseItemEnum::PurchaseOfProfessionalMaterials)].size()) {
				double value = 0.0;
				for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::PurchaseOfProfessionalMaterials)])
				{
					value += var.m_dAggregateAmount;
				}
				series->append(QStringLiteral("专业材料购置费"), value);
			}
			if (invoiceListVector[static_cast<int>(ExpenseItemEnum::PurchaseOfExperimentalMaterials)].size()) {
				double value = 0.0;
				for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::PurchaseOfExperimentalMaterials)])
				{
					value += var.m_dAggregateAmount;
				}
				series->append(QStringLiteral("实验材料购置费"), value);
			}
			if (invoiceListVector[static_cast<int>(ExpenseItemEnum::SportingGoodsPurchaseFee)].size()) {
				double value = 0.0;
				for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::SportingGoodsPurchaseFee)])
				{
					value += var.m_dAggregateAmount;
				}
				series->append(QStringLiteral("体育用品购置费"), value);
			}
			if (invoiceListVector[static_cast<int>(ExpenseItemEnum::XeroxFee)].size()) {
				double value = 0.0;
				for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::XeroxFee)])
				{
					value += var.m_dAggregateAmount;
				}
				series->append(QStringLiteral("资料复印费"), value);
			}
			if (invoiceListVector[static_cast<int>(ExpenseItemEnum::Typography)].size()) {
				double value = 0.0;
				for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::Typography)])
				{
					value += var.m_dAggregateAmount;
				}
				series->append(QStringLiteral("版面印刷费"), value);
			}
			if (invoiceListVector[static_cast<int>(ExpenseItemEnum::MaterialTestingAndProcessingFee)].size()) {
				double value = 0.0;
				for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::MaterialTestingAndProcessingFee)])
				{
					value += var.m_dAggregateAmount;
				}
				series->append(QStringLiteral("材料测试加工费"), value);
			}
			if (invoiceListVector[static_cast<int>(ExpenseItemEnum::LodgingExpenses)].size()) {
				double value = 0.0;
				for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::LodgingExpenses)])
				{
					value += var.m_dAggregateAmount;
				}
				series->append(QStringLiteral("实习费"), value);
			}
			if (invoiceListVector[static_cast<int>(ExpenseItemEnum::StudentActivityFee)].size()) {
				double value = 0.0;
				for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::StudentActivityFee)])
				{
					value += var.m_dAggregateAmount;
				}
				series->append(QStringLiteral("学生活动费"), value);
			}
			if (invoiceListVector[static_cast<int>(ExpenseItemEnum::Correspondence)].size()) {
				double value = 0.0;
				for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::Correspondence)])
				{
					value += var.m_dAggregateAmount;
				}
				series->append(QStringLiteral("通讯费"), value);
			}
			if (invoiceListVector[static_cast<int>(ExpenseItemEnum::PostFee)].size()) {
				double value = 0.0;
				for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::PostFee)])
				{
					value += var.m_dAggregateAmount;
				}
				series->append(QStringLiteral("邮寄费"), value);
			}
			if (invoiceListVector[static_cast<int>(ExpenseItemEnum::SelfServiceCost)].size()) {
				double value = 0.0;
				for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::SelfServiceCost)])
				{
					value += var.m_dAggregateAmount;
				}
				series->append(QStringLiteral("自备车费用"), value);
			}
			if (invoiceListVector[static_cast<int>(ExpenseItemEnum::MotorVehicleMaintenance)].size()) {
				double value = 0.0;
				for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::MotorVehicleMaintenance)])
				{
					value += var.m_dAggregateAmount;
				}
				series->append(QStringLiteral("机动车维修费"), value);
			}
			if (invoiceListVector[static_cast<int>(ExpenseItemEnum::OfficeEquipmentMaintenance)].size()) {
				double value = 0.0;
				for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::OfficeEquipmentMaintenance)])
				{
					value += var.m_dAggregateAmount;
				}
				series->append(QStringLiteral("办公设备维修费"), value);
			}
			if (invoiceListVector[static_cast<int>(ExpenseItemEnum::EquipmentMaintenanceFee)].size()) {
				double value = 0.0;
				for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::EquipmentMaintenanceFee)])
				{
					value += var.m_dAggregateAmount;
				}
				series->append(QStringLiteral("仪器设备维修费"), value);
			}
			if (invoiceListVector[static_cast<int>(ExpenseItemEnum::TrainingFees)].size()) {
				double value = 0.0;
				for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::TrainingFees)])
				{
					value += var.m_dAggregateAmount;
				}
				series->append(QStringLiteral("培训费"), value);
			}
			if (invoiceListVector[static_cast<int>(ExpenseItemEnum::EntertainmentExpense)].size()) {
				double value = 0.0;
				for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::EntertainmentExpense)])
				{
					value += var.m_dAggregateAmount;
				}
				series->append(QStringLiteral("招待费"), value);
			}
			if (invoiceListVector[static_cast<int>(ExpenseItemEnum::ConstructionOfFixedAssets)].size()) {
				double value = 0.0;
				for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::ConstructionOfFixedAssets)])
				{
					value += var.m_dAggregateAmount;
				}
				series->append(QStringLiteral("固定资产构建费"), value);
			}
			if (invoiceListVector[static_cast<int>(ExpenseItemEnum::Streamer)].size()) {
				double value = 0.0;
				for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::Streamer)])
				{
					value += var.m_dAggregateAmount;
				}
				series->append(QStringLiteral("横幅"), value);
			}
			if (invoiceListVector[static_cast<int>(ExpenseItemEnum::Other)].size()) {
				double value = 0.0;
				for each (sUrielInvoiceInfoItem var in invoiceListVector[static_cast<int>(ExpenseItemEnum::Other)])
				{
					value += var.m_dAggregateAmount;
				}
				series->append(QStringLiteral("其他"), value);
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