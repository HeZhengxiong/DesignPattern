#include "Logger.h"


int main()
{
	LoggerFactory *databaseFactory = new DatabaseLoggerFactory();
	Logger *databaseLogger = databaseFactory->createLogger();
	databaseLogger->writeLog();

	LoggerFactory *fileFactory = new FileLoggerFactory();
	Logger* fileLogger = fileFactory->createLogger("myfilelogger");
	fileLogger->writeLog();
}