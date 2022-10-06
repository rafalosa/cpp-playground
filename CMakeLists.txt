cmake_minimum_required(VERSION 3.20)
set(PROJ C++_Playground)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(colored_output)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 17)

project(${PROJ})

enable_testing()

add_subdirectory("variadic_templates")
add_subdirectory("recursive_templates")
add_subdirectory("pimpl idiom")
add_subdirectory("tests")
# add_subdirectory("casting")
# add_subdirectory("compile time stuff")
