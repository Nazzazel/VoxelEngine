//
// Created by nazzazel on 13.07.2026.
//
#pragma once

#include "Core/Manager/SystemManager.hpp"

namespace engine
{
    struct AppSettings;

    class EngineStartup
    {
        public:
        Result Init(SystemManager& m_SystemManager, AppSettings& m_Settings);

    private:
        //CONFIG
        Result Configure(SystemManager& m_SystemManager, AppSettings& m_Settings);
        //INITIALIZATION
        Result Initialize(SystemManager& m_SystemManager);

    };
} // engine


