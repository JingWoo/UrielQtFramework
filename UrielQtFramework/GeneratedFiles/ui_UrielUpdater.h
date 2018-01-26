/********************************************************************************
** Form generated from reading UI file 'UrielUpdater.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_URIELUPDATER_H
#define UI_URIELUPDATER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UrielUpdater
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_4;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QCheckBox *showAllNotifcations;
    QLineEdit *installedVersion;
    QCheckBox *enableDownloader;
    QCheckBox *showUpdateNotifications;
    QLabel *label;
    QCheckBox *customAppcast;
    QTextBrowser *changelogText;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QPushButton *resetButton;
    QSpacerItem *horizontalSpacer;
    QToolButton *checkButton;
    QToolButton *closeButton;

    void setupUi(QMainWindow *UrielUpdater)
    {
        if (UrielUpdater->objectName().isEmpty())
            UrielUpdater->setObjectName(QStringLiteral("UrielUpdater"));
        UrielUpdater->resize(492, 418);
        UrielUpdater->setAutoFillBackground(false);
        UrielUpdater->setTabShape(QTabWidget::Rounded);
        centralwidget = new QWidget(UrielUpdater);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_4 = new QVBoxLayout(centralwidget);
        verticalLayout_4->setSpacing(3);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(3, 3, 3, 3);
        frame_4 = new QFrame(centralwidget);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setFrameShape(QFrame::Box);
        frame_4->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_4);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        frame_2 = new QFrame(frame_4);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(96, 96));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/Mainwindow/Resources/UrielQtFramework/update.png")));

        horizontalLayout_2->addWidget(label_2);

        frame_3 = new QFrame(frame_2);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setFrameShape(QFrame::NoFrame);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_3 = new QLabel(frame_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(12);
        label_3->setFont(font);

        verticalLayout_3->addWidget(label_3);

        label_4 = new QLabel(frame_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(11);
        label_4->setFont(font1);

        verticalLayout_3->addWidget(label_4);


        horizontalLayout_2->addWidget(frame_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(frame_2);

        groupBox = new QGroupBox(frame_4);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        showAllNotifcations = new QCheckBox(groupBox);
        showAllNotifcations->setObjectName(QStringLiteral("showAllNotifcations"));

        gridLayout->addWidget(showAllNotifcations, 3, 0, 1, 1);

        installedVersion = new QLineEdit(groupBox);
        installedVersion->setObjectName(QStringLiteral("installedVersion"));

        gridLayout->addWidget(installedVersion, 2, 1, 1, 1);

        enableDownloader = new QCheckBox(groupBox);
        enableDownloader->setObjectName(QStringLiteral("enableDownloader"));
        enableDownloader->setChecked(true);

        gridLayout->addWidget(enableDownloader, 5, 0, 1, 1);

        showUpdateNotifications = new QCheckBox(groupBox);
        showUpdateNotifications->setObjectName(QStringLiteral("showUpdateNotifications"));
        showUpdateNotifications->setChecked(true);

        gridLayout->addWidget(showUpdateNotifications, 4, 0, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        customAppcast = new QCheckBox(groupBox);
        customAppcast->setObjectName(QStringLiteral("customAppcast"));

        gridLayout->addWidget(customAppcast, 6, 0, 1, 1);


        verticalLayout->addWidget(groupBox);

        changelogText = new QTextBrowser(frame_4);
        changelogText->setObjectName(QStringLiteral("changelogText"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(16);
        changelogText->setFont(font2);
        changelogText->setFrameShape(QFrame::NoFrame);
        changelogText->setReadOnly(true);

        verticalLayout->addWidget(changelogText);

        frame = new QFrame(frame_4);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        resetButton = new QPushButton(frame);
        resetButton->setObjectName(QStringLiteral("resetButton"));

        horizontalLayout->addWidget(resetButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        checkButton = new QToolButton(frame);
        checkButton->setObjectName(QStringLiteral("checkButton"));
        checkButton->setFont(font2);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Mainwindow/Resources/UrielQtFramework/readlog.png"), QSize(), QIcon::Normal, QIcon::Off);
        checkButton->setIcon(icon);
        checkButton->setIconSize(QSize(25, 25));
        checkButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        checkButton->setAutoRaise(true);

        horizontalLayout->addWidget(checkButton);

        closeButton = new QToolButton(frame);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setMinimumSize(QSize(0, 0));
        closeButton->setFont(font2);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Mainwindow/Resources/UrielQtFramework/close5.png"), QSize(), QIcon::Normal, QIcon::Off);
        closeButton->setIcon(icon1);
        closeButton->setIconSize(QSize(25, 25));
        closeButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        closeButton->setAutoRaise(true);

        horizontalLayout->addWidget(closeButton);


        verticalLayout->addWidget(frame);


        verticalLayout_4->addWidget(frame_4);

        UrielUpdater->setCentralWidget(centralwidget);

        retranslateUi(UrielUpdater);

        QMetaObject::connectSlotsByName(UrielUpdater);
    } // setupUi

    void retranslateUi(QMainWindow *UrielUpdater)
    {
        UrielUpdater->setWindowTitle(QApplication::translate("UrielUpdater", "UrielUpdater", Q_NULLPTR));
        label_2->setText(QString());
        label_3->setText(QApplication::translate("UrielUpdater", "<html><head/><body><p><span style=\" font-size:xx-large; font-weight:600;\">\350\275\257\344\273\266\346\233\264\346\226\260\350\257\264\346\230\216</span></p></body></html>", Q_NULLPTR));
        label_4->setText(QApplication::translate("UrielUpdater", "<html><head/><body><p>\347\202\271\345\207\273\346\243\200\346\237\245\346\233\264\346\226\260\357\274\214\344\270\213\350\275\275\346\226\260\347\211\210\346\234\254\357\274\214\345\271\266\346\233\277\346\215\242\346\227\247\347\211\210\346\234\254\343\200\202</p></body></html>", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("UrielUpdater", "Updater Options", Q_NULLPTR));
        showAllNotifcations->setText(QApplication::translate("UrielUpdater", "Show all notifications", Q_NULLPTR));
        installedVersion->setText(QApplication::translate("UrielUpdater", "0.1", Q_NULLPTR));
        installedVersion->setPlaceholderText(QApplication::translate("UrielUpdater", "Write a version string...", Q_NULLPTR));
        enableDownloader->setText(QApplication::translate("UrielUpdater", "Enable integrated downloader", Q_NULLPTR));
        showUpdateNotifications->setText(QApplication::translate("UrielUpdater", "Notify me when an update is available", Q_NULLPTR));
        label->setText(QApplication::translate("UrielUpdater", "Set installed version (latest version is 1.0)", Q_NULLPTR));
        customAppcast->setText(QApplication::translate("UrielUpdater", "Do not use the QSU library to read the appcast", Q_NULLPTR));
        changelogText->setHtml(QApplication::translate("UrielUpdater", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\346\245\267\344\275\223'; font-size:16pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:9pt;\">                      </span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SimSun'; font-size:9pt;\"><br /></p></body></html>", Q_NULLPTR));
        resetButton->setText(QApplication::translate("UrielUpdater", "Reset Fields", Q_NULLPTR));
        checkButton->setText(QApplication::translate("UrielUpdater", "\346\243\200\346\265\213\346\233\264\346\226\260", Q_NULLPTR));
        closeButton->setText(QApplication::translate("UrielUpdater", "\345\205\263\351\227\255", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UrielUpdater: public Ui_UrielUpdater {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_URIELUPDATER_H
