//
// Created by nazzazel on 21.07.2026.
//


#pragma once
#include "Core/Systems/IEngineSystem.hpp"


namespace engine
{
    class TimeSystem: public IEngineSystem
    {
    public:
        ~TimeSystem() override = default;

        Result OnInit() override;// Forced
        Result OnUpdate(float dt) override;
        Result OnShutdown() override;

        std::string CurrentTime() const;
        float GetDeltaTime();




    private:
    };
} // engine
