#include "guard/Exception.h"

#include <cstdarg>

#include <stdio.h>
#include <string.h>

namespace guard
{

Exception::Exception(const std::string& msg)
	: m_message(msg)
{
}

Exception::Exception(const char* fmt, ...)
{
	char buff[256];
	memset(buff, 0, sizeof(buff));
	va_list args;
	va_start(args, fmt);
	int size_out = vsnprintf(buff, sizeof(buff) - 1, fmt, args);
	va_end(args);
	if (size_out != -1) {
		m_message = std::string(buff);
	}
}

}