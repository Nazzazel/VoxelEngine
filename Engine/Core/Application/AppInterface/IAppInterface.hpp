//
// Created by nazzazel on 21.07.2026.
//


#pragma once
namespace engine
{
    class IAppInterface {
    public:
        virtual ~IAppInterface() = default;
        virtual class TimeSystem* GetTimeSystem() = 0;
        virtual class LoggerSystem* GetLoggerSystem() = 0;
        //virtual class IFileSystem* GetFileSystem() = 0;
    };
}