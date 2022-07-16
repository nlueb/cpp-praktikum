cmake_minimum_required(VERSION 3.0)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(c)

include_directories(
    ${CMAKE_SOURCE_DIR}/src
)

add_library(common OBJECT
    src/registers.c
    src/strings.c
)

# Executable
add_executable(tasks
    $<TARGET_OBJECTS:common>
    src/main.c
)

# Fetch Catch2
Include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.1
)
FetchContent_MakeAvailable(Catch2)

# Build Tests
enable_testing()
add_executable(tests
    $<TARGET_OBJECTS:common>
    src/registers.test.cpp
    src/strings.test.cpp
)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
target_include_directories(tests PRIVATE src/)

# Register Tests
add_test(tests env CTEST_OUTPUT_ON_FAILURE=1 ./tests)
