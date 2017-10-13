#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <mutex>


class LogWriter
{
private:
	std::string _FileName = "Log.txt";
	std::ofstream _Stream;
	std::mutex _Mutex;

public: ///Methods
	//Default constructor
	LogWriter();
	LogWriter(std::string FileName);
	//Copy constructor
	LogWriter(const LogWriter &other);
	//Move constructor
	LogWriter(LogWriter &&other) noexcept;
	//Copy assignment operator
	LogWriter& operator=(const LogWriter &other);
	//Move assignment operator
	LogWriter& operator=(const LogWriter &&other);
	virtual ~LogWriter();

public: ///Public methods
	bool WriteLog(const std::string Message) const;
};

