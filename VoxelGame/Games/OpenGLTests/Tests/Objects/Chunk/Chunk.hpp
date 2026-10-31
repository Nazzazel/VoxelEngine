//
// Created by nazzazel on 29.07.2026.
//


#pragma once
#include "SubChunk.hpp"
#include "Core/Systems/Assets/AssetSystem.hpp"
#include "Core/Systems/Renderer/IRenderer/IRenderer.hpp"

#include "Core/Systems/Assets/AssetSystem.hpp"
#include "Core/Systems/Renderer/IRenderer/IRenderer.hpp"
#include "Core/Systems/Assets/AssetSystem.hpp"
#include "Core/Systems/Renderer/IRenderer/IRenderer.hpp"
#include "Engine/Systems/Renderer/Buffers/IVertexArray.hpp"
#include "Engine/Systems/Renderer/Buffers/IVertexBuffer.hpp"
#include "Engine/Systems/Renderer/Buffers/IIndexBuffer.hpp"
#include "Systems/Renderer/Texture/OpenGLTexture.hpp"
#include "VoxelGame/Games/OpenGLTests/Core/Base/VoxelGameHeaders/WorldCoord.hpp"


namespace engine
{
    class OpenGLTexture;
}

namespace opengltests
{
    class Chunk
    {
        public:

        static constexpr int CHUNK_SIZE = 16;
        static constexpr int SUB_CHUNK_STACK_SIZE =1;

       //explicit Chunk(glm::ivec3 chunkPos,engine::AssetSystem& assets,engine::OpenGLTexture& texture);
       explicit Chunk(glm::ivec3 chunkPos,engine::AssetSystem& assets,std::shared_ptr<engine::OpenGLTexture> texture);
        //explicit Chunk(glm::ivec3 chunkPos,engine::AssetSystem& assets);
        ~Chunk() = default;

        void BuildMesh();
        void Draw(engine::IRenderer& renderer,const WorldCoord& cameraPosition);


        // Getters / Setters for world logic or future compute integration
        [[nodiscard]] glm::ivec3 GetPosition() const { return m_ChunkPosition; }

        // Example block modification hook for later (mining/placing)
        void SetBlock(int x, int y, int z, uint8_t blockID);
        [[nodiscard]] uint16_t GetBlock(int x, int y, int z) const;

        private:
        std::array<SubChunk, SUB_CHUNK_STACK_SIZE> BuildFullChunk(glm::ivec3 chunkPos,engine::AssetSystem& assets);


        glm::ivec3 m_ChunkPosition;

        std::shared_ptr<engine::Mesh> m_Mesh;
        std::shared_ptr<engine::Material> m_Material;
       // std::shared_ptr<engine::IShader> m_Shader;

        std::vector<uint16_t> m_Blocks;

        engine::AssetSystem& m_assets;

        //WorldCoord& m_worldPosition;
        //ffff
       // glm::vec3 m_Position = glm::vec3(0.0f);

        engine::IShader* m_Shader = nullptr;
        std::shared_ptr<engine::OpenGLTexture> m_Texture;

        //std::vector<SubChunk> subChunks;
        std::array<SubChunk, SUB_CHUNK_STACK_SIZE> subChunks;


        int chunkX, chunkZ;
    };


} // opengltests
