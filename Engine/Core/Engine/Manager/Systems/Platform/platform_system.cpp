// //
// // Created by nazzazel on 13.07.2026.
// //
//
// #include "platform.hpp"
// #include "Platform/Platform/platform.hpp"
//
// #include <iostream>
//
// #include "Core/Engine/Manager/SystemManager/system_manager.hpp"
// //#include "Core/Engine/Manager/Systems/Logger/logger_system.hpp"
//
// namespace engine
// {
//     uint32_t PlatformSystem::OnInit() // Forced
//     {
//
//         m_SystemManager = this->GetSystemManager();
//         if (!m_SystemManager)
//         {
//             return 1;//todo
//         }
//
//        // m_LoggerSystemPtr = m_SystemManager->GetSystem<engine::LoggerSystem>();
//        // if (!m_LoggerSystemPtr)
//        // {
//        //     return 2;//todo
//        // }
//
//
//         engine::Platform::Init();
//         return 0;
//     }
//
//     uint32_t PlatformSystem::OnUpdate(float dt)
//     {
//         std::cout << "lo434432543l" <<dt << std::endl;
//         return 0;
//     }
//     uint32_t PlatformSystem::OnShutdown()
//     {
//         return 0;
//     }
//
//    //const LoggerSystem* PlatformSystem::GetLogger() const
//    //{
//    //    return m_LoggerSystemPtr;
//    //};
//
// } // engine