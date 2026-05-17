#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include <fstream>
#include <string>
#include <sstream>

#include "opengl_renderer.hpp"



//DebugTools
#include "DebugTools/Core/Logger/logger.hpp"
#include "Backends/OpenGL/Debug/GLScope.hpp"


static void APIENTRY OpenGLDebugCallback(
    GLenum source,
    GLenum type,
    GLuint id,
    GLenum severity,
    GLsizei length,
    const GLchar* message,
    const void* userParam)
{
    std::string severityStr;

    switch (severity)
    {
    case GL_DEBUG_SEVERITY_HIGH:         severityStr = "HIGH"; break;
    case GL_DEBUG_SEVERITY_MEDIUM:       severityStr = "MEDIUM"; break;
    case GL_DEBUG_SEVERITY_LOW:          severityStr = "LOW"; break;
    case GL_DEBUG_SEVERITY_NOTIFICATION: severityStr = "INFO"; break;
    }

    std::string msg = "[OpenGL][" + severityStr + "] " + message;

    debugtools::Logger::Log(debugtools::LogLevel::Error, msg);

    
    if (severity == GL_DEBUG_SEVERITY_HIGH)
    {
#ifdef _DEBUG
        __debugbreak();
#endif
    }
}

namespace backends
{

    OpenGLRenderer::OpenGLRenderer()
    {
		debugtools::Logger::Log(debugtools::LogLevel::Info, "OpenGL Renderer Created");
        int nrAttributes;
        glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
        std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes << std::endl;
    }

    OpenGLRenderer::~OpenGLRenderer()
    {
        
        debugtools::Logger::Log(debugtools::LogLevel::Info, "OpenGL Renderer Destroyed");
    }

    bool OpenGLRenderer::Init()
    {
        
        if (!glfwGetCurrentContext())
        {
            throw std::runtime_error("OpenGL context not available!");
        }

        GL_SCOPE();
        #ifdef _DEBUG
        glEnable(GL_DEBUG_OUTPUT);
        glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
        glDebugMessageCallback(OpenGLDebugCallback, nullptr);

        glDebugMessageControl(
            GL_DONT_CARE,
            GL_DONT_CARE,
            GL_DEBUG_SEVERITY_NOTIFICATION,
            0, nullptr,
            GL_FALSE
        );
        #endif


        // Set viewport (important!)
        int width, height;
        glfwGetFramebufferSize(glfwGetCurrentContext(), &width, &height);
        glViewport(0, 0, width, height);

        // Basic OpenGL state
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);

        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK);

        // Clear color (background)
        glClearColor(0.1f, 0.1f, 0.15f, 1.0f);

        // TODO: load shaders, textures, buffers




        //float positions[]
        //{
        //    -0.5f,  -0.5f,
        //     0.5f,  -0.5f,
        //     0.5f,   0.5f,
        //    -0.5f,   0.5f
        //};
        //
        //unsigned int indices[] = {
        //    0,1,2,
        //    2,3,0
        //};
        //
        //unsigned int buffer;
        //GLCall(glGenBuffers(1, &buffer));
        //GLCall(glBindBuffer(GL_ARRAY_BUFFER, buffer));
        //GLCall(glBufferData(GL_ARRAY_BUFFER, 4 * 2 * sizeof(float), positions, GL_STATIC_DRAW));
        //
        //GLCall(glEnableVertexAttribArray(0));
        //// READ THE dock.gl
        ////(const pointer*) - casting to pointer
        //GLCall(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0));
        //
        //unsigned int ibo;
        //GLCall(glGenBuffers(1, &ibo));
        //GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo));
        //GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW));
        //
        //
        //
        //ShaderProgramSource source = ParseShader("../Engine/Res/shaders/Basic.shader");
        //
        //unsigned int shader = CreateShader(source.VertexSource, source.FragmentSource);
        //GLCall(glUseProgram(shader));
        //
        //GLCall(location = glGetUniformLocation(shader, "u_Color"));
        //ASSERT(location != -1);
        //GLCall(glUniform4f(location, 0.8f, 0.3f, 0.8f, 1.0f));
        //
        //r = 0.0f;
        //increment = 0.05f;




        return true;
    }
    
    void OpenGLRenderer::BeginFrame()
    {
        GL_SCOPE();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    }
    
    void OpenGLRenderer::EndFrame()
    {
        glfwSwapBuffers(glfwGetCurrentContext());
    }

    void OpenGLRenderer::OnResize(int width, int height)
    {
        
        GL_SCOPE();
        glViewport(0, 0, width, height);
    
        m_Projection = glm::ortho(
            0.0f, (float)width,
            0.0f, (float)height
        );

    }

    const glm::mat4& OpenGLRenderer::GetProjection() const
    {
        return m_Projection;
    }

    void OpenGLRenderer::DrawIndexed(const std::unique_ptr<engine::VertexArray>& vao)
    {
        GL_SCOPE();
		vao->Bind();

		//unsigned int count = vao->GetIndexBuffer()->GetCount();
        unsigned int count = vao->GetIndexCount();

        glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, nullptr);

    }






}