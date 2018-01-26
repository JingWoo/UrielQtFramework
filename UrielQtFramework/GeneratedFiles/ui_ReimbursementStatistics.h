/********************************************************************************
** Form generated from reading UI file 'ReimbursementStatistics.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REIMBURSEMENTSTATISTICS_H
#define UI_REIMBURSEMENTSTATISTICS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_ReimbursementStatistics
{
public:
    QHBoxLayout *horizontalLayout;

    void setupUi(QDialog *ReimbursementStatistics)
    {
        if (ReimbursementStatistics->objectName().isEmpty())
            ReimbursementStatistics->setObjectName(QStringLiteral("ReimbursementStatistics"));
        ReimbursementStatistics->resize(909, 659);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        ReimbursementStatistics->setPalette(palette);
        horizontalLayout = new QHBoxLayout(ReimbursementStatistics);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(ReimbursementStatistics);

        QMetaObject::connectSlotsByName(ReimbursementStatistics);
    } // setupUi

    void retranslateUi(QDialog *ReimbursementStatistics)
    {
        ReimbursementStatistics->setWindowTitle(QApplication::translate("ReimbursementStatistics", "ReimbursementStatistics", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ReimbursementStatistics: public Ui_ReimbursementStatistics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REIMBURSEMENTSTATISTICS_H
