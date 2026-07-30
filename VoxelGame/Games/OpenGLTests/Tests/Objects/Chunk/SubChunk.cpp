//
// Created by nazzazel on 30.07.2026.
//

#include "SubChunk.hpp"

namespace opengltests
{
    SubChunk::SubChunk(glm::ivec3 chunkPos,engine::AssetSystem& assets)
    //:m_ChunkPosition(chunkPos*16),m_assets(assets)
    {
        //chunkData = {5000,0};
        chunkData.resize(4096, 1);
    }

    void SubChunk::SetBlock(int x, int y, int z, uint16_t blockID)
    {
        chunkData[0] = 0;//TODO
    }

    uint16_t SubChunk::GetBlock(int x, int y, int z) const
    {

        if (x >= 0 && x < SUB_CHUNK_SIZE &&
            y >= 0 && y < SUB_CHUNK_SIZE &&
            z >= 0 && z < SUB_CHUNK_SIZE) {
            return chunkData[x + y * SUB_CHUNK_SIZE + z * SUB_CHUNK_SIZE * SUB_CHUNK_SIZE];
            }
        return 0;
    }


} // opengltests

