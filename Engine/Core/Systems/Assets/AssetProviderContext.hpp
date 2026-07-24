#pragma once
#include <string>

#include "Core/Systems/File/FileSystem.hpp"

namespace engine
{
    class LoggerSystem;

    struct AssetProviderContext
    {
        AssetProviderContext(){}

        ~AssetProviderContext(){}

        void SetAssetRoot(std::string path){m_AssetRoot = path;}
        //[[nodiscard]] const std::string& GetAssetRoot() const {return m_AssetRoot;}
        [[nodiscard]] std::string& GetAssetRoot() {return m_AssetRoot;}

        void SetLoggerSystem(LoggerSystem* logger){m_LoggerSystem = logger;}
        //[[nodiscard]] const LoggerSystem* GetLoggerSystem() const {return m_LoggerSystem;}
        [[nodiscard]] LoggerSystem* GetLoggerSystem() {return m_LoggerSystem;}

        void SetFileSystem(FileSystem* file_system){m_FileSystem = file_system;}
        //[[nodiscard]] const LoggerSystem* GetLoggerSystem() const {return m_LoggerSystem;}
        [[nodiscard]] FileSystem* GetFileSystem() {return m_FileSystem;}


    private:
        std::string m_AssetRoot;
        LoggerSystem* m_LoggerSystem;
        FileSystem* m_FileSystem;
    };
}
