cmake_minimum_required(VERSION 3.0)
project(oop-exercises)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin/)

SET(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "D:/Programme/Boost/boost_1_69_0/lib")
set(BOOST_LIBRARYDIR D:/Programme/Boost/boost_1_69_0/lib)
find_package(Boost COMPONENTS system filesystem REQUIRED)
IF (Boost_FOUND)
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
    ADD_DEFINITIONS( "-DHAS_BOOST" )
ENDIF()

add_executable(check check.cpp)
add_executable(create-exercise create-exercise.cpp)
add_executable(cpp17 testcpp17.cpp)
target_link_libraries(cpp17 stdc++fs)

install(TARGETS check create-exercise DESTINATION bin)
