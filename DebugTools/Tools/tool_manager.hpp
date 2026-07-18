#pragma once
#include <vector>
#include <memory>

namespace debugtools
{
    class ITool;

    class ToolManager
    {
    public:
        void RegisterTool(std::shared_ptr<ITool> tool);

        void Update(float dt);
        void RenderUI();

    private:
        std::vector<std::shared_ptr<ITool>> m_Tools;
    };
}