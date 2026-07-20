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
        Core/Application/EngineStartUp/engine_startup.cpp
        Core/Application/EngineStartUp/engine_startup.hpp
        Core/Engine/Manager/SystemManager/system_manager.hpp
        Core/Engine/Manager/SystemManager/EngineSystem.hpp
        Core/Engine/Manager/Systems/Logger/logger_system.cpp
        Core/Engine/Manager/Systems/Logger/logger_system.hpp
        Core/Engine/Manager/Systems/Platform/platform_system.cpp
        Core/Engine/Manager/Systems/Platform/platform_system.hpp
        Core/Engine/Manager/Systems/Result/result_handler.cpp
        Core/Engine/Manager/Systems/Result/result_handler.hpp
        Core/Base/Result/result.hpp
        Core/Engine/Manager/Systems/Result/ResultCodesForCategories/result_code_handler.hpp
        Core/Base/Result/ResultCodes.hpp
        Core/Application/Additions/StartUpConfig/start_up_config.hpp
        Core/Platform/IWindow.hpp
        Core/Platform/IInput.hpp
        Core/Platform/PlatformTypes.hpp
        Systems/Platform/GLFW/GLFWWindow.cpp
        Systems/Platform/GLFW/GLFWWindow.hpp
        Core/Base/BaseTypes/Types.hpp
        Core/Base/--PreCompileHeaders--/pch.hpp
        Core/Base/--PreCompileHeaders--/OS_specific/WindowsHeaders.hpp
        Core/Base/--PreCompileHeaders--/OS_specific/LinuxHeaders.hpp
        Core/Base/--PreCompileHeaders--/OS_specific/MacHeaders.hpp
        Core/Base/--PreCompileHeaders--/General/GeneralHeaders.hpp

)

target_link_libraries(Engine PUBLIC DebugTools Backends glad glfw)

# Add the PCH
target_precompile_headers(Engine
        PRIVATE
        Core/Base/--PreCompileHeaders--/pch.hpp
)

target_include_directories(Engine PUBLIC

    ${CMAKE_CURRENT_SOURCE_DIR}/..
    ${CMAKE_CURRENT_SOURCE_DIR}
    Tests/Objects/Triangle
    Tests/Objects/Rot_Cube

)
