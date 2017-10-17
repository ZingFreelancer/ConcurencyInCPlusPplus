#include "stdafx.h"
//#include <iostream>
//#include <string>
//#include <thread>
//#include <mutex>
//#include <chrono>
//#include <condition_variable>
//using namespace std;
//
//bool bArrived = false;
//int DistanceToTarget = 5;
//int DistanceCovered = 0;
//std::condition_variable cv;
//std::mutex mu;
//
//void KeepMoving()
//{
//	while (!bArrived)
//	{
//		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//		DistanceCovered++;
//		cout << "Current distance: " << DistanceCovered << endl;
//		if (DistanceCovered >= DistanceToTarget)
//		{
//			cout << "Keep Moving: Arrived at destination" << endl;
//			cv.notify_one();
//		}
//	}
//}
//
//void AskToBeWakenUpOnTime()
//{
//	unique_lock<mutex> ul(mu);
//	cv.wait(ul, [] {return DistanceCovered >= DistanceToTarget;  });
//	bArrived = true;
//	cout << "Time to wake up dummy!" << endl;
//}



//int main()
//{
//	thread driver(KeepMoving);
//	thread passenger(AskToBeWakenUpOnTime);
//	passenger.join();
//	driver.join();
//
//	system("pause");
//	return 0;
//}