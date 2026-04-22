cmake_minimum_required(VERSION 3.7)

project(Nitro)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS_DEBUG
    "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -Weffc++ -Wconversion -Wsign-conversion -Werror"
)

include(tools/cmake-utils/Libs.cmake)

add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
target_include_directories(
  ${PROJECT_NAME}
  PRIVATE ${CMAKE_SOURCE_DIR}/external ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(${PROJECT_NAME} PUBLIC model::Rectangle)

add_subdirectory(src)

if(ENABLE_TESTS)
  message("## Enable unit tests target")
  include(tools/cmake-utils/Tests.cmake)
  enable_testing()
  add_subdirectory(tests)
endif()
