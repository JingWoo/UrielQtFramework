/********************************************************************************
** Form generated from reading UI file 'LiftingProhibitionDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIFTINGPROHIBITIONDIALOG_H
#define UI_LIFTINGPROHIBITIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LiftingProhibitionDialog
{
public:
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QLabel *Title;
    QSpacerItem *verticalSpacer_4;
    QComboBox *comboBox;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QToolButton *Cancel;
    QSpacerItem *horizontalSpacer;
    QToolButton *OK;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QDialog *LiftingProhibitionDialog)
    {
        if (LiftingProhibitionDialog->objectName().isEmpty())
            LiftingProhibitionDialog->setObjectName(QStringLiteral("LiftingProhibitionDialog"));
        LiftingProhibitionDialog->resize(805, 440);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(70, 70, 70, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        LiftingProhibitionDialog->setPalette(palette);
        horizontalLayout_2 = new QHBoxLayout(LiftingProhibitionDialog);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(83, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        Title = new QLabel(LiftingProhibitionDialog);
        Title->setObjectName(QStringLiteral("Title"));
        QPalette palette1;
        QBrush brush2(QColor(185, 185, 185, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        QBrush brush3(QColor(204, 204, 204, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        QBrush brush4(QColor(120, 120, 120, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        Title->setPalette(palette1);
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(26);
        Title->setFont(font);

        verticalLayout_2->addWidget(Title);

        verticalSpacer_4 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_4);

        comboBox = new QComboBox(LiftingProhibitionDialog);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMinimumSize(QSize(600, 0));
        comboBox->setMaximumSize(QSize(650, 16777215));
        QPalette palette2;
        QBrush brush5(QColor(108, 108, 108, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush5);
        comboBox->setPalette(palette2);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(24);
        comboBox->setFont(font1);
        comboBox->setAutoFillBackground(true);
        comboBox->setFrame(false);

        verticalLayout_2->addWidget(comboBox);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer_3 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        Cancel = new QToolButton(LiftingProhibitionDialog);
        Cancel->setObjectName(QStringLiteral("Cancel"));
        Cancel->setMinimumSize(QSize(130, 40));
        Cancel->setMaximumSize(QSize(130, 40));
        QPalette palette3;
        QBrush brush6(QColor(94, 94, 94, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        Cancel->setPalette(palette3);
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(22);
        Cancel->setFont(font2);
        Cancel->setAutoFillBackground(true);
        Cancel->setAutoRaise(true);

        horizontalLayout->addWidget(Cancel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        OK = new QToolButton(LiftingProhibitionDialog);
        OK->setObjectName(QStringLiteral("OK"));
        OK->setMinimumSize(QSize(130, 40));
        OK->setMaximumSize(QSize(130, 40));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Button, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        OK->setPalette(palette4);
        OK->setFont(font2);
        OK->setAutoFillBackground(true);
        OK->setAutoRaise(true);

        horizontalLayout->addWidget(OK);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout_2->addLayout(verticalLayout_2);

        horizontalSpacer_5 = new QSpacerItem(82, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        retranslateUi(LiftingProhibitionDialog);

        QMetaObject::connectSlotsByName(LiftingProhibitionDialog);
    } // setupUi

    void retranslateUi(QDialog *LiftingProhibitionDialog)
    {
        LiftingProhibitionDialog->setWindowTitle(QApplication::translate("LiftingProhibitionDialog", "LiftingProhibitionDialog", Q_NULLPTR));
        Title->setText(QApplication::translate("LiftingProhibitionDialog", "\350\257\267\351\200\211\346\213\251\351\234\200\350\246\201\350\247\243\347\246\201\347\232\204\346\212\245\351\224\200\344\273\243\345\217\267", Q_NULLPTR));
        Cancel->setText(QApplication::translate("LiftingProhibitionDialog", "\345\217\226\346\266\210", Q_NULLPTR));
        OK->setText(QApplication::translate("LiftingProhibitionDialog", "\347\241\256\345\256\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LiftingProhibitionDialog: public Ui_LiftingProhibitionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIFTINGPROHIBITIONDIALOG_H
