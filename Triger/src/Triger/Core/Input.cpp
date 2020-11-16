#include "trpch.h"
#include "Triger/Core/Input.h"

#ifdef TR_PLATFORM_WINDOWS
#include "Triger/Platform/Windows/WindowsInput.h"
#endif

namespace Triger {

	Scope<Input> Input::s_Instance = Input::Create();

	Scope<Input> Input::Create()
	{
#ifdef TR_PLATFORM_WINDOWS
		return CreateScope<WindowsInput>();
#else
		TR_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif
	}
}