//
// Created by nazzazel on 23.07.2026.
//

#include "FileSystem.hpp"
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif


namespace engine
{

    Result FileSystem::OnInit()// Forced
    {
        m_SystemManager = this->GetSystemManager();

        if (!m_SystemManager)
        {
            return SYSTEM_RESULT(SystemManagerNotSet,Error);//todo
        }

        m_Logger = m_SystemManager->GetSystem<LoggerSystem>();


        m_Logger->AddWarning("exe dir test 1 :::: ->>>>>",GetExecutableDir());
        // Mount default assets directory during engine startup
        namespace fs = std::filesystem;
        std::string path = GetExecutableDir() + "/Res/Assets/Shaders/Basic/OpenGL";

        fs::path projectRoot = path;
        //fs::path projectRoot = currentDir.parent_path().parent_path() / "";
        		if (fs::exists(projectRoot)) {
        		    m_Logger->AddWarning("loh");

        			// Successfully found the folder!
        		} else {
        		    m_Logger->AddWarning("cccccc");
        		    m_Logger->AddWarning("Engine looked for path in: ",projectRoot);
        			// Still not found, print the path to see what it's trying to access
        			std::cout << "Engine looked for path in: " << projectRoot << std::endl;
        		}

        m_AssetRoot = "assets";

        if (!std::filesystem::exists(m_AssetRoot)) {
            // Optionally create it if it doesn't exist
            std::filesystem::create_directory(m_AssetRoot);
        }

        return {};
    }

    Result FileSystem::OnUpdate(float dt)
    {

        m_AssetRoot.clear();
        return {};
    }

    Result FileSystem::OnShutdown()
    {

        return {};
    }
    void FileSystem::Mount(const std::string& physicalPath) {
        m_AssetRoot = physicalPath;
    }

    std::unique_ptr<IFile> FileSystem::OpenFile(const std::string& virtualPath) {
        std::filesystem::path fullPath = std::filesystem::path(m_AssetRoot) / NormalizePath(virtualPath);

        auto file = std::make_unique<NativeFile>(fullPath.string());
        if (!file->IsOpen()) {
            return nullptr;
        }
        return file;
    }

    std::string FileSystem::NormalizePath(const std::string& path) { //Strips down the path aka erase the / or \ at the front for reliable path like /root/ to root/ it ensures cros compability.
        if (!path.empty() && (path[0] == '/' || path[0] == '\\'))
            return path.substr(1);
        return path;
    }

    std::string FileSystem::GetExecutableDir()
    {
        char buffer[PATH_MAX];
        std::string pathStr;

#ifdef _WIN32
        DWORD length = GetModuleFileNameA(NULL, buffer, MAX_PATH);
        if (length > 0) {
            pathStr = std::string(buffer, length);
        }
#else
        ssize_t length = readlink("/proc/self/exe", buffer, sizeof(buffer) - 1);
        if (length > 0) {
            buffer[length] = '\0'; // Crucial: manually null-terminate!
            pathStr = std::string(buffer);
        }
#endif

        if (pathStr.empty()) {
            // Fallback or error handling if it fails
            return std::filesystem::current_path().string();
        }

        std::filesystem::path exePath(pathStr);
        return exePath.parent_path().string();
    }

};

