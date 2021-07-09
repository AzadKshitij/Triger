/*------------ Copyright © 2020 Azad Kshitij. All rights reserved. ------------
//
//   Project     : Triger
//   License     : https://opensource.org/licenses/MIT
//   File        : EntryPoint.h
//   Created On  : 07/11/2020
//   Updated On  : 26/11/2020
//   Created By  : Azad Kshitij @AzadKshitij
//--------------------------------------------------------------------------*/
#pragma once

#include "Triger/Core/Base.h"
#include "Triger/Core/Application.h"

#ifdef TR_PLATFORM_WINDOWS

extern Triger::Application *Triger::CreateApplication(ApplicationCommandLineArgs args);

int main(int argc, char **argv)
{
	Triger::Log::Init();
	TR_CORE_INFO("*************************************************************");
	TR_CORE_INFO("*  _________________   ________________   ________________  *");
	TR_CORE_INFO("* |_______    ______| |  |   _______   | |______    ______| *");
	TR_CORE_INFO("*         |  |        |  |  |       |  |        |  |        *");
	TR_CORE_INFO("*         |  |        |  |  |       |  |        |  |        *");
	TR_CORE_INFO("*         |  |        |  |  |_______|  |        |  |        *");
	TR_CORE_INFO("*         |  |        |  |_____________|        |  |        *");
	TR_CORE_INFO("*         |  |        |  |      |_____|         |  |        *");
	TR_CORE_INFO("*         |  |        |  |        |___|         |  |        *");
	TR_CORE_INFO("*         |  |        |  |          |_|    _____|  |______  *");
	TR_CORE_INFO("*         |__|        |__|          |_|   |_______________| *");
	TR_CORE_INFO("*************************************************************");

	//TR_CORE_INFO("Triger Core Is Running ");
	TR_PROFILE_BEGIN_SESSION("Startup", "TrigerProfile-Startup.json");
	auto app = Triger::CreateApplication({argc, argv});
	TR_PROFILE_END_SESSION();

	TR_PROFILE_BEGIN_SESSION("Runtime", "TrigerProfile-Runtime.json");
	app->Run();
	TR_PROFILE_END_SESSION();

	TR_PROFILE_BEGIN_SESSION("Shutdown", "TrigerProfile-Shutdown.json");
	delete app;
	TR_PROFILE_END_SESSION();
}

#endif