
cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(tictactoe)

include_directories(
    ${CMAKE_SOURCE_DIR}/src
)

add_library(common OBJECT
    src/normal_player.cpp
    src/perfect_player.cpp
    src/random_player.cpp
    src/human_player.cpp
    src/board.cpp
    src/player.cpp
    src/game_controller.cpp
)

# Executable
add_executable(tasks
    $<TARGET_OBJECTS:common>
    src/tictactoe.cpp
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
    src/board.test.cpp
    src/human_player.test.cpp
    src/normal_player.test.cpp
    src/random_player.test.cpp
    src/util.test.cpp
)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
target_include_directories(tests PRIVATE src/)

# Register Tests
add_test(tests env CTEST_OUTPUT_ON_FAILURE=1 ./tests)
