/********************************************************************************
** Form generated from reading UI file 'ReleasingNotices.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RELEASINGNOTICES_H
#define UI_RELEASINGNOTICES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
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

class Ui_ReleasingNotices
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *NoticeCode;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QVBoxLayout *verticalLayout;
    QLineEdit *NoticeTitle;
    QFrame *line;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLabel *NoticeFile;
    QToolButton *NoticeFileBrower;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_7;
    QLabel *ImportanceDegreeLabel;
    QComboBox *ImportanceDegree;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_6;
    QPlainTextEdit *NoticeContent;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_7;
    QToolButton *ConfirmReleaseNotice;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout_3;
    QToolButton *AppClose;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *ReleasingNotices)
    {
        if (ReleasingNotices->objectName().isEmpty())
            ReleasingNotices->setObjectName(QStringLiteral("ReleasingNotices"));
        ReleasingNotices->resize(1023, 613);
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
        ReleasingNotices->setPalette(palette);
        horizontalLayout = new QHBoxLayout(ReleasingNotices);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(89, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        scrollArea = new QScrollArea(ReleasingNotices);
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
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(14);
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        NoticeCode = new QLabel(scrollAreaWidgetContents);
        NoticeCode->setObjectName(QStringLiteral("NoticeCode"));
        NoticeCode->setFont(font);

        horizontalLayout_2->addWidget(NoticeCode);

        label_2 = new QLabel(scrollAreaWidgetContents);
        label_2->setObjectName(QStringLiteral("label_2"));
        QPalette palette2;
        QBrush brush2(QColor(255, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        QBrush brush3(QColor(120, 120, 120, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        label_2->setPalette(palette2);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(12);
        label_2->setFont(font1);

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_2);

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
        NoticeTitle = new QLineEdit(scrollAreaWidgetContents);
        NoticeTitle->setObjectName(QStringLiteral("NoticeTitle"));
        NoticeTitle->setFont(font);
        NoticeTitle->setFrame(false);

        verticalLayout->addWidget(NoticeTitle);

        line = new QFrame(scrollAreaWidgetContents);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);


        horizontalLayout_3->addLayout(verticalLayout);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_5 = new QLabel(scrollAreaWidgetContents);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        horizontalLayout_4->addWidget(label_5);

        NoticeFile = new QLabel(scrollAreaWidgetContents);
        NoticeFile->setObjectName(QStringLiteral("NoticeFile"));
        NoticeFile->setMaximumSize(QSize(800, 16777215));
        QPalette palette3;
        QBrush brush4(QColor(170, 0, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        NoticeFile->setPalette(palette3);
        NoticeFile->setFont(font);

        horizontalLayout_4->addWidget(NoticeFile);

        NoticeFileBrower = new QToolButton(scrollAreaWidgetContents);
        NoticeFileBrower->setObjectName(QStringLiteral("NoticeFileBrower"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Mainwindow/Resources/UrielQtFramework/edits.png"), QSize(), QIcon::Normal, QIcon::Off);
        NoticeFileBrower->setIcon(icon);
        NoticeFileBrower->setAutoRaise(true);

        horizontalLayout_4->addWidget(NoticeFileBrower);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        ImportanceDegreeLabel = new QLabel(scrollAreaWidgetContents);
        ImportanceDegreeLabel->setObjectName(QStringLiteral("ImportanceDegreeLabel"));
        ImportanceDegreeLabel->setFont(font);

        horizontalLayout_7->addWidget(ImportanceDegreeLabel);

        ImportanceDegree = new QComboBox(scrollAreaWidgetContents);
        ImportanceDegree->setObjectName(QStringLiteral("ImportanceDegree"));
        ImportanceDegree->setMinimumSize(QSize(250, 0));
        ImportanceDegree->setFont(font);
        ImportanceDegree->setAutoFillBackground(true);
        ImportanceDegree->setEditable(true);
        ImportanceDegree->setFrame(true);

        horizontalLayout_7->addWidget(ImportanceDegree);

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

        NoticeContent = new QPlainTextEdit(scrollAreaWidgetContents);
        NoticeContent->setObjectName(QStringLiteral("NoticeContent"));
        NoticeContent->setFont(font);
        NoticeContent->setFrameShape(QFrame::StyledPanel);

        verticalLayout_2->addWidget(NoticeContent);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_7 = new QSpacerItem(37, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_7);

        ConfirmReleaseNotice = new QToolButton(scrollAreaWidgetContents);
        ConfirmReleaseNotice->setObjectName(QStringLiteral("ConfirmReleaseNotice"));
        QPalette palette4;
        QBrush brush5(QColor(170, 255, 255, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        ConfirmReleaseNotice->setPalette(palette4);
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(16);
        ConfirmReleaseNotice->setFont(font2);
        ConfirmReleaseNotice->setAutoFillBackground(true);
        ConfirmReleaseNotice->setAutoRaise(true);

        horizontalLayout_6->addWidget(ConfirmReleaseNotice);

        horizontalSpacer_8 = new QSpacerItem(37, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_8);


        verticalLayout_2->addLayout(horizontalLayout_6);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout->addWidget(scrollArea);

        horizontalSpacer_2 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        frame = new QFrame(ReleasingNotices);
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


        retranslateUi(ReleasingNotices);

        QMetaObject::connectSlotsByName(ReleasingNotices);
    } // setupUi

    void retranslateUi(QDialog *ReleasingNotices)
    {
        ReleasingNotices->setWindowTitle(QApplication::translate("ReleasingNotices", "ReleasingNotices", Q_NULLPTR));
        label->setText(QApplication::translate("ReleasingNotices", "\351\200\232\347\237\245\347\274\226\345\217\267\357\274\232", Q_NULLPTR));
        NoticeCode->setText(QApplication::translate("ReleasingNotices", "2017-07-10_001", Q_NULLPTR));
        label_2->setText(QApplication::translate("ReleasingNotices", "(\347\224\261\347\263\273\347\273\237\346\214\211\346\265\201\346\260\264\345\217\267\351\241\272\345\272\217\350\207\252\345\212\250\347\224\237\346\210\220\357\274\214\346\227\240\351\234\200\346\233\264\346\224\271)", Q_NULLPTR));
        label_3->setText(QApplication::translate("ReleasingNotices", "\351\200\232\347\237\245\346\240\207\351\242\230\357\274\232", Q_NULLPTR));
        NoticeTitle->setPlaceholderText(QApplication::translate("ReleasingNotices", "\345\241\253\345\206\231\351\200\232\347\237\245\346\240\207\351\242\230", Q_NULLPTR));
        label_5->setText(QApplication::translate("ReleasingNotices", "\351\200\232\347\237\245\351\231\204\344\273\266\357\274\232", Q_NULLPTR));
        NoticeFile->setText(QApplication::translate("ReleasingNotices", "\346\227\240", Q_NULLPTR));
        NoticeFileBrower->setText(QApplication::translate("ReleasingNotices", "...", Q_NULLPTR));
        ImportanceDegreeLabel->setText(QApplication::translate("ReleasingNotices", "\351\207\215\350\246\201\347\250\213\345\272\246\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("ReleasingNotices", "\351\200\232\347\237\245\345\206\205\345\256\271\357\274\232", Q_NULLPTR));
        NoticeContent->setPlaceholderText(QApplication::translate("ReleasingNotices", "\345\241\253\345\206\231\351\200\232\347\237\245\345\206\205\345\256\271", Q_NULLPTR));
        ConfirmReleaseNotice->setText(QApplication::translate("ReleasingNotices", "\345\217\221\345\270\203\351\200\232\347\237\245", Q_NULLPTR));
        AppClose->setText(QApplication::translate("ReleasingNotices", "...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ReleasingNotices: public Ui_ReleasingNotices {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RELEASINGNOTICES_H
