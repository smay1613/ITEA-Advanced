cmake_minimum_required(VERSION 3.5)

project(task5 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-std=c++17 -lstdc++fs")

add_executable(task5 main.cpp)
target_link_libraries(task5 stdc++fs)

