//
// Created by nazzazel on 24.07.2026.
//


#pragma once
namespace engine
{
    struct IEvent
    {
        virtual ~IEvent() = default;
        bool Handled = false;//Propagation
    };
}