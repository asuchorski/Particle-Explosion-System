#include <QMouseEvent>
#include <QGuiApplication>

#include "NGLScene.h"
#include <ngl/NGLInit.h>
#include <ngl/VAOPrimitives.h>
#include <ngl/ShaderLib.h>
#include <ngl/Util.h>
#include <ngl/Transformation.h>
#include <ngl/Random.h>
#include <ngl/Vec3.h>

#include <iostream>
#include <random>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <cmath>


NGLScene::NGLScene(QWidget *_parent) : QOpenGLWidget(_parent)
{
  m_lastFrameTime = std::chrono::high_resolution_clock::now();
}


NGLScene::~NGLScene()
{
  std::cout<<"Shutting down NGL, removing VAO's and Shaders\n";
}


void NGLScene::resizeGL(int _w , int _h)
{
  m_win.width  = static_cast<int>( _w * devicePixelRatio() );
  m_win.height = static_cast<int>( _h * devicePixelRatio() );
}


void NGLScene::initializeGL()
{
  //load and link the gl commands
  ngl::NGLInit::initialize();
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  //background colour
  glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
  // enable depth testing for drawing
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);
  // enable multisampling for smoother drawing
  glEnable(GL_MULTISAMPLE);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  ngl::ShaderLib::use(ngl::nglColourShader);

  //create a ground plane and sphere
  ngl::VAOPrimitives::createTrianglePlane("ground",300,300,1,1,ngl::Vec3::up());
  ngl::VAOPrimitives::createSphere("sphere", 1.0f, 20.0f);

  startTimer(0);
}

//clear scene and reset the particles to their initial state
void NGLScene::callClearAll()
{
    for (auto& p : m_particles)
    {
      p.age = p.maxAge;
      p.acc = ngl::Vec3(0,0,0);
      colour.r = 0.9;
      colour.g = 0.9;
      colour.b = 0.9;
      m_gravityIncrease = ngl::Vec3(1, 1, 1);
      m_alpha = 1.0;
      m_Spread = 1.0;
    }
}


//UI update the gravity
void NGLScene::updateGravity(int m_newGravity)
{
    m_yGravity = m_newGravity;
    m_gravity.set(0, -(m_yGravity), 0);
}


//UI update inititial velocity
void NGLScene::updateVelocity(double m_newVelocity)
{
    m_yInitialVelocity = m_newVelocity;
    m_initialVel.set(0,m_yInitialVelocity,0);
}


//UI update Age
void NGLScene::updateAge(double m_newAge)
{
    for (auto& p : m_particles)
    {
        p.maxAge = m_newAge;
    }
}


//UI updateSize
void NGLScene::updateSize(int m_newSize)
{
    size.x = (static_cast<float>(m_newSize))/30.0;
    size.y = (static_cast<float>(m_newSize))/30.0;
    size.z = (static_cast<float>(m_newSize))/30.0;
}


//UI updateZoom
void NGLScene::updateZoom(int m_newZoom)
{
    m_Zoom = m_newZoom;
}


//UI updateSpread
void NGLScene::updateSpread(int m_newSpread)
{
   m_Spread = (static_cast<float>(m_newSpread))/10.00;
}


void NGLScene::updateFadeOverTime(int m_newFadeOverTime)
{
    m_fadeOverTime = (static_cast<float>(m_newFadeOverTime))/100000000.00;
}


//UI call square explosion
void NGLScene::callEmitParticles()
{
    emitParticles(m_numParticles);
}


//UI call spherical explosion
void NGLScene::callSphericalParticles()
{
    sphericalParticles(m_numParticles);
}


//UI call triangle explosion
void NGLScene::callTriangleParticles()
{
    triangleParticles(m_numParticles);
}


//UI call implode explosion
void NGLScene::callImplodeExplosion()
{
    implodeExplosion(m_numParticles);
}


//UI call cylindrical explosion
void NGLScene::callCylindricalExplosion()
{
    cylindricalExplosion(m_numParticles);
}


//UI call torus explosion
void NGLScene::callTorusExplosion()
{
    torusExplosion(m_numParticles);
}


//UI update the number of particles
void NGLScene::updateNumParticles(int m_newNumParticles)
{
    m_numParticles = m_newNumParticles;
}


//UI update Emitter X pos
void NGLScene::updateXPos(float m_newX)
{
    m_posX = m_newX;
    for (auto& p: m_particles)
    {
        p.pos.set(m_posX,m_posY,m_posZ);
    }
}


//UI update Emitter Y pos
void NGLScene::updateYPos(float m_newY)
{
    m_posY = m_newY;
    for (auto& p: m_particles)
    {
        p.pos.set(m_posX,m_posY,m_posZ);
    }
}


//UI update Emitter Z pos
void NGLScene::updateZPos(float m_newZ)
{
    m_posZ = m_newZ;
    for (auto& p: m_particles)
    {
        p.pos.set(m_posX,m_posY,m_posZ);
    }
}


//Square explosion
void NGLScene::emitParticles(size_t _n)
{
  m_particles.resize(_n);
  for (auto& p : m_particles)
  {
    //get random values for x,y,z between a specfied region resulting in a cuboid shape
    float x = ((rand() % 100) / (20.0f) - (2.5f));
    float y = ((rand() % 50) / (20.0f) + (1.25f));
    float z = ((rand() % 100) / (20.0f) - (2.5f));

    p.pos.set(m_posX, m_posY, m_posZ);

    //set other parameters
    p.dir = ngl::Vec3(x*m_Spread, y*m_Spread, z*m_Spread);
    m_gravityIncrease = ngl::Vec3(1, 1, 1);
    p.age = (float)ngl::Random::randomPositiveNumber(p.maxAge);
    p.speed = 1.0;
    p.acc = ngl::Vec3(1, 1, 1);
    m_alpha = 1.0;
  }
}


//Spherical explosion
void NGLScene::sphericalParticles(size_t _n)
{
  m_particles.resize(_n);
  for (auto& p : m_particles)
  {
    //get random x,y,z values. define the sphere using spherical coordinates r, phi, theta
    float theta = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 5.0f * M_PI *m_Spread;
    float phi = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 5.0f * M_PI *m_Spread;
    float speed = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) *m_Spread;

    float x = speed * sin(phi) * cos(theta);
    float y = speed * sin(phi) * sin(theta);
    float z = speed * cos(phi);

    //set other parameters
    p.pos.set(m_posX, m_posY, m_posZ);
    p.age = (float)ngl::Random::randomPositiveNumber(p.maxAge);
    p.speed = 1.0;
    p.acc = ngl::Vec3(1, 1, 1);
    m_alpha = 1.0;
    m_gravityIncrease = ngl::Vec3(1, 1, 1);
    p.dir = ngl::Vec3(x, y, z);
  }
}


//Triangle explosion
void NGLScene::triangleParticles(size_t _n)
{
  m_particles.resize(_n);
  for (auto& p : m_particles)
  {
    p.pos.set(m_posX,m_posY,m_posZ);
    //get random x,y,z values. define the triangle using spherical coordinates but restricing r to [0,5], theta to [0, 2PI], phi to [0, PI]
    float theta = (rand() % 360 * M_PI / 180.0f);
    float phi = (rand() % 180 * M_PI / 180.0f) ;
    float r = (rand() % int(5 * 100) / 100.0f) ;

    float x = r * sin(phi) * cos(theta);
    float y = r * sin(phi) * sin(theta);
    float z = r * cos(phi);

    p.dir = ngl::Vec3(x* m_Spread, y* m_Spread, z* m_Spread);
    m_gravityIncrease = ngl::Vec3(1, 1, 1);

    p.age = (float)ngl::Random::randomPositiveNumber(p.maxAge);
    p.speed = r;
    p.acc = ngl::Vec3(1, 1, 1);
  }
  m_alpha = 1.0;
}


//Implode explosion
void NGLScene::implodeExplosion(size_t _n)
{
    m_particles.resize(_n);
    for (auto& p : m_particles)
    {
        p.pos.set(0, 0, 0);
        p.age = (float)ngl::Random::randomPositiveNumber(p.maxAge);

        //get random values for x,y,z. calculates the Cartesian coordinates (x, y, z) of a point in 3D space using trigonometric functions
        float x = cos(p.age) * sin(p.age);
        float y = sin(p.age) * cos(p.age);
        float z = tan(p.age) * sin(p.age) + sin((float)ngl::Random::randomPositiveNumber(10));

        p.pos.set(x, y, z);
        p.dir = ngl::Vec3(x*m_Spread, y*m_Spread, z*m_Spread);
        m_gravityIncrease = ngl::Vec3(1, -3, 1);

        // set the initial velocity and acceleration of the particle
        p.speed = -10;
        p.acc = ngl::Vec3(x*100, -y/100, z*100);

        p.age = (float)ngl::Random::randomPositiveNumber(p.maxAge);;
    }
    m_alpha = 1.0;
}

//Cylindrical explosion
void NGLScene::cylindricalExplosion(size_t _n)
{
    float radius = 0.2 * m_Spread;
    float height = 5 * m_Spread;

    m_particles.resize(_n);
    for (auto& p : m_particles)
    {
        // Generate random x and y coordinates within circle
        double rand_radius = radius * sqrt((double)rand() / RAND_MAX);
        double rand_angle = 2.0 * M_PI * ((double)rand() / RAND_MAX);
        double x = rand_radius * cos(rand_angle);
        double y = rand_radius * sin(rand_angle);

        // Generate random z coordinate within cylinder height
        double z = height * ((double)rand() / RAND_MAX);

        //set other parameters
        p.pos.set(m_posX, m_posY, m_posZ);
        p.age = (float)ngl::Random::randomPositiveNumber(p.maxAge);
        p.speed = 1.0;
        p.acc = ngl::Vec3(1, 1, 1);
        m_alpha = 1.0;
        m_gravityIncrease = ngl::Vec3(1, 1, 1);
        p.dir = ngl::Vec3(x, y, z);
    }
}


//Torus explosion
void NGLScene::torusExplosion(size_t _n)
{
    float majorRadius = 5.0 * m_Spread;
    float minorRadius = 2.0 * m_Spread;

    m_particles.resize(_n);
    for (auto& p : m_particles)
    {
        // Generate random angles within torus

        float phi = 2.0 * M_PI * ((float)rand() / RAND_MAX);
        float theta = 2.0 * M_PI * ((float)rand() / RAND_MAX);

        // Calculate torus position based on phi and theta
        float x = (majorRadius + minorRadius * cos(theta)) * cos(phi);
        float y = (majorRadius + minorRadius * cos(theta)) * sin(phi);
        float z = minorRadius * sin(theta);

        // Set particle position
        p.pos.set(m_posX,m_posY,m_posZ);
        p.age = (float)ngl::Random::randomPositiveNumber(p.maxAge);
        p.speed = 1.0;
        p.acc = ngl::Vec3(1, 1, 1);
        m_alpha = 1.0;
        m_gravityIncrease = ngl::Vec3(1, 1, 1);
        p.dir = ngl::Vec3(x, y, z);
    }
}


//Update renderer
void NGLScene::paintGL()
{
  // clear the screen and depth buffer
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glViewport(0,0,m_win.width,m_win.height);

  auto xrot=ngl::Mat4::rotateX(m_win.spinXFace);
  auto yrot=ngl::Mat4::rotateY(m_win.spinYFace);
  m_globalMouseTX = xrot * yrot;
  m_globalMouseTX.m_m[3][0] = m_modelPos.m_x;
  m_globalMouseTX.m_m[3][1] = m_modelPos.m_y;
  m_globalMouseTX.m_m[3][2] = m_modelPos.m_z;

  //camera setup
  ngl::Vec3 eye(0.0f, 20.0f, m_Zoom);
  ngl::Vec3 target(0.0f, 50.0f, 0.0f);
  ngl::Vec3 up(0.0f, 1.0f, 0.0f);
  m_view = ngl::lookAt(eye, target, up);

  //camera values
  float fov = 60.0f;
  float aspect = 1.0f;
  float near = 0.001f;
  float far = m_Zoom * 10.0f;
  //set the values for the initial velocity and gravity
  m_gravity.set(0, -(m_yGravity), 0);
  m_initialVel.set(0,m_yInitialVelocity,0);

  m_project=ngl::perspective(fov, aspect, near, far);

  //create ground plane
  ngl::ShaderLib::setUniform("Colour", 0.1f,0.1f,0.1f,1.0f);
  ngl::ShaderLib::setUniform("MVP",m_project*m_view * m_globalMouseTX);
  ngl::VAOPrimitives::draw("ground");
  //create and draw the particles
  makeParticles();
  update();
}


void NGLScene::makeParticles()
{
  // Calculate the elapsed time since the last frame
  std::chrono::time_point<std::chrono::high_resolution_clock> now = std::chrono::high_resolution_clock::now();
  float elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - m_lastFrameTime).count() / 1000.0f;

  m_lastFrameTime = now;
  bool allParticlesReachedMaxAge = true;
  for (auto& p : m_particles)
  {
    p.speed += elapsed*m_gravity.length()* m_gravityIncrease.length();
    ngl::Vec3 delta = m_gravity * m_gravityIncrease * p.speed * elapsed * p.acc;
    p.pos += delta;

    // If the particle is still alive, draw it
    if (p.age < p.maxAge)
    {

      //check collision with ground, make them no longer alive if true
      if (p.pos[1] < -1.0 && p.age<1)
      {
        p.age = p.maxAge;
        allParticlesReachedMaxAge = false;
        continue;
      }

      p.pos += m_initialVel+(p.dir * p.speed * elapsed);

      // Update the particle age
      p.age += elapsed;

      allParticlesReachedMaxAge = false;

      ngl::Transformation tx;
      tx.setPosition(p.pos);

      tx.setScale(size.x, size.y, size.z);

      //apply a random colour to the particles if they reach their max height
      if (delta[1] < -1.0)
      {
        srand(time(0));
        float random_numberR = static_cast<float>(rand()) / RAND_MAX;
        float random_numberG = static_cast<float>(rand()) / RAND_MAX;
        float random_numberB = static_cast<float>(rand()) / RAND_MAX;
        colour.r = random_numberR;
        colour.g = random_numberG;
        colour.b = random_numberB;
      }

      //decrease the alpha based on time and user input
      m_alpha -= m_fadeOverTime/(elapsed*2);

      ngl::ShaderLib::setUniform("Colour", colour.r,colour.g,colour.b,m_alpha);
      ngl::ShaderLib::setUniform("MVP", m_project * m_view * tx.getMatrix());
      ngl::VAOPrimitives::draw("sphere");
    }
  }

  // If all particles have reached the maximum age and reset them
  if (allParticlesReachedMaxAge)
  {
    for (auto& p : m_particles)
    {
      p.acc = ngl::Vec3(0,0,0);
      colour.r = 0.9;
      colour.g = 0.9;
      colour.b = 0.9;
      m_gravityIncrease = ngl::Vec3(1, 1, 1);
      m_alpha = 1.0;
    }
  }
}


void NGLScene::keyPressEvent(QKeyEvent *_event)
{
  // called everytime the main window receives a key event
  switch (_event->key())
  {
  // escape key to quite
  case Qt::Key_Escape : QGuiApplication::exit(EXIT_SUCCESS); break;
  case Qt::Key_Space :
      m_win.spinXFace=0;
      m_win.spinYFace=0;
      m_modelPos.set(ngl::Vec3::zero());

  break;
  default : break;
  }
  //update the GLWindow and re-draw
    update();
}

void NGLScene::timerEvent(QTimerEvent *)
{
  update();
}
