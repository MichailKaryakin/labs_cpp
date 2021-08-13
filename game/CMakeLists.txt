cmake_minimum_required(VERSION 3.9)
project(game)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

find_package(SDL2_IMAGE REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIR})

include_directories(${PROJECT_SOURCE_DIR}/headers)

add_executable(game src/main.cpp headers/graphics.h src/graphics.cpp headers/game.h src/game.cpp headers/input.h src/input.cpp headers/sprite.h src/sprite.cpp headers/globals.h headers/animatedsprite.h)

target_link_libraries(game ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} -lmingw32 -lSDL2main -lSDL2 -mwindows)
