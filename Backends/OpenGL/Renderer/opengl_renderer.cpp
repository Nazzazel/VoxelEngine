#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include <fstream>
#include <string>
#include <sstream>

#include "opengl_renderer.hpp"



//DebugTools
#include "Backends/OpenGL/Debug/GLScope.hpp"
#include "Systems/Renderer/Renderer/DrawComponents.hpp"


#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>


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

    //TODO DEAL WITH THIS //TODO DEAL WITH THIS debugtools::Logger::Log(debugtools::LogLevel::Error, msg);

    
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
        //TODO DEAL WITH THIS //TODO DEAL WITH THIS debugtools::Logger::Log(debugtools::LogLevel::Info, "OpenGL Renderer Created");
        int nrAttributes;
        glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
        std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes << std::endl;
    }

    OpenGLRenderer::~OpenGLRenderer()
    {
        
        //TODO DEAL WITH THIS //TODO DEAL WITH THIS debugtools::Logger::Log(debugtools::LogLevel::Info, "OpenGL Renderer Destroyed");
    }

    engine::Result OpenGLRenderer::Init()
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
        OnResize(width, height);

        // Basic OpenGL state
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);

        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK);

        // Clear color (background)
        glClearColor(0.1f, 0.1f, 0.15f, 1.0f);

        // TODO: load shaders, textures, buffers



        {
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


        }




        return {};
    }
    
    void OpenGLRenderer::BeginFrame()
    {
        GL_SCOPE();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    }



    void OpenGLRenderer::EndFrame()
    {
           for (const auto& cmd : m_DrawCommands) {
               if (!cmd.mesh || !cmd.material) continue;

               // 1. Bind material (binds shader and uploads its custom uniforms)
               cmd.material->Bind();

               // 2. Upload per-draw matrices to the active shader
               engine::IShader* shader = cmd.material->GetShader();


               if (shader) {
                   shader->SetMat4("u_Model", cmd.modelMatrix);
                   shader->SetMat4("u_View", m_SceneData.viewMatrix);
                   shader->SetMat4("u_Projection", m_SceneData.projectionMatrix);
               }

               // 3. Bind geometry and draw
               cmd.mesh->GetVertexArray()->Bind();
               DrawIndexed(cmd.mesh->GetIndexCount(),2);
           }

            //if (!command.shader || !command.vertexArray) continue;
//
            //command.shader->Bind();
//
            //// Send global camera/projection matrix and local model matrix
            //command.shader->SetMat4("u_Projection", m_Projection);
            //command.shader->SetMat4("u_Model", command.modelMatrix);
            //command.shader->SetFloat("u_X", command.customFloat); // If you're passing your custom float
//
            //// Bind vertex array and issue draw call
            //command.vertexArray->Bind();
            //DrawIndexed(command.indexCount);

        m_DrawCommands.clear();

       // std::cout << "Cubes        : " <<m_DrawCommands.size()   << std::endl;
       // std::cout << "Cubes Points : " <<m_DrawCommands.size()*8 << std::endl;


        glfwSwapBuffers(glfwGetCurrentContext());
    }

    void OpenGLRenderer::OnResize(int width, int height)
    {
        // Fix: If minimized or invalid size, skip matrix updates entirely
        if (width == 0 || height == 0)
        {
            return;
        }

        GL_SCOPE();
        glViewport(0, 0, width, height);
    
        //m_Projection = glm::ortho(
        //    0.0f, (float)width,
        //    0.0f, (float)height
        //);

        // Create a 3D perspective field of view instead of 2D screen pixels
        m_aspectRatio = (float)width / (float)height;
        //m_SceneData.projectionMatrix = glm::perspective(glm::radians(45.0f), m_aspectRatio, 0.1f, 100.0f);

    }

    float OpenGLRenderer::GetAspectRatio()
    {
        return m_aspectRatio;
    }

    void OpenGLRenderer::SetSceneData(const engine::SceneData& scene_data)
    {
        m_SceneData = scene_data;

        //std::string matrixString = glm::to_string(m_SceneData.viewMatrix);
        //std::cout << "2View Matrix   : " << matrixString << std::endl;

       // std::cout << "---------------------------------------------------------------";
       // std::cout << m_SceneData.viewMatrix << std::endl;
// std::cout << "---------------------------------------------------------------";




        //m_SceneData.projectionMatrix = scene_data.projectionMatrix;
        //m_SceneData.cameraPosition   = scene_data.cameraPosition;
        //m_SceneData.viewMatrix       = scene_data.viewMatrix;

    }

    void OpenGLRenderer::Submit(const engine::DrawCommand& command)
    {
        m_DrawCommands.push_back(command);
    }

    void OpenGLRenderer::DrawIndexed(uint32_t indexCount,int8_t mode)
    {
        GL_SCOPE();
        switch (mode)
        {
        case 0:glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);break;
        case 1:glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); break;
        case 2:glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); break;
        }

        //GL_SCOPE();
		//vao->Bind();

       // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        // Optional: Change color uniform to black or contrast color for lines
        // shader->SetInt("u_RenderMode", 1);
        // glLineWidth(1.5f); // Note: glLineWidth > 1.0 has limited driver support in core profile
        //glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, nullptr);

		//unsigned int count = vao->GetIndexBuffer()->GetCount();
        //unsigned int count = vao->GetIndexCount();
        //glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
        // Optional: Make points larger so they are clearly visible
        //glPointSize(6.0f);

        glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, nullptr);
    }






}
