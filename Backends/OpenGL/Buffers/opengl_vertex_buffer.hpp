#pragma once
#include "Engine/RenderingAPI/Buffers/vertex_buffer.hpp"
#include "Engine/RenderingAPI/Buffers/buffer_layout.hpp"
#include <iostream>

namespace backends
{
	class OpenGLVertexBuffer : public engine::VertexBuffer
	{
	public:
		OpenGLVertexBuffer(const void* data, unsigned int size);
		~OpenGLVertexBuffer();
		void Bind() const override;
		void Unbind() const override;


		//Layout
		void SetLayout(const engine::BufferLayout& layout) override		{
			m_Layout = layout; }
		const engine::BufferLayout& GetLayout() const override			{return m_Layout;}

	private:
		unsigned int m_VertexBufferID;
		engine::BufferLayout m_Layout;
	};



}