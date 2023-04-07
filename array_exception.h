#ifndef ARRAY_EXCEPTION_H
#define ARRAY_EXCEPTION_H

#include <string>


class ArrayException : public std::exception
{
	const std::string _msg;

	public:
	ArrayException(const std::string& msg);
	virtual ~ArrayException();

	const char* what() const noexcept override;
};

#endif
