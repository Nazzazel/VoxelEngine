#pragma once

#pragma once

#include <string>
#include <chrono>

namespace debugtools
{
    class Timer
    {
    public:
        explicit Timer(const std::string& id);

        void Start();
        void Stop();
        void Reset();

        long long ElapsedMs() const;
        const std::string& GetId() const;

    private:
        std::string m_Id;

        std::chrono::steady_clock::time_point m_StartTime;
        std::chrono::steady_clock::time_point m_EndTime;

        bool m_Running = false;
    };
}



//#include <vector>
//#include <memory>
//#include <string>
//#include <chrono>
//
//namespace debugtools
//{
//	//#define TIMER_MANAGER debugtools::TimerManager
//
//
//
//	class Timer
//	{
//	public:
//		Timer(std::string id); //Special id for the timer, can be used to identify it in a list of timers 
//		~Timer();
//
//
//
//		//State Machine Functions
//		void Start();
//		void Stop();
//		void Reset();
//		void Pause();
//		void Mark();
//		void Mark(const char* text);
//
//
//
//
//
//	////Utility Functions
//	//void ShouldPrintId(bool state) {};
//	//
//	////Getters
//	//float	GetElapsedTime() { return 0.0f; }
//	//void	PrintElapsedTime() {};
//	////Setter
//	//void SetId(const char* id) { m_Id = id; };
//
//
//		
//		std::string GetId() { return m_Id; };
//
//
//	private:
//		std::string m_Id;
//
//		std::chrono::steady_clock::time_point m_TimeStart;
//
//	};
//
//	class TimerManager
//	{
//	public:
//		TimerManager();
//		~TimerManager(); //TODO
//
//		static void AddTimer(const char* title);
//		static void RemoveTimer(const char* title);
//		//static void GetTimer(const char* title);
//
//
//		//State Machine Functions
//		static  void Start();
//		static  void Stop();
//		static  void Reset();
//		static  void Pause();
//		static  void Mark();
//		static  void Mark(const char* text);
//
//
//		//Allows you to try settetting the ID of a timer.
//		static void SetTimer(const char* title);//If fail Error in console
//
//
//
//		//static void CurrentTime();
//		static std::string CurrentTime();
//		//
//
//		//void SetInstance();
//
//	private:
//
//		static std::vector<std::unique_ptr<Timer>> m_Timers;
//		static Timer* m_CurrentTimer;
//
//	};
//}


