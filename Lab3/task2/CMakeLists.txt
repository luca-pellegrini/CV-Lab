# Lab3 Task 2
add_executable(task2
    main.cpp
    "../include/myutils.cpp"
    "../include/myutils.h"
    "../include/ImageFilters.cpp"
    "../include/ImageFilters.h"
)
target_link_libraries(task2 ${OpenCV_LIBS})
