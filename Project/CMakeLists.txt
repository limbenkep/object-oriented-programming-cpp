# Projektets namn
project (Trains)
# Minsta tillåtna CMake version
cmake_minimum_required(VERSION 3.2)

# Kompilera med stöd för C++ 11
set (CMAKE_CXX_STANDARD 11)

include_directories(include)

# Add source directory
aux_source_directory(src/ SOURCES)

# Create executable for the run configuration
add_executable(${PROJECT_NAME}-Project ${SOURCES} include/Car.h src/Car.cpp include/Car.h src/Coach.cpp include/Coach.h src/SleepingCar.cpp include/SleepingCar.h src/CoveredFreightCar.cpp include/CoveredFreightCar.h src/OpenFreightCar.cpp include/OpenFreightCar.h)

# In order to avoid '../../../' semantics in include paths (relative), we need to add
# target directory to the configuration
target_include_directories(${PROJECT_NAME}-Project PRIVATE include/ ../_Resources/_libs/)