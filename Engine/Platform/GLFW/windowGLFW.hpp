#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Engine/Platform/WindowCreation/window.hpp"


namespace engine
{
    class WindowGLFW : public Window
    {
    public:
        WindowGLFW(const char* title, int width, int height, Window* shared);
        ~WindowGLFW();

        void PollEvents() override;
        bool ShouldClose() override;

        void MakeContextCurrent() override;
        void SwapBuffers() override;

        void SetName(std::string& name) override;

        GLFWwindow* GetNativeWindow() override { return m_Window; }

        //std::function<void(int, int)> OnResize;
    private:
        static void FramebufferSizeCallback(GLFWwindow* window, int width, int height);

    private:
        GLFWwindow* m_Window;

    };
}