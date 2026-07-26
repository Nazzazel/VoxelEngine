#pragma once
#include <memory>

namespace engine
{
	class IIndexBuffer
	{
	public:
		virtual ~IIndexBuffer() = default;

		virtual void Bind()		const = 0;
		virtual void Unbind()	const = 0;

		virtual unsigned int GetCount() const = 0;

		static std::unique_ptr<IIndexBuffer> Create(unsigned int* indices, unsigned int count);
	
	private:

	};
}
