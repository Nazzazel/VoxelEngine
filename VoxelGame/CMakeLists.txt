# Gather main.cpp alongside any demo scene structures (Triangle, Rot_Cube, etc.)

file(GLOB_RECURSE VOXEL_GAME_SOURCES "*.cpp")

add_executable(VoxelGame ${VOXEL_GAME_SOURCES}
        ../thirdparty/tracy/public/TracyClient.cpp
        src/Core/Application/EntryPoint.cpp
        src/Core/Application/VoxelGameApp.cpp
        src/Core/Application/VoxelGameApp.hpp
        src/Input/Devices/Keyboard/keyboard.cpp
        src/Input/Devices/Keyboard/keyboard.hpp
        src/Input/Devices/Mouse/mouse.cpp
        src/Input/Devices/Mouse/mouse.hpp
        src/Input/Devices/Controller/controller.cpp
        src/Input/Devices/Controller/controller.hpp
        src/Input/InputManager.cpp
        src/Input/InputManager.hpp
        Input/GameInput.cpp
        Input/GameInput.hpp
        Game/Player.hpp
        Game/Core/Systems/Camera/Camera.cpp
        Game/Core/Systems/Camera/Camera.hpp
        Game/Core/Systems/Rendering/DotOnTheScreen.cpp
        Game/Core/Systems/Rendering/DotOnTheScreen.hpp
        Core/Game/GameMain.cpp
        Core/Game/GameMain.hpp
        Core/Game/EngineAccessLayer.cpp
        Core/Game/EngineAccessLayer.hpp
        Core/Game/GameInitClass.cpp
        Core/Game/GameInitClass.hpp
        Games/Minecraft/core/Minecraft.cpp
        Games/Minecraft/core/Minecraft.hpp
        Games/Minecraft/client/main/GameConfig.cpp
        Games/Minecraft/client/main/GameConfig.hpp
        Games/VoxelGame/core/VoxelGame.cpp
        Games/VoxelGame/core/VoxelGame.hpp
        Game/Core/Client/Input/InputHandler.cpp
        Game/Core/Client/Input/InputHandler.hpp
        Games/OpenGLTests/OpenGLTestsApp.cpp
        Games/OpenGLTests/OpenGLTestsApp.hpp
        Games/OpenGLTests/Tests/Objects/RotatingCube/RotatingCube.cpp
        Games/OpenGLTests/Tests/Objects/RotatingCube/RotatingCube.hpp
        Games/OpenGLTests/Tests/Objects/Chunk/Chunk.cpp
        Games/OpenGLTests/Tests/Objects/Chunk/Chunk.hpp

)

# 1. Add Tracy::TracyClient to the end of this list
target_link_libraries(VoxelGame PRIVATE Engine glad glfw )

# 2. Add this line to turn on the profiling macros during compilation
target_compile_definitions(VoxelGame PRIVATE TRACY_ENABLE)

target_precompile_headers(VoxelGame
        REUSE_FROM Engine
)
#target_precompile_headers(Engine
#        PUBLIC
#        ${CMAKE_CURRENT_SOURCE_DIR}/Core/Base/--PreCompileHeaders--/pch.hpp
#)



