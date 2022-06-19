cmake_minimum_required(VERSION 3.23)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(sewerlands LANGUAGES CXX VERSION 0.1)

add_subdirectory("${CMAKE_SOURCE_DIR}/external/SFML")
add_subdirectory("${CMAKE_SOURCE_DIR}/src")
