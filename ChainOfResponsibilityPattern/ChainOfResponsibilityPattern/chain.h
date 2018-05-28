#ifndef chain_h__
#define chain_h__

#include <iostream>

class Handler
{
public:
	virtual ~Handler(){ }
	
	virtual void handleRequest() = 0;

	void setSuccessor(Handler *handler)
	{
		_successor = handler;
	}

	virtual bool isAbleToHanlder() = 0;

protected:
	Handler*		_successor;
};


class ConcreteHandlerA : public Handler
{
public:
	virtual bool isAbleToHanlder()
	{
		return false;
	}

	virtual void handleRequest()
	{
		if (isAbleToHanlder())
		{
			std::cout << "Handler the request by A" << std::endl;
		}
		else
		{
			_successor->handleRequest();
		}
	}

};


class ConcreteHandlerB : public Handler
{
public:
	virtual bool isAbleToHanlder()
	{
		return true;
	}

	virtual void handleRequest()
	{

		if (isAbleToHanlder())
		{
			std::cout << "handled by ConcreteB" << std::endl;
		}
	}
};


#endif // chain_h__
