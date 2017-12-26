cmake_minimum_required(VERSION 2.8)
add_definitions("-W -Wall")

add_executable(main main.c)

install(FILES includes/list.h DESTINATION include)
