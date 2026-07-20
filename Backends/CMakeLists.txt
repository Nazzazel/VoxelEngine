# Recursively grab all backend implementation source files (e.g., OpenGL/ Renderer backend files)
file(GLOB_RECURSE BACKENDS_SOURCES "*.cpp")

add_library(Backends STATIC ${BACKENDS_SOURCES})

# Ensure dependencies can locate top-level includes
target_include_directories(Backends PUBLIC .)
# In Backends/CMakeLists.txt
target_link_libraries(Backends PUBLIC Engine)