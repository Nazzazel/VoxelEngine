//
// Created by nazzazel on 22.07.2026.
//

#include "AssetSystem.hpp"

namespace engine
{
    AssetSystem::AssetSystem()
    {

    }

    Result AssetSystem::OnInit()
    {
        m_SystemManager = this->GetSystemManager();

        if (!m_SystemManager)
        {
            return SYSTEM_RESULT(SystemManagerNotSet,Error);//todo
        }

        m_Logger = m_SystemManager->GetSystem<LoggerSystem>();

        if (!m_Logger)
        {
            return SYSTEM_RESULT(SystemNotFound,Error);//todo
        }

        m_FileSystem = m_SystemManager->GetSystem<FileSystem>();

        if (!m_FileSystem)
        {
            return SYSTEM_RESULT(FileSystemNotSet, Error);
        }

        m_AssetProviderContext = std::make_unique<AssetProviderContext>();

        m_AssetProviderContext->SetAssetRoot(m_FileSystem->GetExecutableDir());
        m_AssetProviderContext->SetLoggerSystem(m_Logger);


        ShaderMangagerStart();

        return {};
    }

    Result AssetSystem::OnUpdate(float dt)
    {
        //return PLATFORM_RESULT(None,Info);
        return {};
    }

    Result AssetSystem::OnShutdown()
    {


        return {};
    }



    Result AssetSystem::ShaderMangagerStart()
    {
        m_ShaderManager = std::make_unique<ShaderManager>(m_AssetProviderContext.get());
        return {};
    }
            ShaderManager& AssetSystem::GetShaderManager()      {return *m_ShaderManager;}
    const   ShaderManager& AssetSystem::GetShaderManager() const{return *m_ShaderManager;}



    void AssetSystem::SetUpIAssetProvider()
    {


    }
} // engine