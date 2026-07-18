cmake_minimum_required(VERSION 3.20)
project(VoxelEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(thirdparty/glad/include)
include_directories(thirdparty/glm)
include_directories(thirdparty/tracy/public)

# Setup global include paths for Glad and GLM
add_library(glad STATIC thirdparty/glad/src/glad.c)
set_source_files_properties(thirdparty/glad/src/glad.c PROPERTIES LANGUAGE CXX)

# Include Thirdparty Directories
add_subdirectory(thirdparty/glfw)

# Add your engine modules in order of dependencies
add_subdirectory(DebugTools)
add_subdirectory(Backends)
add_subdirectory(Engine)
add_subdirectory(VoxelGame)

#Localisation of project
add_definitions(-DPROJECT_ROOT="${CMAKE_SOURCE_DIR}/")
