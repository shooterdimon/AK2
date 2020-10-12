cmake_minimum_required(VERSION 3.16.3)

project("lab2" VERSION 1.0)

add_library(calc STATIC calculator.cpp)
add_executable("${PROJECT_NAME}" main.cpp)
target_link_libraries("${PROJECT_NAME}" calc)
