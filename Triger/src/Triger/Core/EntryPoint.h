/**
 *  @file   EntryPoint.h
 *  @brief  Entry point for any new application
 *  @author Kshitij Azad
 *  @date   November 2, 2020
 ***********************************************/
#pragma once

#include "Triger/Core/Core.h"

#ifdef TR_PLATFORM_WINDOWS

extern Triger::Application *Triger::CreateApplication();

int main(int argc, char **argv)
{
	Triger::Log::Init();
	TR_CORE_INFO("*************************************************************");
	TR_CORE_INFO("*  _________________   ________________   ________________  *" );
	TR_CORE_INFO("* |_______    ______| |  |   _______   | |______    ______| *" );
	TR_CORE_INFO("*         |  |        |  |  |       |  |        |  |        *" );
	TR_CORE_INFO("*         |  |        |  |  |       |  |        |  |        *" );
	TR_CORE_INFO("*         |  |        |  |  |_______|  |        |  |        *" );
	TR_CORE_INFO("*         |  |        |  |_____________|        |  |        *" );
	TR_CORE_INFO("*         |  |        |  |      |_____|         |  |        *" );
	TR_CORE_INFO("*         |  |        |  |        |___|         |  |        *" );
	TR_CORE_INFO("*         |  |        |  |          |_|    _____|  |______  *" );
	TR_CORE_INFO("*         |__|        |__|          |_|   |_______________| *" );
	TR_CORE_INFO("*************************************************************");
	//TR_CORE_INFO("Triger Core Is Running ");
	TR_INFO("Sandbox Is Running");

	auto app = Triger::CreateApplication();
	app->Run();
	delete app;
}

#endif