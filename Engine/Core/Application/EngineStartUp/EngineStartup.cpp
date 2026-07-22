//
// Created by nazzazel on 13.07.2026.
//

#include "EngineStartup.hpp"

#include "Core/Application/Additions/StartUpConfig/start_up_config.hpp"
#include "Core/Systems/Logger/LoggerSystem.hpp"
#include "Core/Systems/Platform/PlatformSystem.hpp"
#include "Core/Systems/Renderer/RendererSystem.hpp"
#include "Core/Systems/Time/TimeSystem.hpp"
#include "Core/Systems/Window/WindowSystem.hpp"
#include "../../Systems/Renderer/IRenderer/IRenderer.hpp"


namespace engine
{


  Result EngineStartup::Init(SystemManager& m_SystemManager, AppSettings& m_Settings )
  {

      if (Result result = m_SystemManager.RegisterSystem<TimeSystem     >(); result.IsFailure()) return result; //Creates a var when it is needed /C++17
      if (Result result = m_SystemManager.RegisterSystem<LoggerSystem   >(); result.IsFailure()) return result; //Creates a var when it is needed /C++17
      if (Result result = m_SystemManager.RegisterSystem<PlatformSystem >(); result.IsFailure()) return result; //Creates a var when it is needed /C++17
      if (Result result = m_SystemManager.RegisterSystem<WindowSystem   >(); result.IsFailure()) return result; //Creates a var when it is needed /C++17
      if (Result result = m_SystemManager.RegisterSystem<RendererSystem >(); result.IsFailure()) return result; //Creates a var when it is needed /C++17
      //if (Result result = m_SystemManager.RegisterSystem<RendererSystem >(); result.IsFailure()) return result; //Creates a var when it is needed /C++17



     // m_Renderer = std::unique_ptr<Renderer>(Renderer::Create());
     // m_Renderer->Init();
      //m_MainWindow->AddResizeListener([this](int w, int h)

      //engine::DebugInput::Init(m_MainWindow->GetNativeWindow());
      /// engine::DebugInput::Init(m_MainWindow->GetNativeWindow()); //KEY HANDLER
      ///
      /// todo 3 m_AssetManager->GetShaderManager().Add(engine::ShaderTypeID::Basic);
      ///
      /// //         //m_Rot_Cube = std::make_unique<Rot_Cube>();
      //         //m_Rot_Cube->Init(*m_AssetManager);

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

       if (Result result = Configure(m_SystemManager, m_Settings); result.IsFailure()){return result;}
       if (Result result = Initialize(m_SystemManager);               result.IsFailure()){return result;}

      return {};

  }

  Result EngineStartup::Configure(SystemManager& m_SystemManager,AppSettings& m_Settings)
  {
      // Configuraten of the system mainly passing or pre Init apply of settings
      auto window = m_SystemManager.GetSystem<WindowSystem>(); window->PreInitWindowConfig(
            m_Settings.GetWindowConfiguration().GetTitle(),
            m_Settings.GetWindowConfiguration().GetWindowWidth(),
            m_Settings.GetWindowConfiguration().GetWindowHeight());


      return {};
  }

  Result EngineStartup::Initialize(SystemManager& m_SystemManager)
  {
      if (Result result = m_SystemManager.InitialiseAll(); result.IsFailure()){return result;}
      return {};
  }
} // engine