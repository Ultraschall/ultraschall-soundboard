cmake_minimum_required(VERSION 3.10)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Builds/CLion/)

install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/Builds/CLion/Soundboard DESTINATION /bin)

