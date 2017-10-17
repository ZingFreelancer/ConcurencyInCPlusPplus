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
//	cout << "AddTwoValues thread id: " << this_thread::get_id() << '\n' << endl;
//	return x + y;
//}
//
//int SubstractTwoValues(int x, int y)
//{
//	cout << "SubstractTwoValues thread id: " << this_thread::get_id() << endl;
//	return x - y;
//}
//
//int main()
//{
//	cout << "----- Main Async Start ("<< this_thread::get_id()<<")-----\n" << endl;
//	int x = 10;
//	int y = 5;
//
//	future<void> f1 = async(launch::async, PrintSomething, "Hello world");
//	future<int> f2 = async(launch::deferred, AddTwoValues, x, y);
//	future<int> f3 = async(launch::deferred | launch::async, SubstractTwoValues, x, y);
//
//	f1.get();
//	cout << "F2: " << f2.get() << endl;
//	cout << "F3: " << f3.get() << endl;
//
//
//	system("pause");
//	return 0;
//}