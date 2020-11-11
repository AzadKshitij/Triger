#pragma once

#include <memory>

#ifdef TR_PLATFORM_WINDOWS
#if TR_DYNAMIC_LINK

	#ifdef TR_BUILD_DLL
		#define TRIGER_API __declspec(dllexport)
	#else 
		#define TRIGER_API __declspec(dllimport)
	#endif // TR_BUILD_DLL

#else
	#define TRIGER_API
#endif
#else
	#error Triget only supports Windows!
#endif // TR_PLATEFORM_WINDOWS

// So that TR_ASSERTS will only work in debug build
#ifdef TR_DEBUG
	#define TR_ENABLE_ASSERTS
#endif // TR_DEBUG

//Will Be removed in Relese build
#ifdef TR_ENABLE_ASSERTS
	#define TR_ASSERT(x, ...) { if(!(x)) { TR_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define TR_CORE_ASSERT(x, ...) { if(!(x)) { TR_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define TR_ASSERT(x, ...)
	#define TR_CORE_ASSERT(x, ...)
#endif //TR_ENABLE_ASSERTS


#define BIT(x) (1 << x)

#define TR_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace Triger {

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}