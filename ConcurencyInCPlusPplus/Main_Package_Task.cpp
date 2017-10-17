#include "stdafx.h"
//#include <chrono>
//#include <ctime>
//#include <future>
//#include <iostream>
//#include <string>
//using namespace std;
//
//void PrintSomething(std::string message)
//{
//	this_thread::sleep_for(chrono::milliseconds(1000));
//	cout << "Printing: " << message << '\n' << endl;
//}
//
//int AddTwoValues(int x, int y)
//{
//	this_thread::sleep_for(chrono::milliseconds(500));
//	cout << "AddTwoValues thread id: " << this_thread::get_id() << endl;
//	return x + y;
//}
//
////Will run it its own thread
//void TaskThread()
//{
//	packaged_task<int(int, int)> task_1(AddTwoValues);
//	future<int> future_1 = task_1.get_future();
//	
//	thread thread_1(std::move(task_1), 50, 25);
//	thread_1.detach();
//
//	cout << "Task Thread: " << future_1.get() << ", id("<< this_thread::get_id() << ")\n" << endl;
//}
//
//
////Will run in main thread
//void TaskNormal()
//{
//	packaged_task<int(int, int)> task_1(AddTwoValues);
//	future<int> future_1 = task_1.get_future();
//	task_1(100, 50);
//	cout << "Task Normal: " << future_1.get() << ", id(" << this_thread::get_id() << ")\n" << endl;
//}
//
//
//int main()
//{
//	cout << "----- Main Package Start (" << this_thread::get_id() << ")-----\n" << endl;
//	TaskThread();
//	TaskNormal();
//
//
//	system("pause");
//	return 0;
//}