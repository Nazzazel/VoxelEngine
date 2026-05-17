#include "Engine/Assets/AssetManager/asset_manager.hpp"



namespace engine
{
	AssetManager::AssetManager()
	{
		PROJECT_ROOT = "E:/Users/kappa/source/repos/VoxelEngine/";
		m_ShaderManager = std::make_unique<engine::ShaderManager>(*this);
	}

	AssetManager::~AssetManager(){}

	void AssetManager::SetAssetRoot(std::string& path)
	{
		PROJECT_ROOT = path;
	}

	const std::string& AssetManager::GetAssetRoot() const 
	{
		return PROJECT_ROOT;
	}





	//void SetAssetRoot(std::string& path);
	//std::string& GetAssetRoot();


}