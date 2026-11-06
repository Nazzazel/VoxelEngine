//
// Created by nazzazel on 25.07.2026.
//


#pragma once
#include "Core/Systems/Assets/Shaders/IShader.hpp"
#include "Systems/Renderer/Buffers/IBufferLayout.hpp"
#include "Systems/Renderer/Buffers/IVertexArray.hpp"



#include "Systems/Renderer/Texture/OpenGLTexture.hpp"


namespace engine
{
    class DrawComponents
    {};

    class Material {
    public:
       // Material(std::shared_ptr<IShader> shader, std::shared_ptr<engine::OpenGLTexture> texture = nullptr) :
        Material(engine::IShader* shader, std::shared_ptr<engine::OpenGLTexture> texture = nullptr) :
        m_Texture(texture),m_Shader(shader) {}
        //Material(IShader* shader) :m_Shader(shader) {}
        ~Material() = default;

        void Bind() {
            if (m_Shader) {
                m_Shader->Bind();
                // Automatically push all stored uniform values to the shader upon binding
                for (const auto& [name, val] : m_Floats)   m_Shader->SetFloat(name, val);
                for (const auto& [name, val] : m_Vec4s)    m_Shader->SetFloat4(name, val.r, val.g, val.b, val.a);
                for (const auto& [name, val] : m_Mat4s)    m_Shader->SetMat4(name, val);




                m_Texture->Bind();
                m_Texture->SetUniforms(m_Shader,"tex0",0);//todo later
                //m_Texture->SetUniforms(m_Shader,"textTexture",0);//todo later
               //if (m_Texture!=nullptr)
               //{
               //m_Texture->Bind();
               //m_Texture->SetUniforms(m_Shader,"tex0",0);//todo later
               //}
            }


        }

       // engine::OpenGLTexture& m_Texture;



        IShader* GetShader() const { return m_Shader; }
        void SetShader(IShader* shader) { m_Shader = shader; }


        // Uniform Setters (stores them to be applied when Bind() is called)
        void SetFloat(const std::string& name, float value) { m_Floats[name] = value; }
        void SetFloat4(const std::string& name, const glm::vec4& value) { m_Vec4s[name] = value; }
        void SetMat4(const std::string& name, const glm::mat4& value) { m_Mat4s[name] = value; }

    private:
        //std::shared_ptr<IShader> m_Shader = nullptr;
        engine::IShader* m_Shader = nullptr;

        // Caching uniform values so the material remembers its state
        std::unordered_map<std::string, float> m_Floats;
        std::unordered_map<std::string, glm::vec4> m_Vec4s;
        std::unordered_map<std::string, glm::mat4> m_Mat4s;
        std::shared_ptr<engine::OpenGLTexture> m_Texture; // Now a pointer!
      //  engine::OpenGLTexture& m_Texture;

    };

    class Mesh {
    public:
        Mesh(
            float* vertices, // a list of "points" that contain information about the "point"; ex: relative position of an object; color coordinates; texture coordinates
            uint32_t vertexSize, // size of a list containing vertices
            const BufferLayout& layout, //THe way information is structured
            uint32_t* indices, //all of the indices // indice - a pattern of order in which vertices are drawn
            uint32_t indexCount //the size of the indices
            ){
            m_VertexArray = IVertexArray::Create();

            auto vertexBuffer = IVertexBuffer::Create(vertices, vertexSize);
            vertexBuffer->SetLayout(layout);
            m_VertexBuffer = vertexBuffer.get();
            m_VertexArray->AddVertexBuffer(std::move(vertexBuffer));

            auto indexBuffer = IIndexBuffer::Create(indices, indexCount);
            m_VertexArray->SetIndexBuffer(std::move(indexBuffer));
        }



        ~Mesh() = default;

        // Add this method to update vertex data dynamically
        void UpdateVertices(const void* data, uint32_t size) {
            if (!m_VertexBuffer) {
                std::cerr << "[Error] Attempted to update vertices on a null VertexBuffer!\n";
                return;
            }
            m_VertexBuffer->Bind();
            m_VertexBuffer->UpdateData(data, size);
        }

        const std::shared_ptr<IVertexArray>& GetVertexArray() const { return m_VertexArray; }
        uint32_t GetIndexCount() const { return m_VertexArray->GetIndexCount(); }

    private:
        std::shared_ptr<IVertexArray> m_VertexArray;
        IVertexBuffer* m_VertexBuffer;
    };


} // engine
