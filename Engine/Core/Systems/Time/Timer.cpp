//
// Created by nazzazel on 25.08.2026.
//

#include "Timer.hpp"

namespace engine
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
        m_StartTime = std::chrono::steady_clock::now();
    }

    void Timer::SetState(bool state)
    {
        m_Running = state;
    }

    void Timer::SetAccuracy(Accuracy accuracy)
    {
        m_Accuracy = accuracy;
    }


    long long Timer::ElapsedMs() const
    {
        if (m_Running)
        {
            switch (m_Accuracy)
            {
                case Accuracy::Hour:        {return std::chrono::duration_cast<std::chrono::hours>          (std::chrono::steady_clock::now() - m_StartTime).count();}
                case Accuracy::Minute:      {return std::chrono::duration_cast<std::chrono::minutes>        (std::chrono::steady_clock::now() - m_StartTime).count();}
                case Accuracy::Second:      {return std::chrono::duration_cast<std::chrono::seconds>        (std::chrono::steady_clock::now() - m_StartTime).count();}
                case Accuracy::MilliSecond: {return std::chrono::duration_cast<std::chrono::milliseconds>   (std::chrono::steady_clock::now() - m_StartTime).count();}
                case Accuracy::MicroSecond: {return std::chrono::duration_cast<std::chrono::microseconds>   (std::chrono::steady_clock::now() - m_StartTime).count();}
                case Accuracy::NanoSecond:  {return std::chrono::duration_cast<std::chrono::nanoseconds>    (std::chrono::steady_clock::now() - m_StartTime).count();}

               // case Accuracy::Count:  {return std::chrono::duration_cast<std::chrono::hours>    (std::chrono::steady_clock::now() - m_StartTime).count();}
               // case A
                default: return 0;
            }

           // return std::chrono::duration_cast<std::chrono::milliseconds>(
               // std::chrono::steady_clock::now() - m_StartTime).count();
        }
        return std::chrono::duration_cast<std::chrono::milliseconds>(
            m_EndTime - m_StartTime).count();
    }

    const std::string& Timer::GetId() const
    {
        return m_Id;
    }

    std::string Timer::GetAccuracy()
    {
        switch (m_Accuracy)
        {
        case Accuracy::Hour:        {return std::string("Hour");}
        case Accuracy::Minute:      {return std::string("Minute");}
        case Accuracy::Second:      {return std::string("Second");}
        case Accuracy::MilliSecond: {return std::string("Millisecond");}
        case Accuracy::MicroSecond: {return std::string("Microsecond");}
        case Accuracy::NanoSecond:  {return std::string("Nanosecond");}

        // case Accuracy::Count:  {return std::chrono::duration_cast<std::chrono::hours>    (std::chrono::steady_clock::now() - m_StartTime).count();}
        // case A
        default: return "NULL";
        }

    }

    std::string Timer::GetAccuracy(Accuracy accuracy)
    {
        switch (accuracy)
        {
        case Accuracy::Hour:        {return std::string("Hour");}
        case Accuracy::Minute:      {return std::string("Minute");}
        case Accuracy::Second:      {return std::string("Second");}
        case Accuracy::MilliSecond: {return std::string("Millisecond");}
        case Accuracy::MicroSecond: {return std::string("Microsecond");}
        case Accuracy::NanoSecond:  {return std::string("Nanosecond");}

        // case Accuracy::Count:  {return std::chrono::duration_cast<std::chrono::hours>    (std::chrono::steady_clock::now() - m_StartTime).count();}
        // case A
        default: return "NULL";
        }

    }

    std::string Timer::GetUnit()
    {
        switch (m_Accuracy)
        {
        case Accuracy::Hour:        {return std::string("h");}
        case Accuracy::Minute:      {return std::string("m");}
        case Accuracy::Second:      {return std::string("s");}
        case Accuracy::MilliSecond: {return std::string("ms");}
        case Accuracy::MicroSecond: {return std::string("us");}
        case Accuracy::NanoSecond:  {return std::string("ns");}

        // case Accuracy::Count:  {return std::chrono::duration_cast<std::chrono::hours>    (std::chrono::steady_clock::now() - m_StartTime).count();}
        // case A
        default: return "NULL";
        }

    }

} // engine


//     Timer::Timer(const std::string& id)
//         : m_Id(id)
//     {
//     }
//
//     void Timer::Start()
//     {
//         m_StartTime = std::chrono::steady_clock::now();
//         m_Running = true;
//     }
//
//     void Timer::Stop()
//     {
//         if (!m_Running) return;
//
//         m_EndTime = std::chrono::steady_clock::now();
//         m_Running = false;
//     }
//
//     void Timer::Reset()
//     {
//         m_Running = false;
//     }
//
//
//
//     long long Timer::ElapsedMs() const
//     {
//         if (m_Running)
//         {
//             return std::chrono::duration_cast<std::chrono::milliseconds>(
//                 std::chrono::steady_clock::now() - m_StartTime).count();
//         }
//         return std::chrono::duration_cast<std::chrono::milliseconds>(
//             m_EndTime - m_StartTime).count();
//     }
//
//     const std::string& Timer::GetId() const
//     {
//         return m_Id;
//     }
// }
//
//
//
// //OLD
//
// //#include <vector>
// //#include <memory>
// //#include <chrono>
// //#include <string>
// //#include "DebugTools/Core/Logger/logger.hpp"
// //
// //
// //namespace debugtools
// //{
// //	Timer::Timer(std::string id) : m_Id(id)
// //	{
// //
// //
// //	//#ifdef DEBUG
// //		//TODO DEAL WITH THIS debugtools::Logger::Log(debugtools::LogLevel::Info, "Timer with ID '" + std::string(id) + "' created.");
// //	//#endif // DEBUG
// //	}
// //
// //	Timer::~Timer()
// //	{
// //	#ifdef DEBUG
// //		//TODO DEAL WITH THIS debugtools::Logger::Log(debugtools::LogLevel::Info, "Timer with ID '" + std::string(m_Id) + "' destroyed.");
// //	#endif // DEBUG
// //	}
// //
// //	void Timer::Start()
// //	{
// //
// //		m_TimeStart = std::chrono::steady_clock::now();
// //
// //	}
// //
// //	void Timer::Stop()
// //	{
// //		auto difference  = std::chrono::steady_clock::now() - m_TimeStart;
// //		auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(difference).count();
// //
// //    //void Timer::Stop()
// //    //{
// //    //    auto difference = std::chrono::steady_clock::now() - m_TimeStart;
// //    //    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(difference).count();
// //
// //        //TODO DEAL WITH THIS debugtools::Logger::Log(debugtools::LogLevel::Info, "Elapsed time: [ " + std::to_string(elapsedTime) + " ms]");
// //    }
// //
// //
// //
// //
// //
// //
// //
// //	void Timer::Reset()
// //	{
// //
// //	}
// //
// //	void Timer::Pause() {}
// //	void Timer::Mark() {}
// //	void Timer::Mark(const char* text) {}
// //	//void Timer::etId() {}
// //
// //
// //
// //
// //
// //
// //
// //
//

