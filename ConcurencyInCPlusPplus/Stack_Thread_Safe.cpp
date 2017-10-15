#include "stdafx.h"
#include "Stack_Thread_Safe.h"

template<typename T>
void Stack_Thread_Safe<T>::push(T element)
{
	std::lock_guard<std::mutex>lg(_mutex);
	_stack.push(element);
}

template<typename T>
void Stack_Thread_Safe<T>::pop()
{
	std::lock_guard<std::mutex>lg(_mutex);
	_stack.pop();
}

template<typename T>
T & Stack_Thread_Safe<T>::top()
{
	std::lock_guard<std::mutex>lg(_mutex);
	return _stack.top();
}

template<typename T>
T & Stack_Thread_Safe<T>::topAndPop()
{
	std::lock_guard<std::mutex>lg(_mutex);
	T& re = _stack.top();
	_stack.pop();
	return re;
}

template<typename T>
bool Stack_Thread_Safe<T>::make_empty()
{
	std::lock_guard<std::mutex>lg(_mutex);
	return _stack.empty();
}

template<typename T>
size_t Stack_Thread_Safe<T>::size() const
{
	std::lock_guard<std::mutex>lg(_mutex);
	return _stack.size();
}
