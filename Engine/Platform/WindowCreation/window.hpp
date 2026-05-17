#pragma once
#include <string>
#include <functional>

struct GLFWwindow;

namespace engine
{
    class Window
    {
    public:
        virtual ~Window() = default;

        virtual void PollEvents()   = 0;
        virtual bool ShouldClose()  = 0;

        virtual void MakeContextCurrent()  = 0;
        virtual void SwapBuffers() = 0;

        virtual void SetName(std::string& name) = 0;

        //std::function<void(int, int)> OnResize;
        
            using ResizeCallback = std::function<void(int, int)>;

            void AddResizeListener(ResizeCallback callback);

        virtual GLFWwindow* GetNativeWindow() = 0;

        static Window* Create(const char* title, int width, int height, Window* shared = nullptr);
    protected:
        void NotifyResize(int w, int h);

    private:
        std::vector<ResizeCallback> m_ResizeCallbacks;
    };
}