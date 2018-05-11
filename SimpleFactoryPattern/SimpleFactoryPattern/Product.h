#ifndef Product_h__
#define Product_h__


class Product
{
public:
	virtual void use() abstract;
};


class ConcreteProductA : public Product
{
public:
	virtual void use()
	{
		std::cout << "Concrete A Implement use" << std::endl;
	}
};

class ConcreteProductB : public Product
{
public:
	virtual void use()
	{
		std::cout << "Concrete B Implement use" << std::endl;
	}
};


class ProductFactory
{
public:
	static Product*	createProduct(const std::string& pd)
	{
		if (pd == "A" || pd == "a")
		{
			return new ConcreteProductA();
		}
		else if (pd == "B" || pd == "b")
		{
			return new ConcreteProductB();
		}

		return nullptr;
	}

};










#endif // Product_h__
