cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17 -pthread)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(SDL2Test)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} src ${SDL2IMAGE_INCLUDE_DIRS})

add_executable(SpaceInvaders src/main.cpp src/renderer.cpp src/game.cpp src/player.cpp src/controller.cpp src/level.cpp)
string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
target_link_libraries(SpaceInvaders ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} pthread)
