#ifndef strategy_h__
#define strategy_h__

#include <iostream>


class AbstractStrategy
{
public:
	virtual ~AbstractStrategy(){}
	virtual void algorithm() = 0;
};


class ConcreteStrategyA : public AbstractStrategy
{
public:
	void algorithm() override
	{
		std::cout << "Apply Algorithm A" << std::endl;
	}
};


class Context
{
public:
	void setStrategy(AbstractStrategy *strategy)
	{
		_strategy = strategy;
	}

	void algorithm()
	{
		_strategy->algorithm();
	}

private:
	AbstractStrategy*		_strategy;
};




#endif // strategy_h__
