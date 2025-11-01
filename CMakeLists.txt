cmake_minimum_required(VERSION 3.10)
project(TestProj)

set(SFML_STATIC_LIBRARIES TRUE)  # Force static linking

find_package(SFML 3.0 COMPONENTS graphics window system REQUIRED)

add_executable(mygame main.cpp)
target_link_libraries(mygame sfml-graphics sfml-window sfml-system)
