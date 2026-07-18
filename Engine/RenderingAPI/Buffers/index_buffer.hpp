#pragma once
#include <memory>

namespace engine
{
	class IndexBuffer
	{
	public:
		~IndexBuffer() = default;

		virtual void Bind()		const = 0;
		virtual void Unbind()	const = 0;

		virtual unsigned int GetCount() const = 0;

		static std::unique_ptr<IndexBuffer> Create(unsigned int* indices, unsigned int count);
	
	private:

	};
}
