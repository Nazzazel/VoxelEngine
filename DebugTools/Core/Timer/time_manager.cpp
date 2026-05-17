#include "time_manager.hpp"



namespace debugtools
{


    TimerManager::TimerManager() {
		std::vector<std::unique_ptr<debugtools::Timer>> m_Timers;
		Timer* m_Current = nullptr;
        bool debug_conf = false;
		debugtools::Logger::Log(debugtools::LogLevel::Info, "Time Managter Init");
		//m_Timers.clear();
	}

	TimerManager::~TimerManager() {
		debugtools::Logger::Log(debugtools::LogLevel::Info, "TimerManager destroyed, all timers cleared.");
	}



    TimerManager& TimerManager::Instance()
    {
        static TimerManager instance;
        return instance;
    }

    void TimerManager::AddTimer(const std::string& id)
    {

        if (FindTimer(id))
        {
			debugtools::Logger::Log(debugtools::LogLevel::Warning,
				"Timer with id '" + id + "' already exists in TimerManager.");
            return;

        }
		debugtools::Logger::Log(debugtools::LogLevel::Info,
			"Added timer with id '" + id + "' to TimerManager.");
        m_Timers.push_back(std::make_unique<Timer>(id));
    }

    void TimerManager::RemoveTimer(const std::string& id)
    {
        m_Timers.erase(
            std::remove_if(m_Timers.begin(), m_Timers.end(),
                [&](const std::unique_ptr<Timer>& t)
                {
                    return t->GetId() == id;
                }),
            m_Timers.end());
		debugtools::Logger::Log(debugtools::LogLevel::Info,
			"Removed timer with id '" + id + "' from TimerManager.");

        if (m_Current && m_Current->GetId() == id)
            m_Current = nullptr;
    }

    bool TimerManager::SetCurrent(const std::string& id)
    {
        m_Current = FindTimer(id);
        if (m_Current != nullptr)
        {
			debugtools::Logger::Log(debugtools::LogLevel::Info, "Succesfully setted timer with id '" + id + "' as a current Timer");
			return true;
        }
        else
        {
			debugtools::Logger::Log(debugtools::LogLevel::Warning,
				"Timer with id '" + id + "' not found in TimerManager. Current timer not set.");
        }
		debugtools::Logger::Log(debugtools::LogLevel::Warning, "Failed to set current timer with id '" + id + "'. Please check if the timer exists in TimerManager.");
		return false;
    }

    void TimerManager::DebugMode(const bool DebugMode)
    {
        debug_conf = DebugMode;
    }

    void TimerManager::Start()
    {
        if (m_Current)
            m_Current->Start();
        else
        {
            debugtools::Logger::Log(debug_conf,debugtools::LogLevel::Info,
            "m_Current : nullptr, please choose the timere using | bool TimerManager::SetCurrent(const std::string& id) | " );
        }
        //m_Current->GetId()
		debugtools::Logger::Log(debug_conf, debugtools::LogLevel::Info, "Started timer '");
    }

    void TimerManager::Stop()
    {
        if (m_Current)
        {
            debugtools::Logger::Log(debug_conf, debugtools::LogLevel::Info, "Stopping timer '");
           //debugtools::Logger::Log(debugtools::LogLevel::Info, "Stopped timer '" + m_Current->GetId() + "'. Elapsed time: " + std::to_string(m_Current->ElapsedMs()) + " ms.");
            GetElapsedMs();
            m_Current->Stop();
        }
    }

    void TimerManager::Reset()
    {
        if (m_Current)
            m_Current->Reset();
    }

    long long TimerManager::GetElapsedMs() const
    {
        if (!m_Current)
        {
			debugtools::Logger::Log(debugtools::LogLevel::Error, "No current timer set. Please set a timer to get elapsed time.");
            return 0;
        }

		debugtools::Logger::Log(debugtools::LogLevel::Info,
			"Elapsed time for timer '" + m_Current->GetId() + "': " +
			std::to_string(m_Current->ElapsedMs()) + " ms.");
        return m_Current->ElapsedMs();
    }

    Timer* TimerManager::FindTimer(const std::string& id)
    {
        for (auto& timer : m_Timers)
        {
            if (timer->GetId() == id)
                return timer.get();
        }
        return nullptr;
    }





}



//OLD
//namespace debugtools
//{
//
//	TimerManager::TimerManager() {
//		debugtools::Logger::Log(debugtools::LogLevel::Info, "Time Managter Init");
//		//m_Timers.clear();
//	}
//
//	TimerManager::~TimerManager() {
//		debugtools::Logger::Log(debugtools::LogLevel::Info, "TimerManager destroyed, all timers cleared.");
//	}
//
//	void TimerManager::AddTimer(const char* title)
//	{
//		if (m_Timers.empty())
//		{
//			return;
//		}
//		for (const auto& timer : m_Timers)
//		{
//			if (strcmp(timer->GetId(), title) == 0)
//			{
//				debugtools::Logger::Log(LogLevel::Warning,
//					"Timer with title '" + std::string(title) + "' already exists.");
//				return;
//			}
//		}
//	}
//
//	void TimerManager::SetTimer(const char* title)
//	{
//		if (m_Timers.empty())
//		{
//			debugtools::Logger::Log(LogLevel::Warning, "No timers available.");
//			return;
//		}
//
//		for (auto& timer : m_Timers)
//		{
//			if (strcmp(timer->GetId(), title) == 0)
//			{
//				m_CurrentTimer = timer.get();
//				return;
//			}
//		}
//
//		m_CurrentTimer = nullptr;
//		debugtools::Logger::Log(LogLevel::Warning,
//			"Timer with title '" + std::string(title) + "' not found.");
//	}
//
//
//	std::string TimerManager::CurrentTime()
//	{
//		std::string timeStr;
//
//		auto now = std::chrono::system_clock::now();
//		auto now_time_t = std::chrono::system_clock::to_time_t(now);
//		std::tm tm{};
//		localtime_s(&tm, &now_time_t); // thread-safe version of localtime
//
//		auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
//
//		timeStr =
//			"[ " +
//			std::to_string(tm.tm_hour) + ":" +
//			std::to_string(tm.tm_min) + ":" +
//			std::to_string(tm.tm_sec) +
//			" ]";
//
//		return timeStr;
//	}
//
//	void TimerManager::Start()
//	{
//		if (!m_CurrentTimer)
//		{
//			debugtools::Logger::Log(debugtools::LogLevel::Warning, "No current timer set. Please set a timer before starting.");
//			return;
//		}
//
//		m_CurrentTimer->Start();
//
//	}
//
//	void TimerManager::Stop()
//	{
//		m_CurrentTimer->Stop();
//		//m_CurrentTimer->~Timer();
//	}
//
//	void TimerManager::Reset()
//	{
//
//	}
//
//	void TimerManager::Pause()
//	{
//	}
//
//	void TimerManager::Mark()
//	{
//
//	}
//
//	void TimerManager::Mark(const char* text)
//	{
//
//	}
//
//}