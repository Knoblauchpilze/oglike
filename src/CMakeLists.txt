project (ogamelike_lib)

set (CMAKE_CXX_STANDARD 14)

set (CMAKE_VERBOSE_MAKEFILE ON)
set (CMAKE_POSITION_INDEPENDENT_CODE ON)

#find_package (Eigen REQUIRED)

set (SOURCES
  ArgumentsException.cpp
  ArgumentsParser.cpp
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
  )

add_library (ogamelike_lib SHARED
  ${SOURCES}
  )

target_include_directories (ogamelike_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

