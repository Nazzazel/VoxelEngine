//
// Created by nazzazel on 13.07.2026.
//

#include "VoxelGameApp.hpp"

#include "Core/Systems/Input/InputSystem.hpp"
#include "VoxelGame/Game/Camera/Camera.hpp"
#include "VoxelGame/Input/GameInput.hpp"

namespace voxelgame
{


        VoxelGameApp::VoxelGameApp(const engine::AppSettings& settings)
                : Application(settings){}

        void VoxelGameApp::OnInit(engine::IAppInterface* engine)
        {
            input = GameInput();
           // input = &G;


            m_pos_ptr = std::make_unique<glm::vec3>();
            input.SetVec3Ptr(m_pos_ptr.get());


            engine->GetLoggerSystem();
            keybordInputStateMap = engine->GetInputSystem()->GetKeybordInputStateMap();
           // keybordInputStateMap->SetIInput(&input);



            //std::cout << "ffff132424" << std::endl;

            //DT_ERROR("lol");//TODO first
            // //TODO DEAL WITH THIS debugtools::Logger::Log(debugtools::LogLevel::Info, "hhhhhhh");
            m_Rot_Cube = std::make_unique<engine::Rot_Cube>();
           // m_Rot_Cube->Init(GetAssetManager());
            m_Rot_Cube->Init(*engine->GetAssetSystem());



            m_camera = std::make_unique<voxelgame::Camera>();
        }

        void VoxelGameApp::OnUpdate(engine::IAppInterface* engine,float dt)
        {

         // Get the input state map via your engine interface or stored pointer
         auto inputMap = engine->GetInputSystem()->GetKeybordInputStateMap();

         float moveSpeed = 5.0f * dt; // Scale by delta time!

         if (inputMap->IsKeyPressed(engine::KeyCodes::KEY_W))
         {
          m_camera->MoveFront(moveSpeed);
         }
         if (inputMap->IsKeyPressed(engine::KeyCodes::KEY_S))
         {
          m_camera->MoveFront(-moveSpeed);
         }
         if (inputMap->IsKeyPressed(engine::KeyCodes::KEY_ESCAPE))
         {
          m_camera->SetPosition(glm::vec3(0.0f));
         }
         if (inputMap->IsKeyPressed(engine::KeyCodes::KEY_R))
         {
          //m_camera->Rotate(glm::vec3(0.0f));
         }


          //  engine->GetLoggerSystem()->AddInfo("lol engine");
            // //TODO DEAL WITH THIS debugtools::Logger::Log(debugtools::LogLevel::Info, "DDDDDD");
            //auto shader = GetAssetManager().GetShaderManager().Get(engine::ShaderTypeID::Basic); //TODO remove this later
            //shader->Bind(); //TODO remove this later

            ////std::cout << "ggggggg1" << std::endl;
            //static float fpsSmoothed = 0.0f;
            //fpsSmoothed = fpsSmoothed * 0.9f + (0.1f / dt);
            //
            //float fps = (dt > 0.0f) ? (1.0f / dt) : 0.0f;
            //float msPerFrame = dt * 1000.0f;

            ////TODO DEAL WITH THIS debugtools::Logger::Log(debugtools::LogLevel::Info,
            //    "   dt:     " + std::to_string(dt) +
            //    " | fps:    " + std::to_string(fpsSmoothed) +
            //    " | ms:     " + std::to_string(msPerFrame)
            //);

            //std::cout << "Game Loop is working delta: " << dt << std::endl;

            // game update logic

        }

        //void VoxelGameApp::OnRender(engine::Renderer& renderer)
        void VoxelGameApp::OnRender(engine::IRenderer& renderer)
        {

           // rot_cube.Draw(*renderer->GetRenderer());

          // float ab = 3.0f;

           //m_Rot_Cube->AdditionalData(ab);
           renderer.SetSceneData(m_SceneData);
           m_Rot_Cube->SetPosition(m_camera->GetPosition());
           m_Rot_Cube->Draw(renderer);








          // //std::cout << "ggggg "<< std::endl;
          // //renderer.DrawTriangle(); //TODO remove this later

          // // rendering logic (later voxel world)

          // //renderer.DrawIndexed()

        }

        void VoxelGameApp::OnShutdown()
        {
            std::cout << "exittttttttttttttttt" << std::endl;
        }
} // voxelgame