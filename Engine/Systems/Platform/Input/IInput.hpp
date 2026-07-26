//
// Created by nazzazel on 25.07.2026.
//


#pragma once
#include "KeyCodes.hpp"

namespace engine
{
    class IInput
    {
        public:
        virtual void InputCallback(engine::KeyCodes keyCode) = 0;
        virtual ~IInput() = default;
    };


}

