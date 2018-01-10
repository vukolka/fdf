cmake_minimum_required(VERSION 3.9)
project(fdf C)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES
        src/main.c)

include_directories(libft/includes)

add_subdirectory(libft)

add_executable(fdf ${SOURCE_FILES})

target_link_libraries(fdf libft.a)