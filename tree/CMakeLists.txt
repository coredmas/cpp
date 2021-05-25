cmake_minimum_required(VERSION 3.17)
project(tree C)

set(CMAKE_C_STANDARD 99)
add_compile_options(-fsanitize=leak,address)
add_link_options(-fsanitize=leak,address)
add_executable(tree main.c)