cmake_minimum_required(VERSION 3.5)
if(NOT DEFINED CMAKE_TOOLCHAIN_FILE AND DEFINED ENV{CMAKE_TOOLCHAIN_FILE})
   set(CMAKE_TOOLCHAIN_FILE $ENV{CMAKE_TOOLCHAIN_FILE})
endif()

project(ExplosionGUIBUILD VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ${PROJECT_SOURCE_DIR}/ui)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(NGL CONFIG REQUIRED)




include_directories(${PROJECT_SOURCE_DIR}/include)


find_package(Qt5 COMPONENTS Widgets REQUIRED)
add_executable(ExplosionGUI)

target_sources(ExplosionGUI PRIVATE

    src/main.cpp
    src/mainwindow.cpp
    src/NGLScene.cpp
    src/NGLSceneMouseControls.cpp
    include/mainwindow.h
    include/NGLScene.h
    include/WindowParams.h
    ui/mainwindow.ui
    shaders/ParticleFragment.glsl
    shaders/ParticleVertex.glsl
)

target_link_libraries(ExplosionGUI PRIVATE NGL Qt5::Widgets)
