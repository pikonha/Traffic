cmake_minimum_required(VERSION 3.9)
project(Trafic CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src/app)
add_subdirectory(src/data)
add_subdirectory(src/structures)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)