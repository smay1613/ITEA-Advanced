CMAKE_MINIMUM_REQUIRED(VERSION 3.9)

project (unit_tests
         LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 11)

set(sources
    "${HM_FUNC_TEST_DIRECTORY}/src/main.cpp"
    "${HM_FUNC_TEST_DIRECTORY}/src/brackets_test.cpp")

set(headers
    "${HM_FUNC_TEST_DIRECTORY}/headers/brackets_test.h")

include_directories(unit_tests
    PRIVATE
        ${HM_FUNC_TEST_DIRECTORY}/headers
)

add_definitions(-DGTEST_LANGUAGE_CXX11)

include(AddGTestTest)

enable_testing()
add_gtest_test(${PROJECT_NAME} "${sources}" functions)
target_compile_options(unit_tests PRIVATE -Wmissing-declarations)


get_filename_component(HW_TESTING_REPO_DIRECTORY "${HM_FUNC_TEST_ROOT_DIRECTORY}" DIRECTORY)

include_directories(
        PRIVATE
        ${HW_TESTING_REPO_DIRECTORY}/include
)


