cmake_minimum_required(VERSION 3.14)
project(gravy)

add_library(gravy STATIC src/is_even.c)

target_include_directories(gravy PUBLIC include)
