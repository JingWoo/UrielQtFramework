/********************************************************************************
** Form generated from reading UI file 'UserRegisterThirdStep.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERREGISTERTHIRDSTEP_H
#define UI_USERREGISTERTHIRDSTEP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserRegisterThirdStep
{
public:
    QFrame *frame;
    QToolButton *AppClose;
    QLabel *label;
    QToolButton *PasswordShow;
    QToolButton *RepeatShow;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *Password;
    QFrame *line;
    QLabel *label_8;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *Repeat;
    QFrame *line_2;
    QToolButton *NextStep;
    QLabel *ErrorInfo;

    void setupUi(QDialog *UserRegisterThirdStep)
    {
        if (UserRegisterThirdStep->objectName().isEmpty())
            UserRegisterThirdStep->setObjectName(QStringLiteral("UserRegisterThirdStep"));
        UserRegisterThirdStep->resize(702, 427);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        UserRegisterThirdStep->setPalette(palette);
        frame = new QFrame(UserRegisterThirdStep);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 701, 21));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(64, 167, 227, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        QLinearGradient gradient(0, 0, 0.755682, 0.864);
        gradient.setSpread(QGradient::PadSpread);
        gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient.setColorAt(0, QColor(0, 195, 195, 255));
        gradient.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush2(gradient);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QLinearGradient gradient1(0, 0, 0.755682, 0.864);
        gradient1.setSpread(QGradient::PadSpread);
        gradient1.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient1.setColorAt(0, QColor(0, 195, 195, 255));
        gradient1.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush3(gradient1);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QLinearGradient gradient2(0, 0, 0.755682, 0.864);
        gradient2.setSpread(QGradient::PadSpread);
        gradient2.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient2.setColorAt(0, QColor(0, 195, 195, 255));
        gradient2.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush4(gradient2);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush4);
        frame->setPalette(palette1);
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
        label = new QLabel(UserRegisterThirdStep);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 120, 141, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(24);
        label->setFont(font);
        PasswordShow = new QToolButton(UserRegisterThirdStep);
        PasswordShow->setObjectName(QStringLiteral("PasswordShow"));
        PasswordShow->setGeometry(QRect(540, 180, 31, 31));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/UserRegister/Resources/UserRegister/eye.png"), QSize(), QIcon::Normal, QIcon::Off);
        PasswordShow->setIcon(icon1);
        PasswordShow->setIconSize(QSize(24, 24));
        PasswordShow->setAutoRaise(true);
        RepeatShow = new QToolButton(UserRegisterThirdStep);
        RepeatShow->setObjectName(QStringLiteral("RepeatShow"));
        RepeatShow->setGeometry(QRect(540, 220, 31, 31));
        RepeatShow->setIcon(icon1);
        RepeatShow->setIconSize(QSize(24, 24));
        RepeatShow->setAutoRaise(true);
        layoutWidget = new QWidget(UserRegisterThirdStep);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(160, 180, 371, 70));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(14);
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Password = new QLineEdit(layoutWidget);
        Password->setObjectName(QStringLiteral("Password"));
        Password->setFont(font1);
        Password->setAutoFillBackground(false);
        Password->setFrame(false);
        Password->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(Password);

        line = new QFrame(layoutWidget);
        line->setObjectName(QStringLiteral("line"));
        QPalette palette2;
        QBrush brush5(QColor(85, 255, 255, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush6(QColor(85, 170, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush6);
        QLinearGradient gradient3(0, 0, 0.755682, 0.864);
        gradient3.setSpread(QGradient::PadSpread);
        gradient3.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient3.setColorAt(0, QColor(0, 195, 195, 255));
        gradient3.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush7(gradient3);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        QLinearGradient gradient4(0, 0, 0.755682, 0.864);
        gradient4.setSpread(QGradient::PadSpread);
        gradient4.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient4.setColorAt(0, QColor(0, 195, 195, 255));
        gradient4.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush8(gradient4);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        QLinearGradient gradient5(0, 0, 0.755682, 0.864);
        gradient5.setSpread(QGradient::PadSpread);
        gradient5.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient5.setColorAt(0, QColor(0, 195, 195, 255));
        gradient5.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush9(gradient5);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        line->setPalette(palette2);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font1);

        gridLayout->addWidget(label_8, 1, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        Repeat = new QLineEdit(layoutWidget);
        Repeat->setObjectName(QStringLiteral("Repeat"));
        Repeat->setFont(font1);
        Repeat->setFrame(false);
        Repeat->setEchoMode(QLineEdit::Password);

        verticalLayout_2->addWidget(Repeat);

        line_2 = new QFrame(layoutWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush6);
        QLinearGradient gradient6(0, 0, 0.755682, 0.864);
        gradient6.setSpread(QGradient::PadSpread);
        gradient6.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient6.setColorAt(0, QColor(0, 195, 195, 255));
        gradient6.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush10(gradient6);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush10);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        QLinearGradient gradient7(0, 0, 0.755682, 0.864);
        gradient7.setSpread(QGradient::PadSpread);
        gradient7.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient7.setColorAt(0, QColor(0, 195, 195, 255));
        gradient7.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush11(gradient7);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush11);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        QLinearGradient gradient8(0, 0, 0.755682, 0.864);
        gradient8.setSpread(QGradient::PadSpread);
        gradient8.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient8.setColorAt(0, QColor(0, 195, 195, 255));
        gradient8.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush12(gradient8);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush12);
        line_2->setPalette(palette3);
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);


        gridLayout->addLayout(verticalLayout_2, 1, 1, 1, 1);

        NextStep = new QToolButton(UserRegisterThirdStep);
        NextStep->setObjectName(QStringLiteral("NextStep"));
        NextStep->setGeometry(QRect(250, 310, 191, 51));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush1);
        QLinearGradient gradient9(0, 0, 0.755682, 0.864);
        gradient9.setSpread(QGradient::PadSpread);
        gradient9.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient9.setColorAt(0, QColor(0, 195, 195, 255));
        gradient9.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush13(gradient9);
        palette4.setBrush(QPalette::Active, QPalette::AlternateBase, brush13);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QLinearGradient gradient10(0, 0, 0.755682, 0.864);
        gradient10.setSpread(QGradient::PadSpread);
        gradient10.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient10.setColorAt(0, QColor(0, 195, 195, 255));
        gradient10.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush14(gradient10);
        palette4.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush14);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        QBrush brush15(QColor(120, 120, 120, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush15);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QLinearGradient gradient11(0, 0, 0.755682, 0.864);
        gradient11.setSpread(QGradient::PadSpread);
        gradient11.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient11.setColorAt(0, QColor(0, 195, 195, 255));
        gradient11.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush16(gradient11);
        palette4.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush16);
        NextStep->setPalette(palette4);
        NextStep->setFont(font);
        NextStep->setAutoFillBackground(true);
        NextStep->setAutoRaise(true);
        ErrorInfo = new QLabel(UserRegisterThirdStep);
        ErrorInfo->setObjectName(QStringLiteral("ErrorInfo"));
        ErrorInfo->setGeometry(QRect(220, 270, 251, 16));
        QPalette palette5;
        QBrush brush17(QColor(255, 0, 0, 255));
        brush17.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush17);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush17);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush17);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush17);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush15);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush15);
        ErrorInfo->setPalette(palette5);
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(12);
        ErrorInfo->setFont(font2);

        retranslateUi(UserRegisterThirdStep);

        QMetaObject::connectSlotsByName(UserRegisterThirdStep);
    } // setupUi

    void retranslateUi(QDialog *UserRegisterThirdStep)
    {
        UserRegisterThirdStep->setWindowTitle(QApplication::translate("UserRegisterThirdStep", "UserRegisterThirdStep", Q_NULLPTR));
        AppClose->setText(QString());
        label->setText(QApplication::translate("UserRegisterThirdStep", "\345\257\206\347\240\201\350\256\276\347\275\256", Q_NULLPTR));
        PasswordShow->setText(QString());
        RepeatShow->setText(QString());
        label_2->setText(QApplication::translate("UserRegisterThirdStep", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        Password->setInputMask(QString());
        label_8->setText(QApplication::translate("UserRegisterThirdStep", "\351\207\215\345\244\215\357\274\232", Q_NULLPTR));
        Repeat->setInputMask(QString());
        NextStep->setText(QApplication::translate("UserRegisterThirdStep", "\344\270\213\344\270\200\346\255\245", Q_NULLPTR));
        ErrorInfo->setText(QApplication::translate("UserRegisterThirdStep", "\345\257\206\347\240\201\344\270\215\344\270\200\350\207\264\357\274\201\351\207\215\346\226\260\350\276\223\345\205\245...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UserRegisterThirdStep: public Ui_UserRegisterThirdStep {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERREGISTERTHIRDSTEP_H
