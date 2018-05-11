#include "ProductAndFactory.h"

int main()
{
	Factory *pfA = new ConcreteFactoryA();
	Product *productA = pfA->createProduct();
	productA->use();

	Factory *pfB = new ConcreteFactoryB();
	Product *productB = pfB->createProduct();
	productB->use();
}