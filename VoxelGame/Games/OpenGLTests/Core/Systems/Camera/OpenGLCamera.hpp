//
// Created by nazzazel on 26.07.2026.
//


#pragma once
#include "Core/Systems/Renderer/IRenderer/IRenderer.hpp"
#include "VoxelGame/Games/OpenGLTests/Core/Base/VoxelGameHeaders/WorldCoord.hpp"


namespace opengltests
{
    class OpenGLCamera
    {
    public:
        OpenGLCamera();

        void MoveFront(float amount);
        void MoveRight(float amount);
        void MoveUp   (float amount);
        void SetPosition(const glm::vec3& pos);
        void SetScoll(float xScrollDelta, float yScrollDelta);
        const glm::vec3& GetPosition() const;
        const WorldCoord& GetWorldPosition() const;
        glm::mat4 GetViewMatrix() const;


        void Rotate(float yoffset, float xoffset); // Added parameters for mouse offset

        void Update(float dt);

        void SetAspectRatio(float aspect);

        engine::SceneData GetSceneData() const;

    private:
        void Move(glm::vec3 delta);


        void RecalculateProjection();
        void UpdateCameraVectors();

        float cameraSpeed = 0.05f;



        //glm::vec3 cameraPos   = glm::vec3(0.0f, 0.0f,  3.0f);
        glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
        glm::vec3 cameraUp    = glm::vec3(0.0f, 1.0f,  0.0f);

        glm::vec3 movementFront = glm::vec3(0.0f, 0.0f, -1.0f);


        //glm::vec3 m_position = glm::vec3(0.0f,  0.0f,  0.0f);


        engine::SceneData m_SceneData;

        float m_yaw         = -90.0f;
        float m_pitch       = 0.0f;
        float m_AspectRatio = 1.6f;
        float fov           = 45.0f;



        WorldCoord m_WorldCameraPosition;
       // engine::IRenderer& m_renderer;

        //glm::quaterian

        //glm::vec3 m_front    = glm::vec3(0.0f,  0.0f, -1.0f);
        //glm::vec3 m_up       = glm::vec3(0.0f,  1.0f,  0.0f);

        // Direction vectors (uncomment these when you want FPS-style look/move)
        //  glm::vec3 m_front     = glm::vec3(0.0f, 0.0f, -1.0f);
        //  glm::vec3 m_up        = glm::vec3(0.0f, 1.0f, 0.0f);
        //  glm::vec3 m_right     = glm::vec3(1.0f, 0.0f, 0.0f);
        //  glm::vec3 m_worldUp   = glm::vec3(0.0f, 1.0f, 0.0f);

        //glm::vec3 m_front;
        //glm::vec3 m_up;
        //glm::vec3 m_right;
        //glm::vec3 m_worldUp;


        //glm::vec3 m_camera_direction = glm::vec3(0.0f,  0.0f,  0.0f); // direction represented from 0.0 - 1.0
        //
        //          m_cameraPos(0.0f,  0.0f,  4.0f),
        // m_cameraTarget(0.0f,  0.0f, -1.0f),
        // m_cameraUp(0.0f,  1.0f,  0.0f),
        //
        //glm::vec3 m_position = glm::vec3(0.0f,  0.0f,  0.0f);

        //glm::vec3 m_cameraPos = glm::vec3(0.0f,  0.0f,  4.0f);      // Where the camera is
        //glm::vec3 m_cameraTarget = glm::vec3(0.0f,  0.0f,  0.0f)        ;    // What it's looking at

        //glm::vec3 m_cameraDirection = glm::normalize(m_cameraPos - m_cameraTarget);

        //// glm::vec3 m_cameraUp = glm::vec3(0.0f,  1.0f,  4.0f);             // Which way is up
        //glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
        //glm::vec3 cameraRight = glm::normalize(glm::cross(up, m_cameraDirection));
        //glm::vec3 m_cameraUp = glm::cross(m_cameraDirection, cameraRight);


    };
} // voxelgame
