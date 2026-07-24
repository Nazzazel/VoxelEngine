#pragma once
#include <memory>
#include "buffer_layout.hpp"

namespace engine
{
	class VertexBuffer
	{
	public:
		//VertexBuffer(const void* data, unsigned int size);
		virtual ~VertexBuffer() = default;

		virtual void Bind()		const = 0;
		virtual void Unbind()	const = 0;

		virtual void SetLayout(const BufferLayout& layout) = 0;
		[[nodiscard]] virtual const BufferLayout& GetLayout() const = 0;

		static std::unique_ptr<VertexBuffer> Create(const void* data, unsigned int size);
		
	private:

	};
}