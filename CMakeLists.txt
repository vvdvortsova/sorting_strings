cmake_minimum_required(VERSION 3.15)
project(sort_strings C)

set(CMAKE_C_STANDARD 11)

add_compile_options( -Wall -Wextra -pedantic -Werror -Wfloat-equal)

add_executable(
        sort_strings
        src/main.c
        src/sort_lib.c
        src/sort_lib.h
        src/help_lib.h
        src/help_lib.c)

add_executable(
        tests
        test/tests.c
        src/help_lib.h
        src/help_lib.c)

set(RESOURCE_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/source.txt
        ${CMAKE_CURRENT_SOURCE_DIR}/results/
        ${CMAKE_CURRENT_SOURCE_DIR}/test/)