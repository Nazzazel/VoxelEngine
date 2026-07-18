//
// Created by nazzazel on 13.07.2026.
//

#pragma once
#include "Core/Engine/Manager/SystemManager/i_engine_system.hpp"

#include <stdint.h>
#include "Core/Engine/Manager/SystemManager/system_manager.hpp"
//#include "Core/Engine/Manager/Systems/Logger/logger_system.hpp"

namespace engine
{
    class PlatformSystem: public IEngineSystem {
    public:
        ~PlatformSystem() = default;
        uint32_t OnInit() override;// Forced
        uint32_t OnUpdate(float dt) override;
        uint32_t OnShutdown() override;


        private:
        //[[nodiscard]] const LoggerSystem* GetLogger() const;

        const SystemManager* m_SystemManager = nullptr;
       // const LoggerSystem* m_LoggerSystemPtr = nullptr;
    };
} // engine
