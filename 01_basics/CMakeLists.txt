
cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(basics)

include_directories(
    ${CMAKE_SOURCE_DIR}/src
)

add_library(common OBJECT
    src/rational.cpp
)

# Executable
add_executable(tasks
    $<TARGET_OBJECTS:common>
    src/main.cpp
)

# Fetch Catch2
Include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.0-preview5
)
FetchContent_MakeAvailable(Catch2)

# Add Tests
enable_testing()
add_executable(tests
    $<TARGET_OBJECTS:common>
    src/rational.test.cpp
)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
target_include_directories(tests PRIVATE src/)
add_test(tests env CTEST_OUTPUT_ON_FAILURE=1 ./tests)
