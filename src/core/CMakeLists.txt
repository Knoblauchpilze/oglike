project (ogamelike_lib_core)

set (CMAKE_CXX_STANDARD 14)

set (CMAKE_VERBOSE_MAKEFILE ON)
set (CMAKE_POSITION_INDEPENDENT_CODE ON)

set (SOURCES
  Building.cpp
  Galaxy.cpp
  GalaxyException.cpp
  OgameException.cpp
  Planet.cpp
  PlanetException.cpp
  Resource.cpp
  ResourceDeposit.cpp
  ResourceMine.cpp
  System.cpp
  SystemException.cpp
  Universe.cpp
  UniverseException.cpp
  Account.cpp
  AccountException.cpp
  Community.cpp
  CommunityException.cpp
  SystemCoordinates.cpp
  Research.cpp
  Ship.cpp
  )

add_library (ogamelike_lib_core SHARED
  ${SOURCES}
  )

set(CORE_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}" PARENT_SCOPE)

target_include_directories (ogamelike_lib_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

