#ifndef NGLSCENE_H_
#define NGLSCENE_H_
#include <ngl/Vec3.h>
#include <ngl/Mat4.h>
#include "WindowParams.h"

#include <QOpenGLWidget>
#include <vector>
//----------------------------------------------------------------------------------------------------------------------
/// @file NGLScene.h
/// @brief this class inherits from the Qt OpenGLWindow and allows us to use NGL to draw OpenGL
/// @author Jonathan Macey
/// @version 1.0
/// @date 10/9/13
/// Revision History :
/// This is an initial version used for the new NGL6 / Qt 5 demos
/// @class NGLScene
/// @brief our main glwindow widget for NGL applications all drawing elements are
/// put in this file
//----------------------------------------------------------------------------------------------------------------------

class NGLScene : public QOpenGLWidget
{
    Q_OBJECT
  public:
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief ctor for our NGL drawing class
    /// @param [in] parent the parent window to the class
    //----------------------------------------------------------------------------------------------------------------------
    NGLScene(QWidget *_parent);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief dtor must close down ngl and release OpenGL resources
    //----------------------------------------------------------------------------------------------------------------------

    ~NGLScene() override;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief the initialize class is called once when the window is created and we have a valid GL context
    /// use this to setup any default GL stuff
    //----------------------------------------------------------------------------------------------------------------------
    void initializeGL() override;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief this is called everytime we want to draw the scene
    //----------------------------------------------------------------------------------------------------------------------
    void paintGL() override;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief this is called everytime we resize the window
    //----------------------------------------------------------------------------------------------------------------------
    void resizeGL(int _w, int _h) override;

//QT slots, function definitions for each UI input
public slots :
    //Explosion buttons
    void callEmitParticles();
    void callSphericalParticles();
    void callTriangleParticles();
    void callImplodeExplosion();
    void callCylindricalExplosion();
    void callTorusExplosion();

    //Clear all button
    void callClearAll();

    //Particle controls buttons
    void updateNumParticles(int m_newNumParticles);
    void updateGravity(int m_newGravity);
    void updateVelocity(double m_newVelocity);
    void updateAge(double m_newAge);
    void updateSize(int m_newSize);
    void updateXPos(float m_newX);
    void updateYPos(float m_newY);
    void updateZPos(float m_newZ);
    void updateZoom(int m_newZoom);
    void updateSpread(int m_newSpread);
    void updateFadeOverTime(int m_newFadeOverTime);

private:

    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Qt Event called when a key is pressed
    /// @param [in] _event the Qt event to query for size etc
    //----------------------------------------------------------------------------------------------------------------------
    void keyPressEvent(QKeyEvent *_event) override;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called every time a mouse is moved
    /// @param _event the Qt Event structure
    //----------------------------------------------------------------------------------------------------------------------
    void mouseMoveEvent (QMouseEvent * _event ) override;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called everytime the mouse button is pressed
    /// inherited from QObject and overridden here.
    /// @param _event the Qt Event structure
    //----------------------------------------------------------------------------------------------------------------------
    void mousePressEvent ( QMouseEvent *_event) override;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called everytime the mouse button is released
    /// inherited from QObject and overridden here.
    /// @param _event the Qt Event structure
    //----------------------------------------------------------------------------------------------------------------------
    void mouseReleaseEvent ( QMouseEvent *_event ) override;

    //----------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called everytime the mouse wheel is moved
    /// inherited from QObject and overridden here.
    /// @param _event the Qt Event structure
    //----------------------------------------------------------------------------------------------------------------------
    void wheelEvent( QWheelEvent *_event) override;
    /// @brief windows parameters for mouse control etc.
    WinParams m_win;

    /// position for our model
    ngl::Vec3 m_modelPos;
    ngl::Mat4 m_view;
    ngl::Mat4 m_project;
    ngl::Mat4 m_globalMouseTX;

    void timerEvent(QTimerEvent * );

    //The struct for the particles including some initial parameters
    struct Particle
    {
      ngl::Vec3 pos;
      ngl::Vec3 dir;
      int life = 10;
      float age;
      double maxAge = 5.0;
      float  speed;
      ngl::Vec3 acc;
    }particle;

    //Struct for the size of the particle
    struct particleSize
    {
      float x = 0.3;
      float y = 0.3;
      float z = 0.3;
    }size;

    //Struct for the particle colour
    struct Colour
    {
      float r = 0.9;
      float g = 0.9;
      float b = 0.9;
    }colour;

    
    std::vector<Particle> m_particles;

    //Gravity and velocity vectors
    ngl::Vec3 m_gravity;
    ngl::Vec3 m_initialVel;
    ngl::Vec3 m_gravityIncrease;

    //void createParticles(size_t _n);

    //function definitions for explosion types
    void emitParticles(size_t _n);
    void sphericalParticles(size_t _n);
    void triangleParticles(size_t _n);
    void implodeExplosion(size_t _n);
    void cylindricalExplosion(size_t _n);
    void torusExplosion(size_t _n);

    //This is called to create the particles and fill the structs with values
    void makeParticles();

    //Initial particle attributes
    int m_numParticles = 1000;
    float m_yGravity = 10.0;
    double m_yInitialVelocity = 2.0;
    float m_posX, m_posY, m_posZ = 0.0f;
    float m_Spread = 1.0f;
    float m_fadeOverTime = 0.0f;
    float m_alpha = 1.0f;

    //Camera zoom variable
    int m_Zoom = 200;
    
    //Timer
    std::chrono::high_resolution_clock::time_point m_lastFrameTime;
};

#endif