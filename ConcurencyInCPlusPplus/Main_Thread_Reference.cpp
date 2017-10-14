#include "stdafx.h"
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

///Pass value by reference
///Thread will have to use "std::ref" in order to avoid errors
void func_1(int & x)
{
	while (true)
	{
		cout << "Value: " << x << endl;
		std::this_thread::sleep_for(chrono::milliseconds(1000));
	}
}

///Pass value by copy
void func_2(int x)
{
	while (true)
	{
		cout << "Value: " << x << endl;
		std::this_thread::sleep_for(chrono::milliseconds(1000));
	}
}

//int main()
//{
//	int x = 7;
//	thread t1(func_1, ref(x));
//	std::this_thread::sleep_for(chrono::milliseconds(5000));
//	x = x * 2;
//
//	cout << "x has changed value to " << x << endl;
//	if(t1.joinable())
//		t1.join();
//
//	system("pause");
//	return 0;
//}