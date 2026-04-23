# unit_Rectangle
set(EXECUTABLE_NAME unit_Rectangle)
add_executable(${EXECUTABLE_NAME} unit_Rectangle.cpp)
create_test(${EXECUTABLE_NAME})
target_link_libraries(
  ${EXECUTABLE_NAME}
  PUBLIC model::utilities
  PRIVATE nlohmann_json::nlohmann_json
)
