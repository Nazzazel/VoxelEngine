//Engine
#include "Engine/Core/application.hpp"
#include <GLFW/glfw3.h>
#include <Platform/Input/Debug/debug_input.hpp>

//#include <GLFW/glfw3.h>


namespace engine
{
    Application::Application(AppSettings& settings)
    {
        engine::Platform::Init();
		debugtools::Logger::Log(debugtools::LogLevel::Info, "Application Init");
        //----------------------------------------------------------------------------------
        m_GameWindow = std::unique_ptr<Window>(
            Window::Create(
                "VoxelGame",
                1280,
                720));
        //----------------------------------------------------------------------------------
        //m_AdditionalWindow = std::unique_ptr<Window>(Window::Create("Additional Window", 1280, 720, m_GameWindow.get()));
        //TODO app more windows

        //----------------------------------------------------------------------------------
        //m_AlfaConsoleWindow = std::unique_ptr<Window>(Window::CreateSpecialisedWindow(
        // m_AlfaConsoleWindow = std::unique_ptr<Window>(Window::Create(
        //     "Console Window",
        //     1280, 720,
        //     //Window::WindowType::Console,
        //     m_GameWindow.get()));
        //----------------------------------------------------------------------------------


		//Create the asset manager
		m_AssetManager = std::make_unique<AssetManager>();
        m_GameWindow->MakeContextCurrent();



		 //TODO add this to the settings later
        // INIT RENDERER ONCE

        //m_Renderer = std::unique_ptr<Renderer>(Renderer::Create());
        
        //Setting the Graphic API for the entire project.
		backends::RendererAPI::SetAPI(backends::RendererAPIType::OpenGL);

		//Creating a renderer for the aplication, this will be used for all rendering operations in the game and debug tools
		m_Renderer = std::unique_ptr<Renderer>(Renderer::Create());
        m_Renderer->Init();

        
        //int w, h;
        //glfwGetFramebufferSize(m_GameWindow->GetNativeWindow(), &w, &h);
        //m_Renderer->OnResize(w, h);
        ////  HERE is the correct place
        //m_GameWindow->OnResize = [&](int w, int h)
        //{
        //        
        //    //glfwGetFramebufferSize(glfwGetCurrentContext(), &w, &h);
        //    m_Renderer->OnResize(w, h);
        //};


        //TODO deal with this crap
        m_GameWindow->AddResizeListener([this](int w, int h)
            {
                m_Renderer->OnResize(w, h);
            });



        engine::DebugInput::Init(m_GameWindow->GetNativeWindow());
        //std::unique_ptr<DebugInput> m_DebugInput = std::make_unique<DebugInput>();



		//I DONT WANT TO DO THIS.//GameShader::BindAssetManager(&GetAssetManager());
		//std::unique_ptr<engine::GameShader> shader = engine::GameShader::Create(engine::ShaderTypeID::Basic);
       
        
        // auto shader = AssetManager::LoadShader("Res/Assets/Shaders/Basic");
        
		m_AssetManager->GetShaderManager().Add(engine::ShaderTypeID::Basic);

        //m_AssetManager::GetShaderManager().Add(engine::ShaderTypeID::Basic);
        //
		//AssetManager::GetShaderManager()
        //    .Get(engine::ShaderTypeID::Basic);

		//m_AssetManager->GetExecutableDir();

        //std::cout << m_AssetManager->GetAssetRoot() << std::endl;
		//m_AssetManager.


        m_Triangle = std::make_unique<Triangle>();
        m_Triangle->Init(*m_AssetManager);

        m_Rot_Cube = std::make_unique<Rot_Cube>();
        m_Rot_Cube->Init(*m_AssetManager);

        //shader->Bind();

		//if (!shader)
		//{
		//	debugtools::Logger::Log(debugtools::LogLevel::Error, "Failed to create shader");
		//}
        //else
        //{
		//	debugtools::Logger::Log(debugtools::LogLevel::Info, "Shader created successfully");
		//	//shader->Bind();
		//	//shader->SetInt("u_Color", 1);
		//	//shader->Unbind();
		//	//debugtools::Logger::Log(debugtools::LogLevel::Info, "Shader operations completed successfully");
        //}
        //
        //
        // OTHER WINDOWS (SHARED CONTEXT)
        //m_DebugMenuWindow = std::unique_ptr<Window>(
        //    Window::Create("Debug Tools",   800, 600, m_GameWindow.get())
        //);
        //m_Renderer->Init();
        //
        //m_ConsoleWindow = std::unique_ptr<Window>(
        //    Window::Create("Console",       800, 600, m_GameWindow.get())
        //);
        //m_Renderer->Init();
        //
        //
        //DebugTools* dbg = DebugTools::GetInstance();
        //
        // DEBUG TOOLS
        //m_ToolManager = std::make_unique<debugtools::ToolManager>();
        //
        // REGISTER CONSOLE TOOL
        //m_ToolManager->RegisterTool(std::make_shared<debugtools::ConsoleTool>());

     }

    Application::~Application()
    {
        engine::Platform::Shutdown();
    }



    void Application::Run()
    {

        using clock = std::chrono::high_resolution_clock;
        auto lastTime = clock::now();

        //float fpsTimer = 0.0f;
        //int frameCount = 0;
        //float fps = 0.0f;


        const int SAMPLE_SIZE = 30;

        std::array<float, SAMPLE_SIZE> frameTimes{};

        std::string title = "Game";

        int frameIndex = 0;
        int frameCountSamples = 0;
        float totalFrameTime = 0.0f;

        float fps = 0.0f;
        float logTimer = 0.0f; // how often you print (e.g. 0.2s = 5 Hz)

        std::string s = "Main Loop Timer";

        debugtools::TimerManager::Instance().AddTimer(s);
        debugtools::TimerManager::Instance().SetCurrent(s);
        //debugtools::TimerManager::Instance().DebugMode(true);

        //debugtools::TimerManager::CurrentTime();
        while (m_Running && !m_GameWindow->ShouldClose())
        {

            //debugtools::TimerManager::Instance().Start();
            //{

                // =========================
                // TIME
                // =========================
                auto currentTime = clock::now();
                deltaTime = std::chrono::duration<float>(currentTime - lastTime).count();
                lastTime = currentTime;
                
                // =========================
                // FPS CALCULATION
                // =========================
                if (frameCountSamples == SAMPLE_SIZE)
                {
                    totalFrameTime -= frameTimes[frameIndex];
                }
                else
                {
                    frameCountSamples++;
                }

                // Add new sample
                frameTimes[frameIndex] = deltaTime;
                totalFrameTime += deltaTime;

                // Move circular index
                frameIndex = (frameIndex + 1) % SAMPLE_SIZE;

                // Compute FPS
                float avgFrameTime = totalFrameTime / frameCountSamples;
                fps = 1.0f / avgFrameTime;

                // Log at ~5 Hz (adjust if you want 10Hz / 30Hz)
                logTimer += deltaTime;
                if (logTimer >= 0.1f) // 0.2s = 5 times per second
                {
                    logTimer = 0.0f;

                    //debugtools::Logger::Log(debugtools::LogLevel::Info,
                    //    "FPS: " + std::to_string(fps) +
                    //    " | ms/frame: " + std::to_string(avgFrameTime * 1000.0f)
                    //);
                    title = "FPS: " + std::to_string(fps);
                    m_GameWindow->SetName(title);
                }
                //titel = "FPS: " + std::to_string(fps);
                //m_GameWindow->SetName(titel);

                

               
            //}

               


            // =========================
            // INPUT
            // =========================
            m_GameWindow->PollEvents();
            //m_DebugMenuWindow->PollEvents();
            //m_ConsoleWindow->PollEvents();


            //  update game logic
            OnUpdate(deltaTime);
            //m_ToolManager->Update(deltaTime);
            // 
            // RenderUI
            //TODO tool handler 
            //toolManager.Update(dt);
            //toolManager.RenderUI();

            m_GameWindow->MakeContextCurrent();

            m_Renderer->BeginFrame();
            OnRender(*m_Renderer); //My Voxel Game


            //m_Rot_Cube->AdditionalData(crap);
            //m_Rot_Cube->Draw(*m_Renderer);
            //m_Triangle->Draw(*m_Renderer);

            m_Renderer->EndFrame();           
            


            //m_DebugMenuWindow->MakeContextCurrent();
            //m_Renderer->BeginFrame();
            //m_Triangle->Draw(*m_Renderer);
            //m_ToolManager->RenderUI();
            //m_Renderer->EndFrame();           
            //
            //
            //
            //
            //m_ConsoleWindow->MakeContextCurrent();
            //m_Renderer->BeginFrame();
            //m_ToolManager->RenderUI();
            //m_Renderer->EndFrame();

            //for (int )



            for (int key : engine::DebugInput::GetPressedKeys())
            {
                std::cout << "Key: " << key << "\n";
                switch (key)
                {
                case 83:
                    crap -= 0.01f;
                    break;

                case 87:
                    crap += 0.01f;
                    break;
                default:
                    break;
                }
                std::cout << "F: " << crap << "\n";
            }

            for (int key : engine::DebugInput::GetPressedMouseButtons())
            {
                std::cout << "MouseKey: " << key << "\n";
            }

            //debugtools::TimerManager::Instance().Stop();
			//TEMP till I got console tool working //TODO
            const auto& logs = debugtools::Logger::GetMessages();

            for (const auto& msg : logs)
            {
                std::cout << msg.time << msg.level << msg.text << "\n";
            }
            debugtools::Logger::Clear();

        }
    }
}