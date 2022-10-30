file(GLOB_RECURSE SOURCES
  "src/*.cpp")

set(HEADERS include)

add_executable(pi_compile_time ${SOURCES})
target_include_directories(pi_compile_time PRIVATE ${HEADERS})
set_target_properties(pi_compile_time PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
  LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

add_compile_options(pi_compile_time -fconstexpr-steps=100000)
