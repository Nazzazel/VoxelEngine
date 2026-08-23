//
// Created by nazzazel on 26.07.2026.
//
#include "DotOnTheScreen.hpp"


#include <glad/glad.h>
#include <GLFW/glfw3.h>
//#include <glm/fwd.hpp>

#include "Core/Systems/Assets/AssetSystem.hpp"
#include "OpenGL/tests/tests.hpp"
#include "Systems/Renderer/Renderer/DrawComponents.hpp"




namespace voxelgame
{

     //std::unique_ptr<VertexArray>  m_vao;
    //std::unique_ptr<VertexBuffer> m_vbo;
    //std::unique_ptr<IndexBuffer>  m_ibo;
    //std::shared_ptr<engine::GameShader> m_shader;

    DotOnTheScreen::~DotOnTheScreen()
    {

    }

    void DotOnTheScreen::Init(engine::AssetSystem& assets)
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

       unsigned int indices[] = {
           0,1,2,
           2,3,0
       };


        backends::tests(); //todo testrerertrterteetrerttertestttttttttttttttttttttttttttttttttttt
   float positions[] =
   {
    // position (pixels)   // color
    -0.5f, -0.5f,  0.5f,       1.0f, 0.0f, 0.0f ,
     0.5f, -0.5f,  0.5f,       1.0f, 0.0f, 0.0f ,
     0.5f,  0.5f,  0.5f,       1.0f, 0.0f, 0.0f ,
    -0.5f,  0.5f,  0.5f,       1.0f, 0.0f, 0.0f
   };


        m_shader = assets.GetShaderManager().Get(engine::ShaderTypeID::Basic);



        //m_Material = std::make_shared<engine::Material>(m_shader);



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


    void DotOnTheScreen::Draw(engine::IRenderer& renderer)
    {



       // m_shader->Bind();


        // 1. Calculate a rotation angle based on elapsed time
       // float time = (float)glfwGetTime();

        // 2. Create an identity matrix, then rotate it
        glm::mat4 model = glm::mat4(1.0f);

        //model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
       // model = glm::translate(model, m_Position);

        // Rotate over time around a diagonal axis (X and Y) so we see it in 3D
       // model = glm::rotate(model, time * glm::radians(20.0f), glm::vec3(0.0f, 1.0f, 0.0f));


        engine::DrawCommand cmd;
        cmd.modelMatrix = model;
        cmd.material = m_Material;
        cmd.mesh     = m_Mesh;


        renderer.Submit(cmd);

    }

} // voxelgame