cmake_minimum_required(VERSION 3.8)

set(RB RailwayBuilder)

set(RBLib RailwayBuilderLib)

project(${RB} CXX)

# Find Qt Core, Gui & Widgets
find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Gui Core)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

enable_testing()

add_subdirectory(googletest)

set(Sources
    mode.h
    elementChosen.h
    borderlayout.h
    borderlayout.cpp
    window.h
    window.cpp
    canvas.h
    canvas.cpp
    element.h
    element.cpp
    track.h
    track.cpp
    map.h
    map.cpp
    message.h
    message.cpp
    filesaver.h
    filesaver.cpp
)

add_library(${RBLib} STATIC ${Sources})

# Link the static lib to to Qt Core, Gui & Widgets
target_link_libraries(${RBLib} PUBLIC Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Gui Qt${QT_VERSION_MAJOR}::Widgets)

add_subdirectory(test)

# add the real executable with only the main.cpp
qt6_add_resources(Sources resources.qrc)
add_executable(${RB} main.cpp ${Sources})
target_link_libraries(RailwayBuilder PUBLIC ${RBLib} )
set_target_properties(${RB} PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)
