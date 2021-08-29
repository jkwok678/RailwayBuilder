cmake_minimum_required(VERSION 3.5)

project(RailwayBuilder VERSION 0.1 LANGUAGES CXX)

# Find Qt Core, Gui & Widgets
find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Gui Core)
# Create a static lib project to contain all the classes
add_library(RailwayBuilderLib STATIC borderlayout.cpp
    borderlayout.h
    mode.h
    elementChosen.h
    canvas.cpp
    canvas.h
    element.cpp
    element.h
    track.cpp
    track.h
    map.cpp
    map.h
    window.cpp
    window.h
    )
# Add an alias to the library to avoid typos
add_library(RailwayBuilderLib::RailwayBuilderLib ALIAS RailwayBuilderLib)
# Better version of set(CMAKE_INCLUDE_CURRENT_DIR ON)
target_include_directories(RailwayBuilderLib PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
# Link the static lib to to Qt Core, Gui & Widgets
target_link_libraries(RailwayBuilderLib PUBLIC Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Gui Qt${QT_VERSION_MAJOR}::Widgets)
# Better version of
# set(CMAKE_AUTOUIC ON)
# set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTORCC ON)
# set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
set_target_properties(RailwayBuilderLib PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
    AUTORCC ON
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)
# add the real executable with only the main.cpp
qt6_add_resources(SOURCES resources.qrc)
add_executable(RailwayBuilder main.cpp ${SOURCES})

# link to the static library
target_link_libraries(RailwayBuilder PUBLIC RailwayBuilderLib::RailwayBuilderLib )
set_target_properties(RailwayBuilder PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)
