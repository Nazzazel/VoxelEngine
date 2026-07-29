//
// Created by nazzazel on 21.07.2026.
//

#include "WindowSystem.hpp"

#include "Core/Systems/Platform/PlatformSystem.hpp"


namespace engine
{

    Result WindowSystem::OnInit() // Forced
    {
        m_SystemManager = this->GetSystemManager();

        if (!m_SystemManager)
        {
            return SYSTEM_RESULT(SystemManagerNotSet,Error);//todo
        }

        m_Logger = m_SystemManager->GetSystem<LoggerSystem>();
        m_Logger->AddInfo("Window System Initiation");

        m_Window = std::unique_ptr<IWindow>(IWindow::Create( m_Title, m_Width, m_Height, m_SharedWindow, m_SystemManager ));

        m_Logger->AddInfo("Window Instance Created");
            //TODO deal with err code
            if (Result result = m_Window->Initialize(); result.IsFailure()) return result;
        m_Logger->AddInfo("Window Instance Initialized");


        //static_cast<GLFWwindow*>(m_Window.get()->GetNativeWindow());




            return {};
    }

    void WindowSystem::EnableCursor(bool enable)
    {
        if (enable)
        {
            glfwSetInputMode(static_cast<GLFWwindow*>(m_Window->GetNativeWindow()), GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        }
        else
        {
            glfwSetInputMode(static_cast<GLFWwindow*>(m_Window->GetNativeWindow()), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        }
        //glfwSetInputMode(static_cast<GLFWwindow*>(m_Window->GetNativeWindow()), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        //glfwSetInputMode(static_cast<GLFWwindow*>(m_Window->GetNativeWindow()), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    }


    Result WindowSystem::OnUpdate(float dt)
    {

        // 2. Poll window and input events (keeps the window alive/responsive)

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