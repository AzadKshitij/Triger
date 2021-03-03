/*------------ Copyright © 2020 Azad Kshitij. All rights reserved. ------------
//
//   Project     : Sandbox
//   License     : https://opensource.org/licenses/MIT
//   File        : SandboxApp.cpp
//   Created On  : 07/11/2020
//   Updated On  : 08/11/2020
//   Created By  : Azad Kshitij @AzadKshitij
//--------------------------------------------------------------------------*/
#include "Triger.h"
#include "Triger/Core/EntryPoint.h"

#include "Sandbox2D.h"
#include "ExampleLayer.h"

namespace Triger
{

	class Sandbox : public Application
	{
	public:
		Sandbox()
			: Application("Sandbox")
		{
			PushLayer(new Sandbox2D());
		}

		~Sandbox()
		{
		}
	};

	Application *CreateApplication()
	{
		return new Sandbox();
	}
}

//class Sandbox : public Triger::Application
//{
//public:
//	Sandbox()
//	{
//		// PushLayer(new ExampleLayer());
//		PushLayer(new Sandbox2D());
//	}
//
//	~Sandbox()
//	{
//	}
//};
//
//Triger::Application* Triger::CreateApplication()
//{
//	return new Sandbox();
//}
