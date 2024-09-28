cmake_minimum_required(VERSION 3.5.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set default build type to Debug if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

set(PROJECT_NAME learning_cpp)

project(${PROJECT_NAME} VERSION 0.1.0 LANGUAGES C CXX)

# Add source files
set(SOURCES
    src/main.cpp
)

# Add the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Specify multiple include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    include
)
