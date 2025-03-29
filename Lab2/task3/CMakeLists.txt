# Lab2 Task 3
add_executable(task3
    main.cpp
    "../include/ImageFilters.cpp"
    "../include/ImageFilters.h"
    "../include/myutils.cpp"
    "../include/myutils.h"
)
target_link_libraries(task3 ${OpenCV_LIBS})
