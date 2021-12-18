/*------------ Copyright © 2020 Azad Kshitij. All rights reserved. ------------
//
//   Project     : Tridor
//   License     : https://opensource.org/licenses/MIT
//   File        : TridorApp.cpp
//   Created On  : 27/11/2020
//   Updated On  : 27/11/2020
//   Created By  : Azad Kshitij @AzadKshitij
//--------------------------------------------------------------------------*/
#include <Triger.h>
#include <Triger/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Triger
{

	class Tridor : public Application
	{
	public:
		Tridor(ApplicationCommandLineArgs args)
			: Application("Tridor", args)
		{
			PushLayer(new EditorLayer());
		}

		~Tridor()
		{
		}
	};

	Application* CreateApplication(ApplicationCommandLineArgs args)
	{
		return new Tridor(args);
	}
}
