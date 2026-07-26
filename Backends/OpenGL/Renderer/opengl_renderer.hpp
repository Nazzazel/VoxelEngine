#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Core/Systems/Renderer/IRenderer/IRenderer.hpp"

namespace backends
{
    class OpenGLRenderer : public engine::IRenderer
    {
    public:
        OpenGLRenderer();
        ~OpenGLRenderer();

        engine::Result Init() override;
        void BeginFrame() override;
        void EndFrame() override;

        void OnResize(int width, int height) override;

		//void DrawTriangle() override; //TODO remove this later

        void SetSceneData(const engine::SceneData& scene_data);

        void Submit(const engine::DrawCommand& command) override;



		void DrawIndexed(uint32_t indexCount) override;


    private:
        glm::mat4 m_ProjectionMatrix;

        std::vector<engine::DrawCommand> m_DrawCommands;

        int all_indexes;
        engine::SceneData m_SceneData;


        //int location;
        //float increment = 0.0f;
        //float r = 0.0f;
    };
}
