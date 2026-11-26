cmake_minimum_required(VERSION 3.25)

project(add_app LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.17.0
    GIT_SHALLOW    TRUE
    FIND_PACKAGE_ARGS NAMES GTest
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(add_app src/main.cpp)
target_include_directories(add_app PRIVATE src)

add_executable(add_tests tests/add_test.cpp)
target_include_directories(add_tests PRIVATE src)
target_link_libraries(add_tests PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(add_tests DISCOVERY_MODE PRE_TEST)
