###############################################################################
# Find SDL
#
# This sets the following variables:
# SDL_FOUND - True if Eigen was found.
# SDL_INCLUDE_DIRS - Directories containing the Eigen include files.
# SDL_DEFINITIONS - Compiler flags for Eigen.
# SDL_VERSION - Package version

if(CMAKE_SYSTEM_NAME STREQUAL Linux)
  set(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} /usr /usr/local)
endif(CMAKE_SYSTEM_NAME STREQUAL Linux)

find_path(SDL_INCLUDE_DIR SDL/
  PATHS "${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/SDL"
)

if(SDL_INCLUDE_DIR)
  message(STATUS "Found SDL at ${SDL_INCLUDE_DIR}")
  file(READ "${SDL_INCLUDE_DIR}/SDL/SDL_version.h" _sdl_version_header)
  string(REGEX MATCH "define[ \t]+SDL_WORLD_VERSION[ \t]+([0-9]+)" _sdl_world_version_match "${_sdl_version_header}")
  set(SDL_WORLD_VERSION "${CMAKE_MATCH_1}")
  string(REGEX MATCH "define[ \t]+SDL_MAJOR_VERSION[ \t]+([0-9]+)" _sdl_major_version_match "${_sdl_version_header}")
  set(SDL_MAJOR_VERSION "${CMAKE_MATCH_1}")
  string(REGEX MATCH "define[ \t]+SDL_MINOR_VERSION[ \t]+([0-9]+)" _sdl_minor_version_match "${_sdl_version_header}")
  set(SDL_MINOR_VERSION "${CMAKE_MATCH_1}")
  set(SDL_VERSION ${SDL_WORLD_VERSION}.${SDL_MAJOR_VERSION}.${SDL_MINOR_VERSION})
endif(SDL_INCLUDE_DIR)

set(SDL_INCLUDE_DIRS ${SDL_INCLUDE_DIR})
set(CMAKE_FIND_FRAMEWORK)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(SDL DEFAULT_MSG SDL_INCLUDE_DIR)

mark_as_advanced(SDL_INCLUDE_DIR)

if(SDL_FOUND)
  message(STATUS "SDL found (include: ${SDL_INCLUDE_DIRS}, version: ${SDL_VERSION})")
endif(SDL_FOUND)
