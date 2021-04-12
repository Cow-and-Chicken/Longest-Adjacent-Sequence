cmake_minimum_required(VERSION 3.5.1)

project(LongestSequence)



add_subdirectory(include)

target_include_directories(LongestSequenceLib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/src")

add_subdirectory(main)