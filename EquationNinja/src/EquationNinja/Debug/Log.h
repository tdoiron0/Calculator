#pragma once
#include "EquationNinja/Core.h"
#include "spdlog/spdlog.h"

#include <memory>

namespace ENlib {
	class EN_API Log {
	public: 
		Log(); 
		~Log(); 

		static void Init(); 

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//core macros 
#define EN_CORE_TRACE(...) ::ENlib::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define EN_CORE_INFO(...) ::ENlib::Log::GetCoreLogger()->info(__VA_ARGS__)
#define EN_CORE_WARN(...) ::ENlib::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define EN_CORE_ERROR(...) ::ENlib::Log::GetCoreLogger()->error(__VA_ARGS__)
#define EN_CORE_FATAL(...) ::ENlib::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//client macros 
#define EN_CLIENT_TRACE(...) ::ENlib::Log::GetClientLogger()->trace(__VA_ARGS__)
#define EN_CLIENT_INFO(...) ::ENlib::Log::GetClientLogger()->info(__VA_ARGS__)
#define EN_CLIENT_WARN(...) ::ENlib::Log::GetClientLogger()->warn(__VA_ARGS__)
#define EN_CLIENT_ERROR(...) ::ENlib::Log::GetClientLogger()->error(__VA_ARGS__)
#define EN_CLIENT_FATAL(...) ::ENlib::Log::GetClientLogger()->fatal(__VA_ARGS__)