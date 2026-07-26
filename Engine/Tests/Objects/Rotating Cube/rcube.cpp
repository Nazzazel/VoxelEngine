#include "rcube.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
//#include <glm/fwd.hpp>

#include "Core/Systems/Assets/AssetSystem.hpp"
#include "OpenGL/tests/tests.hpp"
#include "Systems/Renderer/Renderer/DrawComponents.hpp"


namespace engine
{
    //std::unique_ptr<VertexArray>  m_vao;
    //std::unique_ptr<VertexBuffer> m_vbo;
    //std::unique_ptr<IndexBuffer>  m_ibo;
    //std::shared_ptr<engine::GameShader> m_shader;

    Rot_Cube::~Rot_Cube()
    {

    }

    void Rot_Cube::Init(AssetSystem& assets)
    {
     {
        //tEXTURE
      // float texCoords[] = {
      //     0.0f, 0.0f,  // lower-left corner
      //     1.0f, 0.0f,  // lower-right corner
      //     0.5f, 1.0f   // top-center corner
      // };



        //float positions[]
        //{
        //    // position      // color
        //    -0.5f,  -0.5f,    1.0f, 0.0f, 0.0f,
        //     0.5f,  -0.5f,    0.0f, 1.0f, 0.0f,
        //     0.5f,   0.5f,    0.0f, 0.0f, 1.0f,
        //    -0.5f,   0.5f,    0.5f, 0.5f, 0.5f
        //};

       //float positions[] =
       //{
       //    // position (pixels)   // color
       //     0.5f,  0.5f, 0.0f,       1.0f,0.0f,0.0f,
       //     0.5f, -0.5f, 0.0f,       0.0f,1.0f,0.0f,
       //    -0.5f, -0.5f, 0.0f,       0.0f,0.0f,1.0f,
       //    -0.5f,  0.5f, 0.0f,       1.0f,1.0f,0.0f
       //};


       //float MOREpositions[] =
       //{
       //    // position (pixels)   // color //Texture cords
       //    100.0f, 100.0f,       1,0,0,    100.0f, 100.0f,
       //    300.0f, 100.0f,       0,1,0,    300.0f, 100.0f,
       //    300.0f, 300.0f,       0,0,1,    300.0f, 300.0f,
       //    100.0f, 300.0f,       1,1,0,    100.0f, 300.0f
       //};

       //float Fvertices[] = {
       //    // positions          // colors           // texture coords
       //    0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
       //    0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
       //   -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
       //   -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left
       //;


       //struct Vertex {
       //    float x, y, z;    // Position
       //    float r, g, b;    // Color
       //};

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
     }
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

        //float vertices[] =
        //{
        //    // position      // color
        //    -0.5f, -0.5f,     1.0f, 0.0f, 0.0f,   // red
        //     0.5f, -0.5f,     0.0f, 1.0f, 0.0f,   // green
        //     0.0f,  0.5f,     0.0f, 0.0f, 1.0f    // blue
        //};

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

      //     float positions[] =
      //{
      //    // position (pixels)   // color
      //     0.5f,  0.5f, 0.0f,       1.0f,0.0f,0.0f,
      //     0.5f, -0.5f, 0.0f,       0.0f,1.0f,0.0f,
      //    -0.5f, -0.5f, 0.0f,       0.0f,0.0f,1.0f,
      //    -0.5f,  0.5f, 0.0f,       1.0f,1.0f,0.0f
      //};


        //float vertices[] = {
        //    -0.5f, -0.5f, 0.0f,
        //     0.5f, -0.5f, 0.0f,
        //     0.0f,  0.5f, 0.0f
        //};

        //uint32_t indices[] = { 0, 1, 2 };

        backends::tests(); //todo testrerertrterteetrerttertestttttttttttttttttttttttttttttttttttt
   float positions[] =
   {
    // position (pixels)   // color
    -0.5f, -0.5f,  0.5f,       1.0f, 0.0f, 0.0f ,
     0.5f, -0.5f,  0.5f,       1.0f, 0.0f, 0.0f ,
     0.5f,  0.5f,  0.5f,       1.0f, 0.0f, 0.0f ,
    -0.5f,  0.5f,  0.5f,       1.0f, 0.0f, 0.0f
   };

     {

      //   unsigned int indices[] = {
      //    0,1,2,
      //    2,3,0
      //};
      //
      //
      //  float positions[] =
      //  {
      //   // position (pixels)   // color
      //   0.5f,  0.5f, 0.0f,       1.0f,0.0f,0.0f,
      //   0.5f, -0.5f, 0.0f,       0.0f,1.0f,0.0f,
      //  -0.5f, -0.5f, 0.0f,       0.0f,0.0f,1.0f,
      //  -0.5f,  0.5f, 0.0f,       1.0f,1.0f,0.0f
      // };


     }


         //////////////////////////////////m_vao = IVertexArray::Create();
        //m_ibo = IndexBuffer::Create(indices, 6);

        //auto vbo = IVertexBuffer::Create(cubeVertices, sizeof(cubeVertices));

         // auto vbo = VertexBuffer::Create(positions, sizeof(positions));


        //---------------------------------------------------------
       ////////////////////////////////// m_vao->Bind();

    // vbo->SetLayout(
    //     {
    //         {ShaderDataType::Float3,"a_Position"}
    //         ,{ShaderDataType::Float3,"a_Color"}
    //         ,{ShaderDataType::Float2,"a_TexCoord"}


    //     });
        //---------------------------------------------------------





        //// layout (important!)
        //m_vao->AddVertexBuffer(m_vbo,
        //    {
        //    { ShaderDataType::Float3, "a_Position" }
        //    }
        //);


        //---------------------------------------------------------
       ////////////////////////////////// m_vao->AddVertexBuffer(std::move(vbo));
       ////////////////////////////////// m_vao->SetIndexBuffer(IIndexBuffer::Create(cubeIndices, std::size(cubeIndices))); //TODO Auto count



        //m_vao->SetIndexBuffer(IndexBuffer::Create(indices, std::size(indices))); //TODO Auto count

      //TODO DEAL WITH THIS debugtools::Logger::Log(debugtools::LogLevel::Info, "count" + std::to_string(std::size(cubeIndices)));

     //m_ibo->Bind();

     //m_shader = assets.GetShaderManager().Get(ShaderTypeID::Basic);
        m_shader = assets.GetShaderManager().Get(ShaderTypeID::Basic);




        //---------------------------------------------------------


     //vbo->SetLayout(
     //    {
     //        {ShaderDataType::Float3,"a_Position"}
     //        ,{ShaderDataType::Float3,"a_Color"}
     //        ,{ShaderDataType::Float2,"a_TexCoord"}
//
//
     //    });


        m_Material = std::make_shared<Material>(m_shader);



     const BufferLayout layout =
      {
      {ShaderDataType::Float3,"a_Position"}
      ,{ShaderDataType::Float3,"a_Color"}
      ,{ShaderDataType::Float2,"a_TexCoord"}
      };

        m_Mesh = std::make_shared<Mesh>(
           cubeVertices,
           sizeof(cubeVertices),
           layout,
           cubeIndices,
           std::size(cubeIndices)
        );

    }


    void Rot_Cube::Draw(IRenderer& renderer)
    {
       // m_shader->Bind();


        // 1. Calculate a rotation angle based on elapsed time
        float time = (float)glfwGetTime();

        // 2. Create an identity matrix, then rotate it
        glm::mat4 model = glm::mat4(1.0f);

        //model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
        model = glm::translate(model, m_Position);

        // Rotate over time around a diagonal axis (X and Y) so we see it in 3D
        model = glm::rotate(model, time * glm::radians(20.0f), glm::vec3(0.0f, 1.0f, 0.0f));

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


        //---------
  //     // 3. Upload BOTH matrices to the shader
  // /m_shader->SetMat4("u_Projection", renderer.GetProjection());
  ////  //m_shader->SetMat4("u_Projection", projection);
  // /m_shader->SetMat4("u_Model", model); // <-- Upload your new model matrix
  // /m_shader->SetFloat("u_X", m_i); // <-- Upload your new model matrix
//----------------------------

        //m_shader->SetMat4("u_Projection", renderer.GetProjection());
        //m_shader->SetMat4("u_Projection", projection);

        //m_vao->Bind();
       // renderer.DrawIndexed(m_vao->GetIndexCount());
        DrawCommand cmd;
        cmd.modelMatrix = model;
        cmd.material = m_Material;
        cmd.mesh     = m_Mesh;

       //cmd.vertexArray = m_vao;
       //cmd.shader = m_shader;
       //cmd.modelMatrix = model;
       //cmd.indexCount = m_vao->GetIndexCount();
       //cmd.customFloat = m_i;


        renderer.Submit(cmd);

    }
}
