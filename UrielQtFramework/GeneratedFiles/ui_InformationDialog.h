/********************************************************************************
** Form generated from reading UI file 'InformationDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFORMATIONDIALOG_H
#define UI_INFORMATIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_InformationDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_6;
    QLabel *Ico;
    QLabel *Title;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *Content;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QToolButton *Sure;
    QSpacerItem *horizontalSpacer_3;
    QToolButton *Cancel;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QDialog *InformationDialog)
    {
        if (InformationDialog->objectName().isEmpty())
            InformationDialog->setObjectName(QStringLiteral("InformationDialog"));
        InformationDialog->resize(400, 160);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(98, 102, 106, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        InformationDialog->setPalette(palette);
        verticalLayout = new QVBoxLayout(InformationDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        Ico = new QLabel(InformationDialog);
        Ico->setObjectName(QStringLiteral("Ico"));
        Ico->setMinimumSize(QSize(50, 50));
        Ico->setMaximumSize(QSize(50, 50));
        Ico->setPixmap(QPixmap(QString::fromUtf8(":/Mainwindow/Resources/UrielQtFramework/information.png")));
        Ico->setScaledContents(true);

        horizontalLayout->addWidget(Ico);

        Title = new QLabel(InformationDialog);
        Title->setObjectName(QStringLiteral("Title"));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(22);
        Title->setFont(font);

        horizontalLayout->addWidget(Title);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        Content = new QLabel(InformationDialog);
        Content->setObjectName(QStringLiteral("Content"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(16);
        Content->setFont(font1);
        Content->setWordWrap(true);

        horizontalLayout_2->addWidget(Content);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        Sure = new QToolButton(InformationDialog);
        Sure->setObjectName(QStringLiteral("Sure"));
        Sure->setMinimumSize(QSize(81, 31));
        Sure->setMaximumSize(QSize(81, 31));
        QPalette palette1;
        QBrush brush2(QColor(118, 118, 118, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush2);
        QBrush brush3(QColor(170, 255, 255, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        Sure->setPalette(palette1);
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(14);
        Sure->setFont(font2);
        Sure->setAutoFillBackground(true);
        Sure->setAutoRaise(true);

        horizontalLayout_3->addWidget(Sure);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        Cancel = new QToolButton(InformationDialog);
        Cancel->setObjectName(QStringLiteral("Cancel"));
        Cancel->setMinimumSize(QSize(81, 31));
        Cancel->setMaximumSize(QSize(81, 31));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        Cancel->setPalette(palette2);
        Cancel->setFont(font2);
        Cancel->setAutoFillBackground(true);
        Cancel->setAutoRaise(true);

        horizontalLayout_3->addWidget(Cancel);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(InformationDialog);

        QMetaObject::connectSlotsByName(InformationDialog);
    } // setupUi

    void retranslateUi(QDialog *InformationDialog)
    {
        InformationDialog->setWindowTitle(QApplication::translate("InformationDialog", "InformationDialog", Q_NULLPTR));
        Ico->setText(QString());
        Title->setText(QApplication::translate("InformationDialog", "\346\240\207\351\242\230", Q_NULLPTR));
        Content->setText(QApplication::translate("InformationDialog", "\345\206\205\345\256\271", Q_NULLPTR));
        Sure->setText(QApplication::translate("InformationDialog", "\347\241\256\345\256\232", Q_NULLPTR));
        Cancel->setText(QApplication::translate("InformationDialog", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class InformationDialog: public Ui_InformationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFORMATIONDIALOG_H
