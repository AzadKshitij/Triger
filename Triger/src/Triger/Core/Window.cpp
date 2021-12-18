/*------------ Copyright © 2020 Azad Kshitij. All rights reserved. ------------
//
//   Project     : Triger
//   License     : https://opensource.org/licenses/MIT
//   File        : Window.cpp
//   Created On  : 16/11/2020
//   Updated On  : 16/11/2020
//   Created By  : Azad Kshitij @AzadKshitij
//--------------------------------------------------------------------------*/
#include "trpch.h"
#include "Triger/Core/Window.h"

#ifdef TR_PLATFORM_WINDOWS
#include "Triger/Platform/Windows/WindowsWindow.h"
#endif

namespace Triger
{

	Scope<Window> Window::Create(const WindowProps& props)
	{
#ifdef TR_PLATFORM_WINDOWS
		return CreateScope<WindowsWindow>(props);
#else
		TR_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif
	}
}
