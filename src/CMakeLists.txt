cmake_minimum_required(VERSION 3.23)

set(SEWERLANDS_SOURCES "main.cpp" "sprite.cpp" "game.cpp"
                       "object.cpp" "room.cpp")

set(MACOSX_BUNDLE_ICON_FILE "sewerlands.icns")

set(SEWERLANDS_ICON "${CMAKE_SOURCE_DIR}/data/sewerlands.icns")
file(GLOB_RECURSE SEWERLANDS_RES_SOURCES "${CMAKE_SOURCE_DIR}/data/*")
set_source_files_properties(${SEWERLANDS_ICON}
                            PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")

add_executable(
  TheSewerlands MACOSX_BUNDLE ${SEWERLANDS_ICON} ${SEWERLANDS_SOURCES}
                              ${SEWERLANDS_RES_SOURCES})

# Individually set the file's path properties.
foreach(FILE ${SEWERLANDS_RES_SOURCES})
  # Get the relative path from the data-folder to the particular file.
  file(RELATIVE_PATH NEW_FILE "${CMAKE_SOURCE_DIR}/data" ${FILE})

  # Get the relative path to the file.
  get_filename_component(NEW_FILE_PATH ${NEW_FILE} DIRECTORY)

  # Set it's location inside the app package (under Resources).
  set_source_files_properties(${FILE} PROPERTIES MACOSX_PACKAGE_LOCATION
                              "Resources/${NEW_FILE_PATH}")

  # Optional: Add the file to the 'Resources' folder group in Xcode. This also
  # preserves folder structure.
  source_group("Resources/${NEW_FILE_PATH}" FILES "${FILE}")
endforeach()

target_include_directories(TheSewerlands
    PUBLIC "${CMAKE_SOURCE_DIR}/external/SDL/include"
    PUBLIC "${CMAKE_SOURCE_DIR}/external/SDL_image")

target_link_libraries(TheSewerlands PRIVATE SDL2 SDL2_image)
