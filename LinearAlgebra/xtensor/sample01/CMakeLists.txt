cmake_minimum_required(VERSION 3.10)
project(sample01)

set(CMAKE_CXX_STANDARD 23)

find_package(xtensor REQUIRED)
add_executable(app src/main.cpp)
target_link_libraries(app xtensor)

