cmake_minimum_required(VERSION 3.9)
project(game)
set(CMAKE_CXX_STANDARD 11)

set(SDL2_PATH ${PROJECT_SOURCE_DIR}/i686-w64-mingw32)
find_package(SDL2 REQUIRED)
include_directories( ${SDL2_INCLUDE_DIR} )

add_executable(game main.cpp headers/graphics.h graphics.cpp headers/game.h game.cpp headers/input.h input.cpp)

target_link_libraries(game ${SDL2_LIBRARY} -lmingw32 -lSDL2main -lSDL2 -mwindows)
