#include "prototype.h"
#include <iostream>

int main()
{
	Prototype *pa = new ConcretePrototypeA();
	pa->setVal(10.0);
	Prototype *cloneA = pa->clone();
	std::cout << "Clone A val: " << cloneA->getVal() << std::endl;
}