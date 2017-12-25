cmake_minimum_required(VERSION 2.8)
add_definitions("-W -Wall")

add_library(list STATIC list.c)

install(TARGETS list ARCHIVE DESTINATION lib LIBRARY DESTINATION lib)
install(FILES includes/list.h DESTINATION include)
