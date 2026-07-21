cmake_minimum_required(VERSION 3.20)
project(VoxelEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# add_library(glad STATIC thirdparty/glad/src/glad.c)
# set_source_files_properties(thirdparty/glad/src/glad.c PROPERTIES LANGUAGE CXX)

#include_directories(thirdparty/glad/include)
#include_directories(thirdparty/glm)
#include_directories(thirdparty/tracy/public)

# target_include_directories(glad PUBLIC thirdparty/glad/include)


# 1. Define the library
add_library(glad STATIC thirdparty/glad/src/glad.c)
set_source_files_properties(thirdparty/glad/src/glad.c PROPERTIES LANGUAGE CXX)

# 2. IMPORTANT: Use PUBLIC here so that any target that links to 'glad'
# automatically inherits this include directory
target_include_directories(glad PUBLIC thirdparty/glad/include)
target_include_directories(glad PUBLIC thirdparty/tracy/public)

#sub dirs
add_subdirectory(thirdparty/glfw)
add_subdirectory(Engine)
add_subdirectory(DebugTools)
add_subdirectory(Backends)
add_subdirectory(VoxelGame)


# Add your engine modules in order of dependencies

#Localisation of project
add_definitions(-DPROJECT_ROOT="${CMAKE_SOURCE_DIR}/")

target_precompile_headers(Engine
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/Engine/Core/Base/--PreCompileHeaders--/pch.hpp
)