/********************************************************************************
** Form generated from reading UI file 'UserRegisterSecondStep.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERREGISTERSECONDSTEP_H
#define UI_USERREGISTERSECONDSTEP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
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

class Ui_UserRegisterSecondStep
{
public:
    QFrame *frame;
    QToolButton *AppClose;
    QLabel *label;
    QToolButton *NextStep;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *Name;
    QFrame *line;
    QLabel *namelabel;
    QLabel *label_8;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *ID;
    QFrame *line_2;
    QLabel *idlabel;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *Phone;
    QFrame *line_3;
    QLabel *phonelabel;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *Email;
    QFrame *line_4;
    QLabel *emaillabel;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QLabel *label_7;
    QLabel *banklabel;
    QLabel *label_9;
    QVBoxLayout *verticalLayout_6;
    QLineEdit *BankNumber;
    QFrame *line_6;
    QLabel *banknumberlabel;
    QLabel *label_10;
    QVBoxLayout *verticalLayout_7;
    QLineEdit *Project;
    QFrame *line_7;
    QLabel *projectlabel;
    QVBoxLayout *verticalLayout_12;
    QComboBox *BankType;
    QFrame *line_5;

    void setupUi(QDialog *UserRegisterSecondStep)
    {
        if (UserRegisterSecondStep->objectName().isEmpty())
            UserRegisterSecondStep->setObjectName(QStringLiteral("UserRegisterSecondStep"));
        UserRegisterSecondStep->resize(702, 427);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        QLinearGradient gradient(0, 0, 0.755682, 0.864);
        gradient.setSpread(QGradient::PadSpread);
        gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient.setColorAt(0, QColor(0, 195, 195, 255));
        gradient.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush1(gradient);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        QLinearGradient gradient1(0, 0, 0.755682, 0.864);
        gradient1.setSpread(QGradient::PadSpread);
        gradient1.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient1.setColorAt(0, QColor(0, 195, 195, 255));
        gradient1.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush2(gradient1);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        QLinearGradient gradient2(0, 0, 0.755682, 0.864);
        gradient2.setSpread(QGradient::PadSpread);
        gradient2.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient2.setColorAt(0, QColor(0, 195, 195, 255));
        gradient2.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush3(gradient2);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush3);
        UserRegisterSecondStep->setPalette(palette);
        UserRegisterSecondStep->setStyleSheet(QStringLiteral("alternate-background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0.755682, y2:0.864, stop:0 rgba(0, 195, 195, 255), stop:1 rgba(255, 255, 255, 255));"));
        frame = new QFrame(UserRegisterSecondStep);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 703, 21));
        frame->setMinimumSize(QSize(703, 0));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush4(QColor(64, 167, 227, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush4);
        QLinearGradient gradient3(0, 0, 0.755682, 0.864);
        gradient3.setSpread(QGradient::PadSpread);
        gradient3.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient3.setColorAt(0, QColor(0, 195, 195, 255));
        gradient3.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush5(gradient3);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush4);
        QLinearGradient gradient4(0, 0, 0.755682, 0.864);
        gradient4.setSpread(QGradient::PadSpread);
        gradient4.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient4.setColorAt(0, QColor(0, 195, 195, 255));
        gradient4.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush6(gradient4);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush4);
        QLinearGradient gradient5(0, 0, 0.755682, 0.864);
        gradient5.setSpread(QGradient::PadSpread);
        gradient5.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient5.setColorAt(0, QColor(0, 195, 195, 255));
        gradient5.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush7(gradient5);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush7);
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
        label = new QLabel(UserRegisterSecondStep);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 30, 331, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(24);
        label->setFont(font);
        NextStep = new QToolButton(UserRegisterSecondStep);
        NextStep->setObjectName(QStringLiteral("NextStep"));
        NextStep->setGeometry(QRect(260, 350, 191, 51));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush4);
        QLinearGradient gradient6(0, 0, 0.755682, 0.864);
        gradient6.setSpread(QGradient::PadSpread);
        gradient6.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient6.setColorAt(0, QColor(0, 195, 195, 255));
        gradient6.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush8(gradient6);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush8);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush4);
        QLinearGradient gradient7(0, 0, 0.755682, 0.864);
        gradient7.setSpread(QGradient::PadSpread);
        gradient7.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient7.setColorAt(0, QColor(0, 195, 195, 255));
        gradient7.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush9(gradient7);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush9);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        QBrush brush10(QColor(120, 120, 120, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush10);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush4);
        QLinearGradient gradient8(0, 0, 0.755682, 0.864);
        gradient8.setSpread(QGradient::PadSpread);
        gradient8.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient8.setColorAt(0, QColor(0, 195, 195, 255));
        gradient8.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush11(gradient8);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush11);
        NextStep->setPalette(palette2);
        NextStep->setFont(font);
        NextStep->setAutoFillBackground(true);
        NextStep->setAutoRaise(true);
        layoutWidget = new QWidget(UserRegisterSecondStep);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(160, 70, 401, 151));
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
        Name = new QLineEdit(layoutWidget);
        Name->setObjectName(QStringLiteral("Name"));
        Name->setFont(font1);
        Name->setAutoFillBackground(false);
        Name->setFrame(false);

        verticalLayout->addWidget(Name);

        line = new QFrame(layoutWidget);
        line->setObjectName(QStringLiteral("line"));
        QPalette palette3;
        QBrush brush12(QColor(85, 255, 255, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush12);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush13(QColor(85, 170, 255, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush13);
        QLinearGradient gradient9(0, 0, 0.755682, 0.864);
        gradient9.setSpread(QGradient::PadSpread);
        gradient9.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient9.setColorAt(0, QColor(0, 195, 195, 255));
        gradient9.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush14(gradient9);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush14);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush12);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush13);
        QLinearGradient gradient10(0, 0, 0.755682, 0.864);
        gradient10.setSpread(QGradient::PadSpread);
        gradient10.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient10.setColorAt(0, QColor(0, 195, 195, 255));
        gradient10.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush15(gradient10);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush15);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush12);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush13);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush13);
        QLinearGradient gradient11(0, 0, 0.755682, 0.864);
        gradient11.setSpread(QGradient::PadSpread);
        gradient11.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient11.setColorAt(0, QColor(0, 195, 195, 255));
        gradient11.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush16(gradient11);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush16);
        line->setPalette(palette3);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        namelabel = new QLabel(layoutWidget);
        namelabel->setObjectName(QStringLiteral("namelabel"));
        namelabel->setMaximumSize(QSize(20, 20));
        QPalette palette4;
        QLinearGradient gradient12(0, 0, 0.755682, 0.864);
        gradient12.setSpread(QGradient::PadSpread);
        gradient12.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient12.setColorAt(0, QColor(0, 195, 195, 255));
        gradient12.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush17(gradient12);
        palette4.setBrush(QPalette::Active, QPalette::AlternateBase, brush17);
        QLinearGradient gradient13(0, 0, 0.755682, 0.864);
        gradient13.setSpread(QGradient::PadSpread);
        gradient13.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient13.setColorAt(0, QColor(0, 195, 195, 255));
        gradient13.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush18(gradient13);
        palette4.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush18);
        QLinearGradient gradient14(0, 0, 0.755682, 0.864);
        gradient14.setSpread(QGradient::PadSpread);
        gradient14.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient14.setColorAt(0, QColor(0, 195, 195, 255));
        gradient14.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush19(gradient14);
        palette4.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush19);
        namelabel->setPalette(palette4);
        QFont font2;
        font2.setFamily(QStringLiteral("3ds"));
        font2.setPointSize(14);
        namelabel->setFont(font2);
        namelabel->setAutoFillBackground(true);
        namelabel->setPixmap(QPixmap(QString::fromUtf8(":/UserRegister/Resources/UserRegister/mustfill.png")));
        namelabel->setScaledContents(true);

        gridLayout->addWidget(namelabel, 0, 2, 1, 1);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font1);

        gridLayout->addWidget(label_8, 1, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        ID = new QLineEdit(layoutWidget);
        ID->setObjectName(QStringLiteral("ID"));
        ID->setFont(font1);
        ID->setFrame(false);

        verticalLayout_2->addWidget(ID);

        line_2 = new QFrame(layoutWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Button, brush12);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush13);
        QLinearGradient gradient15(0, 0, 0.755682, 0.864);
        gradient15.setSpread(QGradient::PadSpread);
        gradient15.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient15.setColorAt(0, QColor(0, 195, 195, 255));
        gradient15.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush20(gradient15);
        palette5.setBrush(QPalette::Active, QPalette::AlternateBase, brush20);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush12);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush13);
        QLinearGradient gradient16(0, 0, 0.755682, 0.864);
        gradient16.setSpread(QGradient::PadSpread);
        gradient16.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient16.setColorAt(0, QColor(0, 195, 195, 255));
        gradient16.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush21(gradient16);
        palette5.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush21);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush12);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush13);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush13);
        QLinearGradient gradient17(0, 0, 0.755682, 0.864);
        gradient17.setSpread(QGradient::PadSpread);
        gradient17.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient17.setColorAt(0, QColor(0, 195, 195, 255));
        gradient17.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush22(gradient17);
        palette5.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush22);
        line_2->setPalette(palette5);
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);


        gridLayout->addLayout(verticalLayout_2, 1, 1, 1, 1);

        idlabel = new QLabel(layoutWidget);
        idlabel->setObjectName(QStringLiteral("idlabel"));
        idlabel->setMaximumSize(QSize(20, 20));
        QPalette palette6;
        QLinearGradient gradient18(0, 0, 0.755682, 0.864);
        gradient18.setSpread(QGradient::PadSpread);
        gradient18.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient18.setColorAt(0, QColor(0, 195, 195, 255));
        gradient18.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush23(gradient18);
        palette6.setBrush(QPalette::Active, QPalette::AlternateBase, brush23);
        QLinearGradient gradient19(0, 0, 0.755682, 0.864);
        gradient19.setSpread(QGradient::PadSpread);
        gradient19.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient19.setColorAt(0, QColor(0, 195, 195, 255));
        gradient19.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush24(gradient19);
        palette6.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush24);
        QLinearGradient gradient20(0, 0, 0.755682, 0.864);
        gradient20.setSpread(QGradient::PadSpread);
        gradient20.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient20.setColorAt(0, QColor(0, 195, 195, 255));
        gradient20.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush25(gradient20);
        palette6.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush25);
        idlabel->setPalette(palette6);
        idlabel->setFont(font2);
        idlabel->setAutoFillBackground(true);
        idlabel->setPixmap(QPixmap(QString::fromUtf8(":/UserRegister/Resources/UserRegister/mustfill.png")));
        idlabel->setScaledContents(true);

        gridLayout->addWidget(idlabel, 1, 2, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        Phone = new QLineEdit(layoutWidget);
        Phone->setObjectName(QStringLiteral("Phone"));
        Phone->setFont(font1);
        Phone->setFrame(false);

        verticalLayout_3->addWidget(Phone);

        line_3 = new QFrame(layoutWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::Button, brush12);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush13);
        QLinearGradient gradient21(0, 0, 0.755682, 0.864);
        gradient21.setSpread(QGradient::PadSpread);
        gradient21.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient21.setColorAt(0, QColor(0, 195, 195, 255));
        gradient21.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush26(gradient21);
        palette7.setBrush(QPalette::Active, QPalette::AlternateBase, brush26);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush12);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush13);
        QLinearGradient gradient22(0, 0, 0.755682, 0.864);
        gradient22.setSpread(QGradient::PadSpread);
        gradient22.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient22.setColorAt(0, QColor(0, 195, 195, 255));
        gradient22.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush27(gradient22);
        palette7.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush27);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush12);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush13);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush13);
        QLinearGradient gradient23(0, 0, 0.755682, 0.864);
        gradient23.setSpread(QGradient::PadSpread);
        gradient23.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient23.setColorAt(0, QColor(0, 195, 195, 255));
        gradient23.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush28(gradient23);
        palette7.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush28);
        line_3->setPalette(palette7);
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_3);


        gridLayout->addLayout(verticalLayout_3, 2, 1, 1, 1);

        phonelabel = new QLabel(layoutWidget);
        phonelabel->setObjectName(QStringLiteral("phonelabel"));
        phonelabel->setMaximumSize(QSize(20, 20));
        QPalette palette8;
        QLinearGradient gradient24(0, 0, 0.755682, 0.864);
        gradient24.setSpread(QGradient::PadSpread);
        gradient24.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient24.setColorAt(0, QColor(0, 195, 195, 255));
        gradient24.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush29(gradient24);
        palette8.setBrush(QPalette::Active, QPalette::AlternateBase, brush29);
        QLinearGradient gradient25(0, 0, 0.755682, 0.864);
        gradient25.setSpread(QGradient::PadSpread);
        gradient25.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient25.setColorAt(0, QColor(0, 195, 195, 255));
        gradient25.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush30(gradient25);
        palette8.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush30);
        QLinearGradient gradient26(0, 0, 0.755682, 0.864);
        gradient26.setSpread(QGradient::PadSpread);
        gradient26.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient26.setColorAt(0, QColor(0, 195, 195, 255));
        gradient26.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush31(gradient26);
        palette8.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush31);
        phonelabel->setPalette(palette8);
        phonelabel->setFont(font2);
        phonelabel->setAutoFillBackground(true);
        phonelabel->setPixmap(QPixmap(QString::fromUtf8(":/UserRegister/Resources/UserRegister/mustfill.png")));
        phonelabel->setScaledContents(true);

        gridLayout->addWidget(phonelabel, 2, 2, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font1);

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        Email = new QLineEdit(layoutWidget);
        Email->setObjectName(QStringLiteral("Email"));
        Email->setFont(font1);
        Email->setFrame(false);

        verticalLayout_4->addWidget(Email);

        line_4 = new QFrame(layoutWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::Button, brush12);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush);
        palette9.setBrush(QPalette::Active, QPalette::Window, brush13);
        QLinearGradient gradient27(0, 0, 0.755682, 0.864);
        gradient27.setSpread(QGradient::PadSpread);
        gradient27.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient27.setColorAt(0, QColor(0, 195, 195, 255));
        gradient27.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush32(gradient27);
        palette9.setBrush(QPalette::Active, QPalette::AlternateBase, brush32);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush12);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Window, brush13);
        QLinearGradient gradient28(0, 0, 0.755682, 0.864);
        gradient28.setSpread(QGradient::PadSpread);
        gradient28.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient28.setColorAt(0, QColor(0, 195, 195, 255));
        gradient28.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush33(gradient28);
        palette9.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush33);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush12);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush13);
        palette9.setBrush(QPalette::Disabled, QPalette::Window, brush13);
        QLinearGradient gradient29(0, 0, 0.755682, 0.864);
        gradient29.setSpread(QGradient::PadSpread);
        gradient29.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient29.setColorAt(0, QColor(0, 195, 195, 255));
        gradient29.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush34(gradient29);
        palette9.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush34);
        line_4->setPalette(palette9);
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_4);


        gridLayout->addLayout(verticalLayout_4, 3, 1, 1, 1);

        emaillabel = new QLabel(layoutWidget);
        emaillabel->setObjectName(QStringLiteral("emaillabel"));
        emaillabel->setMaximumSize(QSize(20, 20));
        QPalette palette10;
        QLinearGradient gradient30(0, 0, 0.755682, 0.864);
        gradient30.setSpread(QGradient::PadSpread);
        gradient30.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient30.setColorAt(0, QColor(0, 195, 195, 255));
        gradient30.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush35(gradient30);
        palette10.setBrush(QPalette::Active, QPalette::AlternateBase, brush35);
        QLinearGradient gradient31(0, 0, 0.755682, 0.864);
        gradient31.setSpread(QGradient::PadSpread);
        gradient31.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient31.setColorAt(0, QColor(0, 195, 195, 255));
        gradient31.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush36(gradient31);
        palette10.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush36);
        QLinearGradient gradient32(0, 0, 0.755682, 0.864);
        gradient32.setSpread(QGradient::PadSpread);
        gradient32.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient32.setColorAt(0, QColor(0, 195, 195, 255));
        gradient32.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush37(gradient32);
        palette10.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush37);
        emaillabel->setPalette(palette10);
        emaillabel->setFont(font2);
        emaillabel->setAutoFillBackground(true);
        emaillabel->setPixmap(QPixmap(QString::fromUtf8(":/UserRegister/Resources/UserRegister/mustfill.png")));
        emaillabel->setScaledContents(true);

        gridLayout->addWidget(emaillabel, 3, 2, 1, 1);

        layoutWidget1 = new QWidget(UserRegisterSecondStep);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(160, 220, 401, 127));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font1);

        gridLayout_2->addWidget(label_7, 0, 0, 1, 1);

        banklabel = new QLabel(layoutWidget1);
        banklabel->setObjectName(QStringLiteral("banklabel"));
        banklabel->setMaximumSize(QSize(20, 20));
        QPalette palette11;
        QLinearGradient gradient33(0, 0, 0.755682, 0.864);
        gradient33.setSpread(QGradient::PadSpread);
        gradient33.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient33.setColorAt(0, QColor(0, 195, 195, 255));
        gradient33.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush38(gradient33);
        palette11.setBrush(QPalette::Active, QPalette::AlternateBase, brush38);
        QLinearGradient gradient34(0, 0, 0.755682, 0.864);
        gradient34.setSpread(QGradient::PadSpread);
        gradient34.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient34.setColorAt(0, QColor(0, 195, 195, 255));
        gradient34.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush39(gradient34);
        palette11.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush39);
        QLinearGradient gradient35(0, 0, 0.755682, 0.864);
        gradient35.setSpread(QGradient::PadSpread);
        gradient35.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient35.setColorAt(0, QColor(0, 195, 195, 255));
        gradient35.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush40(gradient35);
        palette11.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush40);
        banklabel->setPalette(palette11);
        banklabel->setFont(font2);
        banklabel->setAutoFillBackground(true);
        banklabel->setPixmap(QPixmap(QString::fromUtf8(":/UserRegister/Resources/UserRegister/mustfill.png")));
        banklabel->setScaledContents(true);

        gridLayout_2->addWidget(banklabel, 0, 2, 1, 1);

        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font1);

        gridLayout_2->addWidget(label_9, 1, 0, 1, 1);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        BankNumber = new QLineEdit(layoutWidget1);
        BankNumber->setObjectName(QStringLiteral("BankNumber"));
        BankNumber->setFont(font1);
        BankNumber->setFrame(false);

        verticalLayout_6->addWidget(BankNumber);

        line_6 = new QFrame(layoutWidget1);
        line_6->setObjectName(QStringLiteral("line_6"));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::Button, brush12);
        palette12.setBrush(QPalette::Active, QPalette::Base, brush);
        palette12.setBrush(QPalette::Active, QPalette::Window, brush13);
        QLinearGradient gradient36(0, 0, 0.755682, 0.864);
        gradient36.setSpread(QGradient::PadSpread);
        gradient36.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient36.setColorAt(0, QColor(0, 195, 195, 255));
        gradient36.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush41(gradient36);
        palette12.setBrush(QPalette::Active, QPalette::AlternateBase, brush41);
        palette12.setBrush(QPalette::Inactive, QPalette::Button, brush12);
        palette12.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::Window, brush13);
        QLinearGradient gradient37(0, 0, 0.755682, 0.864);
        gradient37.setSpread(QGradient::PadSpread);
        gradient37.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient37.setColorAt(0, QColor(0, 195, 195, 255));
        gradient37.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush42(gradient37);
        palette12.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush42);
        palette12.setBrush(QPalette::Disabled, QPalette::Button, brush12);
        palette12.setBrush(QPalette::Disabled, QPalette::Base, brush13);
        palette12.setBrush(QPalette::Disabled, QPalette::Window, brush13);
        QLinearGradient gradient38(0, 0, 0.755682, 0.864);
        gradient38.setSpread(QGradient::PadSpread);
        gradient38.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient38.setColorAt(0, QColor(0, 195, 195, 255));
        gradient38.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush43(gradient38);
        palette12.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush43);
        line_6->setPalette(palette12);
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        verticalLayout_6->addWidget(line_6);


        gridLayout_2->addLayout(verticalLayout_6, 1, 1, 1, 1);

        banknumberlabel = new QLabel(layoutWidget1);
        banknumberlabel->setObjectName(QStringLiteral("banknumberlabel"));
        banknumberlabel->setMaximumSize(QSize(20, 20));
        QPalette palette13;
        QLinearGradient gradient39(0, 0, 0.755682, 0.864);
        gradient39.setSpread(QGradient::PadSpread);
        gradient39.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient39.setColorAt(0, QColor(0, 195, 195, 255));
        gradient39.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush44(gradient39);
        palette13.setBrush(QPalette::Active, QPalette::AlternateBase, brush44);
        QLinearGradient gradient40(0, 0, 0.755682, 0.864);
        gradient40.setSpread(QGradient::PadSpread);
        gradient40.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient40.setColorAt(0, QColor(0, 195, 195, 255));
        gradient40.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush45(gradient40);
        palette13.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush45);
        QLinearGradient gradient41(0, 0, 0.755682, 0.864);
        gradient41.setSpread(QGradient::PadSpread);
        gradient41.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient41.setColorAt(0, QColor(0, 195, 195, 255));
        gradient41.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush46(gradient41);
        palette13.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush46);
        banknumberlabel->setPalette(palette13);
        banknumberlabel->setFont(font2);
        banknumberlabel->setAutoFillBackground(true);
        banknumberlabel->setPixmap(QPixmap(QString::fromUtf8(":/UserRegister/Resources/UserRegister/mustfill.png")));
        banknumberlabel->setScaledContents(true);

        gridLayout_2->addWidget(banknumberlabel, 1, 2, 1, 1);

        label_10 = new QLabel(layoutWidget1);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font1);

        gridLayout_2->addWidget(label_10, 2, 0, 1, 1);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        Project = new QLineEdit(layoutWidget1);
        Project->setObjectName(QStringLiteral("Project"));
        Project->setFont(font1);
        Project->setFrame(false);

        verticalLayout_7->addWidget(Project);

        line_7 = new QFrame(layoutWidget1);
        line_7->setObjectName(QStringLiteral("line_7"));
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::Button, brush12);
        palette14.setBrush(QPalette::Active, QPalette::Base, brush);
        palette14.setBrush(QPalette::Active, QPalette::Window, brush13);
        QLinearGradient gradient42(0, 0, 0.755682, 0.864);
        gradient42.setSpread(QGradient::PadSpread);
        gradient42.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient42.setColorAt(0, QColor(0, 195, 195, 255));
        gradient42.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush47(gradient42);
        palette14.setBrush(QPalette::Active, QPalette::AlternateBase, brush47);
        palette14.setBrush(QPalette::Inactive, QPalette::Button, brush12);
        palette14.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::Window, brush13);
        QLinearGradient gradient43(0, 0, 0.755682, 0.864);
        gradient43.setSpread(QGradient::PadSpread);
        gradient43.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient43.setColorAt(0, QColor(0, 195, 195, 255));
        gradient43.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush48(gradient43);
        palette14.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush48);
        palette14.setBrush(QPalette::Disabled, QPalette::Button, brush12);
        palette14.setBrush(QPalette::Disabled, QPalette::Base, brush13);
        palette14.setBrush(QPalette::Disabled, QPalette::Window, brush13);
        QLinearGradient gradient44(0, 0, 0.755682, 0.864);
        gradient44.setSpread(QGradient::PadSpread);
        gradient44.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient44.setColorAt(0, QColor(0, 195, 195, 255));
        gradient44.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush49(gradient44);
        palette14.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush49);
        line_7->setPalette(palette14);
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line_7);


        gridLayout_2->addLayout(verticalLayout_7, 2, 1, 1, 1);

        projectlabel = new QLabel(layoutWidget1);
        projectlabel->setObjectName(QStringLiteral("projectlabel"));
        projectlabel->setMaximumSize(QSize(20, 20));
        QPalette palette15;
        QLinearGradient gradient45(0, 0, 0.755682, 0.864);
        gradient45.setSpread(QGradient::PadSpread);
        gradient45.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient45.setColorAt(0, QColor(0, 195, 195, 255));
        gradient45.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush50(gradient45);
        palette15.setBrush(QPalette::Active, QPalette::AlternateBase, brush50);
        QLinearGradient gradient46(0, 0, 0.755682, 0.864);
        gradient46.setSpread(QGradient::PadSpread);
        gradient46.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient46.setColorAt(0, QColor(0, 195, 195, 255));
        gradient46.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush51(gradient46);
        palette15.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush51);
        QLinearGradient gradient47(0, 0, 0.755682, 0.864);
        gradient47.setSpread(QGradient::PadSpread);
        gradient47.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient47.setColorAt(0, QColor(0, 195, 195, 255));
        gradient47.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush52(gradient47);
        palette15.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush52);
        projectlabel->setPalette(palette15);
        projectlabel->setFont(font2);
        projectlabel->setAutoFillBackground(true);
        projectlabel->setPixmap(QPixmap(QString::fromUtf8(":/UserRegister/Resources/UserRegister/mustfill.png")));
        projectlabel->setScaledContents(true);

        gridLayout_2->addWidget(projectlabel, 2, 2, 1, 1);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(0);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        BankType = new QComboBox(layoutWidget1);
        BankType->setObjectName(QStringLiteral("BankType"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(BankType->sizePolicy().hasHeightForWidth());
        BankType->setSizePolicy(sizePolicy);
        BankType->setMinimumSize(QSize(305, 0));
        BankType->setMaximumSize(QSize(167, 16777215));
        BankType->setFont(font1);
        BankType->setAutoFillBackground(true);
        BankType->setEditable(true);
        BankType->setDuplicatesEnabled(true);
        BankType->setFrame(false);

        verticalLayout_12->addWidget(BankType);

        line_5 = new QFrame(layoutWidget1);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout_12->addWidget(line_5);


        gridLayout_2->addLayout(verticalLayout_12, 0, 1, 1, 1);

        layoutWidget->raise();
        frame->raise();
        label->raise();
        layoutWidget->raise();
        NextStep->raise();

        retranslateUi(UserRegisterSecondStep);

        QMetaObject::connectSlotsByName(UserRegisterSecondStep);
    } // setupUi

    void retranslateUi(QDialog *UserRegisterSecondStep)
    {
        UserRegisterSecondStep->setWindowTitle(QApplication::translate("UserRegisterSecondStep", "UserRegisterSecondStep", Q_NULLPTR));
        AppClose->setText(QString());
        label->setText(QApplication::translate("UserRegisterSecondStep", "\350\264\246\345\217\267\350\256\276\347\275\256-\347\273\237\350\256\241\344\270\216\346\212\245\351\224\200", Q_NULLPTR));
        NextStep->setText(QApplication::translate("UserRegisterSecondStep", "\344\270\213\344\270\200\346\255\245", Q_NULLPTR));
        label_2->setText(QApplication::translate("UserRegisterSecondStep", "\345\247\223\345\220\215\357\274\232", Q_NULLPTR));
        Name->setInputMask(QString());
        namelabel->setText(QString());
        label_8->setText(QApplication::translate("UserRegisterSecondStep", "\345\255\246\345\217\267\357\274\232", Q_NULLPTR));
        ID->setInputMask(QString());
        idlabel->setText(QString());
        label_4->setText(QApplication::translate("UserRegisterSecondStep", "\346\211\213\346\234\272\357\274\232", Q_NULLPTR));
        Phone->setInputMask(QString());
        phonelabel->setText(QString());
        label_6->setText(QApplication::translate("UserRegisterSecondStep", "\351\202\256\347\256\261\357\274\232", Q_NULLPTR));
        Email->setInputMask(QString());
        emaillabel->setText(QString());
        label_7->setText(QApplication::translate("UserRegisterSecondStep", "\351\223\266\350\241\214\357\274\232", Q_NULLPTR));
        banklabel->setText(QString());
        label_9->setText(QApplication::translate("UserRegisterSecondStep", "\345\215\241\345\217\267:", Q_NULLPTR));
        BankNumber->setInputMask(QString());
        banknumberlabel->setText(QString());
        label_10->setText(QApplication::translate("UserRegisterSecondStep", "\351\241\271\347\233\256\357\274\232", Q_NULLPTR));
        Project->setInputMask(QString());
        projectlabel->setText(QString());
        BankType->setCurrentText(QString());
    } // retranslateUi

};

namespace Ui {
    class UserRegisterSecondStep: public Ui_UserRegisterSecondStep {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERREGISTERSECONDSTEP_H
