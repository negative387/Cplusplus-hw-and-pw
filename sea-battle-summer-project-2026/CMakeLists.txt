cmake_minimum_required(VERSION 4.1)
project(sea_battle_summer_project)

set(CMAKE_CXX_STANDARD 20)

add_executable(sea_battle_summer_project
        main.cpp
        board.cpp
        game.cpp
        input.cpp
        ship.cpp
        utils.cpp
        structures.h
)
