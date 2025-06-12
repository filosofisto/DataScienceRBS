cmake_minimum_required(VERSION 3.12)
project(IF_IDF)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_BUILD_TYPE Debug)

# Application executable
add_executable(App src/main.cpp src/ifidf.cpp)


