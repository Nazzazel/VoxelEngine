//
// Created by nazzazel on 12.07.2026.
//
#pragma once

#include "glm/fwd.hpp"
#include "glm/vec3.hpp"
#include "glm/ext/matrix_transform.hpp"

namespace voxelgame
{
    class camera
    {
    public:
        glm::vec3 Position = {0.0f, 0.0f, 3.0f};
        float Yaw = -90.0f;
        float Pitch = 0.0f;

        glm::mat4 GetViewMatrix() {
            return glm::lookAt(Position, Position + Front, Up);
        }

        //void ProcessKeyboard(Direction dir, float deltaTime);
        void ProcessMouse(float xoffset, float yoffset);
    private:
        glm::vec3 Front = {0.0f, 0.0f, -1.0f};
        glm::vec3 Up = {0.0f, 1.0f, 0.0f};
    };


}

