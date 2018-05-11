/*
Sunny������˾������һ��ϵͳ������־��¼��(Logger)��
�ü�¼������ͨ������;������ϵͳ��������־����ͨ���ļ���¼�����ݿ��¼��
�û�����ͨ���޸������ļ����ظ�����־��¼��ʽ��


����Ƹ�����־��¼��ʱ��Sunny��˾�Ŀ�����Ա������Ҫ����־��¼������һЩ��ʼ��������
��ʼ�����������ù��̽�Ϊ���ӣ�����ĳЩ�������������ϸ���Ⱥ����
������ܻᷢ����¼ʧ�ܡ���η�װ��¼���ĳ�ʼ�����̲���֤���ּ�¼���л����������
Sunny��˾������Ա���ٵ�һ�����⡣
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
		std::cout << "���ݿ���־��¼" << std::endl;
	}
};


class FileLogger : public Logger
{
public:
	virtual void writeLog() override
	{
		std::cout << "�ļ���־��¼" << std::endl;
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