//
// Created by nazzazel on 30.07.2026.
//


#pragma once
namespace opengltests
{
    enum class BlockType : uint64_t
    {
        AIR = 0,
        GRASS = 1,
        STONE = 2,
    };

    uint64_t GetIDFromBlockType(BlockType blockType)
    {
        return static_cast<uint64_t>(blockType);
    }

}