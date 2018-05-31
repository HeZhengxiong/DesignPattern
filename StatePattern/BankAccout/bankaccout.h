#ifndef bankaccout_h__
#define bankaccout_h__

/*
Sunny�����˾��Ϊĳ���п���һ�����ÿ�ҵ��ϵͳ��
�����˻�(Account)�Ǹ�ϵͳ�ĺ�����֮һ��
ͨ��������Sunny�����˾������Ա�����ڸ�ϵͳ�У�
�˻���������״̬�����ڲ�ͬ״̬���˻����ڲ�ͬ����Ϊ��
����˵�����£�

(1) ����˻��������ڵ���0�����˻���״̬
Ϊ����״̬(Normal State)��
��ʱ�û��ȿ�������˻����Ҳ���ԴӸ��˻�ȡ�

(2) ����˻������С��0�����Ҵ���-2000��
���˻���״̬Ϊ͸֧״̬(Overdraft State)��
��ʱ�û��ȿ�������˻����Ҳ���ԴӸ��˻�ȡ�
����Ҫ���������Ϣ��

(3) ����˻���������-2000��
��ô�˻���״̬Ϊ����״̬(Restricted State)��
��ʱ�û�ֻ������˻��������ٴ���ȡ�
ͬʱҲ�����������Ϣ��

(4) �������Ĳ�ͬ����������״̬�ɷ����໥ת����
*/

//TODO: statePattern���ʾ�����Ǻܺã��Ժ��������
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
