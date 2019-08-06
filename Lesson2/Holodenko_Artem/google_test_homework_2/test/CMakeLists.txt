include_directories("${PROJECT_SOURCE_DIR}")

add_executable(main main.cpp)
target_link_libraries(main gtest)



add_executable(first_t test_program_1.cpp)
target_link_libraries(first_t gtest gmock_main)
add_test(NAME first_test COMMAND first_t)

add_executable(second_t test_program_2.cpp)
target_link_libraries(second_t gtest gmock_main)
add_test(NAME second_test COMMAND second_t)
