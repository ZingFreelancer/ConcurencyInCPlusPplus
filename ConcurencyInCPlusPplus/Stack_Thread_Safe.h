#pragma once
#include <stack>
#include <mutex>

template<typename T>
class Stack_Thread_Safe
{
	std::stack<T> _stack;
	std::mutex _mutex;
public:
	void push(T element);
	void pop();
	T& top();
	T& topAndPop();
	bool make_empty();
	size_t size() const;
};


