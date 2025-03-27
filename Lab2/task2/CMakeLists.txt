# Lab2 Task 2
add_executable(task2
    main.cpp
    ImageFilters.cpp
    ImageFilters.h
    "../include/myutils.cpp"
    "../include/myutils.h"
)
target_link_libraries(task2 ${OpenCV_LIBS})
