#include "stdafx.h"
#include "LogWriter.h"
#include <string>
#include <iostream>
#include <thread>
using namespace std;

int main()
{
	string m1 = "Hello this is a message!";
	string m2 = "Good bye my darling!";

	LogWriter log;
	//thread t1(log.WriteLog(m1));
	cout << "Main Messaging: " << m1 << endl;
	cout << "Main Messaging: " << m2 << endl;
	//log.WriteLog(m1);
	//log.WriteLog(m2);
	//t1.join();
	//t2.join();

	return 0;
}