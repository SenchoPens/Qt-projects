/********************************************************************************
** Form generated from reading UI file 'start.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_START_H
#define UI_START_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Start
{
public:
    QLabel *gameName;
    QFrame *recordFrame;
    QLabel *recordLabel;
    QLCDNumber *recordSecondsNumber;
    QLabel *recordSecondsLabel;
    QFrame *buttonsFrame;
    QPushButton *newGameButton;

    void setupUi(QWidget *Start)
    {
        if (Start->objectName().isEmpty())
            Start->setObjectName(QStringLiteral("Start"));
        Start->resize(640, 480);
        gameName = new QLabel(Start);
        gameName->setObjectName(QStringLiteral("gameName"));
        gameName->setGeometry(QRect(265, 90, 120, 31));
        QFont font;
        font.setPointSize(30);
        font.setBold(true);
        font.setWeight(75);
        gameName->setFont(font);
        recordFrame = new QFrame(Start);
        recordFrame->setObjectName(QStringLiteral("recordFrame"));
        recordFrame->setGeometry(QRect(210, 140, 231, 25));
        recordFrame->setFrameShape(QFrame::Box);
        recordFrame->setFrameShadow(QFrame::Plain);
        recordLabel = new QLabel(recordFrame);
        recordLabel->setObjectName(QStringLiteral("recordLabel"));
        recordLabel->setGeometry(QRect(1, 1, 110, 22));
        QFont font1;
        font1.setPointSize(11);
        recordLabel->setFont(font1);
        recordLabel->setFrameShape(QFrame::NoFrame);
        recordLabel->setFrameShadow(QFrame::Plain);
        recordSecondsNumber = new QLCDNumber(recordFrame);
        recordSecondsNumber->setObjectName(QStringLiteral("recordSecondsNumber"));
        recordSecondsNumber->setGeometry(QRect(111, 1, 59, 23));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        QBrush brush2(QColor(127, 127, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush2);
        QBrush brush3(QColor(170, 170, 170, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        QBrush brush4(QColor(255, 255, 220, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        recordSecondsNumber->setPalette(palette);
        recordSecondsNumber->setFrameShape(QFrame::NoFrame);
        recordSecondsNumber->setSmallDecimalPoint(false);
        recordSecondsLabel = new QLabel(recordFrame);
        recordSecondsLabel->setObjectName(QStringLiteral("recordSecondsLabel"));
        recordSecondsLabel->setGeometry(QRect(170, 0, 61, 23));
        recordSecondsLabel->setFont(font1);
        buttonsFrame = new QFrame(Start);
        buttonsFrame->setObjectName(QStringLiteral("buttonsFrame"));
        buttonsFrame->setGeometry(QRect(220, 240, 213, 53));
        buttonsFrame->setToolTipDuration(5);
        buttonsFrame->setFrameShape(QFrame::Box);
        buttonsFrame->setFrameShadow(QFrame::Plain);
        newGameButton = new QPushButton(buttonsFrame);
        newGameButton->setObjectName(QStringLiteral("newGameButton"));
        newGameButton->setGeometry(QRect(1, 1, 211, 51));
        QFont font2;
        font2.setPointSize(20);
        newGameButton->setFont(font2);
        newGameButton->setCheckable(false);
        newGameButton->setChecked(false);
        newGameButton->setAutoDefault(false);
        newGameButton->setFlat(false);
        newGameButton->raise();
        newGameButton->raise();

        retranslateUi(Start);

        newGameButton->setDefault(false);


        QMetaObject::connectSlotsByName(Start);
    } // setupUi

    void retranslateUi(QWidget *Start)
    {
        Start->setWindowTitle(QApplication::translate("Start", "Balls", Q_NULLPTR));
        gameName->setText(QApplication::translate("Start", "BALLS", Q_NULLPTR));
        recordLabel->setText(QApplication::translate("Start", "Biggest Record:", Q_NULLPTR));
        recordSecondsLabel->setText(QApplication::translate("Start", "seconds", Q_NULLPTR));
        newGameButton->setText(QApplication::translate("Start", "Start New Game", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Start: public Ui_Start {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_START_H
