//
// Created by nazzazel on 1.09.2026.
//


#pragma once


namespace opengltests
{



    class ChunkManager
    {
    public:
        ChunkManager();
        ~ChunkManager();

        engine::Result SetRenderDistance(uint8_t distance);
        uint8_t GetRenderDistance();

        void UpdateRenderDistance();





    private:






    };

    
} // opengltests
