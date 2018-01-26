/********************************************************************************
** Form generated from reading UI file 'ResearchProject.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESEARCHPROJECT_H
#define UI_RESEARCHPROJECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ResearchProject
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QVBoxLayout *verticalLayout;
    QLineEdit *Name;
    QFrame *line;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_8;
    QDateEdit *StartTime;
    QLabel *label_9;
    QDateEdit *EndTime;
    QSpacerItem *horizontalSpacer_19;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_16;
    QComboBox *Type;
    QLabel *label_19;
    QVBoxLayout *verticalLayout_10;
    QLineEdit *Number;
    QFrame *line_8;
    QLabel *label_20;
    QVBoxLayout *verticalLayout_12;
    QLineEdit *Funds;
    QFrame *line_10;
    QSpacerItem *horizontalSpacer_15;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_15;
    QVBoxLayout *verticalLayout_9;
    QLineEdit *Participants;
    QFrame *line_7;
    QSpacerItem *horizontalSpacer_16;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLabel *ServerDataAddress;
    QToolButton *DataFileBrower;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_17;
    QVBoxLayout *verticalLayout_11;
    QLineEdit *IndexedAddress;
    QFrame *line_9;
    QSpacerItem *horizontalSpacer_17;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QLabel *ServerPaperAddress;
    QToolButton *PaperFileBrower;
    QSpacerItem *horizontalSpacer_9;
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

    void setupUi(QDialog *ResearchProject)
    {
        if (ResearchProject->objectName().isEmpty())
            ResearchProject->setObjectName(QStringLiteral("ResearchProject"));
        ResearchProject->resize(1023, 613);
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
        ResearchProject->setPalette(palette);
        horizontalLayout = new QHBoxLayout(ResearchProject);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(89, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        scrollArea = new QScrollArea(ResearchProject);
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
        Name = new QLineEdit(scrollAreaWidgetContents);
        Name->setObjectName(QStringLiteral("Name"));
        Name->setFont(font);
        Name->setFrame(false);

        verticalLayout->addWidget(Name);

        line = new QFrame(scrollAreaWidgetContents);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);


        horizontalLayout_3->addLayout(verticalLayout);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_8 = new QLabel(scrollAreaWidgetContents);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);

        horizontalLayout_10->addWidget(label_8);

        StartTime = new QDateEdit(scrollAreaWidgetContents);
        StartTime->setObjectName(QStringLiteral("StartTime"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(StartTime->sizePolicy().hasHeightForWidth());
        StartTime->setSizePolicy(sizePolicy);
        StartTime->setMinimumSize(QSize(200, 0));
        StartTime->setFont(font);
        StartTime->setCalendarPopup(false);

        horizontalLayout_10->addWidget(StartTime);

        label_9 = new QLabel(scrollAreaWidgetContents);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font);

        horizontalLayout_10->addWidget(label_9);

        EndTime = new QDateEdit(scrollAreaWidgetContents);
        EndTime->setObjectName(QStringLiteral("EndTime"));
        sizePolicy.setHeightForWidth(EndTime->sizePolicy().hasHeightForWidth());
        EndTime->setSizePolicy(sizePolicy);
        EndTime->setMinimumSize(QSize(200, 0));
        EndTime->setFont(font);
        EndTime->setCalendarPopup(false);

        horizontalLayout_10->addWidget(EndTime);

        horizontalSpacer_19 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_19);


        verticalLayout_2->addLayout(horizontalLayout_10);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_16 = new QLabel(scrollAreaWidgetContents);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setFont(font);

        horizontalLayout_12->addWidget(label_16);

        Type = new QComboBox(scrollAreaWidgetContents);
        Type->setObjectName(QStringLiteral("Type"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Type->sizePolicy().hasHeightForWidth());
        Type->setSizePolicy(sizePolicy1);
        Type->setMinimumSize(QSize(200, 0));
        Type->setFont(font);

        horizontalLayout_12->addWidget(Type);

        label_19 = new QLabel(scrollAreaWidgetContents);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setFont(font);

        horizontalLayout_12->addWidget(label_19);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(0);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        Number = new QLineEdit(scrollAreaWidgetContents);
        Number->setObjectName(QStringLiteral("Number"));
        Number->setFont(font);
        Number->setFrame(false);

        verticalLayout_10->addWidget(Number);

        line_8 = new QFrame(scrollAreaWidgetContents);
        line_8->setObjectName(QStringLiteral("line_8"));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        verticalLayout_10->addWidget(line_8);


        horizontalLayout_12->addLayout(verticalLayout_10);

        label_20 = new QLabel(scrollAreaWidgetContents);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setFont(font);

        horizontalLayout_12->addWidget(label_20);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(0);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        Funds = new QLineEdit(scrollAreaWidgetContents);
        Funds->setObjectName(QStringLiteral("Funds"));
        Funds->setFont(font);
        Funds->setFrame(false);

        verticalLayout_12->addWidget(Funds);

        line_10 = new QFrame(scrollAreaWidgetContents);
        line_10->setObjectName(QStringLiteral("line_10"));
        line_10->setFrameShape(QFrame::HLine);
        line_10->setFrameShadow(QFrame::Sunken);

        verticalLayout_12->addWidget(line_10);


        horizontalLayout_12->addLayout(verticalLayout_12);

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
        Participants = new QLineEdit(scrollAreaWidgetContents);
        Participants->setObjectName(QStringLiteral("Participants"));
        Participants->setFont(font);
        Participants->setFrame(false);

        verticalLayout_9->addWidget(Participants);

        line_7 = new QFrame(scrollAreaWidgetContents);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        verticalLayout_9->addWidget(line_7);


        horizontalLayout_13->addLayout(verticalLayout_9);

        horizontalSpacer_16 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_16);


        verticalLayout_2->addLayout(horizontalLayout_13);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_5 = new QLabel(scrollAreaWidgetContents);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        horizontalLayout_4->addWidget(label_5);

        ServerDataAddress = new QLabel(scrollAreaWidgetContents);
        ServerDataAddress->setObjectName(QStringLiteral("ServerDataAddress"));
        ServerDataAddress->setMaximumSize(QSize(800, 16777215));
        QPalette palette2;
        QBrush brush2(QColor(170, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        QBrush brush3(QColor(120, 120, 120, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        ServerDataAddress->setPalette(palette2);
        ServerDataAddress->setFont(font);

        horizontalLayout_4->addWidget(ServerDataAddress);

        DataFileBrower = new QToolButton(scrollAreaWidgetContents);
        DataFileBrower->setObjectName(QStringLiteral("DataFileBrower"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Mainwindow/Resources/UrielQtFramework/edits.png"), QSize(), QIcon::Normal, QIcon::Off);
        DataFileBrower->setIcon(icon);
        DataFileBrower->setAutoRaise(true);

        horizontalLayout_4->addWidget(DataFileBrower);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);


        verticalLayout_2->addLayout(horizontalLayout_4);

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

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_6 = new QLabel(scrollAreaWidgetContents);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        horizontalLayout_7->addWidget(label_6);

        ServerPaperAddress = new QLabel(scrollAreaWidgetContents);
        ServerPaperAddress->setObjectName(QStringLiteral("ServerPaperAddress"));
        ServerPaperAddress->setMaximumSize(QSize(800, 16777215));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        ServerPaperAddress->setPalette(palette3);
        ServerPaperAddress->setFont(font);

        horizontalLayout_7->addWidget(ServerPaperAddress);

        PaperFileBrower = new QToolButton(scrollAreaWidgetContents);
        PaperFileBrower->setObjectName(QStringLiteral("PaperFileBrower"));
        PaperFileBrower->setIcon(icon);
        PaperFileBrower->setAutoRaise(true);

        horizontalLayout_7->addWidget(PaperFileBrower);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_9);


        verticalLayout_2->addLayout(horizontalLayout_7);

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
        QPalette palette4;
        QBrush brush4(QColor(170, 255, 255, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        ConfirmBtn->setPalette(palette4);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(16);
        ConfirmBtn->setFont(font1);
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

        frame = new QFrame(ResearchProject);
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


        retranslateUi(ResearchProject);

        QMetaObject::connectSlotsByName(ResearchProject);
    } // setupUi

    void retranslateUi(QDialog *ResearchProject)
    {
        ResearchProject->setWindowTitle(QApplication::translate("ResearchProject", "ResearchProject", Q_NULLPTR));
        label_3->setText(QApplication::translate("ResearchProject", "\351\241\271\347\233\256\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        Name->setPlaceholderText(QApplication::translate("ResearchProject", "\345\241\253\345\206\231\351\241\271\347\233\256\345\220\215\347\247\260", Q_NULLPTR));
        label_8->setText(QApplication::translate("ResearchProject", "\350\265\267\346\255\242\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        StartTime->setDisplayFormat(QApplication::translate("ResearchProject", "yyyy/MM/dd", Q_NULLPTR));
        label_9->setText(QApplication::translate("ResearchProject", "\350\207\263", Q_NULLPTR));
        EndTime->setDisplayFormat(QApplication::translate("ResearchProject", "yyyy/MM/dd", Q_NULLPTR));
        label_16->setText(QApplication::translate("ResearchProject", "\351\241\271\347\233\256\347\261\273\345\210\253:", Q_NULLPTR));
        label_19->setText(QApplication::translate("ResearchProject", "\351\241\271\347\233\256\347\274\226\345\217\267:", Q_NULLPTR));
        Number->setPlaceholderText(QApplication::translate("ResearchProject", "\345\241\253\345\206\231\351\241\271\347\233\256\347\274\226\345\217\267", Q_NULLPTR));
        label_20->setText(QApplication::translate("ResearchProject", "\351\241\271\347\233\256\347\273\217\350\264\271:", Q_NULLPTR));
        Funds->setPlaceholderText(QApplication::translate("ResearchProject", "\345\241\253\345\206\231\351\241\271\347\233\256\347\273\217\350\264\271", Q_NULLPTR));
        label_15->setText(QApplication::translate("ResearchProject", "\345\217\202\344\270\216\344\272\272\345\221\230\357\274\232", Q_NULLPTR));
        Participants->setPlaceholderText(QApplication::translate("ResearchProject", "\345\244\232\344\270\252\345\217\202\344\270\216\344\272\272\345\221\230\344\273\245;\345\210\206\345\274\200", Q_NULLPTR));
        label_5->setText(QApplication::translate("ResearchProject", "\345\256\236\351\252\214\346\225\260\346\215\256\343\200\201\347\205\247\347\211\207\343\200\201\351\241\271\347\233\256\345\256\236\346\226\275\350\277\207\347\250\213\344\270\255\351\207\215\350\246\201\350\265\204\346\226\231\347\255\211\357\274\232", Q_NULLPTR));
        ServerDataAddress->setText(QApplication::translate("ResearchProject", "\346\227\240", Q_NULLPTR));
        DataFileBrower->setText(QApplication::translate("ResearchProject", "...", Q_NULLPTR));
        label_17->setText(QApplication::translate("ResearchProject", "\346\224\266\345\275\225\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        IndexedAddress->setPlaceholderText(QApplication::translate("ResearchProject", "\345\241\253\345\206\231\347\275\221\347\273\234\346\224\266\345\275\225\345\234\260\345\235\200", Q_NULLPTR));
        label_6->setText(QApplication::translate("ResearchProject", "\344\270\212\344\274\240\345\216\237\346\226\207\357\274\232", Q_NULLPTR));
        ServerPaperAddress->setText(QApplication::translate("ResearchProject", "\346\227\240", Q_NULLPTR));
        PaperFileBrower->setText(QApplication::translate("ResearchProject", "...", Q_NULLPTR));
        label_4->setText(QApplication::translate("ResearchProject", "\351\241\271\347\233\256\346\221\230\350\246\201\357\274\232", Q_NULLPTR));
        Abstract->setPlaceholderText(QApplication::translate("ResearchProject", "\345\241\253\345\206\231\351\241\271\347\233\256\346\221\230\350\246\201", Q_NULLPTR));
        ConfirmBtn->setText(QApplication::translate("ResearchProject", "\347\241\256\350\256\244\346\217\220\344\272\244", Q_NULLPTR));
        AppClose->setText(QApplication::translate("ResearchProject", "...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ResearchProject: public Ui_ResearchProject {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESEARCHPROJECT_H
