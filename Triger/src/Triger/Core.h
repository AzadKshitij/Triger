#pragma once

#ifdef TR_PLATFORM_WINDOWS
	#ifdef TR_BUILD_DLL
		#define TRIGER_API __declspec(dllexport)
	#else 
		#define TRIGER_API __declspec(dllimport)
	#endif // TR_BUILD_DLL
#else 
	#error Triget only supports Windows!
#endif // TR_PLATEFORM_WINDOWS


//Will Be removed in Relese build
#ifdef TR_ENABLE_ASSERTS
	#define TR_ASSERT(x, ...) { if(!(x)) { TR_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define TR_CORE_ASSERT(x, ...) { if(!(x)) { TR_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define TR_ASSERT(x, ...)
	#define TR_CORE_ASSERT(x, ...)
#endif //TR_ENABLE_ASSERTS


#define BIT(x) (1 << x)
