#include "Engine/Assets/AssetManager/asset_manager.hpp"



#ifdef _WIN32
#else
#include <unistd.h>
#endif


#include <filesystem>
#include <iostream>


namespace engine
{
	AssetManager::AssetManager()
	{


		namespace fs = std::filesystem;

		// Get the directory where your executable is currently running
		fs::path currentDir = GetExecutableDir();

		// Use the "/" operator to go up to the parent, then up again
		fs::path projectRoot = currentDir.parent_path().parent_path() / "";

		// Check if it exists so you can debug why it was failing before
		if (fs::exists(projectRoot)) {
			PROJECT_ROOT = projectRoot;
			// Successfully found the folder!
		} else {
			// Still not found, print the path to see what it's trying to access
			std::cout << "Engine looked for path in: " << projectRoot << std::endl;
		}


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


	std::string AssetManager::GetExecutableDir() {
		char buffer[PATH_MAX];
		#ifdef _WIN32
		GetModuleFileNameA(NULL, buffer, MAX_PATH);
		#else
		readlink("/proc/self/exe", buffer, PATH_MAX);
		#endif
		std::filesystem::path exePath(buffer);
		// Returns the parent directory of the executable
		//std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!ggggg : SRC: " << exePath.parent_path().string() << std::endl;

		return exePath.parent_path().string();
	}




	//void SetAssetRoot(std::string& path);
	//std::string& GetAssetRoot();


}
