/********************************************************************************
** Form generated from reading UI file 'ExpenseItem.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPENSEITEM_H
#define UI_EXPENSEITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ExpenseItem
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QRadioButton *LocalTransportation;
    QRadioButton *LodgingExpenses;
    QRadioButton *TrainingFees;
    QRadioButton *OfficeSupplies;
    QRadioButton *StudentActivityFee;
    QRadioButton *EntertainmentExpense;
    QRadioButton *PurchaseOfProfessionalMaterials;
    QRadioButton *Correspondence;
    QRadioButton *ConstructionOfFixedAssets;
    QRadioButton *PurchaseOfExperimentalMaterials;
    QRadioButton *PostFee;
    QRadioButton *Streamer;
    QRadioButton *SportingGoodsPurchaseFee;
    QRadioButton *SelfServiceCost;
    QRadioButton *Other;
    QRadioButton *XeroxFee;
    QRadioButton *MotorVehicleMaintenance;
    QRadioButton *Typography;
    QRadioButton *OfficeEquipmentMaintenance;
    QRadioButton *MaterialTestingAndProcessingFee;
    QRadioButton *EquipmentMaintenanceFee;

    void setupUi(QDialog *ExpenseItem)
    {
        if (ExpenseItem->objectName().isEmpty())
            ExpenseItem->setObjectName(QStringLiteral("ExpenseItem"));
        ExpenseItem->resize(455, 232);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        ExpenseItem->setPalette(palette);
        verticalLayout = new QVBoxLayout(ExpenseItem);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(ExpenseItem);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setFlat(true);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        LocalTransportation = new QRadioButton(groupBox);
        LocalTransportation->setObjectName(QStringLiteral("LocalTransportation"));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(11);
        LocalTransportation->setFont(font);

        gridLayout->addWidget(LocalTransportation, 0, 0, 1, 1);

        LodgingExpenses = new QRadioButton(groupBox);
        LodgingExpenses->setObjectName(QStringLiteral("LodgingExpenses"));
        LodgingExpenses->setFont(font);

        gridLayout->addWidget(LodgingExpenses, 0, 1, 1, 1);

        TrainingFees = new QRadioButton(groupBox);
        TrainingFees->setObjectName(QStringLiteral("TrainingFees"));
        TrainingFees->setFont(font);

        gridLayout->addWidget(TrainingFees, 0, 2, 1, 1);

        OfficeSupplies = new QRadioButton(groupBox);
        OfficeSupplies->setObjectName(QStringLiteral("OfficeSupplies"));
        OfficeSupplies->setFont(font);

        gridLayout->addWidget(OfficeSupplies, 1, 0, 1, 1);

        StudentActivityFee = new QRadioButton(groupBox);
        StudentActivityFee->setObjectName(QStringLiteral("StudentActivityFee"));
        StudentActivityFee->setFont(font);

        gridLayout->addWidget(StudentActivityFee, 1, 1, 1, 1);

        EntertainmentExpense = new QRadioButton(groupBox);
        EntertainmentExpense->setObjectName(QStringLiteral("EntertainmentExpense"));
        EntertainmentExpense->setFont(font);

        gridLayout->addWidget(EntertainmentExpense, 1, 2, 1, 1);

        PurchaseOfProfessionalMaterials = new QRadioButton(groupBox);
        PurchaseOfProfessionalMaterials->setObjectName(QStringLiteral("PurchaseOfProfessionalMaterials"));
        PurchaseOfProfessionalMaterials->setFont(font);

        gridLayout->addWidget(PurchaseOfProfessionalMaterials, 2, 0, 1, 1);

        Correspondence = new QRadioButton(groupBox);
        Correspondence->setObjectName(QStringLiteral("Correspondence"));
        Correspondence->setFont(font);

        gridLayout->addWidget(Correspondence, 2, 1, 1, 1);

        ConstructionOfFixedAssets = new QRadioButton(groupBox);
        ConstructionOfFixedAssets->setObjectName(QStringLiteral("ConstructionOfFixedAssets"));
        ConstructionOfFixedAssets->setFont(font);

        gridLayout->addWidget(ConstructionOfFixedAssets, 2, 2, 1, 1);

        PurchaseOfExperimentalMaterials = new QRadioButton(groupBox);
        PurchaseOfExperimentalMaterials->setObjectName(QStringLiteral("PurchaseOfExperimentalMaterials"));
        PurchaseOfExperimentalMaterials->setFont(font);

        gridLayout->addWidget(PurchaseOfExperimentalMaterials, 3, 0, 1, 1);

        PostFee = new QRadioButton(groupBox);
        PostFee->setObjectName(QStringLiteral("PostFee"));
        PostFee->setFont(font);

        gridLayout->addWidget(PostFee, 3, 1, 1, 1);

        Streamer = new QRadioButton(groupBox);
        Streamer->setObjectName(QStringLiteral("Streamer"));
        Streamer->setFont(font);

        gridLayout->addWidget(Streamer, 3, 2, 1, 1);

        SportingGoodsPurchaseFee = new QRadioButton(groupBox);
        SportingGoodsPurchaseFee->setObjectName(QStringLiteral("SportingGoodsPurchaseFee"));
        SportingGoodsPurchaseFee->setFont(font);

        gridLayout->addWidget(SportingGoodsPurchaseFee, 4, 0, 1, 1);

        SelfServiceCost = new QRadioButton(groupBox);
        SelfServiceCost->setObjectName(QStringLiteral("SelfServiceCost"));
        SelfServiceCost->setFont(font);

        gridLayout->addWidget(SelfServiceCost, 4, 1, 1, 1);

        Other = new QRadioButton(groupBox);
        Other->setObjectName(QStringLiteral("Other"));
        Other->setFont(font);

        gridLayout->addWidget(Other, 4, 2, 1, 1);

        XeroxFee = new QRadioButton(groupBox);
        XeroxFee->setObjectName(QStringLiteral("XeroxFee"));
        XeroxFee->setFont(font);

        gridLayout->addWidget(XeroxFee, 5, 0, 1, 1);

        MotorVehicleMaintenance = new QRadioButton(groupBox);
        MotorVehicleMaintenance->setObjectName(QStringLiteral("MotorVehicleMaintenance"));
        MotorVehicleMaintenance->setFont(font);

        gridLayout->addWidget(MotorVehicleMaintenance, 5, 1, 1, 1);

        Typography = new QRadioButton(groupBox);
        Typography->setObjectName(QStringLiteral("Typography"));
        Typography->setFont(font);

        gridLayout->addWidget(Typography, 6, 0, 1, 1);

        OfficeEquipmentMaintenance = new QRadioButton(groupBox);
        OfficeEquipmentMaintenance->setObjectName(QStringLiteral("OfficeEquipmentMaintenance"));
        OfficeEquipmentMaintenance->setFont(font);

        gridLayout->addWidget(OfficeEquipmentMaintenance, 6, 1, 1, 1);

        MaterialTestingAndProcessingFee = new QRadioButton(groupBox);
        MaterialTestingAndProcessingFee->setObjectName(QStringLiteral("MaterialTestingAndProcessingFee"));
        MaterialTestingAndProcessingFee->setFont(font);

        gridLayout->addWidget(MaterialTestingAndProcessingFee, 7, 0, 1, 1);

        EquipmentMaintenanceFee = new QRadioButton(groupBox);
        EquipmentMaintenanceFee->setObjectName(QStringLiteral("EquipmentMaintenanceFee"));
        EquipmentMaintenanceFee->setFont(font);

        gridLayout->addWidget(EquipmentMaintenanceFee, 7, 1, 1, 1);


        verticalLayout->addWidget(groupBox);


        retranslateUi(ExpenseItem);

        QMetaObject::connectSlotsByName(ExpenseItem);
    } // setupUi

    void retranslateUi(QDialog *ExpenseItem)
    {
        ExpenseItem->setWindowTitle(QApplication::translate("ExpenseItem", "ExpenseItem", Q_NULLPTR));
        groupBox->setTitle(QString());
        LocalTransportation->setText(QApplication::translate("ExpenseItem", "\345\270\202\345\206\205\344\272\244\351\200\232\350\264\271", Q_NULLPTR));
        LodgingExpenses->setText(QApplication::translate("ExpenseItem", "\345\256\236\344\271\240\350\264\271", Q_NULLPTR));
        TrainingFees->setText(QApplication::translate("ExpenseItem", "\345\237\271\350\256\255\350\264\271", Q_NULLPTR));
        OfficeSupplies->setText(QApplication::translate("ExpenseItem", "\345\212\236\345\205\254\347\224\250\345\223\201", Q_NULLPTR));
        StudentActivityFee->setText(QApplication::translate("ExpenseItem", "\345\255\246\347\224\237\346\264\273\345\212\250\350\264\271", Q_NULLPTR));
        EntertainmentExpense->setText(QApplication::translate("ExpenseItem", "\346\213\233\345\276\205\350\264\271", Q_NULLPTR));
        PurchaseOfProfessionalMaterials->setText(QApplication::translate("ExpenseItem", "\344\270\223\344\270\232\346\235\220\346\226\231\350\264\255\347\275\256\350\264\271", Q_NULLPTR));
        Correspondence->setText(QApplication::translate("ExpenseItem", "\351\200\232\350\256\257\350\264\271", Q_NULLPTR));
        ConstructionOfFixedAssets->setText(QApplication::translate("ExpenseItem", "\345\233\272\345\256\232\350\265\204\344\272\247\346\236\204\345\273\272\350\264\271", Q_NULLPTR));
        PurchaseOfExperimentalMaterials->setText(QApplication::translate("ExpenseItem", "\345\256\236\351\252\214\346\235\220\346\226\231\350\264\255\347\275\256\350\264\271", Q_NULLPTR));
        PostFee->setText(QApplication::translate("ExpenseItem", "\351\202\256\345\257\204\350\264\271", Q_NULLPTR));
        Streamer->setText(QApplication::translate("ExpenseItem", "\346\250\252\345\271\205", Q_NULLPTR));
        SportingGoodsPurchaseFee->setText(QApplication::translate("ExpenseItem", "\344\275\223\350\202\262\347\224\250\345\223\201\350\264\255\347\275\256\350\264\271", Q_NULLPTR));
        SelfServiceCost->setText(QApplication::translate("ExpenseItem", "\350\207\252\345\244\207\350\275\246\350\264\271\347\224\250", Q_NULLPTR));
        Other->setText(QApplication::translate("ExpenseItem", "\345\205\266\344\273\226", Q_NULLPTR));
        XeroxFee->setText(QApplication::translate("ExpenseItem", "\350\265\204\346\226\231\345\244\215\345\215\260\350\264\271", Q_NULLPTR));
        MotorVehicleMaintenance->setText(QApplication::translate("ExpenseItem", "\346\234\272\345\212\250\350\275\246\347\273\264\344\277\256\350\264\271", Q_NULLPTR));
        Typography->setText(QApplication::translate("ExpenseItem", "\347\211\210\351\235\242\345\215\260\345\210\267\350\264\271", Q_NULLPTR));
        OfficeEquipmentMaintenance->setText(QApplication::translate("ExpenseItem", "\345\212\236\345\205\254\350\256\276\345\244\207\347\273\264\344\277\256\350\264\271", Q_NULLPTR));
        MaterialTestingAndProcessingFee->setText(QApplication::translate("ExpenseItem", "\346\235\220\346\226\231\346\265\213\350\257\225\345\212\240\345\267\245\350\264\271", Q_NULLPTR));
        EquipmentMaintenanceFee->setText(QApplication::translate("ExpenseItem", "\344\273\252\345\231\250\350\256\276\345\244\207\347\273\264\344\277\256\350\264\271", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ExpenseItem: public Ui_ExpenseItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPENSEITEM_H
