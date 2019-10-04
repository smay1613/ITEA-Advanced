include_directories("${PROJECT_SOURCE_DIR}")

# First Simple Google Test
add_executable(testing testing.cpp)
target_link_libraries(testing gtest gmock_main)
add_test(NAME testing_test COMMAND testing)


