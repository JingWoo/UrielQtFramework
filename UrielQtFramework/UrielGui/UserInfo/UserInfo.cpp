#include "UserInfo.h"
#include "UrielQtFrameworkOptions\UrielQtFrameworkOptions.h"
UserInfo::UserInfo(QPoint point, QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	initializeUI(point);
	setSignalsAndSlots();
}

UserInfo::~UserInfo()
{
}

void UserInfo::initializeUI(QPoint point)
{
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);

	this->move(point.x() - 320, point.y() + 30);

	//ui.CloudSpaceProgressBar->setStyleSheet("QProgressBar{ border:2px solid grey; border-radius:5px; text-align: center;}"
	//										"QProgressBar::chunk{ background-color:#05B8CC;width:10px;margin:0.5px;}");
}

void UserInfo::setSignalsAndSlots()
{
	QObject::connect(ui.ReturnTBtn, &QToolButton::clicked, [&]() {
		this->accept(); });

}

void UserInfo::setvalue(const sUrielAccountInfo &item)
{
	ui.Name->setText(item.m_sName);
	ui.WorkNumber->setText(item.m_sSchoolWorkNumber);
	ui.Phone->setText(item.m_sPhoneNumber);
	ui.Project->setText(item.m_sProjectTeam);
	//ui.CloudSpaceInfo->setText(QStringLiteral("ÒÑÓÃ")+ QString::number(item.m_iUsedCouldDiskSpaceSize)+ QStringLiteral("GB/¹²")+ QString::number(item.m_iCouldDiskSpaceSize)+"GB");
	//ui.CloudSpaceProgressBar->setValue(item.m_iUsedCouldDiskSpaceSize/ item.m_iCouldDiskSpaceSize*100);
	UrielQtFrameworkOptions *options= UrielQtFrameworkOptions::getInstance();
	ui.AccountInfoTBtn->setIcon(QIcon(options->getHeadIcoPath()));
}