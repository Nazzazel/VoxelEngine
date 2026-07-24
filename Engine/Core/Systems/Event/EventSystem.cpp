//
// Created by nazzazel on 24.07.2026.
//

#include "EventSystem.hpp"

namespace engine
{
    Result EventSystem::OnInit()
    {
        m_SystemManager = this->GetSystemManager();

        if (!m_SystemManager)
        {
            return SYSTEM_RESULT(SystemManagerNotSet,Error);//todo
        }

        m_Logger = m_SystemManager->GetSystem<LoggerSystem>();


        return {};
    }

    Result EventSystem::OnUpdate(float dt)
    {


        return {};
    }

    Result EventSystem::OnShutdown()
    {


        return {};
    }
} // engine