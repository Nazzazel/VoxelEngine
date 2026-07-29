//
// Created by nazzazel on 21.07.2026.
//


#pragma once
#include "IAppInterface.hpp"
#include "Core/Systems/Systems.hpp"

namespace engine
{
    class EngineCore : public IAppInterface {


    public:
        EngineCore(SystemManager* systemManager)
            :
        m_timeSystem(*systemManager->GetSystem<TimeSystem>()),
        m_logger_system(*systemManager->GetSystem<LoggerSystem>()),

        m_platform_system(*systemManager->GetSystem<PlatformSystem>()),
        m_window_system(*systemManager->GetSystem<WindowSystem>()),
        m_event_system(*systemManager->GetSystem<EventSystem>()),
        m_renderer_system(*systemManager->GetSystem<RendererSystem>()),
        m_file_system(*systemManager->GetSystem<FileSystem>()),
        m_asset_system(*systemManager->GetSystem<AssetSystem>()),

        m_input_system(*systemManager->GetSystem<InputSystem>())



        {}

    private:
        TimeSystem& m_timeSystem;
        LoggerSystem& m_logger_system;


        PlatformSystem& m_platform_system;
        WindowSystem&   m_window_system;
        EventSystem&    m_event_system;
        RendererSystem& m_renderer_system;
        FileSystem&     m_file_system;
        AssetSystem&    m_asset_system;


        InputSystem& m_input_system;
        //FileSystem m_fileSystem

    public:


        TimeSystem&    GetTimeSystem()     override { return m_timeSystem; }
        LoggerSystem&  GetLoggerSystem()   override { return m_logger_system; }

        PlatformSystem&  GetPlatformSystem()   override { return m_platform_system; }
        WindowSystem&  GetWindowSystem()   override { return m_window_system; }
        EventSystem&  GetEventSystem()   override { return m_event_system; }
        RendererSystem&  GetRendererSystem()   override { return m_renderer_system; }
        FileSystem&  GetFileSystem()   override { return m_file_system; }
        AssetSystem&  GetAssetSystem()   override { return m_asset_system; }



        InputSystem&  GetInputSystem()   override { return m_input_system; }




    };
}
