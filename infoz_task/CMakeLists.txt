cmake_minimum_required(VERSION 3.17)
project(infoz_task)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -pthread")
add_compile_options(-fsanitize=leak,address)
add_link_options(-fsanitize=leak,address)
add_executable(infoz_task main.cpp)