cmake_minimum_required(VERSION 3.23)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build)

project(sewerlands LANGUAGES CXX VERSION 0.1)

add_subdirectory(external/SFML)
add_subdirectory(src)
