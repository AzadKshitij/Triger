#pragma once
#include <iostream>
#include <string>
#include <vector>

namespace Tridor
{
	class AppLog
	{
	public:
		AppLog() = default;
		~AppLog() = default;

		std::pair<int, char*> logMessage;
		std::vector<std::pair<int, char*>> logMessages;
		void putMessage(int level, char* message);
	};
}



//::Triger::Log::GetCoreLogger()->trace(__VA_ARGS__)
