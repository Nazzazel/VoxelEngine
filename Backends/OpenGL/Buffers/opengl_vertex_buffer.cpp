#include "opengl_vertex_buffer.hpp"

#include <glad/glad.h>


#include "Backends/OpenGL/Debug/GLScope.hpp"


namespace backends
{


	OpenGLVertexBuffer::OpenGLVertexBuffer(const void* data, unsigned int size)
	{
		GL_SCOPE();
		glGenBuffers(1, &m_VertexBufferID);
		glBindBuffer(GL_ARRAY_BUFFER, m_VertexBufferID);
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	}

	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{
		GL_SCOPE();
		glDeleteBuffers(1, &m_VertexBufferID);
	}

	void OpenGLVertexBuffer::Bind() const
	{
		GL_SCOPE();
		glBindBuffer(GL_ARRAY_BUFFER, m_VertexBufferID);
	}

	void OpenGLVertexBuffer::Unbind() const
	{
		GL_SCOPE();
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}




}

