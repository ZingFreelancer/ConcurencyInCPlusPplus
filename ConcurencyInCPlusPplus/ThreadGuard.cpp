#include "stdafx.h"
#include "ThreadGuard.h"

ThreadGuard::ThreadGuard(std::thread & t) : _t(t)
{}

ThreadGuard::~ThreadGuard()
{
	if (_t.joinable())
	{
		_t.join();
	}
}
