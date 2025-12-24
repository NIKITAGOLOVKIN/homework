cmake_minimum_required(VERSION 3.25)
project(sortingStation C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_library(stack stack.c)
add_executable(sortingStation C_hw5.2_sortingStation.c)
target_link_libraries(sortingStation PRIVATE stack)

target_compile_options(stack PRIVATE -Wall -Wextra -Werror -Wpedantic)
target_compile_options(sortingStation PRIVATE -Wall -Wextra -Werror -Wpedantic)
