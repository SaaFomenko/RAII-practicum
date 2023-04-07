#ifndef SMART_ARRAY_H
#define SMART_ARRAY_H


class smart_array
{
	int _size;
	int* arr;
	int _index;

	public:
	smart_array(int size);
	smart_array& operator=(smart_array& op_right);
	virtual ~smart_array();

	void add_element(int value);
	int get_size();
	int get_element(int index);
};

#endif
