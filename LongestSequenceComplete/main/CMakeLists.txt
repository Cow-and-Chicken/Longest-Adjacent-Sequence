# Creates the Project executable
add_executable(${PROJECT_NAME} main.c)

# Sets the exports property of our executable to 1
set_target_properties(${PROJECT_NAME} PROPERTIES
  ENABLE_EXPORTS 1
)

# Links the project executable with the dynamic library
target_link_libraries(${PROJECT_NAME} LongestSequenceLib)
