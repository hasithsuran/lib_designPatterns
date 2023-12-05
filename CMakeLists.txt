CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
PROJECT(cppDemo)
set (CMAKE_CXX_STANDARD 17)

set(sources main.cpp)
add_executable(${PROJECT_NAME} ${sources})
include_directories(include)