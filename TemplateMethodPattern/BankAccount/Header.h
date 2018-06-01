#ifndef Header_h__
#define Header_h__

/*
ĳ�����˾��Ϊĳ���е�ҵ��֧��ϵͳ����һ����Ϣ����ģ�飬
��Ϣ�����������£�

(1) ϵͳ�����˺ź�������֤�û���Ϣ������û���Ϣ����ϵͳ��ʾ������ʾ��

(2) ����û���Ϣ��ȷ��������û����͵Ĳ�ͬʹ�ò�ͬ����Ϣ���㹫ʽ������Ϣ
��������˻��Ͷ����˻����в�ͬ����Ϣ���㹫ʽ����

(3) ϵͳ��ʾ��Ϣ��

��ʹ��ģ�巽��ģʽ��Ƹ���Ϣ����ģ�顣
*/


#include <iostream>
#include <string>


class Account
{
public:
	virtual ~Account(){ }


	virtual bool validate(const std::string& accountName,
		const std::string& password)
	{
		std::cout << "Account: " << accountName << std::endl;
		std::cout << "Password: " << password << std::endl;

		return true;
	}

	virtual void calculateIntes() = 0;

	void display()
	{
		std::cout << "Show Ints" << std::endl;
	}

	virtual void handle(const std::string& name, const std::string& ps)
	{
		if (validate(name, ps))
		{
			calculateIntes();
			display();
		}
	}
};



class CurrentAccount : public Account
{
public:
	void calculateIntes() override
	{
		std::cout << "Using Current to compute" << std::endl;
	}
};


class SavingAccout : public Account
{
public:
	virtual void calculateIntes() override
	{
		std::cout << "Using saving to compute\n";
	}
};






#endif // Header_h__
