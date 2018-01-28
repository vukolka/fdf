cmake_minimum_required(VERSION 3.9)
project(fdf C)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES
        src/main.c src/events.c fdf.h src/draw.c src/parsing.c src/math.c src/loop.c src/ft_print_error.c src/user_interface.c)

include_directories(libft/includes)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -lmlx -framework OpenGL -framework AppKit")

add_subdirectory(libft)

include_directories(libmlx)

include_directories(classes_lib)

add_executable(fdf ${SOURCE_FILES})

add_subdirectory(classes_lib)

target_link_libraries(fdf classes_lib libft.a -lm)

