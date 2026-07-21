#include "platform.hpp"
#include <GLFW/glfw3.h>


namespace engine
{
    void Platform::Init()
    {

		debugtools::Logger::Log(debugtools::LogLevel::Info,"Platform Init");

        glfwSetErrorCallback([](int error, const char* description)
            {
                std::cerr << "[GLFW ERROR] (" << error << "): " << description << std::endl;
            });

        if (!glfwInit())
        {
			debugtools::Logger::Log(debugtools::LogLevel::Error, "Failed to initialize GLFW");
			// Handle initialization failure (e.g., throw an exception, exit the application, etc.)

			std::exit(EXIT_FAILURE);
        }
        //else 
        //{
        //   
        //    debugtools::Logger::Log(debugtools::LogLevel::Info, "Succesfully initializiated GLFW"); 

        //    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
        //    const GLFWvidmode* mode = glfwGetVideoMode(monitor);

        //    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
        //    

        //    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        //    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
        //    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        //    //glfwWindowHint(GLFW_RED_BITS, mode->redBits);
        //    //glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
        //    //glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
        //    glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

        //    debugtools::Logger::Log(debugtools::LogLevel::Info,
        //        "Succesfully initializiated Colors and refreshrate of the monitor");

        //}

        debugtools::Logger::Log(debugtools::LogLevel::Info, "Successfully initialized GLFW");

        debugtools::Logger::Log(debugtools::LogLevel::Info, "OpenGL context configured");

    }

    void Platform::Shutdown()
    {
        glfwTerminate();
    }
}