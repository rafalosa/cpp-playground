file(GLOB_RECURSE SOURCES
  "src/*.cpp")

  file(GLOB_RECURSE SOURCES_LIB
  "shared/*.cpp")

set(HEADERS include)

add_library(impl SHARED ${SOURCES_LIB})
add_executable(pimpl ${SOURCES})

target_include_directories(pimpl PRIVATE ${HEADERS})
target_include_directories(impl PRIVATE ${HEADERS})

set_target_properties(pimpl PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
  LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

set_target_properties(impl PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
  LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

target_link_libraries(pimpl impl)
