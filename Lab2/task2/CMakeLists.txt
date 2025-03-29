# Lab2 Task 2
add_executable(task2
    main.cpp
    "../include/ImageFilters.cpp"
    "../include/ImageFilters.h"
    "../include/myutils.cpp"
    "../include/myutils.h"
)
target_link_libraries(task2 ${OpenCV_LIBS})
