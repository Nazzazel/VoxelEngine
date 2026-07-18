#pragma once
#include <glad/glad.h>
#include <iostream>

#include "DebugTools/Core/Logger/logger.hpp"


#ifdef _DEBUG
#define ASSERT(x) if (!(x)) __debugbreak(); 
#define GLCall(x) do { \
GLClearError(); \
x; \
ASSERT(GLLogCall(#x, __FILE__, __LINE__));\
}while(0)

#else
#define ASSERT(x) ((void)0)
#define GLCall(x) x
#endif

static void GLClearError()
{
    while (glGetError() != GL_NO_ERROR);
}

static bool GLLogCall(const char* function, const char* file, int line)
{
    while (GLenum error = glGetError())
    {
        debugtools::Logger::Log(debugtools::LogLevel::Error,
            "[OpenGL Error] (" + std::to_string(error) +
            ") | Function -> " + function +
            " | File -> " + file +
            " | Line -> " + std::to_string(line)
        );
        std::cout << "[OpenGL Error] (" << error << ") | Function -> " << function << " | File -> " << file << " | Line -> " << line << std::endl;
        return false;
    }
    return true;
}