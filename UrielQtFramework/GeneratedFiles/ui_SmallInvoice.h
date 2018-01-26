/********************************************************************************
** Form generated from reading UI file 'SmallInvoice.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SMALLINVOICE_H
#define UI_SMALLINVOICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SmallInvoice
{
public:
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *Name;
    QLineEdit *SerialNumber;
    QLineEdit *Amount;
    QLineEdit *SerialNumber_2;
    QLineEdit *Name_2;
    QLineEdit *Amount_2;
    QLineEdit *Name_3;
    QLineEdit *SerialNumber_3;
    QLineEdit *Amount_3;
    QLineEdit *Amount_4;
    QLineEdit *SerialNumber_4;
    QLineEdit *Name_4;
    QLineEdit *Amount_5;
    QLineEdit *SerialNumber_5;
    QLineEdit *Name_5;
    QLineEdit *SerialNumber_6;
    QLineEdit *Name_6;
    QLineEdit *Amount_6;
    QLineEdit *Name_7;
    QLineEdit *Amount_7;
    QLineEdit *SerialNumber_7;
    QLineEdit *SerialNumber_8;
    QLineEdit *Name_8;
    QLineEdit *Amount_8;
    QLineEdit *SerialNumber_9;
    QLineEdit *Name_9;
    QLineEdit *Amount_9;
    QLineEdit *Name_10;
    QLineEdit *SerialNumber_10;
    QLineEdit *Amount_10;
    QLineEdit *SerialNumber_11;
    QLineEdit *Name_11;
    QLineEdit *Amount_11;
    QLineEdit *SerialNumber_12;
    QLineEdit *Name_12;
    QLineEdit *Amount_12;
    QLineEdit *Name_13;
    QLineEdit *SerialNumber_13;
    QLineEdit *Amount_13;
    QLineEdit *SerialNumber_14;
    QLineEdit *Name_14;
    QLineEdit *Amount_14;
    QLineEdit *SerialNumber_15;
    QLineEdit *Name_15;
    QLineEdit *Amount_15;
    QLineEdit *SerialNumber_16;
    QLineEdit *Name_16;
    QLineEdit *Amount_16;
    QLabel *label;
    QToolButton *LocalTransportationTBtn;
    QToolButton *MailingFeeTBtn;
    QToolButton *OtherTBtn;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *TotalAmount;
    QFrame *line;
    QToolButton *ConfirmTBtn;
    QToolButton *StatisticsTBtn;
    QSpacerItem *horizontalSpacer_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout_7;
    QToolButton *AppClose;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *SmallInvoice)
    {
        if (SmallInvoice->objectName().isEmpty())
            SmallInvoice->setObjectName(QStringLiteral("SmallInvoice"));
        SmallInvoice->resize(1178, 718);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        SmallInvoice->setPalette(palette);
        horizontalLayout_2 = new QHBoxLayout(SmallInvoice);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(261, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        groupBox = new QGroupBox(SmallInvoice);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(671, 700));
        groupBox->setMaximumSize(QSize(671, 700));
        groupBox->setFlat(true);
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(20, 80, 81, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(16);
        lineEdit->setFont(font);
        lineEdit->setAlignment(Qt::AlignCenter);
        lineEdit->setReadOnly(true);
        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(100, 80, 311, 31));
        lineEdit_2->setFont(font);
        lineEdit_2->setAlignment(Qt::AlignCenter);
        lineEdit_2->setReadOnly(true);
        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(410, 80, 241, 31));
        lineEdit_3->setFont(font);
        lineEdit_3->setAlignment(Qt::AlignCenter);
        lineEdit_3->setReadOnly(true);
        Name = new QLineEdit(groupBox);
        Name->setObjectName(QStringLiteral("Name"));
        Name->setGeometry(QRect(100, 110, 311, 31));
        Name->setFont(font);
        Name->setAlignment(Qt::AlignCenter);
        SerialNumber = new QLineEdit(groupBox);
        SerialNumber->setObjectName(QStringLiteral("SerialNumber"));
        SerialNumber->setGeometry(QRect(20, 110, 81, 31));
        SerialNumber->setFont(font);
        SerialNumber->setAlignment(Qt::AlignCenter);
        Amount = new QLineEdit(groupBox);
        Amount->setObjectName(QStringLiteral("Amount"));
        Amount->setGeometry(QRect(410, 110, 241, 31));
        Amount->setFont(font);
        Amount->setAlignment(Qt::AlignCenter);
        SerialNumber_2 = new QLineEdit(groupBox);
        SerialNumber_2->setObjectName(QStringLiteral("SerialNumber_2"));
        SerialNumber_2->setGeometry(QRect(20, 140, 81, 31));
        SerialNumber_2->setFont(font);
        SerialNumber_2->setAlignment(Qt::AlignCenter);
        Name_2 = new QLineEdit(groupBox);
        Name_2->setObjectName(QStringLiteral("Name_2"));
        Name_2->setGeometry(QRect(100, 140, 311, 31));
        Name_2->setFont(font);
        Name_2->setAlignment(Qt::AlignCenter);
        Amount_2 = new QLineEdit(groupBox);
        Amount_2->setObjectName(QStringLiteral("Amount_2"));
        Amount_2->setGeometry(QRect(410, 140, 241, 31));
        Amount_2->setFont(font);
        Amount_2->setAlignment(Qt::AlignCenter);
        Name_3 = new QLineEdit(groupBox);
        Name_3->setObjectName(QStringLiteral("Name_3"));
        Name_3->setGeometry(QRect(100, 170, 311, 31));
        Name_3->setFont(font);
        Name_3->setAlignment(Qt::AlignCenter);
        SerialNumber_3 = new QLineEdit(groupBox);
        SerialNumber_3->setObjectName(QStringLiteral("SerialNumber_3"));
        SerialNumber_3->setGeometry(QRect(20, 170, 81, 31));
        SerialNumber_3->setFont(font);
        SerialNumber_3->setAlignment(Qt::AlignCenter);
        Amount_3 = new QLineEdit(groupBox);
        Amount_3->setObjectName(QStringLiteral("Amount_3"));
        Amount_3->setGeometry(QRect(410, 170, 241, 31));
        Amount_3->setFont(font);
        Amount_3->setAlignment(Qt::AlignCenter);
        Amount_4 = new QLineEdit(groupBox);
        Amount_4->setObjectName(QStringLiteral("Amount_4"));
        Amount_4->setGeometry(QRect(410, 200, 241, 31));
        Amount_4->setFont(font);
        Amount_4->setAlignment(Qt::AlignCenter);
        SerialNumber_4 = new QLineEdit(groupBox);
        SerialNumber_4->setObjectName(QStringLiteral("SerialNumber_4"));
        SerialNumber_4->setGeometry(QRect(20, 200, 81, 31));
        SerialNumber_4->setFont(font);
        SerialNumber_4->setAlignment(Qt::AlignCenter);
        Name_4 = new QLineEdit(groupBox);
        Name_4->setObjectName(QStringLiteral("Name_4"));
        Name_4->setGeometry(QRect(100, 200, 311, 31));
        Name_4->setFont(font);
        Name_4->setAlignment(Qt::AlignCenter);
        Amount_5 = new QLineEdit(groupBox);
        Amount_5->setObjectName(QStringLiteral("Amount_5"));
        Amount_5->setGeometry(QRect(410, 230, 241, 31));
        Amount_5->setFont(font);
        Amount_5->setAlignment(Qt::AlignCenter);
        SerialNumber_5 = new QLineEdit(groupBox);
        SerialNumber_5->setObjectName(QStringLiteral("SerialNumber_5"));
        SerialNumber_5->setGeometry(QRect(20, 230, 81, 31));
        SerialNumber_5->setFont(font);
        SerialNumber_5->setAlignment(Qt::AlignCenter);
        Name_5 = new QLineEdit(groupBox);
        Name_5->setObjectName(QStringLiteral("Name_5"));
        Name_5->setGeometry(QRect(100, 230, 311, 31));
        Name_5->setFont(font);
        Name_5->setAlignment(Qt::AlignCenter);
        SerialNumber_6 = new QLineEdit(groupBox);
        SerialNumber_6->setObjectName(QStringLiteral("SerialNumber_6"));
        SerialNumber_6->setGeometry(QRect(20, 260, 81, 31));
        SerialNumber_6->setFont(font);
        SerialNumber_6->setAlignment(Qt::AlignCenter);
        Name_6 = new QLineEdit(groupBox);
        Name_6->setObjectName(QStringLiteral("Name_6"));
        Name_6->setGeometry(QRect(100, 260, 311, 31));
        Name_6->setFont(font);
        Name_6->setAlignment(Qt::AlignCenter);
        Amount_6 = new QLineEdit(groupBox);
        Amount_6->setObjectName(QStringLiteral("Amount_6"));
        Amount_6->setGeometry(QRect(410, 260, 241, 31));
        Amount_6->setFont(font);
        Amount_6->setAlignment(Qt::AlignCenter);
        Name_7 = new QLineEdit(groupBox);
        Name_7->setObjectName(QStringLiteral("Name_7"));
        Name_7->setGeometry(QRect(100, 290, 311, 31));
        Name_7->setFont(font);
        Name_7->setAlignment(Qt::AlignCenter);
        Amount_7 = new QLineEdit(groupBox);
        Amount_7->setObjectName(QStringLiteral("Amount_7"));
        Amount_7->setGeometry(QRect(410, 290, 241, 31));
        Amount_7->setFont(font);
        Amount_7->setAlignment(Qt::AlignCenter);
        SerialNumber_7 = new QLineEdit(groupBox);
        SerialNumber_7->setObjectName(QStringLiteral("SerialNumber_7"));
        SerialNumber_7->setGeometry(QRect(20, 290, 81, 31));
        SerialNumber_7->setFont(font);
        SerialNumber_7->setAlignment(Qt::AlignCenter);
        SerialNumber_8 = new QLineEdit(groupBox);
        SerialNumber_8->setObjectName(QStringLiteral("SerialNumber_8"));
        SerialNumber_8->setGeometry(QRect(20, 320, 81, 31));
        SerialNumber_8->setFont(font);
        SerialNumber_8->setAlignment(Qt::AlignCenter);
        Name_8 = new QLineEdit(groupBox);
        Name_8->setObjectName(QStringLiteral("Name_8"));
        Name_8->setGeometry(QRect(100, 320, 311, 31));
        Name_8->setFont(font);
        Name_8->setAlignment(Qt::AlignCenter);
        Amount_8 = new QLineEdit(groupBox);
        Amount_8->setObjectName(QStringLiteral("Amount_8"));
        Amount_8->setGeometry(QRect(410, 320, 241, 31));
        Amount_8->setFont(font);
        Amount_8->setAlignment(Qt::AlignCenter);
        SerialNumber_9 = new QLineEdit(groupBox);
        SerialNumber_9->setObjectName(QStringLiteral("SerialNumber_9"));
        SerialNumber_9->setGeometry(QRect(20, 350, 81, 31));
        SerialNumber_9->setFont(font);
        SerialNumber_9->setAlignment(Qt::AlignCenter);
        Name_9 = new QLineEdit(groupBox);
        Name_9->setObjectName(QStringLiteral("Name_9"));
        Name_9->setGeometry(QRect(100, 350, 311, 31));
        Name_9->setFont(font);
        Name_9->setAlignment(Qt::AlignCenter);
        Amount_9 = new QLineEdit(groupBox);
        Amount_9->setObjectName(QStringLiteral("Amount_9"));
        Amount_9->setGeometry(QRect(410, 350, 241, 31));
        Amount_9->setFont(font);
        Amount_9->setAlignment(Qt::AlignCenter);
        Name_10 = new QLineEdit(groupBox);
        Name_10->setObjectName(QStringLiteral("Name_10"));
        Name_10->setGeometry(QRect(100, 380, 311, 31));
        Name_10->setFont(font);
        Name_10->setAlignment(Qt::AlignCenter);
        SerialNumber_10 = new QLineEdit(groupBox);
        SerialNumber_10->setObjectName(QStringLiteral("SerialNumber_10"));
        SerialNumber_10->setGeometry(QRect(20, 380, 81, 31));
        SerialNumber_10->setFont(font);
        SerialNumber_10->setAlignment(Qt::AlignCenter);
        Amount_10 = new QLineEdit(groupBox);
        Amount_10->setObjectName(QStringLiteral("Amount_10"));
        Amount_10->setGeometry(QRect(410, 380, 241, 31));
        Amount_10->setFont(font);
        Amount_10->setAlignment(Qt::AlignCenter);
        SerialNumber_11 = new QLineEdit(groupBox);
        SerialNumber_11->setObjectName(QStringLiteral("SerialNumber_11"));
        SerialNumber_11->setGeometry(QRect(20, 410, 81, 31));
        SerialNumber_11->setFont(font);
        SerialNumber_11->setAlignment(Qt::AlignCenter);
        Name_11 = new QLineEdit(groupBox);
        Name_11->setObjectName(QStringLiteral("Name_11"));
        Name_11->setGeometry(QRect(100, 410, 311, 31));
        Name_11->setFont(font);
        Name_11->setAlignment(Qt::AlignCenter);
        Amount_11 = new QLineEdit(groupBox);
        Amount_11->setObjectName(QStringLiteral("Amount_11"));
        Amount_11->setGeometry(QRect(410, 410, 241, 31));
        Amount_11->setFont(font);
        Amount_11->setAlignment(Qt::AlignCenter);
        SerialNumber_12 = new QLineEdit(groupBox);
        SerialNumber_12->setObjectName(QStringLiteral("SerialNumber_12"));
        SerialNumber_12->setGeometry(QRect(20, 440, 81, 31));
        SerialNumber_12->setFont(font);
        SerialNumber_12->setAlignment(Qt::AlignCenter);
        Name_12 = new QLineEdit(groupBox);
        Name_12->setObjectName(QStringLiteral("Name_12"));
        Name_12->setGeometry(QRect(100, 440, 311, 31));
        Name_12->setFont(font);
        Name_12->setAlignment(Qt::AlignCenter);
        Amount_12 = new QLineEdit(groupBox);
        Amount_12->setObjectName(QStringLiteral("Amount_12"));
        Amount_12->setGeometry(QRect(410, 440, 241, 31));
        Amount_12->setFont(font);
        Amount_12->setAlignment(Qt::AlignCenter);
        Name_13 = new QLineEdit(groupBox);
        Name_13->setObjectName(QStringLiteral("Name_13"));
        Name_13->setGeometry(QRect(100, 470, 311, 31));
        Name_13->setFont(font);
        Name_13->setAlignment(Qt::AlignCenter);
        SerialNumber_13 = new QLineEdit(groupBox);
        SerialNumber_13->setObjectName(QStringLiteral("SerialNumber_13"));
        SerialNumber_13->setGeometry(QRect(20, 470, 81, 31));
        SerialNumber_13->setFont(font);
        SerialNumber_13->setAlignment(Qt::AlignCenter);
        Amount_13 = new QLineEdit(groupBox);
        Amount_13->setObjectName(QStringLiteral("Amount_13"));
        Amount_13->setGeometry(QRect(410, 470, 241, 31));
        Amount_13->setFont(font);
        Amount_13->setAlignment(Qt::AlignCenter);
        SerialNumber_14 = new QLineEdit(groupBox);
        SerialNumber_14->setObjectName(QStringLiteral("SerialNumber_14"));
        SerialNumber_14->setGeometry(QRect(20, 500, 81, 31));
        SerialNumber_14->setFont(font);
        SerialNumber_14->setAlignment(Qt::AlignCenter);
        Name_14 = new QLineEdit(groupBox);
        Name_14->setObjectName(QStringLiteral("Name_14"));
        Name_14->setGeometry(QRect(100, 500, 311, 31));
        Name_14->setFont(font);
        Name_14->setAlignment(Qt::AlignCenter);
        Amount_14 = new QLineEdit(groupBox);
        Amount_14->setObjectName(QStringLiteral("Amount_14"));
        Amount_14->setGeometry(QRect(410, 500, 241, 31));
        Amount_14->setFont(font);
        Amount_14->setAlignment(Qt::AlignCenter);
        SerialNumber_15 = new QLineEdit(groupBox);
        SerialNumber_15->setObjectName(QStringLiteral("SerialNumber_15"));
        SerialNumber_15->setGeometry(QRect(20, 530, 81, 31));
        SerialNumber_15->setFont(font);
        SerialNumber_15->setAlignment(Qt::AlignCenter);
        Name_15 = new QLineEdit(groupBox);
        Name_15->setObjectName(QStringLiteral("Name_15"));
        Name_15->setGeometry(QRect(100, 530, 311, 31));
        Name_15->setFont(font);
        Name_15->setAlignment(Qt::AlignCenter);
        Amount_15 = new QLineEdit(groupBox);
        Amount_15->setObjectName(QStringLiteral("Amount_15"));
        Amount_15->setGeometry(QRect(410, 530, 241, 31));
        Amount_15->setFont(font);
        Amount_15->setAlignment(Qt::AlignCenter);
        SerialNumber_16 = new QLineEdit(groupBox);
        SerialNumber_16->setObjectName(QStringLiteral("SerialNumber_16"));
        SerialNumber_16->setGeometry(QRect(20, 560, 81, 31));
        SerialNumber_16->setFont(font);
        SerialNumber_16->setAlignment(Qt::AlignCenter);
        Name_16 = new QLineEdit(groupBox);
        Name_16->setObjectName(QStringLiteral("Name_16"));
        Name_16->setGeometry(QRect(100, 560, 311, 31));
        Name_16->setFont(font);
        Name_16->setAlignment(Qt::AlignCenter);
        Amount_16 = new QLineEdit(groupBox);
        Amount_16->setObjectName(QStringLiteral("Amount_16"));
        Amount_16->setGeometry(QRect(410, 560, 241, 31));
        Amount_16->setFont(font);
        Amount_16->setAlignment(Qt::AlignCenter);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(250, 0, 171, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(20);
        font1.setUnderline(true);
        label->setFont(font1);
        LocalTransportationTBtn = new QToolButton(groupBox);
        LocalTransportationTBtn->setObjectName(QStringLiteral("LocalTransportationTBtn"));
        LocalTransportationTBtn->setGeometry(QRect(120, 40, 121, 31));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(239, 239, 239, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        LocalTransportationTBtn->setPalette(palette1);
        LocalTransportationTBtn->setFont(font);
        LocalTransportationTBtn->setAutoFillBackground(true);
        LocalTransportationTBtn->setAutoRaise(true);
        MailingFeeTBtn = new QToolButton(groupBox);
        MailingFeeTBtn->setObjectName(QStringLiteral("MailingFeeTBtn"));
        MailingFeeTBtn->setGeometry(QRect(280, 40, 121, 31));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Base, brush);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        MailingFeeTBtn->setPalette(palette2);
        MailingFeeTBtn->setFont(font);
        MailingFeeTBtn->setAutoFillBackground(true);
        MailingFeeTBtn->setAutoRaise(true);
        OtherTBtn = new QToolButton(groupBox);
        OtherTBtn->setObjectName(QStringLiteral("OtherTBtn"));
        OtherTBtn->setGeometry(QRect(430, 40, 121, 31));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Base, brush);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        OtherTBtn->setPalette(palette3);
        OtherTBtn->setFont(font);
        OtherTBtn->setAutoFillBackground(true);
        OtherTBtn->setAutoRaise(true);
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 600, 631, 56));
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(18);
        label_2->setFont(font2);

        horizontalLayout->addWidget(label_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        TotalAmount = new QLineEdit(groupBox_2);
        TotalAmount->setObjectName(QStringLiteral("TotalAmount"));
        TotalAmount->setFont(font2);
        TotalAmount->setFrame(false);
        TotalAmount->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(TotalAmount);

        line = new QFrame(groupBox_2);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);


        horizontalLayout->addLayout(verticalLayout);

        ConfirmTBtn = new QToolButton(groupBox);
        ConfirmTBtn->setObjectName(QStringLiteral("ConfirmTBtn"));
        ConfirmTBtn->setGeometry(QRect(440, 660, 171, 31));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Base, brush);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        ConfirmTBtn->setPalette(palette4);
        ConfirmTBtn->setFont(font2);
        ConfirmTBtn->setAutoFillBackground(true);
        ConfirmTBtn->setAutoRaise(true);
        StatisticsTBtn = new QToolButton(groupBox);
        StatisticsTBtn->setObjectName(QStringLiteral("StatisticsTBtn"));
        StatisticsTBtn->setGeometry(QRect(250, 660, 171, 31));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Base, brush);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        StatisticsTBtn->setPalette(palette5);
        StatisticsTBtn->setFont(font2);
        StatisticsTBtn->setAutoFillBackground(true);
        StatisticsTBtn->setAutoRaise(true);

        horizontalLayout_2->addWidget(groupBox);

        horizontalSpacer_2 = new QSpacerItem(162, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        frame = new QFrame(SmallInvoice);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(42, 0));
        frame->setMaximumSize(QSize(42, 16777215));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_7 = new QVBoxLayout(frame);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        AppClose = new QToolButton(frame);
        AppClose->setObjectName(QStringLiteral("AppClose"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Expense/Resources/Expense/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        AppClose->setIcon(icon);
        AppClose->setIconSize(QSize(35, 35));
        AppClose->setAutoRaise(true);

        verticalLayout_7->addWidget(AppClose);

        verticalSpacer = new QSpacerItem(20, 533, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer);


        horizontalLayout_2->addWidget(frame);


        retranslateUi(SmallInvoice);

        QMetaObject::connectSlotsByName(SmallInvoice);
    } // setupUi

    void retranslateUi(QDialog *SmallInvoice)
    {
        SmallInvoice->setWindowTitle(QApplication::translate("SmallInvoice", "SmallInvoice", Q_NULLPTR));
        groupBox->setTitle(QString());
        lineEdit->setText(QApplication::translate("SmallInvoice", "\345\272\217\345\217\267", Q_NULLPTR));
        lineEdit_2->setText(QApplication::translate("SmallInvoice", "\345\220\215\347\247\260", Q_NULLPTR));
        lineEdit_3->setText(QApplication::translate("SmallInvoice", "\351\207\221\351\242\235", Q_NULLPTR));
        Name->setText(QString());
        SerialNumber->setText(QString());
        Amount->setText(QString());
        SerialNumber_2->setText(QString());
        Name_2->setText(QString());
        Amount_2->setText(QString());
        Name_3->setText(QString());
        SerialNumber_3->setText(QString());
        Amount_3->setText(QString());
        Amount_4->setText(QString());
        SerialNumber_4->setText(QString());
        Name_4->setText(QString());
        Amount_5->setText(QString());
        SerialNumber_5->setText(QString());
        Name_5->setText(QString());
        SerialNumber_6->setText(QString());
        Name_6->setText(QString());
        Amount_6->setText(QString());
        Name_7->setText(QString());
        Amount_7->setText(QString());
        SerialNumber_7->setText(QString());
        SerialNumber_8->setText(QString());
        Name_8->setText(QString());
        Amount_8->setText(QString());
        SerialNumber_9->setText(QString());
        Name_9->setText(QString());
        Amount_9->setText(QString());
        Name_10->setText(QString());
        SerialNumber_10->setText(QString());
        Amount_10->setText(QString());
        SerialNumber_11->setText(QString());
        Name_11->setText(QString());
        Amount_11->setText(QString());
        SerialNumber_12->setText(QString());
        Name_12->setText(QString());
        Amount_12->setText(QString());
        Name_13->setText(QString());
        SerialNumber_13->setText(QString());
        Amount_13->setText(QString());
        SerialNumber_14->setText(QString());
        Name_14->setText(QString());
        Amount_14->setText(QString());
        SerialNumber_15->setText(QString());
        Name_15->setText(QString());
        Amount_15->setText(QString());
        SerialNumber_16->setText(QString());
        Name_16->setText(QString());
        Amount_16->setText(QString());
        label->setText(QApplication::translate("SmallInvoice", "\345\260\217\351\242\235\345\217\221\347\245\250\345\241\253\345\206\231", Q_NULLPTR));
        LocalTransportationTBtn->setText(QApplication::translate("SmallInvoice", "\345\270\202\345\206\205\344\272\244\351\200\232\350\264\271", Q_NULLPTR));
        MailingFeeTBtn->setText(QApplication::translate("SmallInvoice", "\351\202\256\345\257\204\350\264\271", Q_NULLPTR));
        OtherTBtn->setText(QApplication::translate("SmallInvoice", "\345\205\266\344\273\226", Q_NULLPTR));
        groupBox_2->setTitle(QString());
        label_2->setText(QApplication::translate("SmallInvoice", "\346\200\273\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        TotalAmount->setText(QString());
        ConfirmTBtn->setText(QApplication::translate("SmallInvoice", "\347\241\256\350\256\244\346\267\273\345\212\240", Q_NULLPTR));
        StatisticsTBtn->setText(QApplication::translate("SmallInvoice", "\344\270\200\351\224\256\347\273\237\350\256\241", Q_NULLPTR));
        AppClose->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SmallInvoice: public Ui_SmallInvoice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMALLINVOICE_H
