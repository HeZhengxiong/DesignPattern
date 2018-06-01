#ifndef Header_h__
#define Header_h__

/*
某软件公司欲为某银行的业务支撑系统开发一个利息计算模块，
利息计算流程如下：

(1) 系统根据账号和密码验证用户信息，如果用户信息错误，系统显示出错提示；

(2) 如果用户信息正确，则根据用户类型的不同使用不同的利息计算公式计算利息
（如活期账户和定期账户具有不同的利息计算公式）；

(3) 系统显示利息。

试使用模板方法模式设计该利息计算模块。
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
