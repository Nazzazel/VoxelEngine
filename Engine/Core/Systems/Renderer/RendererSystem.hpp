//
// Created by nazzazel on 22.07.2026.
//


#pragma once
#include "API/RendererApi.hpp"
#include "Core/Systems/IEngineSystem.hpp"
#include "Core/Systems/Logger/LoggerSystem.hpp"
#include "IRenderer/IRenderer.hpp"
#include "Core/Manager/SystemManager.hpp"

namespace engine
{
    class RendererSystem : public IEngineSystem
    {
        public:

        ~RendererSystem() override = default;

        Result OnInit() override;// Forced
        Result OnUpdate(float dt) override;
        Result OnShutdown() override;

        Result ChangeGraphicAPI(backends::RendererAPIType type);

        IRenderer* GetRenderer() const {return m_Renderer.get();}

        private:
        std::unique_ptr<IRenderer> m_Renderer;

        const SystemManager* m_SystemManager = nullptr;
        const LoggerSystem* m_Logger = nullptr;

    };
} // engine
