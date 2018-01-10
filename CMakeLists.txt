cmake_minimum_required(VERSION 3.9)
project(fdf C)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES
        src/main.c src/draw_line.c)

include_directories(libft/includes)

add_subdirectory(libft)

include_directories(classes_lib)

add_executable(fdf ${SOURCE_FILES})

add_subdirectory(classes_lib)

target_link_libraries(fdf classes_lib libft.a)