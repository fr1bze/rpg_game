cmake_minimum_required(VERSION 3.26)
project(BoxCatcherGame)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL3 REQUIRED)

add_executable(BoxCatcherGame
        main.cpp
        Game.cpp
        Player.cpp
        StraightEnemy.cpp
        ZigzagEnemy.cpp
        SpiralEnemy.cpp
        CollisionSystem.cpp
        ScoreSystem.cpp
        LevelGenerator.cpp
        Renderer.cpp
        ZigzagEnemy.h
)

target_include_directories(BoxCatcherGame PRIVATE ${SDL3_INCLUDE_DIRS})
target_link_libraries(BoxCatcherGame PRIVATE ${SDL3_LIBRARIES})