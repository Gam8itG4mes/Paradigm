#pragma once

#include <memory.h>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Paradigm 
{
	class PARADIGM_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger> & GetCoreLogger(){return s_CoreLogger;}
		inline static std::shared_ptr<spdlog::logger> & GetClientLogger(){return s_ClientLogger;}
		
		
	private: 
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
} 

/*Core log macros*/
#define PD_CORE_ERROR(...)    ::Paradigm::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PD_CORE_WARN(...)     ::Paradigm::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PD_CORE_INFO(...)     ::Paradigm::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PD_CORE_TRACE(...)    ::Paradigm::Log::GetCoreLogger()->trace(__VA_ARGS__)
//#define PD_CORE_FATAL(...)    ::Paradigm::Log::GetCoreLogger()->fatal(__VA_ARGS__)

/*Client log macros*/
#define PD_CLIENT_ERROR(...)  ::Paradigm::Log::GetClientLogger()->error(__VA_ARGS__)
#define PD_CLIENT_WARN(...)   ::Paradigm::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PD_CLIENT_INFO(...)   ::Paradigm::Log::GetClientLogger()->info(__VA_ARGS__)
#define PD_CLIENT_TRACE(...)  ::Paradigm::Log::GetClientLogger()->trace(__VA_ARGS__)
//#define PD_CLIENT_FATAL(...)  ::Paradigm::Log::GetClientLogger()->fatal(__VA_ARGS__)
//fatal is apparently not an error tier. 