#pragma once

// code from https://github.com/SergeyMakeev/TaskScheduler

namespace guard
{

struct Diagnostic
{
	static void ReportAssert(const char* condition, const char* description, const char* sourceFile, int sourceLine);

}; // Diagnostic

}