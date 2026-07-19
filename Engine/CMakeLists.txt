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
        Core/Engine/DefaultEngineStartup/engine_startup.cpp
        Core/Engine/DefaultEngineStartup/engine_startup.hpp
        Core/Engine/Manager/SystemManager/system_manager.hpp
        Core/Engine/Manager/SystemManager/i_engine_system.hpp
        Core/Engine/Manager/Systems/Logger/logger_system.cpp
        Core/Engine/Manager/Systems/Logger/logger_system.hpp
        Core/Engine/Manager/Systems/Platform/platform_system.cpp
        Core/Engine/Manager/Systems/Platform/platform_system.hpp
        Core/Engine/Manager/Systems/Result/result_handler.cpp
        Core/Engine/Manager/Systems/Result/result_handler.hpp
        Core/Engine/Manager/Systems/Result/result.hpp
        Core/Engine/Manager/Systems/Result/ResultCodesForCategories/codes_memory.hpp
        Core/Engine/Manager/Systems/Result/ResultCodesForCategories/result_code_handler.hpp
        Core/Engine/Manager/Systems/Result/ResultCodesForCategories/codes_general.hpp
        Core/Engine/Manager/Systems/Result/ResultCodesForCategories/ResultCodes.hpp

)

target_link_libraries(Engine PUBLIC DebugTools Backends)


target_include_directories(Engine PUBLIC
    .
    Tests/Objects/Triangle
    Tests/Objects/Rot_Cube
)
