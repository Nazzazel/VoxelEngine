#include "Engine/Core/application.hpp"
#include "Engine/RenderingAPI/Renderer/renderer.hpp"

#include "DebugTools/Core/Logger/logger.hpp"

#include <iostream>
class VoxelGameApp : public engine::Application
{
protected:
    void OnUpdate(float dt) override
    {
		auto shader = GetAssetManager().GetShaderManager().Get(engine::ShaderTypeID::Basic); //TODO remove this later
		shader->Bind(); //TODO remove this later

        ////std::cout << "ggggggg1" << std::endl;
        //static float fpsSmoothed = 0.0f;
        //fpsSmoothed = fpsSmoothed * 0.9f + (0.1f / dt);
        //
        //float fps = (dt > 0.0f) ? (1.0f / dt) : 0.0f;
        //float msPerFrame = dt * 1000.0f;

        //debugtools::Logger::Log(debugtools::LogLevel::Info,
        //    "   dt:     " + std::to_string(dt) +
        //    " | fps:    " + std::to_string(fpsSmoothed) +
        //    " | ms:     " + std::to_string(msPerFrame)
        //);

        //std::cout << "Game Loop is working delta: " << dt << std::endl;

        // game update logic

    } 

    void OnRender(engine::Renderer& renderer) override
    {
        //std::cout << "ggggg "<< std::endl;
		//renderer.DrawTriangle(); //TODO remove this later

        // rendering logic (later voxel world)

        //renderer.DrawIndexed()

    }
};

int main()
{
    VoxelGameApp app;
    app.Run();
}