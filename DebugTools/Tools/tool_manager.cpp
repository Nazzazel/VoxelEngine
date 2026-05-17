#include "tool_manager.hpp"
#include "itool.hpp"

namespace debugtools
{
    void ToolManager::RegisterTool(std::shared_ptr<ITool> tool)
    {
        m_Tools.push_back(tool);
    }

    void ToolManager::Update(float dt)
    {
        for (auto& tool : m_Tools)
            tool->OnUpdate(dt);
    }

    void ToolManager::RenderUI()
    {
        for (auto& tool : m_Tools)
            tool->OnUIRender();

    }
}