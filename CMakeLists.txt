cmake_minimum_required(VERSION 3.19)
project(a_star)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${CMAKE_SOURCE_DIR}/lib)

add_executable(a_star src/main.cpp src/aStar.cpp)

target_link_libraries(a_star sfml-graphics sfml-window sfml-system)