#include "guard/Diagnostic.h"
#include "guard/config.h"

#include <logger.h>

#if MT_PLATFORM_WINDOWS 

inline void ThrowException()
{
	__debugbreak();
}

#elif MT_PLATFORM_POSIX

#include<signal.h>
inline void ThrowException()
{
	raise(SIGTRAP);
	// force access violation error
	char* pBadAddr = (char*)0x0;
	*pBadAddr = 0;
}

#elif MT_PLATFORM_OSX

inline void ThrowException()
{
	__builtin_trap();
}

#else

#error Platform is not supported!

#endif

namespace guard
{

void Diagnostic::ReportAssert(const char* condition, const char* description, const char* sourceFile, int sourceLine)
{
	LOGD("Assertion failed : %s. File %s, line %d. Condition %s\n", description, sourceFile, sourceLine, condition);
	ThrowException();
}

}