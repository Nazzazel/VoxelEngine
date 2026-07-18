#pragma once
#include "DebugTools/Tools/itool.hpp"

namespace debugtools
{
    class ConsoleTool : public ITool
    {
    public:
        void OnUIRender() override;
        void OnUpdate(float dt) override;
    };
}