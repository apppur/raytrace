#ifdef WIN32
#include <Windows.h>
#endif

#include "Common.h"

time_t GetMicrosecondeNow()
{
	struct timeval val;
#ifdef WIN32
	LARGE_INTEGER liTime, liFreq;
	QueryPerformanceFrequency(&liFreq);
	QueryPerformanceCounter(&liTime);
	val.tv_sec = (long)(liTime.QuadPart / liFreq.QuadPart);
	val.tv_usec = (long)(liTime.QuadPart * 1000000.0 / liFreq.QuadPart - val.tv_sec * 1000000.0);
#else
	gettimeofday((struct timeval *)&val, NULL);
#endif
	return (val.tv_sec*1000000.0 + val.tv_usec);
}