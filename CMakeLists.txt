cmake_minimum_required(VERSION 3.20)
set(PROJ C++_Playground)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(colored_output)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 17)

project(${PROJ})

add_subdirectory("variadic_templates")
