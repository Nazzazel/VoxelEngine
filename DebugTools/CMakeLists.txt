# Dynamically gather every single .cpp file inside the DebugTools directory tree
file(GLOB_RECURSE DEBUG_TOOLS_SOURCES "*.cpp")

# Double check that we actually found files
if(NOT DEBUG_TOOLS_SOURCES)
    message(FATAL_ERROR "DebugTools directory didn't contain any .cpp files!")
endif()

add_library(DebugTools STATIC ${DEBUG_TOOLS_SOURCES})
target_include_directories(DebugTools PUBLIC .)
