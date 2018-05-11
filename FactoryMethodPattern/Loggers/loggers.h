/*
Sunny软件公司欲开发一个系统运行日志记录器(Logger)，
该记录器可以通过多种途径保存系统的运行日志，如通过文件记录或数据库记录，
用户可以通过修改配置文件灵活地更换日志记录方式。


在设计各类日志记录器时，Sunny公司的开发人员发现需要对日志记录器进行一些初始化工作，
初始化参数的设置过程较为复杂，而且某些参数的设置有严格的先后次序，
否则可能会发生记录失败。如何封装记录器的初始化过程并保证多种记录器切换的灵活性是
Sunny公司开发人员面临的一个难题。
*/
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