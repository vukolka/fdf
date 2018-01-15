cmake_minimum_required(VERSION 3.9)
project(fdf C)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES
        src/main.c src/key_events.c fdf.h src/draw.c src/parsing.c src/math.c src/list_helpers.c src/test_main.c)

include_directories(libft/includes)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")

find_package(libmlx.a)

add_subdirectory(libft)

include_directories(libmlx)

include_directories(classes_lib)

add_executable(fdf ${SOURCE_FILES})

add_subdirectory(classes_lib)

target_link_libraries(fdf classes_lib libft.a -L/home/vukolov/Documents/unit/fdf/libmlx -lmlx -lX11 -lm -lXext)

