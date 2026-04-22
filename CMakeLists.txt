cmake_minimum_required(VERSION 3.7)

project(Nitro)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -Weffc++ -Wconversion -Wsign-conversion -Werror")

add_executable(${PROJECT_NAME} src/main.cpp src/Rectangle.cpp)
