#include "Engine/Platform/GLFW/windowGLFW.hpp"


#include "DebugTools/Core/Logger/logger.hpp"
#include <iostream>

namespace engine
{
  // WindowGLFW::WindowGLFW(const std::string& title, int width, int height, Window* shared)
  // {
  //     static bool s_GLInitialized = false;
  //     debugtools::Logger::Log(debugtools::LogLevel::Info, "Window Creation");
  //     GLFWwindow* sharedContext = shared ? shared->GetNativeWindow() : nullptr;
  //     m_Window = glfwCreateWindow(width, height, title.c_str(), nullptr, sharedContext);
//
  //     if (!m_Window)
//		{
  //         debugtools::Logger::Log(debugtools::LogLevel::Error, "Failed to create GLFW window"); //TODO add Logger
  //         engine::Platform::Shutdown();
  //         return;

//		}
  //     glfwSetWindowUserPointer(m_Window, this);


  //     debugtools::Logger::Log(debugtools::LogLevel::Info, "Set Context");
  //     MakeContextCurrent();
  //
  //     if (!s_GLInitialized)
  //     {
  //         if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  //         {
  //             std::cerr << "Failed to initialize GLAD\n";
  //             throw std::runtime_error("GLAD initialization failed");
  //             //std::exit(-1);
  //         }

  //         s_GLInitialized = true;
  //     }

  //    // glfwGetFramebufferSize(glfwGetCurrentContext(), &width, &height);
  //     glfwSetFramebufferSizeCallback(m_Window, WindowGLFW::FramebufferSizeCallback);

  //     //glfw
  //


  // }

  // void WindowGLFW::SetName(const std::string& name)
  // {
  //     glfwSetWindowTitle(m_Window, name.c_str());
  // }

  // void WindowGLFW::GetWindowSize(int& windowWidth, int& windowHeight)
  // {
  //     glfwGetWindowSize(m_Window, &windowWidth, &windowHeight);
  // }

  // void WindowGLFW::GetFramebufferSize(int& framebufferWidth, int& framebufferHeight)
  // {
  //     glfwGetFramebufferSize(m_Window, &framebufferWidth, &framebufferHeight);
  // }

  // bool WindowGLFW::IsFocused() const
  // {
  //     return glfwGetWindowAttrib(m_Window, GLFW_FOCUSED);
  // }

  // bool WindowGLFW::IsMinimized() const
  // {
  //     return glfwGetWindowAttrib(m_Window, GLFW_ICONIFIED);
  // }



  // void WindowGLFW::FramebufferSizeCallback(GLFWwindow* window, int width, int height)
  // {
  //     auto* win = static_cast<WindowGLFW*>(glfwGetWindowUserPointer(window));

  //     if (win)
  //     {
  //         win->NotifyResize(width, height);
  //     }
  // }


  // WindowGLFW::~WindowGLFW()
  // {
  //     glfwDestroyWindow(m_Window);
  // }

  // void WindowGLFW::PollEvents()
  // {
  //     glfwPollEvents();
  // }

  // bool WindowGLFW::ShouldClose()
  // {
  //     return glfwWindowShouldClose(m_Window);
  // }

  // void WindowGLFW::MakeContextCurrent()
  // {
  //     glfwMakeContextCurrent(m_Window);

//		//  change this to 1 for vsync and
  //     //  0 for no vsync depending on
  //     //  the user's preference or settins



  //     glfwSwapInterval(0); //TODO
  // }

  // void WindowGLFW::SwapBuffers()
  // {
  //     glfwSwapBuffers(m_Window);
  // }
}