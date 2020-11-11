#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Triger
{

	class TRIGER_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
} // namespace Triger

// Core log macros
#define TR_CORE_TRACE(...)        ::Triger::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define TR_CORE_INFO(...)         ::Triger::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TR_CORE_WARN(...)         ::Triger::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TR_CORE_ERROR(...)        ::Triger::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TR_CORE_CRITICAL(...)     ::Triger::Log::GetCoreLogger()->critical(__VA_ARGS__)
								
// Client log macros			
#define TR_TRACE(...)	          ::Triger::Log::GetClientLogger()->trace(__VA_ARGS__)
#define TR_INFO(...)	          ::Triger::Log::GetClientLogger()->info(__VA_ARGS__)
#define TR_WARN(...)	          ::Triger::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TR_ERROR(...)	          ::Triger::Log::GetClientLogger()->error(__VA_ARGS__)
#define TR_CRITICAL(...)	      ::Triger::Log::GetClientLogger()->critical(__VA_ARGS__)
