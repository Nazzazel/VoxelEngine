//
// Created by nazzazel on 13.07.2026.
//

#include "../../Engine/DefaultEngineStartup/engine_startup.hpp"

#include "Core/Engine/Manager/Systems/Logger/logger_system.hpp"

namespace engine
{


  Result EngineStartup::Init(SystemManager& m_SystemManager)
  {

      if (auto result = m_SystemManager.RegisterSystem<LoggerSystem>(); result.IsFailure()) return result; //Creates a var when it is needed /C++17
     // if (auto result = m_SystemManager.RegisterSystem<PlatformSystem>(); result.IsFailure()) return result; //Creates a var when it is needed /C++17
      //m_SystemManager.RegisterSystem<>();
     // m_SystemManager.RegisterSystem<engine::LoggerSystem>();
     // m_SystemManager.RegisterSystem<engine::>();
      return {};

  }



} // engine