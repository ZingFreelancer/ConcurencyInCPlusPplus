#include "stdafx.h"
//#include <iostream>
//#include <mutex>
//#include <queue>
//#include <memory>
//#include <condition_variable>
//#include <thread>
//#include "Queue_Thread_Safe.h"
//
//Queue_Thread_Safe<int> queue;
//void func_1()
//{
//	int value;
//	queue.WaitAndPop(value);
//	std::cout << value << std::endl;
//
//}
//
//void func_2()
//{
//	int x = 10;
//	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
//	queue.push(x);
//}
//
//
//int main()
//{
//
//	std::thread thread_1(func_1);
//	std::thread thread_2(func_2);
//
//	thread_1.join();
//	thread_2.join();
//
//	system("pause");
//	return 0;
//}