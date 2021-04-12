cmake_minimum_required(VERSION 3.5.1)

# Sets the project name
project(LongestSequence) 

# Adds the include subdirectory
add_subdirectory(include)

# Includes the path to the libraries
target_include_directories(LongestSequenceLib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/src")

# Includes the main subdirectory
add_subdirectory(main)