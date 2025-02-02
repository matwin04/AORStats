cmake_minimum_required(VERSION 3.16)
project(PSPlayer)

set(CMAKE_CXX_STANDARD 14)

# Find SDL2 and SDL2_mixer
find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(SDL2_MIXER REQUIRED SDL2_mixer)

# Include and link necessary directories
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_MIXER_INCLUDE_DIRS})
link_directories(${SDL2_LIBRARY_DIRS} ${SDL2_MIXER_LIBRARY_DIRS})

# Add executable
add_executable(${PROJECT_NAME} main.cpp)

# Link libraries
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2_MIXER_LIBRARIES} pspdebug pspaudiolib)
if(PSP)
    create_pbp_file(
        TARGET ${PROJECT_NAME}
        ICON_PATH NULL
        BACKGROUND_PATH NULL
        PREVIEW_PATH NULL
        TITLE ${PROJECT_NAME}
        VERSION 01.00
    )
endif()