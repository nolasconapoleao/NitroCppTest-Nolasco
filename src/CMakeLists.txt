create_lib(utilities model::utilities)
target_link_libraries(utilities PRIVATE nlohmann_json::nlohmann_json)

add_subdirectory(utilities)
