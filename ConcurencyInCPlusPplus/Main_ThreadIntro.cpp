// ConcurencyInCPlusPplus.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <iostream>
#include <string>
#include <thread>

using namespace std;

void PointlessFunction();

//int main()
//{
//	//Create a thread of PointlessFunction
//	thread pointlessThread(PointlessFunction);
//
//	///Main thread waits for PointlessFunction to finish
//	//pointlessThread.join(); 
//
//	///PointlessThread will run freely on its own deatached from Main
//	///PointlessThread will then become a daemon process
//	pointlessThread.detach();
//
//	///Check if pointlessThread can join main thread
//	///HINT: It cant because we've deatached it
//	if (pointlessThread.joinable())
//	{
//		pointlessThread.join();
//	}
//
//	return 0;
//}

void PointlessFunction()
{
	string Re = "This is a pointless function";
	cout << Re << endl;
}
