//
// Created by nazzazel on 20.07.2026.
//

#pragma once

#include ".//General/GeneralHeaders.hpp"

#if defined(_WIN32)
    #include "OS_specific/WindowsHeaders.hpp"
#elif defined(__linux__)
    #include "OS_specific/LinuxHeaders.hpp"
#elif defined(__APPLE__)
    #include "OS_specific/MacHeaders.hpp"
#else
    #error "Unsupported Operating System!"
#endif

