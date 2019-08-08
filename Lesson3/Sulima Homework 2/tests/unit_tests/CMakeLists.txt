CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

project (unit_tests
         LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 11)

set(sources
    "${DENIS_DIRECTORY}/src/main.cpp"
    "${DENIS_DIRECTORY}/src/homeworklesson2.cpp")

set(headers
    "${DENIS_DIRECTORY}/headers/homeworklesson2.h")

include_directories(unit_tests
    PRIVATE
        ${DENIS_DIRECTORY}/headers
)

add_definitions(-DGTEST_LANGUAGE_CXX11)

include(AddGTestTest)

enable_testing()
add_gtest_test(${PROJECT_NAME} "${sources}" DenisHomeWork)

get_filename_component(DENIS_REPO_DIRECTORY "${DENIS_ROOT_DIRECTORY}" DIRECTORY)

include_directories(
        PRIVATE
        ${DENIS_REPO_DIRECTORY}/include
        )
