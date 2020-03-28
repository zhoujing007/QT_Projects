/********************************************************************************
** Form generated from reading UI file 'PythagoreanTree.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PYTHAGOREANTREE_H
#define UI_PYTHAGOREANTREE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PythagoreanTreeClass
{
public:

    void setupUi(QWidget *PythagoreanTreeClass)
    {
        if (PythagoreanTreeClass->objectName().isEmpty())
            PythagoreanTreeClass->setObjectName(QStringLiteral("PythagoreanTreeClass"));
        PythagoreanTreeClass->resize(600, 400);

        retranslateUi(PythagoreanTreeClass);

        QMetaObject::connectSlotsByName(PythagoreanTreeClass);
    } // setupUi

    void retranslateUi(QWidget *PythagoreanTreeClass)
    {
        PythagoreanTreeClass->setWindowTitle(QApplication::translate("PythagoreanTreeClass", "PythagoreanTree", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PythagoreanTreeClass: public Ui_PythagoreanTreeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PYTHAGOREANTREE_H
