//
// Created by nazzazel on 26.07.2026.
//


#pragma once


namespace voxelgame
{
    class Camera
    {
    public:
        void MoveFront(float amount);
        void MoveRight(float amount);
        void SetPosition(const glm::vec3& pos);
        const glm::vec3& GetPosition() const;
        glm::mat4 GetViewMatrix() const;

    private:
        glm::vec3 m_camera_direction = glm::vec3(0.0f,  0.0f,  0.0f); // direction represented from 0.0 1.0

        glm::vec3 m_position = glm::vec3(0.0f,  0.0f,  0.0f);
        glm::vec3 m_front    = glm::vec3(0.0f,  0.0f, -1.0f);
        glm::vec3 m_up       = glm::vec3(0.0f,  1.0f,  0.0f);

        glm::quaterian

    };
} // voxelgame
