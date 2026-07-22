// #include "time_utils.hpp"
// #include <chrono>
// #include <ctime>
//
// namespace debugtools
// {
//     std::string debugtools::TimeUtil::CurrentTime()
//     {
//         auto now = std::chrono::system_clock::now();
//         auto time = std::chrono::system_clock::to_time_t(now);
//
//         std::tm tm{};
//         #if defined(_WIN32)
//         localtime_s(&tm, &time);
//         #else
//         localtime_r(&time, &tm); // Note: Linux reverses the argument order!
//         #endif
//
//         char buffer[16];
//         std::strftime(buffer, sizeof(buffer), "[%H:%M:%S]", &tm);
//
//         return buffer;
//     }
// }
//
// #include "time_utils.hpp"
// #include <chrono>
// #include <ctime>
//
// //namespace debugtools
// //{
// //	std::string debugtools::TimeUtil::CurrentTime()
// //	{
// //		std::string timeStr;
// //
// //		auto now = std::chrono::system_clock::now();
// //		auto now_time_t = std::chrono::system_clock::to_time_t(now);
// //		std::tm tm{};
// //		localtime_s(&tm, &now_time_t); // thread-safe version of localtime
// //
// //		auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
// //
// //		timeStr =
// //			"[ " +
// //			std::to_string(tm.tm_hour) + ":" +
// //			std::to_string(tm.tm_min) + ":" +
// //			std::to_string(tm.tm_sec) +
// //			" ]";
// //
// //		return timeStr;
// //	}
// //}
