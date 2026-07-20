//
// Created by nazzazel on 20.07.2026.
//

#pragma once
#include <string>

#include "Core/Base/Result/result.hpp"

namespace engine
{
    class IWindow {
    public:
        virtual ~IWindow() = default;

        static IWindow* Create(const std::string& title, int width, int height, IWindow* shared = nullptr);

        // Lifecycle
        virtual Result Initialize(int width, int height, const std::string& title) = 0;
        virtual Result Shutdown() = 0;

        // Loop management
        [[nodiscard]] virtual bool ShouldClose() const = 0;
        virtual void PollEvents() = 0;

        virtual void MakeContextCurrent()  = 0;
        virtual void SwapBuffers() = 0;

        //Setters
        virtual Result SetName(const std::string& name) = 0;


        virtual void GetWindowSize(int &windowWidth, int &windowHeight) = 0;
        virtual void GetFramebufferSize(int &framebufferWidth,int &framebufferHeight) = 0;

        //Bool
        virtual bool IsFocused() const = 0;
        virtual bool IsMinimized() const = 0;


        // State access
        virtual void* GetNativeWindow() const = 0; // Return GLFWwindow*

        //TODO ADD event bus later

    private:

    };
}