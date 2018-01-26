/********************************************************************************
** Form generated from reading UI file 'UrielImageViewer.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_URIELIMAGEVIEWER_H
#define UI_URIELIMAGEVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UrielImageViewer
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QToolButton *openAct;
    QToolButton *saveAsAct;
    QToolButton *printAct;
    QToolButton *copyAct;
    QToolButton *pasteAct;
    QToolButton *zoomInAct;
    QToolButton *zoomOutAct;
    QToolButton *normalSizeAct;
    QToolButton *fitToWindowAct;
    QSpacerItem *horizontalSpacer;
    QToolButton *exitAct;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QDialog *UrielImageViewer)
    {
        if (UrielImageViewer->objectName().isEmpty())
            UrielImageViewer->setObjectName(QStringLiteral("UrielImageViewer"));
        UrielImageViewer->resize(855, 552);
        verticalLayout = new QVBoxLayout(UrielImageViewer);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(UrielImageViewer);
        frame->setObjectName(QStringLiteral("frame"));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        frame->setPalette(palette);
        frame->setAutoFillBackground(true);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        openAct = new QToolButton(frame);
        openAct->setObjectName(QStringLiteral("openAct"));
        openAct->setMinimumSize(QSize(30, 30));
        openAct->setMaximumSize(QSize(30, 30));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Expense/Resources/Expense/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        openAct->setIcon(icon);
        openAct->setIconSize(QSize(28, 28));
        openAct->setAutoRaise(true);

        horizontalLayout->addWidget(openAct);

        saveAsAct = new QToolButton(frame);
        saveAsAct->setObjectName(QStringLiteral("saveAsAct"));
        saveAsAct->setMinimumSize(QSize(30, 30));
        saveAsAct->setMaximumSize(QSize(30, 30));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Expense/Resources/Expense/saveas.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveAsAct->setIcon(icon1);
        saveAsAct->setIconSize(QSize(28, 28));
        saveAsAct->setAutoRaise(true);

        horizontalLayout->addWidget(saveAsAct);

        printAct = new QToolButton(frame);
        printAct->setObjectName(QStringLiteral("printAct"));
        printAct->setMinimumSize(QSize(30, 30));
        printAct->setMaximumSize(QSize(30, 30));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Expense/Resources/Expense/print.png"), QSize(), QIcon::Normal, QIcon::Off);
        printAct->setIcon(icon2);
        printAct->setIconSize(QSize(28, 28));
        printAct->setAutoRaise(true);

        horizontalLayout->addWidget(printAct);

        copyAct = new QToolButton(frame);
        copyAct->setObjectName(QStringLiteral("copyAct"));
        copyAct->setMinimumSize(QSize(30, 30));
        copyAct->setMaximumSize(QSize(30, 30));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Expense/Resources/Expense/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        copyAct->setIcon(icon3);
        copyAct->setIconSize(QSize(28, 28));
        copyAct->setAutoRaise(true);

        horizontalLayout->addWidget(copyAct);

        pasteAct = new QToolButton(frame);
        pasteAct->setObjectName(QStringLiteral("pasteAct"));
        pasteAct->setMinimumSize(QSize(30, 30));
        pasteAct->setMaximumSize(QSize(30, 30));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Expense/Resources/Expense/paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        pasteAct->setIcon(icon4);
        pasteAct->setIconSize(QSize(28, 28));
        pasteAct->setAutoRaise(true);

        horizontalLayout->addWidget(pasteAct);

        zoomInAct = new QToolButton(frame);
        zoomInAct->setObjectName(QStringLiteral("zoomInAct"));
        zoomInAct->setMinimumSize(QSize(30, 30));
        zoomInAct->setMaximumSize(QSize(30, 30));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/Expense/Resources/Expense/zoom_in.png"), QSize(), QIcon::Normal, QIcon::Off);
        zoomInAct->setIcon(icon5);
        zoomInAct->setIconSize(QSize(28, 28));
        zoomInAct->setAutoRaise(true);

        horizontalLayout->addWidget(zoomInAct);

        zoomOutAct = new QToolButton(frame);
        zoomOutAct->setObjectName(QStringLiteral("zoomOutAct"));
        zoomOutAct->setMinimumSize(QSize(30, 30));
        zoomOutAct->setMaximumSize(QSize(30, 30));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/Expense/Resources/Expense/zoom_out.png"), QSize(), QIcon::Normal, QIcon::Off);
        zoomOutAct->setIcon(icon6);
        zoomOutAct->setIconSize(QSize(28, 28));
        zoomOutAct->setAutoRaise(true);

        horizontalLayout->addWidget(zoomOutAct);

        normalSizeAct = new QToolButton(frame);
        normalSizeAct->setObjectName(QStringLiteral("normalSizeAct"));
        normalSizeAct->setMinimumSize(QSize(30, 30));
        normalSizeAct->setMaximumSize(QSize(30, 30));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/Expense/Resources/Expense/bt_action_normal_size.png"), QSize(), QIcon::Normal, QIcon::Off);
        normalSizeAct->setIcon(icon7);
        normalSizeAct->setIconSize(QSize(28, 28));
        normalSizeAct->setAutoRaise(true);

        horizontalLayout->addWidget(normalSizeAct);

        fitToWindowAct = new QToolButton(frame);
        fitToWindowAct->setObjectName(QStringLiteral("fitToWindowAct"));
        fitToWindowAct->setMinimumSize(QSize(30, 30));
        fitToWindowAct->setMaximumSize(QSize(30, 30));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/Expense/Resources/Expense/fitToWindow.png"), QSize(), QIcon::Normal, QIcon::Off);
        fitToWindowAct->setIcon(icon8);
        fitToWindowAct->setIconSize(QSize(28, 28));
        fitToWindowAct->setCheckable(true);
        fitToWindowAct->setChecked(false);
        fitToWindowAct->setAutoRaise(true);

        horizontalLayout->addWidget(fitToWindowAct);

        horizontalSpacer = new QSpacerItem(490, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        exitAct = new QToolButton(frame);
        exitAct->setObjectName(QStringLiteral("exitAct"));
        exitAct->setMinimumSize(QSize(30, 30));
        exitAct->setMaximumSize(QSize(30, 30));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/Mainwindow/Resources/UrielQtFramework/close5.png"), QSize(), QIcon::Normal, QIcon::Off);
        exitAct->setIcon(icon9);
        exitAct->setIconSize(QSize(28, 28));
        exitAct->setAutoRaise(true);

        horizontalLayout->addWidget(exitAct);


        verticalLayout->addWidget(frame);

        scrollArea = new QScrollArea(UrielImageViewer);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 855, 520));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(UrielImageViewer);

        QMetaObject::connectSlotsByName(UrielImageViewer);
    } // setupUi

    void retranslateUi(QDialog *UrielImageViewer)
    {
        UrielImageViewer->setWindowTitle(QApplication::translate("UrielImageViewer", "UrielImageViewer", Q_NULLPTR));
        openAct->setText(QString());
        saveAsAct->setText(QString());
        printAct->setText(QString());
        copyAct->setText(QString());
        pasteAct->setText(QString());
        zoomInAct->setText(QString());
        zoomOutAct->setText(QString());
        normalSizeAct->setText(QString());
        fitToWindowAct->setText(QString());
        exitAct->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class UrielImageViewer: public Ui_UrielImageViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_URIELIMAGEVIEWER_H
