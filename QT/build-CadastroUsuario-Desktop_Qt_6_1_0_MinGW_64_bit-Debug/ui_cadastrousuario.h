/********************************************************************************
** Form generated from reading UI file 'cadastrousuario.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CADASTROUSUARIO_H
#define UI_CADASTROUSUARIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CadastroUsuario
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CadastroUsuario)
    {
        if (CadastroUsuario->objectName().isEmpty())
            CadastroUsuario->setObjectName(QString::fromUtf8("CadastroUsuario"));
        CadastroUsuario->setEnabled(true);
        CadastroUsuario->resize(836, 612);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CadastroUsuario->sizePolicy().hasHeightForWidth());
        CadastroUsuario->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(CadastroUsuario);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(550, 500, 91, 31));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(670, 500, 81, 31));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 50, 771, 411));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(30);
        gridLayout->setContentsMargins(30, 0, 30, 0);
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 0, 1, 2);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 0, 2, 1, 1);

        lineEdit_4 = new QLineEdit(widget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lineEdit_4, 1, 2, 1, 1);

        lineEdit_5 = new QLineEdit(widget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        gridLayout->addWidget(lineEdit_5, 2, 0, 1, 2);

        lineEdit_6 = new QLineEdit(widget);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        gridLayout->addWidget(lineEdit_6, 2, 2, 1, 1);

        lineEdit_8 = new QLineEdit(widget);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));

        gridLayout->addWidget(lineEdit_8, 3, 0, 1, 1);

        lineEdit_9 = new QLineEdit(widget);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));

        gridLayout->addWidget(lineEdit_9, 3, 1, 1, 1);

        lineEdit_7 = new QLineEdit(widget);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));

        gridLayout->addWidget(lineEdit_7, 3, 2, 1, 1);

        lineEdit_3 = new QLineEdit(widget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 1, 0, 1, 2);

        CadastroUsuario->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CadastroUsuario);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 836, 21));
        sizePolicy.setHeightForWidth(menubar->sizePolicy().hasHeightForWidth());
        menubar->setSizePolicy(sizePolicy);
        CadastroUsuario->setMenuBar(menubar);
        statusbar = new QStatusBar(CadastroUsuario);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        sizePolicy.setHeightForWidth(statusbar->sizePolicy().hasHeightForWidth());
        statusbar->setSizePolicy(sizePolicy);
        CadastroUsuario->setStatusBar(statusbar);

        retranslateUi(CadastroUsuario);

        QMetaObject::connectSlotsByName(CadastroUsuario);
    } // setupUi

    void retranslateUi(QMainWindow *CadastroUsuario)
    {
        CadastroUsuario->setWindowTitle(QCoreApplication::translate("CadastroUsuario", "CadastroUsuario", nullptr));
        pushButton->setText(QCoreApplication::translate("CadastroUsuario", "Cancelar", nullptr));
        pushButton_2->setText(QCoreApplication::translate("CadastroUsuario", "Cadastrar", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("CadastroUsuario", "Nome Completo", nullptr));
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("CadastroUsuario", "Cpf", nullptr));
        lineEdit_4->setPlaceholderText(QCoreApplication::translate("CadastroUsuario", "Senha", nullptr));
        lineEdit_5->setPlaceholderText(QCoreApplication::translate("CadastroUsuario", "Rua", nullptr));
        lineEdit_6->setPlaceholderText(QCoreApplication::translate("CadastroUsuario", "Cep", nullptr));
        lineEdit_8->setPlaceholderText(QCoreApplication::translate("CadastroUsuario", "Bairro", nullptr));
        lineEdit_9->setPlaceholderText(QCoreApplication::translate("CadastroUsuario", "Cidade", nullptr));
        lineEdit_7->setPlaceholderText(QCoreApplication::translate("CadastroUsuario", "Estado", nullptr));
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("CadastroUsuario", "Email", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CadastroUsuario: public Ui_CadastroUsuario {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CADASTROUSUARIO_H
