//
// Created by nazzazel on 30.07.2026.
//

#include "SubChunk.hpp"

namespace opengltests
{
    SubChunk::SubChunk(){} //TEMP CONSTRUCTOR FOR ARRAY INIT// REASON FAST MEMORY

    SubChunk::SubChunk(uint8_t f_SUB_CHUNK_SIZE, glm::ivec3 chunkPos,engine::AssetSystem& assets)
    //:m_ChunkPosition(chunkPos*16),m_assets(assets)
    {
        SUB_CHUNK_SIZE = f_SUB_CHUNK_SIZE;

        //chunkData = {5000,0};
        std::cout << "x:" << chunkPos.x<< " y: " <<chunkPos.y<< " z: " << chunkPos.z<< std::endl;

        if (chunkPos.y ==1000)
        {
            chunkData.resize(SUB_CHUNK_SIZE*SUB_CHUNK_SIZE*SUB_CHUNK_SIZE, 0);
        }
        else
        {
            chunkData.resize(SUB_CHUNK_SIZE*SUB_CHUNK_SIZE*SUB_CHUNK_SIZE, 1);
        }

        UpdateState();
        //chunkData.resize(SUB_CHUNK_SIZE*SUB_CHUNK_SIZE*SUB_CHUNK_SIZE, 1);
        //chunkData.resize(SUB_CHUNK_SIZE * SUB_CHUNK_SIZE * SUB_CHUNK_SIZE, 1);
    }

    void SubChunk::SetBlock(int x, int y, int z, uint16_t blockID)
    {
        //chunkData[0] = 0;//TODO
        if (x >= 0 && x < SUB_CHUNK_SIZE &&
                y >= 0 && y < SUB_CHUNK_SIZE &&
                z >= 0 && z < SUB_CHUNK_SIZE)
        {
            // Consistent flat-array indexing: x + (y * WIDTH) + (z * WIDTH * HEIGHT)
            int index = x + (y * SUB_CHUNK_SIZE) + (z * SUB_CHUNK_SIZE * SUB_CHUNK_SIZE);
            chunkData[index] = blockID;
        }



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

    void SubChunk::UpdateState() {
        bool hasAir = false;
        bool hasSolid = false;

        for (auto block : chunkData) {
            if (block == 0) hasAir = true;
            else hasSolid = true;
        }

        if (!hasAir) m_State = SubChunkState::Solid;
        else if (!hasSolid) m_State = SubChunkState::Empty;
        else m_State = SubChunkState::Mixed;
        std::cout << "state:" << static_cast<int>(m_State) << std::endl;
        //m_State = SubChunkState::Solid;
    }

    int SubChunk::GetSubChunkState() const
    {
        switch (m_State)
        {
            case SubChunkState::Empty: return 0;
            case SubChunkState::Solid: return 1;
            case SubChunkState::Mixed: return 2;
        }

        return -1;
    }
} // opengltests

