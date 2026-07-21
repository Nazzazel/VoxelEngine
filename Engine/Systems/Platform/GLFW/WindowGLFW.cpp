//
// Created by nazzazel on 20.07.2026.
//

#include "WindowGLFW.hpp"

#include "Core/Manager/SystemManager.hpp"
#include "Core/Systems/Platform/PlatformSystem.hpp"


namespace engine
{
    WindowGLFW::WindowGLFW(const std::string& title, int width, int height, IWindow* shared, SystemManager* system_manager)
    : m_Window(nullptr), m_Width(width), m_Height(height), m_Title(title), m_SharedWindow(shared), m_SystemManager(system_manager)
    {
        std::cout << "gffghfhgfgh\n";
    }

    WindowGLFW::~WindowGLFW()
    {
        Result result = WindowGLFW::Shutdown();
    }

    Result WindowGLFW::Initialize()
    {
        if (m_Window)
        {
            //return Result::AlreadyInitialized; // Or your engine's equivalent success/error enum
        }

        GLFWwindow* sharedContext = m_SharedWindow ? static_cast<GLFWwindow*>(m_SharedWindow->GetNativeWindow()) : nullptr;

        m_Window = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), nullptr, sharedContext);
        if (!m_Window)
        {
            if (Result result = m_SystemManager->ShutdownAll();result.IsFailure()){return result;}
            return PLATFORM_RESULT(WindowCreationFailed,Fatal);// do it later  //TODO
            // debugtools::Logger::Log(debugtools::LogLevel::Error, "Failed to create GLFW window");
            //return Result::Failure;
        }

        glfwSetWindowUserPointer(m_Window, this);
        MakeContextCurrent();

        static bool s_GLInitialized = false;
        if (!s_GLInitialized)
        {
            if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
            {
                std::cerr << "Failed to initialize GLAD\n";
                glfwDestroyWindow(m_Window);
                m_Window = nullptr;
                //return Result::Failure;
            }
            s_GLInitialized = true;
        }

        // glfwSetFramebufferSizeCallback(m_Window, WindowGLFW::FramebufferSizeCallback);
        //return Result::Success;
        return Result::SUCCESS();
    }

    Result WindowGLFW::Shutdown()
    {
        if (m_Window)
        {
            glfwDestroyWindow(m_Window);
            m_Window = nullptr;
        }

        return Result::SUCCESS();
    }

    bool WindowGLFW::ShouldClose() const
    {
        return m_Window ? glfwWindowShouldClose(m_Window) : true;
    }

    void WindowGLFW::PollEvents()
    {
        glfwPollEvents();
    }

    void WindowGLFW::MakeContextCurrent()
    {
        if (m_Window)
        {
            glfwMakeContextCurrent(m_Window);

            glfwSwapInterval(0); //TODO
        }
    }

    void WindowGLFW::SwapBuffers()
    {
        if (m_Window)
        {
            glfwSwapBuffers(m_Window);
        }
    }

    Result WindowGLFW::SetName(const std::string& name)
    {
        m_Title = name;
        if (m_Window)
        {
            glfwSetWindowTitle(m_Window, m_Title.c_str());
        }
        return Result::SUCCESS();
    }

    void WindowGLFW::GetWindowSize(int& windowWidth, int& windowHeight)
    {
        if (m_Window)
        {
            glfwGetWindowSize(m_Window, &windowWidth, &windowHeight);
        }
        else
        {
            windowWidth = 0;
            windowHeight = 0;
        }
    }

    void WindowGLFW::GetFramebufferSize(int& framebufferWidth, int& framebufferHeight)
    {
        if (m_Window)
        {
            glfwGetFramebufferSize(m_Window, &framebufferWidth, &framebufferHeight);
        }
        else
        {
            framebufferWidth = 0;
            framebufferHeight = 0;
        }
    }

    bool WindowGLFW::IsFocused() const
    {
        if (!m_Window) return false;
        return glfwGetWindowAttrib(m_Window, GLFW_FOCUSED) != 0;
    }

    bool WindowGLFW::IsMinimized() const
    {
        if (!m_Window) return false;
        return glfwGetWindowAttrib(m_Window, GLFW_ICONIFIED) != 0;
    }

    void* WindowGLFW::GetNativeWindow() const
    {
        return static_cast<void*>(m_Window);

    }
} // engine