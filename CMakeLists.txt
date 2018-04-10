cmake_minimum_required(VERSION 3.9)
project(Photon)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

set(SOURCES)
file(GLOB SOURCES "*.cpp")

set(CMAKE_CXX_STANDARD 17)

add_executable(main.out ${SOURCES})
target_link_libraries(main.out ${SDL2_LIBRARIES})
