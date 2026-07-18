#pragma once
#pragma once
#include "GLDebug.hpp"

#define GL_SCOPE() gl::Scope scope(__FUNCTION__, __FILE__, __LINE__)

namespace gl
{
    class Scope
    {
    public:
        Scope(const char* func, const char* file, int line)
            : m_Func(func), m_File(file), m_Line(line)
        {
            ClearErrors();
        }

        ~Scope()
        {
            LogError(m_Func, m_File, m_Line);
        }

    private:
        const char* m_Func;
        const char* m_File;
        int m_Line;
    };


    /// <summary>
    ///  EEEEEEEEEEEEEEEEEEEEE
    /// GLFunctionScope scope("OpenGLVertexArray::AddVertexBuffer");
    /// </summary>
    class GLFunctionScope
    {
    public:
        GLFunctionScope(std::string name)
            : m_Name(std::move(name))
        {
            gl::ClearErrors();
        }

        ~GLFunctionScope()
        {
            gl::LogError(m_Name.c_str(), __FILE__, __LINE__);
        }

    private:
        std::string m_Name;
    };

}