cmake_minimum_required(VERSION 3.19)

set( RB RailwayBuilder)

set( RBLIB RailwayBuilderLibrary )

project( ${RB} LANGUAGES CXX )

# Find Qt Core, Gui & Widgets
find_package( QT NAMES Qt6 COMPONENTS Core REQUIRED )
find_package( Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Gui Core )

set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_AUTOUIC ON )
set( CMAKE_AUTOMOC ON )
set( CMAKE_AUTORCC ON )

enable_testing()

# Glob for all library source files
file( GLOB SRC_FILES ${CMAKE_SOURCE_DIR}/*.cpp *.h )

# Identify the main source file
set( MAIN_SRC ${CMAKE_SOURCE_DIR}/main.cpp )

# Remove the main source as this will form the executable
list( REMOVE_ITEM SRC_FILES ${MAIN_SRC} )

add_library( ${RBLIB} STATIC ${SRC_FILES} )
# Link the static lib to to Qt Core, Gui & Widgets
target_link_libraries( ${RBLIB} PUBLIC Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Gui Qt${QT_VERSION_MAJOR}::Widgets )

add_subdirectory(test)

# add the real executable with only the main.cpp
qt6_add_resources( SRC_FILES resources.qrc)

add_executable( ${RB} ${MAIN_SRC} ${SRC_FILES})
target_link_libraries( ${RB} PUBLIC ${RBLIB} )
target_include_directories( ${RB} PRIVATE ${CMAKE_SOURCE_DIR} )

set_target_properties( ${RB} PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)
