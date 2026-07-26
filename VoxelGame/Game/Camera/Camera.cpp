//
// Created by nazzazel on 26.07.2026.
//

#include "Camera.hpp"

#include <glm/ext/matrix_transform.hpp>

namespace voxelgame
{
    void Camera::MoveFront(float amount)
    {
        m_position.x += amount;
    }

    void Camera::MoveRight(float amount)
    {
        m_position.x += amount;
    }

    void Camera::SetPosition(const glm::vec3& pos)
    {
        m_position = pos;
    }

    const glm::vec3& Camera::GetPosition() const
    {
     return m_position;
    }

    glm::mat4 Camera::GetViewMatrix() const
    {

        return glm::mat4(1.0f);
    }
} // voxelgame