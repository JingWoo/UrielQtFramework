/********************************************************************************
** Form generated from reading UI file 'InvoiceInfo.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVOICEINFO_H
#define UI_INVOICEINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InvoiceInfo
{
public:
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *Name;
    QFrame *line;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *Model;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_5;
    QSpinBox *Quantity;
    QFrame *line_5;
    QSpacerItem *horizontalSpacer;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_13;
    QComboBox *Unit;
    QFrame *line_13;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_7;
    QVBoxLayout *verticalLayout_6;
    QLineEdit *Univalent;
    QFrame *line_6;
    QLabel *label_8;
    QToolButton *Calculate;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_15;
    QVBoxLayout *verticalLayout_12;
    QLineEdit *AggregateAmount;
    QFrame *line_12;
    QLabel *label_16;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *InvoiceImage;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_16;
    QSpacerItem *verticalSpacer_5;
    QToolButton *AddInvoiceImage;
    QToolButton *PreviewInvoiceImage;
    QToolButton *DeleteInvoiceImage;
    QSpacerItem *verticalSpacer_6;
    QGroupBox *groupBox_5;
    QHBoxLayout *horizontalLayout_7;
    QLabel *BuyScreenshot;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_17;
    QSpacerItem *verticalSpacer_7;
    QToolButton *AddBuyScreenshot;
    QToolButton *PreviewBuyScreenshot;
    QToolButton *DeleteBuyScreenshot;
    QSpacerItem *verticalSpacer_8;
    QGroupBox *groupBox_6;
    QHBoxLayout *horizontalLayout_8;
    QLabel *VerificationImage;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_18;
    QSpacerItem *verticalSpacer_9;
    QToolButton *AddVerificationImage;
    QToolButton *PreviewVerificationImage;
    QToolButton *DeleteVerificationImage;
    QSpacerItem *verticalSpacer_10;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_8;
    QTextEdit *Description;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *Cancel;
    QPushButton *OK;
    QSpacerItem *horizontalSpacer_4;
    QFrame *frame;
    QVBoxLayout *verticalLayout_7;
    QToolButton *AppClose;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *InvoiceInfo)
    {
        if (InvoiceInfo->objectName().isEmpty())
            InvoiceInfo->setObjectName(QStringLiteral("InvoiceInfo"));
        InvoiceInfo->resize(1325, 772);
        QPalette palette;
        QBrush brush(QColor(156, 156, 156, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        InvoiceInfo->setPalette(palette);
        InvoiceInfo->setAutoFillBackground(true);
        horizontalLayout_10 = new QHBoxLayout(InvoiceInfo);
        horizontalLayout_10->setSpacing(0);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(293, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_3);

        scrollArea = new QScrollArea(InvoiceInfo);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setMinimumSize(QSize(426, 0));
        scrollArea->setMaximumSize(QSize(800, 16777215));
        scrollArea->setFrameShape(QFrame::StyledPanel);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, -540, 678, 1432));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QStringLiteral("label"));
        QPalette palette1;
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label->setPalette(palette1);
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(20);
        label->setFont(font);

        verticalLayout_2->addWidget(label);

        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        groupBox->setPalette(palette2);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(16);
        groupBox->setFont(font1);
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_2->setPalette(palette3);
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(12);
        label_2->setFont(font2);

        horizontalLayout_5->addWidget(label_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Name = new QLineEdit(groupBox);
        Name->setObjectName(QStringLiteral("Name"));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Button, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush);
        Name->setPalette(palette4);
        Name->setFont(font2);
        Name->setAutoFillBackground(true);
        Name->setFrame(false);

        verticalLayout->addWidget(Name);

        line = new QFrame(groupBox);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);


        horizontalLayout_5->addLayout(verticalLayout);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_4->setPalette(palette5);
        label_4->setFont(font2);

        horizontalLayout_4->addWidget(label_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        Model = new QLineEdit(groupBox);
        Model->setObjectName(QStringLiteral("Model"));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::Button, brush);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush);
        Model->setPalette(palette6);
        Model->setFont(font2);
        Model->setAutoFillBackground(true);
        Model->setFrame(false);

        verticalLayout_3->addWidget(Model);

        line_3 = new QFrame(groupBox);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_3);


        horizontalLayout_4->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_5->setPalette(palette7);
        label_5->setFont(font2);

        horizontalLayout->addWidget(label_5);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        Quantity = new QSpinBox(groupBox);
        Quantity->setObjectName(QStringLiteral("Quantity"));
        Quantity->setMinimumSize(QSize(75, 0));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::Base, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush);
        Quantity->setPalette(palette8);
        Quantity->setFrame(false);
        Quantity->setMaximum(9999);
        Quantity->setValue(1);

        verticalLayout_5->addWidget(Quantity);

        line_5 = new QFrame(groupBox);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_5);


        horizontalLayout->addLayout(verticalLayout_5);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_6->setPalette(palette9);
        label_6->setFont(font2);

        horizontalLayout->addWidget(label_6);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setSpacing(0);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        Unit = new QComboBox(groupBox);
        Unit->setObjectName(QStringLiteral("Unit"));
        QPalette palette10;
        QBrush brush3(QColor(0, 0, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette10.setBrush(QPalette::Active, QPalette::Button, brush);
        palette10.setBrush(QPalette::Active, QPalette::Light, brush);
        palette10.setBrush(QPalette::Active, QPalette::Midlight, brush);
        QBrush brush4(QColor(78, 78, 78, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette10.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(104, 104, 104, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette10.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette10.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette10.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette10.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette10.setBrush(QPalette::Active, QPalette::Base, brush);
        palette10.setBrush(QPalette::Active, QPalette::Window, brush);
        palette10.setBrush(QPalette::Active, QPalette::Shadow, brush3);
        palette10.setBrush(QPalette::Active, QPalette::HighlightedText, brush);
        QBrush brush6(QColor(205, 205, 205, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette10.setBrush(QPalette::Active, QPalette::AlternateBase, brush6);
        QBrush brush7(QColor(255, 255, 220, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette10.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette10.setBrush(QPalette::Active, QPalette::ToolTipText, brush3);
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette10.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette10.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette10.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette10.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::Shadow, brush3);
        palette10.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush6);
        palette10.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette10.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush3);
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette10.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette10.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette10.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette10.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette10.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::Shadow, brush3);
        palette10.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette10.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush3);
        Unit->setPalette(palette10);
        Unit->setAutoFillBackground(true);
        Unit->setEditable(true);
        Unit->setFrame(false);

        verticalLayout_13->addWidget(Unit);

        line_13 = new QFrame(groupBox);
        line_13->setObjectName(QStringLiteral("line_13"));
        line_13->setFrameShape(QFrame::HLine);
        line_13->setFrameShadow(QFrame::Sunken);

        verticalLayout_13->addWidget(line_13);


        horizontalLayout->addLayout(verticalLayout_13);


        verticalLayout_4->addLayout(horizontalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette11.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_7->setPalette(palette11);
        label_7->setFont(font2);

        horizontalLayout_2->addWidget(label_7);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        Univalent = new QLineEdit(groupBox);
        Univalent->setObjectName(QStringLiteral("Univalent"));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::Button, brush);
        palette12.setBrush(QPalette::Active, QPalette::Base, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette12.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette12.setBrush(QPalette::Disabled, QPalette::Base, brush);
        Univalent->setPalette(palette12);
        Univalent->setFont(font2);
        Univalent->setAutoFillBackground(true);
        Univalent->setFrame(false);

        verticalLayout_6->addWidget(Univalent);

        line_6 = new QFrame(groupBox);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        verticalLayout_6->addWidget(line_6);


        horizontalLayout_2->addLayout(verticalLayout_6);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette13.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette13.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_8->setPalette(palette13);
        label_8->setFont(font2);

        horizontalLayout_2->addWidget(label_8);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        Calculate = new QToolButton(groupBox);
        Calculate->setObjectName(QStringLiteral("Calculate"));
        QFont font3;
        font3.setPointSize(14);
        Calculate->setFont(font3);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Expense/Resources/Expense/cala.png"), QSize(), QIcon::Normal, QIcon::Off);
        Calculate->setIcon(icon);
        Calculate->setIconSize(QSize(45, 45));
        Calculate->setAutoRaise(true);

        gridLayout->addWidget(Calculate, 0, 1, 2, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_15 = new QLabel(groupBox);
        label_15->setObjectName(QStringLiteral("label_15"));
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette14.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette14.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_15->setPalette(palette14);
        label_15->setFont(font2);

        horizontalLayout_3->addWidget(label_15);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(0);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        AggregateAmount = new QLineEdit(groupBox);
        AggregateAmount->setObjectName(QStringLiteral("AggregateAmount"));
        QPalette palette15;
        palette15.setBrush(QPalette::Active, QPalette::Button, brush);
        palette15.setBrush(QPalette::Active, QPalette::Base, brush);
        palette15.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette15.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette15.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette15.setBrush(QPalette::Disabled, QPalette::Base, brush);
        AggregateAmount->setPalette(palette15);
        AggregateAmount->setFont(font2);
        AggregateAmount->setAutoFillBackground(true);
        AggregateAmount->setFrame(false);

        verticalLayout_12->addWidget(AggregateAmount);

        line_12 = new QFrame(groupBox);
        line_12->setObjectName(QStringLiteral("line_12"));
        line_12->setFrameShape(QFrame::HLine);
        line_12->setFrameShadow(QFrame::Sunken);

        verticalLayout_12->addWidget(line_12);


        horizontalLayout_3->addLayout(verticalLayout_12);

        label_16 = new QLabel(groupBox);
        label_16->setObjectName(QStringLiteral("label_16"));
        QPalette palette16;
        palette16.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette16.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette16.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_16->setPalette(palette16);
        label_16->setFont(font2);

        horizontalLayout_3->addWidget(label_16);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);


        verticalLayout_4->addLayout(gridLayout);


        verticalLayout_2->addWidget(groupBox);

        groupBox_4 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        QPalette palette17;
        palette17.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette17.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette17.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        groupBox_4->setPalette(palette17);
        groupBox_4->setFont(font1);
        horizontalLayout_6 = new QHBoxLayout(groupBox_4);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        InvoiceImage = new QLabel(groupBox_4);
        InvoiceImage->setObjectName(QStringLiteral("InvoiceImage"));
        InvoiceImage->setMinimumSize(QSize(300, 300));
        InvoiceImage->setPixmap(QPixmap(QString::fromUtf8(":/Expense/Resources/Expense/nopicture.png")));
        InvoiceImage->setScaledContents(true);

        horizontalLayout_6->addWidget(InvoiceImage);

        frame_3 = new QFrame(groupBox_4);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setMinimumSize(QSize(38, 150));
        frame_3->setMaximumSize(QSize(38, 150));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_16 = new QVBoxLayout(frame_3);
        verticalLayout_16->setSpacing(0);
        verticalLayout_16->setContentsMargins(11, 11, 11, 11);
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        verticalLayout_16->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_5 = new QSpacerItem(18, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_16->addItem(verticalSpacer_5);

        AddInvoiceImage = new QToolButton(frame_3);
        AddInvoiceImage->setObjectName(QStringLiteral("AddInvoiceImage"));
        AddInvoiceImage->setMinimumSize(QSize(36, 36));
        AddInvoiceImage->setMaximumSize(QSize(36, 36));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Expense/Resources/Expense/addpicture.png"), QSize(), QIcon::Normal, QIcon::Off);
        AddInvoiceImage->setIcon(icon1);
        AddInvoiceImage->setIconSize(QSize(30, 30));
        AddInvoiceImage->setAutoRaise(true);

        verticalLayout_16->addWidget(AddInvoiceImage);

        PreviewInvoiceImage = new QToolButton(frame_3);
        PreviewInvoiceImage->setObjectName(QStringLiteral("PreviewInvoiceImage"));
        PreviewInvoiceImage->setMinimumSize(QSize(36, 36));
        PreviewInvoiceImage->setMaximumSize(QSize(36, 36));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Expense/Resources/Expense/previewpicture.png"), QSize(), QIcon::Normal, QIcon::Off);
        PreviewInvoiceImage->setIcon(icon2);
        PreviewInvoiceImage->setIconSize(QSize(30, 30));
        PreviewInvoiceImage->setAutoRaise(true);

        verticalLayout_16->addWidget(PreviewInvoiceImage);

        DeleteInvoiceImage = new QToolButton(frame_3);
        DeleteInvoiceImage->setObjectName(QStringLiteral("DeleteInvoiceImage"));
        DeleteInvoiceImage->setMinimumSize(QSize(36, 36));
        DeleteInvoiceImage->setMaximumSize(QSize(36, 36));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Expense/Resources/Expense/deletepicture.png"), QSize(), QIcon::Normal, QIcon::Off);
        DeleteInvoiceImage->setIcon(icon3);
        DeleteInvoiceImage->setIconSize(QSize(30, 30));
        DeleteInvoiceImage->setAutoRaise(true);

        verticalLayout_16->addWidget(DeleteInvoiceImage);

        verticalSpacer_6 = new QSpacerItem(18, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_16->addItem(verticalSpacer_6);


        horizontalLayout_6->addWidget(frame_3);


        verticalLayout_2->addWidget(groupBox_4);

        groupBox_5 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setMinimumSize(QSize(0, 300));
        QPalette palette18;
        palette18.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette18.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette18.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        groupBox_5->setPalette(palette18);
        groupBox_5->setFont(font1);
        horizontalLayout_7 = new QHBoxLayout(groupBox_5);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        BuyScreenshot = new QLabel(groupBox_5);
        BuyScreenshot->setObjectName(QStringLiteral("BuyScreenshot"));
        BuyScreenshot->setMinimumSize(QSize(300, 300));
        BuyScreenshot->setPixmap(QPixmap(QString::fromUtf8(":/Expense/Resources/Expense/nopicture.png")));
        BuyScreenshot->setScaledContents(true);

        horizontalLayout_7->addWidget(BuyScreenshot);

        frame_4 = new QFrame(groupBox_5);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setMinimumSize(QSize(38, 150));
        frame_4->setMaximumSize(QSize(38, 150));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        verticalLayout_17 = new QVBoxLayout(frame_4);
        verticalLayout_17->setSpacing(0);
        verticalLayout_17->setContentsMargins(11, 11, 11, 11);
        verticalLayout_17->setObjectName(QStringLiteral("verticalLayout_17"));
        verticalLayout_17->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_7 = new QSpacerItem(18, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_17->addItem(verticalSpacer_7);

        AddBuyScreenshot = new QToolButton(frame_4);
        AddBuyScreenshot->setObjectName(QStringLiteral("AddBuyScreenshot"));
        AddBuyScreenshot->setMinimumSize(QSize(36, 36));
        AddBuyScreenshot->setMaximumSize(QSize(36, 36));
        AddBuyScreenshot->setIcon(icon1);
        AddBuyScreenshot->setIconSize(QSize(30, 30));
        AddBuyScreenshot->setAutoRaise(true);

        verticalLayout_17->addWidget(AddBuyScreenshot);

        PreviewBuyScreenshot = new QToolButton(frame_4);
        PreviewBuyScreenshot->setObjectName(QStringLiteral("PreviewBuyScreenshot"));
        PreviewBuyScreenshot->setMinimumSize(QSize(36, 36));
        PreviewBuyScreenshot->setMaximumSize(QSize(36, 36));
        PreviewBuyScreenshot->setIcon(icon2);
        PreviewBuyScreenshot->setIconSize(QSize(30, 30));
        PreviewBuyScreenshot->setAutoRaise(true);

        verticalLayout_17->addWidget(PreviewBuyScreenshot);

        DeleteBuyScreenshot = new QToolButton(frame_4);
        DeleteBuyScreenshot->setObjectName(QStringLiteral("DeleteBuyScreenshot"));
        DeleteBuyScreenshot->setMinimumSize(QSize(36, 36));
        DeleteBuyScreenshot->setMaximumSize(QSize(36, 36));
        DeleteBuyScreenshot->setIcon(icon3);
        DeleteBuyScreenshot->setIconSize(QSize(30, 30));
        DeleteBuyScreenshot->setAutoRaise(true);

        verticalLayout_17->addWidget(DeleteBuyScreenshot);

        verticalSpacer_8 = new QSpacerItem(18, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_17->addItem(verticalSpacer_8);


        horizontalLayout_7->addWidget(frame_4);


        verticalLayout_2->addWidget(groupBox_5);

        groupBox_6 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setMinimumSize(QSize(0, 300));
        QPalette palette19;
        palette19.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette19.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette19.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        groupBox_6->setPalette(palette19);
        groupBox_6->setFont(font1);
        horizontalLayout_8 = new QHBoxLayout(groupBox_6);
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        VerificationImage = new QLabel(groupBox_6);
        VerificationImage->setObjectName(QStringLiteral("VerificationImage"));
        VerificationImage->setMinimumSize(QSize(300, 300));
        VerificationImage->setPixmap(QPixmap(QString::fromUtf8(":/Expense/Resources/Expense/nopicture.png")));
        VerificationImage->setScaledContents(true);

        horizontalLayout_8->addWidget(VerificationImage);

        frame_5 = new QFrame(groupBox_6);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setMinimumSize(QSize(38, 150));
        frame_5->setMaximumSize(QSize(38, 150));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        verticalLayout_18 = new QVBoxLayout(frame_5);
        verticalLayout_18->setSpacing(0);
        verticalLayout_18->setContentsMargins(11, 11, 11, 11);
        verticalLayout_18->setObjectName(QStringLiteral("verticalLayout_18"));
        verticalLayout_18->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_9 = new QSpacerItem(18, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_18->addItem(verticalSpacer_9);

        AddVerificationImage = new QToolButton(frame_5);
        AddVerificationImage->setObjectName(QStringLiteral("AddVerificationImage"));
        AddVerificationImage->setMinimumSize(QSize(36, 36));
        AddVerificationImage->setMaximumSize(QSize(36, 36));
        AddVerificationImage->setIcon(icon1);
        AddVerificationImage->setIconSize(QSize(30, 30));
        AddVerificationImage->setAutoRaise(true);

        verticalLayout_18->addWidget(AddVerificationImage);

        PreviewVerificationImage = new QToolButton(frame_5);
        PreviewVerificationImage->setObjectName(QStringLiteral("PreviewVerificationImage"));
        PreviewVerificationImage->setMinimumSize(QSize(36, 36));
        PreviewVerificationImage->setMaximumSize(QSize(36, 36));
        PreviewVerificationImage->setIcon(icon2);
        PreviewVerificationImage->setIconSize(QSize(30, 30));
        PreviewVerificationImage->setAutoRaise(true);

        verticalLayout_18->addWidget(PreviewVerificationImage);

        DeleteVerificationImage = new QToolButton(frame_5);
        DeleteVerificationImage->setObjectName(QStringLiteral("DeleteVerificationImage"));
        DeleteVerificationImage->setMinimumSize(QSize(36, 36));
        DeleteVerificationImage->setMaximumSize(QSize(36, 36));
        DeleteVerificationImage->setIcon(icon3);
        DeleteVerificationImage->setIconSize(QSize(30, 30));
        DeleteVerificationImage->setAutoRaise(true);

        verticalLayout_18->addWidget(DeleteVerificationImage);

        verticalSpacer_10 = new QSpacerItem(18, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_18->addItem(verticalSpacer_10);


        horizontalLayout_8->addWidget(frame_5);


        verticalLayout_2->addWidget(groupBox_6);

        groupBox_2 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(0, 180));
        groupBox_2->setMaximumSize(QSize(16777215, 180));
        QPalette palette20;
        palette20.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette20.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette20.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        groupBox_2->setPalette(palette20);
        groupBox_2->setFont(font1);
        verticalLayout_8 = new QVBoxLayout(groupBox_2);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        Description = new QTextEdit(groupBox_2);
        Description->setObjectName(QStringLiteral("Description"));
        Description->setFrameShape(QFrame::Panel);

        verticalLayout_8->addWidget(Description);


        verticalLayout_2->addWidget(groupBox_2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_2);

        Cancel = new QPushButton(scrollAreaWidgetContents);
        Cancel->setObjectName(QStringLiteral("Cancel"));
        QPalette palette21;
        QBrush brush8(QColor(223, 223, 223, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette21.setBrush(QPalette::Active, QPalette::Button, brush8);
        palette21.setBrush(QPalette::Inactive, QPalette::Button, brush8);
        palette21.setBrush(QPalette::Disabled, QPalette::Button, brush8);
        Cancel->setPalette(palette21);
        Cancel->setFont(font1);
        Cancel->setAutoFillBackground(true);
        Cancel->setFlat(true);

        horizontalLayout_9->addWidget(Cancel);

        OK = new QPushButton(scrollAreaWidgetContents);
        OK->setObjectName(QStringLiteral("OK"));
        QPalette palette22;
        palette22.setBrush(QPalette::Active, QPalette::Button, brush8);
        palette22.setBrush(QPalette::Inactive, QPalette::Button, brush8);
        palette22.setBrush(QPalette::Disabled, QPalette::Button, brush8);
        OK->setPalette(palette22);
        OK->setFont(font1);
        OK->setAutoFillBackground(true);
        OK->setFlat(true);

        horizontalLayout_9->addWidget(OK);


        verticalLayout_2->addLayout(horizontalLayout_9);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_10->addWidget(scrollArea);

        horizontalSpacer_4 = new QSpacerItem(293, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_4);

        frame = new QFrame(InvoiceInfo);
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
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Expense/Resources/Expense/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        AppClose->setIcon(icon4);
        AppClose->setIconSize(QSize(35, 35));
        AppClose->setAutoRaise(true);

        verticalLayout_7->addWidget(AppClose);

        verticalSpacer = new QSpacerItem(20, 533, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer);


        horizontalLayout_10->addWidget(frame);


        retranslateUi(InvoiceInfo);

        QMetaObject::connectSlotsByName(InvoiceInfo);
    } // setupUi

    void retranslateUi(QDialog *InvoiceInfo)
    {
        InvoiceInfo->setWindowTitle(QApplication::translate("InvoiceInfo", "InvoiceInfo", Q_NULLPTR));
        label->setText(QApplication::translate("InvoiceInfo", "\346\235\220\346\226\231\350\264\255\347\275\256\345\217\221\347\245\250\344\277\241\346\201\257\345\275\225\345\205\245", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("InvoiceInfo", "\345\217\221\347\245\250\344\277\241\346\201\257", Q_NULLPTR));
        label_2->setText(QApplication::translate("InvoiceInfo", "\346\235\220\346\226\231\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("InvoiceInfo", "\345\236\213\345\217\267\350\247\204\346\240\274\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("InvoiceInfo", "\345\205\245\345\272\223\346\225\260\351\207\217\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("InvoiceInfo", "\345\215\225\344\275\215\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("InvoiceInfo", "\346\235\220\346\226\231\345\215\225\344\273\267\357\274\232", Q_NULLPTR));
        Univalent->setPlaceholderText(QApplication::translate("InvoiceInfo", "\302\245", Q_NULLPTR));
        label_8->setText(QApplication::translate("InvoiceInfo", "\357\274\210\345\205\203\357\274\211", Q_NULLPTR));
        Calculate->setText(QApplication::translate("InvoiceInfo", "\350\256\241\347\256\227", Q_NULLPTR));
        label_15->setText(QApplication::translate("InvoiceInfo", "\346\200\273\351\207\221\351\242\235\357\274\232  ", Q_NULLPTR));
        AggregateAmount->setPlaceholderText(QApplication::translate("InvoiceInfo", "\302\245", Q_NULLPTR));
        label_16->setText(QApplication::translate("InvoiceInfo", "\357\274\210\345\205\203\357\274\211", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("InvoiceInfo", "\346\235\220\346\226\231\350\264\271\345\217\221\347\245\250\345\233\276\345\203\217\345\255\230\346\241\243", Q_NULLPTR));
        InvoiceImage->setText(QString());
        AddInvoiceImage->setText(QApplication::translate("InvoiceInfo", "...", Q_NULLPTR));
        PreviewInvoiceImage->setText(QApplication::translate("InvoiceInfo", "...", Q_NULLPTR));
        DeleteInvoiceImage->setText(QApplication::translate("InvoiceInfo", "...", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("InvoiceInfo", "\351\235\236\346\235\255\345\267\236\346\234\254\345\234\260\345\217\221\347\245\250\351\231\204\350\264\255\344\271\260\346\210\252\345\233\276\345\255\230\346\241\243", Q_NULLPTR));
        BuyScreenshot->setText(QString());
        AddBuyScreenshot->setText(QApplication::translate("InvoiceInfo", "...", Q_NULLPTR));
        PreviewBuyScreenshot->setText(QApplication::translate("InvoiceInfo", "...", Q_NULLPTR));
        DeleteBuyScreenshot->setText(QApplication::translate("InvoiceInfo", "...", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("InvoiceInfo", "\346\200\273\351\207\221\351\242\235\350\266\205\350\277\2071000\345\205\203\345\217\221\347\245\250\346\237\245\351\252\214\345\255\230\346\241\243", Q_NULLPTR));
        VerificationImage->setText(QString());
        AddVerificationImage->setText(QApplication::translate("InvoiceInfo", "...", Q_NULLPTR));
        PreviewVerificationImage->setText(QApplication::translate("InvoiceInfo", "...", Q_NULLPTR));
        DeleteVerificationImage->setText(QApplication::translate("InvoiceInfo", "...", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("InvoiceInfo", "\345\244\207\346\263\250", Q_NULLPTR));
        Description->setPlaceholderText(QApplication::translate("InvoiceInfo", "\346\255\244\345\244\204\345\241\253\345\205\245\345\244\207\346\263\250\344\277\241\346\201\257", Q_NULLPTR));
        Cancel->setText(QApplication::translate("InvoiceInfo", "\345\217\226\346\266\210", Q_NULLPTR));
        OK->setText(QApplication::translate("InvoiceInfo", "\347\241\256\345\256\232", Q_NULLPTR));
        AppClose->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class InvoiceInfo: public Ui_InvoiceInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVOICEINFO_H
