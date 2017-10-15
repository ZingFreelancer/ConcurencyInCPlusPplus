#include "stdafx.h"
#include <iostream>
#include <thread>
#include <chrono>

///Pass value by copy
//void func_2(int& x)
//{
//	while (true)
//	{
//		std::cout << "Func_2: " << x << std::endl;
//		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//	}
//	std::cout << "Func_2 going out of scope, bye!" << std::endl;
//}
//
/////Pass value by reference
/////Thread will have to use "std::ref" in order to avoid errors
//void func_1()
//{
//	int x = 7;
//	std::thread t2(func_2, std::ref(x));
//	t2.detach();
//	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
//	std::cout << "Func_1 going out of scope, bye!" << std::endl;
//}

//int main()
//{
//	std::thread t1(func_1);
//	t1.join();
//
//	system("pause");
//	return 0;
//}