#include "stdafx.h"
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
using namespace std;

std::mutex mu;
void f_1();
void m_1();

void print(string msg);

//int main()
//{
//	///Sequential execution
//	//f_1();
//	//m_1();
//
//	///Concurent execution
//	thread t1(f_1);
//	m_1();
//	t1.join();
//	return 0;
//}

void f_1()
{
	for (int i = 0; i >= -10; i--)
	{
		print("F1: " + std::to_string(i));
	}
}

void m_1()
{
	for (int i = 0; i <= 10; i++)
	{
		print("M1: " + std::to_string(i));
	}
}

void print(string msg)
{
	///lock_guard will unlock mu when it goes out of scope
	std::lock_guard<std::mutex> guard(mu);
	//mu.lock();
	cout << msg << endl;
	//mu.unlock();
}
