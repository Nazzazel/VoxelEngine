//
// Created by nazzazel on 13.07.2026.
//

#include "platform_system.hpp"
#include "Platform/Platform/platform.hpp"

#include <iostream>

#include "Core/Engine/Manager/SystemManager/system_manager.hpp"
//#include "Core/Engine/Manager/Systems/Logger/logger_system.hpp"

namespace engine
{
    Result PlatformSystem::OnInit() // Forced
    {
        m_SystemManager = this->GetSystemManager();
        if (!m_SystemManager)
        {
            return SYSTEM_RESULT(SystemManagerNotSet,Error);//todo
        }

       // m_LoggerSystemPtr = m_SystemManager->GetSystem<engine::LoggerSystem>();
       // if (!m_LoggerSystemPtr)
       // {
       //     return 2;//todo
       // }


        engine::Platform::Init();
        return {};
    }

    Result PlatformSystem::OnUpdate(float dt)
    {
        std::cout << "lo434432543l" <<dt << std::endl;
        return {};
    }
    Result PlatformSystem::OnShutdown()
    {
        return {};
    }

   //const LoggerSystem* PlatformSystem::GetLogger() const
   //{
   //    return m_LoggerSystemPtr;
   //};

} // engine