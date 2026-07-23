//
// Created by nazzazel on 22.07.2026.
//


#include "AssetProviderContext.hpp"
#include "Core/Systems/IEngineSystem.hpp"
#include "Core/Systems/File/FileSystem.hpp"
#include "Shaders/ShaderManager.hpp"


namespace engine
{


    //classes of assests like shader texture ect

    class AssetSystem : public IEngineSystem
    {
    public:




        ~AssetSystem() override = default;

        Result OnInit() override;// Forced
        Result OnUpdate(float dt) override;
        Result OnShutdown() override;

        //Init Setter //TODO in other classes//Setters post inti orf system also needed to be created



        Result ShaderMangagerStart();
        ShaderManager& GetShaderManager();
        const ShaderManager& GetShaderManager() const;


    private:
        void SetUpIAssetProvider();


    private:
        SystemManager* m_SystemManager = nullptr;
        LoggerSystem* m_Logger = nullptr;
        FileSystem* m_FileSystem = nullptr;

        AssetProviderContext m_AssetProviderContext;

        ShaderManager m_ShaderManager;

    };
} // engine
