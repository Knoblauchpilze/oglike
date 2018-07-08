project (ogamelike_lib_view)

set (CMAKE_CXX_STANDARD 14)

set (CMAKE_VERBOSE_MAKEFILE ON)
set (CMAKE_POSITION_INDEPENDENT_CODE ON)

find_package (SDL REQUIRED)

set (SOURCES
  OgameAbstractView.cpp
  EventListener.cpp
  ViewException.cpp
  EventException.cpp
  Drawable.cpp
  Area.cpp
  Vector2f.cpp
  ComparisonUtils.cpp
  GraphicContainer.cpp
  Layout.cpp
  LinearLayout.cpp
  GridLayout.cpp
  GraphicContainerException.cpp
  Font.cpp
  FontException.cpp
  )

add_library (ogamelike_lib_view SHARED
  ${SOURCES}
  ${SDL_INCLUDE_DIRS}
  )

add_library (SDL IMPORTED SHARED)

target_link_libraries(ogamelike_lib_view
  ${SDL_LIBRARY}
  ogamelike_lib_core
  )

target_include_directories (ogamelike_lib_view PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CORE_INCLUDE_DIR}
  )

