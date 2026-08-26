//
// Created by nazzazel on 26.08.2026.
//

#include "TimerSystem.hpp"

namespace engine
{

    Result TimerSystem::OnInit()
    {
        m_SystemManager = this->GetSystemManager();

        if (!m_SystemManager)
        {
            return SYSTEM_RESULT(SystemManagerNotSet,Error);//todo
        }

        m_Logger = m_SystemManager->GetSystem<LoggerSystem>();

        if (!m_Logger)
        {
            return SYSTEM_RESULT(SystemNotFound,Error);//todo
        }

        return {};
    }

    Result TimerSystem::OnUpdate(float dt)
    {
        return {};
    }

    Result TimerSystem::OnShutdown()
    {
        return {};
    }


    // bool TimerSystem::SetCurrent(const std::string& id)
    // {
    //     m_Current = FindTimer(id);
    //     if (m_Current != nullptr)
    //     {
    // 		//TODO DEAL WITH THIS debugtools::Logger::Log(debugtools::LogLevel::Info, "Succesfully setted timer with id '" + id + "' as a current Timer");
    // 		return true;
    //     }
    //     else
    //     {
    // 		//TODO DEAL WITH THIS debugtools::Logger::Log(debugtools::LogLevel::Warning,
    // 			"Timer with id '" + id + "' not found in TimerManager. Current timer not set.");
    //     }
    // 	//TODO DEAL WITH THIS debugtools::Logger::Log(debugtools::LogLevel::Warning, "Failed to set current timer with id '" + id + "'. Please check if the timer exists in TimerManager.");
    // 	return false;
    // }
    //


    void TimerSystem::AddTimer(const std::string& id)
    {
        if (FindTimer(id))
        {

            m_Logger->AddError("Timer with id '" + id + "' already exists in TimerSystem.");

        	//TODO DEAL WITH THIS debugtools::Logger::Log(debugtools::LogLevel::Warning,
        		//"Timer with id '" + id + "' already exists in TimerManager.");
             return;

        }

        m_Logger->AddInfo("Added timer with id '" + id + "");
        //TODO DEAL WITH THIS debugtools::Logger::Log(debugtools::LogLevel::Info,
        	//"Added timer with id '" + id + "' to TimerManager.");
        m_Timers.emplace_back(std::make_unique<Timer>(id));
    }

    void TimerSystem::RemoveTimer(const std::string& id)
    {
        m_Timers.erase(
            std::remove_if(m_Timers.begin(), m_Timers.end(),
                [&](const std::unique_ptr<Timer>& t)
                {
                    return t->GetId() == id;
                }),
            m_Timers.end());


        m_Logger->AddInfo("Removed timer with id '" + id + "");


        //TODO DEAL WITH THIS debugtools::Logger::Log(debugtools::LogLevel::Info,
        	//"Removed timer with id '" + id + "' from TimerManager.");

        if (m_Current && m_Current->GetId() == id)
            m_Current = nullptr;
    }

    void TimerSystem::StartTimer(const std::string& id)
    {
        m_Current = FindTimer(id);

        if (m_Current)
        {
            m_Current->Start();
            m_Logger->AddInfo( "Started timer with id '" + id + "" );

        }
        else
        {
          m_Logger->AddWarning( "m_Current : nullptr - Timer does not exist in TimerSystem." );
        }
    }

    void TimerSystem::StopTimer(const std::string& id)
    {
        m_Current = FindTimer(id);
        if (m_Current)
        {
            //TODO DEAL WITH THIS debugtools::Logger::Log(debug_conf, debugtools::LogLevel::Info, "Stopping timer '");
           ////TODO DEAL WITH THIS debugtools::Logger::Log(debugtools::LogLevel::Info, "Stopped timer '" + m_Current->GetId() + "'. Elapsed time: " + std::to_string(m_Current->ElapsedMs()) + " ms.");
            m_Logger->AddInfo( "Stopped timer '" + m_Current->GetId() + "'. Elapsed time: " );
            GetElapsedMs();
            m_Current->Stop();
        }
        else
        {
            m_Logger->AddWarning( "m_Current : nullptr - Timer does not exist in TimerSystem." );
        }
    }

    void TimerSystem::ResetTimer()
    {
        if (m_Current)
        {
            m_Logger->AddInfo( "Result timer " + m_Current->GetId() + "" );
            m_Current->Reset();
        }
        else
        {
            m_Logger->AddWarning( "m_Current : nullptr - Timer does not exist in TimerSystem." );
        }
    }

    void TimerSystem::GetElapsedMs() const
    {
        if (!m_Current)
        {
            m_Logger->AddWarning( "m_Current : nullptr - Timer does not exist in TimerSystem." );
            return ;
        }

        	m_Logger->AddWarning("Elapsed time for timer '" , m_Current->GetId() , "': ",
        	 m_Current->ElapsedMs()," ", m_Current->GetUnit()),".";
        return;// m_Current->ElapsedMs();
    }

    void TimerSystem::SetTimerAccuracy(Timer::Accuracy accuracy) const
    {
        if (!m_Current)
        {
            m_Logger->AddWarning( "m_Current : nullptr - Timer does not exist in TimerSystem." );
            return ;
        }
        m_Current->SetAccuracy(accuracy);
        m_Logger->AddWarning("Set timer accuracy to [",m_Current->GetAccuracy() ,"] for timer '" + m_Current->GetId() + "'");
        return;// m_Current->ElapsedMs();
    }

    Timer* TimerSystem::FindTimer(const std::string& id)
    {
        for (auto& timer : m_Timers)
        {
            if (timer->GetId() == id)
                return timer.get();
        }
        return nullptr;
    }



} // engine