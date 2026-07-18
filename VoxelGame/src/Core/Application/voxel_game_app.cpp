//
// Created by nazzazel on 13.07.2026.
//

#include "voxel_game_app.hpp"

namespace voxelgame
{


        VoxelGameApp::VoxelGameApp(const engine::AppSettings& settings)
                : Application(settings){}



        void VoxelGameApp::OnInit()
        {
            std::cout << "ffff132424" << std::endl;

            DT_ERROR("lol");
            // debugtools::Logger::Log(debugtools::LogLevel::Info, "hhhhhhh");
            m_Rot_Cube = std::make_unique<engine::Rot_Cube>();
            m_Rot_Cube->Init(GetAssetManager());

        }

        void VoxelGameApp::OnUpdate(float dt)
        {

            // debugtools::Logger::Log(debugtools::LogLevel::Info, "DDDDDD");
            //auto shader = GetAssetManager().GetShaderManager().Get(engine::ShaderTypeID::Basic); //TODO remove this later
            //shader->Bind(); //TODO remove this later

            ////std::cout << "ggggggg1" << std::endl;
            //static float fpsSmoothed = 0.0f;
            //fpsSmoothed = fpsSmoothed * 0.9f + (0.1f / dt);
            //
            //float fps = (dt > 0.0f) ? (1.0f / dt) : 0.0f;
            //float msPerFrame = dt * 1000.0f;

            //debugtools::Logger::Log(debugtools::LogLevel::Info,
            //    "   dt:     " + std::to_string(dt) +
            //    " | fps:    " + std::to_string(fpsSmoothed) +
            //    " | ms:     " + std::to_string(msPerFrame)
            //);

            //std::cout << "Game Loop is working delta: " << dt << std::endl;

            // game update logic

        }

        void VoxelGameApp::OnRender(engine::Renderer& renderer)
        {
            float ab = 3.0f;

            m_Rot_Cube->AdditionalData(ab);
            m_Rot_Cube->Draw(renderer);
            //std::cout << "ggggg "<< std::endl;
            //renderer.DrawTriangle(); //TODO remove this later

            // rendering logic (later voxel world)

            //renderer.DrawIndexed()

        }

        void VoxelGameApp::OnShutdown()
        {
            DT_INFO("Voxel Game Shutting down");
            std::cout << "exittttttttttttttttt" << std::endl;
        }
} // voxelgame