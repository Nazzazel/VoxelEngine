#pragma once
#include <string>

namespace engine
{
    class LoggerSystem;

    struct AssetProviderContext
    {
        AssetProviderContext();
        ~AssetProviderContext() = default;

        void SetAssetRoot(std::string path){m_AssetRoot = path;}
        [[nodiscard]] const std::string& GetAssetRoot() const {return m_AssetRoot;}

        void SetLoggerSystem(LoggerSystem* logger){m_LoggerSystem = logger;}
        [[nodiscard]] LoggerSystem* GetLoggerSystem() const {return m_LoggerSystem;}

    private:
        std::string m_AssetRoot;
        LoggerSystem* m_LoggerSystem;
    };
}