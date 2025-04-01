# Lab2 Task 1
add_executable(task1
    main.cpp
    "../include/myutils.cpp"
    "../include/myutils.h"
)
target_link_libraries(task1 ${OpenCV_LIBS})
