#pragma once
#include <string>
#include <vector>

namespace engine
{



	enum class ShaderDataType
	{
		Float, Float2, Float3, Float4,
		Int, Int2, Int3, Int4,
		UInt, UInt2, UInt3, UInt4,
		Bool,//new
		Mat3,Mat4,
		Double, Double2, Double3, Double4
	};


	static uint32_t ShaderDataTypeSize(ShaderDataType type)
	{
		switch (type)
		{
		case ShaderDataType::Float		: return sizeof(float);
		case ShaderDataType::Float2		: return sizeof(float) * 2;
		case ShaderDataType::Float3		: return sizeof(float) * 3;
		case ShaderDataType::Float4		: return sizeof(float) * 4;

		case ShaderDataType::Int		: return sizeof(int);
		case ShaderDataType::Int2		: return sizeof(int) * 2;
		case ShaderDataType::Int3		: return sizeof(int) * 3;
		case ShaderDataType::Int4		: return sizeof(int) * 4;

		case ShaderDataType::UInt		: return sizeof(unsigned int);
		case ShaderDataType::UInt2		: return sizeof(unsigned int) * 2;
		case ShaderDataType::UInt3		: return sizeof(unsigned int) * 3;
		case ShaderDataType::UInt4		: return sizeof(unsigned int) * 4;

		case ShaderDataType::Bool		: return sizeof(bool);

		case ShaderDataType::Mat3		: return sizeof(float) * 3 * 3;
		case ShaderDataType::Mat4		: return sizeof(float) * 4 * 4;

		case ShaderDataType::Double		: return sizeof(double);
		case ShaderDataType::Double2	: return sizeof(double) * 2;
		case ShaderDataType::Double3	: return sizeof(double) * 3;
		case ShaderDataType::Double4	: return sizeof(double) * 4;
		}
		return 0;
	}

	struct BufferElement 
	{
		ShaderDataType Type;
		std::string Name;
		//unsigned int Type; //OLD ONE
		unsigned int Size;
		size_t Offset;
		bool Normalised;

		BufferElement(ShaderDataType type, const std::string& name, bool normalizes = false)
			:Type(type)
			,Name(name)
			,Size(ShaderDataTypeSize(type))
			,Offset(0)
			,Normalised(normalizes) {}
	};

	class BufferLayout
	{
	public:
		BufferLayout() = default;

		BufferLayout(const std::initializer_list<BufferElement>& elements)
			: m_Elements(elements)
		{

			CalculateOffsetsAndStride();
		}

		const std::vector<BufferElement>& GetElements() const { return m_Elements; }
		uint32_t GetStride() const { return m_Stride; }

	private:
		void CalculateOffsetsAndStride()
		{
			size_t offset = 0;
			m_Stride = 0;

			for (auto& element : m_Elements)
			{
				element.Offset = offset;
				offset += element.Size;
				m_Stride += element.Size;
			}
		}

	private:
		std::vector<BufferElement> m_Elements;
		uint32_t m_Stride = 0;
	
	};

	static uint32_t GetComponentCount(ShaderDataType type)
	{
		switch (type)
		{
		case ShaderDataType::Float:		return 1;
		case ShaderDataType::Float2:	return 2;
		case ShaderDataType::Float3:	return 3;
		case ShaderDataType::Float4:	return 4;

		case ShaderDataType::Int:		return 1;
		case ShaderDataType::Int2:		return 2;
		case ShaderDataType::Int3:		return 3;
		case ShaderDataType::Int4:		return 4;

		case ShaderDataType::UInt:		return 1;
		case ShaderDataType::UInt2: 	return 2;
		case ShaderDataType::UInt3: 	return 3;
		case ShaderDataType::UInt4: 	return 4;



		case ShaderDataType::Bool:		return 1;

		case ShaderDataType::Mat3:		return 3 * 3;//TODO NOT SURE
		case ShaderDataType::Mat4:		return 4 * 4;

		case ShaderDataType::Double:	return 1;
		case ShaderDataType::Double2:	return 2;
		case ShaderDataType::Double3:	return 3;
		case ShaderDataType::Double4:	return 4;



		}
		return 0;
	}


	

}