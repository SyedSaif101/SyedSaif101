cmake_minimum_required(VERSION 3.10)
project(pacman LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(pacman pacman.cpp)

# MSVC-specific: use the console subsystem (default) and UTF-8 source charset
if(MSVC)
    target_compile_options(pacman PRIVATE /utf-8)
endif()
