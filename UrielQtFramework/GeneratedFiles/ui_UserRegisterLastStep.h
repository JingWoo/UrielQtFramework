/********************************************************************************
** Form generated from reading UI file 'UserRegisterLastStep.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERREGISTERLASTSTEP_H
#define UI_USERREGISTERLASTSTEP_H

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

class Ui_UserRegisterLastStep
{
public:
    QToolButton *Finish;
    QFrame *frame;
    QToolButton *AppClose;
    QLabel *label;

    void setupUi(QDialog *UserRegisterLastStep)
    {
        if (UserRegisterLastStep->objectName().isEmpty())
            UserRegisterLastStep->setObjectName(QStringLiteral("UserRegisterLastStep"));
        UserRegisterLastStep->resize(702, 427);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        UserRegisterLastStep->setPalette(palette);
        Finish = new QToolButton(UserRegisterLastStep);
        Finish->setObjectName(QStringLiteral("Finish"));
        Finish->setGeometry(QRect(240, 270, 191, 51));
        QPalette palette1;
        QBrush brush1(QColor(64, 167, 227, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        QLinearGradient gradient(0, 0, 0.755682, 0.864);
        gradient.setSpread(QGradient::PadSpread);
        gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient.setColorAt(0, QColor(0, 195, 195, 255));
        gradient.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush2(gradient);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QLinearGradient gradient1(0, 0, 0.755682, 0.864);
        gradient1.setSpread(QGradient::PadSpread);
        gradient1.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient1.setColorAt(0, QColor(0, 195, 195, 255));
        gradient1.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush3(gradient1);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        QBrush brush4(QColor(120, 120, 120, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QLinearGradient gradient2(0, 0, 0.755682, 0.864);
        gradient2.setSpread(QGradient::PadSpread);
        gradient2.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient2.setColorAt(0, QColor(0, 195, 195, 255));
        gradient2.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush5(gradient2);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush5);
        Finish->setPalette(palette1);
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(24);
        Finish->setFont(font);
        Finish->setAutoFillBackground(true);
        Finish->setAutoRaise(true);
        frame = new QFrame(UserRegisterLastStep);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 701, 21));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Base, brush);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        QLinearGradient gradient3(0, 0, 0.755682, 0.864);
        gradient3.setSpread(QGradient::PadSpread);
        gradient3.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient3.setColorAt(0, QColor(0, 195, 195, 255));
        gradient3.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush6(gradient3);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QLinearGradient gradient4(0, 0, 0.755682, 0.864);
        gradient4.setSpread(QGradient::PadSpread);
        gradient4.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient4.setColorAt(0, QColor(0, 195, 195, 255));
        gradient4.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush7(gradient4);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QLinearGradient gradient5(0, 0, 0.755682, 0.864);
        gradient5.setSpread(QGradient::PadSpread);
        gradient5.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient5.setColorAt(0, QColor(0, 195, 195, 255));
        gradient5.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush8(gradient5);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush8);
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
        label = new QLabel(UserRegisterLastStep);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 150, 601, 31));
        QPalette palette3;
        QBrush brush9(QColor(255, 0, 0, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        QBrush brush10(QColor(0, 0, 0, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush10);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush10);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        label->setPalette(palette3);
        label->setFont(font);

        retranslateUi(UserRegisterLastStep);

        QMetaObject::connectSlotsByName(UserRegisterLastStep);
    } // setupUi

    void retranslateUi(QDialog *UserRegisterLastStep)
    {
        UserRegisterLastStep->setWindowTitle(QApplication::translate("UserRegisterLastStep", "UserRegisterLastStep", Q_NULLPTR));
        Finish->setText(QApplication::translate("UserRegisterLastStep", "\345\256\214\346\210\220", Q_NULLPTR));
        AppClose->setText(QString());
        label->setText(QApplication::translate("UserRegisterLastStep", "\350\257\267\351\235\231\345\277\203\347\255\211\345\276\205\346\210\226\350\201\224\347\263\273\345\256\236\351\252\214\345\256\244\347\256\241\347\220\206\345\221\230\351\200\232\350\277\207\351\252\214\350\257\201\357\274\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UserRegisterLastStep: public Ui_UserRegisterLastStep {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERREGISTERLASTSTEP_H
