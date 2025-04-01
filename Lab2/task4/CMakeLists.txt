# Lab2 Task 4
add_executable(task4
    main.cpp
    "../include/ImageFilters.cpp"
    "../include/ImageFilters.h"
    "../include/myutils.cpp"
    "../include/myutils.h"
)
target_link_libraries(task4 ${OpenCV_LIBS})
