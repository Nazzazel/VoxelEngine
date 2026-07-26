//
// Created by nazzazel on 25.07.2026.
//


#pragma once
#include "IInput.hpp"


namespace engine
{



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
