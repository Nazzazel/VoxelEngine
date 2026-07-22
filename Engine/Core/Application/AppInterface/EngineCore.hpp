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
        m_timeSystem(systemManager->GetSystem<TimeSystem>()),
        m_logger_system(systemManager->GetSystem<LoggerSystem>())

        {

        }

    private:
        TimeSystem* m_timeSystem;
        LoggerSystem* m_logger_system;
        //FileSystem m_fileSystem

    public:
        TimeSystem*    GetTimeSystem()     override { return m_timeSystem; }
        LoggerSystem*  GetLoggerSystem()   override { return m_logger_system; }
    };
}
