#pragma once

namespace engine
{
    enum class Action
    {
        MoveForward,
        MoveBackward,
        MoveLeft,
        MoveRight,

        Jump,
        Sprint,

        BreakBlock,
        PlaceBlock,

        InventoryNext,
        InventoryPrev
    };
}