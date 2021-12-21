set( RBTest ${RBUILD}Tests )

file( GLOB TEST_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*Test.cpp )

foreach( TEST ${TEST_FILES} )
    get_filename_component( EXECUTABLE ${TEST} NAME_WLE )
    add_executable( ${EXECUTABLE} ${TEST} )
    target_include_directories( ${EXECUTABLE} ${CMAKE_SOURCE_DIR} )
    target_link_libraries(${EXECUTABLE} PUBLIC gtest_main ${RBUILDLIB})
    add_test(
        NAME ${EXECUTABLE}
        COMMAND ${EXECUTABLE}
    )
endforeach()
