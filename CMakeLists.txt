cmake_minimum_required(VERSION 3.14)

include(FetchContent)

project(easy_blockchain)

add_library(easy_blockchain STATIC src/matrix_mult.c)

target_include_directories(easy_blockchain PUBLIC include)

#execute_process(COMMAND sudo apt-get install -y libssl-dev, OUTPUT_QUIET)
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
target_link_libraries(easy_blockchain PRIVATE -Wl,--whole-archive CURL::libcurl -Wl,--no-whole-archive)
