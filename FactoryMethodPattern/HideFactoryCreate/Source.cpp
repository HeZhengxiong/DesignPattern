#include "loggers.h"


int main()
{
	LoggerFactory *databaseFactory = new DatabaseLoggerFactory();
	databaseFactory->writeLog();

	LoggerFactory *fileFactory = new FileLoggerFactory();
	fileFactory->writeLog();
}