#ifndef Logger_h__
#define Logger_h__


/*
compare to the Loggers example, add override functions to build the logger.
*/


#include <iostream>
#include <string>

class Logger
{
public:
	Logger(){ }
	virtual ~Logger(){ }

	virtual void writeLog() = 0;
};


class DatabaseLogger : public Logger
{
public:
	virtual void writeLog() override
	{
		std::cout << "数据库日志记录" << std::endl;
	}
};


class FileLogger : public Logger
{
public:
	virtual void writeLog() override
	{
		std::cout << "文件日志记录" << std::endl;
	}
};


class LoggerFactory
{
public:
	LoggerFactory(){ }
	virtual ~LoggerFactory() { }

	virtual Logger* createLogger() = 0;
	virtual Logger* createLogger(const std::string& str) = 0;
};


class DatabaseLoggerFactory : public LoggerFactory
{
public:

	virtual Logger* createLogger() override
	{
		//do some initialized operations
		Logger *logger = new DatabaseLogger();
		return logger;
	}

	virtual Logger* createLogger(const std::string& logString) override
	{
		//do some settings with logString
		Logger *logger = new DatabaseLogger();
		return logger;
	}
};

class FileLoggerFactory : public LoggerFactory
{
public:
	virtual Logger* createLogger() override
	{
		Logger *logger = new FileLogger();
		return logger;
	}

	virtual Logger* createLogger(const std::string& logString) override
	{
		//do some settings with logString
		Logger* logger = new FileLogger();
		return logger;
	}
};



#endif // Logger_h__
