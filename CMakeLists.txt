cmake_minimum_required(VERSION 3.0.0)
project(GIMPSEP VERSION 0.1.0)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(header PUBLIC ${HEADER_FOLDER})
include_directories(cpp PUBLIC ${CPP_FOLDER})

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

set(HEADER_FOLDER ${YOUR_DIRECTORY}/header)
set(HEADER_FILE ${HEADER_FOLDER}/OpenCV.h)

set(CPP_FOLDER ${YOUR_DIRECTORY}/cpp)
set(CPP_FILE ${CPP_FOLDER}/OpenCV.cpp)
set(SOURCES main.cpp ${CPP_FILE} ${HEADER_FILE})

include(CPack)

add_executable(GIMPSEP main.cpp)

target_link_libraries(GIMPSEP ${OpenCV_LIBS})
target_link_libraries(GIMPSEP ${CPP_FILE})