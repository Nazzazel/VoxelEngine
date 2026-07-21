//
// Created by nazzazel on 21.07.2026.
//
#include "IWindow.hpp"

#include "Systems/Platform/GLFW/WindowGLFW.hpp"

namespace engine
{
    IWindow* IWindow::Create(const std::string& title, int width, int height, IWindow* shared,SystemManager* system_manager)
    {
        return new WindowGLFW(title, width, height,shared,system_manager);
    }


}
