project (ogamelike_lib_gui)

set (CMAKE_CXX_STANDARD 14)

set (CMAKE_VERBOSE_MAKEFILE ON)
set (CMAKE_POSITION_INDEPENDENT_CODE ON)

find_package (SDL REQUIRED)
find_package (SDL_ttf REQUIRED)

set (SOURCES
  OgameView.cpp
  GuiException.cpp
  GalaxyView.cpp
  PlanetGalaxyEntry.cpp
  PictureContainer.cpp
  LabelContainer.cpp
  PlanetIconDisplay.cpp
  SwitchPictureContainer.cpp
  )

add_library (ogamelike_lib_gui SHARED
  ${SOURCES}
  ${SDL_INCLUDE_DIRS}
  )

add_library (SDL IMPORTED SHARED)

add_library (SDL_ttf IMPORTED SHARED)

target_link_libraries(ogamelike_lib_gui
  ${SDL_LIBRARY}
  ${SDLTTF_LIBRARY}
  ogamelike_lib_core
  ogamelike_lib_view
  )

target_include_directories (ogamelike_lib_gui PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CORE_INCLUDE_DIR}
  ${VIEW_INCLUDE_DIR}
  )
