/********************************************************************************
** Form generated from reading UI file 'Login.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLabel *label_2;
    QLabel *label_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QToolButton *ConfirmLogin;
    QLabel *label_4;
    QLineEdit *Password;
    QCheckBox *RememberPassword;
    QCheckBox *AutoLogin;
    QLineEdit *Account;
    QLabel *label;
    QLabel *label_5;
    QLabel *HeadIco;
    QToolButton *RegisterAccount;
    QToolButton *FindPassword;
    QToolButton *AppClose;
    QLabel *LoginError;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(584, 297);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        Login->setPalette(palette);
        label_2 = new QLabel(Login);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 20, 521, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(22);
        label_2->setFont(font);
        label_3 = new QLabel(Login);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 180, 231, 81));
        label_3->setAutoFillBackground(true);
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/Login/Resources/Login/zhejianguniversity.png")));
        groupBox = new QGroupBox(Login);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(280, 90, 267, 159));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(14);
        groupBox->setFont(font1);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        ConfirmLogin = new QToolButton(groupBox);
        ConfirmLogin->setObjectName(QStringLiteral("ConfirmLogin"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ConfirmLogin->sizePolicy().hasHeightForWidth());
        ConfirmLogin->setSizePolicy(sizePolicy);
        QPalette palette1;
        QBrush brush1(QColor(216, 241, 241, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        ConfirmLogin->setPalette(palette1);
        ConfirmLogin->setAutoFillBackground(true);
        ConfirmLogin->setAutoRaise(true);

        gridLayout->addWidget(ConfirmLogin, 3, 0, 1, 3);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        Password = new QLineEdit(groupBox);
        Password->setObjectName(QStringLiteral("Password"));
        Password->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(Password, 1, 1, 1, 2);

        RememberPassword = new QCheckBox(groupBox);
        RememberPassword->setObjectName(QStringLiteral("RememberPassword"));

        gridLayout->addWidget(RememberPassword, 2, 0, 1, 2);

        AutoLogin = new QCheckBox(groupBox);
        AutoLogin->setObjectName(QStringLiteral("AutoLogin"));

        gridLayout->addWidget(AutoLogin, 2, 2, 1, 1);

        Account = new QLineEdit(groupBox);
        Account->setObjectName(QStringLiteral("Account"));

        gridLayout->addWidget(Account, 0, 1, 1, 2);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font1);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_5 = new QLabel(Login);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(290, 80, 41, 41));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/Login/Resources/Login/key.png")));
        label_5->setScaledContents(true);
        HeadIco = new QLabel(Login);
        HeadIco->setObjectName(QStringLiteral("HeadIco"));
        HeadIco->setGeometry(QRect(110, 80, 91, 91));
        HeadIco->setPixmap(QPixmap(QString::fromUtf8(":/Login/Resources/Login/HeadIco.png")));
        HeadIco->setScaledContents(true);
        RegisterAccount = new QToolButton(Login);
        RegisterAccount->setObjectName(QStringLiteral("RegisterAccount"));
        RegisterAccount->setGeometry(QRect(310, 260, 91, 18));
        QPalette palette2;
        QBrush brush2(QColor(26, 26, 26, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        QBrush brush3(QColor(120, 120, 120, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        RegisterAccount->setPalette(palette2);
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        RegisterAccount->setFont(font2);
        RegisterAccount->setAutoRaise(true);
        FindPassword = new QToolButton(Login);
        FindPassword->setObjectName(QStringLiteral("FindPassword"));
        FindPassword->setGeometry(QRect(420, 260, 91, 18));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        FindPassword->setPalette(palette3);
        FindPassword->setFont(font2);
        FindPassword->setAutoRaise(true);
        AppClose = new QToolButton(Login);
        AppClose->setObjectName(QStringLiteral("AppClose"));
        AppClose->setGeometry(QRect(566, 0, 21, 20));
        AppClose->setAutoFillBackground(false);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Login/Resources/Login/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        AppClose->setIcon(icon);
        AppClose->setAutoRaise(true);
        LoginError = new QLabel(Login);
        LoginError->setObjectName(QStringLiteral("LoginError"));
        LoginError->setGeometry(QRect(293, 66, 251, 16));
        QPalette palette4;
        QBrush brush4(QColor(255, 0, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        LoginError->setPalette(palette4);
        QFont font3;
        font3.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font3.setPointSize(12);
        LoginError->setFont(font3);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Login", Q_NULLPTR));
        label_2->setText(QApplication::translate("Login", "\346\265\231\346\261\237\345\244\247\345\255\246\347\262\276\345\257\206\345\276\256\347\272\263\346\265\213\351\207\217\345\256\236\351\252\214\345\256\244\347\256\241\347\220\206\347\263\273\347\273\237", Q_NULLPTR));
        label_3->setText(QString());
        groupBox->setTitle(QApplication::translate("Login", "    \347\224\250\346\210\267\347\231\273\345\275\225", Q_NULLPTR));
        ConfirmLogin->setText(QApplication::translate("Login", "\347\231\273\345\275\225", Q_NULLPTR));
        label_4->setText(QApplication::translate("Login", "\345\257\206\347\240\201", Q_NULLPTR));
        RememberPassword->setText(QApplication::translate("Login", "\350\256\260\344\275\217\345\257\206\347\240\201", Q_NULLPTR));
        AutoLogin->setText(QApplication::translate("Login", "\350\207\252\345\212\250\347\231\273\345\275\225", Q_NULLPTR));
        label->setText(QApplication::translate("Login", "\350\264\246\345\217\267", Q_NULLPTR));
        label_5->setText(QString());
        HeadIco->setText(QString());
        RegisterAccount->setText(QApplication::translate("Login", "\346\263\250\345\206\214\350\264\246\345\217\267", Q_NULLPTR));
        FindPassword->setText(QApplication::translate("Login", "\346\211\276\345\233\236\345\257\206\347\240\201", Q_NULLPTR));
        AppClose->setText(QString());
        LoginError->setText(QApplication::translate("Login", "\345\257\206\347\240\201\351\224\231\350\257\257\357\274\201\351\207\215\346\226\260\350\276\223\345\205\245...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
