//
// Created by nazzazel on 21.07.2026.
//


#pragma once


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
                return SYSTEM_RESULT(SystemManagerNotSet,Error);   //System is uninitiated
            }
            m_Manager = system;
            return {};
        };

        [[nodiscard]] SystemManager* GetSystemManager() const {return m_Manager;};


    };
}
