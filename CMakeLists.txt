cmake_minimum_required(VERSION 3.0)
project(oop-exercises)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin/)

add_executable(check check.cpp)
add_executable(create-exercise create-exercise.cpp)

install(TARGETS check create-exercise DESTINATION bin)
