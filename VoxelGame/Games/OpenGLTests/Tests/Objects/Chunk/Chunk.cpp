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
    Chunk::Chunk(glm::ivec3 chunkPos,engine::AssetSystem& assets,std::shared_ptr<engine::OpenGLTexture> texture) :
   // Chunk::Chunk(glm::ivec3 chunkPos,engine::AssetSystem& assets) :
        m_ChunkPosition(chunkPos * 16),
        m_assets(assets),
        subChunks(Chunk::BuildFullChunk(chunkPos,assets)),
        m_Texture(texture)
    {


       // subChunks.begin();

      // subChunks.reserve(24);
      // for (int i = 0; i < 24; ++i)
      // {
      //     // Pass local sub-chunk position (e.g., stacking them along the Y axis)
      //     glm::ivec3 subChunkPos = glm::ivec3(chunkPos.x, i, chunkPos.z);
      //     subChunks.emplace_back(subChunkPos, m_assets);
      // }


       // m_Blocks.resize(CHUNK_SIZE * CHUNK_SIZE * CHUNK_SIZE, 1);
        //m_Blocks.resize(4096, 0);

        // for (int x = 0; x < CHUNK_SIZE; ++x) {
        //     for (int z = 0; z < CHUNK_SIZE; ++z) {
        //         for (int y = 0; y < 4; ++y) { // 4
        //             int index = x + (y * CHUNK_SIZE) + (z * CHUNK_SIZE * CHUNK_SIZE);
        //             m_Blocks[index] = 1; // Solid block ID 1
        //         }
        //     }
        // }

        // for (int x = 0; x < CHUNK_SIZE; ++x) {
        //     for (int z = 0; z < CHUNK_SIZE; ++z) {
        //         for (int y = 0; y < CHUNK_SIZE; ++y) { // 4
        //             //int index = x*z*y; lot like this due to 0zy || x0y || xz0 are going to return 0 aka the same idea


        //             int index =
        //                   x                            + // 15           = 15
        //                 ( z * CHUNK_SIZE             ) + // 15 * 16      = 240
        //                 ( y * CHUNK_SIZE * CHUNK_SIZE) ; // 15 * 16 * 16 = 3840
        //                                                  //                 ||
        //                                                  //                4095
        //             m_Blocks[index] = 1; // Solid block ID 1
        //             /*
        //              *
        //              *
        //              *
        //              *
        //              *
        //              *          \------------------------\
        //              *         | \                        \
        //              *        |   \                        \
        //              *       |     \                        \
        //              *      |       \                        \
        //              *     |         \                        \
        //              *    \           \________________________\
        //              *     \          |              \         |
        //              *      \        |                \       |
        //              *       \      |                  \     |
        //              *        \    |                    \   |
        //              *         \  |                      \ |
        //              *          \|________________________\
        //              *
        //              *
        //              *
        //              *          16x16x16 = 4096
        //              *
        //              *          int index = x
        //              *          + (y * CHUNK_SIZE) + (z * CHUNK_SIZE * CHUNK_SIZE);
        //              *
        //              *          ID =
        //              *
        //              *
        //              */


        //         }
        //     }
        // }
        // SetBlock(0,0,0, 0);


        // for (int x = 0; x < m_Blocks.size(); ++x)
        // {
        //     std::cout << "ID: " << x << " | Block State : " << m_Blocks[x] << std::endl;
        //     //std::cout << m_Blocks.size() << std::endl;
        //
        // }

        auto time = assets.GetSystemManager()->GetSystem<engine::TimeSystem>();
     //   std::cout <<        time->CurrentTime() << "\n";
        //std::cout <<        time->GetDeltaTime() << "\n";

        BuildMesh();
    }

    void Chunk::BuildMesh()
    {


        std::vector<float> vertices;
        std::vector<uint32_t> indices;
        uint32_t indexOffset = 0;


        uint32_t totalHeight = SUB_CHUNK_STACK_SIZE * CHUNK_SIZE;// x *  16 = all y blocks


        size_t estimatedBlocks = CHUNK_SIZE * totalHeight * CHUNK_SIZE;
        vertices.reserve(estimatedBlocks * 3);
        indices.reserve(estimatedBlocks * 3);


        auto appendFaces = [&]
        (
                float x0, float y0, float z0,
                float x1, float y1, float z1,
                float x2, float y2, float z2,
                float x3, float y3, float z3,

                float red, float green, float blue,

                //float x0, float y0, float z0,
                //float x1, float y1, float z1,
                //float cr, float cg, float cb, // Color Value color red,green,blue
                bool invertUV = false
        )
        {
                float faceData[32] =
                {
               //X   Y   Z
                x0, y0, z0,   red, green, blue,   0.0f, 0.0f,
                x1, y1, z1,   red, green, blue,   1.0f, 0.0f,
                x2, y2, z2,   red, green, blue,   1.0f, 1.0f,
                x3, y3, z3,   red, green, blue,   0.0f, 1.0f

                };
            vertices.insert(vertices.end(), std::begin(faceData), std::end(faceData));

            uint32_t quadIndices[6] =
            {

                indexOffset + 0, indexOffset + 1, indexOffset + 2,    // 0---1
                indexOffset + 2, indexOffset + 3, indexOffset + 0     // | \ |
                                                                      // 3__\2
            };
            indices.insert(indices.end(), std::begin(quadIndices), std::end(quadIndices));
            indexOffset += 4;


        };





        //Iterate through every block in the 16x16x16 grid
        for (int subChunkIndex = 0; subChunkIndex < SUB_CHUNK_STACK_SIZE; ++subChunkIndex)
        {
            if (subChunks[subChunkIndex].GetSubChunkState()==0) //EMPTY
            {
                //std::cout << "Empty \n";
                continue;
            }
            if (subChunks[subChunkIndex].GetSubChunkState()==1) //SOLID
            {
                //
                // for (int localY = 0; localY < CHUNK_SIZE; ++localY)
                // {

                    // 1. TOP FACE (y = 15 layer, looking up at absoluteY + 1)
                    for (int z = 0; z < 16; ++z) {
                        for (int x = 0; x < 16; ++x) {

                            int absoluteY = (subChunkIndex * CHUNK_SIZE) + CHUNK_SIZE-1;
                           // int absoluteY = 15; // Top layer of the sub-chunk
                            //int absoluteY = CHUNK_SIZE-1; // Top layer of the sub-chunk

                            float fx0 = (float)x;
                            float fx1 = (float)(x+1);

                            float fy0 = (float)absoluteY;
                            float fy1 = (float)(absoluteY+1);

                            float fz0 = (float)z;
                            float fz1 = (float)(z+1);


                            if (GetBlock(x, absoluteY + 1, z) == 0) { // Check if neighbor above is air
                                // Compute voxel positions (fx0, fy1, fz0, etc.)
                                appendFaces(fx0, fy1, fz1, fx1, fy1, fz1, fx1, fy1, fz0, fx0, fy1, fz0, 1.0f, 0.0f, 0.0f, false);
                            }
                        }
                    }

                    // 2. BOTTOM FACE (y = 0 layer, looking down at absoluteY - 1)
                    for (int z = 0; z < 16; ++z) {
                        for (int x = 0; x < 16; ++x) {
                            int absoluteY = (subChunkIndex * CHUNK_SIZE) +0;
                            // int absoluteY = 15; // Top layer of the sub-chunk
                            //int absoluteY = CHUNK_SIZE-1; // Top layer of the sub-chunk

                            float fx0 = (float)x;
                            float fx1 = (float)(x+1);

                            float fy0 = (float)absoluteY;
                            float fy1 = (float)(absoluteY+1);

                            float fz0 = (float)z;
                            float fz1 = (float)(z+1);
                            if (GetBlock(x, absoluteY - 1, z) == 0) {
                                appendFaces(fx0, fy0, fz0, fx1, fy0, fz0, fx1, fy0, fz1, fx0, fy0, fz1, 0.0f, 1.0f, 0.0f, false);
                            }
                        }
                    }

                    // 3. FRONT FACE (z = 15 layer)
                    for (int y = 0; y < 16; ++y) {
                        for (int x = 0; x < 16; ++x) {


                            //                           appendFaces(
                           //fx0,    fy0,    fz1,
                           //fx1,    fy0,    fz1,
                           //fx1,    fy1,    fz1,
                           //fx0,    fy1,    fz1,
                           //1.0f, 0.0f, 0.0f,
                           //false
                           //);
                            ////
                        int absoluteY = y + (subChunkIndex * CHUNK_SIZE);//todo add offset

                          float fx0 = (float)x;
                          float fx1 = (float)(x+1);

                          float fy0 = (float)absoluteY;
                          float fy1 = (float)(absoluteY+1);

                          //float fz0 = (float)CHUNK_SIZE-1;
                          float fz1 = (float)(CHUNK_SIZE);

                            if (GetBlock(x, absoluteY, CHUNK_SIZE) == 0) { // Checking neighbor in front (+z)
                                appendFaces(fx0, fy0, fz1, fx1, fy0, fz1, fx1, fy1, fz1, fx0, fy1, fz1, 0.0f, 0.0f, 1.0f, false);
                            }
                        }
                    }

                    // 4. BACK FACE (z = 0 layer)
                    for (int y = 0; y < 16; ++y) {
                        for (int x = 0; x < 16; ++x) {
                            //int absoluteY = y;

                            int absoluteY = y + (subChunkIndex * CHUNK_SIZE);//todo add offset

                            float fx0 = (float)x;
                            float fx1 = (float)(x+1);

                            float fy0 = (float)absoluteY;
                            float fy1 = (float)(absoluteY+1);

                            float fz0 = (float)0;
                            //float fz1 = (float)(CHUNK_SIZE);

                            if (GetBlock(x, absoluteY, -1) == 0) { // Checking neighbor behind (-z)
                                appendFaces(fx1, fy0, fz0, fx0, fy0, fz0, fx0, fy1, fz0, fx1, fy1, fz0, 1.0f, 1.0f, 0.0f, false);
                            }
                        }
                    }
               // if (left)
               // {
               //     appendFaces(
               //         fx0,    fy0,    fz0,
               //         fx0,    fy0,    fz1,
               //         fx0,    fy1,    fz1,
               //         fx0,    fy1,    fz0,
               //         0.0f, 1.0f, 0.0f,
               //         false);
               //     //appendFaces(fx0,fy0,fz0,   1,1,1,  1,1,1,  1,1,1, 1,1,1);
               // }
                    // 5. LEFT FACE (x = 0 layer)
                    for (int y = 0; y < 16; ++y) {
                        for (int z = 0; z < 16; ++z) {
                           // int absoluteY = y;


                            int absoluteY = y + (subChunkIndex * CHUNK_SIZE);//todo add offset

                            float fx0 = (float)0;//CHange
                            float fx1 = (float)1;

                            float fy0 = (float)absoluteY;
                            float fy1 = (float)(absoluteY+1);

                            float fz0 = (float)z;
                            float fz1 = (float)(z+1);
                            if (GetBlock(-1, absoluteY, z) == 0) { // Checking neighbor to the left (-x)
                                appendFaces(
                                    fx0, fy0, fz0,
                                    fx0, fy0, fz1,
                                    fx0, fy1, fz1,
                                    fx0, fy1, fz0,
                                    0.0f, 1.0f, 1.0f, false);
                            }
                        }
                    }

                    // 6. RIGHT FACE (x = 15 layer)
                    for (int y = 0; y < 16; ++y) {
                        for (int z = 0; z < 16; ++z) {
                            int absoluteY = y + (subChunkIndex * CHUNK_SIZE);//todo add offset

                          //  float fx0 = (float)CHUNK_SIZE-1;
                            float fx1 = (float)CHUNK_SIZE;

                            float fy0 = (float)absoluteY;
                            float fy1 = (float)(absoluteY+1);

                            float fz0 = (float)z;
                            float fz1 = (float)(z+1);

                            if (GetBlock(16, absoluteY, z) == 0) { // Checking neighbor to the right (+x)
                                 appendFaces(
                                     fx1, fy0, fz1,
                                     fx1, fy0, fz0,
                                     fx1, fy1, fz0,
                                     fx1, fy1, fz1,
                                     1.0f, 1.0f, 1.0f, false);
                            }
                        }
                    }
                //}

                {




                }
                 continue;
             }


            //if(subChunks[subChunkIndex].isEmpty){continue;}

            for (int localY = 0; localY < CHUNK_SIZE; ++localY)
            {





                for (int x = 0; x < CHUNK_SIZE; ++x)
                {
                    for (int z = 0; z < CHUNK_SIZE; ++z)
                    {
                        // int blockID = m_Blocks[x + y * CHUNK_SIZE + z * CHUNK_SIZE * CHUNK_SIZE];
                        //int blockID = GetBlock(x, y, z);

                        int absoluteY = (subChunkIndex * CHUNK_SIZE) + localY;
                        int blockID = subChunks[subChunkIndex].GetBlock(x, localY, z);

                        // If it's air (0), skip it
                        if (blockID == 0) continue;

                        // CHECK NEIGHBORS (Basic Face Culling)
                        // If a neighboring block exists, we skip generating that inner face!
                        // (For simplicity in this skeleton, we will generate all 6 faces if exposed,
                        // or check bounds. Here is the concept for checking the top neighbor):

                        //float xO = (float)x;

                        float fx0 = (float)x;
                        float fx1 = (float)(x+1);

                        float fy0 = (float)absoluteY;
                        float fy1 = (float)(absoluteY+1);

                        float fz0 = (float)z;
                        float fz1 = (float)(z+1);


                        // Check if neighbors are air (0 means exposed face)
                        bool top    = (GetBlock(x, absoluteY + 1, z) == 0);
                        bool bottom = (GetBlock(x, absoluteY - 1, z) == 0);
                        bool left   = (GetBlock(x - 1, absoluteY, z) == 0);
                        bool right  = (GetBlock(x + 1, absoluteY, z) == 0);
                        bool front  = (GetBlock(x, absoluteY, z + 1) == 0);
                        bool back   = (GetBlock(x, absoluteY, z - 1) == 0);


                        //bool top    =true;
                        //bool bottom =true;
                        //bool left   =true;
                        //bool right  =true;
                        //bool front  =true;
                        //bool back   =true;

                       //int pass =1;
                       //if (pass==1){


                            //bool topAir = (y == CHUNK_SIZE - 1) || (m_Blocks[x + (y + 1) * CHUNK_SIZE + z * CHUNK_SIZE * CHUNK_SIZE] == 0);
                       if (front)
                       {
                           appendFaces(
                            fx0,    fy0,    fz1,
                            fx1,    fy0,    fz1,
                            fx1,    fy1,    fz1,
                            fx0,    fy1,    fz1,
                            1.0f, 0.0f, 0.0f,
                            false
                            );
                       }

                       if (left)
                       {
                           appendFaces(
                               fx0,    fy0,    fz0,
                               fx0,    fy0,    fz1,
                               fx0,    fy1,    fz1,
                               fx0,    fy1,    fz0,
                               0.0f, 1.0f, 0.0f,
                               false);
                           //appendFaces(fx0,fy0,fz0,   1,1,1,  1,1,1,  1,1,1, 1,1,1);
                       }

                       if (back)
                       {
                           appendFaces(
                               fx1,    fy0,    fz0,
                               fx0,    fy0,    fz0,
                               fx0,    fy1,    fz0,
                               fx1,    fy1,    fz0,
                               0.0f, 0.0f, 1.0f,
                               false);
                           //appendFaces(fx0,fy0,fz0,   1,1,1,  1,1,1,  1,1,1, 1,1,1);
                       }

                       if (right)
                       {
                           appendFaces(
                               fx1,    fy0,    fz1,
                               fx1,    fy0,    fz0,
                               fx1,    fy1,    fz0,
                               fx1,    fy1,    fz1,
                               0.0f, 0.0f, 1.0f,
                               false);
                           //appendFaces(fx0,fy0,fz0,   1,1,1,  1,1,1,  1,1,1, 1,1,1);
                       }

                       if (top)
                       {
                           appendFaces(
                               fx0,    fy1,    fz1,
                               fx1,    fy1,    fz1,
                               fx1,    fy1,    fz0,
                               fx0,    fy1,    fz0,
                               0.0f, 1.0f, 1.0f,
                               false);
                           //appendFaces(fx0,fy0,fz0,   1,1,1,  1,1,1,  1,1,1, 1,1,1);
                       }

                       if (bottom)
                       {
                           appendFaces(
                               fx0,    fy0,    fz0,
                               fx1,    fy0,    fz0,
                               fx1,    fy0,    fz1,
                               fx0,    fy0,    fz1,
                               0.0f, 0.0f, 1.0f,
                               false);
                           //appendFaces(fx0,fy0,fz0,   1,1,1,  1,1,1,  1,1,1, 1,1,1);
                       }

                  }
              }
            }

        }

        {
        }
        m_Shader = m_assets.GetShaderManager().Get(engine::ShaderTypeID::Basic);
        //m_Shader = m_assets.GetShaderManager().Get(engine::ShaderTypeID::UI);

        m_Material = std::make_unique<engine::Material>(m_Shader,m_Texture);

        const engine::BufferLayout layout =
         {
          {engine::ShaderDataType::Float3,"a_Position"}
         ,{engine::ShaderDataType::Float3,"a_Color"}
         ,{engine::ShaderDataType::Float2,"a_TexCoord"}

         };


        m_Mesh = std::make_shared<engine::Mesh>(
           vertices.data(),
         vertices.size() * sizeof(float),
                  layout,
                  indices.data(),
                indices.size()
        );
    }







    void Chunk::Draw(engine::IRenderer& renderer, const WorldCoord& cameraPosition)
    {
        if (!m_Mesh) return;

        engine::DrawCommand cmd;




         // float time = (float)glfwGetTime();
        float time = 1;


        //float halfChunkSize = (float)CHUNK_SIZE / 2.0f;
        //glm::vec3 centerOffset = glm::vec3(halfChunkSize, halfChunkSize, halfChunkSize);

        // 2. Create an identity matrix, then rotate it

        //glm::ivec3 worldPos = glm::ivec3(
        //    0.0, -19.0, 0.0
        //);
        // Convert chunk absolute world grid to relative local coordinates for the shader
        //glm::vec3 relativeChunkPos = glm::vec3(m_worldPosition.chunkCoord - cameraChunkAnchor) * 16.0f; // assuming 16 blocks wide chunks


        //glm::ivec3 relativePos = m_ChunkPosition - cameraPosition.chunkCoord; //- cameraPosition;

        //model = glm::translate(model, glm::vec3(0.5f, 0.0f, 0.5f));



        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(m_ChunkPosition));




        //model = glm::translate(model, centerOffset);
        // Rotate over time around a diagonal axis (X and Y) so we see it in 3D
       // model = glm::rotate(model, time * 1 * glm::radians(20.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        //model = glm::rotate(model, glm::radians(20.0f), glm::vec3(0.0f, 1.0f, 0.0f));

       // model = glm::translate(model, -centerOffset)

        //
        //
        //
        //
        //// Inside your main render loop or scene manager
        //glm::ivec3 cameraAnchor = playerCamera.GetWorldCoord().chunkCoord;
//
        //for (auto& chunk : loadedChunks)
        //{
        //    // Convert chunk's absolute world ivec3 to a relative vec3 using the camera anchor
        //    glm::vec3 relativeChunkPos = glm::vec3(chunk.worldCoord - cameraAnchor);
//
        //    glm::mat4 model = glm::mat4(1.0f);
        //    model = glm::translate(model, relativeChunkPos);
//
        //    // Send 'model' matrix to shader...
        //}
        //
        //
        //
        //
        //

        cmd.modelMatrix = model;
        cmd.material = m_Material;
       // cmd.material = std::move(m_Material);
        cmd.mesh     = m_Mesh;
       // cmd.mesh     = std::move(m_Mesh);

        renderer.Submit(cmd);
    }

    void Chunk::SetBlock(int x, int y, int z, uint8_t blockID)
    {

        //int index =
        //      x                            + // 15           = 15
        //    ( z * CHUNK_SIZE             ) + // 15 * 16      = 240
        //    ( y * CHUNK_SIZE * CHUNK_SIZE) ; // 15 * 16 * 16 = 3840
        ////                 ||
        ////                4095
        //m_Blocks[index] = blockID; // Solid block ID
        //BuildMesh();

        int subChunkIndex = y / CHUNK_SIZE;
        int localY = y % CHUNK_SIZE;

        if (subChunkIndex >= 0 && subChunkIndex < SUB_CHUNK_STACK_SIZE)
        {
            subChunks[subChunkIndex].SetBlock(x, localY, z, blockID);
            BuildMesh();
        }
    }

    uint16_t Chunk::GetBlock(int x, int y, int z) const
    {
        //// If it's within the current chunk bounds, return the block ID
        //if (x >= 0 && x < CHUNK_SIZE &&
        //    y >= 0 && y < CHUNK_SIZE &&
        //    z >= 0 && z < CHUNK_SIZE) {
        //    return m_Blocks[x + y * CHUNK_SIZE + z * CHUNK_SIZE * CHUNK_SIZE];
        //    }
        //// TODO: If it's outside the chunk, you would normally query neighboring chunks.
        //// For now, returning 0 (air) or 1 (solid) defines how chunk edges behave.
        //return 0;

        // Handle local horizontal bounds check, vertical spans across sub-chunks
        int subChunkIndex = y / CHUNK_SIZE;
        int localY = y % CHUNK_SIZE;

        if (x >= 0 && x < CHUNK_SIZE &&
            subChunkIndex >= 0 && subChunkIndex < SUB_CHUNK_STACK_SIZE &&
            z >= 0 && z < CHUNK_SIZE)
        {
            return subChunks[subChunkIndex].GetBlock(x, localY, z);
        }
        return 0; // Out of bounds / Air


    }

    std::array<SubChunk, Chunk::SUB_CHUNK_STACK_SIZE> Chunk::BuildFullChunk(glm::ivec3 chunkPos, engine::AssetSystem& assets)
    {
        std::array<SubChunk, SUB_CHUNK_STACK_SIZE> temporaryChunks;//SUB_CHUNK_STACK_SIZE =24 layers of sub chunks

        if (chunkPos.x == 1 && chunkPos.z == 1){return temporaryChunks;}
        for (uint8_t i = 0; i < SUB_CHUNK_STACK_SIZE; i++)
        {
            chunkPos.y = i;
            temporaryChunks[i] = SubChunk(CHUNK_SIZE,chunkPos, assets);
        }
        return temporaryChunks;
    }


} // opengltests

