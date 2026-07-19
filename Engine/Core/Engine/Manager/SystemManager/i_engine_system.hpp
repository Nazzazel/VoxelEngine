//
// Created by nazzazel on 13.07.2026.
//

#pragma once
#include <cstdint>

#include "Core/Engine/Manager/Systems/Result/result.hpp"

//#include "Core/Engine/Manager/Systems/Platform/platform.hpp"


namespace engine
{
    class SystemManager;

    class IEngineSystem {
    protected:
        SystemManager* m_Manager = nullptr;
    public:
        virtual ~IEngineSystem() = default;
        virtual Result OnInit() = 0;    // Forced
        virtual Result OnUpdate(float dt) = 0;
        virtual Result OnShutdown() = 0;
        //Link that adds a way of using other systems inside of other systems
        //Reason: Capability of calling and using logger inside of other systems without making it a singleton
        //TODO make sure that uninitiated systems are not capable of causing problems
        [[nodiscard]] Result SetSystemManager(SystemManager* system)
        {
            if(system == nullptr)
            {
                //return 0x01;   //System is uninitiated
            }

            m_Manager = system;
            //return 0;//Succes
        };



        //[[nodiscard]] SystemManager* GetSystemManager() const {return m_Manager;};


    };
}
