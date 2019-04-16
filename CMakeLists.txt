cmake_minimum_required(VERSION 3.0)
project(oop-exercises)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin/)

add_executable(check check.cpp)
add_executable(create-exercise create-exercise.cpp)
add_executable(cpp17 testcpp17.cpp)

target_link_libraries(cpp17 stdc++fs) 

install(TARGETS check create-exercise DESTINATION bin)
