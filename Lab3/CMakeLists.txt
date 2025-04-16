cmake_minimum_required(VERSION 3.5)

project(Lab3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

include_directories(include)

# Task 1
add_executable(task1
    task1/main.cpp
    include/myutils.cpp
    include/myutils.h
)
target_link_libraries(task1 ${OpenCV_LIBS})

# Task 2
add_executable(task2
    task2/main.cpp
    include/myutils.cpp
    include/myutils.h
    include/ImageFilters.cpp
    include/ImageFilters.h
)
target_link_libraries(task2 ${OpenCV_LIBS})

# Task 3

# Task 4

# Task 5

#install(TARGETS Lab2
#    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
