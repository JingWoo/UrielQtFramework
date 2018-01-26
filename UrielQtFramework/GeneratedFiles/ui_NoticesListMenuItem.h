/********************************************************************************
** Form generated from reading UI file 'NoticesListMenuItem.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTICESLISTMENUITEM_H
#define UI_NOTICESLISTMENUITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NoticesListMenuItem
{
public:
    QHBoxLayout *horizontalLayout_2;
    QLabel *Ico;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *Title;
    QSpacerItem *horizontalSpacer;
    QLabel *Time;
    QLabel *Content;

    void setupUi(QWidget *NoticesListMenuItem)
    {
        if (NoticesListMenuItem->objectName().isEmpty())
            NoticesListMenuItem->setObjectName(QStringLiteral("NoticesListMenuItem"));
        NoticesListMenuItem->resize(785, 96);
        NoticesListMenuItem->setMinimumSize(QSize(0, 0));
        NoticesListMenuItem->setMaximumSize(QSize(999999, 99999));
        horizontalLayout_2 = new QHBoxLayout(NoticesListMenuItem);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        Ico = new QLabel(NoticesListMenuItem);
        Ico->setObjectName(QStringLiteral("Ico"));
        Ico->setMinimumSize(QSize(31, 41));
        Ico->setMaximumSize(QSize(31, 41));
        Ico->setPixmap(QPixmap(QString::fromUtf8(":/Mainwindow/Resources/UrielQtFramework/generalNotices.png")));
        Ico->setScaledContents(true);

        horizontalLayout_2->addWidget(Ico);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        Title = new QLabel(NoticesListMenuItem);
        Title->setObjectName(QStringLiteral("Title"));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(11);
        Title->setFont(font);

        horizontalLayout->addWidget(Title);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        Time = new QLabel(NoticesListMenuItem);
        Time->setObjectName(QStringLiteral("Time"));

        horizontalLayout->addWidget(Time);


        verticalLayout->addLayout(horizontalLayout);

        Content = new QLabel(NoticesListMenuItem);
        Content->setObjectName(QStringLiteral("Content"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(9);
        Content->setFont(font1);

        verticalLayout->addWidget(Content);


        horizontalLayout_2->addLayout(verticalLayout);


        retranslateUi(NoticesListMenuItem);

        QMetaObject::connectSlotsByName(NoticesListMenuItem);
    } // setupUi

    void retranslateUi(QWidget *NoticesListMenuItem)
    {
        NoticesListMenuItem->setWindowTitle(QApplication::translate("NoticesListMenuItem", "NoticesListMenuItem", Q_NULLPTR));
        Ico->setText(QString());
        Title->setText(QApplication::translate("NoticesListMenuItem", "\346\240\207\351\242\230", Q_NULLPTR));
        Time->setText(QApplication::translate("NoticesListMenuItem", "2017-07-10", Q_NULLPTR));
        Content->setText(QApplication::translate("NoticesListMenuItem", "\345\206\205\345\256\271", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NoticesListMenuItem: public Ui_NoticesListMenuItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTICESLISTMENUITEM_H
