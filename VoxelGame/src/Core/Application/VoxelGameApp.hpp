//
// Created by nazzazel on 13.07.2026.
//

#pragma once


#include "Core/Application/Application.hpp"
#include "Engine/Core/Systems/Renderer/IRenderer/IRenderer.hpp"

#include "Core/Application/AppInterface/IAppInterface.hpp"

#include <iostream>

#include "Tests/Objects/Rotating Cube/rcube.hpp"
#include "VoxelGame/Game/Camera/Camera.hpp"
#include "VoxelGame/Input/GameInput.hpp"

namespace voxelgame
{
    class VoxelGameApp : public engine::Application
    {
    public:
        explicit VoxelGameApp(const engine::AppSettings& settings);

    protected:

        void OnInit(engine::IAppInterface* engine) override;

        void OnUpdate(engine::IAppInterface* engine,float dt) override;

        //void OnRender(engine::Renderer& renderer) override;
        void OnRender(engine::IRenderer& rendererm) override;

        void OnShutdown() override;

    private:
        std::unique_ptr<engine::Rot_Cube> m_Rot_Cube;//TODO delete
        GameInput input;
        engine::KeybordInputStateMap* keybordInputStateMap;

        std::unique_ptr<glm::vec3> m_pos_ptr;
        glm::vec3 finalPos;

        std::unique_ptr<voxelgame::Camera> m_camera;

        engine::SceneData m_SceneData;

    };
} // voxelgame
