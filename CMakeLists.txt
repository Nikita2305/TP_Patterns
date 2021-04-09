cmake_minimum_required(VERSION 3.10)
project(TP_Project_2_0)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(TP_Project_2_0
        src/main.cpp
        src/Units/UnitEntity.cpp
        src/Units/Unit.cpp
        src/Units/UnitSquad.cpp
        src/Units/Positions/Position.cpp
        src/Units/Positions/ForwardPosition.cpp
        src/Units/Positions/ReversePosition.cpp
        src/Units/Miners/Miner.cpp
        src/Units/Miners/SimpleMiner.cpp
        src/Units/Miners/ImmortalMiner.cpp
        src/Units/Miners/TeleportingMiner.cpp
        src/Units/Warriors/Warrior.cpp
        src/Units/Warriors/SimpleWarrior.cpp
        src/Units/Warriors/ArmorWarrior.cpp
        src/Units/Warriors/SniperWarrior.cpp
        src/Commands/Command.cpp
        src/Commands/AddUnitCommand.cpp
        src/QueryHandling/Executor.cpp
        src/QueryHandling/Query.cpp
        src/QueryHandling/IStream.cpp
        src/QueryHandling/BufferStream.cpp
        src/QueryHandling/StandardInputStream.cpp
        src/QueryHandling/PlayerInterface.cpp
        src/GameObjects/Player.cpp
        src/GameObjects/Direction.cpp
)
