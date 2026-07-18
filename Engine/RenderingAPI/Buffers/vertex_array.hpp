#pragma once
#include <memory>

#include "Engine/RenderingAPI/Buffers/vertex_buffer.hpp"
#include "Engine/RenderingAPI/Buffers/index_buffer.hpp"

namespace engine
{
    class VertexBuffer;

    class VertexArray
    {
    public:
        virtual ~VertexArray() = default;

        virtual void Bind()     const = 0;
        virtual void Unbind()   const = 0;

        virtual void AddVertexBuffer(std::unique_ptr<VertexBuffer> vb) = 0;
        virtual void SetIndexBuffer(std::unique_ptr<IndexBuffer> ibo) = 0;

        virtual unsigned int GetIndexCount() const = 0;

        static std::unique_ptr<VertexArray> Create();
    };
}