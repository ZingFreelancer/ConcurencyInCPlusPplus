#include "stdafx.h"
#include <iostream>
#include <chrono>
#include <string>
#include <mutex>

class Bank_Account2
{
	double _Balance;
	std::string _HolderName;
	std::mutex _Mutex;

public:
	Bank_Account2() {};
	Bank_Account2(double inBalance, std::string inHolderName) : _Balance(inBalance), _HolderName(inHolderName) {}
	
	//Bank_Account2(Bank_Account2& const) = delete;
	//Bank_Account2& operator=(Bank_Account2& const) = delete;

	void Withdraw(double amount)
	{
		std::lock_guard<std::mutex> lg(_Mutex);
		if (_Balance >= amount)
		{
			_Balance -= amount;
			std::cout << _HolderName << "'s new balance: " << _Balance << std::endl;
		}
		else
		{
			std::cout << _HolderName << " has insuficient balance: " << _Balance << std::endl;
		}
	}
	void Deposite(double amount)
	{
		std::lock_guard<std::mutex> lg(_Mutex);
		_Balance += amount;
		std::cout << _HolderName << "'s new balance: " << _Balance << std::endl;
	}
	void Transfer(Bank_Account2 from, Bank_Account2 to, double amount)
	{
		std::lock_guard<std::mutex> lg_1(from._Mutex);
		std::cout << "Lock for " << from._HolderName << " account aquired by " << std::this_thread::get_id() << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));

		std::cout << " waiting to aquire lock for " << to._HolderName << " account by " << std::this_thread::get_id() << std::endl;
		std::lock_guard<std::mutex> lg_2(to._Mutex);

		from.Withdraw(amount);
		to.Deposite(amount);
		std::cout << "Succsessfully transfered " << amount << " from " << from._HolderName << " to " << to._HolderName << std::endl;
	}
};

int main()
{
	Bank_Account2 account;

	Bank_Account2 BA_James(5000, "James");
	Bank_Account2 BA_Martin(10000, "Martin");

	std::thread t1(&Bank_Account2::Transfer, &account, std::ref(BA_James), std::ref(BA_Martin), 500);
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	std::thread t2(&Bank_Account2::Transfer, &account, std::ref(BA_Martin), std::ref(BA_James), 250);

	//std::thread t([&](Bank_Account2* view) { view->refreshWindow(render, playerRect, backTexture, playerTexture); }, &window);

	t1.join();
	t2.join();

	system("pause");
	return 0;
}