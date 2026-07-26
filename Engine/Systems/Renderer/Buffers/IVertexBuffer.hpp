#pragma once
#include <memory>
#include "IBufferLayout.hpp"

namespace engine
{
	class IVertexBuffer
	{
	public:
		//VertexBuffer(const void* data, unsigned int size);
		virtual ~IVertexBuffer() = default;

		virtual void Bind()		const = 0;
		virtual void Unbind()	const = 0;

		virtual void SetLayout(const BufferLayout& layout) = 0;
		[[nodiscard]] virtual const BufferLayout& GetLayout() const = 0;

		static std::unique_ptr<IVertexBuffer> Create(const void* data, unsigned int size);
		
	private:

	};
}