cmake_minimum_required(VERSION 3.5)

project(Task_1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(BUILD_TESTS on)

if (BUILD_TESTS)
    configure_file(CMakeLists.txt.in
            googletest-download/CMakeLists.txt)
    execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
            WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
    execute_process(COMMAND ${CMAKE_COMMAND} --build .
            WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )

    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    
    add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
            ${CMAKE_BINARY_DIR}/googletest-build)
else()
    add_executable(Task_1 Brackets_valid.cpp)
endif()


if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include"
            "${gmock_SOURCE_DIR}/include")
endif()
if (BUILD_TESTS)


enable_testing()
add_subdirectory(test)
endif()
set(SOURCE_FILES Brackets_valid.cpp)
add_library(for_testing ${SOURCE_FILES})
