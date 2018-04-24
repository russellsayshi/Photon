cmake_minimum_required(VERSION 3.5)
project(Photon)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

set(SOURCES)
set(HEADERS)
file(GLOB SOURCES "*.cpp" "shapes/*.cpp" "util/*.cpp")
file(GLOB HEADERS "*.h" "shapes/*.cpp" "util/*.cpp")
set(CMAKE_CXX_FLAGS "-std=c++17")

set(CMAKE_CXX_STANDARD 17)

add_executable(main.out ${SOURCES} ${HEADERS})
target_link_libraries(main.out ${SDL2_LIBRARIES})
