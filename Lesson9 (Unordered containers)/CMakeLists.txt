cmake_minimum_required(VERSION 3.5)

project(Unordered_hometaskFINAL LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Unordered_hometaskFINAL main.cpp ForFileDirectory.cpp ForFileDirectory.h)

target_link_libraries(Unordered_hometaskFINAL -lstdc++fs)
