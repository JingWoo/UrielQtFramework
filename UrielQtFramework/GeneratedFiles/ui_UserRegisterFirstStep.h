/********************************************************************************
** Form generated from reading UI file 'UserRegisterFirstStep.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERREGISTERFIRSTSTEP_H
#define UI_USERREGISTERFIRSTSTEP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_UserRegisterFirstStep
{
public:
    QToolButton *RegisterNewAccount;
    QLabel *label;
    QLabel *label_2;
    QFrame *frame;
    QToolButton *AppClose;

    void setupUi(QDialog *UserRegisterFirstStep)
    {
        if (UserRegisterFirstStep->objectName().isEmpty())
            UserRegisterFirstStep->setObjectName(QStringLiteral("UserRegisterFirstStep"));
        UserRegisterFirstStep->resize(698, 427);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        UserRegisterFirstStep->setPalette(palette);
        QFont font;
        font.setPointSize(22);
        font.setUnderline(false);
        UserRegisterFirstStep->setFont(font);
        RegisterNewAccount = new QToolButton(UserRegisterFirstStep);
        RegisterNewAccount->setObjectName(QStringLiteral("RegisterNewAccount"));
        RegisterNewAccount->setGeometry(QRect(260, 310, 191, 51));
        QPalette palette1;
        QBrush brush1(QColor(64, 167, 227, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        RegisterNewAccount->setPalette(palette1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        RegisterNewAccount->setFont(font1);
        RegisterNewAccount->setAutoFillBackground(true);
        RegisterNewAccount->setAutoRaise(true);
        label = new QLabel(UserRegisterFirstStep);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 20, 701, 181));
        label->setPixmap(QPixmap(QString::fromUtf8(":/UserRegister/Resources/UserRegister/bluebackground.jpg")));
        label->setScaledContents(true);
        label_2 = new QLabel(UserRegisterFirstStep);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 230, 511, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(22);
        font2.setUnderline(false);
        label_2->setFont(font2);
        frame = new QFrame(UserRegisterFirstStep);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 701, 21));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush3(QColor(241, 241, 241, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        frame->setPalette(palette2);
        frame->setAutoFillBackground(true);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        AppClose = new QToolButton(frame);
        AppClose->setObjectName(QStringLiteral("AppClose"));
        AppClose->setGeometry(QRect(680, 0, 21, 21));
        QIcon icon;
        icon.addFile(QStringLiteral(":/UserRegister/Resources/UserRegister/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        AppClose->setIcon(icon);
        AppClose->setAutoRaise(true);

        retranslateUi(UserRegisterFirstStep);

        QMetaObject::connectSlotsByName(UserRegisterFirstStep);
    } // setupUi

    void retranslateUi(QDialog *UserRegisterFirstStep)
    {
        UserRegisterFirstStep->setWindowTitle(QApplication::translate("UserRegisterFirstStep", "UserRegisterFirstStep", Q_NULLPTR));
        RegisterNewAccount->setText(QApplication::translate("UserRegisterFirstStep", "\346\226\260\347\224\250\346\210\267\346\263\250\345\206\214", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QApplication::translate("UserRegisterFirstStep", "\346\265\231\346\261\237\345\244\247\345\255\246\347\262\276\345\257\206\345\276\256\347\272\263\346\265\213\351\207\217\345\256\236\351\252\214\345\256\244\347\256\241\347\220\206\347\263\273\347\273\237", Q_NULLPTR));
        AppClose->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class UserRegisterFirstStep: public Ui_UserRegisterFirstStep {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERREGISTERFIRSTSTEP_H
