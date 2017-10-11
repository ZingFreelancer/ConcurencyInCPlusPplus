#include "stdafx.h"
#include <iostream>
#include <string>
#include <thread>

using namespace std;

class Fctor {
public:
	void operator()(string msg)
	{
		cout << "Fctor says " << msg << endl;
		msg = "Meow";
	}
};

//int main()
//{
//	cout << "Thread id: " << this_thread::get_id << endl;
//	string s = "Woff";
//	thread t1((Fctor()), s);
//	t1.join(); ///t1 runs and then goes out of scope
//
//	thread::hardware_concurrency();
//
//	//cout << "Main says: " << s << endl;
//	//try
//	//{
//	//	cout << "Main says: " << s << endl;
//	//}
//	//catch (...)
//	//{
//	//	t1.join();
//	//	throw;
//	//}
//	//t1.join();
//	
//	return 0;
//	///pointlessThread will go out of scope
//}