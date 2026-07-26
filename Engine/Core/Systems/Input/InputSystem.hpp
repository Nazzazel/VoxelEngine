//
// Created by nazzazel on 25.07.2026.
//


#pragma once
#include "Core/Systems/IEngineSystem.hpp"
#include "Core/Systems/Logger/LoggerSystem.hpp"
#include "Systems/Platform/Input/InputMapStates.hpp"


namespace engine
{
    class InputSystem: public IEngineSystem
    {
    public:
        ~InputSystem() override = default;
        Result OnInit() override;// Forced
        Result OnUpdate(float dt) override;
        Result OnShutdown() override;


        KeybordInputStateMap* GetKeybordInputStateMap();

    private:
        SystemManager* m_SystemManager = nullptr;
        LoggerSystem* m_Logger = nullptr;


        std::unique_ptr<KeybordInputStateMap> keyboardInputStateMap;

    };
} // engine
