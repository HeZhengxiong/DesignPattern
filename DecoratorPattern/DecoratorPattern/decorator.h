#ifndef decorator_h__
#define decorator_h__

#include <iostream>

class Component
{
public:
	virtual ~Component(){ }

	virtual void operation() = 0;
};


class ConcreteComponent : public Component
{
public:
	virtual void operation()
	{
		std::cout << "ConcreteComponent Implement operation" << std::endl;
	}
};



class Decorator : public Component
{
public:
	Decorator() = default;
	Decorator(Component *c) : _concreteComponent(c) { }

	virtual void operation()
	{
		_concreteComponent->operation();
	}

protected:
	Component	*_concreteComponent;
};


class ConcreteDecoratorA : public Decorator
{
public:
	ConcreteDecoratorA(Component *c) : Decorator(c){ }

	virtual void operation()
	{
		this->Decorator::operation();
	}

	void addedFunctionConcreteA()
	{
		std::cout << "Added Function ConcreteA" << std::endl;
	}
};


class ConcreteDecoratorB : public Decorator
{
public:
	ConcreteDecoratorB(Component *c) : Decorator(c){ }

	virtual void operation()
	{
		this->Decorator::operation();
	}

	void newBFunction()
	{
		std::cout << "Added Function for ConcreteDecorator B" << std::endl;
	}
};




#endif // decorator_h__
