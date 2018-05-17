#ifndef abstractFactoryPattern_h__
#define abstractFactoryPattern_h__

#include <iostream>

class AbstractProductA
{
public:
	virtual void showProduct() = 0;
};


class AbstractProductB
{
public:
	virtual void hello() = 0;
};


/////
//Product Serials 01

class ProductA1 : public AbstractProductA
{
public:
	virtual void showProduct()
	{
		std::cout << "this is product a1" << std::endl;
	}
};

class ProductB1 : public AbstractProductB
{
public:
	virtual void hello()
	{
		std::cout << "hello from product b1" << std::endl;
	}
};


//////////////////////////////////////////////////////////////////////////
//serials 2

class ProductA2 : public AbstractProductA
{
public:
	virtual void showProduct()
	{
		std::cout << "show product a2" << std::endl;
	}
};

class ProductB2 : public AbstractProductB
{
public:
	virtual void hello()
	{
		std::cout << "hello from product b2" << std::endl;
	}
};



class Factory
{
public:
	Factory(){}
	virtual ~Factory(){ }

	virtual AbstractProductA* createProductA() = 0;
	virtual AbstractProductB* createProductB() = 0;
};


class ConcreteFactory1 : public Factory
{
public:
	AbstractProductA* createProductA()
	{
		AbstractProductA *pa = new ProductA1();
		return pa;
	}

	AbstractProductB* createProductB()
	{
		AbstractProductB *pb = new ProductB1();
		return pb;
	}
};


class ConcreteFactory2 : public Factory
{
public:

	AbstractProductA* createProductA()
	{
		AbstractProductA* pa = new ProductA2();
		return pa;
	}

	AbstractProductB* createProductB()
	{
		AbstractProductB *pb = new ProductB2();
		return pb;
	}
};




#endif // abstractFactoryPattern_h__
