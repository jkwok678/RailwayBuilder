set(RBTest RailwayBuilderTests)

set (SOURCES
    allTests.cpp
    elementTest.cpp
)

add_executable(${RBTest} ${SOURCES})
target_link_libraries(${RBTest} PUBLIC
        gtest_main
        ${RBLIB}
)
target_include_directories( ${RBTest} PRIVATE ${CMAKE_SOURCE_DIR} )
add_test(
        NAME ${RBTest}
        COMMAND ${RBTest}
)
