//
// Created by nazzazel on 28.07.2026.
//


#pragma once
#include "Core/Application/AppInterface/IAppInterface.hpp"
#include "Core/Base/VoxelGameHeaders/WorldCoord.hpp"
#include "Core/Client/Input/InputHandler.hpp"
#include "Core/Systems/Renderer/IRenderer/IRenderer.hpp"
#include "Tests/Objects/RotatingCube/RotatingCube.hpp"
#include "Core/Systems/Window/WindowSystem.hpp"
#include "Tests/Objects/Chunk/Chunk.hpp"

namespace opengltests
{
    class OpenGLTestsApp
    {
        public:
        void OnInit(engine::IAppInterface& engine);//TODO
        void OnUpdate(engine::IAppInterface& engine,float dt);
        //void OnRender(Renderer& m_Renderer) {}
        void OnRender(engine::IRenderer& renderer);
        void OnShutdown(); //TODO

        private:
        std::unique_ptr<InputHandler> m_input_handler;//TODO delete
        std::unique_ptr<OpenGLCamera> m_opengl_camera;

        std::unique_ptr<RotatingCube> m_Rot_Cube;//TODO delete
        //std::unique_ptr<Chunk> m_Chunk;//TODO delete

        std::vector<std::unique_ptr<Chunk>> loadedChunks;


        WorldCoord m_worldPosition;

    };
} // opengltests
