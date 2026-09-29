cmake_minimum_required(VERSION 3.29)
project(game_of_life LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(game_core STATIC
        src/universe.cpp
        src/rule.cpp
        src/filereader.cpp
        src/filewritter.cpp
        src/render.cpp
        src/presetregistry.cpp
        src/preset.cpp
        src/command.cpp
        src/mode.cpp
        src/commandparser.cpp
        src/modeparser.cpp
)

target_include_directories(game_core PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(game_of_life src/main.cpp)
target_link_libraries(game_of_life PRIVATE game_core)

find_package(GTest REQUIRED)

add_executable(UnitTests
        tests/ruletests.cpp
        tests/universetests.cpp
        tests/commandtests.cpp
        tests/commandparsertests.cpp
        tests/modeparser.cpp
        tests/presettests.cpp
        tests/presetregistry.cpp
        tests/filereadertests.cpp
        tests/filewrittertests.cpp
)

target_link_libraries(UnitTests PRIVATE game_core GTest::gtest GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(UnitTests)