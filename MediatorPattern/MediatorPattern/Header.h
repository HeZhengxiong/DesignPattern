#ifndef Header_h__
#define Header_h__

#include <iostream>
#include <vector>
#include <string>

class Mediator;

class Colleague
{
public:
	Colleague(Mediator *m_)
	{
		_mediator = m_;
	}

	virtual void method1() = 0;

	void method2();


protected:
	Mediator*	_mediator;
};

class Mediator
{
public:
	virtual ~Mediator(){ }

	void registerA(Colleague* colleague)
	{
		_colleagues.push_back(colleague);
	}

	virtual void operation() = 0;

protected:
	std::vector<Colleague*>	_colleagues;
};


class ConcreteMediator : public Mediator
{
public:
	virtual void operation()
	{
		std::cout << "Doing some stuff with colleagues" << std::endl;
	}
};




class ConcreteColleague : public Colleague
{
public:
	virtual void method1()
	{
		std::cout << "ConcreteColleague called" << std::endl;
	}

	ConcreteColleague(Mediator* m_) : Colleague(m_){ }
};


void Colleague::method2()
{
	_mediator->operation();
}


#endif // Header_h__
