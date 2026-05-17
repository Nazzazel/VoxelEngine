#pragma once


#include <memory>
//#include <Engine/Res/Assets/Shaders/ShadersLib/shader_library.hpp>
#include "Engine/RenderingAPI/Buffers/vertex_array.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


namespace engine
{
    class Renderer
    {
    public:


        virtual ~Renderer() = default;
        
        virtual bool Init() = 0;
        virtual void BeginFrame() = 0;
        virtual void EndFrame() = 0;

        virtual void OnResize(int width, int height) = 0;
        virtual const glm::mat4& GetProjection() const = 0;


		//virtual void DrawTriangle() = 0; //TODO remove this later
        virtual void DrawIndexed(const std::unique_ptr<VertexArray>& vao) = 0;

        static std::unique_ptr<Renderer> Create();
	protected:
		//std::unique_ptr<engine::ShaderLibrary> m_ShaderLibrary; //TODO remove this later




    };
}