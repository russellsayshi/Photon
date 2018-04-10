cmake_minimum_required(VERSION 3.9)
project(Photon)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

set(SOURCES)
set(HEADERS Colors.h)
file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

set(CMAKE_CXX_STANDARD 17)

add_executable(main.out ${SOURCES} ${HEADERS})
target_link_libraries(main.out ${SDL2_LIBRARIES})
