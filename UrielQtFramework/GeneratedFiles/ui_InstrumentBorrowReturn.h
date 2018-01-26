/********************************************************************************
** Form generated from reading UI file 'InstrumentBorrowReturn.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSTRUMENTBORROWRETURN_H
#define UI_INSTRUMENTBORROWRETURN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateTimeEdit>
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

class Ui_InstrumentBorrowReturn
{
public:
    QHBoxLayout *horizontalLayout_2;
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
    QHBoxLayout *horizontalLayout_10;
    QLabel *BorrowReturnStatus;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QRadioButton *LendStatus;
    QRadioButton *ReturnStatus;
    QSpacerItem *horizontalSpacer_12;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_9;
    QVBoxLayout *verticalLayout_6;
    QLineEdit *BorrowReturnAddress;
    QFrame *line_5;
    QSpacerItem *horizontalSpacer_18;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_10;
    QDateTimeEdit *BorrowReturnTime;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_19;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *BorrowReturnStaffName;
    QFrame *line_2;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *Auditor;
    QFrame *line_3;
    QSpacerItem *horizontalSpacer_6;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_7;
    QPlainTextEdit *UseDescription;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_7;
    QToolButton *ConfirmOperation;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout_3;
    QToolButton *AppClose;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *InstrumentBorrowReturn)
    {
        if (InstrumentBorrowReturn->objectName().isEmpty())
            InstrumentBorrowReturn->setObjectName(QStringLiteral("InstrumentBorrowReturn"));
        InstrumentBorrowReturn->resize(1275, 834);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 0));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(240, 240, 240, 0));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        InstrumentBorrowReturn->setPalette(palette);
        horizontalLayout_2 = new QHBoxLayout(InstrumentBorrowReturn);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(89, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        scrollArea = new QScrollArea(InstrumentBorrowReturn);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        QPalette palette1;
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        scrollArea->setPalette(palette1);
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1097, 834));
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

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        BorrowReturnStatus = new QLabel(scrollAreaWidgetContents);
        BorrowReturnStatus->setObjectName(QStringLiteral("BorrowReturnStatus"));
        BorrowReturnStatus->setFont(font);

        horizontalLayout_10->addWidget(BorrowReturnStatus);

        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, 0);
        LendStatus = new QRadioButton(groupBox);
        LendStatus->setObjectName(QStringLiteral("LendStatus"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(12);
        LendStatus->setFont(font1);

        horizontalLayout->addWidget(LendStatus);

        ReturnStatus = new QRadioButton(groupBox);
        ReturnStatus->setObjectName(QStringLiteral("ReturnStatus"));
        ReturnStatus->setFont(font1);
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
        BorrowReturnAddress = new QLineEdit(scrollAreaWidgetContents);
        BorrowReturnAddress->setObjectName(QStringLiteral("BorrowReturnAddress"));
        BorrowReturnAddress->setFont(font);
        BorrowReturnAddress->setFrame(false);

        verticalLayout_6->addWidget(BorrowReturnAddress);

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

        BorrowReturnTime = new QDateTimeEdit(scrollAreaWidgetContents);
        BorrowReturnTime->setObjectName(QStringLiteral("BorrowReturnTime"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(13);
        BorrowReturnTime->setFont(font2);

        horizontalLayout_12->addWidget(BorrowReturnTime);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_3);

        horizontalSpacer_19 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_19);


        verticalLayout_5->addLayout(horizontalLayout_12);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(scrollAreaWidgetContents);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        horizontalLayout_4->addWidget(label_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        BorrowReturnStaffName = new QLineEdit(scrollAreaWidgetContents);
        BorrowReturnStaffName->setObjectName(QStringLiteral("BorrowReturnStaffName"));
        BorrowReturnStaffName->setFont(font);
        BorrowReturnStaffName->setFrame(false);

        verticalLayout_2->addWidget(BorrowReturnStaffName);

        line_2 = new QFrame(scrollAreaWidgetContents);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);


        horizontalLayout_4->addLayout(verticalLayout_2);

        horizontalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);


        verticalLayout_5->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(scrollAreaWidgetContents);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        horizontalLayout_5->addWidget(label_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        Auditor = new QLineEdit(scrollAreaWidgetContents);
        Auditor->setObjectName(QStringLiteral("Auditor"));
        Auditor->setFont(font);
        Auditor->setFrame(false);

        verticalLayout_4->addWidget(Auditor);

        line_3 = new QFrame(scrollAreaWidgetContents);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_3);


        horizontalLayout_5->addLayout(verticalLayout_4);

        horizontalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);


        verticalLayout_5->addLayout(horizontalLayout_5);

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
        UseDescription = new QPlainTextEdit(groupBox_3);
        UseDescription->setObjectName(QStringLiteral("UseDescription"));
        UseDescription->setMinimumSize(QSize(0, 150));
        UseDescription->setFont(font);
        UseDescription->setFrameShape(QFrame::StyledPanel);

        verticalLayout_7->addWidget(UseDescription);


        verticalLayout_5->addWidget(groupBox_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_7 = new QSpacerItem(37, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_7);

        ConfirmOperation = new QToolButton(scrollAreaWidgetContents);
        ConfirmOperation->setObjectName(QStringLiteral("ConfirmOperation"));
        QPalette palette2;
        QBrush brush3(QColor(170, 255, 255, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        ConfirmOperation->setPalette(palette2);
        ConfirmOperation->setFont(font3);
        ConfirmOperation->setAutoFillBackground(true);
        ConfirmOperation->setAutoRaise(true);

        horizontalLayout_6->addWidget(ConfirmOperation);

        horizontalSpacer_8 = new QSpacerItem(37, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_8);


        verticalLayout_5->addLayout(horizontalLayout_6);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_2->addWidget(scrollArea);

        horizontalSpacer_2 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        frame = new QFrame(InstrumentBorrowReturn);
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


        horizontalLayout_2->addWidget(frame);


        retranslateUi(InstrumentBorrowReturn);

        QMetaObject::connectSlotsByName(InstrumentBorrowReturn);
    } // setupUi

    void retranslateUi(QDialog *InstrumentBorrowReturn)
    {
        InstrumentBorrowReturn->setWindowTitle(QApplication::translate("InstrumentBorrowReturn", "InstrumentBorrowReturn", Q_NULLPTR));
        label_3->setText(QApplication::translate("InstrumentBorrowReturn", "\350\256\276\345\244\207\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        InstrumentName->setPlaceholderText(QApplication::translate("InstrumentBorrowReturn", "\345\241\253\345\206\231\350\256\276\345\244\207\345\220\215\347\247\260", Q_NULLPTR));
        BorrowReturnStatus->setText(QApplication::translate("InstrumentBorrowReturn", "\345\275\223\345\211\215\347\212\266\346\200\201\357\274\232", Q_NULLPTR));
        groupBox->setTitle(QString());
        LendStatus->setText(QApplication::translate("InstrumentBorrowReturn", "\345\200\237\345\207\272", Q_NULLPTR));
        ReturnStatus->setText(QApplication::translate("InstrumentBorrowReturn", "\345\255\230\346\224\276", Q_NULLPTR));
        label_9->setText(QApplication::translate("InstrumentBorrowReturn", "\345\200\237\350\277\230\344\275\215\347\275\256\357\274\232", Q_NULLPTR));
        BorrowReturnAddress->setPlaceholderText(QApplication::translate("InstrumentBorrowReturn", "\345\241\253\345\206\231\346\211\200\345\234\250\344\275\215\347\275\256", Q_NULLPTR));
        label_10->setText(QApplication::translate("InstrumentBorrowReturn", "\345\200\237\350\277\230\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("InstrumentBorrowReturn", "\345\200\237\350\277\230\344\272\272\345\221\230\357\274\232", Q_NULLPTR));
        BorrowReturnStaffName->setPlaceholderText(QApplication::translate("InstrumentBorrowReturn", "\345\241\253\345\206\231\345\200\237\350\277\230\344\272\272\345\247\223\345\220\215", Q_NULLPTR));
        label_5->setText(QApplication::translate("InstrumentBorrowReturn", "\345\200\237\350\277\230\345\256\241\346\240\270\357\274\232", Q_NULLPTR));
        Auditor->setPlaceholderText(QApplication::translate("InstrumentBorrowReturn", "\345\256\241\346\240\270\344\272\272\345\247\223\345\220\215", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("InstrumentBorrowReturn", "\344\275\277\347\224\250\346\217\217\350\277\260\357\274\232", Q_NULLPTR));
        UseDescription->setPlaceholderText(QApplication::translate("InstrumentBorrowReturn", "\345\241\253\345\206\231\350\256\276\345\244\207\346\217\217\350\277\260", Q_NULLPTR));
        ConfirmOperation->setText(QApplication::translate("InstrumentBorrowReturn", "\347\241\256\350\256\244\345\200\237\345\207\272", Q_NULLPTR));
        AppClose->setText(QApplication::translate("InstrumentBorrowReturn", "...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class InstrumentBorrowReturn: public Ui_InstrumentBorrowReturn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSTRUMENTBORROWRETURN_H
