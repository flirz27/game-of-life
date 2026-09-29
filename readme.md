Conway's Game of Life

A C++ implementation of John Conway's Game of Life with multiple run modes, custom rules, and preset support.
Features

    Classic and custom rules in #R B3/S23 format

    Load universes from #Life 1.06 files

    Save the current state to a file

    Three run modes: interactive, file-based, and offline

    Preset directory for quick startup configuration selection

    Unit tests with GoogleTest

Requirements

    CMake ≥ 3.29

    A C++17-capable compiler (clang or gcc)

    GoogleTest

-Install GoogleTest (Debian/Ubuntu):


##bash

sudo apt install libgtest-dev cmake clang

-Building


##bash

git clone <git@github.com:flirz27/game-of-life.git>

cd conways_game_of_life

cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug

cmake --build build

-Executable: build/game_of_life

-Tests: build/UnitTests

-Run the tests:

##bash

cd build && ctest --output-on-failure

-Run Modes

The program support 3 modes.

1. Using files in preset directory near run file

2. Load a specific file and show game on console

3. like 3, but will go through <t> ticks and save it

-Command	Description
tick <n> / t <n>	Advance n generations and render the field (defaults to 1)

dump <path>	Save the current state to a file

help	Show the list of commands

exit	Quit the program

-File Format
The project uses the #Life 1.06 format:
text

#Life 1.06

#N Glider

#R B3/S23

10 10

1 2

2 3

0 3

1 3

2 3

    The #Life 1.06 line is a mandatory header.

    #N <name> — universe name.

    #R B.../S... — rule: digits after B are neighbor counts for birth, after S for survival.

    <width> <height> — field dimensions.

    The remaining lines are coordinates of live cells x y.

-Architecture

    Universe — holds the current and next cell generations, evolves them using a given rule.

    Rule — parses B/S rules and decides a cell's fate based on its neighbor count.

    Preset / PresetRegistry — preset loading and cataloguing.

    FileReader / FileWriter — wrappers around file streams.

    Render — draws the field to the terminal (@ for live cells, . for dead ones).

    Command / CommandParser — Command pattern for interactive mode.

    Mode / ModeParser — selects a run mode based on command-line arguments.
