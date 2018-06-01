#include "strategy.h"

int main()
{
	Context *c = new Context;

	AbstractStrategy *sa = new ConcreteStrategyA();
	c->setStrategy(sa);

	c->algorithm();
}