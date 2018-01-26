#include "SmallInvoice.h"
#include "UrielDatabase\UrielDatabase.h"
#include "UrielQtFrameworkOptions\UrielQtFrameworkOptions.h"
#include "UrielGui\CommonDialog\InformationDialog\InformationDialog.h"
SmallInvoice::SmallInvoice(UrielDatabase * database, UrielQtFrameworkOptions *option, QWidget *parent)
	: QDialog(parent), m_database(database), m_options(option)
{
	ui.setupUi(this);
	initializeUI(parent);
	setSignalsAndSlots();
}

SmallInvoice::~SmallInvoice()
{
}
void SmallInvoice::initializeUI(QWidget *parent)
{
	this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());
	//this->setAttribute(Qt::WA_TranslucentBackground, true);

	this->resize(parent->geometry().width(), parent->geometry().height() - 45);
	this->move(parent->x(), parent->y() + 45);
	//set as Transparent degree
	//setWindowOpacity(0.7);
}
void SmallInvoice::setReimburseCodeAndInvoiceType(const QString & Code, const QString & type)
{
	this->m_sReimburseCode = Code;
	this->m_InvoiceType = type;
}

void SmallInvoice::setSignalsAndSlots()
{
	QObject::connect(ui.AppClose, &QToolButton::clicked, this, &SmallInvoice::reject);
	QObject::connect(ui.LocalTransportationTBtn,&QToolButton::clicked,this, &SmallInvoice::onLocalTransportationTBtnClicked);
	QObject::connect(ui.MailingFeeTBtn, &QToolButton::clicked, this, &SmallInvoice::onMailingFeeTBtnClicked);
	QObject::connect(ui.OtherTBtn, &QToolButton::clicked, this, &SmallInvoice::onOtherTBtnClicked);
	QObject::connect(ui.StatisticsTBtn, &QToolButton::clicked, this, &SmallInvoice::onStatisticsTBtnClicked);
	QObject::connect(ui.ConfirmTBtn, &QToolButton::clicked, this, &SmallInvoice::onConfirmTBtnClicked);
	QObject::connect(ui.Amount, &QLineEdit::editingFinished, this, &SmallInvoice::onAmountEditingFinished);
	QObject::connect(ui.Amount_2, &QLineEdit::editingFinished, this, &SmallInvoice::onAmount_2EditingFinished);
	QObject::connect(ui.Amount_3, &QLineEdit::editingFinished, this, &SmallInvoice::onAmount_3EditingFinished);
	QObject::connect(ui.Amount_4, &QLineEdit::editingFinished, this, &SmallInvoice::onAmount_4EditingFinished);
	QObject::connect(ui.Amount_5, &QLineEdit::editingFinished, this, &SmallInvoice::onAmount_5EditingFinished);
	QObject::connect(ui.Amount_6, &QLineEdit::editingFinished, this, &SmallInvoice::onAmount_6EditingFinished);
	QObject::connect(ui.Amount_7, &QLineEdit::editingFinished, this, &SmallInvoice::onAmount_7EditingFinished); 
	QObject::connect(ui.Amount_8, &QLineEdit::editingFinished, this, &SmallInvoice::onAmount_8EditingFinished);
	QObject::connect(ui.Amount_9, &QLineEdit::editingFinished, this, &SmallInvoice::onAmount_9EditingFinished);
	QObject::connect(ui.Amount_10, &QLineEdit::editingFinished, this, &SmallInvoice::onAmount_10EditingFinished);
	QObject::connect(ui.Amount_11, &QLineEdit::editingFinished, this, &SmallInvoice::onAmount_11EditingFinished);
	QObject::connect(ui.Amount_12, &QLineEdit::editingFinished, this, &SmallInvoice::onAmount_12EditingFinished);
	QObject::connect(ui.Amount_13, &QLineEdit::editingFinished, this, &SmallInvoice::onAmount_13EditingFinished);
	QObject::connect(ui.Amount_14, &QLineEdit::editingFinished, this, &SmallInvoice::onAmount_14EditingFinished);
	QObject::connect(ui.Amount_15, &QLineEdit::editingFinished, this, &SmallInvoice::onAmount_15EditingFinished);
	QObject::connect(ui.Amount_16, &QLineEdit::editingFinished, this, &SmallInvoice::onAmount_16EditingFinished);
}

void SmallInvoice::onLocalTransportationTBtnClicked() {
	QString name = QStringLiteral("杭州市内交通费");
	ui.Name->setText(name);
	ui.Name_2->setText(name);
	ui.Name_3->setText(name);
	ui.Name_4->setText(name);
	ui.Name_5->setText(name);
	ui.Name_6->setText(name);
	ui.Name_7->setText(name);
	ui.Name_8->setText(name);
	ui.Name_9->setText(name);
	ui.Name_10->setText(name);
	ui.Name_11->setText(name);
	ui.Name_12->setText(name);
	ui.Name_13->setText(name);
	ui.Name_14->setText(name);
	ui.Name_15->setText(name);
	ui.Name_16->setText(name);
}
void SmallInvoice::onMailingFeeTBtnClicked() {
	QString name = QStringLiteral("邮寄费");
	ui.Name->setText(name);
	ui.Name_2->setText(name);
	ui.Name_3->setText(name);
	ui.Name_4->setText(name);
	ui.Name_5->setText(name);
	ui.Name_6->setText(name);
	ui.Name_7->setText(name);
	ui.Name_8->setText(name);
	ui.Name_9->setText(name);
	ui.Name_10->setText(name);
	ui.Name_11->setText(name);
	ui.Name_12->setText(name);
	ui.Name_13->setText(name);
	ui.Name_14->setText(name);
	ui.Name_15->setText(name);
	ui.Name_16->setText(name);
}
void SmallInvoice::onOtherTBtnClicked() {
	QString name = QStringLiteral("其他费用");
	ui.Name->setText(name);
	ui.Name_2->setText(name);
	ui.Name_3->setText(name);
	ui.Name_4->setText(name);
	ui.Name_5->setText(name);
	ui.Name_6->setText(name);
	ui.Name_7->setText(name);
	ui.Name_8->setText(name);
	ui.Name_9->setText(name);
	ui.Name_10->setText(name);
	ui.Name_11->setText(name);
	ui.Name_12->setText(name);
	ui.Name_13->setText(name);
	ui.Name_14->setText(name);
	ui.Name_15->setText(name);
	ui.Name_16->setText(name);
}
void SmallInvoice::onStatisticsTBtnClicked() {
	double value = 0.0;
	if (ui.Amount->text().isEmpty())
		ui.Name->setText("");
	else
		value += ui.Amount->text().toDouble();
	if (ui.Amount_2->text().isEmpty())
		ui.Name_2->setText("");
	else
		value += ui.Amount_2->text().toDouble();
	if (ui.Amount_3->text().isEmpty())
		ui.Name_3->setText("");
	else
		value += ui.Amount_3->text().toDouble();
	if (ui.Amount_4->text().isEmpty())
		ui.Name_4->setText("");
	else
		value += ui.Amount_4->text().toDouble();
	if (ui.Amount_5->text().isEmpty())
		ui.Name_5->setText("");
	else
		value += ui.Amount_5->text().toDouble();
	if (ui.Amount_6->text().isEmpty())
		ui.Name_6->setText("");
	else
		value += ui.Amount_6->text().toDouble();
	if (ui.Amount_7->text().isEmpty())
		ui.Name_7->setText("");
	else
		value += ui.Amount_7->text().toDouble();
	if (ui.Amount_8->text().isEmpty())
		ui.Name_8->setText("");
	else
		value += ui.Amount_8->text().toDouble();
	if (ui.Amount_9->text().isEmpty())
		ui.Name_9->setText("");
	else
		value += ui.Amount_9->text().toDouble();
	if (ui.Amount_10->text().isEmpty())
		ui.Name_10->setText("");
	else
		value += ui.Amount_10->text().toDouble();
	if (ui.Amount_11->text().isEmpty())
		ui.Name_11->setText("");
	else
		value += ui.Amount_11->text().toDouble();
	if (ui.Amount_12->text().isEmpty())
		ui.Name_12->setText("");
	else
		value += ui.Amount_12->text().toDouble();
	if (ui.Amount_13->text().isEmpty())
		ui.Name_13->setText("");
	else
		value += ui.Amount_13->text().toDouble();
	if (ui.Amount_14->text().isEmpty())
		ui.Name_14->setText("");
	else
		value += ui.Amount_14->text().toDouble();
	if (ui.Amount_15->text().isEmpty())
		ui.Name_15->setText("");
	else
		value += ui.Amount_15->text().toDouble();
	if (ui.Amount_16->text().isEmpty())
		ui.Name_16->setText("");
	else
		value += ui.Amount_16->text().toDouble();
	ui.TotalAmount->setText(m_options->DigitalChineseUppercase(value)+"    CNY:"+QString::number(value));
}

//typedef struct _SUrielInvoiceInfoItem
//{
//	int m_iId{ 0 };
//	QString m_sReimburseCode{ "" };
//	QString m_sType{ "" };
//	QString m_sName{ "" };
//	QString m_sModel{ "" };
//	int m_iQuantity{ 0 };
//	QString m_sUnit{ "" };
//	double m_dUnivalent{ 0.00 };
//	double m_dAggregateAmount{ 0.00 };
//	QString m_sDescription{ "" };
//	QString m_sInvoiceImagePath{ "" };
//	QString m_sBuyScreenshotPath{ "" };
//	QString m_sVerificationImagePath{ "" };
//	QString m_sReimbursePerson{ "" };
//	QDateTime m_tReimburseTime{ QDateTime::currentDateTime() };
//	QString m_sFilingState{ QStringLiteral("未归档") };
//	QString m_sArchivesName{ "" };
//	QString m_sRemark{ "" };
//} sUrielInvoiceInfoItem, *pUrielInvoiceInfoItem;

void SmallInvoice::onConfirmTBtnClicked() {
	m_stInvoiceInfoItem.m_sReimburseCode= m_sReimburseCode;
	m_stInvoiceInfoItem.m_sType = m_InvoiceType;
	m_stInvoiceInfoItem.m_iQuantity = 1;
	m_stInvoiceInfoItem.m_sUnit = QStringLiteral("张");
	
	m_stInvoiceInfoItem.m_sReimbursePerson = m_options->getAccount();
	m_stInvoiceInfoItem.m_tReimburseTime = QDateTime::currentDateTime();
	QString err;
	if (!ui.Amount->text().isEmpty()) {
		m_stInvoiceInfoItem.m_sName = ui.Name->text();
		m_stInvoiceInfoItem.m_dUnivalent = ui.Amount->text().toDouble();
		m_stInvoiceInfoItem.m_dAggregateAmount = ui.Amount->text().toDouble();
		m_database->insertInvoice(m_stInvoiceInfoItem,err);
	}
	if (!ui.Amount_2->text().isEmpty()) {
		m_stInvoiceInfoItem.m_sName = ui.Name_2->text();
		m_stInvoiceInfoItem.m_dUnivalent = ui.Amount_2->text().toDouble();
		m_stInvoiceInfoItem.m_dAggregateAmount = ui.Amount_2->text().toDouble();
		m_database->insertInvoice(m_stInvoiceInfoItem, err);
	}
	if (!ui.Amount_3->text().isEmpty()) {
		m_stInvoiceInfoItem.m_sName = ui.Name_3->text();
		m_stInvoiceInfoItem.m_dUnivalent = ui.Amount_3->text().toDouble();
		m_stInvoiceInfoItem.m_dAggregateAmount = ui.Amount_3->text().toDouble();
		m_database->insertInvoice(m_stInvoiceInfoItem, err);
	}
	if (!ui.Amount_4->text().isEmpty()) {
		m_stInvoiceInfoItem.m_sName = ui.Name_4->text();
		m_stInvoiceInfoItem.m_dUnivalent = ui.Amount_4->text().toDouble();
		m_stInvoiceInfoItem.m_dAggregateAmount = ui.Amount_4->text().toDouble();
		m_database->insertInvoice(m_stInvoiceInfoItem, err);
	}
	if (!ui.Amount_5->text().isEmpty()) {
		m_stInvoiceInfoItem.m_sName = ui.Name_5->text();
		m_stInvoiceInfoItem.m_dUnivalent = ui.Amount_5->text().toDouble();
		m_stInvoiceInfoItem.m_dAggregateAmount = ui.Amount_5->text().toDouble();
		m_database->insertInvoice(m_stInvoiceInfoItem, err);
	}
	if (!ui.Amount_6->text().isEmpty()) {
		m_stInvoiceInfoItem.m_sName = ui.Name_6->text();
		m_stInvoiceInfoItem.m_dUnivalent = ui.Amount_6->text().toDouble();
		m_stInvoiceInfoItem.m_dAggregateAmount = ui.Amount_6->text().toDouble();
		m_database->insertInvoice(m_stInvoiceInfoItem, err);
	}
	if (!ui.Amount_7->text().isEmpty()) {
		m_stInvoiceInfoItem.m_sName = ui.Name_7->text();
		m_stInvoiceInfoItem.m_dUnivalent = ui.Amount_7->text().toDouble();
		m_stInvoiceInfoItem.m_dAggregateAmount = ui.Amount_7->text().toDouble();
		m_database->insertInvoice(m_stInvoiceInfoItem, err);
	}
	if (!ui.Amount_8->text().isEmpty()) {
		m_stInvoiceInfoItem.m_sName = ui.Name_8->text();
		m_stInvoiceInfoItem.m_dUnivalent = ui.Amount_8->text().toDouble();
		m_stInvoiceInfoItem.m_dAggregateAmount = ui.Amount_8->text().toDouble();
		m_database->insertInvoice(m_stInvoiceInfoItem, err);
	}
	if (!ui.Amount_9->text().isEmpty()) {
		m_stInvoiceInfoItem.m_sName = ui.Name_9->text();
		m_stInvoiceInfoItem.m_dUnivalent = ui.Amount_9->text().toDouble();
		m_stInvoiceInfoItem.m_dAggregateAmount = ui.Amount_9->text().toDouble();
		m_database->insertInvoice(m_stInvoiceInfoItem, err);
	}
	if (!ui.Amount_10->text().isEmpty()) {
		m_stInvoiceInfoItem.m_sName = ui.Name_10->text();
		m_stInvoiceInfoItem.m_dUnivalent = ui.Amount_10->text().toDouble();
		m_stInvoiceInfoItem.m_dAggregateAmount = ui.Amount_10->text().toDouble();
		m_database->insertInvoice(m_stInvoiceInfoItem, err);
	}
	if (!ui.Amount_11->text().isEmpty()) {
		m_stInvoiceInfoItem.m_sName = ui.Name_11->text();
		m_stInvoiceInfoItem.m_dUnivalent = ui.Amount_11->text().toDouble();
		m_stInvoiceInfoItem.m_dAggregateAmount = ui.Amount_11->text().toDouble();
		m_database->insertInvoice(m_stInvoiceInfoItem, err);
	}
	if (!ui.Amount_12->text().isEmpty()) {
		m_stInvoiceInfoItem.m_sName = ui.Name_12->text();
		m_stInvoiceInfoItem.m_dUnivalent = ui.Amount_12->text().toDouble();
		m_stInvoiceInfoItem.m_dAggregateAmount = ui.Amount_12->text().toDouble();
		m_database->insertInvoice(m_stInvoiceInfoItem, err);
	}
	if (!ui.Amount_13->text().isEmpty()) {
		m_stInvoiceInfoItem.m_sName = ui.Name_13->text();
		m_stInvoiceInfoItem.m_dUnivalent = ui.Amount_13->text().toDouble();
		m_stInvoiceInfoItem.m_dAggregateAmount = ui.Amount_13->text().toDouble();
		m_database->insertInvoice(m_stInvoiceInfoItem, err);
	}
	if (!ui.Amount_14->text().isEmpty()) {
		m_stInvoiceInfoItem.m_sName = ui.Name_14->text();
		m_stInvoiceInfoItem.m_dUnivalent = ui.Amount_14->text().toDouble();
		m_stInvoiceInfoItem.m_dAggregateAmount = ui.Amount_14->text().toDouble();
		m_database->insertInvoice(m_stInvoiceInfoItem, err);
	}
	if (!ui.Amount_15->text().isEmpty()) {
		m_stInvoiceInfoItem.m_sName = ui.Name_15->text();
		m_stInvoiceInfoItem.m_dUnivalent = ui.Amount_15->text().toDouble();
		m_stInvoiceInfoItem.m_dAggregateAmount = ui.Amount_15->text().toDouble();
		m_database->insertInvoice(m_stInvoiceInfoItem, err);
	}
	if (!ui.Amount_16->text().isEmpty()) {
		m_stInvoiceInfoItem.m_sName = ui.Name_16->text();
		m_stInvoiceInfoItem.m_dUnivalent = ui.Amount_16->text().toDouble();
		m_stInvoiceInfoItem.m_dAggregateAmount = ui.Amount_16->text().toDouble();
		m_database->insertInvoice(m_stInvoiceInfoItem, err);
	}
	if (err.isEmpty()) {
		InformationDialog infor(QStringLiteral("信息"), QStringLiteral("已成功添加"), this);
		if (infor.exec() == QDialog::Accepted) {
			accept();
		}
	}
	else {
		InformationDialog infor(QStringLiteral("信息"), QStringLiteral("添加失败，请联系数据库管理员"), this);
		if (infor.exec() == QDialog::Accepted) {
			accept();
		}
	}
}

void SmallInvoice::onAmountEditingFinished() {
	if (!ui.Amount->text().isEmpty())
		ui.SerialNumber->setText("1");
}
void SmallInvoice::onAmount_2EditingFinished() {
	if (!ui.Amount_2->text().isEmpty())
		ui.SerialNumber_2->setText("2");
}
void SmallInvoice::onAmount_3EditingFinished() {
	if (!ui.Amount_3->text().isEmpty())
		ui.SerialNumber_3->setText("3");
}
void SmallInvoice::onAmount_4EditingFinished() {
	if (!ui.Amount_4->text().isEmpty())
		ui.SerialNumber_4->setText("4");
}
void SmallInvoice::onAmount_5EditingFinished() {
	if (!ui.Amount_5->text().isEmpty())
		ui.SerialNumber_5->setText("5");
}
void SmallInvoice::onAmount_6EditingFinished() {
	if (!ui.Amount_6->text().isEmpty())
		ui.SerialNumber_6->setText("6");
}
void SmallInvoice::onAmount_7EditingFinished() {
	if (!ui.Amount_7->text().isEmpty())
		ui.SerialNumber_7->setText("7");
}
void SmallInvoice::onAmount_8EditingFinished() {
	if (!ui.Amount_8->text().isEmpty())
		ui.SerialNumber_8->setText("8");
}
void SmallInvoice::onAmount_9EditingFinished() {
	if (!ui.Amount_9->text().isEmpty())
		ui.SerialNumber_9->setText("9");
}
void SmallInvoice::onAmount_10EditingFinished() {
	if (!ui.Amount_10->text().isEmpty())
		ui.SerialNumber_10->setText("10");
}
void SmallInvoice::onAmount_11EditingFinished() {
	if (!ui.Amount_11->text().isEmpty())
		ui.SerialNumber_11->setText("11");
}
void SmallInvoice::onAmount_12EditingFinished() {
	if (!ui.Amount_12->text().isEmpty())
		ui.SerialNumber_12->setText("12");
}
void SmallInvoice::onAmount_13EditingFinished() {
	if (!ui.Amount_13->text().isEmpty())
		ui.SerialNumber_13->setText("13");
}
void SmallInvoice::onAmount_14EditingFinished() {
	if (!ui.Amount_14->text().isEmpty())
		ui.SerialNumber_14->setText("14");
}
void SmallInvoice::onAmount_15EditingFinished() {
	if (!ui.Amount_15->text().isEmpty())
		ui.SerialNumber_15->setText("15");
}
void SmallInvoice::onAmount_16EditingFinished() {
	if (!ui.Amount_16->text().isEmpty())
		ui.SerialNumber_16->setText("16");
}
