#pragma once
#pragma once
#include <glad/glad.h>
#include <iostream>
#include <string>

namespace gl
{
    inline bool IsReady()
    {
        return glGetError != nullptr;
    }

    inline void ClearErrors()
    {
        if (!IsReady()) return;

        while (glGetError() != GL_NO_ERROR);
    }

    inline bool LogError(const char* function, const char* file, int line)
    {
        if (!IsReady())
        {
            std::cerr << "[OpenGL Error] GLAD not initialized!\n";
            return false;
        }

        bool ok = true;

        while (GLenum error = glGetError())
        {
            std::cerr
                << "[OpenGL Error] (" << error << ") "
                << function << " | "
                << file << ":" << line
                << std::endl;

            ok = false;
        }

        return ok;
    }


}