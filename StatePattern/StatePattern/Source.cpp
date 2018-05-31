#include "state.h"


int main()
{
	Context *c = new Context;
	c->setVal(0);
	c->changeState();
	c->request();

	c->setVal(1);
	c->changeState();
	c->request();
}