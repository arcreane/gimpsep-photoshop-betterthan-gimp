cmake_minimum_required(VERSION 3.21)
project(GIMPSEP)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV)

include_directories(${OpenCV_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 14)

add_executable(GIMPSEP main.cpp OpenCV.cpp OpenCV.h "Resize.cpp" "Resize.h" "Brightness.cpp" "Brightness.h" "Video.cpp" "Video.h")

target_link_libraries(GIMPSEP ${OpenCV_LIBS})
