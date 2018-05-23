#include "adapter.h"

int main()
{
	Adaptee *ade = new Adaptee();
	Target *t = new Adapter(ade);
	t->request();
}