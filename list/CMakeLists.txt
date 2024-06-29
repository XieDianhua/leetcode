cmake_minimum_required(VERSION 3.10) 

project(List)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_executable(removeElements src/removeElements.cpp)

# add_executable(linkedlist src/linkedlist.cpp)

# add_executable(reverseList src/reverseList.cpp)

