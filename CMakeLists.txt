cmake_minimum_required (VERSION 3.1)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
#set(CMAKE_BINARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
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
  )

target_link_libraries(
  ogamelike
  ogamelike_lib
  )
