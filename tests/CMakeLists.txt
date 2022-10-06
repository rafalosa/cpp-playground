include(FetchContent)

FetchContent_Declare(googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
GIT_TAG release-1.12.1)

FetchContent_MakeAvailable(googletest)

add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

set(HEADERS include)

add_executable(math_tests "src/math_tests.cpp")

target_include_directories(math_tests PRIVATE ${HEADERS})

target_link_libraries(math_tests PRIVATE GTest::GTest)

add_test(math_test math_tests)


