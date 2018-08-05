project (ogamelike_lib_server)

set (CMAKE_CXX_STANDARD 14)

#set (CMAKE_VERBOSE_MAKEFILE ON)
set (CMAKE_POSITION_INDEPENDENT_CODE ON)

set (SOURCES
  ServerLauncher.cpp
  ServerException.cpp
  Runnable.cpp
  TimeManager.cpp
  UniverseRunnable.cpp
  )

add_library (ogamelike_lib_server SHARED
  ${SOURCES}
  )

set(SERVER_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}" PARENT_SCOPE)

target_link_libraries(ogamelike_lib_server
  ogamelike_lib_core
  ogamelike_lib_player
  )

target_include_directories (ogamelike_lib_server PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CORE_INCLUDE_DIR}
  )

