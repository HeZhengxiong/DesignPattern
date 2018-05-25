#include "decorator.h"


int main()
{
	Component *concreteComponent = new ConcreteComponent();

	ConcreteDecoratorA *decorator = new ConcreteDecoratorA(concreteComponent);

	decorator->operation();
	decorator->addedFunctionConcreteA();
}