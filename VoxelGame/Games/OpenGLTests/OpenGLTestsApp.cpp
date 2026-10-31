//
// Created by nazzazel on 28.07.2026.
//

#include "OpenGLTestsApp.hpp"

#include "Core/Systems/Time/TimerSystem.hpp"
#include "Tests/Objects/Text.hpp"


namespace opengltests
{
 //   loadedChunks = std::vector<Chunk> loadedChunks[render_distance*render_distance];

    void OpenGLTestsApp::OnInit(engine::IAppInterface& engine)
    {
       // m_engine = engine;
        texture = std::make_unique<engine::OpenGLTexture>();


        m_opengl_camera = std::make_unique<opengltests::OpenGLCamera>(engine);
        m_input_handler = std::make_unique<InputHandler>(engine.GetInputSystem(),*m_opengl_camera, engine);

        loadedChunks.reserve(render_distance*render_distance);


        ///



       //m_Rot_Cube = std::make_unique<RotatingCube>();
       //m_Rot_Cube->Init(engine.GetAssetSystem());


       glm::ivec3 chunkPos(50, 0, 50);
      // glm::ivec3 chunkPos(4, 0, 4);
       //nnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnb
       //

    // engine.GetTimerSystem().AddTimer("Chunk Timer");
    // engine.GetTimerSystem().StartTimer("Chunk Timer");
     //engine.GetTimerSystem().SetTimerAccuracy(engine::Timer::Accuracy::MicroSecond);
     engine.GetTimerSystem().SetTimerAccuracy(engine::Timer::Accuracy::MilliSecond);


    for (int x = -(chunkPos.x/2); x < chunkPos.x/2; x++)
    {
    // for (int y = -1; y < chunkPos.y; y++)
    // {
      for (int z = -(chunkPos.z/2); z < chunkPos.z/2; z++)
      {
       //std::cout   << "mark  \n";
       ///auto& newChunk = loadedChunks.emplace_back(std::make_unique<Chunk>(glm::vec3(x,y,z), engine.GetAssetSystem(),texture));
       auto& newChunk = loadedChunks.emplace_back(Chunk(glm::vec3(x,-5,z), engine.GetAssetSystem(),texture));
       newChunk.BuildMesh();
      // engine.GetTimerSystem().GetElapsedMs();
      // engine.GetTimerSystem().ResetTimer();
      }
   //  }
    }

      m_text = std::make_unique<opengltests::Text>(engine.GetAssetSystem(),"/usr/share/fonts/Adwaita/AdwaitaSans-Regular.ttf",std::make_unique<engine::OpenGLTexture>());

     //m_text = text;
    // m_text = m_text()

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
      //m_engine = engine;
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

       m_text->Draw(renderer,"123456789",0.5,0.5,1,glm::vec3(255,0,0));
  //rendquadtest(renderer);






      //for (unsigned int i = 0; i < sizeof(cubePositions) / sizeof(cubePositions[0]); i++)
      //{
      //    // std::cout << i << std::endl;
      //  m_Rot_Cube->SetPosition(cubePositions[i]);
      //  m_Rot_Cube->Draw(renderer);
      // }

    }

 void OpenGLTestsApp::rendquadtest(engine::IRenderer& renderer)
    {
  //    // 1. Set up a temporary identity/ortho scene data so it draws on the screen in NDC space (-1 to 1)
  //    engine::SceneData uiSceneData;
  //    uiSceneData.viewMatrix = glm::mat4(1.0f);
  //    uiSceneData.projectionMatrix = glm::mat4(1.0f); // Identity means coordinates range from -1 to 1
  //    renderer.SetSceneData(uiSceneData);
  //
  //    // 2. Define a simple quad right in the center of the screen (-0.5 to 0.5)
  //    // Layout: a_Position (Float2), a_TexCoord (Float2)
  //    float quadVertices[] = {
  //     -0.5f,  0.5f,  0.0f, 1.0f, // Top-left
  //     -0.5f, -0.5f,  0.0f, 0.0f, // Bottom-left
  //      0.5f, -0.5f,  1.0f, 0.0f, // Bottom-right
  //
  //     -0.5f,  0.5f,  0.0f, 1.0f, // Top-left
  //      0.5f, -0.5f,  1.0f, 0.0f, // Bottom-right
  //      0.5f,  0.5f,  1.0f, 1.0f  // Top-right
  // };
  //
  //    uint32_t quadIndices[] = { 0, 1, 2, 3, 4, 5 };
  //
  //    const engine::BufferLayout layout = {
  //     {engine::ShaderDataType::Float2, "a_Position"},
  //     {engine::ShaderDataType::Float2, "a_TexCoord"}
  //    };
  //
  //    // Create a temporary test mesh (or make it static so you don't recreate it every frame)
  //    auto testMesh = std::make_shared<engine::Mesh>(
  //        quadVertices, sizeof(quadVertices),
  //        layout,
  //        quadIndices, 6
  //    );
  //
  //    // Get your UI shader
  //    auto shader = m_engine.GetAssetSystem().GetShaderManager().Get(engine::ShaderTypeID::UI); // Use your asset system method
  //
  //    // Create a material (pass nullptr or a dummy texture if your material requires one)
  //    auto material = std::make_shared<engine::Material>(shader, nullptr);
  //
  //    // 3. Submit the draw command
  //    engine::DrawCommand cmd;
  //    cmd.modelMatrix = glm::mat4(1.0f);
  //    cmd.material = material;
  //    cmd.mesh = testMesh;
  //    renderer.Submit(cmd);
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