//#include "shader_library.hpp"
//
//namespace engine
//{
//	void ShaderLibrary::Add(ShaderTypeID type, std::unique_ptr<engine::GameShader> shader)
//	{
//		std::string typeStr = ShaderTypeToString(type);
//		m_Shaders[typeStr] = std::move(shader);
//	}
//	std::unique_ptr<engine::GameShader> ShaderLibrary::Get(ShaderTypeID type)
//	{
//		std::string typeStr = ShaderTypeToString(type);
//		if (m_Shaders.find(typeStr) != m_Shaders.end())
//		{
//			return std::move(m_Shaders[typeStr]);
//		}
//		return nullptr;
//	}
//
//}