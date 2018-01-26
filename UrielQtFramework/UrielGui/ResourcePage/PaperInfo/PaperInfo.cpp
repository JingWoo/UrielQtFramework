#include "PaperInfo.h"
#include <QFileDialog>
#include <QFile>
#include "UrielDatabase\UrielDatabase.h"
#include "UrielQtFrameworkOptions\UrielQtFrameworkOptions.h"
#include "UrielFileTransfer\FTP\UrielFTP.h"
#include "UrielGui\CommonDialog\ProgressDialog\ProgressDialog.h"
#include "UrielGui\CommonDialog\InformationDialog\InformationDialog.h"
PaperInfo::PaperInfo(UrielDatabase * database, UrielQtFrameworkOptions *option, QWidget *parent)
	: QDialog(parent), m_database(database), m_options(option)
{
	ui.setupUi(this);
	initializeUI(parent);
	setSignalsAndSlots();
}

PaperInfo::~PaperInfo()
{
}

void PaperInfo::openWithEditMode(const sUrielPaperItem & item)
{
	m_bIsEditMode = true;
	ui.PaperConfirmBTn->setText(QStringLiteral("ȷ�ϸ���"));
	m_stPaperInfo = item;
	ui.OriginalTitle->setText(m_stPaperInfo.OriginalTitle);
	ui.TranslationTitle->setText(m_stPaperInfo.TranslationTitle);
	ui.PeriodicalName->setText(m_stPaperInfo.PeriodicalName);
	ui.PeriodicalLevel->setCurrentText(m_stPaperInfo.PeriodicalLevel);
	m_stPaperInfo.PeriodicalLanguage == QStringLiteral("Ӣ��") ?\
		ui.PeriodicalLanguage_English->setChecked(true) : ui.PeriodicalLanguage_Chinese->setChecked(true);
	ui.EmploymentTime->setDateTime(m_stPaperInfo.EmploymentTime);
	ui.VolumeNumber->setText(m_stPaperInfo.VolumeNumber);
	ui.StartAndEndPageNumber->setText(m_stPaperInfo.StartAndEndPageNumber);
	ui.InfluenceFactor->setText(m_stPaperInfo.InfluenceFactor);
	ui.IsThesisContent->setCurrentText(m_stPaperInfo.IsThesisContent);
	ui.CommunicationUnit->setText(m_stPaperInfo.CommunicationUnit);
	ui.Author->setText(m_stPaperInfo.Author);
	ui.IndexedAddress->setText(m_stPaperInfo.IndexedAddress);


	QString dispalyString = "";
	QStringList remoteFileNameList = m_stPaperInfo.ServerFileAddress.split(";");
	for each (QString var in remoteFileNameList)
	{
		if (!var.isEmpty())
			dispalyString +=QFileInfo(var).fileName() + ";";
	}
	if (!dispalyString.isEmpty())
		dispalyString.resize(dispalyString.size() - 1);

	ui.ServerFileAddress->setText(dispalyString);

   ui.Abstract->setPlainText(m_stPaperInfo.Abstract);

}
void PaperInfo::initializeUI(QWidget *parent)
{
	this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());
	//this->setAttribute(Qt::WA_TranslucentBackground, true);

	this->resize(parent->geometry().width(), parent->geometry().height() - 45);
	this->move(parent->x(), parent->y() + 45);
	//set as Transparent degree
	//setWindowOpacity(0.7);

	QStringList level;
	level << "SCI" << "EI" << "SSCI" << "AHCI" << "ISTP" << QStringLiteral("һ������") << QStringLiteral("��������")
		<< "IM" << "CABI" << QStringLiteral("A������") << QStringLiteral("B������") << QStringLiteral("����")
		<< "CSSCI" << "CSCD" << QStringLiteral("�����ڿ�") << QStringLiteral("�������Ȩ�����ڿ�");
	ui.PeriodicalLevel->addItems(level);
	ui.PeriodicalLevel->setCurrentIndex(0);
	ui.IsThesisContent->addItem(QStringLiteral("��"));
	ui.IsThesisContent->addItem(QStringLiteral("��"));
	ui.IsThesisContent->setCurrentIndex(0);
	ui.CommunicationUnit->setText(QStringLiteral("�㽭��ѧ"));
}

void PaperInfo::setSignalsAndSlots()
{
	QObject::connect(ui.AppClose, &QToolButton::clicked, this, &PaperInfo::reject);
	QObject::connect(ui.PaperFileBrower, &QToolButton::clicked, this, &PaperInfo::onPaperFileBrowerClicked);
	QObject::connect(ui.PaperConfirmBTn, &QToolButton::clicked, this, &PaperInfo::onConfirmClicked);
}

void PaperInfo::onPaperFileBrowerClicked() {
	QStringList files = QFileDialog::getOpenFileNames(
		this, tr("QFileDialog::getOpenFileNames()"),
		QCoreApplication::applicationDirPath(),
		tr("All Files (*);;Word Files (*.doc);;PPT Files (*.ppt);;PDF Files (*.pdf);;Text Files (*.txt)"));
	if (files.count()) {
		for each (auto file in files)
		{

			m_sLoaclFilePaths += file + ";";
			QFileInfo fileInfo(file);
			m_sRemoteFilePaths += fileInfo.fileName() + ";";
		}
	}
	m_sRemoteFilePaths.resize(m_sRemoteFilePaths.length() - 1);
	m_sLoaclFilePaths.resize(m_sLoaclFilePaths.length() - 1);
	ui.ServerFileAddress->setText(m_sRemoteFilePaths);
	if (m_sLoaclFilePaths.split(";").count())
		m_bPaperChange = true;
}

void PaperInfo::onConfirmClicked() {
	UrielFtp *urielFtp = UrielFtp::getInstance();
	if (!m_bIsEditMode)//����ģʽ
	{
		QStringList fileNameList = m_sLoaclFilePaths.split(";");
		for each (QString var in fileNameList) {
			
			ProgressDialog *progressDialog = new ProgressDialog(this);
			progressDialog->setTotalProgressBarMax(1);
			QObject::connect(urielFtp, static_cast<void (UrielFtp::*)(qint64 readBytes, qint64 totalBytes)>(&UrielFtp::updateDataTransferProgressSignal), \
				progressDialog, &ProgressDialog::updateProgressBarValue);
			progressDialog->setTotalProgressBarMax(1);
			urielFtp->uploadFile(var, urielFtp->getRootPath() + "/Paper");
			progressDialog->exec();
			QEventLoop eventloop;
			QTimer::singleShot(100, &eventloop, SLOT(quit()));
			eventloop.exec();
		}
		
		m_stPaperInfo.OriginalTitle = ui.OriginalTitle->text();
		m_stPaperInfo.TranslationTitle = ui.TranslationTitle->text();
		m_stPaperInfo.PeriodicalName = ui.PeriodicalName->text();
		m_stPaperInfo.PeriodicalLevel = ui.PeriodicalLevel->currentText();
		m_stPaperInfo.PeriodicalLanguage = ui.PeriodicalLanguage_English->isChecked() ? QStringLiteral("Ӣ��") : QStringLiteral("����");
		m_stPaperInfo.EmploymentTime = ui.EmploymentTime->dateTime();
		m_stPaperInfo.VolumeNumber = ui.VolumeNumber->text();
		m_stPaperInfo.StartAndEndPageNumber = ui.StartAndEndPageNumber->text();
		m_stPaperInfo.InfluenceFactor = ui.InfluenceFactor->text();
		m_stPaperInfo.IsThesisContent = ui.IsThesisContent->currentText();
		m_stPaperInfo.CommunicationUnit = ui.CommunicationUnit->text();
		m_stPaperInfo.Author = ui.Author->text();
		m_stPaperInfo.IndexedAddress = ui.IndexedAddress->text();

		QString RemoteNoticesFilePath = urielFtp->getRootPath() + "/Paper";
		QStringList remoteFileNameList = m_sRemoteFilePaths.split(";");
		m_sRemoteFilePaths = "";
		for each (QString var in remoteFileNameList)
		{
			if (!var.isEmpty())
				m_sRemoteFilePaths += (RemoteNoticesFilePath + "/" + var + ";");
		}
		if (!m_sRemoteFilePaths.isEmpty())
			m_sRemoteFilePaths.resize(m_sRemoteFilePaths.size() - 1);

		m_stPaperInfo.ServerFileAddress = m_sRemoteFilePaths;

		m_stPaperInfo.Abstract = ui.Abstract->toPlainText();
		m_stPaperInfo.Uploader = m_options->getAccount();
		m_stPaperInfo.UploadTime = QDateTime::currentDateTime();
		m_stPaperInfo.DownloadCount = 0;
		m_database->insertPaper(m_stPaperInfo);

		InformationDialog infodlg(QStringLiteral("��Ϣ"), QStringLiteral("������Ϣ����������ݿ⣡"), this);
		infodlg.exec();

		this->accept();
	}
	else {//�༭ģʽ
		if (m_bPaperChange) {
			//ɾ��ԭ��������
			QStringList fileList = m_stPaperInfo.ServerFileAddress.split(";");
			for each (QString var in fileList)
				urielFtp->Remove(var);
			//�ϴ��µ�����
			QStringList fileNameList = m_sLoaclFilePaths.split(";");
			for each (QString var in fileNameList) {

				ProgressDialog *progressDialog = new ProgressDialog(this);
				progressDialog->setTotalProgressBarMax(1);
				QObject::connect(urielFtp, static_cast<void (UrielFtp::*)(qint64 readBytes, qint64 totalBytes)>(&UrielFtp::updateDataTransferProgressSignal), \
					progressDialog, &ProgressDialog::updateProgressBarValue);
				progressDialog->setTotalProgressBarMax(1);
				urielFtp->uploadFile(var, urielFtp->getRootPath() + "/Paper");
				progressDialog->exec();
				QEventLoop eventloop;
				QTimer::singleShot(100, &eventloop, SLOT(quit()));
				eventloop.exec();
			}
		}
		m_stPaperInfo.OriginalTitle = ui.OriginalTitle->text();
		m_stPaperInfo.TranslationTitle = ui.TranslationTitle->text();
		m_stPaperInfo.PeriodicalName = ui.PeriodicalName->text();
		m_stPaperInfo.PeriodicalLevel = ui.PeriodicalLevel->currentText();
		m_stPaperInfo.PeriodicalLanguage = ui.PeriodicalLanguage_English->isChecked() ? QStringLiteral("Ӣ��") : QStringLiteral("����");
		m_stPaperInfo.EmploymentTime = ui.EmploymentTime->dateTime();
		m_stPaperInfo.VolumeNumber = ui.VolumeNumber->text();
		m_stPaperInfo.StartAndEndPageNumber = ui.StartAndEndPageNumber->text();
		m_stPaperInfo.InfluenceFactor = ui.InfluenceFactor->text();
		m_stPaperInfo.IsThesisContent = ui.IsThesisContent->currentText();
		m_stPaperInfo.CommunicationUnit = ui.CommunicationUnit->text();
		m_stPaperInfo.Author = ui.Author->text();
		m_stPaperInfo.IndexedAddress = ui.IndexedAddress->text();

		if (m_bPaperChange) {
			QString RemoteNoticesFilePath = urielFtp->getRootPath() + "/Paper";
			QStringList remoteFileNameList = m_sRemoteFilePaths.split(";");
			m_sRemoteFilePaths = "";
			for each (QString var in remoteFileNameList)
			{
				if (!var.isEmpty())
					m_sRemoteFilePaths += (RemoteNoticesFilePath + "/" + var + ";");
			}
			if (!m_sRemoteFilePaths.isEmpty())
				m_sRemoteFilePaths.resize(m_sRemoteFilePaths.size() - 1);

			m_stPaperInfo.ServerFileAddress = m_sRemoteFilePaths;
		}
		m_stPaperInfo.Abstract = ui.Abstract->toPlainText();
		m_stPaperInfo.Uploader = m_options->getAccount();
		m_stPaperInfo.UploadTime = QDateTime::currentDateTime();
		//m_stPaperInfo.DownloadCount = 0;
		m_database->updatePaper(m_stPaperInfo);
		InformationDialog infodlg(QStringLiteral("��Ϣ"), QStringLiteral("������Ϣ�Ѹ��������ݿ⣡"), this);
		infodlg.exec();
		this->accept();
	}
}