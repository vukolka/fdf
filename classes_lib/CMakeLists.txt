cmake_minimum_required(VERSION 3.9)
project(classes_lib C)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES
        new.c
        Point.c
        String.c init_classes.c classes_lib.h MLXConn.c MLXConn.h Image.c Image.h)
include_directories(../libft/includes)

add_library(classes_lib ${SOURCE_FILES})