//#include "shader_library.hpp"
//
//namespace engine
//{
//	void ShaderLibrary::Add(ShaderTypeID type, std::unique_ptr<GameShader> shader)
//	{
//		std::string name = ShaderTypeToString(type);
//		m_Shaders[name] = std::move(shader);
//	}
//	std::unique_ptr<GameShader> ShaderLibrary::Get(ShaderTypeID type)
//	{
//		return nullptr; //TODO
//	}
//	std::string ShaderLibrary::ShaderTypeToString(ShaderTypeID type)
//	{
//		switch (type)
//		{
//		case ShaderTypeID::Basic: return "Basic";
//		case ShaderTypeID::Lighting: return "Lighting";
//		case ShaderTypeID::PBR: return "PBR";
//		case ShaderTypeID::Shadow: return "Shadow";
//		case ShaderTypeID::Skybox: return "Skybox";
//		case ShaderTypeID::UI: return "UI";
//		case ShaderTypeID::Particles: return "Particles";
//		case ShaderTypeID::Debug: return "Debug";
//		default: return "Unknown";
//		}
//	}
//}