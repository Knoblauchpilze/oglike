cmake_minimum_required (VERSION 3.1)

set (CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set (CMAKE_CXX_STANDARD 14)

set (CMAKE_VERBOSE_MAKEFILE ON)

project(ogamelike)

add_subdirectory(src)

set (SOURCES
  main.cpp
  )

add_executable(ogamelike
  ${SOURCES}
  ${CORE_INCLUDE_DIR}
  )

set (CORE_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/core")

target_include_directories(ogamelike PRIVATE
  ${CORE_INCLUDE_DIR}
  )

target_link_libraries(
  ogamelike
  ogamelike_lib_core
  ogamelike_lib_view
  )
