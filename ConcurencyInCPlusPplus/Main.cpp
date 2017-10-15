#include "stdafx.h"
#include <string>
#include <iostream>
#include <thread>
#include <chrono>
#include "Bank_Account.h"
using namespace std;
//
//int main()
//{
//	Bank_Account bank;
//
//	Bank_Account BA_James(5000, "James");
//	Bank_Account BA_Martin(10000, "Martin");
//
//	//std::thread t1(&Bank_Account::Transfer, &BA_James, std::ref(BA_James), std::ref(BA_Martin), 1250);
//	//std::this_thread::sleep_for(std::chrono::milliseconds(100));
//	//std::thread t2(&Bank_Account::Transfer, &bank, std::ref(BA_Martin), std::ref(BA_James), 250);
//
//	//t1.join();
//	//t2.join();
//
//	system("pause");
//	return 0;
//}