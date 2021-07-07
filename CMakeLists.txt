cmake_minimum_required(VERSION 3.1)

project(tictactoe)

## If you want to link SFML statically
# set(SFML_STATIC_LIBRARIES TRUE)

## In most cases better set in the CMake cache
# set(SFML_DIR "<sfml root prefix>/lib/cmake/SFML")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB SOURCES "src/*.cpp")

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(tictactoe ${SOURCES})
target_link_libraries(tictactoe sfml-graphics sfml-audio)