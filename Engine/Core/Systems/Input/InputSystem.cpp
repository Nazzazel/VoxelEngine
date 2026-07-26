//
// Created by nazzazel on 25.07.2026.
//

#include "InputSystem.hpp"

namespace engine
{
    Result InputSystem::OnInit()
    {
        m_SystemManager = this->GetSystemManager();

        if (!m_SystemManager)
        {
            return SYSTEM_RESULT(SystemManagerNotSet,Error);//todo
        }

        m_Logger = m_SystemManager->GetSystem<LoggerSystem>();

        keyboardInputStateMap = std::make_unique<KeybordInputStateMap>();

        return {};
    }

    Result InputSystem::OnUpdate(float dt)
    {
        return {};
    }

    Result InputSystem::OnShutdown()
    {
        return {};
    }

    KeybordInputStateMap* InputSystem::GetKeybordInputStateMap()
    {

        return keyboardInputStateMap.get();
    }
} // engine