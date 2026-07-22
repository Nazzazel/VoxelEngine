#pragma once
#include "Engine/Renderer/Buffers/vertex_array.hpp"
#include "Engine/Renderer/Buffers/index_buffer.hpp"

#include <vector>

namespace backends
{

    class OpenGLVertexArray : public engine::VertexArray
    {
    public:
        OpenGLVertexArray();
        ~OpenGLVertexArray();

        void Bind() const override;
        void Unbind() const override;

        void AddVertexBuffer(std::unique_ptr<engine::VertexBuffer> vb) override;
		void SetIndexBuffer(std::unique_ptr<engine::IndexBuffer> ibo) override;

        unsigned int GetIndexCount() const;


    private:
        unsigned int m_VertexArrayID;

        std::vector<std::unique_ptr<engine::VertexBuffer>> m_VertexBuffers;
        std::unique_ptr<engine::IndexBuffer> m_IndexBuffer;

    };


}