#include "stdafx.h"
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

//void func_1()
//{
//	cout << "Func_1 id: " << std::this_thread::get_id() << endl;
//}
//
//void func_2()
//{
//	cout << "Func_2 id: " << std::this_thread::get_id() << endl;
//}
//
//
//
//int main()
//{
//	thread t1(func_1);
//	thread t2 = std::move(t1);
//	t1 = thread(func_2);
//
//	t1.join();
//	t2.join();
//
//	cout << "\n\nMax number of threads: " << thread::hardware_concurrency() << endl;
//
//	system("pause");
//	return 0;
//}