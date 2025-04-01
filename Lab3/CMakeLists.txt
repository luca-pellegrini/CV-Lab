cmake_minimum_required(VERSION 3.5)

project(Lab3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_subdirectory(task1)
add_subdirectory(task2)
#add_subdirectory(task3)
#add_subdirectory(task4)
#add_subdirectory(task5)
#add_subdirectory(task6)

#install(TARGETS Lab2
#    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
