#pragma once

#ifdef PD_PLATFORM_WINDOWS
	#ifdef PD_BUILD_DLL
		#define PARADIGM_API __declspec(dllexport)
	#else
		#define PARADIGM_API __declspec(dllimport)	
	#endif
#else 
	#error Paradigm is only supported on Windows!
#endif

#define BIT(x) (1 << x)