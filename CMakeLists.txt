cmake_minimum_required(VERSION 3.10)

project(Life VERSION 0.1)

set(CMAKE_SOURCE_DIR "src/")

add_executable(Life "src/main.c")
target_link_libraries(Life curses)
target_link_libraries(Life m)
