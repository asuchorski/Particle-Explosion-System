/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *m_centralWidget;
    QGridLayout *m_mainWindowGridLayout;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QGroupBox *ZooControl;
    QGridLayout *gridLayout;
    QSlider *m_zoom;
    QGroupBox *Colours;
    QGridLayout *gridLayout_2;
    QPushButton *Implode_button;
    QPushButton *Torus_button;
    QPushButton *Cylindrical_button;
    QPushButton *Spherical_button;
    QPushButton *Square_button;
    QPushButton *Triangle_button;
    QGroupBox *groupBox;
    QFormLayout *formLayout_3;
    QLabel *x_txt;
    QDoubleSpinBox *m_x_pos;
    QLabel *y_txt;
    QDoubleSpinBox *m_y_pos;
    QDoubleSpinBox *m_z_pos;
    QLabel *z_txt;
    QGroupBox *ParticleControls;
    QFormLayout *formLayout;
    QLabel *numOfParticles_txt;
    QSpinBox *m_numParticles;
    QLabel *initialVelocity_txt;
    QDoubleSpinBox *m_initialVelocity;
    QLabel *life_txt;
    QDoubleSpinBox *m_age;
    QSpacerItem *verticalSpacer_2;
    QLabel *expansion_txt;
    QSlider *m_expansion;
    QSpacerItem *verticalSpacer_3;
    QLabel *label;
    QSlider *m_spread;
    QSpacerItem *verticalSpacer_5;
    QLabel *Gravity_txt;
    QDial *m_gravityDial;
    QPushButton *m_clearScreen;
    QSlider *m_fadeOverTime;
    QLabel *label_3;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1080, 870);
        QPalette palette;
        QBrush brush(QColor(243, 243, 243, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(46, 52, 54, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(69, 78, 81, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(57, 65, 67, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(23, 26, 27, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(31, 35, 36, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        QBrush brush7(QColor(0, 0, 0, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush7);
        QBrush brush8(QColor(51, 51, 51, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush8);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush7);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
        QBrush brush9(QColor(255, 255, 220, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush9);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush7);
        QBrush brush10(QColor(231, 231, 231, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush10);
        QBrush brush11(QColor(35, 35, 35, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush11);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        QBrush brush12(QColor(202, 202, 202, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush12);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush11);
        QBrush brush13(QColor(160, 160, 160, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush13);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush10);
        QBrush brush14(QColor(255, 0, 0, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush14);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush10);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush8);
        QBrush brush15(QColor(118, 118, 118, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush15);
        QBrush brush16(QColor(81, 81, 81, 255));
        brush16.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush16);
        QBrush brush17(QColor(0, 0, 0, 102));
        brush17.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush17);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush10);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        QBrush brush18(QColor(238, 238, 236, 255));
        brush18.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush18);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush8);
        QBrush brush19(QColor(177, 177, 177, 255));
        brush19.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush19);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush16);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush17);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush10);
        MainWindow->setPalette(palette);
        m_centralWidget = new QWidget(MainWindow);
        m_centralWidget->setObjectName(QString::fromUtf8("m_centralWidget"));
        m_mainWindowGridLayout = new QGridLayout(m_centralWidget);
        m_mainWindowGridLayout->setObjectName(QString::fromUtf8("m_mainWindowGridLayout"));
        label_2 = new QLabel(m_centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setPixmap(QPixmap(QString::fromUtf8("../images/UI_Banner.png")));

        m_mainWindowGridLayout->addWidget(label_2, 0, 0, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        m_mainWindowGridLayout->addItem(horizontalSpacer_2, 4, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        m_mainWindowGridLayout->addItem(horizontalSpacer, 4, 0, 1, 1);

        ZooControl = new QGroupBox(m_centralWidget);
        ZooControl->setObjectName(QString::fromUtf8("ZooControl"));
        ZooControl->setAcceptDrops(false);
        ZooControl->setLayoutDirection(Qt::LeftToRight);
        ZooControl->setAutoFillBackground(false);
        gridLayout = new QGridLayout(ZooControl);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        m_zoom = new QSlider(ZooControl);
        m_zoom->setObjectName(QString::fromUtf8("m_zoom"));
        m_zoom->setCursor(QCursor(Qt::SizeVerCursor));
        m_zoom->setMouseTracking(false);
        m_zoom->setLayoutDirection(Qt::LeftToRight);
        m_zoom->setMinimum(0);
        m_zoom->setMaximum(1400);
        m_zoom->setValue(200);
        m_zoom->setTracking(true);
        m_zoom->setOrientation(Qt::Vertical);
        m_zoom->setInvertedAppearance(false);
        m_zoom->setInvertedControls(true);

        gridLayout->addWidget(m_zoom, 0, 0, 1, 1);


        m_mainWindowGridLayout->addWidget(ZooControl, 0, 2, 5, 1);

        Colours = new QGroupBox(m_centralWidget);
        Colours->setObjectName(QString::fromUtf8("Colours"));
        gridLayout_2 = new QGridLayout(Colours);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        Implode_button = new QPushButton(Colours);
        Implode_button->setObjectName(QString::fromUtf8("Implode_button"));

        gridLayout_2->addWidget(Implode_button, 1, 1, 1, 1);

        Torus_button = new QPushButton(Colours);
        Torus_button->setObjectName(QString::fromUtf8("Torus_button"));

        gridLayout_2->addWidget(Torus_button, 2, 1, 1, 1);

        Cylindrical_button = new QPushButton(Colours);
        Cylindrical_button->setObjectName(QString::fromUtf8("Cylindrical_button"));

        gridLayout_2->addWidget(Cylindrical_button, 2, 0, 1, 1);

        Spherical_button = new QPushButton(Colours);
        Spherical_button->setObjectName(QString::fromUtf8("Spherical_button"));

        gridLayout_2->addWidget(Spherical_button, 0, 0, 1, 1);

        Square_button = new QPushButton(Colours);
        Square_button->setObjectName(QString::fromUtf8("Square_button"));

        gridLayout_2->addWidget(Square_button, 1, 0, 1, 1);

        Triangle_button = new QPushButton(Colours);
        Triangle_button->setObjectName(QString::fromUtf8("Triangle_button"));

        gridLayout_2->addWidget(Triangle_button, 0, 1, 1, 1);


        m_mainWindowGridLayout->addWidget(Colours, 3, 3, 1, 1);

        groupBox = new QGroupBox(m_centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        formLayout_3 = new QFormLayout(groupBox);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        x_txt = new QLabel(groupBox);
        x_txt->setObjectName(QString::fromUtf8("x_txt"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, x_txt);

        m_x_pos = new QDoubleSpinBox(groupBox);
        m_x_pos->setObjectName(QString::fromUtf8("m_x_pos"));
        m_x_pos->setCursor(QCursor(Qt::PointingHandCursor));
        m_x_pos->setMinimum(-100.000000000000000);
        m_x_pos->setMaximum(100.000000000000000);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, m_x_pos);

        y_txt = new QLabel(groupBox);
        y_txt->setObjectName(QString::fromUtf8("y_txt"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, y_txt);

        m_y_pos = new QDoubleSpinBox(groupBox);
        m_y_pos->setObjectName(QString::fromUtf8("m_y_pos"));
        m_y_pos->setCursor(QCursor(Qt::PointingHandCursor));
        m_y_pos->setMinimum(-100.000000000000000);
        m_y_pos->setMaximum(100.000000000000000);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, m_y_pos);

        m_z_pos = new QDoubleSpinBox(groupBox);
        m_z_pos->setObjectName(QString::fromUtf8("m_z_pos"));
        m_z_pos->setCursor(QCursor(Qt::PointingHandCursor));
        m_z_pos->setMinimum(-100.000000000000000);
        m_z_pos->setMaximum(100.000000000000000);

        formLayout_3->setWidget(2, QFormLayout::FieldRole, m_z_pos);

        z_txt = new QLabel(groupBox);
        z_txt->setObjectName(QString::fromUtf8("z_txt"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, z_txt);


        m_mainWindowGridLayout->addWidget(groupBox, 4, 3, 1, 1);

        ParticleControls = new QGroupBox(m_centralWidget);
        ParticleControls->setObjectName(QString::fromUtf8("ParticleControls"));
        formLayout = new QFormLayout(ParticleControls);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        numOfParticles_txt = new QLabel(ParticleControls);
        numOfParticles_txt->setObjectName(QString::fromUtf8("numOfParticles_txt"));

        formLayout->setWidget(0, QFormLayout::LabelRole, numOfParticles_txt);

        m_numParticles = new QSpinBox(ParticleControls);
        m_numParticles->setObjectName(QString::fromUtf8("m_numParticles"));
        m_numParticles->setCursor(QCursor(Qt::PointingHandCursor));
        m_numParticles->setMaximum(30000);
        m_numParticles->setSingleStep(100);
        m_numParticles->setValue(1000);

        formLayout->setWidget(0, QFormLayout::FieldRole, m_numParticles);

        initialVelocity_txt = new QLabel(ParticleControls);
        initialVelocity_txt->setObjectName(QString::fromUtf8("initialVelocity_txt"));

        formLayout->setWidget(1, QFormLayout::LabelRole, initialVelocity_txt);

        m_initialVelocity = new QDoubleSpinBox(ParticleControls);
        m_initialVelocity->setObjectName(QString::fromUtf8("m_initialVelocity"));
        m_initialVelocity->setCursor(QCursor(Qt::PointingHandCursor));
        m_initialVelocity->setMaximum(50.000000000000000);
        m_initialVelocity->setSingleStep(0.200000000000000);
        m_initialVelocity->setValue(2.000000000000000);

        formLayout->setWidget(1, QFormLayout::FieldRole, m_initialVelocity);

        life_txt = new QLabel(ParticleControls);
        life_txt->setObjectName(QString::fromUtf8("life_txt"));

        formLayout->setWidget(2, QFormLayout::LabelRole, life_txt);

        m_age = new QDoubleSpinBox(ParticleControls);
        m_age->setObjectName(QString::fromUtf8("m_age"));
        m_age->setCursor(QCursor(Qt::PointingHandCursor));
        m_age->setMinimum(0.000000000000000);
        m_age->setMaximum(50.000000000000000);
        m_age->setSingleStep(0.500000000000000);
        m_age->setValue(10.000000000000000);

        formLayout->setWidget(2, QFormLayout::FieldRole, m_age);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(3, QFormLayout::LabelRole, verticalSpacer_2);

        expansion_txt = new QLabel(ParticleControls);
        expansion_txt->setObjectName(QString::fromUtf8("expansion_txt"));

        formLayout->setWidget(4, QFormLayout::LabelRole, expansion_txt);

        m_expansion = new QSlider(ParticleControls);
        m_expansion->setObjectName(QString::fromUtf8("m_expansion"));
        m_expansion->setCursor(QCursor(Qt::OpenHandCursor));
        m_expansion->setValue(10);
        m_expansion->setOrientation(Qt::Horizontal);

        formLayout->setWidget(4, QFormLayout::FieldRole, m_expansion);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(5, QFormLayout::LabelRole, verticalSpacer_3);

        label = new QLabel(ParticleControls);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label);

        m_spread = new QSlider(ParticleControls);
        m_spread->setObjectName(QString::fromUtf8("m_spread"));
        m_spread->setCursor(QCursor(Qt::OpenHandCursor));
        m_spread->setMinimum(1);
        m_spread->setMaximum(1000);
        m_spread->setValue(1);
        m_spread->setOrientation(Qt::Horizontal);

        formLayout->setWidget(6, QFormLayout::FieldRole, m_spread);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(8, QFormLayout::LabelRole, verticalSpacer_5);

        Gravity_txt = new QLabel(ParticleControls);
        Gravity_txt->setObjectName(QString::fromUtf8("Gravity_txt"));

        formLayout->setWidget(11, QFormLayout::LabelRole, Gravity_txt);

        m_gravityDial = new QDial(ParticleControls);
        m_gravityDial->setObjectName(QString::fromUtf8("m_gravityDial"));
        m_gravityDial->setCursor(QCursor(Qt::OpenHandCursor));
        m_gravityDial->setMinimum(-10);
        m_gravityDial->setMaximum(30);
        m_gravityDial->setValue(10);
        m_gravityDial->setInvertedAppearance(false);
        m_gravityDial->setInvertedControls(false);
        m_gravityDial->setWrapping(false);
        m_gravityDial->setNotchesVisible(true);

        formLayout->setWidget(11, QFormLayout::FieldRole, m_gravityDial);

        m_clearScreen = new QPushButton(ParticleControls);
        m_clearScreen->setObjectName(QString::fromUtf8("m_clearScreen"));

        formLayout->setWidget(13, QFormLayout::SpanningRole, m_clearScreen);

        m_fadeOverTime = new QSlider(ParticleControls);
        m_fadeOverTime->setObjectName(QString::fromUtf8("m_fadeOverTime"));
        m_fadeOverTime->setCursor(QCursor(Qt::OpenHandCursor));
        m_fadeOverTime->setMaximum(100);
        m_fadeOverTime->setValue(20);
        m_fadeOverTime->setOrientation(Qt::Horizontal);

        formLayout->setWidget(9, QFormLayout::FieldRole, m_fadeOverTime);

        label_3 = new QLabel(ParticleControls);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(9, QFormLayout::LabelRole, label_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(10, QFormLayout::LabelRole, verticalSpacer);


        m_mainWindowGridLayout->addWidget(ParticleControls, 0, 3, 3, 1);

        MainWindow->setCentralWidget(m_centralWidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1080, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Explosion NGL", nullptr));
        label_2->setText(QString());
        ZooControl->setTitle(QCoreApplication::translate("MainWindow", "Zoom", nullptr));
        Colours->setTitle(QCoreApplication::translate("MainWindow", "Explosion Type", nullptr));
        Implode_button->setText(QCoreApplication::translate("MainWindow", "Implode", nullptr));
        Torus_button->setText(QCoreApplication::translate("MainWindow", "Torus", nullptr));
        Cylindrical_button->setText(QCoreApplication::translate("MainWindow", "Cylindrical", nullptr));
        Spherical_button->setText(QCoreApplication::translate("MainWindow", "Spherical", nullptr));
        Square_button->setText(QCoreApplication::translate("MainWindow", "Square", nullptr));
        Triangle_button->setText(QCoreApplication::translate("MainWindow", "Triangle", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Emitter Controls", nullptr));
        x_txt->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        y_txt->setText(QCoreApplication::translate("MainWindow", "y", nullptr));
        z_txt->setText(QCoreApplication::translate("MainWindow", "z", nullptr));
        ParticleControls->setTitle(QCoreApplication::translate("MainWindow", "Explosion Controls", nullptr));
        numOfParticles_txt->setText(QCoreApplication::translate("MainWindow", "Number of Particles", nullptr));
        initialVelocity_txt->setText(QCoreApplication::translate("MainWindow", "Initial Velocity", nullptr));
        life_txt->setText(QCoreApplication::translate("MainWindow", "Life", nullptr));
        expansion_txt->setText(QCoreApplication::translate("MainWindow", "Expansion", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Spread", nullptr));
        Gravity_txt->setText(QCoreApplication::translate("MainWindow", "Gravity", nullptr));
        m_clearScreen->setText(QCoreApplication::translate("MainWindow", "Clear Screen", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Fade Over TIme", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
