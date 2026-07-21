//
// Created by nazzazel on 21.07.2026.
//


#pragma once
#include "Core/Systems/IEngineSystem.hpp"
#include "IWindow/IWindow.hpp"
#include "Core/Manager/SystemManager.hpp"


namespace engine
{

    class WindowSystem : public IEngineSystem
    {
    public:
        ~WindowSystem() override = default;

        Result OnInit() override;// Forced
        Result OnUpdate(float dt) override;
        Result OnShutdown() override;



        IWindow* GetWindow() const;

        //Setters
        void PreInitWindowConfig(const std::string& title, int width, int height, IWindow* shared = nullptr);

    private:
        std::unique_ptr<IWindow> m_Window;



        const SystemManager* m_SystemManager = nullptr;
        const LoggerSystem* m_Logger = nullptr;

    private:
        int m_Width = 0, m_Height = 0;
        std::string m_Title;
        IWindow* m_SharedWindow;
    };
} // engine
