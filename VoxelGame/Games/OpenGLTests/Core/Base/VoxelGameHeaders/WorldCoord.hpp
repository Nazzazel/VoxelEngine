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

    inline WorldCoord WorldCoordDiffrence (WorldCoord& newWorldCoord, WorldCoord& oldWorldCoord)
    {
        WorldCoord diff_WorldCoord;// TODO deal with the copy

        diff_WorldCoord.localOffset.x = newWorldCoord.localOffset.x - oldWorldCoord.localOffset.x;
        diff_WorldCoord.localOffset.y = newWorldCoord.localOffset.y - oldWorldCoord.localOffset.y;
        diff_WorldCoord.localOffset.z = newWorldCoord.localOffset.z - oldWorldCoord.localOffset.z;

        diff_WorldCoord.localOffset.r = newWorldCoord.localOffset.r - oldWorldCoord.localOffset.r;
        diff_WorldCoord.localOffset.g = newWorldCoord.localOffset.g - oldWorldCoord.localOffset.g;
        diff_WorldCoord.localOffset.b = newWorldCoord.localOffset.b - oldWorldCoord.localOffset.b;

        diff_WorldCoord.localOffset.s = newWorldCoord.localOffset.s - oldWorldCoord.localOffset.s;
        diff_WorldCoord.localOffset.t = newWorldCoord.localOffset.t - oldWorldCoord.localOffset.t;
        diff_WorldCoord.localOffset.p = newWorldCoord.localOffset.p - oldWorldCoord.localOffset.p;


        return diff_WorldCoord;
    }
}