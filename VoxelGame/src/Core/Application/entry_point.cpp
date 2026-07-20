//
// Created by nazzazel on 13.07.2026.
//
#include <tracy/Tracy.hpp>

#include "voxel_game_app.hpp"
#include "../../../../Engine/Core/Application/application.hpp"



int main()
{
    engine::WindowConfig win_config(1280,720,"GameEngine");
    engine::AdditionalParams additionalParams{ .m_debugMode = true};
    engine::AppSettings settings(win_config, additionalParams);

    voxelgame::VoxelGameApp app(settings);

    app.Run();
}

