/********************************************************************************
** Form generated from reading UI file 'CashPaymentCertificate.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CASHPAYMENTCERTIFICATE_H
#define UI_CASHPAYMENTCERTIFICATE_H

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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CashPaymentCertificate
{
public:
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_5;
    QLabel *label;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QFrame *line;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineEdit_3;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *lineEdit_5;
    QFrame *line_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_15;
    QVBoxLayout *verticalLayout_12;
    QLineEdit *lineEdit_8;
    QFrame *line_12;
    QLabel *label_16;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_8;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_4;
    QFrame *frame;
    QVBoxLayout *verticalLayout_7;
    QToolButton *toolButton_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *CashPaymentCertificate)
    {
        if (CashPaymentCertificate->objectName().isEmpty())
            CashPaymentCertificate->setObjectName(QStringLiteral("CashPaymentCertificate"));
        CashPaymentCertificate->resize(1063, 577);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(155, 155, 155, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        CashPaymentCertificate->setPalette(palette);
        horizontalLayout_10 = new QHBoxLayout(CashPaymentCertificate);
        horizontalLayout_10->setSpacing(0);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(295, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_3);

        scrollArea = new QScrollArea(CashPaymentCertificate);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setMinimumSize(QSize(426, 0));
        scrollArea->setFrameShape(QFrame::StyledPanel);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 424, 575));
        verticalLayout_5 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_5->setSpacing(9);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QStringLiteral("label"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label->setPalette(palette1);
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(20);
        label->setFont(font);

        verticalLayout_5->addWidget(label);

        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        groupBox->setPalette(palette2);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(16);
        groupBox->setFont(font1);
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
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
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QPalette palette4;
        QBrush brush3(QColor(156, 156, 156, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        lineEdit->setPalette(palette4);
        lineEdit->setFont(font2);
        lineEdit->setAutoFillBackground(true);
        lineEdit->setFrame(false);

        verticalLayout->addWidget(lineEdit);

        line = new QFrame(groupBox);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);


        horizontalLayout_5->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_4->setPalette(palette5);
        label_4->setFont(font2);

        horizontalLayout_4->addWidget(label_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        lineEdit_3->setPalette(palette6);
        lineEdit_3->setFont(font2);
        lineEdit_3->setAutoFillBackground(true);
        lineEdit_3->setFrame(false);

        verticalLayout_3->addWidget(lineEdit_3);

        line_3 = new QFrame(groupBox);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_3);


        horizontalLayout_4->addLayout(verticalLayout_3);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_5->setPalette(palette7);
        label_5->setFont(font2);

        horizontalLayout_6->addWidget(label_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        lineEdit_5 = new QLineEdit(groupBox);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        lineEdit_5->setPalette(palette8);
        lineEdit_5->setFont(font2);
        lineEdit_5->setAutoFillBackground(true);
        lineEdit_5->setFrame(false);

        verticalLayout_4->addWidget(lineEdit_5);

        line_4 = new QFrame(groupBox);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_4);


        horizontalLayout_6->addLayout(verticalLayout_4);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_15 = new QLabel(groupBox);
        label_15->setObjectName(QStringLiteral("label_15"));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_15->setPalette(palette9);
        label_15->setFont(font2);

        horizontalLayout_3->addWidget(label_15);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(0);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        lineEdit_8 = new QLineEdit(groupBox);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette10.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette10.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette10.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        lineEdit_8->setPalette(palette10);
        lineEdit_8->setFont(font2);
        lineEdit_8->setAutoFillBackground(true);
        lineEdit_8->setFrame(false);

        verticalLayout_12->addWidget(lineEdit_8);

        line_12 = new QFrame(groupBox);
        line_12->setObjectName(QStringLiteral("line_12"));
        line_12->setFrameShape(QFrame::HLine);
        line_12->setFrameShadow(QFrame::Sunken);

        verticalLayout_12->addWidget(line_12);


        horizontalLayout_3->addLayout(verticalLayout_12);

        label_16 = new QLabel(groupBox);
        label_16->setObjectName(QStringLiteral("label_16"));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette11.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_16->setPalette(palette11);
        label_16->setFont(font2);

        horizontalLayout_3->addWidget(label_16);


        verticalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout_5->addWidget(groupBox);

        groupBox_2 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(0, 180));
        groupBox_2->setMaximumSize(QSize(16777215, 1000));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette12.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        groupBox_2->setPalette(palette12);
        groupBox_2->setFont(font1);
        verticalLayout_8 = new QVBoxLayout(groupBox_2);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(groupBox_2);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette13.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette13.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        textEdit->setPalette(palette13);
        textEdit->setAutoFillBackground(false);
        textEdit->setFrameShape(QFrame::Panel);

        verticalLayout_8->addWidget(textEdit);


        verticalLayout_5->addWidget(groupBox_2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_2);

        pushButton = new QPushButton(scrollAreaWidgetContents);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QPalette palette14;
        QBrush brush4(QColor(223, 223, 223, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette14.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette14.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette14.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        pushButton->setPalette(palette14);
        pushButton->setFont(font1);
        pushButton->setAutoFillBackground(true);
        pushButton->setFlat(true);

        horizontalLayout_9->addWidget(pushButton);

        pushButton_2 = new QPushButton(scrollAreaWidgetContents);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        QPalette palette15;
        palette15.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette15.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette15.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        pushButton_2->setPalette(palette15);
        pushButton_2->setFont(font1);
        pushButton_2->setAutoFillBackground(true);
        pushButton_2->setFlat(true);

        horizontalLayout_9->addWidget(pushButton_2);


        verticalLayout_5->addLayout(horizontalLayout_9);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_2);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_10->addWidget(scrollArea);

        horizontalSpacer_4 = new QSpacerItem(294, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_4);

        frame = new QFrame(CashPaymentCertificate);
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
        toolButton_2 = new QToolButton(frame);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Expense/Resources/Expense/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon);
        toolButton_2->setIconSize(QSize(35, 35));
        toolButton_2->setAutoRaise(true);

        verticalLayout_7->addWidget(toolButton_2);

        verticalSpacer = new QSpacerItem(20, 533, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer);


        horizontalLayout_10->addWidget(frame);


        retranslateUi(CashPaymentCertificate);

        QMetaObject::connectSlotsByName(CashPaymentCertificate);
    } // setupUi

    void retranslateUi(QDialog *CashPaymentCertificate)
    {
        CashPaymentCertificate->setWindowTitle(QApplication::translate("CashPaymentCertificate", "CashPaymentCertificate", Q_NULLPTR));
        label->setText(QApplication::translate("CashPaymentCertificate", "\347\216\260\351\207\221\346\224\257\344\273\230\346\203\205\345\206\265\350\257\264\346\230\216\344\271\246\345\275\225\345\205\245", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("CashPaymentCertificate", "\345\237\272\346\234\254\344\277\241\346\201\257", Q_NULLPTR));
        label_2->setText(QApplication::translate("CashPaymentCertificate", "\345\215\225\344\275\215\344\273\243\347\240\201    \357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("CashPaymentCertificate", "\347\216\260\351\207\221\346\224\257\344\273\230\351\241\271\347\233\256\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("CashPaymentCertificate", "\347\247\221\347\233\256        \357\274\232", Q_NULLPTR));
        label_15->setText(QApplication::translate("CashPaymentCertificate", "\347\216\260\351\207\221\346\224\257\344\273\230\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        lineEdit_8->setPlaceholderText(QApplication::translate("CashPaymentCertificate", "\302\245", Q_NULLPTR));
        label_16->setText(QApplication::translate("CashPaymentCertificate", "\357\274\210\345\205\203\357\274\211", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("CashPaymentCertificate", "\346\203\205\345\206\265\350\257\264\346\230\216", Q_NULLPTR));
        textEdit->setPlaceholderText(QApplication::translate("CashPaymentCertificate", "\346\255\244\345\244\204\345\241\253\345\205\245\345\244\207\346\263\250\344\277\241\346\201\257", Q_NULLPTR));
        pushButton->setText(QApplication::translate("CashPaymentCertificate", "\345\217\226\346\266\210", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("CashPaymentCertificate", "\347\241\256\345\256\232", Q_NULLPTR));
        toolButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CashPaymentCertificate: public Ui_CashPaymentCertificate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CASHPAYMENTCERTIFICATE_H
