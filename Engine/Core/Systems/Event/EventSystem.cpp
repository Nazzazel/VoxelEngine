//
// Created by nazzazel on 24.07.2026.
//

#include "EventSystem.hpp"

#include "Events.hpp"
#include "Core/Systems/Window/WindowSystem.hpp"
#include "GLFW/glfw3.h"

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

        // 1. Grab the WindowSystem to hook into GLFW callbacks
        auto windowSystem = m_SystemManager->GetSystem<WindowSystem>();

        s_Instance = this;

//        glfwSetJoystickUserPointer(-2137,s_Instance);

        glfwSetJoystickCallback([](int jid, int event)
        {
            if (s_Instance)
            {
                bool connected = (event == GLFW_CONNECTED);
                s_Instance->GetEventBus()->Emit<events::JoystickConnectEvent>(jid, connected);
            }
        });


        if (windowSystem && windowSystem->GetWindow())
        {
            GLFWwindow* nativeWindow = static_cast<GLFWwindow*>(windowSystem->GetWindow()->GetNativeWindow());

            // 2. Set the GLFW Key Callback to emit events into our EventBus
            glfwSetWindowUserPointer(nativeWindow, &m_EventBus);


            // Window Size / Framebuffer Resize Callback
            glfwSetFramebufferSizeCallback(nativeWindow, [](GLFWwindow* window, int width, int height) {
                auto eventBus = static_cast<EventBus*>(glfwGetWindowUserPointer(window));
                if (eventBus) {
                    eventBus->Emit<events::WindowResizeEvent>(width, height);
                }
            });

            glfwSetWindowFocusCallback(nativeWindow, [](GLFWwindow* window, int focused)
            {
                    auto eventBus = static_cast<EventBus*>(glfwGetWindowUserPointer(window));
                    if (eventBus)
                {
                    eventBus->Emit<events::WindowFocusEvent>(focused == GL_TRUE);
                }
            });



            glfwSetDropCallback(nativeWindow, [](GLFWwindow* window, int path_count, const char* paths[])
            {
                auto eventBus = static_cast<EventBus*>(glfwGetWindowUserPointer(window));
                if (eventBus)
                {
                    eventBus->Emit<events::FileDropEvent>(path_count, paths);
                }
            });







            glfwSetKeyCallback(nativeWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods)
            {
                auto eventBus = static_cast<EventBus*>(glfwGetWindowUserPointer(window));
                if (eventBus)
                {
                    if (action == GLFW_PRESS || action == GLFW_REPEAT)
                    {
                        eventBus->Emit<events::KeyPressedEvent>(key);
                    }
                    if (action == GLFW_RELEASE)
                    {
                        eventBus->Emit<events::KeyReleasedEvent>(key);
                    }

                }
            });

            glfwSetCharCallback(nativeWindow, [](GLFWwindow* window, unsigned int codepoint)
            {
                auto eventBus = static_cast<EventBus*>(glfwGetWindowUserPointer(window));
                if (eventBus)
                {
                    eventBus->Emit<events::KeyTypedEvent>(codepoint);
                }
            });


            glfwSetCursorPosCallback(nativeWindow, [](GLFWwindow* window, double xPos, double yPos)
            {
                auto eventBus = static_cast<EventBus*>(glfwGetWindowUserPointer(window));
                if (eventBus)
                {
                    eventBus->Emit<events::MouseMovedEvent>((float)xPos, (float)yPos);
                }
            });

            // Mouse Button Callback
            glfwSetMouseButtonCallback(nativeWindow, [](GLFWwindow* window, int button, int action, int mods) {
                auto eventBus = static_cast<EventBus*>(glfwGetWindowUserPointer(window));
                if (eventBus) {
                    if (action == GLFW_PRESS) eventBus->Emit<events::MouseButtonPressedEvent>(button);
                    else if (action == GLFW_RELEASE) eventBus->Emit<events::MouseButtonReleasedEvent>(button);
                }
            });
































        }

        return {};
    }

    Result EventSystem::OnUpdate(float dt)
    {

        m_EventBus.ProcessEvents();

        return {};
    }

    Result EventSystem::OnShutdown()
    {


        return {};
    }



} // engine