/********************************************************************************
** Form generated from reading UI file 'NoticesCommentItem.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTICESCOMMENTITEM_H
#define UI_NOTICESCOMMENTITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NoticesCommentItem
{
public:
    QVBoxLayout *verticalLayout_4;
    QFrame *line;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QToolButton *HeadIco;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QToolButton *Name;
    QSpacerItem *horizontalSpacer;
    QLabel *Content;
    QVBoxLayout *verticalLayout;
    QLabel *Time;
    QToolButton *Comment;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *NoticesCommentItem)
    {
        if (NoticesCommentItem->objectName().isEmpty())
            NoticesCommentItem->setObjectName(QStringLiteral("NoticesCommentItem"));
        NoticesCommentItem->resize(689, 107);
        verticalLayout_4 = new QVBoxLayout(NoticesCommentItem);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        line = new QFrame(NoticesCommentItem);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        HeadIco = new QToolButton(NoticesCommentItem);
        HeadIco->setObjectName(QStringLiteral("HeadIco"));
        HeadIco->setMinimumSize(QSize(32, 32));
        HeadIco->setMaximumSize(QSize(32, 32));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Mainwindow/Resources/UrielQtFramework/head.png"), QSize(), QIcon::Normal, QIcon::Off);
        HeadIco->setIcon(icon);
        HeadIco->setIconSize(QSize(32, 32));
        HeadIco->setAutoRaise(true);

        verticalLayout_3->addWidget(HeadIco);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        Name = new QToolButton(NoticesCommentItem);
        Name->setObjectName(QStringLiteral("Name"));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(12);
        Name->setFont(font);
        Name->setAutoRaise(true);

        horizontalLayout->addWidget(Name);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout);

        Content = new QLabel(NoticesCommentItem);
        Content->setObjectName(QStringLiteral("Content"));
        Content->setFont(font);
        Content->setWordWrap(true);

        verticalLayout_2->addWidget(Content);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Time = new QLabel(NoticesCommentItem);
        Time->setObjectName(QStringLiteral("Time"));

        verticalLayout->addWidget(Time);

        Comment = new QToolButton(NoticesCommentItem);
        Comment->setObjectName(QStringLiteral("Comment"));
        QPalette palette;
        QBrush brush(QColor(0, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Light, brush);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Active, QPalette::NoRole, brush);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Inactive, QPalette::NoRole, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Disabled, QPalette::NoRole, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush);
        Comment->setPalette(palette);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(11);
        Comment->setFont(font1);
        Comment->setAutoRaise(true);

        verticalLayout->addWidget(Comment);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_4->addLayout(horizontalLayout_2);


        retranslateUi(NoticesCommentItem);

        QMetaObject::connectSlotsByName(NoticesCommentItem);
    } // setupUi

    void retranslateUi(QWidget *NoticesCommentItem)
    {
        NoticesCommentItem->setWindowTitle(QApplication::translate("NoticesCommentItem", "NoticesCommentItem", Q_NULLPTR));
        HeadIco->setText(QApplication::translate("NoticesCommentItem", "H", Q_NULLPTR));
        Name->setText(QApplication::translate("NoticesCommentItem", "Uriel", Q_NULLPTR));
        Content->setText(QString());
        Time->setText(QApplication::translate("NoticesCommentItem", "07-02 16:11", Q_NULLPTR));
        Comment->setText(QApplication::translate("NoticesCommentItem", "\350\257\204\350\256\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NoticesCommentItem: public Ui_NoticesCommentItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTICESCOMMENTITEM_H
