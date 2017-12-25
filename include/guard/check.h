#pragma once

// code from https://github.com/SergeyMakeev/TaskScheduler

#include "guard/config.h"
#include "guard/Diagnostic.h"

#if defined(GD_DEBUG) || defined(GD_INSTRUMENTED_BUILD)

#define GD_REPORT_ASSERT_IMPL( condition, description, file, line ) guard::Diagnostic::ReportAssert(#condition, description, file, line);

#ifndef GD_REPORT_ASSERT
#define GD_REPORT_ASSERT( description ) { GD_REPORT_ASSERT_IMPL( "always", description, __FILE__, __LINE__ ) }
#endif

#ifndef GD_ASSERT
#define GD_ASSERT( condition, description ) { if ( !(condition) ) { GD_REPORT_ASSERT_IMPL( #condition, description, __FILE__, __LINE__ ) } }
#endif

#ifndef GD_VERIFY
#define GD_VERIFY( condition, description, operation ) { if ( !(condition) ) { { GD_REPORT_ASSERT_IMPL( #condition, description, __FILE__, __LINE__ ) }; operation; } }
#endif

#else

#ifndef GD_REPORT_ASSERT
#define GD_REPORT_ASSERT( description )
#endif

#ifndef GD_ASSERT
#define GD_ASSERT( condition, description )
#endif

#ifndef GD_VERIFY
#define GD_VERIFY( condition, description, operation ) { if ( !(condition) ) { operation; } }
#endif

#endif