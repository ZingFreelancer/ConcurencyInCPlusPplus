#include "stdafx.h"
//#include <chrono>
//#include <ctime>
//#include <future>
//#include <iostream>
//using namespace std;
//
//int HowOldIsUniverse()
//{
//	return chrono::duration_cast<chrono::hours>(chrono::system_clock::now().time_since_epoch()).count();
//}
//
//void calculate_heat_death()
//{
//	cout << "Calculation failed!" << endl;
//}
//
//
//int main()
//{
//	cout << "----- Main Future Start -----" << endl;
//	future<int> f1 = std::async(HowOldIsUniverse);
//	calculate_heat_death();
//	cout << "Time since: " << f1.get() << endl;
//
//	system("pause");
//	return 0;
//}