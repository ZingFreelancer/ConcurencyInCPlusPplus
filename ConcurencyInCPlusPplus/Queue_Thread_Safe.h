#pragma once
#include <queue>
#include <thread>
#include <memory>
#include <mutex>
#include <condition_variable>

template<typename T>
class Queue_Thread_Safe
{
private:
	std::queue<std::shared_ptr<T>> _Queue;
	std::mutex _Mutex;
	std::condition_variable _CV;

public:
	//Default constructor
	Queue_Thread_Safe() {}
	//Copy constructor
	Queue_Thread_Safe(Queue_Thread_Safe const &other) 
	{
		std::lock_guard<std::mutex> lg(other._Mutex);
		_Queue = other._Queue;
	}
	~Queue_Thread_Safe() noexcept {}
//Member functions
public:
	//Pop with value storing in reference
	void push(T& value) 
	{
		std::lock_guard<std::mutex> lg(_Mutex);
		_Queue.push(std::make_shared<T>(value));
		_CV.notify_one();
	}

	//Return the first item in queue
	std::shared_ptr<T> pop()
	{
		std::lock_guard<std::mutex> lg(_Mutex);
		if (!_Queue.empty())
		{
			std::shared_ptr<T> ref(_Queue.front());
			_Queue.pop();
			return ref;
		}
		return std::nullptr_t;
	}

	//Return first item in queue via reference
	bool pop(T& ref)
	{
		std::lock_guard<std::mutex> lg(_Mutex);
		if (!_Queue.empty())
		{
			ref = *_Queue.front().get();
			_Queue.pop();
			return true;
		}
		return false;
	}

	//Empty the queue
	void MakeEmpty()
	{
		std::lock_guard<std::mutex> lg(_Mutex);
		std::queue<T> empty;
		std::swap(_Queue, empty);
	}

	//Check if queue is empty
	bool IsEmpty() const
	{
		std::lock_guard<std::mutex> lg(_Mutex);
		return _Queue.empty();
	}

	//Wait and Pop with value storing in reference
	bool WaitAndPop(T& ref)
	{
		std::unique_lock<std::mutex> lg(_Mutex);
		_CV.wait(lg, [this]
		{
			return !_Queue.empty();
		});
		ref = *_Queue.front().get();
		_Queue.pop();
		return true;
	}

	//Wait and Pop, return the value
	std::shared_ptr<T> WaitAndPop()
	{
		std::unique_lock<std::mutex> lg(_Mutex);
		_CV.wait(lg, [this]
		{
			return !_Queue.empty();
		});
		std::shared_ptr<T> re(_Queue.front());
		_Queue.pop();
		return re;
	}

	//Check size 
	size_t size() const
	{
		return _Queue.size();
	}
};


