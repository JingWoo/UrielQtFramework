/********************************************************************************
** Form generated from reading UI file 'TimeFilter.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMEFILTER_H
#define UI_TIMEFILTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TimeFilter
{
public:
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *NearlyADay;
    QRadioButton *NearlyAWeek;
    QRadioButton *NearlyAMonth;
    QRadioButton *NearlyAYear;
    QRadioButton *All;

    void setupUi(QDialog *TimeFilter)
    {
        if (TimeFilter->objectName().isEmpty())
            TimeFilter->setObjectName(QStringLiteral("TimeFilter"));
        TimeFilter->resize(337, 234);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        TimeFilter->setPalette(palette);
        groupBox = new QGroupBox(TimeFilter);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 301, 211));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(18);
        groupBox->setFont(font);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(40, -1, -1, -1);
        NearlyADay = new QRadioButton(groupBox);
        NearlyADay->setObjectName(QStringLiteral("NearlyADay"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(14);
        NearlyADay->setFont(font1);

        verticalLayout->addWidget(NearlyADay);

        NearlyAWeek = new QRadioButton(groupBox);
        NearlyAWeek->setObjectName(QStringLiteral("NearlyAWeek"));
        NearlyAWeek->setFont(font1);

        verticalLayout->addWidget(NearlyAWeek);

        NearlyAMonth = new QRadioButton(groupBox);
        NearlyAMonth->setObjectName(QStringLiteral("NearlyAMonth"));
        NearlyAMonth->setFont(font1);

        verticalLayout->addWidget(NearlyAMonth);

        NearlyAYear = new QRadioButton(groupBox);
        NearlyAYear->setObjectName(QStringLiteral("NearlyAYear"));
        NearlyAYear->setFont(font1);

        verticalLayout->addWidget(NearlyAYear);

        All = new QRadioButton(groupBox);
        All->setObjectName(QStringLiteral("All"));
        All->setFont(font1);

        verticalLayout->addWidget(All);


        retranslateUi(TimeFilter);

        QMetaObject::connectSlotsByName(TimeFilter);
    } // setupUi

    void retranslateUi(QDialog *TimeFilter)
    {
        TimeFilter->setWindowTitle(QApplication::translate("TimeFilter", "TimeFilter", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("TimeFilter", "\351\200\211\346\213\251\346\227\266\351\227\264\346\256\265", Q_NULLPTR));
        NearlyADay->setText(QApplication::translate("TimeFilter", "\350\277\221\344\270\200\345\244\251", Q_NULLPTR));
        NearlyAWeek->setText(QApplication::translate("TimeFilter", "\350\277\221\344\270\200\345\221\250", Q_NULLPTR));
        NearlyAMonth->setText(QApplication::translate("TimeFilter", "\350\277\221\344\270\200\346\234\210", Q_NULLPTR));
        NearlyAYear->setText(QApplication::translate("TimeFilter", "\350\277\221\344\270\200\345\271\264", Q_NULLPTR));
        All->setText(QApplication::translate("TimeFilter", "\346\211\200\346\234\211", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TimeFilter: public Ui_TimeFilter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMEFILTER_H
