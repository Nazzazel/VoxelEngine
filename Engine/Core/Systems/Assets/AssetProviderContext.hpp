#pragma once
#include <string>

namespace engine
{
    class LoggerSystem;

    struct AssetProviderContext
    {
        AssetProviderContext()
        {
            std::cout << "created AssetProviderContext "<< &m_AssetRoot << std::endl;

        }

        ~AssetProviderContext()
        {
            std::cout << "destroyed AssetProviderContext "<< &m_AssetRoot << std::endl;
        }

        void SetAssetRoot(std::string path){m_AssetRoot = path;}
        //[[nodiscard]] const std::string& GetAssetRoot() const {return m_AssetRoot;}
        [[nodiscard]] std::string& GetAssetRoot() {return m_AssetRoot;}

        void SetLoggerSystem(LoggerSystem* logger){m_LoggerSystem = logger;}
        //[[nodiscard]] const LoggerSystem* GetLoggerSystem() const {return m_LoggerSystem;}
        [[nodiscard]] LoggerSystem* GetLoggerSystem() {return m_LoggerSystem;}

    private:
        std::string m_AssetRoot;
        LoggerSystem* m_LoggerSystem;
    };
}