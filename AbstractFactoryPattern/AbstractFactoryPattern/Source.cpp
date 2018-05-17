#include "abstractFactoryPattern.h"


int main()
{
	Factory *c1 = new ConcreteFactory1();
	AbstractProductA *pa = c1->createProductA();
	AbstractProductB *pb = c1->createProductB();
	pa->showProduct();
	pb->hello();
}