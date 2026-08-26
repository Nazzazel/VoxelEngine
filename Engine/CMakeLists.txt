# Use standard file globbing to grab all cpp files inside the engine subsystems
file(GLOB_RECURSE ENGINE_SOURCES
    "Assets/*.cpp"
    "Core/*.cpp"
    "Platform/*.cpp"
    "RenderingAPI/*.cpp"
    "Src/*.cpp"
    "Tests/*.cpp"
)
#add_custom_command(
#        TARGET Engine POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy_directory
#        "${CMAKE_CURRENT_SOURCE_DIR}/Res"
#        "$<TARGET_FILE_DIR:Engine>/Res"
#        COMMENT "Copying resource files to output directory..."
#)

add_library(Engine STATIC ${ENGINE_SOURCES}
#        Core/Application/Application.cpp
        Core/Application/EngineStartUp/EngineStartup.cpp
        Core/Application/EngineStartUp/EngineStartup.hpp
        Core/Base/Result/Result.hpp
        Core/Base/Result/ResultCodes.hpp
        Core/Application/Additions/StartUpConfig/start_up_config.hpp
        Core/Systems/Window/IWindow/IWindow.hpp
        Core/Base/BaseTypes/Types.hpp
        Core/Base/--PreCompileHeaders--/pch.hpp
        Core/Base/--PreCompileHeaders--/OS_specific/WindowsHeaders.hpp
        Core/Base/--PreCompileHeaders--/OS_specific/LinuxHeaders.hpp
        Core/Base/--PreCompileHeaders--/OS_specific/MacHeaders.hpp
        Core/Base/--PreCompileHeaders--/General/GeneralHeaders.hpp
        Core/Base/--PreCompileHeaders--/General/Std.hpp
        Core/Base/--PreCompileHeaders--/General/EngineBaseHeaders.hpp
        Core/Base/Base.hpp
        Core/Manager/SystemManager.hpp
        Core/Systems/Platform/PlatformSystem.hpp
        Core/Systems/Logger/LoggerSystem.cpp
        Core/Systems/Logger/LoggerSystem.hpp
        Core/Systems/IEngineSystem.hpp
        Core/Systems/Platform/PlatformSystem.cpp
        Core/Systems/Window/IWindow/IWindow.cpp
        Core/Systems/Window/WindowSystem.cpp
        Core/Systems/Window/WindowSystem.hpp
        Systems/Platform/GLFW/WindowGLFW.cpp
        Core/Systems/Time/TimeSystem.cpp
        Core/Systems/Time/TimeSystem.hpp
        Core/Application/AppInterface/EngineCore.hpp
        Core/Application/AppInterface/IAppInterface.hpp
        Core/Systems/Systems.hpp
        Core/Systems/Renderer/RendererSystem.cpp
        Core/Systems/Renderer/RendererSystem.hpp
        Core/Systems/Assets/AssetSystem.cpp
        Core/Systems/Assets/AssetSystem.hpp
        Core/Systems/Assets/Shaders/ShaderManager.cpp
        Core/Systems/Assets/Shaders/ShaderManager.hpp
        Core/Systems/Assets/Shaders/Specialized/IComputeShader.hpp
        Core/Systems/File/FileSystem.cpp
        Core/Systems/File/FileSystem.hpp
        Core/Systems/Assets/Shaders/Loader/ShaderLoader.cpp
        Core/Systems/Assets/Shaders/Loader/ShaderLoader.hpp
        Core/Systems/Assets/Shaders/ShaderData.hpp
        Systems/Renderer/Buffers/IVertexArray.hpp
        Systems/Renderer/Buffers/IVertexArray.cpp
        Systems/Renderer/Buffers/IVertexBuffer.hpp
        Systems/Renderer/Buffers/IVertexBuffer.cpp
        Systems/Renderer/Buffers/IIndexBuffer.hpp
        Systems/Renderer/Buffers/IIndexBuffer.cpp
        Core/Systems/Event/EventSystem.cpp
        Core/Systems/Event/EventSystem.hpp
        Core/Systems/Event/EventBus.hpp
        Core/Systems/Event/IEvent.hpp
        Core/Systems/Event/Events.hpp
        Systems/Renderer/Renderer/DrawComponents.hpp
        Systems/Platform/Input/EngineInput.hpp
        Systems/Platform/Input/InputMapStates.hpp
        Systems/Platform/Input/KeyCodes.hpp
        Systems/Platform/Input/IInput.hpp
        Core/Systems/Input/InputSystem.cpp
        Core/Systems/Input/InputSystem.hpp
        Core/Base/--PreCompileHeaders--/General/Graphic.hpp
        Systems/Renderer/Model/Model.cpp
        Systems/Renderer/Model/Model.hpp
        Systems/Renderer/Texture/OpenGLTexture.cpp
        Systems/Renderer/Texture/OpenGLTexture.hpp
        Core/Systems/Time/Timer.cpp
        Core/Systems/Time/Timer.hpp
        Core/Systems/Time/TimerSystem.cpp
        Core/Systems/Time/TimerSystem.hpp

)

target_link_libraries(Engine PUBLIC DebugTools Backends glad glfw)

# Add the PCH
#target_precompile_headers(Engine
#        PUBLIC
#        Core/Base/--PreCompileHeaders--/pch.hpp
#)

target_include_directories(Engine PUBLIC

    ${CMAKE_CURRENT_SOURCE_DIR}/..
    ${CMAKE_CURRENT_SOURCE_DIR}
    Tests/Objects/Triangle
    Tests/Objects/Rot_Cube
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/Base/--PreCompileHeaders--

)

#target_precompile_headers(Engine
#        PUBLIC
#        ${CMAKE_CURRENT_SOURCE_DIR}/Core/Base/--PreCompileHeaders--/pch.hpp
#)
target_precompile_headers(Engine
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/Core/Base/--PreCompileHeaders--/pch.hpp
)

