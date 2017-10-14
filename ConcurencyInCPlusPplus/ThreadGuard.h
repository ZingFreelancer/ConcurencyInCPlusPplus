#pragma once
#include <thread>

class ThreadGuard
{
	std::thread& _t;

public:
	explicit ThreadGuard(std::thread & t);
	~ThreadGuard();

	//ThreadGuard(ThreadGuard & const) = delete;
	//ThreadGuard & operator= (ThreadGuard & const) = delete;
};

