#pragma once


#ifdef FREEZER_PLATFORM_WINDOWS
	#ifdef FREEZER_BUILD_DLL
		#define FREEZER_API __declspec(dllexport)
	#else
		#define FREEZER_API __declspec(dllimport)
	#endif
#else
	#error Freezer Engine only supports Windows!
#endif

#ifdef FREEZER_ENABLE_ASSERTS
	#define FREEZER_ASSERT(x, ...) { if(!(x)) {FREEZER_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define FREEZER_CORE_ASSERT(x, ...) { if(!(x)) {FREEZER_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define FREEZER_ASSERT(x, ...)
	#define FREEZER_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define FREEZER_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)