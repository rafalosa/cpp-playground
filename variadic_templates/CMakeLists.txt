file(GLOB_RECURSE SOURCES
  "src/*.cpp")

set(HEADERS include)

add_executable(variadic_templates ${SOURCES})
target_include_directories(variadic_templates PRIVATE ${HEADERS})
set_target_properties(variadic_templates PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
  LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
