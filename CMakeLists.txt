cmake_minimum_required(VERSION 3.16)
 
project(MPCsolve)
 
set(CMAKE_CXX_FLAGS "-std=c++11")

link_directories("/usr/local/lib")
include_directories("/usr/local/include")
include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(third_party/qpOASES)

file(GLOB_RECURSE SRC_LIST
    "src/*/*.cpp"
    "src/*/*.h"
)

add_executable(main main.cpp)
target_link_libraries(main qpOASES)