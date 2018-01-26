/********************************************************************************
** Form generated from reading UI file 'UserInfo.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERINFO_H
#define UI_USERINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_UserInfo
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *Name;
    QToolButton *AccountInfoTBtn;
    QFrame *line;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *WorkNumber;
    QLabel *label_5;
    QLabel *Phone;
    QLabel *label_6;
    QLabel *Project;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QToolButton *ReturnTBtn;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *UserInfo)
    {
        if (UserInfo->objectName().isEmpty())
            UserInfo->setObjectName(QStringLiteral("UserInfo"));
        UserInfo->resize(437, 222);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        UserInfo->setPalette(palette);
        UserInfo->setSizeGripEnabled(false);
        UserInfo->setModal(false);
        verticalLayout_2 = new QVBoxLayout(UserInfo);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Name = new QLabel(UserInfo);
        Name->setObjectName(QStringLiteral("Name"));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(20);
        Name->setFont(font);

        verticalLayout->addWidget(Name);


        horizontalLayout_2->addLayout(verticalLayout);

        AccountInfoTBtn = new QToolButton(UserInfo);
        AccountInfoTBtn->setObjectName(QStringLiteral("AccountInfoTBtn"));
        AccountInfoTBtn->setMinimumSize(QSize(60, 60));
        AccountInfoTBtn->setMaximumSize(QSize(60, 60));
        AccountInfoTBtn->setAutoFillBackground(false);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Mainwindow/Resources/UrielQtFramework/circle.png"), QSize(), QIcon::Normal, QIcon::Off);
        AccountInfoTBtn->setIcon(icon);
        AccountInfoTBtn->setIconSize(QSize(60, 60));
        AccountInfoTBtn->setAutoRaise(true);

        horizontalLayout_2->addWidget(AccountInfoTBtn);


        verticalLayout_2->addLayout(horizontalLayout_2);

        line = new QFrame(UserInfo);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(UserInfo);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(14);
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        WorkNumber = new QLabel(UserInfo);
        WorkNumber->setObjectName(QStringLiteral("WorkNumber"));
        WorkNumber->setFont(font1);

        gridLayout->addWidget(WorkNumber, 0, 1, 1, 1);

        label_5 = new QLabel(UserInfo);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font1);

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        Phone = new QLabel(UserInfo);
        Phone->setObjectName(QStringLiteral("Phone"));
        Phone->setFont(font1);

        gridLayout->addWidget(Phone, 1, 1, 1, 1);

        label_6 = new QLabel(UserInfo);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font1);

        gridLayout->addWidget(label_6, 2, 0, 1, 1);

        Project = new QLabel(UserInfo);
        Project->setObjectName(QStringLiteral("Project"));
        Project->setFont(font1);

        gridLayout->addWidget(Project, 2, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        ReturnTBtn = new QToolButton(UserInfo);
        ReturnTBtn->setObjectName(QStringLiteral("ReturnTBtn"));
        ReturnTBtn->setMinimumSize(QSize(100, 35));
        ReturnTBtn->setMaximumSize(QSize(100, 35));
        QPalette palette1;
        QBrush brush1(QColor(170, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        ReturnTBtn->setPalette(palette1);
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(12);
        ReturnTBtn->setFont(font2);
        ReturnTBtn->setAutoFillBackground(true);
        ReturnTBtn->setAutoRaise(true);

        horizontalLayout->addWidget(ReturnTBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(UserInfo);

        QMetaObject::connectSlotsByName(UserInfo);
    } // setupUi

    void retranslateUi(QDialog *UserInfo)
    {
        UserInfo->setWindowTitle(QApplication::translate("UserInfo", "UserInfo", Q_NULLPTR));
        Name->setText(QApplication::translate("UserInfo", "\345\220\264\346\231\257", Q_NULLPTR));
        AccountInfoTBtn->setText(QString());
        label_2->setText(QApplication::translate("UserInfo", "\345\255\246\345\217\267\357\274\232", Q_NULLPTR));
        WorkNumber->setText(QApplication::translate("UserInfo", "21525201", Q_NULLPTR));
        label_5->setText(QApplication::translate("UserInfo", "\347\224\265\350\257\235\357\274\232", Q_NULLPTR));
        Phone->setText(QApplication::translate("UserInfo", "18100177919", Q_NULLPTR));
        label_6->setText(QApplication::translate("UserInfo", "\351\241\271\347\233\256\357\274\232", Q_NULLPTR));
        Project->setText(QApplication::translate("UserInfo", "\345\237\272\344\272\216\346\234\272\345\231\250\350\247\206\350\247\211\347\232\204\350\275\264\346\211\277\346\273\232\345\255\220\350\241\250\351\235\242\346\243\200\346\265\213\347\263\273\347\273\237", Q_NULLPTR));
        ReturnTBtn->setText(QApplication::translate("UserInfo", "\350\277\224\345\233\236", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UserInfo: public Ui_UserInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINFO_H
