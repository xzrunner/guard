#pragma once

#include <exception>
#include <string>

namespace guard
{

class Exception : public std::exception
{
public:
	Exception(const std::string& msg);
	Exception(const char* fmt, ...);
	virtual ~Exception() throw() {}

	virtual const char* what() const throw() {
		return m_message.c_str();
	}

private:
	std::string m_message;

}; // Exception

}
