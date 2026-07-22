//
// Created by nazzazel on 22.07.2026.
//


#include "Core/Systems/IEngineSystem.hpp"
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

        Result ShaderMangagerStart();
        ShaderManager& GetShaderManager();
        const ShaderManager& GetShaderManager() const;





    private:


    };
} // engine
