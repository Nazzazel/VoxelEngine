#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Engine/Platform/WindowCreation/window.hpp"


namespace engine
{
    class WindowGLFW : public Window
    {
    public:
        WindowGLFW(const std::string& title, int width, int height, Window* shared);
        ~WindowGLFW();

        void PollEvents() override;
        bool ShouldClose() override;

        void MakeContextCurrent() override;
        void SwapBuffers() override;

        //Setters
        void SetName(const std::string& name) override;


        //Getters
        GLFWwindow* GetNativeWindow() override { return m_Window; }

        void GetWindowSize(int &windowWidth, int &windowHeight) override;
        void GetFramebufferSize(int &framebufferWidth,int &framebufferHeight) override;

        //Bool
        bool IsFocused() const override;
        bool IsMinimized() const override;


        //std::function<void(int, int)> OnResize;
    private:
        static void FramebufferSizeCallback(GLFWwindow* window, int width, int height);

    private:
        GLFWwindow* m_Window;

    };
}