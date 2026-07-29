//
// Created by nazzazel on 29.07.2026.
//

#include "Chunk.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
//#include <glm/fwd.hpp>

#include "Core/Systems/Assets/AssetSystem.hpp"
#include "OpenGL/tests/tests.hpp"
#include "Systems/Renderer/Renderer/DrawComponents.hpp"



namespace opengltests
{
    Chunk::Chunk(glm::ivec3 chunkPos):
        m_ChunkPosition(chunkPos)
    {
        // Initialize your block data array (0 = air, 1 = solid block, etc.)
        // In a real engine, this would be filled by your compute shader or noise generator.
        m_Blocks.resize(CHUNK_SIZE * CHUNK_SIZE * CHUNK_SIZE, 0);

        // Let's fill it with a simple test pattern (e.g., solid floor at the bottom)
        for (int x = 0; x < CHUNK_SIZE; ++x) {
            for (int z = 0; z < CHUNK_SIZE; ++z) {
                for (int y = 0; y < 4; ++y) {
                    int index = x + (y * CHUNK_SIZE) + (z * CHUNK_SIZE * CHUNK_SIZE);
                    m_Blocks[index] = 1; // Solid block ID 1
                }
            }
        }


    }

    void Chunk::BuildMesh(engine::AssetSystem& assets)
    {
       // std::vector<float> vertices;
       // std::vector<uint32_t> indices;
        uint32_t indexOffset = 0;

       // Iterate through every block in the 16x16x16 grid
       //// for (int x = 0; x < CHUNK_SIZE; ++x)
       // {
       //     for (int y = 0; y < CHUNK_SIZE; ++y) {
       //         for (int z = 0; z < CHUNK_SIZE; ++z) {
       //             int blockID = m_Blocks[x + y * CHUNK_SIZE + z * CHUNK_SIZE * CHUNK_SIZE];

                    //// If it's air (0), skip it
                    //if (blockID == 0) continue;

                    //// CHECK NEIGHBORS (Basic Face Culling)
                    //// If a neighboring block exists, we skip generating that inner face!
                    //// (For simplicity in this skeleton, we will generate all 6 faces if exposed,
                    //// or check bounds. Here is the concept for checking the top neighbor):

                    //bool topAir = (y == CHUNK_SIZE - 1) || (m_Blocks[x + (y + 1) * CHUNK_SIZE + z * CHUNK_SIZE * CHUNK_SIZE] == 0);

                    //if (topAir)
                    //{
                    //    // Push vertices for the top face of THIS specific block,
                    //    // offset by its local (x, y, z) position inside the chunk!
                    //    float x0 = (float)x, x1 = (float)(x + 1);
                    //    float y0 = (float)(y + 1); // Top face
                    //    float z0 = (float)z, z1 = (float)(z + 1);

                        //// Format matching your buffer layout: Position(3), Color/Normal(3), UV(2)
                        //std::vector<float> faceVertices = {
                        //    x0, y0, z1,  0.0f, 1.0f, 0.0f,  0.0f, 0.0f,
                        //    x1, y0, z1,  0.0f, 1.0f, 0.0f,  1.0f, 0.0f,
                        //    x1, y0, z0,  0.0f, 1.0f, 0.0f,  1.0f, 1.0f,
                        //    x0, y0, z0,  0.0f, 1.0f, 0.0f,  0.0f, 1.0f
                        //};

                        //vertices.insert(vertices.end(), faceVertices.begin(), faceVertices.end());

                        //// Add indices for this quad
                        //indices.push_back(indexOffset + 0);
                        //indices.push_back(indexOffset + 1);
                        //indices.push_back(indexOffset + 2);
                        //indices.push_back(indexOffset + 2);
                        //indices.push_back(indexOffset + 3);
                        //indices.push_back(indexOffset + 0);

        //                indexOffset += 4;
        //            }
        //            // Repeat checks for bottom, left, right, front, back faces...
        //        }
        //    }
        //}
                // 24 Vertices for a distinct-colored cube

      // float Vertices[] =
      // {
      //     // Vertex position    //Color                 //Texture Cords
      //     0.0f, 0.0f, 0.0f,     0.0f, 0.0f, 0.0f,       0.0f, 0.0f,
      //     0.0f, 0.0f, 0.0f,     0.0f, 0.0f, 0.0f,       1.0f, 0.0f,
      //     0.0f, 0.0f, 0.0f,     0.0f, 0.0f, 0.0f,       1.0f, 1.0f,
      //     0.0f, 0.0f, 0.0f,     0.0f, 0.0f, 0.0f,       0.0f, 0.0f
      // };

        //float Vertices[];

       //for (int x = 0; x < CHUNK_SIZE; ++x)
       //{
       //    for (int y = 0; y < CHUNK_SIZE; ++y)
       //    {
       //        for (int z = 0; z < CHUNK_SIZE; ++z)
       //        {
       //            std::vector<float> faceVertices = {
       //                     0, 0, 0,  0.0f, 1.0f, 0.0f,  0.0f, 0.0f,
       //                     0, 1, 0,      0.0f, 1.0f, 0.0f,  1.0f, 0.0f,
       //                     1, 1, 0,      0.0f, 1.0f, 0.0f,  1.0f, 1.0f,
       //                     0, 1, 0,      0.0f, 1.0f, 0.0f,  0.0f, 1.0f
       //            };
       //            vertices.insert(vertices.end(), faceVertices.begin(), faceVertices.end());
       //        }
       //    }
       //}


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



       //float faceVertices[] =
       //{
       /// std::vector<float> faceVertices = {
       //         0, 0, 0,      0.0f, 1.0f, 0.0f,  0.0f, 0.0f,
       //         0, 1, 0,      0.0f, 1.0f, 0.0f,  1.0f, 0.0f,
       //         1, 1, 0,      0.0f, 1.0f, 0.0f,  1.0f, 1.0f,
       //         0, 0, 0,      0.0f, 1.0f, 0.0f,  0.0f, 1.0f
       //};


     //float faceVertices[] =
     //{
     //    // std::vector<float> faceVertices = {
     //    0.0f, 0.0f, 0.0f,      1.0f, 0.0f, 0.0f,     0.0f, 0.0f,
     //    0.0f, 1.0f, 0.0f,      0.0f, 1.0f, 0.0f,     1.0f, 0.0f,
     //    1.0f, 1.0f, 0.0f,      0.0f, 1.0f, 1.0f,     1.0f, 1.0f
     //};


       //float faceVertices[] =
       //{
       //    // position (pixels)   // color
       //    0.5f, -0.5f,  0.5f,       1.0f, 0.0f, 0.0f ,1.0f, 1.0f,
       //     0.5f, -0.5f,  0.5f,       1.0f, 0.0f, 0.0f ,1.0f, 0.0f,
       //     0.5f,  0.5f,  0.5f,       1.0f, 0.0f, 0.0f ,0.0f, 0.0f,
       //    -0.5f,  0.5f,  0.5f,       1.0f, 0.0f, 0.0f ,0.0f, 1.0f
       //   };

     // float faceVertices[] =
     // {
     //     //x y z
     //     // position (pixels)   // color
     //      0.0f,  0.0f,  0.0f,       1.0f, 0.0f, 0.0f,
     //      1.0f,  0.0f,  0.0f,       1.0f, 0.0f, 0.0f,
     //      1.0f,  1.0f,  0.0f,       1.0f, 0.0f, 0.0f,
     //      0.0f,  1.0f,  0.0f,       1.0f, 0.0f, 0.0f
     // };


       //  float faceVertices[] =
       //  {
       //
       //      //Front
       //      //x y z
       //      // position               // color              //Texture //TODO IF TEXTURE WOULD BE ROTATED TRY TO DEAL WITH TEXTURE CORDS
       //      0.0f,  0.0f,  1.0f,       1.0f, 0.0f, 0.0f,     0.0f, 0.0f, //0
       //      1.0f,  0.0f,  1.0f,       1.0f, 0.0f, 0.0f,     1.0f, 0.0f, //1
       //      1.0f,  1.0f,  1.0f,       1.0f, 0.0f, 0.0f,     1.0f, 1.0f, //2
       //      0.0f,  1.0f,  1.0f,       1.0f, 0.0f, 0.0f,     0.0f, 1.0f, //3
       //
       //      //<- left from the front x y z
       //      0.0f,  1.0f,  0.0f,       0.0f, 1.0f, 0.0f,     1.0f, 1.0f, //4
       //      0.0f,  0.0f,  0.0f,       0.0f, 1.0f, 0.0f,     1.0f, 0.0f, //5
       //
       //
       //      1.0f,  1.0f,  0.0f,       0.0f, 1.0f, 0.0f,     0.0f, 0.0f, //6
       //      0.0f,  1.0f,  1.0f,       0.0f, 1.0f, 0.0f,     0.0f, 1.0f  //7
       //
       // };
        //            0.0f,  0.0f,  1.0f,       1.0f, 0.0f, 0.0f,     0.0f, 0.0f, //0        1.0f, 0.0f, //0
        //            1.0f,  0.0f,  1.0f,       1.0f, 0.0f, 0.0f,     1.0f, 0.0f, //1        0.0f, 0.0f, //1
        //            1.0f,  1.0f,  1.0f,       1.0f, 0.0f, 0.0f,     1.0f, 1.0f, //2        0.0f, 1.0f, //2
        //            0.0f,  1.0f,  1.0f,       1.0f, 0.0f, 0.0f,     0.0f, 1.0f, //3        1.0f, 1.0f, //3

        float faceVertices[] =
        {

            //Front
            //x y z
            // position               // color              //Texture //TODO IF TEXTURE WOULD BE ROTATED TRY TO DEAL WITH TEXTURE CORDS
            0.0f,  0.0f,  1.0f,       1.0f, 0.0f, 0.0f,     0.0f, 0.0f, //0        1.0f, 0.0f, //0 1 1
            1.0f,  0.0f,  1.0f,       1.0f, 0.0f, 0.0f,     1.0f, 0.0f, //1        0.0f, 0.0f, //1 0 1
            1.0f,  1.0f,  1.0f,       1.0f, 0.0f, 0.0f,     1.0f, 1.0f, //2        0.0f, 1.0f, //2 0 0
            0.0f,  1.0f,  1.0f,       1.0f, 0.0f, 0.0f,     0.0f, 1.0f, //3        1.0f, 1.0f, //3 1 0

            //<- left from the front x y z
            0.0f,  1.0f,  0.0f,       0.0f, 1.0f, 0.0f,     1.0f, 0.0f, //4 0 0 -> 1 1 now work? why idk
            0.0f,  0.0f,  0.0f,       0.0f, 1.0f, 0.0f,     1.0f, 1.0f, //5

            //
            1.0f,  0.0f,  0.0f,       0.0f, 1.0f, 0.0f,     0.0f, 1.0f, //6
            1.0f,  1.0f,  0.0f,       0.0f, 1.0f, 0.0f,     0.0f, 0.0f  //7

       };
       //uint32_t Indices[] = {
       //    0,1,2 ,2,3,0,
       //    3,4,5 ,3,0,5
       //    3,4,5 ,5,0,3
       //};
        uint32_t Indices[] = {
            //Front
            0,1,2,
            2,3,0,
            //Left
            0,3,5,
            3,4,5,
            //Back
            5,4,6,
            4,7,6,

            //Right
            6,7,1,
            7,2,1,

            //Top




            //
            //
            //
            //7,3,2,//2,7,3//3,2,7
            //3,2,4,
            //4,3,2

            3,2,7,
            //2,7,4,
            7,4,3
            //4,3,2





            //Bottom


        };
        //0,3,5 ,3,4,5
        //0,5,3 oppsite


        //x y z
        //
        //0,1,0 --- 1,1,0
        //|            |
        //|            |
        //0,0,0 --- 0,1,0
        //
        //

        m_Shader = assets.GetShaderManager().Get(engine::ShaderTypeID::Basic);


        m_Material = std::make_shared<engine::Material>(m_Shader);

    // m_Material->SetFloat4()


     backends::tests(); //t
     const engine::BufferLayout layout =
      {
       {engine::ShaderDataType::Float3,"a_Position"}
      ,{engine::ShaderDataType::Float3,"a_Color"}
      ,{engine::ShaderDataType::Float2,"a_TexCoord"}
      };

        //m_Mesh = std::make_shared<engine::Mesh>(
        //   cubeVertices,
        //   sizeof(cubeVertices),
        //   layout,
        //   cubeIndices,
        //   std::size(cubeIndices)
        //);


        m_Mesh = std::make_shared<engine::Mesh>(
           faceVertices,
           sizeof(faceVertices),
           layout,
           Indices,
           std::size(Indices)
        );



    }

    void Chunk::Draw(engine::IRenderer& renderer)
    {
        if (!m_Mesh) return;

        engine::DrawCommand cmd;


          //float time = (float)glfwGetTime();
        float time = 1;

        // 2. Create an identity matrix, then rotate it
        glm::mat4 model = glm::mat4(1.0f);
        glm::vec3 worldPos = glm::vec3(
            0.0f, -2.0f, 0.0f


        );

        //model = glm::translate(model, glm::vec3(0.5f, 0.0f, 0.5f));
        model = glm::translate(model, worldPos);

        // Rotate over time around a diagonal axis (X and Y) so we see it in 3D
        model = glm::rotate(model, time * 1 * glm::radians(20.0f), glm::vec3(0.0f, 1.0f, 0.0f));

        cmd.modelMatrix = model;
        cmd.material = m_Material;
        cmd.mesh     = m_Mesh;

        renderer.Submit(cmd);
    }



} // opengltests

