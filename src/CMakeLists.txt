cmake_minimum_required(VERSION 3.1)

set (CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules")

add_subdirectory(app)
add_subdirectory(core)
add_subdirectory(view)
add_subdirectory(gui)
add_subdirectory(player)
add_subdirectory(server)
