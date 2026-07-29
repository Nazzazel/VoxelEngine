//
// Created by nazzazel on 28.07.2026.
//


#pragma once

#include "Core/Application/AppInterface/IAppInterface.hpp"
#include "Core/Systems/Input/InputSystem.hpp"
#include "Systems/Platform/Input/InputMapStates.hpp"
#include "VoxelGame/Games/OpenGLTests/Core/Systems/Camera/OpenGLCamera.hpp"


namespace opengltests
{
    class InputHandler
    {
        public:
        InputHandler(engine::InputSystem& inputs_system,OpenGLCamera& camera,engine::IAppInterface& engine):
        m_input(inputs_system),

        m_keyboardInputStateMap(*inputs_system.GetKeybordInputStateMap()),
        m_mouseInputState(*inputs_system.GetMouseInputState()),
        m_camera(camera),
        m_engine(engine)
        {};

        ~InputHandler() = default;

        void OnUpdate(float dt);

        private:

        void KeyboardHandler(float dt);
        void MouseHandler(float dt);

        private:
        engine::InputSystem& m_input;
        engine::IAppInterface& m_engine;


        engine::KeybordInputStateMap&   m_keyboardInputStateMap;
        engine::MouseInputState&        m_mouseInputState;

        OpenGLCamera& m_camera;

        float moveSpeed;
    };
} // voxelgame
