cmake_minimum_required(VERSION 3.9)
project(pong)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

find_package(SDL2_IMAGE REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIR})

find_package(SDL2_TTF REQUIRED)
include_directories(${SDL2_TTF_INCLUDE_DIR})

find_package(SDL2_MIXER REQUIRED)
include_directories(${SDL2_MIXER_INCLUDE_DIR})

include_directories(${PROJECT_SOURCE_DIR}/headers)

add_executable(pong
        src/ball.cpp
        headers/ball.hpp
        src/main.cpp
        src/paddle.cpp
        headers/paddle.hpp
        src/pong.cpp
        headers/pong.hpp)


target_link_libraries(pong ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY} ${SDL2_MIXER_LIBRARY} -lmingw32 -lSDL2main -lSDL2 -mwindows)