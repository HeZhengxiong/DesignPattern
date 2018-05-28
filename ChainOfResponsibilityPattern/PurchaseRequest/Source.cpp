#include "purchase.h"

int main()
{
	PurchaseRequest r;
	r.setPrice(200000);

	Director *d = new Director;
	ViceManager *vm = new ViceManager;
	Manager *m = new Manager;
	Board *b = new Board;

	d->setSuccessor(vm);
	vm->setSuccessor(m);
	m->setSuccessor(b);

	d->processRequest(r);
}