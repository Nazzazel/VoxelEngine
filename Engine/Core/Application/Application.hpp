#pragma once


//Engine
// #include "Engine/Assets/AssetManager/asset_manager.hpp"
// #include "Engine/Platform/WindowCreation/window.hpp"
// #include "Engine/RenderingAPI/Renderer/renderer.hpp"
// #include "Engine/Tests/Objects/Rotating Cube/rcube.hpp"



//DebugTools
// #include "DebugTools/Tools/tool_manager.hpp"


//System


//#include "../Engine/Manager/SystemManager/system_manager.hpp"
#include "Additions/StartUpConfig/start_up_config.hpp"
#include "Core/Manager/SystemManager.hpp"
#include "Core/Platform/IWindow/IWindow.hpp"
#include "API/renderer_api.hpp"
#include "EngineStartUp/EngineStartup.hpp"

//LLLL
#include "Core/Systems/Logger/LoggerSystem.hpp"
#include "RenderingAPI/Renderer/renderer.hpp"


namespace engine
{
    //class Window;
    //class Renderer;

    // struct addon_params(int argc, char** argv);
    // struct AppParams

    class Application
    {
    public:
        Application(const AppSettings& settings);
        virtual ~Application();

        void Run();

        IWindow& GetWindow() { return *m_MainWindow; }
		//AssetManager& GetAssetManager() { return *m_AssetManager; }//TODO


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
       // virtual void OnRender(Renderer& m_Renderer) {}
        virtual void OnRender() {}
        virtual void OnShutdown() {} //TODO

    private:
        std::unique_ptr<IWindow> m_MainWindow;

        std::unique_ptr<engine::SystemManager> m_SystemManager;

        std::unique_ptr<Renderer> m_Renderer;

		//IDK if I need this but I will add it later if I do
        //TODO std::unique_ptr<AssetManager> m_AssetManager;

        //Later
        //std::unique_ptr<AssetManager> m_StateManager;
        //std::unique_ptr<AssetManager> m_TimeManager;
        //std::unique_ptr<AssetManager> m_RenderManager; //TODO inmortant
        //std::unique_ptr<AssetManager> m_CacheManager;
        //std::unique_ptr<AssetManager> m_EntityComponentManager;
        //std::unique_ptr<AssetManager> m_PhysicsManager;
        //std::unique_ptr<AssetManager> m_AudioManager;

        //Handler for tools aka debug tools and registering other types of tools //TODO
        //std::unique_ptr<debugtools::ToolManager> m_ToolManager;








        AppSettings m_Settings;//INIT and app settings get from the projects stitting atop/using engine

        float deltaTime = 0.0f;;
        bool m_EngineRunning = true;
        bool m_GameRunning = true;


        // void StatsInit();
        void FpsDelta();


		float crap = 1.0f;//TODO delete



        //Tests //TODO delete

        //TODO std::unique_ptr<Rot_Cube> m_Rot_Cube;//TODO delete

    private:
        //std::vector<std::unique_ptr<void>> m_EngineObjects;


    };
}
