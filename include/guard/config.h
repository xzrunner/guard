#pragma once

// code from https://github.com/SergeyMakeev/TaskScheduler

// Target Platform
////////////////////////////////////////////////////////////////////////
#if   _WIN32

#define MT_PLATFORM_WINDOWS (1)

#elif __APPLE_CC__

#define MT_PLATFORM_OSX (1)

#else

#define MT_PLATFORM_POSIX (1)

#endif

// Debug / Release
////////////////////////////////////////////////////////////////////////

#if defined(_DEBUG) || defined(DEBUG)

#define GD_DEBUG (1)

#else

#define GD_RELEASE (1)

#endif
