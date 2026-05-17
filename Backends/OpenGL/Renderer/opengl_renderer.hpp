#pragma once
#include "Engine/RenderingAPI/renderer/renderer.hpp"
#include "Engine/RenderingAPI/Buffers/vertex_array.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace backends
{
    class OpenGLRenderer : public engine::Renderer
    {
    public:
        OpenGLRenderer();
        ~OpenGLRenderer();

        bool Init() override;
        void BeginFrame() override;
        void EndFrame() override;

        void OnResize(int width, int height) override;

		//void DrawTriangle() override; //TODO remove this later

        const glm::mat4& GetProjection() const override;

		void DrawIndexed(const std::unique_ptr<engine::VertexArray>& vao) override;

    private:

        glm::mat4 m_Projection;
        //int location;
        //float increment = 0.0f;
        //float r = 0.0f;
    };
}