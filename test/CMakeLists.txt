cmake_minimum_required(VERSION 3.8)

set(RBTest RailwayBuilderTests)

set (SOURCES
    allTests.cpp
    elementTest.cpp
)

add_executable(${RBTest} ${SOURCES})
target_link_libraries(${RBTest} PUBLIC
	gtest_main
        RailwayBuilderLib
)

add_test(
	NAME ${RBTest}
	COMMAND ${RBTest}
)
