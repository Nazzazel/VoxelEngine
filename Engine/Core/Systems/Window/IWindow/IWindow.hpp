//
// Created by nazzazel on 20.07.2026.
//

#pragma once



namespace engine
{
    class IWindow {
    public:
        virtual ~IWindow() = default;

        [[nodiscard]] static IWindow* Create(const std::string& title, int width, int height, IWindow* shared, SystemManager* m_SystemManager);

        // Lifecycle
        [[nodiscard]] virtual Result Initialize() = 0;
        [[nodiscard]] virtual Result Shutdown() = 0;

        // Loop management
        virtual bool ShouldClose() const = 0;
        virtual void PollEvents() = 0;

        virtual void MakeContextCurrent()  = 0;
        virtual void SwapBuffers() = 0;

        //Setters
        [[nodiscard]] virtual Result SetName(const std::string& name) = 0;


        virtual void GetWindowSize(int &windowWidth, int &windowHeight) = 0;
        virtual void GetFramebufferSize(int &framebufferWidth,int &framebufferHeight) = 0;

        //Bool
        [[nodiscard]] virtual bool IsFocused() const = 0;
        [[nodiscard]] virtual bool IsMinimized() const = 0;


        // State access
        [[nodiscard]] virtual void* GetNativeWindow() const = 0; // Return GLFWwindow*

        //TODO ADD event bus later

    private:

    };


}

//TODO  create A CPP HERE IS THE PREV OF WHAT I HAD BEFORE
//namespace engine
// {
//     Window* Window::Create(const std::string& title, int width, int height, Window* shared)
//     {
//         return new WindowGLFW(title, width, height, shared);
//     }
//
//     //Window* Window::CreateSpecialisedWindow(const char* title, int width, int height, WindowType type, Window* shared)
//     //{
//     //    return new WindowGLFW(title, width, height, shared);
//     //}
//
//     void Window::AddResizeListener(ResizeCallback callback)
//     {
//         m_ResizeCallbacks.push_back(callback);
//     }
//
//     void Window::NotifyResize(int w, int h)
//     {
//         for (auto& cb : m_ResizeCallbacks)
//             cb(w, h);
//     }
// }
