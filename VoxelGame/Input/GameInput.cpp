//
// Created by nazzazel on 25.07.2026.
//

#include "GameInput.hpp"

#include <glm/vec3.hpp>


namespace voxelgame
{

    void GameInput::InputCallback(engine::KeyCodes  keyCode)
    {
        switch (keyCode)
        {
            case engine::KeyCodes::KEY_ESCAPE:
                {
                    *m_pos_ptr = glm::vec3(0.0f, 0.0f, 0.0f);
                    std::cout << "ddsd\n";
                    break;
                }
            case engine::KeyCodes::KEY_W:
                {
                    *m_pos_ptr += glm::vec3(0.0f, 0.0f, 0.1f);
                    std::cout << "ddsd\n";
                    break;
                }

            case engine::KeyCodes::KEY_S:
                {
                    *m_pos_ptr += glm::vec3(0.0f, 0.0f, -0.1f);
                    std::cout << "ddsd\n";
                    break;
                }


        }

    }


}
