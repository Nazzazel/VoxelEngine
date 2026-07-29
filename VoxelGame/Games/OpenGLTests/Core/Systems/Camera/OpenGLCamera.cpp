//
// Created by nazzazel on 26.07.2026.
//

#include "OpenGLCamera.hpp"

#include <glm/ext/matrix_transform.hpp>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>

#include "GLFW/glfw3.h"

namespace opengltests
{
    OpenGLCamera::OpenGLCamera()
    : m_position(0.0f, 0.0f, 0.0f),
         //m_front(0.0f, 0.0f, -1.0f),
         //m_up(0.0f, 1.0f, 0.0f),
         //m_right(1.0f, 0.0f, 0.0f),
         //m_worldUp(0.0f, 1.0f, 0.0f),
         //m_yaw(-90.0f), // Looking down -Z by default
         //m_pitch(0.0f),


            //cameraPos(0.0f, 0.0f, 5.0f),
            //cameraTarget(0.0f, 0.0f, 0.0f),
            //cameraUp(0.0f, 1.0f, 0.0f),


          m_AspectRatio(1.6f)
    {
        UpdateCameraVectors();
        RecalculateProjection();
    }


    void OpenGLCamera::Update(float dt)
    {

        RecalculateProjection();
    }

    // Inside Camera.hpp / Camera.cpp
    void OpenGLCamera::SetAspectRatio(float aspect)
    {

        m_AspectRatio = aspect;
        RecalculateProjection();

        //m_SceneData.projectionMatrix =  glm::perspective(glm::radians(45.0f),  m_AspectRatio, 0.1f, 100.0f);

    }


    void OpenGLCamera::RecalculateProjection()
    {
        //TODO Try Out Later
        m_SceneData.projectionMatrix = glm::perspective(glm::radians(fov), m_AspectRatio, 0.1f, 100.0f);

    }
   // void Camera::Update(float aspectRatio)
   // {
//
//
//
   //   m_SceneData.projectionMatrix =  glm::perspective(glm::radians(45.0f),  aspectRatio, 0.1f, 100.0f);
//
   // }

    void OpenGLCamera::MoveFront(float amount)
    {


        if (amount > 0.0f)
        {
            cameraSpeed = amount;
            cameraPos += cameraSpeed * cameraFront;

        }

        if (amount < 0.0f)
        {
            cameraSpeed = amount;
            cameraPos += cameraSpeed * cameraFront;

        }

       // m_position.x += amount;
        //m_position += m_front * amount;
    }

    void OpenGLCamera::MoveRight(float amount)
    {
        //cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;

        if (amount > 0.0f)
        {
            cameraSpeed = -amount;
            cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
            //cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
        }

        if (amount < 0.0f)
        {
            cameraSpeed = amount;
            cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
            //cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
        }

        //m_position.x += amount;
        //m_position += m_right * amount;
    }

    void OpenGLCamera::MoveUp(float amount)
    {
        cameraSpeed = amount;
        m_position.x += amount;
        //m_position += m_up * amount;
    }

    void OpenGLCamera::SetPosition(const glm::vec3& pos)
    {
        m_position = pos;
    }

    const glm::vec3& OpenGLCamera::GetPosition() const
    {
     return m_position;
    }

    void OpenGLCamera::SetScoll(float xScrollDelta, float yScrollDelta)
    {

        fov -= (float)yScrollDelta;
        if (fov < 0.0f)
            fov = 1.0f;
       if (fov > 45.0f)
           fov = 45.0f;

    }

    glm::mat4 OpenGLCamera::GetViewMatrix() const
    {
        //return glm::lookAt(m_position, m_position, m_up);
       // return glm::mat4(1.0f);
      // const float radius = 10.0f;
      // float camX = sin(glfwGetTime()) * radius;
      // float camZ = cos(glfwGetTime()) * radius;
      // glm::mat4 view;
      // view = glm::lookAt(glm::vec3(camX, 0.0, camZ), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));

      // glm::mat4 view =
       // std::cout << "ffdfddffgg" << std::endl;
     // std::cout << glm::to_string(cameraPos) << std::endl;
      // return glm::lookAt(cameraPos, cameraTarget, cameraUp);
        //cameraPos = glm::vec3(0.0f, 0.5f, 0.0f);
        //glm::mat4 view = glm::lookAt(cameraPos, cameraTarget, cameraUp);
       // return glm::lookAt(m_cameraPos, m_cameraTarget + m_front, m_cameraUp);

        //view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

        glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

        return view;






        //std::cout << "\n================ [ CAMERA DEBUG ] ================\n";
        //std::cout << "m_position   : " << glm::to_string(m_position) << "\n";
        //std::cout << "cameraPos    : " << glm::to_string(cameraPos) << "\n";
        //std::cout << "cameraTarget : " << glm::to_string(cameraTarget) << "\n";
        //std::cout << "cameraUp     : " << glm::to_string(cameraUp) << "\n";
        //std::cout << "1View Matrix   : " << glm::to_string(view) << "\n";
       // std::cout << "=================================================\n";


        //return view;
    }

    engine::SceneData OpenGLCamera::GetSceneData() const
    {
        engine::SceneData data = m_SceneData;
        data.viewMatrix = GetViewMatrix(); // Ensure view matrix is bundled if your SceneData holds it!
        return data;
    }


    void OpenGLCamera::Rotate(float yoffset, float xoffset)
    {

        //glm::vec3 direction;
        //direction.x = cos(glm::radians(yaw)); // Note that we convert the angle to radians first
        //direction.z = sin(glm::radians(yaw));




        //m_yaw+=0.01f;
        //std::cout <<  m_yaw << std::endl;

        //degrees += 0.001;
        //cameraPos = glm::vec3(0.0f, 0.0f, 0.0f);
        //cameraTarget += glm::vec3(0.001f, 0.0f, 0.0f);

        //std::cout << cameraTarget.z << std::endl;

        // Sensitivity multiplier
        float sensitivity = 0.1f;
        xoffset *= sensitivity;
        yoffset *= sensitivity;

         m_yaw   += xoffset;
         m_pitch += yoffset;


        if (m_pitch > 89.0f)
            m_pitch = 89.0f;
        if (m_pitch < -89.0f)
            m_pitch = -89.0f;



        glm::vec3 front;
        front.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
        front.y = sin(glm::radians(m_pitch));
        front.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
        cameraFront = glm::normalize(front);


     ////// Constrain pitch to avoid screen flipping
     //if (m_pitch > 89.0f)  m_pitch = 89.0f;
     //if (m_pitch < -89.0f) m_pitch = -89.0f;

        UpdateCameraVectors();
    }





    void OpenGLCamera::UpdateCameraVectors()
    {
     //   //Calculate the new Front vector using Euler angles
    // glm::vec3 front;
    // front.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    // front.y = sin(glm::radians(m_pitch));
    // front.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    // m_front = glm::normalize(front);
//
     //   //Re-calculate the Right and Up vector
      // m_right = glm::normalize(glm::cross(m_front, m_worldUp));
       //m_up    = glm::normalize(glm::cross(m_right, m_front));
    }
} // voxelgame