//
// Created by nazzazel on 24.07.2026.
//


#pragma once
#include "EventBus.hpp"
#include "Core/Systems/IEngineSystem.hpp"
#include "Core/Systems/Logger/LoggerSystem.hpp"


namespace engine
{
    class EventSystem: public IEngineSystem
    {
    public:
        ~EventSystem() override = default;
        Result OnInit() override;// Forced
        Result OnUpdate(float dt) override;
        Result OnShutdown() override;

        EventBus* GetEventBus() {return &m_EventBus;};


    private:
        SystemManager* m_SystemManager = nullptr;
        LoggerSystem* m_Logger = nullptr;

        EventBus m_EventBus;
        inline static EventSystem* s_Instance = nullptr; // for sake of controller and global events //go figure
    };
} // engine
