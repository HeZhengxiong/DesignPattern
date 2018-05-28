#include "chain.h"


int main()
{
	ConcreteHandlerA *a = new ConcreteHandlerA;
	ConcreteHandlerB *b = new ConcreteHandlerB;

	a->setSuccessor(b);
	a->handleRequest();
}