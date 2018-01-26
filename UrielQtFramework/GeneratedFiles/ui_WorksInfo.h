/********************************************************************************
** Form generated from reading UI file 'WorksInfo.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORKSINFO_H
#define UI_WORKSINFO_H

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

class Ui_WorksInfo
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_7;
    QComboBox *Type;
    QSpacerItem *horizontalSpacer_11;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QVBoxLayout *verticalLayout;
    QLineEdit *Name;
    QFrame *line;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_16;
    QVBoxLayout *verticalLayout_10;
    QLineEdit *PublishingHouse;
    QFrame *line_8;
    QSpacerItem *horizontalSpacer_15;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_10;
    QDateEdit *EmploymentTime;
    QSpacerItem *horizontalSpacer_14;
    QLabel *label_11;
    QDateEdit *PublishingTime;
    QSpacerItem *horizontalSpacer_18;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_15;
    QVBoxLayout *verticalLayout_9;
    QLineEdit *ISBN;
    QFrame *line_7;
    QSpacerItem *horizontalSpacer_19;
    QLabel *label_18;
    QVBoxLayout *verticalLayout_12;
    QLineEdit *PrintingTimes;
    QFrame *line_10;
    QSpacerItem *horizontalSpacer_16;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_17;
    QVBoxLayout *verticalLayout_11;
    QLineEdit *Author;
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

    void setupUi(QDialog *WorksInfo)
    {
        if (WorksInfo->objectName().isEmpty())
            WorksInfo->setObjectName(QStringLiteral("WorksInfo"));
        WorksInfo->resize(1023, 613);
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
        WorksInfo->setPalette(palette);
        horizontalLayout = new QHBoxLayout(WorksInfo);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(89, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        scrollArea = new QScrollArea(WorksInfo);
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

        Type = new QComboBox(scrollAreaWidgetContents);
        Type->setObjectName(QStringLiteral("Type"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Type->sizePolicy().hasHeightForWidth());
        Type->setSizePolicy(sizePolicy);
        Type->setMinimumSize(QSize(250, 0));
        Type->setFont(font);
        Type->setAutoFillBackground(true);
        Type->setEditable(true);
        Type->setFrame(true);

        horizontalLayout_9->addWidget(Type);

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

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_16 = new QLabel(scrollAreaWidgetContents);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setFont(font);

        horizontalLayout_12->addWidget(label_16);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(0);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        PublishingHouse = new QLineEdit(scrollAreaWidgetContents);
        PublishingHouse->setObjectName(QStringLiteral("PublishingHouse"));
        PublishingHouse->setFont(font);
        PublishingHouse->setFrame(false);

        verticalLayout_10->addWidget(PublishingHouse);

        line_8 = new QFrame(scrollAreaWidgetContents);
        line_8->setObjectName(QStringLiteral("line_8"));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        verticalLayout_10->addWidget(line_8);


        horizontalLayout_12->addLayout(verticalLayout_10);

        horizontalSpacer_15 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_15);


        verticalLayout_2->addLayout(horizontalLayout_12);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_10 = new QLabel(scrollAreaWidgetContents);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font);

        horizontalLayout_11->addWidget(label_10);

        EmploymentTime = new QDateEdit(scrollAreaWidgetContents);
        EmploymentTime->setObjectName(QStringLiteral("EmploymentTime"));
        EmploymentTime->setMinimumSize(QSize(205, 0));
        EmploymentTime->setFont(font);
        EmploymentTime->setCalendarPopup(true);

        horizontalLayout_11->addWidget(EmploymentTime);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_14);

        label_11 = new QLabel(scrollAreaWidgetContents);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font);

        horizontalLayout_11->addWidget(label_11);

        PublishingTime = new QDateEdit(scrollAreaWidgetContents);
        PublishingTime->setObjectName(QStringLiteral("PublishingTime"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(PublishingTime->sizePolicy().hasHeightForWidth());
        PublishingTime->setSizePolicy(sizePolicy1);
        PublishingTime->setMinimumSize(QSize(205, 0));
        PublishingTime->setFont(font);
        PublishingTime->setCalendarPopup(true);

        horizontalLayout_11->addWidget(PublishingTime);

        horizontalSpacer_18 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_18);


        verticalLayout_2->addLayout(horizontalLayout_11);

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
        ISBN = new QLineEdit(scrollAreaWidgetContents);
        ISBN->setObjectName(QStringLiteral("ISBN"));
        ISBN->setMinimumSize(QSize(245, 0));
        ISBN->setFont(font);
        ISBN->setFrame(false);

        verticalLayout_9->addWidget(ISBN);

        line_7 = new QFrame(scrollAreaWidgetContents);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        verticalLayout_9->addWidget(line_7);


        horizontalLayout_13->addLayout(verticalLayout_9);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_19);

        label_18 = new QLabel(scrollAreaWidgetContents);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setFont(font);

        horizontalLayout_13->addWidget(label_18);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(0);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        PrintingTimes = new QLineEdit(scrollAreaWidgetContents);
        PrintingTimes->setObjectName(QStringLiteral("PrintingTimes"));
        PrintingTimes->setMinimumSize(QSize(200, 0));
        PrintingTimes->setFont(font);
        PrintingTimes->setFrame(false);

        verticalLayout_12->addWidget(PrintingTimes);

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
        Author = new QLineEdit(scrollAreaWidgetContents);
        Author->setObjectName(QStringLiteral("Author"));
        Author->setFont(font);
        Author->setFrame(false);

        verticalLayout_11->addWidget(Author);

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

        frame = new QFrame(WorksInfo);
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


        retranslateUi(WorksInfo);

        QMetaObject::connectSlotsByName(WorksInfo);
    } // setupUi

    void retranslateUi(QDialog *WorksInfo)
    {
        WorksInfo->setWindowTitle(QApplication::translate("WorksInfo", "WorksInfo", Q_NULLPTR));
        label_7->setText(QApplication::translate("WorksInfo", "\350\221\227\344\275\234\347\261\273\345\236\213\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("WorksInfo", "\350\221\227\344\275\234\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        Name->setPlaceholderText(QApplication::translate("WorksInfo", "\345\241\253\345\206\231\350\221\227\344\275\234\345\220\215\347\247\260", Q_NULLPTR));
        label_16->setText(QApplication::translate("WorksInfo", "\345\207\272\347\211\210\347\244\276  \357\274\232", Q_NULLPTR));
        PublishingHouse->setPlaceholderText(QApplication::translate("WorksInfo", "\345\241\253\345\206\231\345\207\272\347\211\210\347\244\276", Q_NULLPTR));
        label_10->setText(QApplication::translate("WorksInfo", "\345\275\225\347\224\250\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        label_11->setText(QApplication::translate("WorksInfo", "\345\207\272\347\211\210\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        label_15->setText(QApplication::translate("WorksInfo", "ISBN\357\274\232", Q_NULLPTR));
        ISBN->setPlaceholderText(QApplication::translate("WorksInfo", "\345\241\253\345\206\231ISBN", Q_NULLPTR));
        label_18->setText(QApplication::translate("WorksInfo", "\345\215\260\345\210\267\346\254\241\346\225\260\357\274\232", Q_NULLPTR));
        PrintingTimes->setPlaceholderText(QApplication::translate("WorksInfo", "\345\241\253\345\206\231\345\215\260\345\210\267\346\254\241\346\225\260", Q_NULLPTR));
        label_17->setText(QApplication::translate("WorksInfo", "\344\275\234\350\200\205\344\277\241\346\201\257\357\274\232", Q_NULLPTR));
        Author->setPlaceholderText(QApplication::translate("WorksInfo", "\345\244\232\344\270\252\344\275\234\350\200\205\344\273\245;\345\210\206\345\274\200", Q_NULLPTR));
        label_5->setText(QApplication::translate("WorksInfo", "\344\270\212\344\274\240\350\221\227\344\275\234\357\274\232", Q_NULLPTR));
        ServerFileAddress->setText(QApplication::translate("WorksInfo", "\346\227\240", Q_NULLPTR));
        FileBrower->setText(QApplication::translate("WorksInfo", "...", Q_NULLPTR));
        label_4->setText(QApplication::translate("WorksInfo", "\350\221\227\344\275\234\346\221\230\350\246\201\357\274\232", Q_NULLPTR));
        Abstract->setPlaceholderText(QApplication::translate("WorksInfo", "\345\241\253\345\206\231\344\270\223\345\210\251\346\221\230\350\246\201", Q_NULLPTR));
        ConfirmBtn->setText(QApplication::translate("WorksInfo", "\347\241\256\345\256\232\346\267\273\345\212\240", Q_NULLPTR));
        AppClose->setText(QApplication::translate("WorksInfo", "...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WorksInfo: public Ui_WorksInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORKSINFO_H
