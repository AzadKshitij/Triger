/*------------ Copyright © 2020 Azad Kshitij. All rights reserved. ------------
//
//   Project     : Triger
//   License     : https://opensource.org/licenses/MIT
//   File        : Base.h
//   Created On  : 07/11/2020
//   Updated On  : 29/11/2020
//   Created By  : Azad Kshitij @AzadKshitij
//--------------------------------------------------------------------------*/
#pragma once

#include <memory>
#include "Triger/Core/PlatformDetection.h"

#ifdef TR_DEBUG
#if defined(TR_PLATFORM_WINDOWS)
#define TR_DEBUGBREAK() __debugbreak()
#elif defined(TR_PLATFORM_LINUX)
#include <signal.h>
#define TR_DEBUGBREAK() raise(SIGTRAP)
#else
#error "Platform doesn't support debugbreak yet!"
#endif
#define TR_ENABLE_ASSERTS
#else
#define TR_DEBUGBREAK()
#endif

#ifdef TR_ENABLE_ASSERTS
#define TR_ASSERT(x, ...)                                   \
	{                                                       \
		if (!(x))                                           \
		{                                                   \
			TR_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
			TR_DEBUGBREAK();                                \
		}                                                   \
	}
#define TR_CORE_ASSERT(x, ...)                                   \
	{                                                            \
		if (!(x))                                                \
		{                                                        \
			TR_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
			TR_DEBUGBREAK();                                     \
		}                                                        \
	}
#else
#define TR_ASSERT(x, ...)
#define TR_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define TR_BIND_EVENT_FN(fn) [this](auto &&...args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace Triger
{

	template <typename T>
	using Scope = std::unique_ptr<T>;
	template <typename T, typename... Args>
	constexpr Scope<T> CreateScope(Args &&...args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template <typename T>
	using Ref = std::shared_ptr<T>;
	template <typename T, typename... Args>
	constexpr Ref<T> CreateRef(Args &&...args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}
