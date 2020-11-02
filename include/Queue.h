#pragma once
#include <iostream>

using namespace std;
template<class T>
class Queue

{
protected:

	const T** Array;
	int size;
	int first;
	int last;
	int DataCount;

public:
	Queue();
	Queue(int _size);
	Queue(Queue& _queue);
	~Queue();

	void push(T& _queue);
	const T& pop();
	bool IsEmpty();
	bool IsFull();
	int GetSize();
	
};

template<class T>
inline Queue<T>::Queue()
	{
		Array = 0;
		size = 0;
		first = 0; // голова
		last = 0; // хвост (свободная позиция)
		DataCount = 0;
	}

template<class T>
inline Queue<T>::Queue(int _size)
	{
		if (_size < 0) throw logic_error("negative size");
		Array = new const T*[_size];
		size = _size;
		first = 0;
		last = 0;
		DataCount = 0;
	}

template<class T>
inline Queue<T>::Queue(Queue & _queue) //конструктор копирования
	{
		Array = new const T*[_queue.size];
		for (int i = first; i < last; i++)
			Array[i] = _queue.Array[i];
		size = _queue.size;
		first = _queue.first;
		last = _queue.last;
		DataCount = _queue.DataCount;
	}

template<class T>
inline Queue<T>:: ~Queue()
	{
		delete[] Array;
		size = 0;
		first = 0;
		last = 0;
		
	}

template<class T>
inline bool Queue<T>::IsEmpty()
	{
		return(DataCount == 0);
	}

template<class T>
inline bool Queue<T>::IsFull()
	{
		return(DataCount == size);
	}

template<class T>
inline void Queue<T>::push(T & _queue) // добавляем элемент в очередь
	{
		if ((*this).IsFull()) throw logic_error("Container is full");
		if (Array == 0) throw logic_error("memory error");
		Array[last] = &_queue;
		last = (last + 1) % size;
		DataCount++;
	}

template<class T>
inline const T& Queue<T>::pop() //выводим и убираем элемент из очереди
	{
		if (this->IsEmpty()) throw logic_error("Queue is empty");
		if (Array == 0) throw logic_error("memory error");
		const T* tmp = Array[first];
		first = (first + 1) % size;
		DataCount--;
		return (*tmp);
	}

template<class T>
inline int Queue<T>::GetSize()
	{
		return size;
	}

