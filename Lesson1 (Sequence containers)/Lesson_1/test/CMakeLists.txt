include_directories("${PROJECT_SOURCE_DIR}")

add_executable(main main.cpp)
target_link_libraries(main gtest)

add_executable(simple simple.cpp)
target_link_libraries(simple gtest gmock_main TestExample)
add_test(NAME simple_test COMMAND simple)
