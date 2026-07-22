# Use standard file globbing to grab all cpp files inside the engine subsystems
file(GLOB_RECURSE ENGINE_SOURCES
    "Assets/*.cpp"
    "Core/*.cpp"
    "Platform/*.cpp"
    "RenderingAPI/*.cpp"
    "Src/*.cpp"
    "Tests/*.cpp"  # <--- Ensure this line is present!
)

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