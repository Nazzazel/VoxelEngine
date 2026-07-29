//
// Created by nazzazel on 28.07.2026.
//


#pragma once
#include "Core/Systems/Assets/AssetSystem.hpp"
#include "Core/Systems/Renderer/IRenderer/IRenderer.hpp"
#include "Core/Systems/Assets/AssetSystem.hpp"
#include "Core/Systems/Renderer/IRenderer/IRenderer.hpp"
#include "Engine/Systems/Renderer/Buffers/IVertexArray.hpp"
#include "Engine/Systems/Renderer/Buffers/IVertexBuffer.hpp"
#include "Engine/Systems/Renderer/Buffers/IIndexBuffer.hpp"

namespace opengltests
{
    class RotatingCube
    {
        public:
        RotatingCube() = default;
        ~RotatingCube();

        void Init(engine::AssetSystem& assets);

        void SetPosition(const glm::vec3& position) { m_Position = position; }
        void Translate(const glm::vec3& offset) { m_Position += offset; }

        void Draw(engine::IRenderer& renderer);


    private:
        std::shared_ptr<engine::Mesh> m_Mesh;
        std::shared_ptr<engine::Material> m_Material;

        engine::IShader* m_shader = nullptr;
        glm::vec3 m_Position = glm::vec3(0.0f);


    };
}
