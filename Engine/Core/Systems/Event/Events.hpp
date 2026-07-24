//
// Created by nazzazel on 24.07.2026.
//


#pragma once
#include "IEvent.hpp"

namespace engine
{
    struct KeyPressedEvent : public IEvent
    {
        int KeyCode; //idk maybe m_ later i dont think so LOL
        KeyPressedEvent(int key) : KeyCode(key) {};

    };






}
