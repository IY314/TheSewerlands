cmake_minimum_required(VERSION 3.24)

set(SWR_SOURCES "main.cpp")

add_executable(TheSewerlands ${SWR_SOURCES})

target_include_directories(
  TheSewerlands PUBLIC "${CMAKE_SOURCE_DIR}/external/SDL/include"
                       "${CMAKE_SOURCE_DIR}/external/SDL_image")

target_link_libraries(TheSewerlands PUBLIC SDL2 SDL2_image)
