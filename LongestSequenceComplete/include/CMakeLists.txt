# Creates the dynamic library
add_library(
    LongestSequenceLib  SHARED  
    src/includes/longestSequence.h    
    src/includes/longestSequence.c
)

# Includes the path to the libraries
target_link_directories(LongestSequenceLib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
