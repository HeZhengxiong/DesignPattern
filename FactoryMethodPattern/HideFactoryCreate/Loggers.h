#ifndef Loggers_h__
#define Loggers_h__

#include <iostream>

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

	//this virtual setting can  be removed( same result)
	virtual void writeLog()
	{
		Logger *logger = createLogger();
		logger->writeLog();
	}
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
};

class FileLoggerFactory : public LoggerFactory
{
public:
	virtual Logger* createLogger() override
	{
		Logger *logger = new FileLogger();
		return logger;
	}
};


#endif // Loggers_h__
