cmake_minimum_required(VERSION 3.10)
project(sample01)

set(CMAKE_CXX_STANDARD 23)

add_executable(app src/main.cpp)
find_package(xtensor REQUIRED)
target_link_libraries(app PRIVATE xtensor)
#find_package(xtensor-blas REQUIRED)
#target_link_libraries(app PRIVATE xtensor xtensor-blas)
