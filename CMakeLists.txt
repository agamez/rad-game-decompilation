cmake_minimum_required(VERSION 3.16)
project(rad LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED sdl2)

# Recovered game code — one translation unit per original code segment
# (large segments split into part files; see docs/notes-*.md).
file(GLOB RECOVERED_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)
list(FILTER RECOVERED_SOURCES EXCLUDE REGEX ".*/main.c$")

# Platform abstraction layer (SDL2 + Nuked OPL2)
set(PAL_SOURCES
  pal/pal.c
  pal/video.c
  pal/input.c
  pal/dos.c
  pal/audio.c
  pal/int.c
  pal/opl3.c
)

add_executable(rad ${RECOVERED_SOURCES} src/main.c ${PAL_SOURCES})

target_include_directories(rad PRIVATE src pal)
target_compile_options(rad PRIVATE -Wall)
target_link_libraries(rad PRIVATE ${SDL2_LIBRARIES})
target_include_directories(rad PRIVATE ${SDL2_INCLUDE_DIRS})
