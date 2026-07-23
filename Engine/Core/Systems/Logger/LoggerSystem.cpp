//
// Created by nazzazel on 21.07.2026.
//

#include "LoggerSystem.hpp"




namespace engine
{
    //std::vector<LogMessage> LoggerSystem::m_Messages;

    Result LoggerSystem::OnInit() // Forced
    {
        m_SystemManager = this->GetSystemManager();

        if (!m_SystemManager)
        {
            return SYSTEM_RESULT(SystemManagerNotSet,Error);//todo
        }

        m_Timer = m_SystemManager->GetSystem<TimeSystem>();


        AddInfo("Logger System Initialized");
        return {};
    }

    Result LoggerSystem::OnUpdate(float dt)
    {
       // std::cout << dt << std::endl;
       // std::cout << "lo434432543l" <<dt << std::endl;



        for (const auto& msg : m_Messages)
        {
            std::cout << GetFormatedLog(msg) << "\n";
           // std::cout << GetDetailedFormatedLog(msg) << "\n";
        }

        ClearLog();
        return {};
    }

    Result LoggerSystem::OnShutdown()
    {
        ClearLog();
        return {};
    }

    Result LoggerSystem::ClearLog()
    {
        //TODO dddd
        m_Messages.clear();

        //return ENGINE_ERR(Memory, NullPointer, 1);

        return {};//CLear Auto Init -> Code 0 -> O Problems / Code 0 -> no Problems
    }

    std::string_view LoggerSystem::ReturnLogClassString( LogLevel log_level) const
    {

        switch (log_level)
        {
            //break; structure an old fossil left from tests, it will stay here until I will not change that\
            // It does not do anything either way.
        case LogLevel::INFO:    return  "INFO";     break;
        case LogLevel::WARNING: return  "WARNING";  break;
        case LogLevel::DEBUG:   return  "DEBUG";    break;
        case LogLevel::ERROR:   return  "ERROR";    break;
        case LogLevel::FATAL:   return  "FATAL";    break;
        case LogLevel::MSG:     return  "MSG";      break;
        }
        return "UNKNOWN";
    }

    std::string LoggerSystem::GetFormatedLog(const LogMessage& log) const
    {
       // std::string log_file_line = std::string(log.m_file) + " : "  + std::to_string(log.m_line);
       // std::stringstream log_stream = log.m_file + log.m_file;
//        std::string translatedMessage = log.
        //return
        //    "["+log.m_time + "] " +
        //    "[" + ReturnLogClassString(log.m_level) +"]" +
        //        log.m_message + //TODO Later support Translation
        //        "FILE/LINE" + log_file_line;


        //Newer Versuioin //TODO test and implement
        return std::format("[{}] [{}] {}",
                       log.m_time,
                       ReturnLogClassString(log.m_level),
                       log.m_message
                       );


    }

    std::string LoggerSystem::GetDetailedFormatedLog(const LogMessage& log) const
    {
        return std::format("[{}] [{}] {} FILE/LINE: {} : {}",
                       log.m_time,
                       ReturnLogClassString(log.m_level),
                       log.m_message,
                       log.m_file,
                       log.m_line
                       );
    }
} // engine