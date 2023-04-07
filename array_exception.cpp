#include "array_exception.h"


ArrayException::ArrayException(const std::string& msg) :
	_msg(msg)
{}

const char* ArrayException::what() const noexcept
{
	return _msg.c_str();
}

ArrayException::~ArrayException()
{}
