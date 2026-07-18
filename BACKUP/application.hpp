#pragma once
#include "Engine/Platform/Platform/platform.hpp"

//Engine
#include "Engine/Assets/AssetManager/asset_manager.hpp"
#include "Engine/RenderingAPI/Shader/game_shader.hpp"
#include "Engine/Platform/WindowCreation/window.hpp"
#include "Engine/RenderingAPI/Renderer/renderer.hpp"
#include "Engine/Tests/Objects/Triangle/triangle.hpp"
#include "Engine/Tests/Objects/Rotating Cube/rcube.hpp"



//DebugTools
#include "DebugTools/Core/Timer/time_manager.hpp"
#include "DebugTools/Tools/tool_manager.hpp"
#include "DebugTools/Tools/ConsoleTool/console_tool.hpp"
#include "DebugTools/Core/Logger/logger.hpp"


#include "Backends/API/renderer_api.hpp"

//System
#include <memory>
#include <chrono>
#include <iostream>
#include <array>






namespace engine
{

    struct EngineConfig
    {
        //TODO deal with this like a file read or smg/// For those are Default values

    };

    struct WindowConfig
    {
        int windowWidth;
        int windowHeight;
        const char* title;

    };

    struct AdditionalParams {
        size_t memoryBudgetMB; // Memory size
        //bool enableVSync;      // Example: Graphics flag
        bool debugMode;       // Debugging flag
    };

    //
    struct AppSettings {
        WindowConfig window;
        AdditionalParams extra;
    };


    class Window;
    class Renderer;

    // struct addon_params(int argc, char** argv);
    // struct AppParams

    class Application
    {
    public:
        Application(AppSettings& settings);
        virtual ~Application();

        void Run();

        Window& GetWindow() { return *m_GameWindow; }
		AssetManager& GetAssetManager() { return *m_AssetManager; }

    protected:
        // for game-specific logic later
        virtual void OnInit() {}
        virtual void OnUpdate(float dt) {}
        virtual void OnRender(Renderer& m_Renderer) {}
        virtual void OnShutdown() {}

    private:
        std::unique_ptr<Window> m_GameWindow;
        std::unique_ptr<Window> m_AdditionalWindow;

        std::unique_ptr<Window> m_DebugMenuWindow; // Menu to choose debugging tools from
        std::unique_ptr<Window> m_ConsoleWindow;   // Window for my own console
        

        //Alfa for tests and othe purposes
        std::unique_ptr<Window> m_AlfaConsoleWindow;   // Window for my own console jjdfgshjidsfgkshfg

        std::unique_ptr<Renderer> m_Renderer;

		//IDK if I need this but I will add it later if I do
        std::unique_ptr<AssetManager> m_AssetManager;


        //Handler for tools aka debug tools
        std::unique_ptr<debugtools::ToolManager> m_ToolManager;



		float deltaTime = 0.0f;;
		float crap = 1.0f;;

        bool m_Running = true;


        //Tests 

        std::unique_ptr<Triangle> m_Triangle;
        std::unique_ptr<Rot_Cube> m_Rot_Cube;



       // float fpsTimer = 0.0f;
       /// int frameCount = 0;
      //  float fps = 0.0f;
    private:
       // void StatsInit();
        void FpsDelta();
    };
}