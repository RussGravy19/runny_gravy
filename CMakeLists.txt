cmake_minimum_required(VERSION 3.14)
project(gravy)

include(FetchContent)

add_library(gravy STATIC src/gravy.c)

target_include_directories(gravy PUBLIC include)

# this requires libssl-dev (apt)
set(BUILD_CURL_EXE OFF CACHE BOOL "" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
set(BUILD_STATIC_LIBS ON CACHE BOOL "" FORCE)

FetchContent_Declare(
    curl
    GIT_REPOSITORY https://github.com/curl/curl.git
    GIT_TAG curl-8_11_1
    GIT_PROGRESS TRUE
    GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(curl)
target_link_libraries(gravy PRIVATE -Wl,--whole-archive CURL::libcurl -Wl,--no-whole-archive)