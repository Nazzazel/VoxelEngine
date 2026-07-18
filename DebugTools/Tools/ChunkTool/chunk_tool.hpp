#pragma once
#include "Tools/itool.hpp"

namespace debugtools
{
    class ConsoleTool : public ITool
    {
    public:
        void OnUIRender() override;
    };
}