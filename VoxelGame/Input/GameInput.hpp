//
// Created by nazzazel on 25.07.2026.
//


#pragma once
#include <glm/vec3.hpp>

#include "Systems/Platform/Input/IInput.hpp"
#include "Systems/Platform/Input/KeyCodes.hpp"


namespace voxelgame
{
    class GameInput : public engine::IInput
    {
        public:
        void SetVec3Ptr(glm::vec3* ptr){m_pos_ptr = ptr;}
        private:
        void InputCallback(engine::KeyCodes  keyCode) override;

        glm::vec3* m_pos_ptr;
    };


}
