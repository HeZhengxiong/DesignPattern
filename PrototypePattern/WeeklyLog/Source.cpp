#include "Log.h"

int main()
{
	Log *log = new WeeklyLog();
	log->setName("张三");
	log->setDate("第12周");
	log->setContent("这周很忙，周一到周五都在加班");

	Log *cloneLog = log->clone();
	cloneLog->setName("李四");
	
	std::cout << cloneLog->getName() << " " << cloneLog->getDate() << " " <<
		cloneLog->getContent() << std::endl;
}