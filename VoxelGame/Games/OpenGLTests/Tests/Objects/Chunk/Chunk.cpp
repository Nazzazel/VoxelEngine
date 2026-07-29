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
                   // std::cout << "dddd" << std::endl;
                }
            }
        }


    }

    void Chunk::BuildMesh(engine::AssetSystem& assets)
    {
        std::vector<float> vertices;
        std::vector<uint32_t> indices;
        uint32_t indexOffset = 0;


        {

            //Iterate through every block in the 16x16x16 grid
        // for (int x = 0; x < CHUNK_SIZE; ++x)
        // {
        //     for (int y = 0; y < CHUNK_SIZE; ++y) {
        //         for (int z = 0; z < CHUNK_SIZE; ++z) {
        //             int blockID = m_Blocks[x + y * CHUNK_SIZE + z * CHUNK_SIZE * CHUNK_SIZE];
        //
        //             // If it's air (0), skip it
        //             if (blockID == 0) continue;
        //           //  std::cout << "aaaaa" << std::endl;
        //             // CHECK NEIGHBORS (Basic Face Culling)
        //             // If a neighboring block exists, we skip generating that inner face!
        //             // (For simplicity in this skeleton, we will generate all 6 faces if exposed,
        //             // or check bounds. Here is the concept for checking the top neighbor):
        //
        //             //bool topAir = (y == CHUNK_SIZE - 1) || (m_Blocks[x + (y + 1) * CHUNK_SIZE + z * CHUNK_SIZE * CHUNK_SIZE] == 0);
        //             bool topAir = true;
        //             if (topAir)
        //             {
        //                 // Push vertices for the top face of THIS specific block,
        //                 // offset by its local (x, y, z) position inside the chunk!
        //                 float x0 = (float)x, x1 = (float)(x + 1);
        //                 float y0 = (float)(y + 1); // Top face
        //                 float z0 = (float)z, z1 = (float)(z + 1);
        //
        //                 // Format matching your buffer layout: Position(3), Color/Normal(3), UV(2)
        //                 std::vector<float> faceVertices = {
        //                     x0, y0, z1,  0.0f, 1.0f, 0.0f,  0.0f, 0.0f,
        //                     x1, y0, z1,  0.0f, 1.0f, 0.0f,  1.0f, 0.0f,
        //                     x1, y0, z0,  0.0f, 1.0f, 0.0f,  1.0f, 1.0f,
        //                     x0, y0, z0,  0.0f, 1.0f, 0.0f,  0.0f, 1.0f
        //                 };
        //
        //                 vertices.insert(vertices.end(), faceVertices.begin(), faceVertices.end());
        //
        //                 // Add indices for this quad
        //                 indices.push_back(indexOffset + 0);
        //                 indices.push_back(indexOffset + 1);
        //                 indices.push_back(indexOffset + 2);
        //                 indices.push_back(indexOffset + 2);
        //                 indices.push_back(indexOffset + 3);
        //                 indices.push_back(indexOffset + 0);
        //
        //                 indexOffset += 4;
        //             }
        //             // Repeat checks for bottom, left, right, front, back faces...
        //         }
        //     }
        // }

        }








                // 24 Vertices for a distinct-colored cube
        backends::tests(); //t

        // Setup the buffer layout matching your renderer
        const engine::BufferLayout layout = {
            {engine::ShaderDataType::Float3, "a_Position"},
            {engine::ShaderDataType::Float3, "a_Color"},
            {engine::ShaderDataType::Float2, "a_TexCoord"}
        };

        // Create the mesh object from our dynamically generated vectors
        m_Shader = assets.GetShaderManager().Get(engine::ShaderTypeID::Basic);
        m_Material = std::make_shared<engine::Material>(m_Shader);

        if (!vertices.empty()) {
            m_Mesh = std::make_shared<engine::Mesh>(
                vertices.data(),
                vertices.size() * sizeof(float),
                layout,
                indices.data(),
                indices.size()
            );
        }

        //    m_Mesh = std::make_shared<engine::Mesh>(
        //       cubeVertices,
        //       sizeof(cubeVertices),
        //       layout,
        //       cubeIndices,
        //       std::size(cubeIndices)
        //    );


        //m_shader = assets.GetShaderManager().Get(engine::ShaderTypeID::Basic);


        //m_Material = std::make_shared<engine::Material>(m_shader);

    // m_Material->SetFloat4()


     // backends::tests(); //t
     // const engine::BufferLayout layout =
     //  {
     //  {engine::ShaderDataType::Float3,"a_Position"}
     //  ,{engine::ShaderDataType::Float3,"a_Color"}
     //  ,{engine::ShaderDataType::Float2,"a_TexCoord"}
     //  };
     //
     //    m_Mesh = std::make_shared<engine::Mesh>(
     //       cubeVertices,
     //       sizeof(cubeVertices),
     //       layout,
     //       cubeIndices,
     //       std::size(cubeIndices)
     //    );


       //m_Mesh = std::make_shared<engine::Mesh>(
       //   faceVertices,
       //   sizeof(faceVertices),
       //   layout,
       //   Indices,
       //   std::size(Indices)
       //);



    }

    void Chunk::Draw(engine::IRenderer& renderer)
    {
        if (!m_Mesh) return;

        engine::DrawCommand cmd;


        //  float time = (float)glfwGetTime();
        float time = 1;

        // 2. Create an identity matrix, then rotate it
        glm::mat4 model = glm::mat4(1.0f);
        glm::vec3 worldPos = glm::vec3(
                    m_ChunkPosition.x * CHUNK_SIZE,
                    m_ChunkPosition.y * CHUNK_SIZE,
                    m_ChunkPosition.z * CHUNK_SIZE
                );

        //model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
        model = glm::translate(model, worldPos);

        // Rotate over time around a diagonal axis (X and Y) so we see it in 3D
       // model = glm::rotate(model, time * glm::radians(20.0f), glm::vec3(0.0f, 1.0f, 0.0f));

        cmd.modelMatrix = model;
        cmd.material = m_Material;
        cmd.mesh     = m_Mesh;

        renderer.Submit(cmd);
    }



} // opengltests

