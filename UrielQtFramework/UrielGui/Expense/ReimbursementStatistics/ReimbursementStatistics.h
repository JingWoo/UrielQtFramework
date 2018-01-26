#pragma once

#include <QDialog>
#include "ui_ReimbursementStatistics.h"
#include "UrielDefinition\UrielDefinition.h"
class ReimbursementStatistics : public QDialog
{
	Q_OBJECT

public:
	ReimbursementStatistics( QWidget *parent = Q_NULLPTR);
	~ReimbursementStatistics();
	void setPMInvoiceList(const QList<sUrielInvoiceInfoItem>& PMInvoiceList);
	void setExpenseOperationModel(const ExpenseOperationModel & OperationModel);
	void setCMInvoiceList(const QHash<QString, QList<sUrielInvoiceInfoItem>> & CMInvoiceList);
	void showReport();
private:
	void initializeUI(QWidget *parent = Q_NULLPTR);
	QVector<QList<sUrielInvoiceInfoItem>> getInvoiceListVectorByProject(const QList<sUrielInvoiceInfoItem>& InvoiceList);
private:
	Ui::ReimbursementStatistics ui;
	QList<sUrielInvoiceInfoItem> m_PMInvoiceList;
	ExpenseOperationModel m_eExpenseOperationModel{ ExpenseOperationModel::PersonalModel };
	QHash<QString, QList<sUrielInvoiceInfoItem>> m_hCMInvoiceList;

};
