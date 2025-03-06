cmake_minimum_required(VERSION 3.14)
execute_process(COMMAND sudo apt install -y libcurl4-openssl-dev, OUTPUT_QUIET)
project(gravy)

add_library(gravy STATIC src/is_even.c)

target_include_directories(gravy PUBLIC include)
