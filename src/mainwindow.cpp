#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_ui(new Ui::MainWindow)
{
    m_ui->setupUi(this);
    m_scene = new NGLScene(this);

    //NGL scene particle explosion window
    m_ui->m_mainWindowGridLayout->addWidget(m_scene,1,0,4,2);

    //Signals and slots for explosion types button inputs from the UI
    connect(m_ui->Square_button,SIGNAL(clicked(bool)),m_scene,SLOT(callEmitParticles()));
    connect(m_ui->Spherical_button,SIGNAL(clicked(bool)),m_scene,SLOT(callSphericalParticles()));
    connect(m_ui->Triangle_button,SIGNAL(clicked(bool)),m_scene,SLOT(callTriangleParticles()));
    connect(m_ui->Implode_button,SIGNAL(clicked(bool)),m_scene,SLOT(callImplodeExplosion()));
    connect(m_ui->Cylindrical_button,SIGNAL(clicked(bool)),m_scene,SLOT(callCylindricalExplosion()));
    connect(m_ui->Torus_button,SIGNAL(clicked(bool)),m_scene,SLOT(callTorusExplosion()));

    //Signal and slots for clear all button from the UI
    connect(m_ui->m_clearScreen,SIGNAL(clicked(bool)),m_scene,SLOT(callClearAll()));

    //Inputs from the UI for particle control parameters
    connect(m_ui->m_numParticles, QOverload<int>::of(&QSpinBox::valueChanged),m_scene, &NGLScene::updateNumParticles);

    connect(m_ui->m_gravityDial, &QDial::valueChanged, m_scene, &NGLScene::updateGravity);
    connect(m_ui->m_initialVelocity, QOverload<double>::of(&QDoubleSpinBox::valueChanged),m_scene, &NGLScene::updateVelocity);
    connect(m_ui->m_age, QOverload<double>::of(&QDoubleSpinBox::valueChanged),m_scene, &NGLScene::updateAge);
    connect(m_ui->m_expansion, &QSlider::valueChanged, m_scene, &NGLScene::updateSize);
    connect(m_ui->m_zoom, &QSlider::valueChanged, m_scene, &NGLScene::updateZoom);
    connect(m_ui->m_spread, &QSlider::valueChanged, m_scene, &NGLScene::updateSpread);
    connect(m_ui->m_fadeOverTime, &QSlider::valueChanged, m_scene, &NGLScene::updateFadeOverTime);

    //Inputs from the UI for emitter position 
    connect(m_ui->m_x_pos, QOverload<double>::of(&QDoubleSpinBox::valueChanged),m_scene, &NGLScene::updateXPos);
    connect(m_ui->m_y_pos, QOverload<double>::of(&QDoubleSpinBox::valueChanged),m_scene, &NGLScene::updateYPos);
    connect(m_ui->m_z_pos, QOverload<double>::of(&QDoubleSpinBox::valueChanged),m_scene, &NGLScene::updateZPos);


    m_scene->show();
}

MainWindow::~MainWindow()
{
    delete m_ui;
    delete m_scene;
}

