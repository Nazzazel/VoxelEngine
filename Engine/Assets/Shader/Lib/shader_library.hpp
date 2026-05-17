#pragma once
//#include <unordered_map>
//#include <memory>
//#include <string>
//#include <Engine/Renderer/API/shader.hpp>

namespace engine
{

	enum class ShaderTypeID
	{
		Basic,
		Lighting,
		//from here I have no idea what each of them do LOL
		PBR,
		Shadow,
		Skybox,
		UI,
		Particles,
		Debug
		// Add more shader types as needed
	};

	//class ShaderLibrary {
	//
	//	public:
	//		void Add(ShaderTypeID type, std::unique_ptr<GameShader> shader); // shaderLibrary.Add("basic", Shader::Create("basic")); auto shader = shaderLibrary.Get("basic");
	//		std::unique_ptr<GameShader> Get(ShaderTypeID type);
	//
	//
	//		static std::string ShaderTypeToString(ShaderTypeID type);
	//	private:
	//		//std::unordered_map<std::string, std::unique_ptr<GameShader>> m_Shaders;
	//
	//
	//		
	//
	//};

}