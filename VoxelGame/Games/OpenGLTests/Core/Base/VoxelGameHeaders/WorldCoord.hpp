//
// Created by nazzazel on 30.07.2026.
//


#pragma once


namespace opengltests
{
    struct WorldCoord
    {
        glm::ivec3 chunkCoord = glm::ivec3(0);   // Exact grid/chunk coordinates//Set up X Y Z cord for chunks 1 is full lenght aka 1 1 1 = 16 16 16
        glm::vec3  localOffset = glm::vec3(0.0f); // Sub-block smooth position

        // Helper to get a safe, jitter-free float vector relative to a rendering anchor (like the camera)
        glm::vec3 ToRenderPos(const glm::ivec3& renderAnchor) const
        {
            glm::ivec3 diff = chunkCoord - renderAnchor;
            return glm::vec3(diff) + localOffset;
        }
    };
}