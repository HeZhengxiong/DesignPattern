#include "Log.h"

int main()
{
	Log *log = new WeeklyLog();
	log->setName("����");
	log->setDate("��12��");
	log->setContent("���ܺ�æ����һ�����嶼�ڼӰ�");

	Log *cloneLog = log->clone();
	cloneLog->setName("����");
	
	std::cout << cloneLog->getName() << " " << cloneLog->getDate() << " " <<
		cloneLog->getContent() << std::endl;
}