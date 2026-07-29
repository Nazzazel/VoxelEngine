//
// Created by nazzazel on 28.07.2026.
//


#pragma once
#include "Core/Systems/Input/InputSystem.hpp"
#include "Systems/Platform/Input/InputMapStates.hpp"


namespace voxelgame
{
    class InputHandler
    {
        public:
        InputHandler(engine::InputSystem& inputs_system):
        m_input(inputs_system),

        m_keyboardInputStateMap(*inputs_system.GetKeybordInputStateMap()),
        m_mouseInputState(*inputs_system.GetMouseInputState())

        {};

        ~InputHandler() = default;



        void KeyboardHandler();
        void MouseHandler();

        private:
        engine::InputSystem& m_input;


        engine::KeybordInputStateMap&   m_keyboardInputStateMap;
        engine::MouseInputState&        m_mouseInputState;
    };
} // voxelgame
