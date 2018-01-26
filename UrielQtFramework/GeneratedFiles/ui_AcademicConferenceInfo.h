/********************************************************************************
** Form generated from reading UI file 'AcademicConferenceInfo.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACADEMICCONFERENCEINFO_H
#define UI_ACADEMICCONFERENCEINFO_H

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

class Ui_AcademicConferenceInfo
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
    QDateEdit *ReleaseTime;
    QSpacerItem *horizontalSpacer_18;
    QLabel *label_18;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_7;
    QRadioButton *ConferenceLanguage_Chinese;
    QRadioButton *ConferenceLanguage_English;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_21;
    QComboBox *PublicationForm;
    QSpacerItem *horizontalSpacer_20;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_20;
    QVBoxLayout *verticalLayout_13;
    QLineEdit *Author;
    QFrame *line_11;
    QSpacerItem *horizontalSpacer_19;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_15;
    QVBoxLayout *verticalLayout_9;
    QLineEdit *ConferenceName;
    QFrame *line_7;
    QLabel *label_19;
    QVBoxLayout *verticalLayout_12;
    QLineEdit *ConferenceSessionsNumber;
    QFrame *line_10;
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
    QToolButton *FileBrower;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_6;
    QPlainTextEdit *Abstract;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_7;
    QToolButton *ConfirmBtn;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout_3;
    QToolButton *AppClose;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *AcademicConferenceInfo)
    {
        if (AcademicConferenceInfo->objectName().isEmpty())
            AcademicConferenceInfo->setObjectName(QStringLiteral("AcademicConferenceInfo"));
        AcademicConferenceInfo->resize(1023, 613);
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
        AcademicConferenceInfo->setPalette(palette);
        horizontalLayout = new QHBoxLayout(AcademicConferenceInfo);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(89, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        scrollArea = new QScrollArea(AcademicConferenceInfo);
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
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 845, 613));
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

        ReleaseTime = new QDateEdit(scrollAreaWidgetContents);
        ReleaseTime->setObjectName(QStringLiteral("ReleaseTime"));
        ReleaseTime->setMinimumSize(QSize(150, 0));
        QFont font1;
        font1.setFamily(QStringLiteral("Times New Roman"));
        font1.setPointSize(12);
        ReleaseTime->setFont(font1);
        ReleaseTime->setCalendarPopup(true);

        horizontalLayout_8->addWidget(ReleaseTime);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_18);

        label_18 = new QLabel(scrollAreaWidgetContents);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setFont(font);

        horizontalLayout_8->addWidget(label_18);

        groupBox_2 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(10);
        groupBox_2->setFont(font2);
        horizontalLayout_7 = new QHBoxLayout(groupBox_2);
        horizontalLayout_7->setSpacing(10);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(10, 0, 10, 0);
        ConferenceLanguage_Chinese = new QRadioButton(groupBox_2);
        ConferenceLanguage_Chinese->setObjectName(QStringLiteral("ConferenceLanguage_Chinese"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font3.setPointSize(12);
        ConferenceLanguage_Chinese->setFont(font3);
        ConferenceLanguage_Chinese->setChecked(false);

        horizontalLayout_7->addWidget(ConferenceLanguage_Chinese);

        ConferenceLanguage_English = new QRadioButton(groupBox_2);
        ConferenceLanguage_English->setObjectName(QStringLiteral("ConferenceLanguage_English"));
        QFont font4;
        font4.setPointSize(12);
        ConferenceLanguage_English->setFont(font4);
        ConferenceLanguage_English->setChecked(true);

        horizontalLayout_7->addWidget(ConferenceLanguage_English);


        horizontalLayout_8->addWidget(groupBox_2);

        horizontalSpacer_10 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_10);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        label_21 = new QLabel(scrollAreaWidgetContents);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setFont(font);

        horizontalLayout_16->addWidget(label_21);

        PublicationForm = new QComboBox(scrollAreaWidgetContents);
        PublicationForm->setObjectName(QStringLiteral("PublicationForm"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PublicationForm->sizePolicy().hasHeightForWidth());
        PublicationForm->setSizePolicy(sizePolicy);
        PublicationForm->setFont(font3);

        horizontalLayout_16->addWidget(PublicationForm);

        horizontalSpacer_20 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_20);


        verticalLayout_2->addLayout(horizontalLayout_16);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label_20 = new QLabel(scrollAreaWidgetContents);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setFont(font);

        horizontalLayout_15->addWidget(label_20);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setSpacing(0);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        Author = new QLineEdit(scrollAreaWidgetContents);
        Author->setObjectName(QStringLiteral("Author"));
        Author->setFont(font);
        Author->setFrame(false);

        verticalLayout_13->addWidget(Author);

        line_11 = new QFrame(scrollAreaWidgetContents);
        line_11->setObjectName(QStringLiteral("line_11"));
        line_11->setFrameShape(QFrame::HLine);
        line_11->setFrameShadow(QFrame::Sunken);

        verticalLayout_13->addWidget(line_11);


        horizontalLayout_15->addLayout(verticalLayout_13);

        horizontalSpacer_19 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_19);


        verticalLayout_2->addLayout(horizontalLayout_15);

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
        ConferenceName = new QLineEdit(scrollAreaWidgetContents);
        ConferenceName->setObjectName(QStringLiteral("ConferenceName"));
        ConferenceName->setMinimumSize(QSize(450, 0));
        ConferenceName->setFont(font);
        ConferenceName->setFrame(false);

        verticalLayout_9->addWidget(ConferenceName);

        line_7 = new QFrame(scrollAreaWidgetContents);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        verticalLayout_9->addWidget(line_7);


        horizontalLayout_13->addLayout(verticalLayout_9);

        label_19 = new QLabel(scrollAreaWidgetContents);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setFont(font);

        horizontalLayout_13->addWidget(label_19);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(0);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        ConferenceSessionsNumber = new QLineEdit(scrollAreaWidgetContents);
        ConferenceSessionsNumber->setObjectName(QStringLiteral("ConferenceSessionsNumber"));
        ConferenceSessionsNumber->setMaximumSize(QSize(16777215, 16777215));
        ConferenceSessionsNumber->setFont(font);
        ConferenceSessionsNumber->setFrame(false);

        verticalLayout_12->addWidget(ConferenceSessionsNumber);

        line_10 = new QFrame(scrollAreaWidgetContents);
        line_10->setObjectName(QStringLiteral("line_10"));
        line_10->setFrameShape(QFrame::HLine);
        line_10->setFrameShadow(QFrame::Sunken);

        verticalLayout_12->addWidget(line_10);


        horizontalLayout_13->addLayout(verticalLayout_12);

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

        FileBrower = new QToolButton(scrollAreaWidgetContents);
        FileBrower->setObjectName(QStringLiteral("FileBrower"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Mainwindow/Resources/UrielQtFramework/edits.png"), QSize(), QIcon::Normal, QIcon::Off);
        FileBrower->setIcon(icon);
        FileBrower->setAutoRaise(true);

        horizontalLayout_4->addWidget(FileBrower);

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

        ConfirmBtn = new QToolButton(scrollAreaWidgetContents);
        ConfirmBtn->setObjectName(QStringLiteral("ConfirmBtn"));
        QPalette palette3;
        QBrush brush4(QColor(170, 255, 255, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        ConfirmBtn->setPalette(palette3);
        QFont font5;
        font5.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font5.setPointSize(16);
        ConfirmBtn->setFont(font5);
        ConfirmBtn->setAutoFillBackground(true);
        ConfirmBtn->setAutoRaise(true);

        horizontalLayout_6->addWidget(ConfirmBtn);

        horizontalSpacer_8 = new QSpacerItem(37, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_8);


        verticalLayout_2->addLayout(horizontalLayout_6);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout->addWidget(scrollArea);

        horizontalSpacer_2 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        frame = new QFrame(AcademicConferenceInfo);
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


        retranslateUi(AcademicConferenceInfo);

        QMetaObject::connectSlotsByName(AcademicConferenceInfo);
    } // setupUi

    void retranslateUi(QDialog *AcademicConferenceInfo)
    {
        AcademicConferenceInfo->setWindowTitle(QApplication::translate("AcademicConferenceInfo", "AcademicConferenceInfo", Q_NULLPTR));
        label_7->setText(QApplication::translate("AcademicConferenceInfo", "\350\256\272\346\226\207\351\242\230\347\233\256\357\274\232", Q_NULLPTR));
        OriginalTitle->setPlaceholderText(QApplication::translate("AcademicConferenceInfo", "\345\241\253\345\206\231\350\256\272\346\226\207\351\242\230\347\233\256", Q_NULLPTR));
        label_3->setText(QApplication::translate("AcademicConferenceInfo", "\347\277\273\350\257\221\351\242\230\347\233\256\357\274\232", Q_NULLPTR));
        TranslationTitle->setPlaceholderText(QApplication::translate("AcademicConferenceInfo", "\345\241\253\345\206\231\347\277\273\350\257\221\351\242\230\347\233\256", Q_NULLPTR));
        label_6->setText(QApplication::translate("AcademicConferenceInfo", "\345\217\221\350\241\250\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        label_18->setText(QApplication::translate("AcademicConferenceInfo", "\344\274\232\350\256\256\350\257\255\350\250\200\357\274\232", Q_NULLPTR));
        groupBox_2->setTitle(QString());
        ConferenceLanguage_Chinese->setText(QApplication::translate("AcademicConferenceInfo", "\344\270\255\346\226\207", Q_NULLPTR));
        ConferenceLanguage_English->setText(QApplication::translate("AcademicConferenceInfo", "\350\213\261\346\226\207", Q_NULLPTR));
        label_21->setText(QApplication::translate("AcademicConferenceInfo", "\345\217\221\350\241\250\345\275\242\345\274\217\357\274\232", Q_NULLPTR));
        label_20->setText(QApplication::translate("AcademicConferenceInfo", "\344\275\234\350\200\205\344\277\241\346\201\257\357\274\232", Q_NULLPTR));
        Author->setPlaceholderText(QApplication::translate("AcademicConferenceInfo", "\345\244\232\344\270\252\344\275\234\350\200\205\344\273\245;\345\210\206\345\274\200", Q_NULLPTR));
        label_15->setText(QApplication::translate("AcademicConferenceInfo", "\344\274\232\350\256\256\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        ConferenceName->setPlaceholderText(QApplication::translate("AcademicConferenceInfo", "\345\241\253\345\206\231\344\274\232\350\256\256\345\220\215\347\247\260", Q_NULLPTR));
        label_19->setText(QApplication::translate("AcademicConferenceInfo", "\344\274\232\350\256\256\345\261\212\346\225\260\357\274\232", Q_NULLPTR));
        ConferenceSessionsNumber->setPlaceholderText(QApplication::translate("AcademicConferenceInfo", "\345\241\253\345\206\231\344\274\232\350\256\256\345\261\212\346\225\260", Q_NULLPTR));
        label_17->setText(QApplication::translate("AcademicConferenceInfo", "\346\224\266\345\275\225\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        IndexedAddress->setPlaceholderText(QApplication::translate("AcademicConferenceInfo", "\345\241\253\345\206\231\347\275\221\347\273\234\346\224\266\345\275\225\345\234\260\345\235\200", Q_NULLPTR));
        label_5->setText(QApplication::translate("AcademicConferenceInfo", "\344\270\212\344\274\240\345\216\237\346\226\207\357\274\232", Q_NULLPTR));
        ServerFileAddress->setText(QApplication::translate("AcademicConferenceInfo", "\346\227\240", Q_NULLPTR));
        FileBrower->setText(QApplication::translate("AcademicConferenceInfo", "...", Q_NULLPTR));
        label_4->setText(QApplication::translate("AcademicConferenceInfo", "\350\256\272\346\226\207\346\221\230\350\246\201\357\274\232", Q_NULLPTR));
        Abstract->setPlaceholderText(QApplication::translate("AcademicConferenceInfo", "\345\241\253\345\206\231\350\256\272\346\226\207\346\221\230\350\246\201", Q_NULLPTR));
        ConfirmBtn->setText(QApplication::translate("AcademicConferenceInfo", "\347\241\256\345\256\232\346\267\273\345\212\240", Q_NULLPTR));
        AppClose->setText(QApplication::translate("AcademicConferenceInfo", "...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AcademicConferenceInfo: public Ui_AcademicConferenceInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACADEMICCONFERENCEINFO_H
