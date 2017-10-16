#pragma once
#include <string>
#include <mutex>

class Bank_Account
{
private:
	double _Balance;
	std::string _HolderName;
	std::mutex _Mutex;

public:
	Bank_Account();
	Bank_Account(double inBalance, std::string inHolderName);
	~Bank_Account();
	Bank_Account(Bank_Account& const) = delete;
	Bank_Account& operator=(Bank_Account& const) = delete;
	bool Withdraw(const double amount);
	bool Deposite(const double amount);
	bool Transfer(Bank_Account &from, Bank_Account &to, const double amount);
};

