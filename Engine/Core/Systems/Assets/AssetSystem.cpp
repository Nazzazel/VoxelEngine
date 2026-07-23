//
// Created by nazzazel on 22.07.2026.
//

#include "AssetSystem.hpp"

namespace engine
{
    Result AssetSystem::OnInit()
    {
        m_SystemManager = this->GetSystemManager();

        if (!m_SystemManager)
        {
            return SYSTEM_RESULT(SystemManagerNotSet,Error);//todo
        }

        m_Logger = m_SystemManager->GetSystem<LoggerSystem>();

        m_FileSystem = m_SystemManager->GetSystem<FileSystem>();
        if (!m_FileSystem)
        {
            return SYSTEM_RESULT(FileSystemNotSet, Error);
        }


        m_AssetProviderContext.SetAssetRoot(m_FileSystem->GetExecutableDir());
        m_AssetProviderContext.SetLoggerSystem(m_Logger);




        return {};
    }

    Result AssetSystem::OnUpdate(float dt)
    {

        return {};
    }

    Result AssetSystem::OnShutdown()
    {
        return {};
    }

    Result AssetSystem::ShaderMangagerStart()
    {

    }

    ShaderManager& AssetSystem::GetShaderManager()
    {

    }

    const ShaderManager& AssetSystem::GetShaderManager() const
    {
    }

    void AssetSystem::SetUpIAssetProvider()
    {


    }
} // engine