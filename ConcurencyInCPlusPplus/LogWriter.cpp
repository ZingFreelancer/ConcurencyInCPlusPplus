#include "stdafx.h"
#include "LogWriter.h"

LogWriter::LogWriter() : LogWriter("Log.txt")
{}

LogWriter::LogWriter(std::string FileName) : _FileName(FileName), _Stream(_FileName, std::ofstream::out | std::ofstream::app)
{}

LogWriter::LogWriter(const LogWriter & other)
{
	std::cout << "LogWriter copy constructor" << std::endl;
	_FileName = other._FileName;
}

LogWriter::LogWriter(LogWriter && other) noexcept
{
	std::cout << "LogWriter move copy constructor" << std::endl;
	_FileName = other._FileName;
	other._FileName = "";
}

LogWriter & LogWriter::operator=(const LogWriter & other)
{
	std::cout << "Copy assignment operator" << std::endl;
	_FileName = other._FileName;
	return *this;
}

LogWriter & LogWriter::operator=(const LogWriter && other)
{
	std::cout << "Move assignment operator" << std::endl;
	_FileName = std::move(other._FileName);
	return *this;
}

LogWriter::~LogWriter()
{}

bool LogWriter::WriteLog(const std::string Message) const
{
	std::ofstream ofs(_FileName, std::ofstream::out | std::ofstream::app);
	if (ofs.is_open())
	{
		ofs << Message << std::endl;
		ofs.close();
		return true;
	}
	return false;
}
