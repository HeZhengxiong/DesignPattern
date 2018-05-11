#ifndef ProductAndFactory_h__
#define ProductAndFactory_h__

#include <iostream>


class Product
{
public:
	virtual void use() = 0;
};


class ConcreteProductA : public Product
{
public:
	virtual void use() override
	{
		std::cout << "Using ConcreteProduct A" << std::endl;
	}
};

class ConcreteProductB : public Product
{
public:
	virtual void use() override
	{
		std::cout << "Using ConcreteProduct B" << std::endl;
	}
};


class Factory
{
public:
	virtual Product* createProduct() = 0;
};


class ConcreteFactoryA : public Factory
{
public:
	virtual Product* createProduct() override
	{
		return new ConcreteProductA();
	}
};

class ConcreteFactoryB : public Factory
{
public:
	virtual Product* createProduct() override
	{
		return new ConcreteProductB();
	}
};



#endif // ProductAndFactory_h__
