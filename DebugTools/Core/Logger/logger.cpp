#include "logger.hpp"

namespace debugtools
{
    std::vector<LogMessage> Logger::s_Messages;

    void Logger::Log(LogLevel level, const std::string& message)
    {
        s_Messages.push_back({ level, message });
    }

    void Logger::Log(bool should_show, LogLevel level, const std::string& message)
    {
        if(should_show )s_Messages.push_back({ level, message });
    }

    const std::vector<LogMessage>& Logger::GetMessages()
    {
        return s_Messages;
    }

    void Logger::Clear()
    {
        s_Messages.clear();
    }
}