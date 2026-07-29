//
// Created by nazzazel on 28.07.2026.
//

#include "RotatingCube.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
//#include <glm/fwd.hpp>

#include "Core/Systems/Assets/AssetSystem.hpp"
#include "OpenGL/tests/tests.hpp"
#include "Systems/Renderer/Renderer/DrawComponents.hpp"


namespace opengltests
{
    RotatingCube::~RotatingCube()
    {

    }

    void RotatingCube::Init(engine::AssetSystem& assets)
    {
        // 24 Vertices for a distinct-colored cube
        float cubeVertices[] = {
            // Front face (Red)
             -0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f , 1.0f, 1.0f,
              0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f , 1.0f, 0.0f,
              0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f , 0.0f, 0.0f,
             -0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f , 0.0f, 1.0f,
            // Back face (Green)
             -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f , 1.0f, 1.0f,
             -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f , 1.0f, 0.0f,
              0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f , 0.0f, 0.0f,
              0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f , 0.0f, 1.0f,
            // Top face (Blue)
             -0.5f,  0.5f, -0.5f,  0.0f, 0.0f, 1.0f , 1.0f, 1.0f,
             -0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f , 1.0f, 0.0f,
              0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f , 0.0f, 0.0f,
              0.5f,  0.5f, -0.5f,  0.0f, 0.0f, 1.0f , 0.0f, 1.0f,
            // Bottom face (Yellow)
             -0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 0.0f , 1.0f, 1.0f,
              0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 0.0f , 1.0f, 0.0f,
              0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 0.0f , 0.0f, 0.0f,
             -0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 0.0f , 0.0f, 1.0f,
            // Right face (Magenta)
              0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 1.0f , 1.0f, 1.0f,
              0.5f,  0.5f, -0.5f,  1.0f, 0.0f, 1.0f , 1.0f, 0.0f,
              0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 1.0f , 0.0f, 0.0f,
              0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 1.0f , 0.0f, 1.0f,
            // Left face (Cyan)
             -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 1.0f , 1.0f, 1.0f,
             -0.5f, -0.5f,  0.5f,  0.0f, 1.0f, 1.0f , 1.0f, 0.0f,
             -0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 1.0f , 0.0f, 0.0f,
             -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 1.0f , 0.0f, 1.0f
        };

        // 12 Triangles (6 faces * 2 triangles)
        uint32_t cubeIndices[] = {
            0,  1,  2,  2,  3,  0,
            4,  5,  6,  6,  7,  4,
            8,  9,  10, 10, 11, 8,
            12, 13, 14, 14, 15, 12,
            16, 17, 18, 18, 19, 16,
            20, 21, 22, 22, 23, 20
        };


        m_shader = assets.GetShaderManager().Get(engine::ShaderTypeID::Basic);


        m_Material = std::make_shared<engine::Material>(m_shader);

    // m_Material->SetFloat4()


     backends::tests(); //t
     const engine::BufferLayout layout =
      {
      {engine::ShaderDataType::Float3,"a_Position"}
      ,{engine::ShaderDataType::Float3,"a_Color"}
      ,{engine::ShaderDataType::Float2,"a_TexCoord"}
      };

        m_Mesh = std::make_shared<engine::Mesh>(
           cubeVertices,
           sizeof(cubeVertices),
           layout,
           cubeIndices,
           std::size(cubeIndices)
        );

    }


    void RotatingCube::Draw(engine::IRenderer& renderer)
    {
     engine::DrawCommand cmd;


     //  float time = (float)glfwGetTime();
     float time = 1;

     // 2. Create an identity matrix, then rotate it
     glm::mat4 model = glm::mat4(1.0f);


      //model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
      model = glm::translate(model, m_Position);

      // Rotate over time around a diagonal axis (X and Y) so we see it in 3D
      model = glm::rotate(model, time * glm::radians(20.0f), glm::vec3(0.0f, 1.0f, 0.0f));

      cmd.modelMatrix = model;
      cmd.material    = m_Material;
      cmd.mesh        = m_Mesh;


      renderer.Submit(cmd);
    }

}