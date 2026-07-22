//
// Created by nazzazel on 13.07.2026.
//

#pragma once


#include "Core/Application/Application.hpp"
#include "../../../../Engine/Core/Systems/Renderer/IRenderer/IRenderer.hpp"

#include "Core/Application/AppInterface/IAppInterface.hpp"

#include <iostream>

namespace voxelgame
{
    class VoxelGameApp : public engine::Application
    {
    public:
        explicit VoxelGameApp(const engine::AppSettings& settings);

    protected:

        void OnInit(engine::IAppInterface* engine) override;

        void OnUpdate(engine::IAppInterface* engine) override;

        //void OnRender(engine::Renderer& renderer) override;
        void OnRender() override;

        void OnShutdown() override;

    private:
        //std::unique_ptr<engine::Rot_Cube> m_Rot_Cube;//TODO delete


    };
} // voxelgame
