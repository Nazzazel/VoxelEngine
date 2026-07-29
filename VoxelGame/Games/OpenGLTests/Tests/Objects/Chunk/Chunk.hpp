//
// Created by nazzazel on 29.07.2026.
//


#pragma once
#include "Core/Systems/Assets/AssetSystem.hpp"
#include "Core/Systems/Renderer/IRenderer/IRenderer.hpp"

#include "Core/Systems/Assets/AssetSystem.hpp"
#include "Core/Systems/Renderer/IRenderer/IRenderer.hpp"
#include "Core/Systems/Assets/AssetSystem.hpp"
#include "Core/Systems/Renderer/IRenderer/IRenderer.hpp"
#include "Engine/Systems/Renderer/Buffers/IVertexArray.hpp"
#include "Engine/Systems/Renderer/Buffers/IVertexBuffer.hpp"
#include "Engine/Systems/Renderer/Buffers/IIndexBuffer.hpp"


namespace opengltests
{
    class Chunk
    {
        public:

        static constexpr int CHUNK_SIZE = 16;

        explicit Chunk(glm::ivec3 chunkPos);
        ~Chunk() = default;

        void BuildMesh(engine::AssetSystem& assets);
        void Draw(engine::IRenderer& renderer);


        // Getters / Setters for world logic or future compute integration
        [[nodiscard]] glm::ivec3 GetPosition() const { return m_ChunkPosition; }

        // Example block modification hook for later (mining/placing)
        void SetBlock(int x, int y, int z, uint8_t blockID);
        [[nodiscard]] uint8_t GetBlock(int x, int y, int z) const;

        private:
        glm::ivec3 m_ChunkPosition;

        std::shared_ptr<engine::Mesh> m_Mesh;
        std::shared_ptr<engine::Material> m_Material;
       // std::shared_ptr<engine::IShader> m_Shader;

        std::vector<uint8_t> m_Blocks;




        //ffff
       // glm::vec3 m_Position = glm::vec3(0.0f);

        engine::IShader* m_Shader = nullptr;
    };


} // opengltests
