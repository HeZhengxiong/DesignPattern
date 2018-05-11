#include "loggers.h"


int main()
{
	LoggerFactory *factory = new FileLoggerFactory();
	Logger *logger = factory->createLogger();

	logger->writeLog();

	return 0;
}