cmake_minimum_required(VERSION 3.15)
project(ImprovedCombatGame)

set(CMAKE_CXX_STANDARD 14)

add_executable(ImprovedCombatGame main.cpp Enemy.cpp Enemy.h Weapon.cpp Weapon.h Player.cpp Player.h Adventure.cpp Adventure.h)