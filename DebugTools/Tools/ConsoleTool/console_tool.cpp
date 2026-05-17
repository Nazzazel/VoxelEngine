#include "console_tool.hpp"
#include "Core/Logger/logger.hpp"

// UI is abstract (you define later)
#include <iostream>

namespace debugtools
{
    void ConsoleTool::OnUIRender()
    {
        const auto& logs = Logger::GetMessages();

        for (const auto& msg : logs)
        {
            std::cout << msg.text << std::endl;
        }
    }

    void ConsoleTool::OnUpdate(float dt)
    {

    }


}