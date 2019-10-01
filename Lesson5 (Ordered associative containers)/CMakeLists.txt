cmake_minimum_required(VERSION 3.5)

project(hw_3_tests LANGUAGES CXX)


add_definitions(-DGTEST_LANGUAGE_CXX11)

find_package(Threads REQUIRED)

if ($ENV{GOOGLETEST_DIR})
    set(GOOGLETEST_DIR $ENV{GOOGLETEST_DIR})
else ()
    message(WARNING "Using googletest src dir specified at Qt Creator wizard")
    set(GOOGLETEST_DIR "/home/anyo/Projects/GoogleTests/googletest-src")
endif ()
if (EXISTS ${GOOGLETEST_DIR})
    set(GTestSrc ${GOOGLETEST_DIR}/googletest)
    set(GMockSrc ${GOOGLETEST_DIR}/googlemock)
else ()
    message( FATAL_ERROR "No googletest src dir found - set GOOGLETEST_DIR to enable!")
endif ()


include_directories(${GTestSrc} ${GTestSrc}/include ${GMockSrc} ${GMockSrc}/include)

add_executable(hw_3_tests main.cpp tst_hw_3_tests.h
               ${GTestSrc}/src/gtest-all.cc
               ${GMockSrc}/src/gmock-all.cc)
add_test(hw_3_tests COMMAND hw_3_tests)
target_link_libraries(hw_3_tests PRIVATE Threads::Threads)

