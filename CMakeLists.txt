cmake_minimum_required(VERSION 3.17)
project(TP_Project_2_0)

set(CMAKE_CXX_STANDARD 14)

add_executable(TP_Project_2_0 src/main.cpp src/Units/Unit.cpp include/Units/Unit.h src/Units/Miner.cpp include/Units/Miner.h src/Units/Warrior.cpp include/Units/Warrior.h src/Units/SimpleMiner.cpp include/Units/SimpleMiner.h src/Units/ImmortalMiner.cpp include/Units/ImmortalMiner.h src/Units/TeleportingMiner.cpp include/Units/TeleportingMiner.h src/Units/SimpleWarrior.cpp include/Units/SimpleWarrior.h src/Units/ArmorWarrior.cpp include/Units/ArmorWarrior.h src/Units/SniperWarrior.cpp include/Units/SniperWarrior.h src/Commands/Command.cpp include/Commands/Command.h src/Commands/AddUnitCommand.cpp include/Commands/AddUnitCommand.h src/Commands/DeleteUnitsCommand.cpp include/Commands/DeleteUnitsCommand.h src/Commands/ExitCommand.cpp include/Commands/ExitCommand.h)