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

#define BIT(x) (1 << x)