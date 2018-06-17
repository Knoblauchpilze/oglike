project (ogamelike_lib_view)

set (CMAKE_CXX_STANDARD 14)

set (CMAKE_VERBOSE_MAKEFILE ON)
set (CMAKE_POSITION_INDEPENDENT_CODE ON)

find_package (SDL REQUIRED)

set (SOURCES
  OgameView.cpp
  )

add_library (ogamelike_lib_view SHARED
  ${SOURCES}
  )

target_include_directories (ogamelike_lib_view PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CORE_INCLUDE_DIR}
  )

