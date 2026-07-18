# Gather main.cpp alongside any demo scene structures (Triangle, Rot_Cube, etc.)
file(GLOB_RECURSE VOXEL_GAME_SOURCES "*.cpp")

add_executable(VoxelGame ${VOXEL_GAME_SOURCES}
        src/Core/camera.cpp
        src/Core/camera.hpp
        ../thirdparty/tracy/public/TracyClient.cpp
        src/Core/Application/entry_point.cpp
        src/Core/Application/voxel_game_app.cpp
        src/Core/Application/voxel_game_app.hpp
        src/Input/Devices/Keyboard/keyboard.cpp
        src/Input/Devices/Keyboard/keyboard.hpp
        src/Input/Devices/Mouse/mouse.cpp
        src/Input/Devices/Mouse/mouse.hpp
        src/Input/Devices/Controller/controller.cpp
        src/Input/Devices/Controller/controller.hpp
        src/Input/InputManager.cpp
        src/Input/InputManager.hpp
)

# 1. Add Tracy::TracyClient to the end of this list
target_link_libraries(VoxelGame PRIVATE Engine glad glfw )

# 2. Add this line to turn on the profiling macros during compilation
target_compile_definitions(VoxelGame PRIVATE TRACY_ENABLE)
