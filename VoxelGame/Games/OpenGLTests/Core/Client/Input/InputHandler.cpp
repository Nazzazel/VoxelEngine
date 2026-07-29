//
// Created by nazzazel on 28.07.2026.
//

#include "InputHandler.hpp"

#include "Core/Systems/Window/WindowSystem.hpp"

namespace opengltests
{
    void InputHandler::OnUpdate(float dt)
    {
        KeyboardHandler(dt);
        MouseHandler(dt);

        moveSpeed = 2.5f * dt;


    }
    bool cursorbool = true;


    void InputHandler::KeyboardHandler(float dt)
    {
        if (m_keyboardInputStateMap.IsKeyPressed(engine::KeyCodes::KEY_W))
        {
            m_camera.MoveFront(moveSpeed);
        }
        if (m_keyboardInputStateMap.IsKeyPressed(engine::KeyCodes::KEY_S))
        {
            m_camera.MoveFront(-moveSpeed);
        }
        if (m_keyboardInputStateMap.IsKeyPressed(engine::KeyCodes::KEY_A))
        {
            m_camera.MoveRight(moveSpeed);
        }
        if (m_keyboardInputStateMap.IsKeyPressed(engine::KeyCodes::KEY_D))
        {
            m_camera.MoveRight(-moveSpeed);
        }
        if (m_keyboardInputStateMap.IsKeyPressed(engine::KeyCodes::KEY_SPACE))
        {
            m_camera.MoveUp(-moveSpeed);
        }
        if (m_keyboardInputStateMap.IsKeyPressed(engine::KeyCodes::KEY_LEFT_SHIFT))
        {
            m_camera.MoveUp(moveSpeed);
        }
        if (m_keyboardInputStateMap.IsKeyPressed(engine::KeyCodes::KEY_ESCAPE))
        {
            cursorbool = !cursorbool;
            m_engine.GetWindowSystem().EnableCursor(cursorbool);
           // m_engine.GetWindowSystem().EnableCursor(cursorbool);
                    //m_camera->SetPosition(glm::vec3(0.0f));
            m_camera.SetPosition(glm::vec3(0.0f, 0.0f, 0.0f));
        }
        if (m_keyboardInputStateMap.IsKeyPressed(engine::KeyCodes::KEY_R))
        {
          //m_camera->Rotate(glm::vec3(0.0f));
            m_camera.Rotate(0,0.01f);
        }

    }


    void InputHandler::MouseHandler(float dt)
    {

        m_camera.Update(dt);

        float xoffset = m_mouseInputState.xDelta;
        float yoffset = m_mouseInputState.yDelta;

        float xscrolloffset = m_mouseInputState.m_xScrollDelta;
        float yscrolloffset = m_mouseInputState.m_yScrollDelta;

        // Reset deltas so they don't continuously spin the camera next frame
        m_mouseInputState.ResetDeltas();

        if (xoffset != 0.0f || yoffset != 0.0f )
        {
            //std::cout <<   " " << yoffset << " "   << " " << xoffset << std::endl;
            m_camera.Rotate(yoffset, xoffset);
        }

        if (xscrolloffset != 0.0f || yscrolloffset != 0.0f )
        {
            //std::cout <<   " " << yoffset << " "   << " " << xoffset << std::endl;
            m_camera.SetScoll(xscrolloffset,yscrolloffset);
        }
    }



} // voxelgame