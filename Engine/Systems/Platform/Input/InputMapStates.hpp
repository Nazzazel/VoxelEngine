//
// Created by nazzazel on 25.07.2026.
//


#pragma once
#include "IInput.hpp"


namespace engine
{
    struct MouseInputState
    {
        float x = 0.0f;
        float y = 0.0f;
        float xDelta = 0.0f;
        float yDelta = 0.0f;

        float m_xScrollDelta = 0.0f;
        float m_yScrollDelta = 0.0f;

        bool firstMouse = true;

        void UpdatePosition(float mouseX, float mouseY)
        {
            if (firstMouse)
            {
                x = mouseX;
                y = mouseY;
                firstMouse = false;
            }

            xDelta = mouseX - x;
            yDelta = y - mouseY; // Reversed for standard OpenGL screen coords

            x = mouseX;
            y = mouseY;
        }

        void UpdateScrollPosition(float xScrollDelta, float yScrollDelta)
        {
                m_xScrollDelta = xScrollDelta;
                m_yScrollDelta = yScrollDelta;
        }

        void ResetDeltas()
        {

            xDelta = 0.0f;
            yDelta = 0.0f;

            m_xScrollDelta = 0;
            m_yScrollDelta = 0;

        }

        void UpdateInputStates(const int32_t& keyCode, bool IsKeyPressed)
        {
            mouseKeyStates[keyCode] = IsKeyPressed;
        }




        std::vector<bool> mouseKeyStates = std::vector(30, false);;
    };


    struct KeybordInputStateMap
    {
        KeybordInputStateMap(){}
        ~KeybordInputStateMap(){}

        //std::vector<engine::KeyboardKeyData> keyStates;



        void UpdateInputStates(const int32_t& keyCode, bool IsKeyPressed)
        {

           // keyStates[0] = IsKeyPressed;

        /// keyStates =  std::vector(100, false);

        /// std::cout << "Vector size: " << keyStates.size() << std::endl;

            // if (keyStates.empty()) {
            //     std::cout << "CRITICAL: keyStates vector is empty!\n";
            //     return;
            // }
           //std::cout << keyStates[1] << std::endl   ;
            //keyStates.emplace_back(keyCode, IsKeyPressed);
            keyStates[keyCode] = IsKeyPressed;
           //auto mappedKey = static_cast<KeyCodes>(keyCode);
           //if (m_input!=nullptr)
           //{
           //    m_input->InputCallback(mappedKey);
           //}
        }

        bool IsKeyPressed(engine::KeyCodes key)
        {
            return keyStates[static_cast<int32_t>(key)];
           //return keyStates[key];
        }

      //  void SetIInput(IInput* input){if (input!=nullptr){m_input = input;}}





    private:

        IInput* m_input = nullptr;
        std::vector<bool> keyStates = std::vector(500, false);;

    };





}
