#pragma once

#include <vector>
#include <memory>
#include <string>

#include <DebugTools/Core/Timer/timer.hpp>
#include "DebugTools/Core/Logger/logger.hpp"


namespace debugtools
{
    class Timer;

    class TimerManager
    {
    public:
        TimerManager();
        ~TimerManager();

        static TimerManager& Instance();

        void AddTimer(const std::string& id);
        void RemoveTimer(const std::string& id);

        bool SetCurrent(const std::string& id);

        void Start();
        void Stop();
        void Reset();

        long long GetElapsedMs() const;


        void DebugMode(bool DebugMode);


        

    private:
        //TimerManager() = default;
        //~TimerManager() = default;

        Timer* FindTimer(const std::string& id);

    private:
        std::vector<std::unique_ptr<Timer>> m_Timers;
        Timer* m_Current = nullptr;

        bool debug_conf;
    };
}