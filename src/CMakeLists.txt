cmake_minimum_required(VERSION 3.23)

set(SEWERLANDS_SOURCES "main.cpp" "sprite.cpp" "game.cpp"
                       "object.cpp" "room.cpp")

add_executable(TheSewerlands ${SEWERLANDS_SOURCES})

target_include_directories(TheSewerlands
    PUBLIC "${CMAKE_SOURCE_DIR}/external/SDL/include"
    PUBLIC "${CMAKE_SOURCE_DIR}/external/SDL_image")

target_link_libraries(TheSewerlands PRIVATE SDL2 SDL2_image)
