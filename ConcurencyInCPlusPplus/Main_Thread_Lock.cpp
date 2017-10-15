#include "stdafx.h"
#include <iostream>
#include <thread>
#include <mutex>
#include <list>
using namespace std;

//std::list<int> _list;
//std::mutex _m;
//
//void add_to_list(int const & val);
//size_t size();
//
//
//int main()
//{
//	thread t1(add_to_list, 4);
//	thread t2(add_to_list, 9);
//
//	t1.join();
//	t2.join();
//
//	cout << "List size: " << size() << endl;
//
//	system("pause");
//	return 0;
//}
//
//void add_to_list(int const & val)
//{
//
//	_m.lock();
//	cout << "Adding to list: " << val << endl;
//	_list.push_front(val);
//	_m.unlock();
//}
//
//size_t size()
//{
//	///Can use lock guards to automatically lock and unlock mutex
//	lock_guard<mutex> lg(_m);
//	return _list.size();
//}
