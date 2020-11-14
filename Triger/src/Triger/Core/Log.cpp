#include "trpch.h"
#include <spdlog/sinks/stdout_color_sinks.h>

#include "Log.h"


namespace Triger {

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		/*
		* [%T] -> Timestamp
		* %n -> Name of the console whether is is Core Or Client
		* %v%$ -> The message
		*/
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("Triger");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);

	}
}
