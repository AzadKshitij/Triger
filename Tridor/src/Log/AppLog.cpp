#include "AppLog.h"

namespace Tridor
{
	void AppLog::putMessage(int level, char* message)
	{
		logMessage.first = level;
		logMessage.second = message;
		logMessages.push_back(logMessage);
	}
}
