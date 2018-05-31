#ifndef bankaccout_h__
#define bankaccout_h__

/*
Sunny软件公司欲为某银行开发一套信用卡业务系统，
银行账户(Account)是该系统的核心类之一，
通过分析，Sunny软件公司开发人员发现在该系统中，
账户存在三种状态，且在不同状态下账户存在不同的行为，
具体说明如下：

(1) 如果账户中余额大于等于0，则账户的状态
为正常状态(Normal State)，
此时用户既可以向该账户存款也可以从该账户取款；

(2) 如果账户中余额小于0，并且大于-2000，
则账户的状态为透支状态(Overdraft State)，
此时用户既可以向该账户存款也可以从该账户取款，
但需要按天计算利息；

(3) 如果账户中余额等于-2000，
那么账户的状态为受限状态(Restricted State)，
此时用户只能向该账户存款，不能再从中取款，
同时也将按天计算利息；

(4) 根据余额的不同，以上三种状态可发生相互转换。
*/

//TODO: statePattern这个示例不是很好，以后继续开发
#include <iostream>
#include <string>

class AccoutState;


class Accout
{
public:
	Accout(const std::string& owner, double init)
	{

	}

	double getBalance()
	{
		return _balance;
	}

	void setBalance(double balance)
	{
		_balance = balance;
	}

	void setState(AccoutState *state)
	{
		_state = state;
	}

	void deposite(double amout)
	{

	}

	void withdraw(double amout)
	{

	}

	void computeInterest()
	{

	}


protected:
	AccoutState	    *_state;
	std::string		_owner;
	double			_balance;
};



class AccoutState
{
public:
	virtual void deposit(double amout);
	virtual void withdraw(double amout);
	virtual void computeInterest();
	virtual void stateCheck();

protected:
	Accout*		_acc;
};


class NormalState : public AccoutState
{
public:
	NormalState(Accout *acc)
	{
		_acc = acc;
	}

	void deposite(double amout)
	{
		_acc->setBalance(_acc->getBalance() + amout);
		stateCheck();
	}
};



#endif // bankaccout_h__
