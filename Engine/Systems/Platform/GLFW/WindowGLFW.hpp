//
// Created by nazzazel on 20.07.2026.
//

#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Core/Systems/Window/IWindow/IWindow.hpp"



namespace engine
{
    class WindowGLFW : public IWindow
    {
    public:
        WindowGLFW(const std::string& title, int width, int height, IWindow* shared, SystemManager* m_SystemManager);
        ~WindowGLFW() override;

        // Lifecycle
        //virtual Result Initialize(int width, int height, const std::string& title) override;
        Result Initialize() override;
        Result Shutdown() override;

        // Loop management
        [[nodiscard]] bool ShouldClose() const override;
        void PollEvents() override;

        void MakeContextCurrent()  override;
        void SwapBuffers() override;

        //Setters
         Result SetName(const std::string& name) override;


        void GetWindowSize(int &windowWidth, int &windowHeight) override;
        void GetFramebufferSize(int &framebufferWidth,int &framebufferHeight) override;

        //Bool
         [[nodiscard]] bool IsFocused() const override;
         [[nodiscard]] bool IsMinimized() const override;


        // State access
        [[nodiscard]] void* GetNativeWindow() const override; // Return GLFWwindow*

        private:
        GLFWwindow* m_Window;
        IWindow* m_SharedWindow;

        int m_Width, m_Height;
        std::string m_Title;

    };


} // engine
