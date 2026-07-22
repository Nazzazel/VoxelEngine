// #pragma once
//
//
//
// #include <Engine/Assets/Shader/ShaderManager/shader_manager.hpp>
// #include <Engine/Assets/AssetManager/Interfaces/IAssetProvider.h>
//
//
// #include <memory>
//
// #include "Core/Systems/Assets/IAssetProvider.hpp"
// //#include <string>
// //#include <filesystem>
//
//
// namespace engine
// {
//
//
//
// 	class AssetManager : public engine::IAssetProvider
// 	{
// 	public:
//
//
//
// 		AssetManager();
// 		~AssetManager();
//
// 		//std::filesystem::path GetExecutableDir();
//
// 		void SetAssetRoot(std::string&  path);
// 		const std::string& GetAssetRoot() const override;
//
// 		//void Use
//
//
// 		//Shader
// 		ShaderManager& GetShaderManager() { return *m_ShaderManager; }
// 		//std::unique_ptr<engine::GameShader> LoadShader(const std::string& filepath);
//
//
//
//
// 	private:
//
// 		std::string PROJECT_ROOT;
//
// 		static AssetManager instance;
//
// 		std::unique_ptr<engine::ShaderManager> m_ShaderManager;
//
// 		std::string GetExecutableDir();
//
// 	};
//
//
//
// }