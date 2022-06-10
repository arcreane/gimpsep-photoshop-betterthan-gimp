cmake_minimum_required(VERSION 3.21)
project(GIMPSEP)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV)

include_directories(${OpenCV_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 14)

add_executable(GIMPSEP "Image.cpp" "Image.h" "ResizeImage.cpp" "ResizeImage.h"
        "DilateImage.cpp" "DilateImage.h" "ErodeImage.cpp" "ErodeImage.h"
        "Folder.cpp" "Folder.h" "CannyEdgeDetection.cpp" "CannyEdgeDetection.h"
        Stitching.cpp Stitching.h
        main.cpp)

target_link_libraries(GIMPSEP ${OpenCV_LIBS})
