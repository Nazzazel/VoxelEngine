#pragma once

//#include <unordered_map>
//#include "Engine/Renderer/API/shader.hpp"
#include "Engine/Assets/AssetManager/Interfaces/IAssetProvider.h"
#include "../ShaderTypeID.h"
#include "Engine/Assets/Shader/Load/shader_loader.hpp"
#include "../../../Core/Systems/Assets/Shaders/IShader.hpp"

#include <string>
#include <unordered_map>
#include <memory>

namespace engine
{

	class ShaderManager
	{

	public:
		ShaderManager(IAssetProvider& provider);
		~ShaderManager();

		//std::string ParseOpenGlShader(const std::string& filepath);
		//std::string GetShaderData(const std::string& filepath);


		void Add(ShaderTypeID type);
		IShader* Get(ShaderTypeID type);
		//MAYBE// shaderLibrary.Add("basic", Shader::Create("basic")); auto shader = shaderLibrary.Get("basic");
		
		
		//void Add(ShaderTypeID type, std::unique_ptr<GameShader> shader); // shaderLibrary.Add("basic", Shader::Create("basic")); auto shader = shaderLibrary.Get("basic");


		//static std::string ShaderTypeToString(ShaderTypeID type);
	private:
		std::unordered_map<ShaderTypeID, std::unique_ptr<IShader>> m_Shaders;

		IAssetProvider& m_provider;

		ShaderLoader m_shader_loader;

		std::string ShaderTypeIDToString(ShaderTypeID type);

	};
}