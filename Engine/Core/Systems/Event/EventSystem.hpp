//
// Created by nazzazel on 24.07.2026.
//


#pragma once
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


    private:
        SystemManager* m_SystemManager = nullptr;
        LoggerSystem* m_Logger = nullptr;

    };
} // engine
