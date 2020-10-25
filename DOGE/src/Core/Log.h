#pragma once
#include "Core.h"

#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)

namespace DOGE
{
	class Log
	{
	public:
		static void Init();

		static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static Ref<spdlog::logger>  s_CoreLogger;
		static Ref<spdlog::logger>  s_ClientLogger;
	};
}

#define DOGE_CORE_INFO(...)     DOGE::Log::GetCoreLogger()->info(__VA_ARGS__)
#define DOGE_CORE_WARN(...)     DOGE::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define DOGE_CORE_ERROR(...)    DOGE::Log::GetCoreLogger()->error(__VA_ARGS__)
#define DOGE_CORE_CRITICAL(...) DOGE::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define DOGE_CORE_TRACE(...)    DOGE::Log::GetCoreLogger()->trace(__VA_ARGS__)

#define DOGE_INFO(...)     DOGE::Log::GetClientLogger()->info(__VA_ARGS__)
#define DOGE_WARN(...)     DOGE::Log::GetClientLogger()->warn(__VA_ARGS__)
#define DOGE_ERROR(...)    DOGE::Log::GetClientLogger()->error(__VA_ARGS__)
#define DOGE_CRITICAL(...) DOGE::Log::GetClientLogger()->critical(__VA_ARGS__)
#define DOGE_TRACE(...)    DOGE::Log::GetClientLogger()->trace(__VA_ARGS__)

#define DOGE_CORE_ASSERT(x, ...) if (!x) { DOGE_CORE_ERROR(__VA_ARGS__); __debugbreak; }  
#define DOGE_ASSERT(x, ...) if (!x) { DOGE_ERROR(__VA_ARGS__); __debugbreak; }  

