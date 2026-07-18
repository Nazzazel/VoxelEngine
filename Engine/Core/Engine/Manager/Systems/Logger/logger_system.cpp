//
// Created by nazzazel on 13.07.2026.
//

#include "logger_system.hpp"

#include <format>


namespace engine
{
    //std::vector<LogMessage> LoggerSystem::m_Messages;

    uint32_t LoggerSystem::OnInit() // Forced
    {
       // DT_INFO("LoggerSystem Initiated");
        return 0;
    }

    uint32_t LoggerSystem::OnUpdate(float dt)
    {
       // std::cout << dt << std::endl;
       // std::cout << "lo434432543l" <<dt << std::endl;



        for (const auto& msg : m_Messages)
        {
            std::cout << GetFormatedLog(msg) << "\n";
        }
        ClearLog();
        return 0;
    }

    uint32_t LoggerSystem::OnShutdown()
    {
        ClearLog();
        return 0;
    }

    uint32_t LoggerSystem::ClearLog()
    {
        //TODO dddd
        m_Messages.clear();
        return 0;
    }

    std::string_view LoggerSystem::ReturnLogClassString( LogLevel log_level) const
    {

        switch (log_level)
        {
        case LogLevel::INFO:    return  "INFO"; break;
        case LogLevel::WARNING: return  "WARNING"; break;
        case LogLevel::DEBUG:   return  "DEBUG"; break;
        case LogLevel::ERROR:   return  "ERROR"; break;
        case LogLevel::MSG:     return  "MSG"; break;
        }
        return "UNKNOWN";
    }

    std::string LoggerSystem::GetFormatedLog(const LogMessage& log) const
    {
        std::string log_file_line = std::string(log.m_file) + " : "  + std::to_string(log.m_line);
       // std::stringstream log_stream = log.m_file + log.m_file;
//        std::string translatedMessage = log.
        //return
        //    "["+log.m_time + "] " +
        //    "[" + ReturnLogClassString(log.m_level) +"]" +
        //        log.m_message + //TODO Later support Translation
        //        "FILE/LINE" + log_file_line;


        //Newer Versuioin //TODO test and implement
        return std::format("[{}] [{}] {} FILE/LINE: {} : {}",
                       log.m_time,
                       ReturnLogClassString(log.m_level),
                       log.m_message,
                       log.m_file,
                       log.m_line);


    }
} // engine