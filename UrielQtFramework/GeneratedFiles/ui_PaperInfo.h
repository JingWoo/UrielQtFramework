/********************************************************************************
** Form generated from reading UI file 'PaperInfo.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAPERINFO_H
#define UI_PAPERINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
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
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PaperInfo
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_7;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *OriginalTitle;
    QFrame *line_3;
    QSpacerItem *horizontalSpacer_11;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QVBoxLayout *verticalLayout;
    QLineEdit *TranslationTitle;
    QFrame *line;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *PeriodicalName;
    QFrame *line_2;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_8;
    QComboBox *PeriodicalLevel;
    QSpacerItem *horizontalSpacer_13;
    QLabel *label_9;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *PeriodicalLanguage_Chinese;
    QRadioButton *PeriodicalLanguage_English;
    QSpacerItem *horizontalSpacer_12;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_10;
    QDateEdit *EmploymentTime;
    QLabel *label_11;
    QVBoxLayout *verticalLayout_6;
    QLineEdit *VolumeNumber;
    QFrame *line_4;
    QLabel *label_12;
    QVBoxLayout *verticalLayout_7;
    QLineEdit *StartAndEndPageNumber;
    QFrame *line_5;
    QLabel *label_13;
    QVBoxLayout *verticalLayout_8;
    QLineEdit *InfluenceFactor;
    QFrame *line_6;
    QSpacerItem *horizontalSpacer_14;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_14;
    QComboBox *IsThesisContent;
    QLabel *label_16;
    QVBoxLayout *verticalLayout_10;
    QLineEdit *CommunicationUnit;
    QFrame *line_8;
    QSpacerItem *horizontalSpacer_15;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_15;
    QVBoxLayout *verticalLayout_9;
    QLineEdit *Author;
    QFrame *line_7;
    QSpacerItem *horizontalSpacer_16;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_17;
    QVBoxLayout *verticalLayout_11;
    QLineEdit *IndexedAddress;
    QFrame *line_9;
    QSpacerItem *horizontalSpacer_17;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLabel *ServerFileAddress;
    QToolButton *PaperFileBrower;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_6;
    QPlainTextEdit *Abstract;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_7;
    QToolButton *PaperConfirmBTn;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout_3;
    QToolButton *AppClose;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *PaperInfo)
    {
        if (PaperInfo->objectName().isEmpty())
            PaperInfo->setObjectName(QStringLiteral("PaperInfo"));
        PaperInfo->resize(1105, 613);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(240, 240, 240, 50));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        PaperInfo->setPalette(palette);
        horizontalLayout = new QHBoxLayout(PaperInfo);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(89, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        scrollArea = new QScrollArea(PaperInfo);
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
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 927, 613));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_7 = new QLabel(scrollAreaWidgetContents);
        label_7->setObjectName(QStringLiteral("label_7"));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(14);
        label_7->setFont(font);

        horizontalLayout_9->addWidget(label_7);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        OriginalTitle = new QLineEdit(scrollAreaWidgetContents);
        OriginalTitle->setObjectName(QStringLiteral("OriginalTitle"));
        OriginalTitle->setFont(font);
        OriginalTitle->setFrame(false);

        verticalLayout_5->addWidget(OriginalTitle);

        line_3 = new QFrame(scrollAreaWidgetContents);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_3);


        horizontalLayout_9->addLayout(verticalLayout_5);

        horizontalSpacer_11 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_11);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(scrollAreaWidgetContents);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        TranslationTitle = new QLineEdit(scrollAreaWidgetContents);
        TranslationTitle->setObjectName(QStringLiteral("TranslationTitle"));
        TranslationTitle->setFont(font);
        TranslationTitle->setFrame(false);

        verticalLayout->addWidget(TranslationTitle);

        line = new QFrame(scrollAreaWidgetContents);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);


        horizontalLayout_3->addLayout(verticalLayout);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_6 = new QLabel(scrollAreaWidgetContents);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        horizontalLayout_8->addWidget(label_6);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        PeriodicalName = new QLineEdit(scrollAreaWidgetContents);
        PeriodicalName->setObjectName(QStringLiteral("PeriodicalName"));
        PeriodicalName->setFont(font);
        PeriodicalName->setFrame(false);

        verticalLayout_4->addWidget(PeriodicalName);

        line_2 = new QFrame(scrollAreaWidgetContents);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_2);


        horizontalLayout_8->addLayout(verticalLayout_4);

        horizontalSpacer_10 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_10);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_8 = new QLabel(scrollAreaWidgetContents);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);

        horizontalLayout_10->addWidget(label_8);

        PeriodicalLevel = new QComboBox(scrollAreaWidgetContents);
        PeriodicalLevel->setObjectName(QStringLiteral("PeriodicalLevel"));
        PeriodicalLevel->setMinimumSize(QSize(250, 0));
        PeriodicalLevel->setFont(font);
        PeriodicalLevel->setAutoFillBackground(true);
        PeriodicalLevel->setEditable(true);
        PeriodicalLevel->setFrame(true);

        horizontalLayout_10->addWidget(PeriodicalLevel);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_13);

        label_9 = new QLabel(scrollAreaWidgetContents);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font);

        horizontalLayout_10->addWidget(label_9);

        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(10);
        groupBox->setFont(font1);
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        PeriodicalLanguage_Chinese = new QRadioButton(groupBox);
        PeriodicalLanguage_Chinese->setObjectName(QStringLiteral("PeriodicalLanguage_Chinese"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(12);
        PeriodicalLanguage_Chinese->setFont(font2);
        PeriodicalLanguage_Chinese->setChecked(false);

        horizontalLayout_2->addWidget(PeriodicalLanguage_Chinese);

        PeriodicalLanguage_English = new QRadioButton(groupBox);
        PeriodicalLanguage_English->setObjectName(QStringLiteral("PeriodicalLanguage_English"));
        QFont font3;
        font3.setPointSize(12);
        PeriodicalLanguage_English->setFont(font3);
        PeriodicalLanguage_English->setChecked(true);

        horizontalLayout_2->addWidget(PeriodicalLanguage_English);


        horizontalLayout_10->addWidget(groupBox);

        horizontalSpacer_12 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_12);


        verticalLayout_2->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_10 = new QLabel(scrollAreaWidgetContents);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font);

        horizontalLayout_11->addWidget(label_10);

        EmploymentTime = new QDateEdit(scrollAreaWidgetContents);
        EmploymentTime->setObjectName(QStringLiteral("EmploymentTime"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(EmploymentTime->sizePolicy().hasHeightForWidth());
        EmploymentTime->setSizePolicy(sizePolicy);
        EmploymentTime->setMinimumSize(QSize(150, 0));
        EmploymentTime->setFont(font);
        EmploymentTime->setCalendarPopup(false);

        horizontalLayout_11->addWidget(EmploymentTime);

        label_11 = new QLabel(scrollAreaWidgetContents);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font);

        horizontalLayout_11->addWidget(label_11);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        VolumeNumber = new QLineEdit(scrollAreaWidgetContents);
        VolumeNumber->setObjectName(QStringLiteral("VolumeNumber"));
        VolumeNumber->setFont(font);
        VolumeNumber->setFrame(false);

        verticalLayout_6->addWidget(VolumeNumber);

        line_4 = new QFrame(scrollAreaWidgetContents);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_6->addWidget(line_4);


        horizontalLayout_11->addLayout(verticalLayout_6);

        label_12 = new QLabel(scrollAreaWidgetContents);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font);

        horizontalLayout_11->addWidget(label_12);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        StartAndEndPageNumber = new QLineEdit(scrollAreaWidgetContents);
        StartAndEndPageNumber->setObjectName(QStringLiteral("StartAndEndPageNumber"));
        StartAndEndPageNumber->setFont(font);
        StartAndEndPageNumber->setFrame(false);

        verticalLayout_7->addWidget(StartAndEndPageNumber);

        line_5 = new QFrame(scrollAreaWidgetContents);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line_5);


        horizontalLayout_11->addLayout(verticalLayout_7);

        label_13 = new QLabel(scrollAreaWidgetContents);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font);

        horizontalLayout_11->addWidget(label_13);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        InfluenceFactor = new QLineEdit(scrollAreaWidgetContents);
        InfluenceFactor->setObjectName(QStringLiteral("InfluenceFactor"));
        InfluenceFactor->setFont(font);
        InfluenceFactor->setFrame(false);

        verticalLayout_8->addWidget(InfluenceFactor);

        line_6 = new QFrame(scrollAreaWidgetContents);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        verticalLayout_8->addWidget(line_6);


        horizontalLayout_11->addLayout(verticalLayout_8);

        horizontalSpacer_14 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_14);


        verticalLayout_2->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_14 = new QLabel(scrollAreaWidgetContents);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font);

        horizontalLayout_12->addWidget(label_14);

        IsThesisContent = new QComboBox(scrollAreaWidgetContents);
        IsThesisContent->setObjectName(QStringLiteral("IsThesisContent"));
        IsThesisContent->setMinimumSize(QSize(100, 0));
        IsThesisContent->setFont(font);
        IsThesisContent->setAutoFillBackground(true);
        IsThesisContent->setEditable(true);
        IsThesisContent->setFrame(true);

        horizontalLayout_12->addWidget(IsThesisContent);

        label_16 = new QLabel(scrollAreaWidgetContents);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setFont(font);

        horizontalLayout_12->addWidget(label_16);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(0);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        CommunicationUnit = new QLineEdit(scrollAreaWidgetContents);
        CommunicationUnit->setObjectName(QStringLiteral("CommunicationUnit"));
        CommunicationUnit->setFont(font);
        CommunicationUnit->setFrame(false);

        verticalLayout_10->addWidget(CommunicationUnit);

        line_8 = new QFrame(scrollAreaWidgetContents);
        line_8->setObjectName(QStringLiteral("line_8"));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        verticalLayout_10->addWidget(line_8);


        horizontalLayout_12->addLayout(verticalLayout_10);

        horizontalSpacer_15 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_15);


        verticalLayout_2->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_15 = new QLabel(scrollAreaWidgetContents);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setFont(font);

        horizontalLayout_13->addWidget(label_15);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        Author = new QLineEdit(scrollAreaWidgetContents);
        Author->setObjectName(QStringLiteral("Author"));
        Author->setFont(font);
        Author->setFrame(false);

        verticalLayout_9->addWidget(Author);

        line_7 = new QFrame(scrollAreaWidgetContents);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        verticalLayout_9->addWidget(line_7);


        horizontalLayout_13->addLayout(verticalLayout_9);

        horizontalSpacer_16 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_16);


        verticalLayout_2->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_17 = new QLabel(scrollAreaWidgetContents);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setFont(font);

        horizontalLayout_14->addWidget(label_17);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(0);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        IndexedAddress = new QLineEdit(scrollAreaWidgetContents);
        IndexedAddress->setObjectName(QStringLiteral("IndexedAddress"));
        IndexedAddress->setFont(font);
        IndexedAddress->setFrame(false);

        verticalLayout_11->addWidget(IndexedAddress);

        line_9 = new QFrame(scrollAreaWidgetContents);
        line_9->setObjectName(QStringLiteral("line_9"));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);

        verticalLayout_11->addWidget(line_9);


        horizontalLayout_14->addLayout(verticalLayout_11);

        horizontalSpacer_17 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_17);


        verticalLayout_2->addLayout(horizontalLayout_14);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_5 = new QLabel(scrollAreaWidgetContents);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        horizontalLayout_4->addWidget(label_5);

        ServerFileAddress = new QLabel(scrollAreaWidgetContents);
        ServerFileAddress->setObjectName(QStringLiteral("ServerFileAddress"));
        ServerFileAddress->setMaximumSize(QSize(800, 16777215));
        QPalette palette2;
        QBrush brush2(QColor(170, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        QBrush brush3(QColor(120, 120, 120, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        ServerFileAddress->setPalette(palette2);
        ServerFileAddress->setFont(font);

        horizontalLayout_4->addWidget(ServerFileAddress);

        PaperFileBrower = new QToolButton(scrollAreaWidgetContents);
        PaperFileBrower->setObjectName(QStringLiteral("PaperFileBrower"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Mainwindow/Resources/UrielQtFramework/edits.png"), QSize(), QIcon::Normal, QIcon::Off);
        PaperFileBrower->setIcon(icon);
        PaperFileBrower->setAutoRaise(true);

        horizontalLayout_4->addWidget(PaperFileBrower);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_4 = new QLabel(scrollAreaWidgetContents);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        horizontalLayout_5->addWidget(label_4);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);


        verticalLayout_2->addLayout(horizontalLayout_5);

        Abstract = new QPlainTextEdit(scrollAreaWidgetContents);
        Abstract->setObjectName(QStringLiteral("Abstract"));
        Abstract->setFont(font);
        Abstract->setFrameShape(QFrame::StyledPanel);

        verticalLayout_2->addWidget(Abstract);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_7 = new QSpacerItem(37, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_7);

        PaperConfirmBTn = new QToolButton(scrollAreaWidgetContents);
        PaperConfirmBTn->setObjectName(QStringLiteral("PaperConfirmBTn"));
        QPalette palette3;
        QBrush brush4(QColor(170, 255, 255, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        PaperConfirmBTn->setPalette(palette3);
        QFont font4;
        font4.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font4.setPointSize(16);
        PaperConfirmBTn->setFont(font4);
        PaperConfirmBTn->setAutoFillBackground(true);
        PaperConfirmBTn->setAutoRaise(true);

        horizontalLayout_6->addWidget(PaperConfirmBTn);

        horizontalSpacer_8 = new QSpacerItem(37, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_8);


        verticalLayout_2->addLayout(horizontalLayout_6);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout->addWidget(scrollArea);

        horizontalSpacer_2 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        frame = new QFrame(PaperInfo);
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
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Mainwindow/Resources/UrielQtFramework/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        AppClose->setIcon(icon1);
        AppClose->setIconSize(QSize(30, 30));
        AppClose->setAutoRaise(true);

        verticalLayout_3->addWidget(AppClose);

        verticalSpacer = new QSpacerItem(20, 572, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout->addWidget(frame);


        retranslateUi(PaperInfo);

        QMetaObject::connectSlotsByName(PaperInfo);
    } // setupUi

    void retranslateUi(QDialog *PaperInfo)
    {
        PaperInfo->setWindowTitle(QApplication::translate("PaperInfo", "PaperInfo", Q_NULLPTR));
        label_7->setText(QApplication::translate("PaperInfo", "\345\216\237\345\210\212\351\242\230\347\233\256\357\274\232", Q_NULLPTR));
        OriginalTitle->setPlaceholderText(QApplication::translate("PaperInfo", "\345\241\253\345\206\231\345\216\237\345\210\212\351\242\230\347\233\256", Q_NULLPTR));
        label_3->setText(QApplication::translate("PaperInfo", "\347\277\273\350\257\221\351\242\230\347\233\256\357\274\232", Q_NULLPTR));
        TranslationTitle->setPlaceholderText(QApplication::translate("PaperInfo", "\345\241\253\345\206\231\347\277\273\350\257\221\351\242\230\347\233\256", Q_NULLPTR));
        label_6->setText(QApplication::translate("PaperInfo", "\346\234\237\345\210\212\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        PeriodicalName->setPlaceholderText(QApplication::translate("PaperInfo", "\345\241\253\345\206\231\346\234\237\345\210\212\345\220\215\347\247\260", Q_NULLPTR));
        label_8->setText(QApplication::translate("PaperInfo", "\346\234\237\345\210\212\347\272\247\345\210\253\357\274\232", Q_NULLPTR));
        label_9->setText(QApplication::translate("PaperInfo", "\346\234\237\345\210\212\350\257\255\350\250\200\357\274\232", Q_NULLPTR));
        groupBox->setTitle(QString());
        PeriodicalLanguage_Chinese->setText(QApplication::translate("PaperInfo", "\344\270\255\346\226\207", Q_NULLPTR));
        PeriodicalLanguage_English->setText(QApplication::translate("PaperInfo", "\350\213\261\346\226\207", Q_NULLPTR));
        label_10->setText(QApplication::translate("PaperInfo", "\345\275\225\347\224\250\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        EmploymentTime->setDisplayFormat(QApplication::translate("PaperInfo", "yyyy/MM/dd", Q_NULLPTR));
        label_11->setText(QApplication::translate("PaperInfo", "\345\215\267\346\234\237\345\217\267:", Q_NULLPTR));
        VolumeNumber->setPlaceholderText(QApplication::translate("PaperInfo", "\345\241\253\345\206\231\345\215\267\346\234\237\345\217\267", Q_NULLPTR));
        label_12->setText(QApplication::translate("PaperInfo", "\350\265\267\346\255\242\351\241\265\347\240\201:", Q_NULLPTR));
        StartAndEndPageNumber->setPlaceholderText(QApplication::translate("PaperInfo", "\345\241\253\345\206\231\350\265\267\346\255\242\351\241\265\347\240\201", Q_NULLPTR));
        label_13->setText(QApplication::translate("PaperInfo", "\345\275\261\345\223\215\345\233\240\345\255\220:", Q_NULLPTR));
        InfluenceFactor->setPlaceholderText(QApplication::translate("PaperInfo", "\345\241\253\345\206\231\345\275\261\345\223\215\345\233\240\345\255\220", Q_NULLPTR));
        label_14->setText(QApplication::translate("PaperInfo", "\346\230\257\345\220\246\345\255\246\344\275\215\350\256\272\346\226\207\345\206\205\345\256\271\357\274\232", Q_NULLPTR));
        label_16->setText(QApplication::translate("PaperInfo", "\351\200\232\350\256\257\345\215\225\344\275\215:", Q_NULLPTR));
        CommunicationUnit->setPlaceholderText(QApplication::translate("PaperInfo", "\345\241\253\345\206\231\351\200\232\350\256\257\345\215\225\344\275\215", Q_NULLPTR));
        label_15->setText(QApplication::translate("PaperInfo", "\344\275\234\350\200\205\344\277\241\346\201\257\357\274\232", Q_NULLPTR));
        Author->setPlaceholderText(QApplication::translate("PaperInfo", "\345\244\232\344\270\252\344\275\234\350\200\205\344\273\245;\345\210\206\345\274\200", Q_NULLPTR));
        label_17->setText(QApplication::translate("PaperInfo", "\346\224\266\345\275\225\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        IndexedAddress->setPlaceholderText(QApplication::translate("PaperInfo", "\345\241\253\345\206\231\347\275\221\347\273\234\346\224\266\345\275\225\345\234\260\345\235\200", Q_NULLPTR));
        label_5->setText(QApplication::translate("PaperInfo", "\344\270\212\344\274\240\345\216\237\346\226\207\357\274\232", Q_NULLPTR));
        ServerFileAddress->setText(QApplication::translate("PaperInfo", "\346\227\240", Q_NULLPTR));
        PaperFileBrower->setText(QApplication::translate("PaperInfo", "...", Q_NULLPTR));
        label_4->setText(QApplication::translate("PaperInfo", "\350\256\272\346\226\207\346\221\230\350\246\201\357\274\232", Q_NULLPTR));
        Abstract->setPlaceholderText(QApplication::translate("PaperInfo", "\345\241\253\345\206\231\350\256\272\346\226\207\346\221\230\350\246\201", Q_NULLPTR));
        PaperConfirmBTn->setText(QApplication::translate("PaperInfo", "\347\241\256\345\256\232\346\267\273\345\212\240", Q_NULLPTR));
        AppClose->setText(QApplication::translate("PaperInfo", "...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PaperInfo: public Ui_PaperInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAPERINFO_H
