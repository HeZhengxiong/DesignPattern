#ifndef builder_h__
#define builder_h__

#include <iostream>

class Product
{
public:
	Product(){ }

};


class Builder
{
public:
	Builder() : _product(new Product()){ }
	virtual ~Builder(){ }

	virtual void buildPartA() = 0;
	virtual void buildPartB() = 0;
	virtual void buildPartC() = 0;

	virtual Product* getResult()
	{
		return _product;
	}

private:
	Product*		_product;
};


class ProductABuilder : public Builder
{
public:
	virtual void buildPartA()
	{
		std::cout << "ProductA: build part a" << std::endl;
	}

	virtual void buildPartB()
	{
		std::cout << "ProductA: build part b" << std::endl;
	}

	virtual void buildPartC()
	{
		std::cout << "ProductA: build part c" << std::endl;
	}

};


class ProductBBuilder : public Builder
{
public:
	virtual void buildPartA()
	{
		std::cout << "ProductB: build part a" << std::endl;
	}

	virtual void buildPartB()
	{
		std::cout << "ProductB: build part b" << std::endl;
	}

	virtual void buildPartC()
	{
		std::cout << "ProductB: build part c" << std::endl;
	}

};



class Director
{
private:
	Builder*		_builder;

public:
	Director(Builder* builder) : _builder(builder){ }

	void setBuilder(Builder* builder)
	{
		_builder = builder;
	}

	Product* construct()
	{
		_builder->buildPartA();
		_builder->buildPartB();
		_builder->buildPartC();

		return _builder->getResult();
	}
};



#endif // builder_h__
