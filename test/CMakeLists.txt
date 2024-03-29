set( RBTEST ${RB}Tests )

file( GLOB TEST_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp )

include( FetchContent )

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

set( gtest_force_shared_crt ON CACHE BOOL "" FORCE )
FetchContent_MakeAvailable( googletest )
add_executable( ${RBTEST} ${TEST_FILES} )
target_link_libraries( ${RBTEST} gtest_main )
target_link_libraries( ${RBTEST} ${RBLIB} )
target_include_directories( ${RBTEST} PRIVATE ${CMAKE_SOURCE_DIR} )

include( GoogleTest )
gtest_discover_tests( ${RBTEST} DISCOVERY_MODE PRE_TEST)
