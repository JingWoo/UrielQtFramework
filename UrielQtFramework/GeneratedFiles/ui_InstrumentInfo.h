/********************************************************************************
** Form generated from reading UI file 'InstrumentInfo.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSTRUMENTINFO_H
#define UI_INSTRUMENTINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InstrumentInfo
{
public:
    QHBoxLayout *horizontalLayout_15;
    QSpacerItem *horizontalSpacer;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QVBoxLayout *verticalLayout;
    QLineEdit *InstrumentName;
    QFrame *line;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *InstrumentModel;
    QFrame *line_2;
    QSpacerItem *horizontalSpacer_16;
    QHBoxLayout *horizontalLayout_7;
    QLabel *ImportanceDegreeLabel;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *InstrumentVender;
    QFrame *line_3;
    QSpacerItem *horizontalSpacer_17;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QDoubleSpinBox *InstrumentPrice;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_6;
    QDateEdit *InstrumentPurchaseTime;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_7;
    QSpinBox *InstrumentGuaranteePeriod;
    QSpacerItem *horizontalSpacer_11;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_12;
    QComboBox *ProjectTeamCombox;
    QVBoxLayout *verticalLayout_10;
    QFrame *line_8;
    QSpacerItem *horizontalSpacer_19;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_11;
    QVBoxLayout *verticalLayout_8;
    QLineEdit *InstrumentPresentPersonInCharge;
    QFrame *line_7;
    QSpacerItem *horizontalSpacer_15;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_8;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QRadioButton *LendStatus;
    QRadioButton *ReturnStatus;
    QSpacerItem *horizontalSpacer_12;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_9;
    QVBoxLayout *verticalLayout_6;
    QLineEdit *InstrumentAddress;
    QFrame *line_5;
    QSpacerItem *horizontalSpacer_18;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_10;
    QLabel *InstrumentSDKAddress;
    QToolButton *InstrumentSDKBrowerTB;
    QSpacerItem *horizontalSpacer_14;
    QToolButton *SDKDownLoad;
    QSpacerItem *horizontalSpacer_13;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_7;
    QPlainTextEdit *InstrumentDescription;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_14;
    QLabel *InstrumentImage;
    QVBoxLayout *verticalLayout_9;
    QSpacerItem *verticalSpacer_2;
    QToolButton *ChangeImageTB;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_7;
    QToolButton *ConfirmOperation;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout_3;
    QToolButton *AppClose;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *InstrumentInfo)
    {
        if (InstrumentInfo->objectName().isEmpty())
            InstrumentInfo->setObjectName(QStringLiteral("InstrumentInfo"));
        InstrumentInfo->resize(1078, 916);
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
        InstrumentInfo->setPalette(palette);
        InstrumentInfo->setAutoFillBackground(true);
        horizontalLayout_15 = new QHBoxLayout(InstrumentInfo);
        horizontalLayout_15->setSpacing(0);
        horizontalLayout_15->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        horizontalLayout_15->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(89, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer);

        scrollArea = new QScrollArea(InstrumentInfo);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush);
        scrollArea->setPalette(palette1);
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1069, 1436));
        verticalLayout_5 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(scrollAreaWidgetContents);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(14);
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        InstrumentName = new QLineEdit(scrollAreaWidgetContents);
        InstrumentName->setObjectName(QStringLiteral("InstrumentName"));
        InstrumentName->setFont(font);
        InstrumentName->setFrame(false);

        verticalLayout->addWidget(InstrumentName);

        line = new QFrame(scrollAreaWidgetContents);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);


        horizontalLayout_3->addLayout(verticalLayout);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_5 = new QLabel(scrollAreaWidgetContents);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        horizontalLayout_4->addWidget(label_5);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        InstrumentModel = new QLineEdit(scrollAreaWidgetContents);
        InstrumentModel->setObjectName(QStringLiteral("InstrumentModel"));
        InstrumentModel->setFont(font);
        InstrumentModel->setFrame(false);

        verticalLayout_2->addWidget(InstrumentModel);

        line_2 = new QFrame(scrollAreaWidgetContents);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);


        horizontalLayout_4->addLayout(verticalLayout_2);

        horizontalSpacer_16 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_16);


        verticalLayout_5->addLayout(horizontalLayout_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        ImportanceDegreeLabel = new QLabel(scrollAreaWidgetContents);
        ImportanceDegreeLabel->setObjectName(QStringLiteral("ImportanceDegreeLabel"));
        ImportanceDegreeLabel->setFont(font);

        horizontalLayout_7->addWidget(ImportanceDegreeLabel);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        InstrumentVender = new QLineEdit(scrollAreaWidgetContents);
        InstrumentVender->setObjectName(QStringLiteral("InstrumentVender"));
        InstrumentVender->setFont(font);
        InstrumentVender->setFrame(false);

        verticalLayout_4->addWidget(InstrumentVender);

        line_3 = new QFrame(scrollAreaWidgetContents);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_3);


        horizontalLayout_7->addLayout(verticalLayout_4);

        horizontalSpacer_17 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_17);


        verticalLayout_5->addLayout(horizontalLayout_7);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_4 = new QLabel(scrollAreaWidgetContents);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        horizontalLayout_5->addWidget(label_4);

        InstrumentPrice = new QDoubleSpinBox(scrollAreaWidgetContents);
        InstrumentPrice->setObjectName(QStringLiteral("InstrumentPrice"));
        QFont font1;
        font1.setFamily(QStringLiteral("3ds"));
        font1.setPointSize(14);
        InstrumentPrice->setFont(font1);
        InstrumentPrice->setMaximum(1e+10);

        horizontalLayout_5->addWidget(InstrumentPrice);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);


        verticalLayout_5->addLayout(horizontalLayout_5);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_6 = new QLabel(scrollAreaWidgetContents);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        horizontalLayout_8->addWidget(label_6);

        InstrumentPurchaseTime = new QDateEdit(scrollAreaWidgetContents);
        InstrumentPurchaseTime->setObjectName(QStringLiteral("InstrumentPurchaseTime"));
        InstrumentPurchaseTime->setMinimumSize(QSize(164, 0));
        InstrumentPurchaseTime->setFont(font1);

        horizontalLayout_8->addWidget(InstrumentPurchaseTime);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_10);


        verticalLayout_5->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_7 = new QLabel(scrollAreaWidgetContents);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        horizontalLayout_9->addWidget(label_7);

        InstrumentGuaranteePeriod = new QSpinBox(scrollAreaWidgetContents);
        InstrumentGuaranteePeriod->setObjectName(QStringLiteral("InstrumentGuaranteePeriod"));
        InstrumentGuaranteePeriod->setFont(font1);
        InstrumentGuaranteePeriod->setMaximum(1000000000);

        horizontalLayout_9->addWidget(InstrumentGuaranteePeriod);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_11);


        verticalLayout_5->addLayout(horizontalLayout_9);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        label_12 = new QLabel(scrollAreaWidgetContents);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font);

        horizontalLayout_16->addWidget(label_12);

        ProjectTeamCombox = new QComboBox(scrollAreaWidgetContents);
        ProjectTeamCombox->setObjectName(QStringLiteral("ProjectTeamCombox"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ProjectTeamCombox->sizePolicy().hasHeightForWidth());
        ProjectTeamCombox->setSizePolicy(sizePolicy);
        ProjectTeamCombox->setFont(font);
        ProjectTeamCombox->setEditable(true);

        horizontalLayout_16->addWidget(ProjectTeamCombox);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(0);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        line_8 = new QFrame(scrollAreaWidgetContents);
        line_8->setObjectName(QStringLiteral("line_8"));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        verticalLayout_10->addWidget(line_8);


        horizontalLayout_16->addLayout(verticalLayout_10);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_19);


        verticalLayout_5->addLayout(horizontalLayout_16);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_11 = new QLabel(scrollAreaWidgetContents);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font);

        horizontalLayout_13->addWidget(label_11);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        InstrumentPresentPersonInCharge = new QLineEdit(scrollAreaWidgetContents);
        InstrumentPresentPersonInCharge->setObjectName(QStringLiteral("InstrumentPresentPersonInCharge"));
        InstrumentPresentPersonInCharge->setFont(font);
        InstrumentPresentPersonInCharge->setFrame(false);

        verticalLayout_8->addWidget(InstrumentPresentPersonInCharge);

        line_7 = new QFrame(scrollAreaWidgetContents);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        verticalLayout_8->addWidget(line_7);


        horizontalLayout_13->addLayout(verticalLayout_8);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_15);


        verticalLayout_5->addLayout(horizontalLayout_13);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_8 = new QLabel(scrollAreaWidgetContents);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);

        horizontalLayout_10->addWidget(label_8);

        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, 0);
        LendStatus = new QRadioButton(groupBox);
        LendStatus->setObjectName(QStringLiteral("LendStatus"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(12);
        LendStatus->setFont(font2);

        horizontalLayout->addWidget(LendStatus);

        ReturnStatus = new QRadioButton(groupBox);
        ReturnStatus->setObjectName(QStringLiteral("ReturnStatus"));
        ReturnStatus->setFont(font2);
        ReturnStatus->setChecked(true);

        horizontalLayout->addWidget(ReturnStatus);


        horizontalLayout_10->addWidget(groupBox);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_12);


        verticalLayout_5->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_9 = new QLabel(scrollAreaWidgetContents);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font);

        horizontalLayout_11->addWidget(label_9);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        InstrumentAddress = new QLineEdit(scrollAreaWidgetContents);
        InstrumentAddress->setObjectName(QStringLiteral("InstrumentAddress"));
        InstrumentAddress->setFont(font);
        InstrumentAddress->setFrame(false);

        verticalLayout_6->addWidget(InstrumentAddress);

        line_5 = new QFrame(scrollAreaWidgetContents);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout_6->addWidget(line_5);


        horizontalLayout_11->addLayout(verticalLayout_6);

        horizontalSpacer_18 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_18);


        verticalLayout_5->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_10 = new QLabel(scrollAreaWidgetContents);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font);

        horizontalLayout_12->addWidget(label_10);

        InstrumentSDKAddress = new QLabel(scrollAreaWidgetContents);
        InstrumentSDKAddress->setObjectName(QStringLiteral("InstrumentSDKAddress"));
        InstrumentSDKAddress->setMaximumSize(QSize(800, 16777215));
        QPalette palette2;
        QBrush brush2(QColor(170, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        QBrush brush3(QColor(120, 120, 120, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        InstrumentSDKAddress->setPalette(palette2);
        InstrumentSDKAddress->setFont(font);

        horizontalLayout_12->addWidget(InstrumentSDKAddress);

        InstrumentSDKBrowerTB = new QToolButton(scrollAreaWidgetContents);
        InstrumentSDKBrowerTB->setObjectName(QStringLiteral("InstrumentSDKBrowerTB"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Mainwindow/Resources/UrielQtFramework/edits.png"), QSize(), QIcon::Normal, QIcon::Off);
        InstrumentSDKBrowerTB->setIcon(icon);
        InstrumentSDKBrowerTB->setAutoRaise(true);

        horizontalLayout_12->addWidget(InstrumentSDKBrowerTB);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_14);

        SDKDownLoad = new QToolButton(scrollAreaWidgetContents);
        SDKDownLoad->setObjectName(QStringLiteral("SDKDownLoad"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Mainwindow/Resources/UrielQtFramework/download01.png"), QSize(), QIcon::Normal, QIcon::Off);
        SDKDownLoad->setIcon(icon1);
        SDKDownLoad->setAutoRaise(true);

        horizontalLayout_12->addWidget(SDKDownLoad);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_13);


        verticalLayout_5->addLayout(horizontalLayout_12);

        groupBox_3 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font3.setPointSize(16);
        groupBox_3->setFont(font3);
        verticalLayout_7 = new QVBoxLayout(groupBox_3);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        InstrumentDescription = new QPlainTextEdit(groupBox_3);
        InstrumentDescription->setObjectName(QStringLiteral("InstrumentDescription"));
        InstrumentDescription->setMinimumSize(QSize(0, 150));
        InstrumentDescription->setFont(font);
        InstrumentDescription->setFrameShape(QFrame::StyledPanel);

        verticalLayout_7->addWidget(InstrumentDescription);


        verticalLayout_5->addWidget(groupBox_3);

        groupBox_2 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(0, 800));
        groupBox_2->setFont(font);
        horizontalLayout_14 = new QHBoxLayout(groupBox_2);
        horizontalLayout_14->setSpacing(0);
        horizontalLayout_14->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalLayout_14->setContentsMargins(0, 0, 0, 0);
        InstrumentImage = new QLabel(groupBox_2);
        InstrumentImage->setObjectName(QStringLiteral("InstrumentImage"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(InstrumentImage->sizePolicy().hasHeightForWidth());
        InstrumentImage->setSizePolicy(sizePolicy1);
        InstrumentImage->setMinimumSize(QSize(1000, 800));

        horizontalLayout_14->addWidget(InstrumentImage);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_2);

        ChangeImageTB = new QToolButton(groupBox_2);
        ChangeImageTB->setObjectName(QStringLiteral("ChangeImageTB"));
        ChangeImageTB->setMaximumSize(QSize(47, 47));
        ChangeImageTB->setAutoFillBackground(true);
        ChangeImageTB->setIcon(icon);
        ChangeImageTB->setIconSize(QSize(40, 40));
        ChangeImageTB->setAutoRaise(true);

        verticalLayout_9->addWidget(ChangeImageTB);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_3);


        horizontalLayout_14->addLayout(verticalLayout_9);


        verticalLayout_5->addWidget(groupBox_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_7 = new QSpacerItem(37, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_7);

        ConfirmOperation = new QToolButton(scrollAreaWidgetContents);
        ConfirmOperation->setObjectName(QStringLiteral("ConfirmOperation"));
        QPalette palette3;
        QBrush brush4(QColor(170, 255, 255, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        ConfirmOperation->setPalette(palette3);
        ConfirmOperation->setFont(font3);
        ConfirmOperation->setAutoFillBackground(true);
        ConfirmOperation->setAutoRaise(true);

        horizontalLayout_6->addWidget(ConfirmOperation);

        horizontalSpacer_8 = new QSpacerItem(37, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_8);


        verticalLayout_5->addLayout(horizontalLayout_6);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_4);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_15->addWidget(scrollArea);

        horizontalSpacer_2 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_2);

        frame = new QFrame(InstrumentInfo);
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
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Mainwindow/Resources/UrielQtFramework/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        AppClose->setIcon(icon2);
        AppClose->setIconSize(QSize(30, 30));
        AppClose->setAutoRaise(true);

        verticalLayout_3->addWidget(AppClose);

        verticalSpacer = new QSpacerItem(20, 572, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout_15->addWidget(frame);


        retranslateUi(InstrumentInfo);

        QMetaObject::connectSlotsByName(InstrumentInfo);
    } // setupUi

    void retranslateUi(QDialog *InstrumentInfo)
    {
        InstrumentInfo->setWindowTitle(QApplication::translate("InstrumentInfo", "InstrumentInfo", Q_NULLPTR));
        label_3->setText(QApplication::translate("InstrumentInfo", "\350\256\276\345\244\207\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        InstrumentName->setPlaceholderText(QApplication::translate("InstrumentInfo", "\345\241\253\345\206\231\350\256\276\345\244\207\345\220\215\347\247\260", Q_NULLPTR));
        label_5->setText(QApplication::translate("InstrumentInfo", "\350\256\276\345\244\207\345\236\213\345\217\267\357\274\232", Q_NULLPTR));
        InstrumentModel->setPlaceholderText(QApplication::translate("InstrumentInfo", "\345\241\253\345\206\231\350\256\276\345\244\207\345\236\213\345\217\267", Q_NULLPTR));
        ImportanceDegreeLabel->setText(QApplication::translate("InstrumentInfo", "\347\224\237\344\272\247\345\216\202\345\256\266\357\274\232", Q_NULLPTR));
        InstrumentVender->setPlaceholderText(QApplication::translate("InstrumentInfo", "\345\241\253\345\206\231\347\224\237\344\272\247\345\216\202\345\256\266", Q_NULLPTR));
        label_4->setText(QApplication::translate("InstrumentInfo", "\350\256\276\345\244\207\344\273\267\346\240\274\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("InstrumentInfo", "\350\264\255\344\271\260\346\227\245\346\234\237\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("InstrumentInfo", "\350\264\250\344\277\235\346\234\237/\346\234\210\357\274\232", Q_NULLPTR));
        label_12->setText(QApplication::translate("InstrumentInfo", "\346\211\200\345\261\236\351\241\271\347\233\256\357\274\232", Q_NULLPTR));
        label_11->setText(QApplication::translate("InstrumentInfo", "\347\216\260\350\264\237\350\264\243\344\272\272\357\274\232", Q_NULLPTR));
        InstrumentPresentPersonInCharge->setPlaceholderText(QApplication::translate("InstrumentInfo", "\345\241\253\345\206\231\347\216\260\350\264\237\350\264\243\344\272\272", Q_NULLPTR));
        label_8->setText(QApplication::translate("InstrumentInfo", "\345\275\223\345\211\215\347\212\266\346\200\201\357\274\232", Q_NULLPTR));
        groupBox->setTitle(QString());
        LendStatus->setText(QApplication::translate("InstrumentInfo", "\345\200\237\345\207\272", Q_NULLPTR));
        ReturnStatus->setText(QApplication::translate("InstrumentInfo", "\345\255\230\346\224\276", Q_NULLPTR));
        label_9->setText(QApplication::translate("InstrumentInfo", "\346\211\200\345\234\250\344\275\215\347\275\256\357\274\232", Q_NULLPTR));
        InstrumentAddress->setPlaceholderText(QApplication::translate("InstrumentInfo", "\345\241\253\345\206\231\346\211\200\345\234\250\344\275\215\347\275\256", Q_NULLPTR));
        label_10->setText(QApplication::translate("InstrumentInfo", "\350\265\204\346\226\231\344\275\215\347\275\256\357\274\232", Q_NULLPTR));
        InstrumentSDKAddress->setText(QApplication::translate("InstrumentInfo", "\346\227\240", Q_NULLPTR));
        InstrumentSDKBrowerTB->setText(QApplication::translate("InstrumentInfo", "...", Q_NULLPTR));
        SDKDownLoad->setText(QApplication::translate("InstrumentInfo", "...", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("InstrumentInfo", "\350\256\276\345\244\207\346\217\217\350\277\260\357\274\232", Q_NULLPTR));
        InstrumentDescription->setPlaceholderText(QApplication::translate("InstrumentInfo", "\345\241\253\345\206\231\350\256\276\345\244\207\346\217\217\350\277\260", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("InstrumentInfo", "\350\256\276\345\244\207\345\233\276\347\211\207", Q_NULLPTR));
        InstrumentImage->setText(QString());
        ChangeImageTB->setText(QApplication::translate("InstrumentInfo", "...", Q_NULLPTR));
        ConfirmOperation->setText(QApplication::translate("InstrumentInfo", "\346\267\273\345\212\240\350\256\276\345\244\207", Q_NULLPTR));
        AppClose->setText(QApplication::translate("InstrumentInfo", "...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class InstrumentInfo: public Ui_InstrumentInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSTRUMENTINFO_H
