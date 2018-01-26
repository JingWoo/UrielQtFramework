/********************************************************************************
** Form generated from reading UI file 'InstrumentBorrowReturnHistory.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSTRUMENTBORROWRETURNHISTORY_H
#define UI_INSTRUMENTBORROWRETURNHISTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_InstrumentBorrowReturnHistory
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QTableView *tableView;
    QSpacerItem *horizontalSpacer_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout_3;
    QToolButton *AppClose;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *InstrumentBorrowReturnHistory)
    {
        if (InstrumentBorrowReturnHistory->objectName().isEmpty())
            InstrumentBorrowReturnHistory->setObjectName(QStringLiteral("InstrumentBorrowReturnHistory"));
        InstrumentBorrowReturnHistory->resize(1305, 739);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(240, 240, 240, 0));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        InstrumentBorrowReturnHistory->setPalette(palette);
        horizontalLayout = new QHBoxLayout(InstrumentBorrowReturnHistory);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(89, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        tableView = new QTableView(InstrumentBorrowReturnHistory);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setFrameShape(QFrame::NoFrame);

        horizontalLayout->addWidget(tableView);

        horizontalSpacer_2 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        frame = new QFrame(InstrumentBorrowReturnHistory);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(0, 0));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        AppClose = new QToolButton(frame);
        AppClose->setObjectName(QStringLiteral("AppClose"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Mainwindow/Resources/UrielQtFramework/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        AppClose->setIcon(icon);
        AppClose->setIconSize(QSize(30, 30));
        AppClose->setAutoRaise(true);

        verticalLayout_3->addWidget(AppClose);

        verticalSpacer = new QSpacerItem(20, 572, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout->addWidget(frame);


        retranslateUi(InstrumentBorrowReturnHistory);

        QMetaObject::connectSlotsByName(InstrumentBorrowReturnHistory);
    } // setupUi

    void retranslateUi(QDialog *InstrumentBorrowReturnHistory)
    {
        InstrumentBorrowReturnHistory->setWindowTitle(QApplication::translate("InstrumentBorrowReturnHistory", "InstrumentBorrowReturnHistory", Q_NULLPTR));
        AppClose->setText(QApplication::translate("InstrumentBorrowReturnHistory", "...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class InstrumentBorrowReturnHistory: public Ui_InstrumentBorrowReturnHistory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSTRUMENTBORROWRETURNHISTORY_H
