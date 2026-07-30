//
// Created by nazzazel on 28.07.2026.
//

#include "OpenGLTestsApp.hpp"




namespace opengltests
{
    void OpenGLTestsApp::OnInit(engine::IAppInterface& engine)
    {


        m_opengl_camera = std::make_unique<opengltests::OpenGLCamera>();
        m_input_handler = std::make_unique<InputHandler>(engine.GetInputSystem(),*m_opengl_camera, engine);


       //m_Rot_Cube = std::make_unique<RotatingCube>();
       //m_Rot_Cube->Init(engine.GetAssetSystem());


      // glm::ivec3 chunkPos(20, 0, 20);


        // for (int x = -(chunkPos.x/2); x < chunkPos.x/2; x++)
        // {
        //  for (int y = -1; y < chunkPos.y; y++)
        //  {
        //   for (int z = -(chunkPos.z/2); z < chunkPos.z/2; z++)
        //   {
        //    auto& newChunk = loadedChunks.emplace_back(std::make_unique<Chunk>(glm::vec3(x,y,z), engine.GetAssetSystem()));
        //    newChunk->BuildMesh();
        //   }
        //  }
        // }
     auto& newChunk = loadedChunks.emplace_back(std::make_unique<Chunk>(glm::vec3(0,-2,0), engine.GetAssetSystem()));
     newChunk->BuildMesh();


        //loadedChunks.emplace_back(newChunk);

        //loadedChunks.push_back(std::make_unique<Chunk>(chunkPos,engine.GetAssetSystem()));
       //m_worldPosition =

      // m_Chunk = std::make_unique<Chunk>(chunkPos,engine.GetAssetSystem());
      // m_Chunk->BuildMesh();
    }



    void OpenGLTestsApp::OnUpdate(engine::IAppInterface& engine, float dt)
    {
        m_input_handler->OnUpdate(dt);
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

   // glm::vec3 cubePositions[] = {
   //     glm::vec3( 0.0f,  0.0f,  0.0f),
   //     glm::vec3( 2.0f,  5.0f, -15.0f),
   //     glm::vec3(-1.5f, -2.2f, -2.5f),
   //     glm::vec3(-3.8f, -2.0f, -12.3f),
   //     glm::vec3( 2.4f, -0.4f, -3.5f),
   //     glm::vec3(-1.7f,  3.0f, -7.5f),
   //     glm::vec3( 1.3f, -2.0f, -2.5f),
   //     glm::vec3( 1.5f,  2.0f, -2.5f),
   //     glm::vec3( 1.5f,  0.2f, -1.5f),
   //     glm::vec3(-1.3f,  1.0f, -1.5f)
   //};


    void OpenGLTestsApp::OnRender(engine::IRenderer& renderer)
    {

        renderer.SetSceneData(m_opengl_camera->GetSceneData());
      //  m_Chunk->SetBlock(0,0,0, 0);
        //m_Chunk->Draw(renderer , m_opengl_camera.get()->GetWorldPosition());

        for (const auto& chunk : loadedChunks)
        {
         chunk->Draw(renderer, m_opengl_camera->GetWorldPosition());
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


} // opengltests