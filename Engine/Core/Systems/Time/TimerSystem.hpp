//
// Created by nazzazel on 26.08.2026.
//


#pragma once
#include "Core/Systems/IEngineSystem.hpp"
#include "Timer.hpp"
#include "Core/Systems/Logger/LoggerSystem.hpp"

namespace engine
{
    class TimerSystem: public IEngineSystem
    {
    public:
        ~TimerSystem() override = default;

        Result OnInit() override;// Forced
        Result OnUpdate(float dt) override;
        Result OnShutdown() override;

        void AddTimer(const std::string& id);
        void RemoveTimer(const std::string& id);
        void StartTimer(const std::string& id);
        void StopTimer(const std::string& id);

       // bool SetCurrent(const std::string& id);
        void ResetTimer();
        void GetElapsedMs() const;
        void SetTimerAccuracy(Timer::Accuracy accuracy) const;




    private:
        Timer* FindTimer(const std::string& id);

        std::vector<std::unique_ptr<Timer>> m_Timers;
        Timer* m_Current = nullptr;


        const SystemManager* m_SystemManager = nullptr;
        const LoggerSystem* m_Logger = nullptr;

    };
} // engine
