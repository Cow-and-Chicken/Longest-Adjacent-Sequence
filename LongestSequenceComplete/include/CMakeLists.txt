add_library(
    LongestSequenceLib  SHARED  
    src/includes/longestSequence.h    
    src/includes/longestSequence.c
)

target_link_directories(LongestSequenceLib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
