#include "opengl_vertex_array.hpp"
#include "Engine/RenderingAPI/Buffers/vertex_buffer.hpp"
#include "Engine/RenderingAPI/Buffers/buffer_layout.hpp"
#include <glad/glad.h>

#include "Backends/OpenGL/Debug/GLScope.hpp"




namespace backends
{

    OpenGLVertexArray::OpenGLVertexArray()
    {
        GL_SCOPE();
        glGenVertexArrays(1, &m_VertexArrayID);
    }

    OpenGLVertexArray::~OpenGLVertexArray()
    {
        GL_SCOPE();
        glDeleteVertexArrays(1, &m_VertexArrayID);
    }

    void OpenGLVertexArray::Bind() const
    {
        GL_SCOPE();
        glBindVertexArray(m_VertexArrayID);
    }

    void OpenGLVertexArray::Unbind() const
    {
        GL_SCOPE();
        glBindVertexArray(0);
    }

    void OpenGLVertexArray::AddVertexBuffer(std::unique_ptr<engine::VertexBuffer> vb)
    {
        GL_SCOPE();
        Bind();
        

        //m_VertexBuffers.emplace_back()
            
        const auto& layout = vb->GetLayout();
        //for (layout)
        uint32_t index = 0;

        for (const auto& element : layout.GetElements())
        {
            glEnableVertexAttribArray(index);

            glVertexAttribPointer(
                index,
                GetComponentCount(element.Type),
                GL_FLOAT,
                element.Normalised ? GL_TRUE : GL_FALSE,
                layout.GetStride(),
                (const void*)element.Offset
            );

            index++;
        }




        m_VertexBuffers.push_back(std::move(vb));




        auto& buffer = m_VertexBuffers.back();
        buffer->Bind();




        //std::cout << "SizeVB:" << m_VertexBuffers.size() << "\n";

        // position
        //glEnableVertexAttribArray(0);
        //glVertexAttribPointer(
        //    0,
        //    2,
        //    GL_FLOAT,
        //    GL_FALSE,
        //    5 * sizeof(float),
        //    (void*)0
        //);

        //// color
        //glEnableVertexAttribArray(1);
        //glVertexAttribPointer(
        //    1,
        //    3,
        //    GL_FLOAT,
        //    GL_FALSE,
        //    5 * sizeof(float),
        //    (void*)(2 * sizeof(float))
        //);

        //glVertexAttribPointer(
        //    0,                  // location
        //    3,                  // number of values
        //    GL_FLOAT,           // type
        //    GL_FALSE,           // normalize?
        //    3 * sizeof(float),  // stride
        //    (const void*)0      // offset
        //);
        
        //Element
        //      class 

        
        //glEnableVertexAttribArray(0); //Loacation of the attribute in the shader, aka layout(location = 0) in the vertex shader
        //GLCall(glVertexAttribPointer(//TEMP, just for the triangle test, later we will have to read the layout from the shader and set it up accordingly
        //          0, 
        //          2, 
        //          GL_FLOAT, 
        //          GL_FALSE, 
        //          2 * sizeof(float), 
        //          0));
        // 
        //glVertexAttribPointer( //layout(location = 0) in vec3 aPos; 
        //    0,                  // location
        //    3,                  // vec3
        //    GL_FLOAT,
        //    GL_FALSE,
        //    3 * sizeof(float),
        //    (const void*)0
        //);


    }



    void OpenGLVertexArray::SetIndexBuffer(std::unique_ptr<engine::IndexBuffer> ibo)
    {
        Bind();
        ibo->Bind();

        m_IndexBuffer = std::move(ibo);
    }



    unsigned int OpenGLVertexArray::GetIndexCount() const
    {
        return m_IndexBuffer ? m_IndexBuffer->GetCount() : 0;
    }

    static GLenum ShaderDataTypeToOpenGLBaseType(engine::ShaderDataType type)
    {
        switch (type)   
        {
        //Float
        case engine::ShaderDataType::Float:
        case engine::ShaderDataType::Float2:
        case engine::ShaderDataType::Float3:
        case engine::ShaderDataType::Float4:
            return GL_FLOAT;

        //Int
        case engine::ShaderDataType::Int:
        case engine::ShaderDataType::Int2:
        case engine::ShaderDataType::Int3:
        case engine::ShaderDataType::Int4:
            return GL_INT;

        //Unsigned Int
        case engine::ShaderDataType::UInt:
        case engine::ShaderDataType::UInt2:
        case engine::ShaderDataType::UInt3:
        case engine::ShaderDataType::UInt4:
            return GL_UNSIGNED_INT;

        // Bool
        case engine::ShaderDataType::Bool:
            return GL_BOOL;

        // Double
        case engine::ShaderDataType::Double:
        case engine::ShaderDataType::Double2:
        case engine::ShaderDataType::Double3:
        case engine::ShaderDataType::Double4:
            return GL_DOUBLE;


        default:
            break;
        }

        return 0;
    }


}
