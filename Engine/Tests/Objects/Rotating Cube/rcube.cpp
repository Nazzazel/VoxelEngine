#include "rcube.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/fwd.hpp>



namespace engine
{
    //std::unique_ptr<VertexArray>  m_vao;
    //std::unique_ptr<VertexBuffer> m_vbo;
    //std::unique_ptr<IndexBuffer>  m_ibo;
    //std::shared_ptr<engine::GameShader> m_shader;

    Rot_Cube::~Rot_Cube()
    {

    }

    void Rot_Cube::Init(AssetManager& assets)
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
            100.0f, 100.0f,       1,0,0,
            300.0f, 100.0f,       0,1,0,
            300.0f, 300.0f,       0,0,1,
            100.0f, 300.0f,       1,1,0
        };

        struct Vertex {
            float x, y, z;    // Position
            float r, g, b;    // Color
        };

        //// 24 Vertices for a distinct-colored cube
        //Vertex cubeVertices[] = {
        //    // Front face (Red)
        //    { -0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f },
        //    {  0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f },
        //    {  0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f },
        //    { -0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f },
        //    // Back face (Green)
        //    { -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f },
        //    { -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f },
        //    {  0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f },
        //    {  0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f },
        //    // Top face (Blue)
        //    { -0.5f,  0.5f, -0.5f,  0.0f, 0.0f, 1.0f },
        //    { -0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f },
        //    {  0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f },
        //    {  0.5f,  0.5f, -0.5f,  0.0f, 0.0f, 1.0f },
        //    // Bottom face (Yellow)
        //    { -0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 0.0f },
        //    {  0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 0.0f },
        //    {  0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 0.0f },
        //    { -0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 0.0f },
        //    // Right face (Magenta)
        //    {  0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 1.0f },
        //    {  0.5f,  0.5f, -0.5f,  1.0f, 0.0f, 1.0f },
        //    {  0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 1.0f },
        //    {  0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 1.0f },
        //    // Left face (Cyan)
        //    { -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 1.0f },
        //    { -0.5f, -0.5f,  0.5f,  0.0f, 1.0f, 1.0f },
        //    { -0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 1.0f },
        //    { -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 1.0f }
        //};

        // 24 Vertices for a distinct-colored cube
        float cubeVertices[] = {
            // Front face (Red)
             -0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f ,
              0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f ,
              0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f ,
             -0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f ,
            // Back face (Green)
             -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f ,
             -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f ,
              0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f ,
              0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f ,
            // Top face (Blue)
             -0.5f,  0.5f, -0.5f,  0.0f, 0.0f, 1.0f ,
             -0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f ,
              0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f ,
              0.5f,  0.5f, -0.5f,  0.0f, 0.0f, 1.0f ,
            // Bottom face (Yellow)
             -0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 0.0f ,
              0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 0.0f ,
              0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 0.0f ,
             -0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 0.0f ,
            // Right face (Magenta)
              0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 1.0f ,
              0.5f,  0.5f, -0.5f,  1.0f, 0.0f, 1.0f ,
              0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 1.0f ,
              0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 1.0f ,
            // Left face (Cyan)
             -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 1.0f ,
             -0.5f, -0.5f,  0.5f,  0.0f, 1.0f, 1.0f ,
             -0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 1.0f ,
             -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 1.0f 
        };

        //float vertices[] =
        //{
        //    // position      // color
        //    -0.5f, -0.5f,     1.0f, 0.0f, 0.0f,   // red
        //     0.5f, -0.5f,     0.0f, 1.0f, 0.0f,   // green
        //     0.0f,  0.5f,     0.0f, 0.0f, 1.0f    // blue
        //};

        // 12 Triangles (6 faces * 2 triangles)
        unsigned int cubeIndices[] = {
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

        //float vertices[] = {
        //    -0.5f, -0.5f, 0.0f,
        //     0.5f, -0.5f, 0.0f,
        //     0.0f,  0.5f, 0.0f
        //};

        //uint32_t indices[] = { 0, 1, 2 };

        m_vao = VertexArray::Create();
        //m_ibo = IndexBuffer::Create(indices, 6);

        auto vbo = VertexBuffer::Create(cubeVertices, sizeof(cubeVertices));

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
        m_vao->SetIndexBuffer(IndexBuffer::Create(cubeIndices, std::size(cubeIndices))); //TODO Auto count

       // //TODO DEAL WITH THIS debugtools::Logger::Log(debugtools::LogLevel::Info, "count" + std::to_string(std::size(cubeIndices)));

        //m_ibo->Bind();

        m_shader = assets.GetShaderManager().Get(ShaderTypeID::Basic);

       
      

    }
   
    void Rot_Cube::AdditionalData(float& i)
    {

		m_i = i;

    }

    void Rot_Cube::Draw(IRenderer& renderer)
    {
        m_shader->Bind();


        // 1. Calculate a rotation angle based on elapsed time
        float time = (float)glfwGetTime();

        // 2. Create an identity matrix, then rotate it
        glm::mat4 model = glm::mat4(1.0f);

        // Rotate over time around a diagonal axis (X and Y) so we see it in 3D
        model = glm::rotate(model, time * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));

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

        // 3. Upload BOTH matrices to the shader
        m_shader->SetMat4("u_Projection", renderer.GetProjection());
        m_shader->SetMat4("u_Model", model); // <-- Upload your new model matrix
        m_shader->SetFloat("u_X", m_i); // <-- Upload your new model matrix


        //m_shader->SetMat4("u_Projection", renderer.GetProjection());
        //m_shader->SetMat4("u_Projection", projection);

        m_vao->Bind();
        renderer.DrawIndexed(m_vao);
    }
}
