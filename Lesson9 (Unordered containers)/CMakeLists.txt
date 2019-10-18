cmake_minimum_required(VERSION 3.5)

project(unordered_hw LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

link_libraries(stdc++fs)

add_executable(unordered_hw main.cpp)
