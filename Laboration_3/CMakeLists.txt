# Projektets namn
project (Bank_System2)
# Minsta tillåtna CMake version
cmake_minimum_required(VERSION 3.2)

# Kompilera med stöd för C++ 11
set (CMAKE_CXX_STANDARD 11)

include_directories(include)

#file(GLOB SOURCES "src/*.cpp")

# Add source directory
aux_source_directory(src/ SOURCES)

# Add source directory
aux_source_directory(src/ SOURCES)

# Create executable for the run configuration
add_executable(${PROJECT_NAME}-Laboration_3 ${SOURCES} src/Account.cpp include/Account.h src/TransactionAccount.cpp include/TransactionAccount.h src/SavingsAccount.cpp include/SavingsAccount.h src/LongTermSavingsAccount.cpp include/LongTermSavingsAccount.h Customer.cpp Customer.h)

# In order to avoid '../../../' semantics in include paths (relative), we need to add
# target directory to the configuration
target_include_directories(${PROJECT_NAME}-Laboration_3 PRIVATE include/ ../_Resources/_libs/)