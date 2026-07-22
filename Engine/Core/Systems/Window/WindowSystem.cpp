//
// Created by nazzazel on 21.07.2026.
//

#include "WindowSystem.hpp"



namespace engine
{

    Result WindowSystem::OnInit() // Forced
    {
        m_SystemManager = this->GetSystemManager();

        m_Logger = m_SystemManager->GetSystem<LoggerSystem>();
        m_Logger->AddInfo("Window System Initiation");

        m_Window = std::unique_ptr<IWindow>(IWindow::Create( m_Title, m_Width, m_Height, m_SharedWindow, m_SystemManager ));

        m_Logger->AddInfo("Window Instance Created");
            //TODO deal with err code
            if (Result result = m_Window->Initialize(); result.IsFailure()) return result;
        m_Logger->AddInfo("Window Instance Initialized");
            return {};
    }

    Result WindowSystem::OnUpdate(float dt)
    {

        return {};
    }


    Result WindowSystem::OnShutdown()
    {
        m_Window.reset();
        return {};
    }

    IWindow* WindowSystem::GetWindow() const
    {
        return m_Window.get();
    }

    void WindowSystem::PreInitWindowConfig(const std::string& title, int width, int height, IWindow* shared)
    {
        m_Title         = title ;
        m_Width         = width ;
        m_Height        = height;
        m_SharedWindow  = shared;
    }
} // engine