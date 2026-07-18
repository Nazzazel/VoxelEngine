#pragma once

#include <iostream>

#include "DebugTools/Core/Logger/logger.hpp"
#include "DebugTools/Core/Timer/time_manager.hpp"

namespace engine
{
    class Platform
    {
    public:
        static void Init();
        static void Shutdown();
    };
}