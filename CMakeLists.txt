cmake_minimum_required(VERSION 3.10)
project(CFString_Generator)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} main.cpp Generator.cpp ExpansionTree.cpp FileHandler.cpp)