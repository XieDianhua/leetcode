cmake_minimum_required(VERSION 3.10) 

project(array)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(test src/test.cpp)

add_executable(search src/search.cpp)

add_executable(removeElement src/removeElement.cpp)

add_executable(minSubArrayLen src/minSubArrayLen.cpp)

add_executable(sortedSquares src/sortedSquares.cpp)

add_executable(generateMatrix src/generateMatrix.cpp)
