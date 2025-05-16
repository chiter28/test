#pragma once
#include <vector>
#if defined(WIN32) || defined(_WINDOWS)
	#ifdef EXPORT
		#define MATH_API __declspec(dllexport)
	#elif IMPORT 
		#define MATH_API __declspec(dllimport)
	#else 
		#define MATH_API
	#endif // EXPORT
#else
	#define MATH_API __attribute__((visibility("default")))
#endif

MATH_API int factorial(int n);
MATH_API int max(int x, int y);
MATH_API int sum(int n);
MATH_API int randomInt(int min, int max);
