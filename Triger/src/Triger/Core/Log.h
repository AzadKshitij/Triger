/*------------ Copyright © 2020 Azad Kshitij. All rights reserved. ------------
//
//   Project     : Triger
//   License     : https://opensource.org/licenses/MIT
//   File        : Log.h
//   Created On  : 07/11/2020
//   Updated On  : 30/11/2020
//   Created By  : Azad Kshitij @AzadKshitij
//--------------------------------------------------------------------------*/
#pragma once

#include "Triger/Core/Base.h"

//#define 
#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/string_cast.hpp"

// This ignores all warnings raised inside External headers
#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace Triger
{
	/**
	 * @brief 
	*/
	class Log
	{

	public:
		//static std::vector<spdlog::sink_ptr> logSinks;

	public:
		/**
		 * @brief 
		*/
		static void Init();

		/**
		 * @brief 
		 * @return 
		*/
		inline static std::shared_ptr<spdlog::logger> &GetCoreLogger() { return s_CoreLogger; }

		/**
		 * @brief 
		 * @return 
		*/
		inline static std::shared_ptr<spdlog::logger> &GetClientLogger() { return s_ClientLogger; }

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

template<typename OStream, glm::length_t L, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, const glm::vec<L, T, Q>& vector)
{
	return os << glm::to_string(vector);
}

template<typename OStream, glm::length_t C, glm::length_t R, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, const glm::mat<C, R, T, Q>& matrix)
{
	return os << glm::to_string(matrix);
}

template<typename OStream, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, glm::qua<T, Q> quaternion)
{
	return os << glm::to_string(quaternion);
}


// Core log macros
#define TR_CORE_TRACE(...) ::Triger::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define TR_CORE_INFO(...) ::Triger::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TR_CORE_WARN(...) ::Triger::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TR_CORE_ERROR(...) ::Triger::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TR_CORE_CRITICAL(...) ::Triger::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define TR_TRACE(...) ::Triger::Log::GetClientLogger()->trace(__VA_ARGS__)
#define TR_INFO(...) ::Triger::Log::GetClientLogger()->info(__VA_ARGS__)
#define TR_WARN(...) ::Triger::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TR_ERROR(...) ::Triger::Log::GetClientLogger()->error(__VA_ARGS__)
#define TR_CRITICAL(...) ::Triger::Log::GetClientLogger()->critical(__VA_ARGS__)
