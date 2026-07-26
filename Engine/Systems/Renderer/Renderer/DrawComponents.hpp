//
// Created by nazzazel on 25.07.2026.
//


#pragma once
#include "Core/Systems/Assets/Shaders/IShader.hpp"
#include "Systems/Renderer/Buffers/IBufferLayout.hpp"
#include "Systems/Renderer/Buffers/IVertexArray.hpp"


namespace engine
{
    class DrawComponents
    {};

    class Material {
    public:
        Material(IShader* shader) : m_Shader(shader) {}
        ~Material() = default;

        void Bind() {
            if (m_Shader) {
                m_Shader->Bind();
                // Automatically push all stored uniform values to the shader upon binding
                for (const auto& [name, val] : m_Floats)   m_Shader->SetFloat(name, val);
                for (const auto& [name, val] : m_Vec4s)    m_Shader->SetFloat4(name, val.r, val.g, val.b, val.a);
                for (const auto& [name, val] : m_Mat4s)    m_Shader->SetMat4(name, val);
            }
        }

        IShader* GetShader() const { return m_Shader; }
        void SetShader(IShader* shader) { m_Shader = shader; }

        // Uniform Setters (stores them to be applied when Bind() is called)
        void SetFloat(const std::string& name, float value) { m_Floats[name] = value; }
        void SetFloat4(const std::string& name, const glm::vec4& value) { m_Vec4s[name] = value; }
        void SetMat4(const std::string& name, const glm::mat4& value) { m_Mat4s[name] = value; }

    private:
        IShader* m_Shader = nullptr;

        // Caching uniform values so the material remembers its state
        std::unordered_map<std::string, float> m_Floats;
        std::unordered_map<std::string, glm::vec4> m_Vec4s;
        std::unordered_map<std::string, glm::mat4> m_Mat4s;
    };

    class Mesh {
    public:
        Mesh(float* vertices, uint32_t vertexSize, const BufferLayout& layout, uint32_t* indices, uint32_t indexCount) {
            m_VertexArray = IVertexArray::Create();

            auto vertexBuffer = IVertexBuffer::Create(vertices, vertexSize);
            vertexBuffer->SetLayout(layout);
            m_VertexArray->AddVertexBuffer(std::move(vertexBuffer));

            auto indexBuffer = IIndexBuffer::Create(indices, indexCount);
            m_VertexArray->SetIndexBuffer(std::move(indexBuffer));
        }

        ~Mesh() = default;

        const std::shared_ptr<IVertexArray>& GetVertexArray() const { return m_VertexArray; }
        uint32_t GetIndexCount() const { return m_VertexArray->GetIndexCount(); }

    private:
        std::shared_ptr<IVertexArray> m_VertexArray;
    };


} // engine
