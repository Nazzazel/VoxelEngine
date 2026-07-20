//
// Created by nazzazel on 13.07.2026.
//
#pragma once
#include <memory>

#include "Core/Engine/Manager/SystemManager/system_manager.hpp"
#include "Core/Engine/Manager/Systems/Result/result.hpp"


namespace engine
{
    class EngineStartup
    {
        public:
        Result Init(SystemManager& m_SystemManager);

    private:
    };
} // engine


