project (ogamelike_lib_player)

set (CMAKE_CXX_STANDARD 14)

set (CMAKE_VERBOSE_MAKEFILE ON)
set (CMAKE_POSITION_INDEPENDENT_CODE ON)

find_package (SDL REQUIRED)

set (SOURCES
  Player.cpp
  )

add_library (ogamelike_lib_player SHARED
  ${SOURCES}
  )

target_link_libraries(ogamelike_lib_player
  ogamelike_lib_core
  )

target_include_directories (ogamelike_lib_player PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CORE_INCLUDE_DIR}
  )

