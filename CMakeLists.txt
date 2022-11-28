cmake_minimum_required(VERSION 3.21)
project(drzewobinarne)

set(CMAKE_CXX_STANDARD 14)

add_executable(drzewobinarne main.cpp listy/node.h drzewobinarne/tree.h)
