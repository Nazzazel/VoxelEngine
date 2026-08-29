//
// Created by nazzazel on 28.07.2026.
//

#include "OpenGLTestsApp.hpp"

#include "Core/Systems/Time/TimerSystem.hpp"


namespace opengltests
{
 //   loadedChunks = std::vector<Chunk> loadedChunks[render_distance*render_distance];

    void OpenGLTestsApp::OnInit(engine::IAppInterface& engine)
    {



        m_opengl_camera = std::make_unique<opengltests::OpenGLCamera>();
        m_input_handler = std::make_unique<InputHandler>(engine.GetInputSystem(),*m_opengl_camera, engine);

     loadedChunks.reserve(render_distance*render_distance);


        ///



       //m_Rot_Cube = std::make_unique<RotatingCube>();
       //m_Rot_Cube->Init(engine.GetAssetSystem());


      // glm::ivec3 chunkPos(6, 0, 6);
       glm::ivec3 chunkPos(7, 0, 7);
       //nnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnb
       //

     engine.GetTimerSystem().AddTimer("Chunk Timer");
     engine.GetTimerSystem().StartTimer("Chunk Timer");
     //engine.GetTimerSystem().SetTimerAccuracy(engine::Timer::Accuracy::MicroSecond);
     engine.GetTimerSystem().SetTimerAccuracy(engine::Timer::Accuracy::MilliSecond);


    for (int x = -(chunkPos.x/2); x < chunkPos.x/2; x++)
    {
    // for (int y = -1; y < chunkPos.y; y++)
    // {
      for (int z = -(chunkPos.z/2); z < chunkPos.z/2; z++)
      {
       std::cout   << "mark  \n";
       ///auto& newChunk = loadedChunks.emplace_back(std::make_unique<Chunk>(glm::vec3(x,y,z), engine.GetAssetSystem(),texture));
       auto& newChunk = loadedChunks.emplace_back(Chunk(glm::vec3(x,-1,z), engine.GetAssetSystem(),texture));
       newChunk.BuildMesh();
       engine.GetTimerSystem().GetElapsedMs();
       engine.GetTimerSystem().ResetTimer();
      }
   //  }
    }


     //newChunk->BuildMesh();



   //  auto& newChunk = loadedChunks.emplace_back(std::make_unique<Chunk>(glm::vec3(1,1,1), engine.GetAssetSystem()));//havege the pointer on a vector<chunk> to avoid overhead
     // auto& newChunk = loadedChunks.emplace_back(std::make_unique<Chunk>(glm::vec3(1,1,1), engine.GetAssetSystem(),texture));//havege the pointer on a vector<chunk> to avoid overhead
     // newChunk->BuildMesh();



     //auto& newChunk = loadedChunks.emplace_back(std::make_unique<Chunk>(glm::vec3(0,-2,0), engine.GetAssetSystem()));
     //newChunk->BuildMesh();


        //loadedChunks.emplace_back(newChunk);

        //loadedChunks.push_back(std::make_unique<Chunk>(chunkPos,engine.GetAssetSystem()));
       //m_worldPosition =

      // m_Chunk = std::make_unique<Chunk>(chunkPos,engine.GetAssetSystem());
      // m_Chunk->BuildMesh();
    }



    void OpenGLTestsApp::OnUpdate(engine::IAppInterface& engine, float dt)
    {

     UpdateWindowSize(engine, dt);
        m_input_handler->OnUpdate(dt);





    }


    void OpenGLTestsApp::OnRender(engine::IRenderer& renderer)
    {

        renderer.SetSceneData(m_opengl_camera->GetSceneData());
      //  m_Chunk->SetBlock(0,0,0, 0);
        //m_Chunk->Draw(renderer , m_opengl_camera.get()->GetWorldPosition());

        for ( auto& chunk : loadedChunks)
        {
         chunk.Draw(renderer, m_opengl_camera->GetWorldPosition());
        }

      //for (unsigned int i = 0; i < sizeof(cubePositions) / sizeof(cubePositions[0]); i++)
      //{
      //    // std::cout << i << std::endl;
      //  m_Rot_Cube->SetPosition(cubePositions[i]);
      //  m_Rot_Cube->Draw(renderer);
      // }

    }

    void OpenGLTestsApp::OnShutdown()
    {

    }

    void OpenGLTestsApp::UpdateWindowSize(engine::IAppInterface& engine, float dt)
    {

     auto windowObj = engine.GetWindowSystem().GetWindow();
     int width, height;
     windowObj->GetWindowSize(width, height);

     static int lastWidth = 0;
     static int lastHeight = 0;

     if (width != lastWidth || height != lastHeight)
     {
      lastWidth = width;
      lastHeight = height;

      if (height > 0)
      {
       float aspect = static_cast<float>(width) / static_cast<float>(height);
       m_opengl_camera->SetAspectRatio(aspect); // Updates projection matrix only when size changes!
      }
     }

    }
} // opengltests