cmake_minimum_required(VERSION 3.9)
project(game)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

find_package(SDL2_IMAGE REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIR})

include_directories(${PROJECT_SOURCE_DIR}/headers)

add_executable(game main.cpp headers/graphics.h graphics.cpp headers/game.h game.cpp headers/input.h input.cpp)

target_link_libraries(game ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} -lmingw32 -lSDL2main -lSDL2 -mwindows)
