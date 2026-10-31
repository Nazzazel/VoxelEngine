//Engine
#include "Application.hpp"

#include <thread>
#include <GLFW/glfw3.h>

#include "triangle.hpp"
#include "AppInterface/EngineCore.hpp"
#include "Core/Systems/Assets/AssetSystem.hpp"
#include "Core/Systems/Event/EventSystem.hpp"
#include "Core/Systems/Renderer/RendererSystem.hpp"
#include "Core/Systems/Window/WindowSystem.hpp"
#include "EngineStartUp/EngineStartup.hpp"
#include "Systems/Platform/Input/EngineInput.hpp"



// #include <Platform/Input/Debug/debug_input.hpp>
//
// //#include "Engine/DefaultEngineStartup/engine_startup.hpp"
// //#include "Engine/Manager/Systems/Logger/logger_system.hpp"
// #include "EngineStartUp/engine_startup.hpp"
// #include "../Engine/Manager/Systems/Logger/logger_system.hpp"
// #include "../Engine/Manager/Systems/Platform/platform_system.hpp"
// #include "API/renderer_api.hpp"
//#include <tracy/Tracy.hpp>
#define TRACY_ENABLE
//#include <GLFW/glfw3.h>

namespace engine
{
    Application::Application(const AppSettings& settings)
        :m_Settings(settings)
    {



       m_SystemManager = std::make_unique<engine::SystemManager>();

        engine::EngineStartup engine_startup{};
        if (Result result = engine_startup.Init(*m_SystemManager,m_Settings);result.IsFailure())
        {

            std::cout << "???//\n";

        }
       // EngineCore core = EngineCore(m_SystemManager.get());







        //----------------------------------------------------------------------------------

     }

    Application::~Application()
    {
        Result result = m_SystemManager->ShutdownAll();//TODO / Result here is kinda useless, but I will (propably) do it later
        auto info = result.Inspect();
    }



    void Application::Run()
    {
        //Application::OnInit(core);

        TimeSystem* timer    = m_SystemManager->GetSystem<TimeSystem>();
        logger = m_SystemManager->GetSystem<LoggerSystem>();
        WindowSystem* window = m_SystemManager->GetSystem<WindowSystem>();
        EventSystem* event_system = m_SystemManager->GetSystem<EventSystem>();
        AssetSystem* asset   = m_SystemManager->GetSystem<AssetSystem>();
        RendererSystem* renderer   = m_SystemManager->GetSystem<RendererSystem>();


        TraditionalPipelineShaderFlag flag{};
        flag.SetFragment(true);
        flag.SetVertex(true);
        //flag.SetGeometry(true);
        //flag.SetTessellationControl(true);
        //flag.SetTessellationEvaluation(true);

        asset->GetShaderManager().SetTraditionalPipeline(flag);

        asset->GetShaderManager().LoadEngineShader(ShaderTypeID::Basic);
        asset->GetShaderManager().LoadEngineShader(ShaderTypeID::UI);



        EngineInput e_input = EngineInput(m_SystemManager.get()) ;
        e_input.Init();
        e_input.GLFWEventCallbacks();







        EngineCore engine = EngineCore{m_SystemManager.get()};
        OnInit(engine);

       // rot_cube.Init(*asset);
        //Triangle triangle;
       // triangle.Init(*asset);


        logger->AddInfo("dddd");

       // auto last_frame_time = std::chrono::steady_clock::now();

        const double TARGET_UPS = 60.0; // Updates Per Second
        const double TIME_PER_UPDATE = 1.0 / TARGET_UPS;

        double accumulator = 0.0;
        auto lastTime = std::chrono::high_resolution_clock::now();

        const auto target_frame_duration = std::chrono::nanoseconds(1000000000 / 60);

        double inside_loop = 0.0f;

        while (m_EngineRunning && !window->GetWindow()->ShouldClose())
        {

            auto currentTime = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsedTime = currentTime - lastTime;
            lastTime = currentTime;

            accumulator += elapsedTime.count();

            // --- 1. Calculate Delta Time ---
           // auto current_frame_time = std::chrono::steady_clock::now();
           // std::chrono::duration<float> elapsed = current_frame_time - last_frame_time;
           // last_frame_time = current_frame_time;
            float dt = elapsedTime.count();

            if (Result result = m_SystemManager->UpdateAll(dt);result.IsFailure()) { logger->AddResult(result);}

            OnUpdate(engine, dt);

            renderer->GetRenderer()->BeginFrame();

            OnRender(*renderer->GetRenderer());

            //---------------------------------------------------------
          //  rot_cube.Draw(*renderer->GetRenderer());
            //triangle.Draw(*renderer->GetRenderer());
            //---------------------------------------------------------

            renderer->GetRenderer()->EndFrame();

          //  std::string name = "Outside : " + std::to_string(timer->GetFPS()) + " : Inside : " + std::to_string(inside_loop);

            window->GetWindow()->SetName(std::to_string(timer->GetFPS()));

            // High-resolution clock to track inner loop time
            auto frame_start = std::chrono::high_resolution_clock::now();

            // --- INNER LOOP (Locked to 60 UPS) ---
            // Put your game logic, physics update, or per-frame tasks here:
            // update_game_state();
            // -------------------------------------


        }

    }

    void Application::RunDDD(int a)
    {
        switch (a)
        {
         //  case GLFW_KEY_ESCAPE: rot_cube.SetPosition({0,0,0}); logger->AddInfo("DFFFFF"); break;
         //  case GLFW_KEY_W:      rot_cube.Translate({0,0,0.1f}); break;
         //  case GLFW_KEY_S:      rot_cube.Translate({0,0,-0.1f}); break;
        }


    }
}




    // namespace engine
    // {
    //     Application::Application(const AppSettings& settings)
    //         :m_Settings(settings)
    //     {
    //
    //         //Default Engine Load // Later maybe last stable version
    //         //Made to load and activate all of the nessesary game systems like File systems ect.
    //         //SO that the later processes can change and setup the correct paramiters from files
    //         //This was done to prevent Engine from crashing endlessly.
    //         //The system will try to load and test the correctness of loaded from files version of the game engine.
    //         //TODO read this and do certain things
    //         ////
    //         //Main Reason:
    //         //You are incapable of loading a game confing without elready working file system.
    //         //In addition it adds stability
    //         //-------------------------------------------
    //         //Modeles That are being setup:
    //         Platform::Init();
    //         ////TODO DEAL WITH THIS debugtools::Logger
    //         //
    //         //m_AssetManager = std::make_unique<AssetManager>(); // plus other managers
    //         //backends::RendererAPI::SetAPI(backends::RendererAPIType::OpenGL);// later will be deleted // TODO// it will be put as one of the managers
    //         //
    //         //
    //         //-------------------------------------------
    //
    //
    //
    //
    //         m_SystemManager = std::make_unique<engine::SystemManager>();
    //         auto r = m_SystemManager->RegisterSystem<engine::LoggerSystem>();
    //
    //
    //         //s
    //         //m_SystemManager->RegisterSystem<engine::LoggerSystem>();
    //
    //         // The IDE might handle this much better
    //         //auto manager = std::move(m_SystemManager);
    //         //uint32_t a = m_SystemManager->RegisterSystem<engine::ddd>();
    //         //m_SystemManager->RegisterSystem<engine::PlatformSystem>();
    //
    //        // auto h = m_SystemManager->GetSystem<engine::LoggerSystem>();
    //        // h->AddInfo("gggg");
    //         //h->AddInfo("dd");
    //         //h->AddWarning("gggg");
    //        // h->AddInfo("gggg");
    //        // h->AddError("gggg");
    //
    //
    //        // Result result = engine::EngineStartup::Init();//push THE REGISTRY
    //         engine::EngineStartup engine_startup{};
    //         Result result = engine_startup.Init(*m_SystemManager);
    //
    //        // auto h = m_SystemManager->GetSystem<engine::LoggerSystem>();
    //         //h->AddInfo("gggg");
    //
    //         //TODO check int
    //         //-------------------------------------------
    //
    //
    //
    //
    //         //m_SystemManager->GetSystem<>()
    //
    //
    //         DT_INFO("Application Init");
    // 		////TODO DEAL WITH THIS debugtools::Logger::Log(debugtools::LogLevel::Info, "Application Init");
    //         //----------------------------------------------------------------------------------
    //
    //         m_MainWindow = std::unique_ptr<IWindow>(
    //             IWindow::Create(
    //                 m_Settings.GetWindowConfiguration().GetTitle(),
    //                 m_Settings.GetWindowConfiguration().GetWindowWidth(),
    //                 m_Settings.GetWindowConfiguration().GetWindowHeight()));
    //
    //         //----------------------------------------------------------------------------------
    //
    //
    //
    //         //TODO app more windows
    //
    // 		//Create the asset manager
    // 		//m_AssetManager = std::make_unique<AssetManager>();
    //         m_MainWindow->MakeContextCurrent();
    //
    //
    //
    // 		 //TODO add this to the settings later
    //         // INIT RENDERER ONCE
    //
    //         //Setting the Graphic API for the entire project.
    // 		backends::RendererAPI::SetAPI(backends::RendererAPIType::OpenGL);
    //
    // 		//Creating a renderer for the aplication, this will be used for all rendering operations in the game and debug tools
    // 		m_Renderer = std::unique_ptr<Renderer>(Renderer::Create());
    //         m_Renderer->Init();
    //
    //
    //         //TODO deal with this crap
    //         //m_MainWindow->AddResizeListener([this](int w, int h)
    //         //    {
    // //
    //         //        m_Renderer->OnResize(w, h);
    //         //    });
    //
    //
    //
    /// engine::DebugInput::Init(m_MainWindow->GetNativeWindow()); //KEY HANDLER
    //
    //
    // 		//todo 3 m_AssetManager->GetShaderManager().Add(engine::ShaderTypeID::Basic);
    //
    //
    //         //m_Rot_Cube = std::make_unique<Rot_Cube>();
    //         //m_Rot_Cube->Init(*m_AssetManager);
    //      }
    //
    //     Application::~Application()
    //     {
    //         //TODO
    //         //deleating stuff from here first vector with all of the unique pointers
    //
    //         m_SystemManager->ShutdownAll();
    //
    //         m_MainWindow.reset();
    //
    //         engine::Platform::Shutdown();
    //     }
    //
    //
    //
    //     void Application::Run()
    //     {
    //
    //
    // ///m_Triangle.reset();//TODO
    //         ///AFTER BULLSHIT
    //         OnInit();
    //         //m_SystemManager->GetSystem<engine::LoggerSystem>()->OnInit();
    //
    //         auto k_logger = m_SystemManager->GetSystem<engine::LoggerSystem>();
    //
    //
    //         while (m_EngineRunning && !m_MainWindow->ShouldClose())
    //         {
    //
    //             // =========================
    //             // INPUT
    //             // =========================
    //             m_MainWindow->PollEvents();
    //             //  update game logic
    //             OnUpdate(deltaTime);
    //
    //             m_MainWindow->MakeContextCurrent();
    //
    //            //m_Renderer->BeginFrame();
    //            //OnRender(*m_Renderer); //My Voxel Game
    //
    //              //
    //
    //
    //             //m_Rot_Cube->AdditionalData(crap);
    //             //m_Rot_Cube->Draw(*m_Renderer);
    //             //m_Triangle->Draw(*m_Renderer);
    //
    //             m_Renderer->EndFrame();
    //
    //
    //             m_SystemManager->UpdateAll(1);//Todo Later
    //             //temp
    //             //todo 3
    // //------------------------------------------------------------------------------------------------
    //            // for (int key : engine::DebugInput::GetPressedKeys())
    //            // {
    //            //     std::cout << "Key: " << key << "\n";
    //            //     switch (key)
    //            //     {
    //            //     case 83:
    //            //         crap -= 0.01f;
    //            //         break;
    // //
    //            //     case 87:

    //            //         crap += 0.01f;
    //            //         break;
    //            //     default:
    //            //         break;
    //            //     }
    //            //     std::cout << "F: " << crap << "\n";
    //            // }
    // //
    //            // for (int key : engine::DebugInput::GetPressedMouseButtons())
    //            // {
    //            //     k_logger->AddInfo("MouseKey: ",key);
    //            //     //std::cout << "MouseKey: " << key << "\n";
    //            // }
    // //------------------------------------------------------------------------------------------------
    //             //debugtools::TimerManager::Instance().Stop();
    // 			//TEMP till I got console tool working //TODO
    //             //todo 3
    //
    //         //End Of the Engine while() loop
    //         }
    //
    //         if (!m_EngineRunning || m_MainWindow->ShouldClose())
    //         {
    //             //OnShutdown();
    //         }
    //         if (m_MainWindow->ShouldClose())
    //         {
    //             std::cout << "exitddddddddddddddddddddddddd" << std::endl;
    //         }
    //
    //
    //
    //     }
    // }}
