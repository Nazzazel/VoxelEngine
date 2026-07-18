#pragma once
#include <string>
#include <functional>

struct GLFWwindow;

namespace engine
{
    class Window
    {
    public:
		enum class WindowType
        {
            Console,
			Default
        };


    public:
        virtual ~Window() = default;

        virtual void PollEvents()   = 0;
        virtual bool ShouldClose()  = 0;

        virtual void MakeContextCurrent()  = 0;
        virtual void SwapBuffers() = 0;

        //Setters
        virtual void SetName(const std::string& name) = 0;


        //Getters
        virtual GLFWwindow* GetNativeWindow() = 0;

        virtual void GetWindowSize(int &windowWidth, int &windowHeight) = 0;
        virtual void GetFramebufferSize(int &framebufferWidth,int &framebufferHeight) = 0;

        //Bool
        virtual bool IsFocused() const = 0;
        virtual bool IsMinimized() const = 0;



        //std::function<void(int, int)> OnResize;
        
            using ResizeCallback = std::function<void(int, int)>;

            void AddResizeListener(ResizeCallback callback);





        static Window* Create(const std::string& title, int width, int height, Window* shared = nullptr);
        //static Window* CreateSpecialisedWindow(const char* title, int width, int height, WindowType type, Window* shared);





    protected:
        void NotifyResize(int w, int h);

    private:
        std::vector<ResizeCallback> m_ResizeCallbacks;
    };
}