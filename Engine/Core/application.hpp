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
//#include "DebugTools/Core/Logger/logger.hpp"


#include "Backends/API/renderer_api.hpp"

//System
#include <memory>
#include <chrono>
#include <iostream>
#include <array>

#include "Engine/Manager/SystemManager/system_manager.hpp"


//Aditional namespace for clarity
//This is used for arg from app using engine
namespace engine
{
    struct EngineConfig
    {
        //TODO deal with this like a file read or smg/// For those are Default values
        //TODO later lol
    };

    struct WindowConfig
    {
        int m_windowWidth;
        int m_windowHeight;
        std::string m_title;

        WindowConfig(
            //---------------------------------------------------------------
            const  int windowWidth,
            const  int windowHeight,
                   std::string title)
            //---------------------------------------------------------------
        : m_windowWidth(windowWidth), m_windowHeight(windowHeight), m_title(title) {}

        [[nodiscard]] int GetWindowWidth() const            {return m_windowWidth;}
        [[nodiscard]] int GetWindowHeight() const           {return m_windowHeight;}
        [[nodiscard]] std::string& GetTitle()               {return m_title;}

    };

    struct AdditionalParams {
        const size_t m_memoryBudgetMB = 8000; // Memory size
        //bool enableVSync;      // Example: Graphics flag
        const  bool m_debugMode = false;       // Debugging flag

        // AdditionalParams(
        //     //---------------------------------------------------------------
        //     size_t memoryBudgetMB = 8000,
        //     bool debugMode = false)
        //     //---------------------------------------------------------------
        // : m_memoryBudgetMB(memoryBudgetMB), m_debugMode(debugMode){}


        [[nodiscard]] size_t GetMemoryBudget() const     {return m_memoryBudgetMB;}
        [[nodiscard]] bool IsDebugModeActive() const    { return m_debugMode; }

    };

    //
    struct AppSettings {
        //EngineConfig engine_configuration;
        WindowConfig m_window_configuration;
        AdditionalParams m_extra;

        AppSettings(
            const WindowConfig& window_configuration,
            const AdditionalParams& extra)
            : m_window_configuration(window_configuration), m_extra(extra){}


        [[nodiscard]] WindowConfig GetWindowConfiguration()   const   {return m_window_configuration;}
        [[nodiscard]] AdditionalParams GetExtra()             const   {return m_extra;}
    };
}


namespace engine
{
    class Window;
    class Renderer;

    // struct addon_params(int argc, char** argv);
    // struct AppParams

    class Application
    {
    public:
        Application(const AppSettings& settings);
        virtual ~Application();

        void Run();

        Window& GetWindow() { return *m_MainWindow; }

		AssetManager& GetAssetManager() { return *m_AssetManager; }


        //Engine is an enviroment where game is running
        //so all hot-swaps and other reload based changes touching game or the App
        //could be made on still working engine
        bool& IsGameRunning() { return m_GameRunning; }
        void StopGameRunning() { m_GameRunning = false; }
        void StartGameRunning() { m_GameRunning = true; }

        //TODO other types of getters for ex toolmanager

    protected:
        // for game-specific logic later
        virtual void OnInit() {}//TODO
        virtual void OnUpdate(float dt) {}
        virtual void OnRender(Renderer& m_Renderer) {}
        virtual void OnShutdown() {} //TODO

    private:
        std::unique_ptr<Window> m_MainWindow;

        std::unique_ptr<Renderer> m_Renderer;

		//IDK if I need this but I will add it later if I do
        std::unique_ptr<AssetManager> m_AssetManager;

        //Later
        //std::unique_ptr<AssetManager> m_StateManager;
        //std::unique_ptr<AssetManager> m_TimeManager;
        //std::unique_ptr<AssetManager> m_RenderManager; //TODO inmortant
        //std::unique_ptr<AssetManager> m_CacheManager;
        //std::unique_ptr<AssetManager> m_EntityComponentManager;
        //std::unique_ptr<AssetManager> m_PhysicsManager;
        //std::unique_ptr<AssetManager> m_AudioManager;

        //Handler for tools aka debug tools and registering other types of tools //TODO
        std::unique_ptr<debugtools::ToolManager> m_ToolManager;


        std::unique_ptr<engine::SystemManager> m_SystemManager;





        AppSettings m_Settings;//INIT and app settings get from the projects stitting atop/using engine

        float deltaTime = 0.0f;;
        bool m_EngineRunning = true;
        bool m_GameRunning = true;


        // void StatsInit();
        void FpsDelta();


		float crap = 1.0f;//TODO delete



        //Tests //TODO delete

        std::unique_ptr<Rot_Cube> m_Rot_Cube;//TODO delete

    private:
        //std::vector<std::unique_ptr<void>> m_EngineObjects;


    };
}