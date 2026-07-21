//
// Created by nazzazel on 21.07.2026.
//
#include "PlatformSystem.hpp"

#include "Core/Manager/SystemManager.hpp"
#include "GLFW/glfw3.h"

namespace engine
{
    Result PlatformSystem::OnInit() // Forced
    {
        m_SystemManager = this->GetSystemManager();

        m_Logger = m_SystemManager->GetSystem<LoggerSystem>();

        if (!m_SystemManager)
        {
            return SYSTEM_RESULT(SystemManagerNotSet,Error);//todo
        }

        m_Logger->AddInfo("Platform Initiation ");


        if (Result result = GLFWCheck(); result.IsFailure()) return result; //Creates a var when it is needed /C++17
        m_Logger->AddInfo("Checked GLFW");
        if (Result result = HintSetup(); result.IsFailure()) return result; //Creates a var when it is needed /C++17
        m_Logger->AddInfo("Setup GLFW Hint");


        // m_LoggerSystemPtr = m_SystemManager->GetSystem<engine::LoggerSystem>();
        // if (!m_LoggerSystemPtr)
        // {
        //     return 2;//todo
        // }


        //engine::Platform::Init();
        return {};
    }



    Result PlatformSystem::OnUpdate(float dt)
    {
        return {};
    }
    Result PlatformSystem::OnShutdown()
    {
        glfwTerminate();
        return {};
    }

    Result PlatformSystem::GLFWCheck()
    {

        if (!glfwInit())
        {
           m_Logger->AddFatal("GLFW Initialization Failed");
            // Handle initialization failure (e.g., throw an exception, exit the application, etc.)

            return PLATFORM_RESULT(GLFWInitiationFail,Fatal);
            std::exit(EXIT_FAILURE);//TODO
        }

        return Result::SUCCESS();
    }

    Result PlatformSystem::HintSetup()
    {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        #ifdef _DEBUG
                glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
        #endif

        #ifdef __APPLE__
                glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        #endif

        return Result::SUCCESS();
    }



} // engine