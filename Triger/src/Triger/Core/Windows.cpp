#include "trpch.h"
#include "Triger/Core/Window.h"

#ifdef TR_PLATFORM_WINDOWS
#include "Triger/Platform/Windows/WindowsWindow.h"
#endif

namespace Triger {

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