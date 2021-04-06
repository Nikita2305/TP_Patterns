cmake_minimum_required(VERSION 3.10)
project(TP_Project_2_0)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(TP_Project_2_0
    src/main.cpp
    src/Units/Unit.cpp
    src/Units/Miner.cpp
    src/Units/Warrior.cpp
    src/Units/SimpleMiner.cpp
    src/Units/ImmortalMiner.cpp
    src/Units/TeleportingMiner.cpp
    src/Units/SimpleWarrior.cpp
    src/Units/ArmorWarrior.cpp
    src/Units/SniperWarrior.cpp
    src/Commands/Command.cpp
    src/Commands/AddUnitCommand.cpp
    src/Commands/DeleteUnitsCommand.cpp
    src/Commands/ExitCommand.cpp
)
