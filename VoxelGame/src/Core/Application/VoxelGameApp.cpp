//
// Created by nazzazel on 13.07.2026.
//

#include "VoxelGameApp.hpp"

// #include "Core/Systems/Input/InputSystem.hpp"
// #include "../../../Game/Core/Systems/Camera/Camera.hpp"
// #include "VoxelGame/Game/Core/Client/Input/InputHandler.hpp"
//
// #include "VoxelGame/Input/GameInput.hpp"

namespace voxelgame
{


        VoxelGameApp::VoxelGameApp(const engine::AppSettings& settings)
                : Application(settings){}

        void VoxelGameApp::OnInit(engine::IAppInterface& engine)
        {
         m_OpenGLTestsApp = std::make_unique<opengltests::OpenGLTestsApp>();
         m_OpenGLTestsApp->OnInit(engine);


         //OpenGLTestsApp::OnInit(engine);

            //input = GameInput();
            //input_handler = std::make_unique<InputHandler>(engine.GetInputSystem());





           // input = &G;
           // m_pos_ptr = std::make_unique<glm::vec3>();
            //input.SetVec3Ptr(m_pos_ptr.get());

           // engine.GetLoggerSystem();
            //keybordInputStateMap = engine.GetInputSystem().GetKeybordInputStateMap();
           // keybordInputStateMap->SetIInput(&input);



            //std::cout << "ffff132424" << std::endl;

            //DT_ERROR("lol");//TODO first
            // //TODO DEAL WITH THIS debugtools::Logger::Log(debugtools::LogLevel::Info, "hhhhhhh");
          //  m_Rot_Cube = std::make_unique<engine::Rot_Cube>();
           // m_Rot_Cube->Init(GetAssetManager());
            //m_Rot_Cube->Init(engine.GetAssetSystem());



          //  m_camera = std::make_unique<voxelgame::Camera>();

        }

        bool cursorbool = true;

        void VoxelGameApp::OnUpdate(engine::IAppInterface& engine,float dt)
        {
         m_OpenGLTestsApp->OnUpdate(engine, dt);
        // // auto windowObj = engine.GetWindowSystem().GetWindow();
        //  int width, height;
        //  //windowObj->GetWindowSize(width, height);
        //
        //  static int lastWidth = 0;
        //  static int lastHeight = 0;
        //
        //  if (width != lastWidth || height != lastHeight)
        //  {
        //   lastWidth = width;
        //   lastHeight = height;
        //
        //   if (height > 0)
        //   {
        //    float aspect = static_cast<float>(width) / static_cast<float>(height);
        //    m_camera->SetAspectRatio(aspect); // Updates projection matrix only when size changes!
        //   }
        //  }



         //TODO 123FFFFFFFFF
         //int width,height;
        // engine->GetWindowSystem()->GetWindow()->GetWindowSize(width,height);

         //std::cout << width << " " << height << std::endl;

         //m_camera->Update((float)width / (float)height);


         // Get the input state map via your engine interface or stored pointer
        // auto& inputSystem = engine.GetInputSystem();
        // auto inputMap = inputSystem.GetKeybordInputStateMap();
        // auto mouseState = inputSystem.GetMouseInputState();
//
        // float moveSpeed = 2.5f * dt; // Scale by delta time!
//
        // if (inputMap->IsKeyPressed(engine::KeyCodes::KEY_W))
        // {
        //  m_camera->MoveFront(moveSpeed);
        // }
        // if (inputMap->IsKeyPressed(engine::KeyCodes::KEY_S))
        // {
        //  m_camera->MoveFront(-moveSpeed);
        // }
        // if (inputMap->IsKeyPressed(engine::KeyCodes::KEY_A))
        // {
        //  m_camera->MoveRight(moveSpeed);
        // }
        // if (inputMap->IsKeyPressed(engine::KeyCodes::KEY_D))
        // {
        //  m_camera->MoveRight(-moveSpeed);
        // }
        // if (inputMap->IsKeyPressed(engine::KeyCodes::KEY_SPACE))
        // {
        //  m_camera->MoveUp(-moveSpeed);
        // }
        // if (inputMap->IsKeyPressed(engine::KeyCodes::KEY_LEFT_SHIFT))
        // {
        //  m_camera->MoveUp(moveSpeed);
        // }
        // if (inputMap->IsKeyPressed(engine::KeyCodes::KEY_ESCAPE))
 //      // {
 //        cursorbool = !cursorbool;
 //        engine.GetWindowSystem().EnableCursor(cursorbool);
 //        //m_camera->SetPosition(glm::vec3(0.0f));
 //        m_camera->SetPosition(glm::vec3(0.0f, 0.0f, 0.0f));
 //       }
 //       if (inputMap->IsKeyPressed(engine::KeyCodes::KEY_R))
 //       {
 //         //m_camera->Rotate(glm::vec3(0.0f));
 //         m_camera->Rotate(0,0.01f);
 //       }

 //       m_camera->Update(dt);

 //      float xoffset = mouseState->xDelta;
 //      float yoffset = mouseState->yDelta;

 //       float xscrolloffset = mouseState->m_xScrollDelta;
 //       float yscrolloffset = mouseState->m_yScrollDelta;

 //       // Reset deltas so they don't continuously spin the camera next frame
 //       mouseState->ResetDeltas();

 //     if (xoffset != 0.0f || yoffset != 0.0f )
 //     {
 //      //std::cout <<   " " << yoffset << " "   << " " << xoffset << std::endl;
 //      m_camera->Rotate(yoffset, xoffset);
 //     }

 //     if (xscrolloffset != 0.0f || yscrolloffset != 0.0f )
 //     {
 //      //std::cout <<   " " << yoffset << " "   << " " << xoffset << std::endl;
 //      m_camera->SetScoll(xscrolloffset,yscrolloffset);
 ///}

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


        // glm::vec3 CubesPosition[]
        // {
        //  {1.0f, 0.0f, 0.0f},
        //  {3.0f, 6.0f, 0.0f},
        //  {0.0f, 0.0f, 0.0f},
        //  {0.0f, 7.0f, 2.0f},
        //  {8.0f, 4.0f, 2.0f},
        //  {2.0f, 9.0f, 4.0f},
        //  {0.0f, 2.0f, 5.0f}
        // };

      // glm::vec3 cubePositions[] = {
      //      glm::vec3( 0.0f,  0.0f,  0.0f),
      //      glm::vec3( 2.0f,  5.0f, -15.0f),
      //      glm::vec3(-1.5f, -2.2f, -2.5f),
      //      glm::vec3(-3.8f, -2.0f, -12.3f),
      //      glm::vec3( 2.4f, -0.4f, -3.5f),
      //      glm::vec3(-1.7f,  3.0f, -7.5f),
      //      glm::vec3( 1.3f, -2.0f, -2.5f),
      //      glm::vec3( 1.5f,  2.0f, -2.5f),
      //      glm::vec3( 1.5f,  0.2f, -1.5f),
      //      glm::vec3(-1.3f,  1.0f, -1.5f)
      // };

      // //void VoxelGameApp::OnRender(engine::Renderer& renderer)
      void VoxelGameApp::OnRender(engine::IRenderer& renderer)
       {

         m_OpenGLTestsApp->OnRender(renderer);
      ////  m_camera->SetAspectRatio(renderer.GetAspectRatio()); // Upda
      //    // rot_cube.Draw(*renderer->GetRenderer());

      //   // float ab = 3.0f;

      //    //m_Rot_Cube->AdditionalData(ab);
      /// std::cout << "gdgfd\n";
      //    renderer.SetSceneData(m_camera->GetSceneData());



      //    //m_Rot_Cube->SetPosition(m_camera->GetPosition());

      //  for (unsigned int i = 0; i < sizeof(cubePositions) / sizeof(cubePositions[0]); i++)
//{
      //  // std::cout << i << std::endl;
      //   m_Rot_Cube->SetPosition(cubePositions[i]);
      //   m_Rot_Cube->Draw(renderer);


      //  }
        // while (CubesPosition->length())dw
        // {
//
        // }








          // //std::cout << "ggggg "<< std::endl;
          // //renderer.DrawTriangle(); //TODO remove this later

          // // rendering logic (later voxel world)

          // //renderer.DrawIndexed()

        }

        void VoxelGameApp::OnShutdown()
        {
         m_OpenGLTestsApp->OnShutdown();
            std::cout << "exittttttttttttttttt" << std::endl;
        }
} // voxelgame