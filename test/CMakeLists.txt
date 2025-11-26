cmake_minimum_required(VERSION 3.31)

set(TEST_SOURCES
        runAllTests.cpp
        TestContoCorrente.cpp
        TestMovimenti.cpp
)


add_executable(runAllTests ${TEST_SOURCES})
message(STATUS "Creato target runAllTests")

set(GTEST_ROOT "/opt/homebrew/opt/googletest")

target_include_directories(runAllTests PRIVATE
        ${GTEST_ROOT}/include ${CMAKE_SOURCE_DIR}
)

target_link_libraries(runAllTests PRIVATE
        core
        ${GTEST_ROOT}/lib/libgtest.a
        ${GTEST_ROOT}/lib/libgtest_main.a
        pthread
)

