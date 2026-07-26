#pragma once
#include "Engine/Systems/Renderer/Buffers/IVertexBuffer.hpp"
#include "Engine/Systems/Renderer/Buffers/IBufferLayout.hpp"
#include <iostream>

namespace backends
{
	class OpenGLVertexBuffer : public engine::IVertexBuffer
	{
	public:
		OpenGLVertexBuffer(const void* data, unsigned int size);
		~OpenGLVertexBuffer() override;
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