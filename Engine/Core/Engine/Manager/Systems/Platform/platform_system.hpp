//
// Created by nazzazel on 13.07.2026.
//

#pragma once
#include "Core/Engine/Manager/SystemManager/EngineSystem.hpp"
#include "Core/Engine/Manager/SystemManager/system_manager.hpp"

namespace engine
{
    class PlatformSystem: public IEngineSystem {
    public:
        ~PlatformSystem() = default;
        Result OnInit() override;// Forced
        Result OnUpdate(float dt) override;
        Result OnShutdown() override;


        private:
        //[[nodiscard]] const LoggerSystem* GetLogger() const;

        const SystemManager* m_SystemManager = nullptr;
       // const LoggerSystem* m_LoggerSystemPtr = nullptr;
    };
} // engine

//TODO later think about this
//class RendererSystem : public IEngineSystem
//{
//    using Dependencies = TypeList<LoggerSystem, PlatformSystem>;
//};