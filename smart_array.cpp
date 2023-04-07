#include <string>
#include "smart_array.h"
#include "array_exception.h"

static const std::string over_arr_msg = "Массив переполнен. Значение не добавлено!";

smart_array::smart_array(int size) : 
	_size(size),
	_index(0)
{
	arr = new int[_size];
}

smart_array& smart_array::operator=(smart_array& op_right)
{
	int size = op_right.get_size();
	if (_size != size)
	{
		_size = size;
		delete[] arr;

		arr = new int[_size];
	}

	for (int i = 0; i < _size; ++i)
	{
		arr[i] = op_right.get_element(i);
	}

	return *this;
}

smart_array::~smart_array()
{
	delete[] arr;
	arr = nullptr;
}

void smart_array::add_element(int value)
{
	if (_index >= _size)
	{
		throw ArrayException(over_arr_msg);
	}

	arr[_index] = value;
	++_index;
}

int smart_array::get_size()
{
	return _size;
}

int smart_array::get_element(int index)
{
	if (index < 0 || _size <= index)
	{
		const std::string msg = "Массив не содержит элемента с индексом: "
			+ std::to_string(index);

		throw ArrayException(msg);
	}

	return arr[index];
}
