#pragma once
#include <string>
#include <vector>

#include <ostream> 
#include "DebugTools/Core/Timer/time_utils.hpp"

namespace debugtools
{
    enum class LogLevel
    {
        Info,
        Warning,
        Error
    };

	inline std::ostream& operator<<(std::ostream& os, const LogLevel& level)
	{
		std::string levelStr;
        switch (level)
        {
        case LogLevel::Info:    levelStr = "INFO"; break;
        case LogLevel::Warning: levelStr = "WARNING"; break;
        case LogLevel::Error:   levelStr = "ERROR"; break;
        }
		os << "[ " << levelStr << " ] : ";
		return os;
	}

    struct LogMessage
    {
    public:
        std::string time;
        LogLevel level;
        std::string text;
        
        
        LogMessage(LogLevel lvl, const std::string& msg) : level(lvl), text(msg), time(debugtools::TimeUtil::CurrentTime()) {}

		//friend std::ostream& operator<<(std::ostream& os, const LogMessage& msg)
		//{
		//	std::string levelStr = "";
		//	//switch (msg.level)
		//	//{
		//	//case LogLevel::Info:    levelStr = "[INFO] "; break;
		//	//case LogLevel::Warning: levelStr = "[WARNING] "; break;
		//	//case LogLevel::Error:   levelStr = "[ERROR] "; break;
		//	//}
  //          //os << levelStr;


    };

    class Logger
    {
    public:

        static void Log                  (LogLevel level, const std::string& message);
        static void Log(bool should_show, LogLevel level, const std::string& message);

        //static void Log(,LogLevel level, const std::string& message);

        static const std::vector<LogMessage>& GetMessages();
        static void Clear();

    private:
        static std::vector<LogMessage> s_Messages;
    };
}