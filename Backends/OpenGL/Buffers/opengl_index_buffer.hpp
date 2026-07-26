#pragma once
#include "Engine/Systems/Renderer/Buffers/IIndexBuffer.hpp"


namespace backends
{
	class OpenGLIndexBuffer : public engine::IIndexBuffer
	{
	public:
		OpenGLIndexBuffer(unsigned int* indices, unsigned int count);
		~OpenGLIndexBuffer();
		void Bind() const override;
		void Unbind() const override;

		unsigned int GetCount() const override { return m_Count; }



	private:
		unsigned int m_IndexBufferID;
		unsigned int m_Count;

	};



}