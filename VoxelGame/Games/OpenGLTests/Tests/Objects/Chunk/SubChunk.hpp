//
// Created by nazzazel on 30.07.2026.
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
#include "VoxelGame/Games/OpenGLTests/Core/Base/VoxelGameHeaders/WorldCoord.hpp"

namespace opengltests
{

    //TODO
    class SubChunk
    {
    public:
        uint8_t SUB_CHUNK_SIZE = 16; //Max 256 block chunk

        SubChunk();
        SubChunk(uint8_t f_SUB_CHUNK_SIZE, glm::ivec3 chunkPos,engine::AssetSystem& assets);
        ~SubChunk() = default;

       // std::vector<uint16_t > pallette;
       // std::vector<uint64_t > blockData; //blockData[0] + offset based on the unique amount of // 4 unique block -> 2bits -> 64bit/2bit -> 32 blocks

        std::vector<glm::uint16_t> chunkData;

        bool isEmpty = false;

        void SetBlock(int x, int y, int z, uint16_t blockID);
        [[nodiscard]] uint16_t GetBlock(int x, int y, int z) const;

    private:



    };
} // opengltests
