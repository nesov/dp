cmake_minimum_required(VERSION 3.21)

set(PROJECT_NAME __dp)

project(${PROJECT_NAME} VERSION 1.0 LANGUAGES CXX)

set(CMAKE_OSX_ARCHITECTURES "arm64")

set(CMAKE_CXX_FLAGS_DEBUG           "-std=c++20 -O0 -g -Wall -fcolor-diagnostics -fansi-escape-codes -DDEBUG")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO  "-std=c++20 -O2 -g -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE         "-std=c++20 -O3 -DNDEBUG")
set(CMAKE_CXX_FLAGS_MINSIZEREL      "-std=c++20 -Os -DNDEBUG")


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(${PROJECT_NAME} src/main.cpp)




# target_link_libraries(${PROJECT_NAME} -pthread)