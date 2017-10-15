#include "stdafx.h"
#include "Bank_Account.h"
#include <iostream>
#include <chrono>

Bank_Account::Bank_Account()
{}

Bank_Account::Bank_Account(double inBalance, std::string inHolderName) : _Balance(inBalance), _HolderName(inHolderName)
{}

Bank_Account::~Bank_Account()
{}


bool Bank_Account::Withdraw(const double amount)
{
	std::lock_guard<std::mutex> lg(_Mutex);
	if (_Balance >= amount)
	{
		_Balance -= amount;
		std::cout << _HolderName << "'s new balance: " << _Balance << std::endl;
		return true;
	}
	else
	{
		std::cout << _HolderName << " has insuficient balance: " << _Balance << std::endl;
		return false;
	}
}

bool Bank_Account::Deposite(const double amount)
{
	std::lock_guard<std::mutex> lg(_Mutex);
	_Balance += amount;
	std::cout << _HolderName << "'s new balance: " << _Balance << std::endl;
	return true;
}

bool Bank_Account::Transfer(Bank_Account from, Bank_Account to, double amount)
{
	std::lock_guard<std::mutex> lg(from._Mutex);
	std::cout << "Lock for " << from._HolderName << " account aquired by " << std::this_thread::get_id() << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	std::cout << " waiting to aquire lock for " << to._HolderName << " account by " << std::this_thread::get_id() << std::endl;
	std::lock_guard<std::mutex> lg_2(to._Mutex);

	if (from.Withdraw(amount))
	{
		to.Deposite(amount);
		std::cout << "Succsessfully transfered " << amount << " from " << from._HolderName << " to " << to._HolderName << std::endl;
		return true;
	}
	else
	{
		std::cout << "Transfer failed." << std::endl;
		return false;
	}
}
