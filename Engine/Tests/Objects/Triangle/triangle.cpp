#include "triangle.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/fwd.hpp>


namespace engine
{
    //std::unique_ptr<VertexArray>  m_vao;
    //std::unique_ptr<VertexBuffer> m_vbo;
    //std::unique_ptr<IndexBuffer>  m_ibo;
    //std::shared_ptr<engine::GameShader> m_shader;

    void Triangle::Init(AssetManager& assets)
    {

        //float positions[]
        //{
        //    // position      // color
        //    -0.5f,  -0.5f,    1.0f, 0.0f, 0.0f,
        //     0.5f,  -0.5f,    0.0f, 1.0f, 0.0f,
        //     0.5f,   0.5f,    0.0f, 0.0f, 1.0f,
        //    -0.5f,   0.5f,    0.5f, 0.5f, 0.5f
        //};

        float positions[] =
        {
            // position (pixels)   // color
            -0.5f, -0.5f,  0.5f,       1.0f, 0.0f, 0.0f ,
             0.5f, -0.5f,  0.5f,       1.0f, 0.0f, 0.0f ,
             0.5f,  0.5f,  0.5f,       1.0f, 0.0f, 0.0f ,
            -0.5f,  0.5f,  0.5f,       1.0f, 0.0f, 0.0f
        };

        //float vertices[] =
        //{
        //    // position      // color
        //    -0.5f, -0.5f,     1.0f, 0.0f, 0.0f,   // red
        //     0.5f, -0.5f,     0.0f, 1.0f, 0.0f,   // green
        //     0.0f,  0.5f,     0.0f, 0.0f, 1.0f    // blue
        //};

        unsigned int indices[] = {
            0,1,2,
            2,3,0
        };

        //float vertices[] = {
        //    -0.5f, -0.5f, 0.0f,
        //     0.5f, -0.5f, 0.0f,
        //     0.0f,  0.5f, 0.0f
        //};

        //uint32_t indices[] = { 0, 1, 2 };

        m_vao = VertexArray::Create();
        //m_ibo = IndexBuffer::Create(indices, 6);

        auto vbo = VertexBuffer::Create(positions, sizeof(positions));
       
        m_vao->Bind();

        vbo->SetLayout(
            {
                {ShaderDataType::Float3,"a_Position"},
                {ShaderDataType::Float3,"a_Color"}

            
            });

        //// layout (important!)
        //m_vao->AddVertexBuffer(m_vbo,
        //    {
        //    { ShaderDataType::Float3, "a_Position" }
        //    }
        //);



		m_vao->AddVertexBuffer(std::move(vbo));
        m_vao->SetIndexBuffer(IndexBuffer::Create(indices, 6));

        //m_ibo->Bind();

        m_shader = assets.GetShaderManager().Get(ShaderTypeID::Basic);

       
      

    }

    void Triangle::Draw(Renderer& renderer)
    {
        m_shader->Bind();

        //location = glGetUniformLocation(m_shader->GetID(), "u_Color");
        //glUniform4f(location, 0.8f, 0.3f, 0.8f, 1.0f);
        //
        //float r = (float)rand() / (float)RAND_MAX;
        //float g = (float)rand() / (float)RAND_MAX;
        //float b = (float)rand() / (float)RAND_MAX;
        //
        //m_shader->SetFloat4("u_Color", r, g, b, 1.0f);
        //
        //m_shader->SetFloat4("u_Color", 0.8f, 0.3f, 0.8f, 1.0f);
        //
        //m_shader->SetFloat("u_Time", glfwGetTime());


        //renderer.
        //int width = 1280;
        //int height = 720;
        //
        //glm::mat4 projection = glm::ortho(
        //    0.0f, (float)width,
        //    0.0f, (float)height
        //);

                // 1. Calculate a rotation angle based on elapsed time
        float time = (float)glfwGetTime();

        // 2. Create an identity matrix, then rotate it
        glm::mat4 model = glm::mat4(1.0f);

        // Rotate over time around a diagonal axis (X and Y) so we see it in 3D
       // model = glm::rotate(model, glm::radians(5.0f), glm::vec3(0.0f, 1.0f, 0.0f));


        m_shader->SetMat4("u_Projection", renderer.GetProjection());
        m_shader->SetMat4("u_Model", model);
        //m_shader->SetMat4("u_Projection", projection);

        m_vao->Bind();
        renderer.DrawIndexed(m_vao);
    }
}