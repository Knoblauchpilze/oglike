project (ogamelike_lib_gui)

set (CMAKE_CXX_STANDARD 14)

set (CMAKE_VERBOSE_MAKEFILE ON)
set (CMAKE_POSITION_INDEPENDENT_CODE ON)

find_package (SDL REQUIRED)

set (SOURCES
  OgameView.cpp
  )

add_library (ogamelike_lib_gui SHARED
  ${SOURCES}
  ${SDL_INCLUDE_DIRS}
  )

add_library (SDL IMPORTED SHARED)

target_link_libraries(ogamelike_lib_gui
  ${SDL_LIBRARY}
  ogamelike_lib_view
  )

target_include_directories (ogamelike_lib_gui PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${VIEW_INCLUDE_DIR}
  )

