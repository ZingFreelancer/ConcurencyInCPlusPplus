#include "stdafx.h"
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "ThreadGuard.h"

using namespace std;

//void func_1()
//{
//	cout << "Hello from Thread One!" << endl;
//}
//
//void error_func()
//{
//	throw std::runtime_error("Runtime error occured");
//}
//
/////Protected with use of thread guard
//int main()
//{
//	std::thread t1(func_1);
//	ThreadGuard tg(t1);
//	
//	///Cause error
//	error_func();
//
//	cout << "Hello from main" << endl;
//	system("pause");
//	return 0;
//}


/////Protected with use of try catch
//int main()
//{
//	std::thread t1(func_1);
//
//	///Error is thrown and t1 is never executed
//	error_func();
//
//	///Wrap it in try catch block and manage join from it.
//	try
//	{
//		error_func();
//		t1.join();
//	}
//	catch (...)
//	{
//		t1.join();
//	}
//	
//	cout << "Hello from main!" << endl;
//
//	system("pause");
//	return 0;
//}