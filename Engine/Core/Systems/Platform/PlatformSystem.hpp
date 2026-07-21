//
// Created by nazzazel on 21.07.2026.
//


#pragma once
#include "Core/Systems/IEngineSystem.hpp"
#include "Core/Systems/Logger/LoggerSystem.hpp"

namespace engine
{

    class PlatformSystem: public IEngineSystem {
    public:
        ~PlatformSystem() override = default;
        Result OnInit() override;// Forced
        Result OnUpdate(float dt) override;
        Result OnShutdown() override;


    private:
        //void callbacks
        //---- later

        //check glfw
        Result GLFWCheck();


        //setting up hints
        Result HintSetup();



    private:
        //[[nodiscard]] const LoggerSystem* GetLogger() const;



        const SystemManager* m_SystemManager = nullptr;
        const LoggerSystem* m_Logger = nullptr;
    };
} // engine