#pragma once
#include <memory>

#include "Engine/Systems/Renderer/Buffers/IVertexBuffer.hpp"
#include "Engine/Systems/Renderer/Buffers/IIndexBuffer.hpp"

namespace engine
{
    class IVertexBuffer;

    class IVertexArray
    {
    public:
        virtual ~IVertexArray() = default;

        virtual void Bind()     const = 0;
        virtual void Unbind()   const = 0;

        virtual void AddVertexBuffer(std::unique_ptr<IVertexBuffer> vb) = 0;
        virtual void SetIndexBuffer(std::unique_ptr<IIndexBuffer> ibo) = 0;

        virtual unsigned int GetIndexCount() const = 0;

        static std::unique_ptr<IVertexArray> Create();
    };
}