//
// Created by nazzazel on 13.07.2026.
//

#include "engine_startup.hpp"

#include "Core/Engine/Manager/Systems/Logger/logger_system.hpp"

namespace engine
{


  Result EngineStartup::Init(SystemManager& m_SystemManager)
  {

      if (auto result = m_SystemManager.RegisterSystem<LoggerSystem>(); result.IsFailure()) return result; //Creates a var when it is needed /C++17
      //if (auto result = m_SystemManager.RegisterSystem<PlatformSystem>(); result.IsFailure()) return result;




      //std::unique_ptr<Renderer> m_Renderer;

      //IDK if I need this but I will add it later if I do
      //std::unique_ptr<AssetManager> m_AssetManager;

      //Later
      //std::unique_ptr<AssetManager> m_StateManager;
      //std::unique_ptr<AssetManager> m_TimeManager;
      //std::unique_ptr<AssetManager> m_RenderManager; //TODO inmortant
      //std::unique_ptr<AssetManager> m_CacheManager;
      //std::unique_ptr<AssetManager> m_EntityComponentManager;
      //std::unique_ptr<AssetManager> m_PhysicsManager;
      //std::unique_ptr<AssetManager> m_AudioManager;

      // if (auto result = m_SystemManager.RegisterSystem<PlatformSystem>(); result.IsFailure()) return result; //Creates a var when it is needed /C++17
      //m_SystemManager.RegisterSystem<>();
     // m_SystemManager.RegisterSystem<engine::LoggerSystem>();
     // m_SystemManager.RegisterSystem<engine::>();
      return {};

  }



} // engine