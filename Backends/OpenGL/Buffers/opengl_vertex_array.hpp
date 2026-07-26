#pragma once
#include "Engine/Systems/Renderer/Buffers/IVertexArray.hpp"
#include "Engine/Systems/Renderer/Buffers/IIndexBuffer.hpp"

#include <vector>

#include "thirdparty/glfw/src/internal.h"

namespace backends
{

    class OpenGLVertexArray : public engine::IVertexArray
    {
    public:
        OpenGLVertexArray();
        ~OpenGLVertexArray();

        void Bind() const override;
        void Unbind() const override;

        void AddVertexBuffer(std::unique_ptr<engine::IVertexBuffer> vb) override;
		void SetIndexBuffer(std::unique_ptr<engine::IIndexBuffer> ibo) override;

        unsigned int GetIndexCount() const;


    private:
        static GLenum ShaderDataTypeToOpenGLBaseType(engine::ShaderDataType);

        unsigned int m_VertexArrayID;

        std::vector<std::unique_ptr<engine::IVertexBuffer>> m_VertexBuffers;
        std::unique_ptr<engine::IIndexBuffer> m_IndexBuffer;

    };


}
