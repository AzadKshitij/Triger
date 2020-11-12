/**
 *  @file   Log.h
 *  @brief  Loging system for core and applications
 *  @author Kshitij Azad
 *  @date   November 2, 2020
 ***********************************************/
#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Triger
{
	/**
	 * @brief 
	*/
	class TRIGER_API Log
	{
	public:

		/**
		 * @brief 
		*/
		static void Init();
		
		/**
		 * @brief 
		 * @return 
		*/
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		
		/**
		 * @brief 
		 * @return 
		*/
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:

		/**
		 * @brief 
		*/
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		
		/**
		 * @brief 
		*/
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
