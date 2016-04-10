cmake_minimum_required(VERSION 3.5)
project(De_Novo_DNA_Builder)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp digraph.cpp digraph.h)
add_executable(De_Novo_DNA_Builder ${SOURCE_FILES})