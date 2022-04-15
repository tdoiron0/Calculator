#pragma once

#ifdef EN_PLATFORM_WINDOWS
	#ifdef EN_BUILD_DLL
		#define EN_API __declspec(dllexport)
	#else
		#define EN_API __declspec(dllimport)
	#endif
#else 
	#error Only supported on Windows
#endif