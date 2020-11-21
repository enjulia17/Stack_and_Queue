#pragma once
#include <iostream>

using namespace std;

template<class T>
class Stack
{
protected:
	const T** Array;
	int size;
	int last;
	int DataCount;

public:
	Stack();
	Stack(int _size);
	Stack(Stack& _stack);
	~Stack();

	void push(T& _stack);
	const T& pop();
	bool IsEmpty();
	bool IsFull();
	int GetSize();
	void SetMemory(void* p, int _size);

	void transform();
};

template<class T>
inline Stack<T>::Stack()
{
	Array = 0;
	size = 0;
	last = 0; //свободная позиция (так как по хвосту я добавляю)
}

template<class T>
inline Stack<T>::Stack(int _size)
{
	if (_size < 0)throw logic_error("negative size");
	Array = new const T*[_size];
	size = _size;
	last = 0;
}

template<class T>
inline Stack<T>::Stack(Stack & _stack) //конструктор копирования
{
	Array = new const T*[_stack.size];
	for (int i = 0; i < last; i++)
		Array[i] = _stack.Array[i];
	size = _stack.size;
	last = _stack.last;
}

template<class T>
inline Stack<T>:: ~Stack()
{
	delete[] Array;
	size = 0;
	last = 0;
}

template<class T>
inline bool Stack<T>::IsEmpty()
{
	return(last == 0);
}

template<class T>
inline bool Stack<T>::IsFull()
{
	return(last == size);
}

template<class T>
inline void Stack<T>::push(T & _stack)
{
	if ((*this).IsFull()) throw logic_error("Container is full");
	if (Array == 0) throw logic_error("memory error");
	Array[last] = &_stack;
	last++;
}

template<class T>
inline const T& Stack<T>::pop()
{
	if (this->IsEmpty()) throw logic_error("Stack is empty");
	if (Array == 0) throw logic_error("memory error");
	const T* tmp = Array[last - 1];
	last--;
	return (*tmp);
}

template<class T>
inline int Stack<T>::GetSize()
{
	return size;
}

template<class T>
inline void Stack<T>::SetMemory(void* p, int _size)
{
	if (Array != 0)
	{
		delete[] Array;
	}
	Array = new const T*[_size];
	T* tmp = static_cast<T*>(p);
	for (int i = 0; i < _size; i++)
	{
		Array[i] = tmp + i;
	}
	size = _size;
	last = _size;
	DataCount = _size;
}

//Доп.задание
template<class T>
inline void Stack<T>::transform()
{
	const T** temp_arr;
	temp_arr = new const T*[size];
	const T* temp = nullptr;
	int counter = 0;
	for (int i = 0; i < last; i++)
	{
		if (*Array[i] % 2 == 1)
		{
			if (temp == nullptr)
			{
				temp_arr[counter] = Array[i];
				counter++;
			}

			if (temp != nullptr)
			{
				temp_arr[counter] = temp;
				temp = nullptr;
				counter++;
				temp_arr[counter] = Array[i];
				counter++;
			}
		}
		else
		{
			if (temp == nullptr)
				temp = Array[i];
			else if (temp != nullptr)
				if (*temp < *Array[i])
					temp = Array[i];
			if (i == last - 1)
			{
				temp_arr[counter] = temp;
				counter++;
			}
		}
	}

	last = counter;
	DataCount = last;
	delete[] Array;
	Array = new const T*[size];
	for (int i = 0; i < last; i++)
		Array[i] = temp_arr[i];
	delete[] temp_arr;

}


