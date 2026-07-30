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
    Chunk::Chunk(glm::ivec3 chunkPos,engine::AssetSystem& assets):
        m_ChunkPosition(chunkPos),m_assets(assets)
    {
        m_Blocks.resize(CHUNK_SIZE * CHUNK_SIZE * CHUNK_SIZE, 0);
        //m_Blocks.resize(4096, 0);


       // for (int x = 0; x < CHUNK_SIZE; ++x) {
       //     for (int z = 0; z < CHUNK_SIZE; ++z) {
       //         for (int y = 0; y < 4; ++y) { // 4
       //             int index = x + (y * CHUNK_SIZE) + (z * CHUNK_SIZE * CHUNK_SIZE);
       //             m_Blocks[index] = 1; // Solid block ID 1
       //         }
       //     }
       // }

        for (int x = 0; x < CHUNK_SIZE; ++x) {
            for (int z = 0; z < CHUNK_SIZE; ++z) {
                for (int y = 0; y < CHUNK_SIZE; ++y) { // 4
                    //int index = x*z*y; lot like this due to 0zy || x0y || xz0 are going to return 0 aka the same idea


                    int index =
                          x                            + // 15           = 15
                        ( z * CHUNK_SIZE             ) + // 15 * 16      = 240
                        ( y * CHUNK_SIZE * CHUNK_SIZE) ; // 15 * 16 * 16 = 3840
                                                         //                 ||
                                                         //                4095
                    m_Blocks[index] = 1; // Solid block ID 1
                    /*
                     *
                     *
                     *
                     *
                     *
                     *          \------------------------\
                     *         | \                        \
                     *        |   \                        \
                     *       |     \                        \
                     *      |       \                        \
                     *     |         \                        \
                     *    \           \________________________\
                     *     \          |              \         |
                     *      \        |                \       |
                     *       \      |                  \     |
                     *        \    |                    \   |
                     *         \  |                      \ |
                     *          \|________________________\
                     *
                     *
                     *
                     *          16x16x16 = 4096
                     *
                     *          int index = x
                     *          + (y * CHUNK_SIZE) + (z * CHUNK_SIZE * CHUNK_SIZE);
                     *
                     *          ID =
                     *
                     *
                     */





                }
            }
        }
       // SetBlock(0,0,0, 0);


        // for (int x = 0; x < m_Blocks.size(); ++x)
        // {
        //     std::cout << "ID: " << x << " | Block State : " << m_Blocks[x] << std::endl;
        //     //std::cout << m_Blocks.size() << std::endl;
        //
        // }

    }

    void Chunk::BuildMesh()
    {


        std::vector<float> vertices;
        std::vector<uint32_t> indices;
        uint32_t indexOffset = 0;

       //Iterate through every block in the 16x16x16 grid
       for (int x = 0; x < CHUNK_SIZE; ++x)
       {
           for (int y = 0; y < CHUNK_SIZE; ++y) {
               for (int z = 0; z < CHUNK_SIZE; ++z) {
                     int blockID = m_Blocks[x + y * CHUNK_SIZE + z * CHUNK_SIZE * CHUNK_SIZE];

                        // If it's air (0), skip it
                        if (blockID == 0) continue;

                        // CHECK NEIGHBORS (Basic Face Culling)
                        // If a neighboring block exists, we skip generating that inner face!
                        // (For simplicity in this skeleton, we will generate all 6 faces if exposed,
                        // or check bounds. Here is the concept for checking the top neighbor):

                        float x0 = (float)x;
                        float x1 = (float)(x+1);

                        float y0 = (float)y;
                        float y1 = (float)(y+1);

                        float z0 = (float)z;
                        float z1 = (float)(z+1);

                            // Check if neighbors are air (0 means exposed face)
                            bool top    = (GetBlock(x, y + 1, z) == 0);
                            bool bottom = (GetBlock(x, y - 1, z) == 0);
                            bool left   = (GetBlock(x - 1, y, z) == 0);
                            bool right  = (GetBlock(x + 1, y, z) == 0);
                            bool front  = (GetBlock(x, y, z + 1) == 0);
                            bool back   = (GetBlock(x, y, z - 1) == 0);
                        //bool topAir = (y == CHUNK_SIZE - 1) || (m_Blocks[x + (y + 1) * CHUNK_SIZE + z * CHUNK_SIZE * CHUNK_SIZE] == 0);

                        if (front)
                        {
                            // Format matching your buffer layout: Position(3), Color/Normal(3), UV(2)
                            std::vector<float> faceVerticesFront = {
                                //  X      Y      Z
                                x0,  y0,  z1,       1.0f, 0.0f, 0.0f,     0.0f, 0.0f,
                                x1,  y0,  z1,       1.0f, 0.0f, 0.0f,     1.0f, 0.0f,
                                x1,  y1,  z1,       1.0f, 0.0f, 0.0f,     1.0f, 1.0f,
                                x0,  y1,  z1,       1.0f, 0.0f, 0.0f,     0.0f, 1.0f,

                            };
                            vertices.insert(vertices.end(), faceVerticesFront.begin(), faceVerticesFront.end());
                            // Add indices for this quad
                            indices.push_back(indexOffset + 0);
                            indices.push_back(indexOffset + 1);
                            indices.push_back(indexOffset + 2);
                            indices.push_back(indexOffset + 2);
                            indices.push_back(indexOffset + 3);
                            indices.push_back(indexOffset + 0);
                            indexOffset += 4;
                        }
                        if (left)
                        {
                       std::vector<float> faceVerticesLeft = {
                           //  X      Y      Z
                           x0,  y0,  z0,       0.0f, 1.0f, 0.0f,     0.0f, 0.0f, // x0,  y0,  z1,   0 0 1 /
                           x0,  y0,  z1,       0.0f, 1.0f, 0.0f,     1.0f, 0.0f, // x1,  y0,  z1,   1 0 1 /
                           x0,  y1,  z1,       0.0f, 1.0f, 0.0f,     1.0f, 1.0f, // x1,  y1,  z1,   1 1 1 /
                           x0,  y1,  z0,       0.0f, 1.0f, 0.0f,     0.0f, 1.0f, // x0,  y1,  z1,   0 1 1 /

                       };
                       vertices.insert(vertices.end(), faceVerticesLeft.begin(), faceVerticesLeft.end());
                       // Add indices for this quad
                       indices.push_back(indexOffset + 0);
                       indices.push_back(indexOffset + 1);
                       indices.push_back(indexOffset + 2);
                       indices.push_back(indexOffset + 2);
                       indices.push_back(indexOffset + 3);
                       indices.push_back(indexOffset + 0);
                       indexOffset += 4;
                   }

                       if (back)
                       {
                           std::vector<float> faceVerticesBack = {
                               //  X      Y      Z
                               x1,  y0,  z0,       0.0f, 0.0f, 1.0f,     0.0f, 0.0f,
                               x0,  y0,  z0,       0.0f, 0.0f, 1.0f,     1.0f, 0.0f,
                               x0,  y1,  z0,       0.0f, 0.0f, 1.0f,     1.0f, 1.0f,
                               x1,  y1,  z0,       0.0f, 0.0f, 1.0f,     0.0f, 1.0f,

                           };
                           vertices.insert(vertices.end(), faceVerticesBack.begin(), faceVerticesBack.end());
                           // Add indices for this quad
                           indices.push_back(indexOffset + 0);
                           indices.push_back(indexOffset + 1);
                           indices.push_back(indexOffset + 2);
                           indices.push_back(indexOffset + 2);
                           indices.push_back(indexOffset + 3);
                           indices.push_back(indexOffset + 0);
                           indexOffset += 4;
                       }
                       if (right)
                       {
                               std::vector<float> faceVerticesRight = {
                                   //  X      Y      Z
                                   x1,  y0,  z1,       1.0f, 1.0f, 0.0f,     0.0f, 0.0f, // x0,  y0,  z1,   0 0 1 /
                                   x1,  y0,  z0,       1.0f, 1.0f, 0.0f,     1.0f, 0.0f, // x1,  y0,  z1,   1 0 1 /
                                   x1,  y1,  z0,       1.0f, 1.0f, 0.0f,     1.0f, 1.0f, // x1,  y1,  z1,   1 1 1 /
                                   x1,  y1,  z1,       1.0f, 1.0f, 0.0f,     0.0f, 1.0f, // x0,  y1,  z1,   0 1 1 /

                               };
                               vertices.insert(vertices.end(), faceVerticesRight.begin(), faceVerticesRight.end());
                               // Add indices for this quad
                               indices.push_back(indexOffset + 0);
                               indices.push_back(indexOffset + 1);
                               indices.push_back(indexOffset + 2);
                               indices.push_back(indexOffset + 2);
                               indices.push_back(indexOffset + 3);
                               indices.push_back(indexOffset + 0);
                               indexOffset += 4;
                           }
                       if (top)
                       {
                           std::vector<float> faceVerticesTop = {
                               //  X      Y      Z
                               x0,  y1,  z1,       0.0f, 1.0f, 1.0f,     0.0f, 0.0f,
                               x1,  y1,  z1,       0.0f, 1.0f, 1.0f,     1.0f, 0.0f,
                               x1,  y1,  z0,       0.0f, 1.0f, 1.0f,     1.0f, 1.0f,
                               x0,  y1,  z0,       0.0f, 1.0f, 1.0f,     0.0f, 1.0f,

                            };
                            vertices.insert(vertices.end(), faceVerticesTop.begin(), faceVerticesTop.end());
                            // Add indices for this quad
                            indices.push_back(indexOffset + 0);
                            indices.push_back(indexOffset + 1);
                            indices.push_back(indexOffset + 2);
                            indices.push_back(indexOffset + 2);
                            indices.push_back(indexOffset + 3);
                            indices.push_back(indexOffset + 0);
                            indexOffset += 4;
                      }
                       if (bottom)
                       {
                           std::vector<float> faceVerticesBottom = {
                               //  X      Y      Z
                               x0,  y0,  z0,       1.0f, 1.0f, 1.0f,     0.0f, 0.0f, // x0,  y0,  z1,   0 0 1 /
                               x1,  y0,  z0,       1.0f, 1.0f, 1.0f,     1.0f, 0.0f, // x1,  y0,  z1,   1 0 1 /
                               x1,  y0,  z1,       1.0f, 1.0f, 1.0f,     1.0f, 1.0f, // x1,  y1,  z1,   1 1 1 /
                               x0,  y0,  z1,       1.0f, 1.0f, 1.0f,     0.0f, 1.0f, // x0,  y1,  z1,   0 1 1 /

                           };
                           vertices.insert(vertices.end(), faceVerticesBottom.begin(), faceVerticesBottom.end());
                           // Add indices for this quad
                           indices.push_back(indexOffset + 0);
                           indices.push_back(indexOffset + 1);
                           indices.push_back(indexOffset + 2);
                           indices.push_back(indexOffset + 2);
                           indices.push_back(indexOffset + 3);
                           indices.push_back(indexOffset + 0);
                           indexOffset += 4;
                                   }

                    //}
                    // Repeat checks for bottom, left, right, front, back faces...
              }
          }
      }
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

        // for (int x = 0; x < CHUNK_SIZE; ++x)
        // {
        //     for (int y = 0; y < CHUNK_SIZE; ++y)
        //     {
        //         for (int z = 0; z < CHUNK_SIZE; ++z)
        //         {
        //
        //
        //
        //         }
        //     }
        // }


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


{
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
    }
      //  float faceVertices[] =
      //  {
      //      //x y z
      //      // position               // color              //Texture //TODO IF TEXTURE WOULD BE ROTATED TRY TO DEAL WITH TEXTURE CORDS
      //      0.0f,  0.0f,  1.0f,       1.0f, 0.0f, 0.0f,     0.0f, 0.0f, //0        1.0f, 0.0f, //0 1 1
      //      1.0f,  0.0f,  1.0f,       1.0f, 0.0f, 0.0f,     1.0f, 0.0f, //1        0.0f, 0.0f, //1 0 1
      //      1.0f,  1.0f,  1.0f,       1.0f, 0.0f, 0.0f,     1.0f, 1.0f, //2        0.0f, 1.0f, //2 0 0
      //      0.0f,  1.0f,  1.0f,       1.0f, 0.0f, 0.0f,     0.0f, 1.0f, //3        1.0f, 1.0f, //3 1 0
//
      // };





       //std::vector<float> faceVertices = {
       ////      //x y z
       ////      // position               // color              //Texture //TODO IF TEXTURE WOULD BE ROTATED TRY TO DEAL WITH TEXTURE CORDS
       //         0.0f,  0.0f,  1.0f,       1.0f, 0.0f, 0.0f,     0.0f, 0.0f,
       //         1.0f,  0.0f,  1.0f,       1.0f, 0.0f, 0.0f,     1.0f, 0.0f,
       //         1.0f,  1.0f,  1.0f,       1.0f, 0.0f, 0.0f,     1.0f, 1.0f,
       //         0.0f,  1.0f,  1.0f,       1.0f, 0.0f, 0.0f,     0.0f, 1.0f,
       //};
      //  vertices.insert(vertices.end(), faceVertices.begin(), faceVertices.end());
      //  // Add indices for this quad
      //  indices.push_back(indexOffset + 0);
      //  indices.push_back(indexOffset + 1);
      //  indices.push_back(indexOffset + 2);
      //  indices.push_back(indexOffset + 2);
      //  indices.push_back(indexOffset + 3);
      //  indices.push_back(indexOffset + 0);
      //  indexOffset += 4;

      // uint32_t Indices[] = {
      //     //Face
      //     0,1,2,
      //     2,3,0,
      // };

        m_Shader = m_assets.GetShaderManager().Get(engine::ShaderTypeID::Basic);


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

//
        //m_Mesh = std::make_shared<engine::Mesh>(
        //   faceVertices,
        //   sizeof(faceVertices),
        //   layout,
        //   Indices,
        //   std::size(Indices)
        //);

        m_Mesh = std::make_shared<engine::Mesh>(
           vertices.data(),
         vertices.size() * sizeof(float),
                  layout,
                  indices.data(),
                indices.size()
        );



    }







    void Chunk::Draw(engine::IRenderer& renderer)
    {


        if (!m_Mesh) return;

        engine::DrawCommand cmd;


          float time = (float)glfwGetTime();
        //float time = 1;


        float halfChunkSize = (float)CHUNK_SIZE / 2.0f;
        glm::vec3 centerOffset = glm::vec3(halfChunkSize, halfChunkSize, halfChunkSize);

        // 2. Create an identity matrix, then rotate it
        glm::mat4 model = glm::mat4(1.0f);
        glm::vec3 worldPos = glm::vec3(
            0.0f, -19.0f, 0.0f
        );

        //model = glm::translate(model, glm::vec3(0.5f, 0.0f, 0.5f));
        model = glm::translate(model, worldPos);

        model = glm::translate(model, centerOffset);
        // Rotate over time around a diagonal axis (X and Y) so we see it in 3D
        model = glm::rotate(model, time * 1 * glm::radians(20.0f), glm::vec3(0.0f, 1.0f, 0.0f));

        model = glm::translate(model, -centerOffset);

        cmd.modelMatrix = model;
        cmd.material = m_Material;
        cmd.mesh     = m_Mesh;

        renderer.Submit(cmd);
    }

    void Chunk::SetBlock(int x, int y, int z, uint8_t blockID)
    {

        int index =
              x                            + // 15           = 15
            ( z * CHUNK_SIZE             ) + // 15 * 16      = 240
            ( y * CHUNK_SIZE * CHUNK_SIZE) ; // 15 * 16 * 16 = 3840
        //                 ||
        //                4095
        m_Blocks[index] = blockID; // Solid block ID
        BuildMesh();


    }

    uint16_t Chunk::GetBlock(int x, int y, int z) const
    {
        // If it's within the current chunk bounds, return the block ID
        if (x >= 0 && x < CHUNK_SIZE &&
            y >= 0 && y < CHUNK_SIZE &&
            z >= 0 && z < CHUNK_SIZE) {
            return m_Blocks[x + y * CHUNK_SIZE + z * CHUNK_SIZE * CHUNK_SIZE];
            }
        // TODO: If it's outside the chunk, you would normally query neighboring chunks.
        // For now, returning 0 (air) or 1 (solid) defines how chunk edges behave.
        return 0;
    }
} // opengltests

