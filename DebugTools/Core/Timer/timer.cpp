#include "timer.hpp"

namespace debugtools
{
    Timer::Timer(const std::string& id)
        : m_Id(id)
    {
    }

    void Timer::Start()
    {
        m_StartTime = std::chrono::steady_clock::now();
        m_Running = true;
    }

    void Timer::Stop()
    {
        if (!m_Running) return;

        m_EndTime = std::chrono::steady_clock::now();
        m_Running = false;
    }

    void Timer::Reset()
    {
        m_Running = false;
    }



    long long Timer::ElapsedMs() const
    {
        if (m_Running)
        {
            return std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::steady_clock::now() - m_StartTime).count();
        }
        return std::chrono::duration_cast<std::chrono::milliseconds>(
            m_EndTime - m_StartTime).count();
    }

    const std::string& Timer::GetId() const
    {
        return m_Id;
    }
}



//OLD

//#include <vector>
//#include <memory>
//#include <chrono>
//#include <string>
//#include "DebugTools/Core/Logger/logger.hpp"
// 
// 
//namespace debugtools
//{
//	Timer::Timer(std::string id) : m_Id(id)
//	{
//		
//		 
//	//#ifdef DEBUG
//		debugtools::Logger::Log(debugtools::LogLevel::Info, "Timer with ID '" + std::string(id) + "' created.");
//	//#endif // DEBUG
//	}
//
//	Timer::~Timer()
//	{
//	#ifdef DEBUG
//		debugtools::Logger::Log(debugtools::LogLevel::Info, "Timer with ID '" + std::string(m_Id) + "' destroyed.");
//	#endif // DEBUG
//	}
//
//	void Timer::Start()
//	{
//
//		m_TimeStart = std::chrono::steady_clock::now();
//
//	}
//
//	void Timer::Stop()
//	{
//		auto difference  = std::chrono::steady_clock::now() - m_TimeStart;
//		auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(difference).count();
//
//    //void Timer::Stop()
//    //{
//    //    auto difference = std::chrono::steady_clock::now() - m_TimeStart;
//    //    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(difference).count();
//
//        debugtools::Logger::Log(debugtools::LogLevel::Info, "Elapsed time: [ " + std::to_string(elapsedTime) + " ms]");
//    }
//		
//	
//	
//	
//	
//	
//
//	void Timer::Reset()
//	{
//			
//	}
//
//	void Timer::Pause() {}
//	void Timer::Mark() {}
//	void Timer::Mark(const char* text) {}
//	//void Timer::etId() {}
//
//
//
//
//
//
//
//}

