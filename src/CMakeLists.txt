cmake_minimum_required(VERSION 3.23)

set(SEWERLANDS_SOURCES
    "main.cpp"
)

set(MACOSX_BUNDLE_ICON_FILE sewerlands.icns)

set(SEWERLANDS_ICON ${CMAKE_SOURCE_DIR}/data/sewerlands.icns)
set_source_files_properties(${SEWERLANDS_ICON} PROPERTIES
    MACOSX_PACKAGE_LOCATION "Resources")

add_executable(TheSewerlands MACOSX_BUNDLE ${SEWERLANDS_ICON} ${SEWERLANDS_SOURCES})

target_link_libraries(TheSewerlands PUBLIC sfml-graphics sfml-window sfml-system)
