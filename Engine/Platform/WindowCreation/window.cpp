#include "window.hpp"
#include "Engine/Platform/GLFW/WindowGLFW.hpp"

namespace engine
{
    Window* Window::Create(const char* title, int width, int height, Window* shared)
    {
        return new WindowGLFW(title, width, height, shared);
    }

    void Window::AddResizeListener(ResizeCallback callback)
    {
        m_ResizeCallbacks.push_back(callback);
    }

    void Window::NotifyResize(int w, int h)
    {
        for (auto& cb : m_ResizeCallbacks)
            cb(w, h);
    }
}