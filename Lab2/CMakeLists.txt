cmake_minimum_required(VERSION 3.5)

project(Lab2 LANGUAGES CXX)

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
    include/ImageFilters.cpp
    include/ImageFilters.h
    include/myutils.cpp
    include/myutils.h
)
target_link_libraries(task2 ${OpenCV_LIBS})

# Task 3
add_executable(task3
    task3/main.cpp
    include/ImageFilters.cpp
    include/ImageFilters.h
    include/myutils.cpp
    include/myutils.h
)
target_link_libraries(task3 ${OpenCV_LIBS})

# Task 4
add_executable(task4
    task4/main.cpp
    include/ImageFilters.cpp
    include/ImageFilters.h
    include/myutils.cpp
    include/myutils.h
)
target_link_libraries(task4 ${OpenCV_LIBS})

# Task 5
#add_executable(task5 task5/main.cpp)
#target_link_libraries(task5 ${OpenCV_LIBS})

# Task 6
#add_executable(task6 task6/main.cpp)
#target_link_libraries(task6 ${OpenCV_LIBS})

#install(TARGETS Lab2
#    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
