add_executable(${PROJECT_NAME}    main.c)

set_target_properties(${PROJECT_NAME} PROPERTIES
  ENABLE_EXPORTS 1
  OUTPUT_NAME ${PROJECT_NAME}
)

target_link_libraries(${PROJECT_NAME} LongestSequenceLib)
