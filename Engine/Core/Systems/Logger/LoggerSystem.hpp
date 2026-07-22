//
// Created by nazzazel on 21.07.2026.
//


#pragma once
#include "Core/Systems/IEngineSystem.hpp"
#include "Core/Systems/Time/TimeSystem.hpp"
#include "Core/Manager/SystemManager.hpp"

namespace engine
{
    enum class LogLevel
    {
        ERROR,
        WARNING,
        INFO,
        DEBUG,
        MSG,
        FATAL

    };

    struct LogMessage
    {
    public:
        std::string m_time;
        LogLevel m_level;
        std::string m_message;
        const char* m_file;
        int m_line;
        //LogMessage(std::string time, LogLevel level, std::string message): m_time(time), m_level(level), m_message(message) {}
        LogMessage(const std::string& time,const LogLevel level,const std::string& message, const char* file, const int line)
        : m_time(time), m_level(level), m_message(message), m_file(file), m_line(line) {}
    };

 class LoggerSystem : public IEngineSystem {
    public:
       // template <typename... Args> void AddInfo    (Args&&... args)    const  {LogToConsole(LogLevel::INFO,       std::forward<Args>(args)...);}
       // template <typename... Args> void AddWarning (Args&&... args)    const  {LogToConsole(LogLevel::WARNING,    std::forward<Args>(args)...);}
       // template <typename... Args> void AddError   (Args&&... args)    const  {LogToConsole(LogLevel::ERROR,      std::forward<Args>(args)...);}
       // template <typename... Args> void AddDebug   (Args&&... args)    const  {LogToConsole(LogLevel::DEBUG,      std::forward<Args>(args)...);}
       // template <typename... Args> void AddMsg     (Args&&... args)    const  {LogToConsole(LogLevel::MSG,        std::forward<Args>(args)...);}

       // template <typename... Args> void AddInfo        (Args&&... args)    const  {LogMessage("11:12:14",LogLevel::INFO    ,std::forward<Args>(args)...,__FILE__,__LINE__);}
       //template <typename... Args> void AddWarning     (Args&&... args)    const  {LogMessage("11:12:14",LogLevel::WARNING ,std::forward<Args>(args)...,__FILE__,__LINE__);}
       //template <typename... Args> void AddError       (Args&&... args)    const  {LogMessage("11:12:14",LogLevel::ERROR   ,std::forward<Args>(args)...,__FILE__,__LINE__);}
       //template <typename... Args> void AddDebug       (Args&&... args)    const  {LogMessage("11:12:14",LogLevel::DEBUG   ,std::forward<Args>(args)...,__FILE__,__LINE__);}
       //template <typename... Args> void AddMsg         (Args&&... args)    const  {LogMessage("11:12:14",LogLevel::MSG     ,std::forward<Args>(args)...,__FILE__,__LINE__);}

       template <typename... Args> void AddInfo        (Args&&... args)    const   {m_Messages.emplace_back(m_Timer->CurrentTime(),LogLevel::INFO       ,ArgToString(std::forward<Args>(args)...),__FILE__,__LINE__);}
       template <typename... Args> void AddWarning     (Args&&... args)    const   {m_Messages.emplace_back(m_Timer->CurrentTime(),LogLevel::WARNING    ,ArgToString(std::forward<Args>(args)...),__FILE__,__LINE__);}
       template <typename... Args> void AddError       (Args&&... args)    const   {m_Messages.emplace_back(m_Timer->CurrentTime(),LogLevel::ERROR      ,ArgToString(std::forward<Args>(args)...),__FILE__,__LINE__);}
       template <typename... Args> void AddFatal       (Args&&... args)    const   {m_Messages.emplace_back(m_Timer->CurrentTime(),LogLevel::FATAL      ,ArgToString(std::forward<Args>(args)...),__FILE__,__LINE__);}
       template <typename... Args> void AddDebug       (Args&&... args)    const   {m_Messages.emplace_back(m_Timer->CurrentTime(),LogLevel::DEBUG      ,ArgToString(std::forward<Args>(args)...),__FILE__,__LINE__);}
       template <typename... Args> void AddMsg         (Args&&... args)    const   {m_Messages.emplace_back(m_Timer->CurrentTime(),LogLevel::MSG        ,ArgToString(std::forward<Args>(args)...),__FILE__,__LINE__);}
    private:

        std::string_view ReturnLogClassString( LogLevel log_level) const;

        std::string GetFormatedLog(const LogMessage& log) const;
        std::string GetDetailedFormatedLog(const LogMessage& log) const;

    public:
         ~LoggerSystem() = default;
         [[nodiscard]] Result OnInit() override;
         [[nodiscard]] Result OnUpdate(float dt) override ;
         [[nodiscard]] Result OnShutdown() override ;

    private:
        //
         [[nodiscard]] Result ClearLog();




     private:
         template <typename... Args>
         std::string ArgToString(Args&&... args) const {
             std::stringstream ss;
             (ss << ... << args);
             return ss.str();
         }


         mutable std::vector<LogMessage> m_Messages;

        const SystemManager* m_SystemManager = nullptr;
        const TimeSystem* m_Timer = nullptr;
     };

}

