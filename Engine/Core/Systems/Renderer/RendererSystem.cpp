//
// Created by nazzazel on 22.07.2026.
//

#include "RendererSystem.hpp"




namespace engine
{


    Result RendererSystem::OnInit()
    {
        m_SystemManager = this->GetSystemManager();
        m_Logger = m_SystemManager->GetSystem<LoggerSystem>();

        if (!m_SystemManager)
        {
            return SYSTEM_RESULT(SystemManagerNotSet,Error);//todo
        }

        m_Logger->AddInfo("Renderer System Initiation");

        backends::RendererAPI::SetAPI(backends::RendererAPIType::OpenGL);

        m_Logger->AddInfo("Renderer System Renderer API set to -> ", backends::RendererAPI::RendererAPIToString(backends::RendererAPI::GetAPI()));

            m_Renderer = std::unique_ptr<IRenderer>(IRenderer::Create());
            if (!m_Renderer){return SYSTEM_RESULT(FailedToInitialize,Fatal);}
        m_Logger->AddInfo("Renderer Instance Created");
        if (Result result = m_Renderer->Init(); result.IsFailure()) return result;
        m_Logger->AddInfo("Renderer Instance Initiated");


        return {};
    }

    Result RendererSystem::OnUpdate(float dt)
    {
       //m_Renderer->BeginFrame();
       //m_Renderer->EndFrame();


        return {};
    }

    Result RendererSystem::OnShutdown()
    {


        return {};
    }

    Result RendererSystem::ChangeGraphicAPI(backends::RendererAPIType type)
    {
        backends::RendererAPI::SetAPI(type);
        return {};
    }
} // engine